//#include <map>

#include "string_helper.h"
#include "entity.h"
#include "mesh.h"
#include "file.h"
#include<algorithm>

namespace LoadOBJ{
struct FaceData{

	int vi;
	int ti;
	int ni;
	int its;
};


inline vector<string> split(const string& strValue, char separator){
	vector<string> vecstrResult;
	int startpos=0;
	int endpos=0;

	endpos = strValue.find_first_of(separator, startpos);
	while (endpos != -1)
	{       
		vecstrResult.push_back(strValue.substr(startpos, endpos-startpos)); // add to vector
		startpos = endpos+1; //jump past sep
		endpos = strValue.find_first_of(separator, startpos); // find next
	}
	//lastone, so no 2nd param required to go to end of string
	vecstrResult.push_back(strValue.substr(startpos));
        
	    

	return vecstrResult;
}

/*inline vector<string> CustomSplit(const string& st, char delim){
	
		// handles n/n/n as 3 numbers even when n//n
		vector<string> out;

		if (st.length() < 1) return {"","",""};
		
		int n=0, nn=0;
		int reset = 1;
		//string s;
		
		for (unsigned int i=0; i<st.length();i++){
			if (reset){
				out.push_back("0");
				reset = 0;
			}
			if (st[i] == delim){
				//int ii = i + nn;
				//s = st.substr(i,nn);
				
				n++;
				reset = 1;
			}else{
				out[n] +=st[i];
			}
		}
		
		return out;
}*/


class ObjNormal{
public:

	float nx, ny, nz;
	
	void GetValues(string data){
	
		int comp=0;
		vector<string> values = split(data, ' ');
		
		for (unsigned int i=0;i<values.size();i++){
			if (values[i].length() > 0){
				values[comp] = values[i];
				comp++;
			}
		}
		
		nx = ::atof(values[0].c_str());
		ny = ::atof(values[1].c_str());
		nz = ::atof(values[2].c_str());
		
		//DebugLog "X:" + nx + " Y:" + ny + " Z:" + nz
		
	}
	
};

class ObjTexCoord{
public:

	float u, v, w;
	
	void GetValues(string data){
	
		int comp=0;
		vector<string> values = split(data, ' ');
		
		for (unsigned int i=0;i<values.size();i++){
			if (values[i].length() > 0){
				values[comp] = values[i];
				comp++;
			}
		}
		
		u = ::atof(values[0].c_str());
		v = ::atof(values[1].c_str());
		
		if (comp == 2) return;
		
		w = ::atof(values[comp-1].c_str());
		
		//DebugLog "X:" + u + " Y:" + v + " W:" + w
		
	}
	
};

class ObjVertex{
public:

	float x, y, z, w; // w = weight for curves + surfaces
	float r, g, b; // added support for vertex colors
	
	void GetValues(string data){
	
		int comp=0;
		vector<string> values = split(data, ' ');
		
		for (unsigned int i=0;i<values.size();i++){
			if (values[i].length() > 0){
				values[comp] = values[i];
				comp++;
			}
		}
		
		x = ::atof(values[0].c_str());
		y = ::atof(values[1].c_str());
		z = ::atof(values[2].c_str());
		
		if (comp == 3 || comp == 4) {
			r=g=b=255.0;
			return;
		}
		
		r = abs(::atof(values[comp-3].c_str()))*255.0;
		g = abs(::atof(values[comp-2].c_str()))*255.0;
		b = abs(::atof(values[comp-1].c_str()))*255.0;

		
		//DebugLog "X:" + x + " Y:" + y + " Z:" + z + " R:" + r + " G:" + g + " B:" + b
		
	}
	
};

class VertCache{
	
	int size = 1;
	vector<int> realvertindex; // cache vert address when created
	vector<int> texusedindex; // cache vert to tex coord index
	vector<int> normusedindex; // cache vert to normal index used
	
public:
	void Reset(int i){
	
		//VertCache* c = new VertCache;
		realvertindex.assign(i,-1);
		texusedindex.assign(i,0);
		normusedindex.assign(i,0);
		size = i;
	}
	
	// CheckVert(vert index, texture index, norm index)
	int CheckVert(int vi, int ti, int ni){
	
		if (vi > size - 1) return -1;
		//if (realvertindex[vi]<0) return -1;
		
		// check for similar vertex, different vt and vn, if so, create new vertex
		if (texusedindex[vi] != ti && ti != 0) return -1;
		if (normusedindex[vi] != ni && ni != 0) return -1;
		
		// else return real vertex index
		return realvertindex[vi];
		
	}
	
	// Set real vert index
	void SetCache(int vi, int reali, int ti = 0, int ni = 0){
	
		if (vi >= size){
			realvertindex.resize(vi + 1,-1);
			texusedindex.resize(vi + 1,0);
			normusedindex.resize(vi + 1,0);
			size = vi + 1;
		}
		
		realvertindex[vi] = reali;
		texusedindex[vi] = ti;
		normusedindex[vi] = ni;
		
	}
	
};

class ObjMtl{
public:

	string name;
	Brush* brush;
	Texture* texture;
	Surface* meshSurface;
	VertCache cache;

	ObjMtl(){
		cache.Reset(1);
		meshSurface=0;
		brush=0;
		texture=0;
	}
	
};

vector<FaceData> ParseFaces( string data){
		
		vector<string> data1 = split(data,' ');
		
		int s = 0;
		vector<FaceData> fdata;
		fdata.resize(data1.size());
		
		for (unsigned int i=0; i< data1.size();i++){
			if (data1[i] == "") continue;
			
			vector<string> D2 = split(data1[i], '/');
			
			
			if (D2[0] != "") fdata[s].vi = ::atoi(D2[0].c_str()) - 1;
			if (D2[1] != "") fdata[s].ti = ::atoi(D2[1].c_str()) - 1;
			if (D2[2] != "") fdata[s].ni = ::atoi(D2[2].c_str()) - 1;
			
			if (fdata[s].vi < 0) fdata[s].vi = 0;
			if (fdata[s].ti < 0) fdata[s].ti = 0;
			if (fdata[s].ni < 0) fdata[s].ni = 0;
			
			s++;
		}
		
		fdata.resize(s);
		return fdata;
}		

vector<ObjMtl> ParseMTLLib(string url){
		
	vector<ObjMtl> MatLib;
	url=File::ResourceFilePath(url);

	File* file;
	file=File::ReadFile(url);
	if (file == 0) return MatLib;
		
	int CMI = -1;
	int is_brush = 0;
		
	while (!file->Eof()){
		string curline = file->ReadLine();
		string tag=curline.substr(0,9); transform(tag.begin(),tag.end(),tag.begin(),::tolower);

		// Create new brush
		if (tag.substr(0,7)=="newmtl "){
			ObjMtl tmp;
			CMI=MatLib.size();

			tmp.name = Trim(curline.substr(7));
			tmp.brush = Brush::CreateBrush();
			tmp.brush->BrushFX (0); // default, used to be 4 + 16

			MatLib.push_back(tmp);

			is_brush = 1;
				
		}			
		// Colours
		if (tag.substr(0,3)=="kd " && is_brush!=0){
			
			string data = Trim(curline.substr(3));
			float f[3];
			int comp=0;
			vector<string> values = split(data, ' ');
				
			for (unsigned int i=0;i<values.size();i++){
				if (values[i].length() > 0){
					values[comp] = values[i];
					comp++;
				}
			}
				
			f[0] = ::atof(values[0].c_str());
			f[1] = ::atof(values[1].c_str());
			f[2] = ::atof(values[2].c_str());
				
			MatLib[CMI].brush->BrushColor(f[0] * 255, f[1] * 255, f[2] * 255);
				
		}
			
		if (tag.substr(0,2)=="d " && is_brush!=0){
			MatLib[CMI].brush->BrushAlpha(::atof(curline.substr(2).c_str()));
		}			

		if (tag.substr(0,3)=="tr " && is_brush!=0){
			MatLib[CMI].brush->BrushAlpha(::atof(curline.substr(2).c_str()));
		}
			
		if (tag.substr(0,7)=="map_kd " && is_brush!=0){
				
			string texfile = Trim(curline.substr(7));
			
			MatLib[CMI].texture = Texture::LoadTexture(texfile, 1);
				
			MatLib[CMI].brush->BrushTexture(MatLib[CMI].texture);
				
		}
			
	}
		
	return MatLib;
		
}


Mesh* LoadOBJ(string f_name,Entity* parent_ent_ext){

	// Start file reading
	File* file;
	file=File::ReadResourceFile(f_name);

	list<Mesh*> mesh_list;

	vector<ObjMtl> matlibsArray;

	vector<ObjVertex> vertexP;
	vector<ObjNormal> vertexN;
	vector<ObjTexCoord> vertexT;

	string gname;
	//int snumber = -1;
		
	int hasNorms = 0;
	unsigned int VC = 0;
	unsigned int VN = 0;
	unsigned int VT = 0;
	unsigned int TRI = 0;
	unsigned int SC = 0;
		
	unsigned int v0, v1, v2;
	int ri;
	unsigned int id;
		
	Mesh* root = Mesh::CreateMesh(parent_ent_ext);
	mesh_list.push_back(root);

	Mesh* mesh=0;
	Surface* surface=0;
	int meshonce=0;
	ObjMtl localMtl;
	ObjMtl* currMtl=0;
	string curline;

	while (!file->Eof()){
		curline = file->ReadLine();
		if (curline.length() < 1) continue;
		if (curline[0] == '#') continue;

		string tag=curline.substr(0,9); transform(tag.begin(),tag.end(),tag.begin(),::tolower);
		if (tag.substr(0,2)=="o "){
			root->NameEntity(curline.substr(2)); // model name
			continue;
		} 
		if (tag.substr(0,2)=="g "){
			gname=curline.substr(2); // surface brush name
			continue;
		} 
		if (tag.substr(0,2)=="s "){
			string tt=curline.substr(2);transform(tt.begin(),tt.end(),tt.begin(),::tolower);
			//if (tt != "off") snumber = atoi(tt.c_str());
			// s = smoothing groups, not supported
			continue;
		} 
		if (tag.substr(0,2)=="v "){
			if (meshonce==0){
				meshonce=1;
				mesh = Mesh::CreateMesh(root);
				mesh_list.push_back(mesh);
			}
					
			//if (VC >= (vertexP.size() - 1)) vertexP.resize(vertexP.size()+1024);
					
			//vertexP[VC + 1] = New TObjVertex
			ObjVertex tmp;
			tmp.GetValues(curline.substr(2));
			vertexP.push_back(tmp);
			//vertexP[VC + 1]->GetValues(curline.substr(2));
			VC++;
			continue;
		}
		if (tag.substr(0,2)=="f "){
			if (surface==0 && mesh!=0){
				// no mtl, assume only one surface, no material lib
				surface = mesh->CreateSurface();
				SC++;
			}
			if (currMtl==0) currMtl=&localMtl;
			currMtl->meshSurface = surface;
			meshonce=0;

			if (surface!=0){
				// add verts
				// avoiding index 0 as this is reserved for null
				v0 = 0;
				v1 = 0;
				v2 = 0;
				ri = 0;
				
				vector<FaceData> FV = ParseFaces(curline.substr(2));
						
				// assume at least 3 verts for a triangle, start at 2 (base0)	
				// also do not use unused vertices
				// also each surface starts at vert id = 0
				for (id = 2; id<FV.size(); id++){
						
					v0 = FV[0].vi;
					v1 = FV[id - 1].vi;
					v2 = FV[id].vi;
					ri = currMtl->cache.CheckVert(v0, FV[0].ti, FV[0].ni);
					if (ri < 0){
						v0 = surface->AddVertex(vertexP[v0].x, vertexP[v0].y, -vertexP[v0].z);
						currMtl->cache.SetCache(FV[0].vi, v0, FV[0].ti, FV[0].ni);
					}else{
						v0 = ri;
					}
					surface->VertexColor(v0, vertexP[v0].r, vertexP[v0].g, vertexP[v0].b);
							
					ri = currMtl->cache.CheckVert(v1, FV[id - 1].ti, FV[id - 1].ni);
					if (ri < 0){
						v1 = surface->AddVertex(vertexP[v1].x, vertexP[v1].y, -vertexP[v1].z);
						currMtl->cache.SetCache(FV[id - 1].vi, v1, FV[id - 1].ti, FV[id - 1].ni);
					}else{
						v1 = ri;
					}
					surface->VertexColor(v1, vertexP[v1].r, vertexP[v1].g, vertexP[v1].b);
							
					ri = currMtl->cache.CheckVert(v2, FV[id].ti, FV[id].ni);
					if (ri < 0){
						v2 = surface->AddVertex(vertexP[v2].x, vertexP[v2].y, -vertexP[v2].z);
						currMtl->cache.SetCache(FV[id].vi, v2, FV[id].ti, FV[id].ni);
					}else{
						v2 = ri;
					}
					surface->VertexColor(v2, vertexP[v2].r, vertexP[v2].g, vertexP[v2].b);
														
					if (vertexN.size()>0 && FV[0].ni !=0){
						surface->VertexNormal (v0, vertexN[FV[0].ni].nx , vertexN[FV[0].ni].ny , vertexN[FV[0].ni].nz);
						surface->VertexNormal (v1, vertexN[FV[id - 1].ni].nx, vertexN[FV[id - 1].ni].ny, vertexN[FV[id - 1].ni].nz);
						surface->VertexNormal (v2, vertexN[FV[id].ni].nx, vertexN[FV[id].ni].ny, vertexN[FV[id].ni].nz);
					}
							
					if (vertexT.size()>0 && FV[0].ti !=0){
						surface->VertexTexCoords (v0, vertexT[FV[0].ti].u , 1-vertexT[FV[0].ti].v);
						surface->VertexTexCoords (v1, vertexT[FV[id - 1].ti].u, 1 - vertexT[FV[id - 1].ti].v);
						surface->VertexTexCoords (v2, vertexT[FV[id].ti].u, 1 - vertexT[FV[id].ti].v);
		 			}
							
					surface->AddTriangle(v0, v2, v1);
					TRI++;
				}
						
			}
					
			continue;
					
		}
		if (tag.substr(0,3)=="vn "){
			//if (VN > vertexN.size() Then vertexN = vertexN[..vertexN.length + MAXVERTS]
					
			ObjNormal tmp;
			tmp.GetValues(curline.substr(3));
			vertexN.push_back(tmp);
			VN++;
			hasNorms = 1;
			continue;
		}
		if (tag.substr(0,3)=="vt "){
			ObjTexCoord tmp;
			tmp.GetValues(curline.substr(3));
			vertexT.push_back(tmp);
			VT++;
			continue;
		}
		if (tag.substr(0,7)=="mtllib "){
			vector<ObjMtl> lib = ParseMTLLib(curline.substr(7));

			matlibsArray.insert(matlibsArray.end(), lib.begin(), lib.end());
			continue;
		}
		if (tag.substr(0,7)=="usemtl "){
			string texName = Trim(curline.substr(7));
			for (id = 0; id<matlibsArray.size();id++){
				if (matlibsArray[id].name == texName){
					currMtl = &matlibsArray[id];
					break;
				}
			}
			if (currMtl!=0){
						
				//reuse existing surfaces
				if (currMtl->meshSurface==0){
					currMtl->meshSurface = mesh->CreateSurface();
					currMtl->meshSurface->PaintSurface(currMtl->brush);
							
				}
						
				surface = currMtl->meshSurface;
				continue;
			}
		}

	}
	if (!hasNorms){
			
		list<Mesh*>::iterator it;

		for(it=mesh_list.begin();it!=mesh_list.end();it++){
			Mesh* mesh=*it;
			mesh->UpdateNormals();
		}
	}
		
	return root;


}

}