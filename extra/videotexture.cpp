#ifdef linux
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#endif

#ifdef WIN32
#include <gl\GLee.h>
#include <GL/gl.h>
#endif

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

// FFmpeg
extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libswresample/swresample.h>
    #include <libavutil/imgutils.h>
}

// Grafica e Audio
#include <AL/al.h>
#include <AL/alc.h>

//Stub of OpenB3D texture

#include "texture.h"


// --- 1. CODA PACCHETTI THREAD-SAFE ---
struct PacketQueue {
    std::queue<AVPacket*> queue;
    std::mutex mtx;
    std::condition_variable cond;
    std::atomic<bool> quit{false};

    void push(AVPacket* pkt) {
        std::unique_lock<std::mutex> lock(mtx);
        queue.push(av_packet_clone(pkt));
        cond.notify_one();
    }

    bool pop(AVPacket** pkt) {
        std::unique_lock<std::mutex> lock(mtx);
        cond.wait(lock, [this] { return !queue.empty() || quit; });
        if (quit && queue.empty()) return false;
        *pkt = queue.front();
        queue.pop();
        return true;
    }

    void stop() { quit = true; cond.notify_all(); }
};

// --- 2. IL PLAYER ---
class VideoPlayer {
public:
    // Contexts
    AVFormatContext* fmt_ctx = nullptr;
    AVCodecContext *v_ctx = nullptr, *a_ctx = nullptr;
    SwsContext* sws_ctx = nullptr;
    SwrContext* swr_ctx = nullptr;

    // Queues
    PacketQueue v_queue, a_queue;
    
    // Sync & States
    std::atomic<double> audio_clock{0.0};
    double total_audio_played_time = 0.0;
    int v_stream_idx = -1, a_stream_idx = -1;

    // Audio Buffer (Resampling)
    uint8_t* a_out_buffer = nullptr;
    int max_a_out_samples = 0;

    // OpenAL & OpenGL IDs
    ALuint alSource;
    ALuint alBuffers[4];
    GLuint textureID;

    //Threads
    std::thread t_read;
    std::thread t_audio;


    bool open(const char* url) {
        if (avformat_open_input(&fmt_ctx, url, NULL, NULL) < 0) return false;
        avformat_find_stream_info(fmt_ctx, NULL);

        for (int i = 0; i < fmt_ctx->nb_streams; i++) {
            if (fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) v_stream_idx = i;
            if (fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) a_stream_idx = i;
        }

        setupVideo();
        setupAudio();
        return true;
    }

    void setupVideo() {
        auto par = fmt_ctx->streams[v_stream_idx]->codecpar;
        v_ctx = avcodec_alloc_context3(avcodec_find_decoder(par->codec_id));
        avcodec_parameters_to_context(v_ctx, par);
        avcodec_open2(v_ctx, avcodec_find_decoder(par->codec_id), NULL);
        
        sws_ctx = sws_getContext(v_ctx->width, v_ctx->height, v_ctx->pix_fmt,
                                 v_ctx->width, v_ctx->height, AV_PIX_FMT_RGB24, SWS_BILINEAR, NULL, NULL, NULL);
    }

    void setupAudio() {
        auto par = fmt_ctx->streams[a_stream_idx]->codecpar;
        a_ctx = avcodec_alloc_context3(avcodec_find_decoder(par->codec_id));
        avcodec_parameters_to_context(a_ctx, par);
        avcodec_open2(a_ctx, avcodec_find_decoder(par->codec_id), NULL);

        AVChannelLayout out_layout;
        av_channel_layout_default(&out_layout, 2);
        swr_alloc_set_opts2(&swr_ctx, &out_layout, AV_SAMPLE_FMT_S16, 44100,
                            &a_ctx->ch_layout, a_ctx->sample_fmt, a_ctx->sample_rate, 0, NULL);
        swr_init(swr_ctx);

        alGenSources(1, &alSource);
        alGenBuffers(4, alBuffers);
    }

    // --- LOGICA THREAD AUDIO ---
    void audioThread() {
        AVFrame* frame = av_frame_alloc();
        AVPacket* pkt = nullptr;
        int buf_idx = 0;

        while (a_queue.pop(&pkt)) {
            avcodec_send_packet(a_ctx, pkt);
            while (avcodec_receive_frame(a_ctx, frame) == 0) {
                // Resampling
                int out_samples = swr_get_out_samples(swr_ctx, frame->nb_samples);
                av_samples_alloc(&a_out_buffer, NULL, 2, out_samples, AV_SAMPLE_FMT_S16, 0);
                int converted = swr_convert(swr_ctx, &a_out_buffer, out_samples, (const uint8_t**)frame->data, frame->nb_samples);
                int data_size = av_samples_get_buffer_size(NULL, 2, converted, AV_SAMPLE_FMT_S16, 1);

                // OpenAL Streaming
                ALint processed;
                alGetSourcei(alSource, AL_BUFFERS_PROCESSED, &processed);
                
                // Se la coda è piena (4 buffer), aspetta che uno si liberi
                while (processed == 0) {
                    ALint queued;
                    alGetSourcei(alSource, AL_BUFFERS_QUEUED, &queued);
                    if (queued < 4) break; 
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    alGetSourcei(alSource, AL_BUFFERS_PROCESSED, &processed);
                }

                ALuint bid;
                if (processed > 0) {
                    alSourceUnqueueBuffers(alSource, 1, &bid);
                    total_audio_played_time += (double)data_size / (2 * 2 * 44100.0);
                } else {
                    ALint queued;
                    alGetSourcei(alSource, AL_BUFFERS_QUEUED, &queued);
                    bid = alBuffers[queued];
                }

                alBufferData(bid, AL_FORMAT_STEREO16, a_out_buffer, data_size, 44100);
                alSourceQueueBuffers(alSource, 1, &bid);

                ALint state;
                alGetSourcei(alSource, AL_SOURCE_STATE, &state);
                if (state != AL_PLAYING) alSourcePlay(alSource);

                // Sync Clock
                float offset;
                alGetSourcef(alSource, AL_SEC_OFFSET, &offset);
                audio_clock.store(total_audio_played_time + offset);
            }
            av_packet_free(&pkt);
        }
        av_frame_free(&frame);
    }

    // --- LOGICA THREAD READER ---
    void readerThread() {
        AVPacket pkt;
        while (av_read_frame(fmt_ctx, &pkt) >= 0) {
            if (pkt.stream_index == v_stream_idx) v_queue.push(&pkt);
            else if (pkt.stream_index == a_stream_idx) a_queue.push(&pkt);
            else av_packet_unref(&pkt);

            // Throttle: non leggere troppo veloci
            while (v_queue.queue.size() > 50) std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};




class MovieTexture : public Texture {
    AVFrame* v_frame;
    AVFrame* v_frame_rgb;
    uint8_t* v_buf;
public:
	VideoPlayer player;

	static MovieTexture* LoadMovieTexture(const char* filename,int flags=0);
	void FreeMovieTexture();
	void updateVideoTex();
};


MovieTexture* MovieTexture::LoadMovieTexture(const char* filename, int flags) {
        // 1. Apri il file e trova lo stream video
	MovieTexture* tex=new MovieTexture();
	tex_list.push_back(tex);

    // Init OpenAL Context
    ALCdevice* dev = alcOpenDevice(NULL);
    ALCcontext* ctx = alcCreateContext(dev, NULL);
    alcMakeContextCurrent(ctx);

        if (!tex->player.open(filename)) return 0;



    tex->v_frame = av_frame_alloc();
    tex->v_frame_rgb = av_frame_alloc();
    tex->v_buf = (uint8_t*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB24, tex->player.v_ctx->width, tex->player.v_ctx->height, 1));
	av_image_fill_arrays(tex->v_frame_rgb->data, tex->v_frame_rgb->linesize, tex->v_buf, AV_PIX_FMT_RGB24, tex->player.v_ctx->width, tex->player.v_ctx->height, 1);

tex->player.t_read= std::thread(&VideoPlayer::readerThread, &tex->player);
tex->player.t_audio=std::thread(&VideoPlayer::audioThread, &tex->player);

        // 5. Crea la Texture OpenGL

	tex->flags=flags;
	tex->FilterFlags();
	tex->width=tex->player.v_ctx->width;
	tex->height=tex->player.v_ctx->height;

	unsigned int name;
	glGenTextures (1,&name);
	tex->texture=name;


//        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, name);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->player.v_ctx->width, tex->player.v_ctx->height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
        
        return tex;
}

void MovieTexture::updateVideoTex() {
        AVPacket* pkt = nullptr;
        if (player.v_queue.pop(&pkt)) {
            avcodec_send_packet(player.v_ctx, pkt);
            while (avcodec_receive_frame(player.v_ctx, v_frame) == 0) {
                double pts = v_frame->best_effort_timestamp * av_q2d(player.fmt_ctx->streams[player.v_stream_idx]->time_base);
                
                // Sync: Aspetta l'audio
                while (pts > player.audio_clock.load() + 0.01) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }

                // Render
                sws_scale(player.sws_ctx, v_frame->data, v_frame->linesize, 0, player.v_ctx->height, v_frame_rgb->data, v_frame_rgb->linesize);
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, player.v_ctx->width, player.v_ctx->height, GL_RGB, GL_UNSIGNED_BYTE, v_frame_rgb->data[0]);
		glGenerateMipmap(GL_TEXTURE_2D);
            }
            av_packet_free(&pkt);
        }
    }



extern "C" {
MovieTexture* LoadMovieTexture(char* file,int flags){
	return MovieTexture::LoadMovieTexture(file,flags);
}

void updateVideoTex(MovieTexture* m){
	m->updateVideoTex();
}
}