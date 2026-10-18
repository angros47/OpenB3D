#ifdef EMSCRIPTEN
#include <GLES2/gl2.h>
#define GLES2
#endif

#ifdef linux
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#endif

#ifdef WIN32
#include <gl\GLee.h>
#endif

#ifdef __APPLE__
#include "GLee.h"
#endif

#include "mesh.h"
#include "global.h"
#include "camera.h"




#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>


GLint GaussianShader=0;

const char* vertexShaderSource = 
    "#version 300 es\n"
    "precision highp float;\n"
    "precision highp sampler2D;\n"
    "\n"
    "uniform sampler2D u_dataTexture;\n"
    "uniform int u_textureWidth;\n"
    "uniform int u_startOffset;\n" 
    "uniform mat4 u_view;\n"
    "uniform mat4 u_projection;\n"
    "uniform vec2 u_viewport;\n"
    "\n"
    "out vec2 v_uv;\n"
    "out vec4 v_color;\n"
    "out vec3 v_conic;\n"
    "\n"
    "mat3 quatToMat3(vec4 q) {\n"
    "    float x = q.x, y = q.y, z = q.z, w = q.w;\n"
    "    // Standard Column-Major Matrix\n"
    "    return mat3(\n"
    "        1.0 - 2.0*(y*y + z*z), 2.0*(x*y + w*z), 2.0*(x*z - w*y), // Colonna 0\n"
    "        2.0*(x*y - w*z), 1.0 - 2.0*(x*x + z*z), 2.0*(y*z + w*x), // Colonna 1\n"
    "        2.0*(x*z + w*y), 2.0*(y*z - w*x), 1.0 - 2.0*(x*x + y*y)  // Colonna 2\n"
    "    );\n"
    "}\n"
    "\n"
    "void main() {\n"
    "    // 1. Fetch Dati\n"
    "    int globalID = gl_InstanceID + u_startOffset;\n"
    "\n"
    "    int x = globalID % u_textureWidth;\n"
    "    int y = globalID / u_textureWidth;\n" 
    "    vec4 data0 = texelFetch(u_dataTexture, ivec2(x * 4, y), 0);\n"
    "    vec4 data1 = texelFetch(u_dataTexture, ivec2(x * 4 + 1, y), 0);\n"
    "    vec4 data2 = texelFetch(u_dataTexture, ivec2(x * 4 + 2, y), 0);\n"
    "    vec4 data3 = texelFetch(u_dataTexture, ivec2(x * 4 + 3, y), 0);\n"
    "\n"
    "    vec3 pos = data0.xyz;\n"
    "    // Se sembrano sbagliati, prova exp() qui\n"
    "    v_color = data1;\n"
    "    vec3 cov1 = data2.xyz;\n"
    "    vec3 cov2 = data3.xyz;\n"
    "\n"
    "    // 2. Calcolo Posizione in View Space (FONDAMENTALE)\n"
    "// 1. Posizione View Space\n"
    "    vec4 camPos = u_view * vec4(pos, 1.0);\n"
    "    if (camPos.z > -0.1) { gl_Position = vec4(0.0); return; }\n"
    "\n"
    "    // 2. Covarianza 3D in WORLD SPACE (Sigma = R * S * S^T * R^T)\n"
    "    mat3 sigmaWorld = mat3(\n"
    "        cov1.x, cov1.y, cov1.z,\n"
    "        cov1.y, cov2.x, cov2.y,\n"
    "        cov1.z, cov2.y, cov2.z\n"
    "    );\n"
    "\n"
    "    // 3. Trasformazione in VIEW SPACE\n"
    "    // Estraiamo la rotazione pura dalla view matrix\n"
    "    mat3 W = mat3(u_view); \n"
    "    // Sigma_view = W * Sigma_world * W^T\n"
    "    mat3 sigmaView = W * sigmaWorld * transpose(W);\n"
    "\n"
    "    // 4. Proiezione 2D con Jacobiano (Versione Semplificata)\n"
    "    float z = camPos.z;\n"
    "    float focal_x = u_projection[0][0] * u_viewport.x * 0.5;\n"
    "    float focal_y = u_projection[1][1] * u_viewport.y * 0.5;\n"
    "\n"
    "    // Elementi del Jacobiano proiettati\n"
    "    float m11 = focal_x / z;\n"
    "    float m13 = -(focal_x * camPos.x) / (z * z);\n"
    "    float m22 = focal_y / z;\n"
    "    float m23 = -(focal_y * camPos.y) / (z * z);\n"
    "\n"
    "    // Costruiamo la covarianza 2D proiettando sigmaView\n"
    "    float cov11 = m11 * m11 * sigmaView[0][0] + m13 * m13 * sigmaView[2][2] + 2.0 * m11 * m13 * sigmaView[0][2];\n"
    "    float cov12 = m11 * m22 * sigmaView[0][1] + m11 * m23 * sigmaView[0][2] + m13 * m22 * sigmaView[1][2] + m13 * m23 * sigmaView[2][2];\n"
    "    float cov22 = m22 * m22 * sigmaView[1][1] + m22 * m23 * sigmaView[1][2] * 2.0 + m23 * m23 * sigmaView[2][2]; \n"
    "    // Nota: aggiunto il termine 2.0 * m22 * m23 * sigmaView[1][2] che mancava\n"
    "\n"
    "    mat2 cov2d = mat2(cov11, cov12, cov12, cov22);\n"
    "\n"
    "    // 5. Stabilizzazione e Conica\n"
    "    cov2d[0][0] += 0.3;\n"
    "    cov2d[1][1] += 0.3;\n"
    "\n"
    "    float det = cov2d[0][0] * cov2d[1][1] - cov2d[0][1] * cov2d[0][1];\n"
    "    if (det < 1e-6) { gl_Position = vec4(0.0); return; }\n"
    "    v_conic = vec3(cov2d[1][1], -cov2d[0][1], cov2d[0][0]) / det;\n"
    "\n"
    "    // 6. Output Geometria\n"
    "    // 1. Calcolo del raggio corretto (Autovalore massimo)\n"
    "    // Questo trova l'estensione reale dell'ellisse, non solo lungo gli assi x e y.\n"
    "    float mid = 0.5 * (cov2d[0][0] + cov2d[1][1]);\n"
    "    float term = sqrt(max(0.1, mid * mid - det));\n"
    "    float lambda1 = mid + term; // Autovalore massimo\n"
    "    \n"
    "    // Usiamo 4.0 invece di 3.0 perché nel fragment moltiplichi l'alpha per 4.0,\n"
    "    // rendendo visibili parti della gaussiana che normalmente sarebbero trasparenti.\n"
    "    float max_extent = sqrt(lambda1) * 4.0;\n"
    "    \n"
    "    // Protezione contro splat troppo grandi\n"
    "    max_extent = min(max_extent, u_viewport.x * 1.0); \n"
    "    \n"
    "    // 2. Generazione del triangolo (Procedural Geometry)\n"
    "    // Questa formula genera un triangolo che copre esattamente il quadrato [-1, 1]\n"
    "    // Vertici: (-1, -1), (3, -1), (-1, 3)\n"
    "    vec2 local_uv = vec2((gl_VertexID << 1) & 2, gl_VertexID & 2) * 2.0 - 1.0;\n"
    "    \n"
    "    // 3. Output\n"
    "    v_uv = local_uv * max_extent;\n"
    "    \n"
    "    vec4 centerProj = u_projection * camPos;\n"
    "    // Usiamo centerProj.w per mantenere la prospettiva corretta\n"
    "    gl_Position = vec4(centerProj.xy + (v_uv / u_viewport) * centerProj.w, centerProj.z, centerProj.w);\n"
    "}\0";

const char* fragmentShaderSource = 
    "#version 300 es\n"
    "precision highp float;\n"
    "\n"
    "in vec2 v_uv;\n"
    "in vec4 v_color;\n"
    "in vec3 v_conic;\n"
    "out vec4 fragColor;\n"
    "\n"
    "float ign(vec2 v) {\n"
    "    vec3 magic = vec3(0.06711056, 0.00583715, 52.9829189);\n"
    "    return fract(magic.z * fract(dot(v, magic.xy)));\n"
    "}\n"
    "float bayer4x4(vec2 screenPos) {\n"
    "    vec2 pos = mod(screenPos, 4.0);\n"
    "    int index = int(pos.x) + int(pos.y) * 4;\n"
    "    float table[16] = float[16](\n"
    "        0.0/16.0, 8.0/16.0, 2.0/16.0, 10.0/16.0,\n"
    "        12.0/16.0, 4.0/16.0, 14.0/16.0, 6.0/16.0,\n"
    "        3.0/16.0, 11.0/16.0, 1.0/16.0, 9.0/16.0,\n"
    "        15.0/16.0, 7.0/16.0, 13.0/16.0, 5.0/16.0\n"
    "    );\n"
    "    return table[index];\n"
    "}\n"
    "float rand(vec2 co) {\n"
    "    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);\n"
    "}\n"
    "\n"
    "void main() {\n"
    "    // Calcolo della potenza dell'esponente basato sulla conica 2D\n"
    "    // d2 = A*x^2 + B*x*y + C*y^2\n"
    "    float d2 = v_conic.x * v_uv.x * v_uv.x + \n"
    "               2.0 * v_conic.y * v_uv.x * v_uv.y + \n"
    "               v_conic.z * v_uv.y * v_uv.y;\n"
    "\n"
    "    if (d2 > 12.0) discard;\n"
    "\n"
    "    // Gaussiana 2D\n"
    "    float alpha = exp(-0.3 * d2) * v_color.a * 4.0;\n"
    "\n"
    "    alpha = smoothstep(0.0, 1.0, alpha);"
    "    // Modello stocastico\n"
    "    float threshold = ign(gl_FragCoord.xy);\n"
    "    if (alpha < threshold) discard;\n"
    "\n"
    "    fragColor = vec4(v_color.rgb, 1.0);\n"
    "}\0";

const char* fragmentShaderSourceAC = 
    "#version 300 es\n"
    "precision highp float;\n"
    "\n"
    "in vec2 v_uv;\n"
    "in vec4 v_color;\n"
    "in vec3 v_conic;\n"
    "out vec4 fragColor;\n"
    "\n"
    "void main() {\n"
    "    // Calcolo della potenza dell'esponente basato sulla conica 2D\n"
    "    // d2 = A*x^2 + B*x*y + C*y^2\n"
    "    float d2 = v_conic.x * v_uv.x * v_uv.x + \n"
    "               2.0 * v_conic.y * v_uv.x * v_uv.y + \n"
    "               v_conic.z * v_uv.y * v_uv.y;\n"
    "\n"
    "    if (d2 < 0.0) discard;\n"
    "\n"
    "    // Gaussiana 2D\n"
    "    float alpha = exp(-0.3 * d2) * v_color.a * 4.0;\n"
    "    fragColor = vec4(v_color.rgb, alpha);\n"
    "}\0";


// --- UTILITY FUNCTIONS ---

GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    // Controllo errori di compilazione
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERRORE COMPILAZIONE SHADER (%s):\n%s\n", 
               (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT"), infoLog);
        return 0;
    }
    return shader;
}

GLuint createShaderProgram() {
    GLint samples;
    glGetIntegerv(GL_SAMPLES, &samples);
samples=0;

    GLuint vertexShader, fragmentShader;
    vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    if (samples>1){
      fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSourceAC);
    }else{
      fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    }

    if (!vertexShader || !fragmentShader) return 0;

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Controllo errori di linking
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("ERRORE LINKING PROGRAMMA:\n%s\n", infoLog);
        return 0;
    }

    // Una volta linkati, gli shader singoli possono essere eliminati
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}


typedef struct {
    float s0, s1, s2, s3, s4, s5;
} Covariance3D;

Covariance3D compute_covariance_3d(const float scale[3], const float quat[4]) {
    // 1. Normalizzazione del quaternione
    float x = quat[1], y = quat[2], z = quat[3], w = quat[0];
    float inv_len = 1.0f / sqrtf(x*x + y*y + z*z + w*w);
    x *= inv_len; y *= inv_len; z *= inv_len; w *= inv_len;

    // 2. Costruzione della matrice di rotazione R dal quaternione
    float R[9];
    R[0] = 1.0f - 2.0f * (y * y + z * z);
    R[1] = 2.0f * (x * y - w * z);
    R[2] = 2.0f * (x * z + w * y);

    R[3] = 2.0f * (x * y + w * z);
    R[4] = 1.0f - 2.0f * (x * x + z * z);
    R[5] = 2.0f * (y * z - w * x);

    R[6] = 2.0f * (x * z - w * y);
    R[7] = 2.0f * (y * z + w * x);
    R[8] = 1.0f - 2.0f * (x * x + y * y);

    // 3. Matrice M = R * S (dove S è la matrice diagonale delle scale)
    // Non serve creare S, basta moltiplicare le colonne di R per le scale
    float M[9];
    for (int i = 0; i < 3; i++) {
        M[i*3 + 0] = R[i*3 + 0] * scale[0];
        M[i*3 + 1] = R[i*3 + 1] * scale[1];
        M[i*3 + 2] = R[i*3 + 2] * scale[2];
    }

    // 4. Covarianza Sigma = M * M^T (Simmetrica)
    Covariance3D cov;
    cov.s0 = M[0]*M[0] + M[1]*M[1] + M[2]*M[2]; // m11
    cov.s1 = M[0]*M[3] + M[1]*M[4] + M[2]*M[5]; // m12
    cov.s2 = M[0]*M[6] + M[1]*M[7] + M[2]*M[8]; // m13
    cov.s3 = M[3]*M[3] + M[4]*M[4] + M[5]*M[5]; // m22
    cov.s4 = M[3]*M[6] + M[4]*M[7] + M[5]*M[8]; // m23
    cov.s5 = M[6]*M[6] + M[7]*M[7] + M[8]*M[8]; // m33

    return cov;
}



typedef struct {
    float p0[4]; // Pixel 0: Pos.x, Pos.y, Pos.z, unused
    float p1[4]; // Pixel 1: Color.r, Color.g, Color.b, Color.a
    float p2[4]; // Pixel 2: Covariance 1, Covariance 2, Covariance 3, unused
    float p3[4]; // Pixel 2: Covariance 4, Covariance 5, Covariance 6, unused
} GpuSplat;









class GaussianSplat : public Mesh{
	/*struct GaussianData {
		float x, y, z;
		float nx, ny, nz; // Spesso usati per la scala o normali
		float f_dc_0, f_dc_1, f_dc_2; // Colore base (SH)
		float opacity;
		float scale_0, scale_1, scale_2;
		float rot_0, rot_1, rot_2, rot_3; // Quaternione
	};

	vector<GaussianData> data;*/
	//static int shader=0;

	// Informazioni sulla singola cella della griglia
	struct GridCell {
		int startIndex;
		int totalInstances;
		float center[3]; // X, Y, Z della sfera
		float radius;    // Raggio della sfera
	};

	// La nostra griglia piatta (Flat Grid)
	std::vector<GridCell> gridCells;
    
	// Dimensioni della griglia (impostabili a piacimento, es. 4x1x4 per il treno)
	int gridX;
	int gridY;
	int gridZ;


	struct SplatPoint {
		float pos[3];
		float scale[3];
		uint8_t rgba[4];
		uint8_t rot[4];
	};

	vector<SplatPoint> data;

	GLuint vao;
	GLuint data_texture;
	int no_gaussians;
	int currentInstances;


	std::vector<SplatPoint> LoadSplatFile(const std::string& filename);
public:


	static GaussianSplat* LoadGaussianSplat(char* filename, int divX=1, int divY=1, int divZ=1, Entity* parent_ent=NULL);
	GaussianSplat* CopyEntity(Entity* parent_ent=NULL);
	void FreeEntity(void);
	void Render();
	void SetSplatLOD(float factor);
};


std::vector<GaussianSplat::SplatPoint> GaussianSplat::LoadSplatFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) return {};

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Calcola quanti punti ci sono (dimensione totale / 32 byte)
    size_t count = size / sizeof(SplatPoint);

    std::vector<SplatPoint> points(count);

    if (file.read(reinterpret_cast<char*>(points.data()), size)) {
        return points;
    }

    return {};
}



GaussianSplat* GaussianSplat::LoadGaussianSplat(char* filename, int divX, int divY, int divZ, Entity* parent_ent){
	GaussianSplat* g= new GaussianSplat;

	g->AddParent(parent_ent);
	entity_list.push_back(g);
	g->min_x=-999999999;
	g->max_x=999999999;
	g->min_y=-999999999;
	g->max_y=999999999;
	g->min_z=-999999999;
	g->max_z=999999999;
	g->no_surfs=1;
	Surface* surf=new Surface();
	g->surf_list.push_back(surf);



	g->data=g->LoadSplatFile(filename);

g->gridX = divX;
g->gridY = divY;
g->gridZ = divZ;
    g->no_gaussians = g->data.size();

    // 1. TROVA L'AABB GLOBALE DELLA SCENA
    float gMin[3] = { 999999.0f,  999999.0f,  999999.0f};
    float gMax[3] = {-999999.0f, -999999.0f, -999999.0f};
    for (const auto& pt : g->data) {
        for(int i=0; i<3; ++i) {
            if(pt.pos[i] < gMin[i]) gMin[i] = pt.pos[i];
            if(pt.pos[i] > gMax[i]) gMax[i] = pt.pos[i];
        }
    }

    // 2. SMISTAMENTO NEI BUCKETS DELLA GRIGLIA
    int totalCells = g->gridX * g->gridY * g->gridZ;
    std::vector<std::vector<SplatPoint>> buckets(totalCells);

    for (const auto& pt : g->data) {
        // Calcola in quale cella si trova il punto (normalizzato 0.0 - 1.0)
        float tx = (pt.pos[0] - gMin[0]) / (gMax[0] - gMin[0]);
        float ty = (pt.pos[1] - gMin[1]) / (gMax[1] - gMin[1]);
        float tz = (pt.pos[2] - gMin[2]) / (gMax[2] - gMin[2]);

        int cx = std::clamp(static_cast<int>(tx * g->gridX), 0, g->gridX - 1);
        int cy = std::clamp(static_cast<int>(ty * g->gridY), 0, g->gridY - 1);
        int cz = std::clamp(static_cast<int>(tz * g->gridZ), 0, g->gridZ - 1);

        int cellIndex = cx + (cy * g->gridX) + (cz * g->gridX * g->gridY);
        buckets[cellIndex].push_back(pt);
    }

    // 3. ORDINAMENTO DI OGNI BUCKET (Grande -> Piccolo) E COSTRUZIONE GRIGLIA FINAL
    g->data.clear(); // Ricostruiamo il vettore originale ordinato spazialmente
    g->gridCells.clear();

    for (int i = 0; i < totalCells; i++) {
        if (buckets[i].empty()) continue;

        // Ordina il bucket corrente per dimensione (LOD)
        std::sort(buckets[i].begin(), buckets[i].end(), [](const SplatPoint& a, const SplatPoint& b) {
            float sizeA = a.scale[0] * a.scale[1] * a.scale[2];
            float sizeB = b.scale[0] * b.scale[1] * b.scale[2];
            return sizeA > sizeB;
        });

	// Registra le informazioni sulla cella
        GridCell cell;
        cell.startIndex = g->data.size();
        cell.totalInstances = buckets[i].size();

        // A. Calcoliamo prima il centro geometrico (media dei punti)
        double sumX = 0, sumY = 0, sumZ = 0;
        for (const auto& pt : buckets[i]) {
            sumX += pt.pos[0];
            sumY += pt.pos[1];
            sumZ += pt.pos[2];
        }
        cell.center[0] = static_cast<float>(sumX / buckets[i].size());
        cell.center[1] = static_cast<float>(sumY / buckets[i].size());
        cell.center[2] = static_cast<float>(sumZ / buckets[i].size());

        // B. Calcoliamo il raggio (la distanza massima dal centro)
        float maxDistSq = 0.0f;
        for (const auto& pt : buckets[i]) {
            float dx = pt.pos[0] - cell.center[0];
            float dy = pt.pos[1] - cell.center[1];
            float dz = pt.pos[2] - cell.center[2];
            float distSq = dx*dx + dy*dy + dz*dz;
            if (distSq > maxDistSq) maxDistSq = distSq;
        }
        // Aggiungiamo un piccolo margine fisso (es. +0.5) per evitare che gli splat 
        // sui bordi vengano tagliati prima del tempo a causa della loro dimensione fisica
        cell.radius = std::sqrt(maxDistSq) + 0.5f; 

        g->gridCells.push_back(cell);        // Registra le informazioni sulla cella

        // Inserisce i dati ordinati nel vettore principale globale
        g->data.insert(g->data.end(), buckets[i].begin(), buckets[i].end());
    }

    g->currentInstances = g->data.size(); // Default globale

    // [Il resto del codice per generare la texture texData rimane IDENTICO, 
    // perché legge sequenzialmente g->data che ora è ordinato a blocchi!]


	
	if (GaussianShader==0) GaussianShader=createShaderProgram();
	glGenVertexArrays(1, &g->vao);


    int width = 2048; // Larghezza fissa della texture
    int height = (g->no_gaussians + width - 1) / width;

    // Allochiamo memoria per la texture (3 pixel per splat)
    GpuSplat* texData = (GpuSplat*)calloc(width * height, sizeof(GpuSplat));

    for (int i = 0; i < g->no_gaussians; i++) {
	float quat[4];
	quat[0] = (g->data[i].rot[0] - 128.0f) / 128.0f;
	quat[1] = (g->data[i].rot[1] - 128.0f) / 128.0f;
	quat[2] = (g->data[i].rot[2] - 128.0f) / 128.0f;
	quat[3] = (g->data[i].rot[3] - 128.0f) / 128.0f;



	Covariance3D cov= compute_covariance_3d(g->data[i].scale, quat);

	// Pixel 0: Posizione + Scale.x
	texData[i].p0[0] = g->data[i].pos[0];
	texData[i].p0[1] = g->data[i].pos[1];
	texData[i].p0[2] = g->data[i].pos[2];
	texData[i].p0[3] = 0.0f;

	// Pixel 1: Scale.y, Scale.z, Color.r, Color.g
	texData[i].p1[0] = g->data[i].rgba[0] / 255.0f;
	texData[i].p1[1] = g->data[i].rgba[1] / 255.0f;
	texData[i].p1[2] = g->data[i].rgba[2] / 255.0f;
	texData[i].p1[3] = g->data[i].rgba[3] / 255.0f;

	// Pixel 2: Color.b, Color.a, Quat.x, Quat.y
	texData[i].p2[0] = cov.s0;
	texData[i].p2[1] = cov.s1;
	texData[i].p2[2] = cov.s2;
	texData[i].p2[3] = 0.0f;

	// Pixel 3: Quat.z, Quat.w, Padding
	texData[i].p3[0] = cov.s3;
	texData[i].p3[1] = cov.s4; 
	texData[i].p3[2] = cov.s5;
	texData[i].p3[3] = 0.0f;
    }


    glGenTextures(1, &g->data_texture);
    glBindTexture(GL_TEXTURE_2D, g->data_texture);
    
    // Impostazioni critiche per Data Texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Caricamento come FLOAT a 32 bit
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width * 4, height, 0, GL_RGBA, GL_FLOAT, texData);

    free(texData);


	return g;
}

GaussianSplat* GaussianSplat::CopyEntity(Entity* parent_ent){
	return 0;
}

void GaussianSplat::FreeEntity(void){
	Entity::FreeEntity();

	delete this;

	return;
}

void GaussianSplat::SetSplatLOD(float factor) {
    // factor va da 0.0 (vuoto) a 1.0 (massimo dettaglio)
    // Assicurati che il valore sia nel range
    factor = std::clamp(factor, 0.01f, 1.0f);
    
    // Calcola il numero di istanze da passare a glDrawArraysInstanced
    currentInstances = static_cast<int>(no_gaussians * factor);
}

void GaussianSplat::Render(){
    glUseProgram(GaussianShader);

    float cam_width  = Global::camera_in_use->vwidth;
    float cam_height = Global::camera_in_use->vheight;

    glUniform1i(glGetUniformLocation(GaussianShader, "u_textureWidth"), 2048);
    glUniform2f(glGetUniformLocation(GaussianShader, "u_viewport"), cam_width, cam_height); // Esempio

    GLint projLoc = glGetUniformLocation(GaussianShader, "u_projection");
    GLint viewLoc = glGetUniformLocation(GaussianShader, "u_view");
    GLint offsetLoc = glGetUniformLocation(GaussianShader, "u_startOffset"); // <--- NUOVA LOCAZIONE

    Matrix new_mat;
    Global::camera_in_use->mat.GetInverse(new_mat);
    new_mat.Multiply(mat);

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Global::camera_in_use->proj_mat[0]);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &new_mat.grid[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, data_texture);
    glUniform1i(glGetUniformLocation(GaussianShader, "u_dataTexture"), 0);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
    glDisable(GL_CULL_FACE);
    
    glBindVertexArray(vao);

    // Calcoliamo il fattore LOD corrente (basato su quante istanze totali vogliamo rispetto al massimo)
    float lodFactor = static_cast<float>(currentInstances) / static_cast<float>(no_gaussians);

    // ... dentro GaussianSplat::Render() prima del ciclo for ...

    // Recuperiamo il frustum della camera (adatta il puntatore alla tua libreria)
    auto& frustum = Global::camera_in_use->frustum; 

    float scaleX = std::sqrt(mat.grid[0][0]*mat.grid[0][0] + mat.grid[0][1]*mat.grid[0][1] + mat.grid[0][2]*mat.grid[0][2]);
    float scaleY = std::sqrt(mat.grid[1][0]*mat.grid[1][0] + mat.grid[1][1]*mat.grid[1][1] + mat.grid[1][2]*mat.grid[1][2]);
    float scaleZ = std::sqrt(mat.grid[2][0]*mat.grid[2][0] + mat.grid[2][1]*mat.grid[2][1] + mat.grid[2][2]*mat.grid[2][2]);
    float maxEntityScale = std::max({scaleX, scaleY, scaleZ});

    // CICLO SULLE CELLE DELLA GRIGLIA
    for (const auto& cell : gridCells) {
        
        // --- CONTROLLO DI VISIBILITÀ (Frustum Culling) ---
        bool visible = true;
        float x = cell.center[0];
        float y = cell.center[1];
        float z = -cell.center[2];
        float radius = cell.radius*maxEntityScale;
	mat.TransformVec(x, y, z, 1);

        for (int p = 0; p <= 5; p++) {
            float d = frustum[p][0] * x + 
                      frustum[p][1] * y + 
                      frustum[p][2] * -z + 
                      frustum[p][3];
            
            if (d <= -radius) {
                visible = false;
                break; // Fuori da questo piano, inutile controllare gli altri
            }
        }

        if (!visible) continue; // Salta il disegno di questo cubo!
        // --------------------------------------------------

        // Calcola quante istanze disegnare per questo specifico cubo
        int instancesToDraw = static_cast<int>(cell.totalInstances * lodFactor);
        if (instancesToDraw <= 0) continue;

        // Invia l'offset di questa cella allo shader
        glUniform1i(offsetLoc, cell.startIndex);

        // Disegna la fetta della texture legata a questa cella
        glDrawArraysInstanced(GL_TRIANGLES, 0, 3, instancesToDraw);
    }

    glBindVertexArray(0);
    glUseProgram(0);
}


extern "C"{
GaussianSplat* LoadGaussianSplat(char* filename,int divX=1, int divY=1, int divZ=1, Entity* parent_ent=NULL){
	return GaussianSplat::LoadGaussianSplat(filename, divX, divY, divZ, parent_ent);
}

void SetSplatLOD(GaussianSplat* s, float factor) {
	s->SetSplatLOD(factor);
}

}