#ifndef BONE_H
#define BONE_H
/*
 *  bone.h
 *  iminib3d
 *
 *  Created by Simon Harrison.
 *  Copyright Si Design. All rights reserved.
 *
 */

#include "entity.h"
#include "animation_keys.h"

#include <iostream>
using namespace std;

class Bone : public Entity{

	void bone_update();
public:

	float qw,qx,qy,qz;

	AnimationKeys* keys;

	// additional matrices used for animation purposes
	Matrix mat2;
	Matrix inv_mat; // set in TModel, when loading anim mesh
	Matrix tform_mat;

	//float kx,ky,kz,kqw,kqx,kqy,kqz; // used to store current keyframe in AnimateMesh, for use with transition

	Bone(){

		qw=1.0,qx=0.0,qy=0.0,qz=0.0;

		keys=NULL;

	}

	Bone* CopyEntity(Entity* parent_ent=NULL);
	void FreeEntity(void);

	void RotateBone(float pitch,float yaw,float roll);
	void PositionBone(float x,float y,float z);
	int MoveBone(float x,float y,float z, int segments);

};

#endif
