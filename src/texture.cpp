#ifdef EMSCRIPTEN
#include <GLES3/gl3.h>
#include <GLES3/gl2ext.h>
#define GLES2
#endif


/*
 *  texture.mm
 *  iminib3d
 *
 *  Created by Simon Harrison.
 *  Copyright Si Design. All rights reserved.
 *
 */

#ifdef linux
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#endif

#ifdef WIN32
#include <gl\GLee.h>
#include <GL\glu.h>
#endif

#ifdef __APPLE__
#include "GLee.h"
#include <OpenGL/glu.h>
#endif


#include "texture.h"
#include "stb_image.h"

#include "texture_filter.h"
#include "string_helper.h"
#include "file.h"
#include "global.h"
#include "shadow.h"

#include <string.h>

list<Texture*> Texture::tex_list;

void CopyPixels (unsigned char *src, unsigned int srcWidth, unsigned int srcHeight, unsigned int srcX, unsigned int srcY, unsigned char *dst, unsigned int dstWidth, unsigned int dstHeight, unsigned int bytesPerPixel);


Texture* Texture::LoadTexture(string filename,int flags){
	if (flags&128) {
		//filename=Strip(filename); // get rid of path info
		filename=File::ResourceFilePath(filename);

		/*if (filename==""){
			cout << "Error: Cannot Find Texture: " << filename << endl;
			return NULL;
		}*/

		Texture* tex=new Texture();
		tex->file=filename;

		// set tex.flags before TexInList
		tex->flags=flags;
		tex->FilterFlags();

		// check to see if texture with same properties exists already, if so return existing texture
		Texture* old_tex=tex->TexInList();
		if(old_tex){
			delete tex;
			return old_tex;
		}else{
			tex_list.push_back(tex);
		}

		string filename_left=Left(filename,Len(filename)-4);
		string filename_right=Right(filename,3);
		//const char* c_filename_left=filename_left.c_str();
		//const char* c_filename_right=filename_right.c_str();
		unsigned char* buffer;
		buffer=stbi_load(filename.c_str(),&tex->width,&tex->height,0,4);

		unsigned int name;
		tex->no_frames=1;
		tex->width=tex->width/6;
		tex->frames=new unsigned int[6];

		unsigned char* dstbuffer=new unsigned char[tex->width*tex->height*4];
		glGenTextures (1,&name);
		glBindTexture (GL_TEXTURE_CUBE_MAP,name);

		//tex.gltex=tex.gltex[..tex.no_frames]
		for (int i=0;i<6;i++){
			CopyPixels (buffer,tex->width*6, tex->height,tex->width*i, 0, dstbuffer, tex->width, tex->height, 4);
#ifndef GLES2
			switch(i){
				case 0:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 1:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 2:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 3:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 4:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 5:
					gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
			}
		}
#else
			switch(i){
				case 0:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 1:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 2:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 3:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 4:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
				case 5:
					glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
					break;
			}
		}
		glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
#endif
		delete[] dstbuffer;
		stbi_image_free(buffer);

		tex->texture=name;
		return tex;
	}
	else
	{
	  return Texture::LoadAnimTexture(filename,flags,0,0,0,1);
	}
}


Texture* Texture::LoadAnimTexture(string filename,int flags, int frame_width,int frame_height,int first_frame,int frame_count){

	//filename=Strip(filename); // get rid of path info

	filename=File::ResourceFilePath(filename);

	/*if (filename==""){
		cout << "Error: Cannot Find Texture: " << filename << endl;
		return NULL;
	}*/

	Texture* tex=new Texture();
	tex->file=filename;

	// set tex.flags before TexInList
	tex->flags=flags;
	tex->FilterFlags();

	// check to see if texture with same properties exists already, if so return existing texture
	Texture* old_tex=tex->TexInList();
	if(old_tex){
		delete tex;
		return old_tex;
	}else{
		tex_list.push_back(tex);
	}

	string filename_left=Left(filename,Len(filename)-4);
	string filename_right=Right(filename,3);

	//const char* c_filename_left=filename_left.c_str();
	//const char* c_filename_right=filename_right.c_str();



	unsigned char* buffer;

	buffer=stbi_load(filename.c_str(),&tex->width,&tex->height,0,4);

	unsigned int name;
	if (frame_count<2){
		glGenTextures (1,&name);
		glBindTexture (GL_TEXTURE_2D,name);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
#ifndef GLES2
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
#else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
		glGenerateMipmap(GL_TEXTURE_2D);
#endif

		tex->texture=name;
	} else {


		tex->no_frames=frame_count;
		tex->frames=new unsigned int[frame_count];

		unsigned char* dstbuffer=new unsigned char[frame_width*frame_height*4];


		//tex.gltex=tex.gltex[..tex.no_frames]

		int frames_in_row=tex->width/frame_width;


		for (int i=0;i<frame_count;i++){
			CopyPixels (buffer,tex->width, tex->height,frame_width*(i%frames_in_row), frame_height*(i/frames_in_row),
			dstbuffer, frame_width, frame_height, 4);

			glGenTextures (1,&name);
			glBindTexture (GL_TEXTURE_2D,name);
#ifndef GLES2
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,frame_width, frame_height, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
#else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame_width, frame_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dstbuffer);
			glGenerateMipmap(GL_TEXTURE_2D);
#endif

			tex->frames[i]=name;
		}

		tex->texture=tex->frames[0];
		tex->width=frame_width;
		tex->height=frame_height;
		delete[] dstbuffer;

	}
	stbi_image_free(buffer);

	return tex;

}

Texture* Texture::CreateTexture(int width,int height,int flags, int frames){

	Texture* tex=new Texture();
	tex_list.push_back(tex);

	tex->flags=flags;
	tex->FilterFlags();
	tex->width=width;
	tex->height=height;

	unsigned int name;
	glGenTextures (1,&name);
	tex->texture=name;


	return tex;

}

void Texture::FreeTexture(){
	tex_list.remove(this);
	delete this;
}

void Texture::DrawTexture(int x,int y){
  //	[texture drawAtPoint:CGPointMake(x,y)];
}

void Texture::TextureBlend(int blend_no){
	blend=blend_no;
}

void Texture::TextureCoords(int coords_no){
	coords=coords_no;
}

void Texture::ScaleTexture(float u_s,float v_s){
	u_scale=1.0/u_s;
	v_scale=1.0/v_s;
}

void Texture::PositionTexture(float u_p,float v_p){
	u_pos=-u_p;
	v_pos=-v_p;
}

void Texture::RotateTexture(float ang){
	angle=ang;
}

/*
Method TextureWidth()

	Return width

End Method

Method TextureHeight()

	Return height

End Method
*/

string Texture::TextureName(){
	return file;
}

void Texture::ClearTextureFilters(){
	TextureFilter::tex_filter_list.clear();
}

void Texture::AddTextureFilter(string text_match,int flags){
	TextureFilter* filter=new TextureFilter();
	filter->text_match=text_match;
	filter->flags=flags;
	TextureFilter::tex_filter_list.push_back(filter);
}

Texture* Texture::TexInList(){
	// check if tex already exists in list and if so return it
	list<Texture*>::iterator it;
	for(it=tex_list.begin();it!=tex_list.end();it++){
		Texture* tex=*it;
		if(file==tex->file && flags==tex->flags){// && blend==tex->blend){
			//if(u_scale==tex->u_scale && v_scale==tex->v_scale && u_pos==tex->u_pos && v_pos==tex->v_pos && angle==tex->angle){
				return tex;
			//}
		}
	}
	return NULL;
}

void Texture::FilterFlags(){
	// combine specifieds flag with texture filter flags
	list<TextureFilter*>::iterator it;
	for(it=TextureFilter::tex_filter_list.begin();it!=TextureFilter::tex_filter_list.end();it++){
		TextureFilter* filter=*it;
		if(Instr(file,filter->text_match)) flags=flags|filter->flags;
	}
}

// used in LoadTexture, strips path info from filename
/*string Texture::Strip(string filename){
	string stripped_filename=filename;
	string::size_type idx;

	idx=filename.find('/');
	if(idx!=string::npos){
		stripped_filename=filename.substr(filename.rfind('/')+1);
	}

	idx=filename.find("\\");
	if(idx!=string::npos){
		stripped_filename=filename.substr(filename.rfind("\\")+1);
	}

	return stripped_filename;

}*/

void Texture::BufferToTex(unsigned char* buffer, int frame){
	if(flags&128){
		glBindTexture (GL_TEXTURE_CUBE_MAP,texture);
#ifndef GLES2
		switch (cube_face){
		case 0:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 1:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 2:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 3:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 4:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 5:
			gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		}
#else
		switch(cube_face){
		case 0:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 1:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 2:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 3:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 4:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		case 5:
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
			break;
		}
		glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

#endif
	}else{
		glBindTexture (GL_TEXTURE_2D,texture);
#ifndef GLES2
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
#else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
		glGenerateMipmap(GL_TEXTURE_2D);
#endif
	}

}

void Texture::BackBufferToTex(int frame){
	if(flags&128){
		glBindTexture (GL_TEXTURE_CUBE_MAP,texture);
		switch (cube_face){
		case 0:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		case 1:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		case 2:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		case 3:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		case 4:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		case 5:
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y,0,GL_RGBA,0,Global::height-height,width,height,0);
			break;
		}
#ifndef GLES2
		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
#else
		glGenerateMipmap(GL_TEXTURE_2D);
#endif
	}else{
		glBindTexture (GL_TEXTURE_2D,texture);
		glCopyTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,0,Global::height-height,width,height,0);
#ifndef GLES2
		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
#else
		glGenerateMipmap(GL_TEXTURE_2D);
#endif
	}
}

void Texture::CameraToTex(Camera* cam, int frame){

	GLenum target;

	Global::camera_in_use=cam;

	if(flags&128){
		target=GL_TEXTURE_CUBE_MAP;
	}else{
		target=GL_TEXTURE_2D;
	}
	

	glBindTexture (target, texture);

	if (framebuffer==0){
		framebuffer=new unsigned int[2];
		glGenFramebuffers(1, &framebuffer[0]);
		glGenRenderbuffers(1, &framebuffer[1]);
		if(flags&128){
			for (int i=0;i<6;i++){
				switch(i){
					case 0:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
					case 1:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
					case 2:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
					case 3:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
					case 4:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
					case 5:
						glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
						break;
				}
			}
		}else{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		}

	}

	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[0]);

	if(flags&128){
		switch (cube_face){
		case 0:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, texture, 0);
			break;
		case 1:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, texture, 0);
			break;
		case 2:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X, texture, 0);
			break;
		case 3:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, texture, 0);
			break;
		case 4:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, texture, 0);
			break;
		case 5:
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, texture, 0);
			break;
		}

	}else{
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
	}

	//Depth buffer
	glBindRenderbuffer(GL_RENDERBUFFER, framebuffer[1]);
	glRenderbufferStorage( GL_RENDERBUFFER, GL_DEPTH_STENCIL, width, height);
#ifndef GLES2
	glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, framebuffer[1]); 
	glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, framebuffer[1]); 
#else
	glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, framebuffer[1]); 
#endif

	cam->Render();

	if (Global::Shadows_enabled==true)
		ShadowObject::Update(cam);


	glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, 0); 

	glGenerateMipmap(target);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);


}


void Texture::TexToBuffer(unsigned char* buffer, int frame){
#ifndef GLES2
	glBindTexture (GL_TEXTURE_2D,texture);
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
#endif
}


void Texture::DepthBufferToTex(Camera* cam=0 ){
	glBindTexture(GL_TEXTURE_2D,texture);
	if (cam==0){
		glCopyTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,0,Global::height-height,width,height,0);
#ifndef GLES2
		glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP_SGIS,GL_TRUE);
#endif
	}else{
		Global::camera_in_use=cam;
		if (framebuffer==0){
			framebuffer=new unsigned int[1];
			glGenFramebuffers(1, &framebuffer[0]);
			//glGenRenderbuffers(1, &framebuffer[1]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, 0);

			glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[0]);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
		}else{
			glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[0]);
		}

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
		//glBindRenderbuffer(GL_RENDERBUFFER, framebuffer[1]);

		cam->Render();
		//glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, 0); 

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		//glBindRenderbuffer(GL_RENDERBUFFER, 0);

	}
}


void CopyPixels (unsigned char *src, unsigned int srcWidth, unsigned int srcHeight, unsigned int srcX, unsigned int srcY, unsigned char *dst, unsigned int dstWidth, unsigned int dstHeight, unsigned int bytesPerPixel) {
  // Copy image data line by line
  unsigned int y;
  for (y = 0; y < dstHeight; y++)
    memcpy (dst + y * dstWidth * bytesPerPixel, src + ((y + srcY) * srcWidth + srcX) * bytesPerPixel, dstWidth * bytesPerPixel);
}

