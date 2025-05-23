#ifndef SHADER_MAT_H
#define SHADER_MAT_H


//#include "global.h"
#include "matrix.h"
//#include "surface.h"
#include "texture.h"
#include "shaderobject.h"

#include <string>
#include <sstream>

class Surface;
class Entity;

class ShaderData{
	public:
	int name;
	int type;
	union{
		//float valuef[3];
		//int valuei[3];
		//double valued[3];
		float* fp[4];
		int* ip[4];
		Entity* ent;
		struct {
			Surface* surf;
			int vbo;
		};
		struct {
			void (*Enable)(void);
			void (*Disable)(void);
		};
	};
};

class Material : public Texture{
public:
	static Material* LoadMaterial(string filename,int flags=0, int frame_width=0,int frame_height=0,int first_frame=0,int frame_count=1);
	void BufferToMaterial(unsigned char* buffer);
	void MaterialToBuffer(unsigned char* buffer);
};


class Sampler{
public:
	Texture* texture;
	int Slot;
	int is3D;
	
	static Sampler* Create(int Slot, Texture* Tex);

};



class Shader {//: public MaterialPlugin{
	//static int ShaderIDCount;

	int texCount;
	Sampler* Shader_Tex[255];
	ProgramObject* arb_program;
	//int ID;
	//string name;

	vector<ShaderData> Parameters;


	//-------------------------------------------------------------------------------	
	
	//void UpdateData(Surface* surf);
	
	// internal 
public:
	int tex_coords0_loc;
	int tex_coords1_loc;
	int norms_loc;
	int cols_loc;
	int cols3_loc;
#ifndef GLES2
	unsigned int legacy;
	union{
		Surface* surf;
		vector<float>* vertices;
	};
#endif

	static list<Shader*> shader_list;

	static Shader* CreateShaderMaterial(string Name = "");
	void TurnOn(Matrix& mat, Brush* brush=0);
	void TurnOff();
	int AddShader(string _vert, int type);
	int AddShaderFromString(string _shader, int type);
	void Link();

	void AddSampler(string Name, int Slot, Texture* Tex, int is3D);
	void ProgramAttriBegin();
	void ProgramAttriEnd();
	void FreeShader();

	void SetFloat(string name, float v1);
	void SetFloat2(string name, float v1, float v2);
	void SetFloat3(string name, float v1, float v2, float v3);
	void SetFloat4(string name, float v1, float v2, float v3, float v4);
	void UseFloat(string name, float* v1);
	void UseFloat2(string name, float* v1, float* v2);
	void UseFloat3(string name, float* v1, float* v2, float* v3);
	void UseFloat4(string name, float* v1, float* v2, float* v3, float* v4);
	void SetInteger(string name, int v1);
	void SetInteger2(string name, int v1, int v2);
	void SetInteger3(string name, int v1, int v2, int v3);
	void SetInteger4(string name, int v1, int v2, int v3, int v4);
	void UseInteger(string name, int* v1);
	void UseInteger2(string name, int* v1, int* v2);
	void UseInteger3(string name, int* v1, int* v2, int* v3);
	void UseInteger4(string name, int* v1, int* v2, int* v3, int* v4);

	void UseSurface(string name, Surface* surf, int vbo);
	void UseMatrix(string name, int mode);
	void UseEntity(string name, Entity* ent, int mode);
	void UseFunction(void (*Enable)(void), void (*Disable)(void));

	int GetProgram(){return arb_program->Program;}
	/*void SetParameter1S(string name, float v1);
	void SetParameter2S(string name, float v1, float v2);
	void SetParameter3S(string name, float v1, float v2, float v3);
	void SetParameter4S(string name, float v1, float v2, float v3, float v4);
	void SetParameter1I(string name, int v1);
	void SetParameter2I(string name, int v1, int v2);
	void SetParameter3I(string name, int v1, int v2, int v3);
	void SetParameter4I(string name, int v1, int v2, int v3, int v4);
	void SetVector1I(string name, int* v1);
	void SetVector2I(string name, int* v1);
	void SetVector3I(string name, int* v1);
	void SetVector4I(string name, int* v1);
	void SetParameter1F(string name, float v1);
	void SetParameter2F(string name, float v1, float v2);
	void SetParameter3F(string name, float v1, float v2, float v3);
	void SetParameter4F(string name, float v1, float v2, float v3, float v4);
	void SetVector1F(string name, float* v1);
	void SetVector2F(string name, float* v1);
	void SetVector3F(string name, float* v1);
	void SetVector4F(string name, float* v1);
	void SetMatrix2F(string name, float* m);
	void SetMatrix3F(string name, float* m);
	void SetMatrix4F(string name, float* m);
	void SetParameter1D(string name, double v1);
	void SetParameter2D(string name, double v1, double v2);
	void SetParameter3D(string name, double v1, double v2, double v3);
	void SetParameter4D(string name, double v1, double v2, double v3, double v4);*/

};

#endif
