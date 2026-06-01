#ifndef LIGHTPROBES_H
#define LIGHTPROBES_H


#include "terrain.h"
#include "mesh.h"



class ProbeVolume : public Terrain{
	struct col{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
	struct probe{
		/*
		0: Negative x (left)
		1: negative y (down)
		2: Negative z (backward)
		3: Positive x (right)
		4: positive y (up)
		5: positive z (forward)
		*/
		col face[6];
	} *probes;

	vector<bool> isValid;
	float GridSpacing;

	int width, height, depth;
	void GetCol (float x, float y, float z, col l[]);
	void UpdateChildrenColor(Entity* ent_p);
public:
	void UpdateMeshColor (Mesh* mesh, bool mode);

	static ProbeVolume* CreateProbeVolume(float w=1, float h=1, float d=1, Entity* parent_ent=0);
	ProbeVolume* CopyEntity(Entity* parent_ent=NULL);

	void ClearProbes();

	void UpdateLightProbe (float x, float y, float z);
	void SetValidProbe (float x, float y, float z);
	void SetLightProbe (float x, float y, float z, int face, unsigned char r, unsigned char g, unsigned char b );
	void SetLight(float x, float y, float z, float range, float r, float g, float b, bool obscurer=0);

	void ApplyDiffusion(int numPassages);

	void FreeEntity(void);
	void TreeCheck(CollisionInfo* ci){};

	void UpdateTerrain();

};

#endif
