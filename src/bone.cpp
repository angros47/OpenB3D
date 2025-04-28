/*
 *  bone.mm
 *  iminib3d
 *
 *  Created by Simon Harrison.
 *  Copyright Si Design. All rights reserved.
 *
 */

#include "bone.h"

#include "global.h"

Bone* Bone::CopyEntity(Entity* parent_ent){

	// new bone
	Bone* bone=new Bone;
	
	// copy contents of child list before adding parent
	list<Entity*>::iterator it;
	for(it=child_list.begin();it!=child_list.end();it++){
		Entity* ent=*it;
		ent->CopyEntity(bone);
	}
	
	// add parent, add to list
	bone->AddParent(parent_ent);
	entity_list.push_back(bone);
	
	// update matrix
	if(bone->parent){
		bone->mat.Overwrite(bone->parent->mat);
	}else{
		bone->mat.LoadIdentity();
	}
	
	// copy entity info
	
	bone->mat.Multiply(mat);

	bone->px=px;
	bone->py=py;
	bone->pz=pz;
	bone->sx=sx;
	bone->sy=sy;
	bone->sz=sz;
	bone->qw=qw;
	bone->qx=qx;
	bone->qy=qy;
	bone->qz=qz;
	
	bone->name=name;
	bone->class_name=class_name;
	bone->order=order;
	bone->hide=false;
	
	// copy bone info
	
	bone->keys=keys->Copy();
	
	bone->mat2=mat2;
	bone->inv_mat=inv_mat;
	bone->tform_mat=tform_mat;

	return bone;

}

void Bone::FreeEntity(){

	if (keys){
		delete keys;
	}

	Entity::FreeEntity();
	
	delete this;
	
	return;

}

/*void Bone::bone_update(){
	mat2.Overwrite(bent.rotmat);
	mat2.grid[3][0]=n_px;
	mat2.grid[3][1]=n_py;
	mat2.grid[3][2]=n_pz;

	if(dynamic_cast<Bone*>(parent)!=NULL){
		Matrix new_mat;
		new_mat.Overwrite(dynamic_cast<Bone*>(parent)->mat2);
		new_mat.Multiply(mat2);
		mat2.Overwrite(new_mat);
	}
	for(int i=1;i<=this->CountChildren();i++){
		Entity* ent=this->GetChild(i);
		if(dynamic_cast<Bone*>(ent)){
			dynamic_cast<Bone*>(ent)->bone_update();
		}
	}
}*/

void Bone::RotateBone(float pitch,float yaw,float roll){
	rotmat.LoadIdentity();
	rotmat.Rotate(pitch, yaw, roll);
	mat2.Overwrite(rotmat);
	mat2.grid[3][0]=px;
	mat2.grid[3][1]=py;
	mat2.grid[3][2]=-pz;
	if(dynamic_cast<Bone*>(parent)!=NULL){
		mat2.Multiply2(dynamic_cast<Bone*>(parent)->mat2);
	}
	mat2.GetInverse(inv_mat);
}

void Bone::PositionBone(float x,float y,float z){
	px = x;
	py = y;
	pz = z;
	mat2.Overwrite(rotmat);
	mat2.grid[3][0]=px;
	mat2.grid[3][1]=py;
	mat2.grid[3][2]=-pz;
	if(dynamic_cast<Bone*>(parent)!=NULL){
		mat2.Multiply2(dynamic_cast<Bone*>(parent)->mat2);
	}
	mat2.GetInverse(inv_mat);

}

int Bone::MoveBone(float x,float y,float z, int segments){

	const int MAX_ITERACTIONS=2;
	for (int i2=0;i2<MAX_ITERACTIONS;i2++){
	
		float dx=mat2.grid[3][0]-x;
		float dy=mat2.grid[3][1]-y;
		float dz=mat2.grid[3][2]+z;

		if (dx*dx+dy*dy+dz*dz < 0.001) return 1;

		Bone* seg=this;

		for (int i=0;i<segments;i++){


			if(dynamic_cast<Bone*>(seg->parent)!=NULL){
				seg=dynamic_cast<Bone*>(seg->parent);

				Bone *s, *s2;
				s=this;


				Matrix m0,m1;
				if(dynamic_cast<Bone*>(seg->parent)!=NULL){
					s2=dynamic_cast<Bone*>(seg->parent);
					s2->mat2.GetInverse(m0);
					m0.ToRotMat();
					/*m0.grid[3][0] = 0; //remove translation
					m0.grid[3][1] = 0;
					m0.grid[3][2] = 0;*/
					m1.Overwrite(s2->mat2);
					m1.ToRotMat();
					/*m1.grid[3][0] = 0; //remove translation
					m1.grid[3][1] = 0;
					m1.grid[3][2] = 0;*/
				}else{
					s2=seg;
					m0.LoadIdentity();
					m1.LoadIdentity();
				}

				//convert to absolute rotation...
				seg->rotmat.Multiply2(m1);


				//make sure the end of the joint points points to 0,0
				float end_x=seg->mat2.grid[3][0]-mat2.grid[3][0];
				float end_y=seg->mat2.grid[3][1]-mat2.grid[3][1];
				float end_z=seg->mat2.grid[3][2]-mat2.grid[3][2];

				float end_pitch=atan2deg(-end_y, sqrt(end_z*end_z+end_x*end_x));
				float end_yaw=atan2deg(end_x, end_z);

				seg->MQ_Turn(-end_yaw, 0, 1, 0, 1);
				//seg->MQ_Turn(-end_pitch, 1, 0, 0, 1);

				//the previous instruction can be joined with the next MQ_Turn


				//now point to the target
				float target_x=seg->mat2.grid[3][0]-x;
				float target_y=seg->mat2.grid[3][1]-y;
				float target_z=seg->mat2.grid[3][2]+z;

				float target_pitch=atan2deg(-target_y, sqrt(target_z*target_z+target_x*target_x));
				float target_yaw=atan2deg(target_x, target_z);



				seg->MQ_Turn(target_pitch-end_pitch, 1, 0, 0, 1);
				seg->MQ_Turn(target_yaw, 0, 1, 0, 1);
				//...and back to native rotation
				seg->rotmat.Multiply2(m0);

				//update children
				while (s!=s2){
					if (dynamic_cast<Bone*>(s->parent)==s2){
						s->mat2.Overwrite(s->rotmat);
						s->mat2.grid[3][0]=s->px;
						s->mat2.grid[3][1]=s->py;
						s->mat2.grid[3][2]=-s->pz;
						s->mat2.Multiply2(s2->mat2);

						s2=s; s=this;
					} else {
						s=dynamic_cast<Bone*>(s->parent);
					}
				}
			}
		}
	}
	return 0;
}
