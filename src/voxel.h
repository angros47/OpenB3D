#ifndef VOXEL_H
#define VOXEL_H

#include "mesh.h"

#include <iostream>
using namespace std;

class VoxelSprite : public Mesh{

public:

	Material* material[8];
	int no_mats;

#ifndef GLES2
	int LOD[16*3];
#endif

	static VoxelSprite* CreateVoxelSprite(int slices=64, Entity* parent_ent=NULL);
	VoxelSprite* CopyEntity(Entity* parent_ent=NULL);
	void FreeEntity(void);
	void VoxelSpriteMaterial(Material* mat);
	void Render();

};

#endif
