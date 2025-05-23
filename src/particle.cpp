#include <stdlib.h> 

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


#include "camera.h"
#include "particle.h"
#include "surface.h"
#include "pick.h"

list<ParticleBatch*> ParticleBatch::particle_batch_list;
list<ParticleEmitter*> ParticleEmitter::emitter_list;


void ParticleBatch::Render(){
	int depth_mask_disabled=false;

	Surface* surf=*surf_list.begin();

#ifndef GLES2
	glDisable(GL_ALPHA_TEST); // ?

	if(Global::fx1!=true){
		Global::fx1=true;
		glDisableClientState(GL_NORMAL_ARRAY);
	}

	if(Global::fx2!=true){
		Global::fx2=true;
		glEnableClientState(GL_COLOR_ARRAY);
		glEnable(GL_COLOR_MATERIAL);
	}

	if(surf->alpha_enable==true){
		if(Global::alpha_enable!=true){
			Global::alpha_enable=true;
			glEnable(GL_BLEND);
		}
		glDepthMask(GL_FALSE); // must be set to false every time, as it's always equal to true before it's called
		depth_mask_disabled=true; // set this to true to we know when to enable depth mask at bottom of function
	}else{
		if(Global::alpha_enable!=false){
			Global::alpha_enable=false;
			glDisable(GL_BLEND);
			//glDepthMask(GL_TRUE); already set to true
		}
	}
#else
	Global::shader=&Global::shader_particle;
	glUseProgram(Global::shader->ambient_program);
	glUniformMatrix4fv(Global::shader->view, 1 , 0, &Global::camera_in_use->mod_mat[0] );
	glUniformMatrix4fv(Global::shader->proj, 1 , 0, &Global::camera_in_use->proj_mat[0] );

#endif

	if(brush.blend!=Global::blend_mode){
		Global::blend_mode=brush.blend;

		switch(brush.blend){
			case 0:
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // alpha
				break;
			case 1:
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // alpha
				break;
			case 2:
				glBlendFunc(GL_DST_COLOR,GL_ZERO); // multiply
				break;
			case 3:
				glBlendFunc(GL_SRC_ALPHA,GL_ONE); // additive and alpha
				break;
		}

	}


	if(surf->ShaderMat!=NULL){
#ifndef GLES2
		if (surf->ShaderMat->legacy!=0) surf->ShaderMat->surf=surf;
		if (surf->ShaderMat->cols_loc){
			glEnableVertexAttribArray(surf->ShaderMat->cols_loc);
			glVertexAttribPointer(surf->ShaderMat->cols_loc, 4, GL_FLOAT, GL_FALSE, 0, &surf->vert_col[0]);
		}

#else
		glBindBuffer(GL_ARRAY_BUFFER, surf->vbo_id[0]);
		glBufferData(GL_ARRAY_BUFFER,(surf->no_verts*3*sizeof(float)),&surf->vert_coords[0],GL_STREAM_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		if (surf->ShaderMat->cols_loc){
			glEnableVertexAttribArray(surf->ShaderMat->cols_loc);
			glBindBuffer(GL_ARRAY_BUFFER,surf->vbo_id[4]);
			glBufferData(GL_ARRAY_BUFFER,(surf->no_verts*4*sizeof(float)),&surf->vert_col[0],GL_STREAM_DRAW);
			glVertexAttribPointer(surf->ShaderMat->cols_loc, 4, GL_FLOAT, GL_FALSE, 0, 0);
		}
#endif
		surf->ShaderMat->TurnOn(mat, &brush);
	}else{
#ifndef GLES2
		glEnable( GL_POINT_SPRITE ); 

		float quadratic[] = {0,0,1};
		glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );

		glEnable( GL_POINT_SMOOTH );
		glPointSize(brush.tex[0]->width * Global::camera_in_use->vheight*.5);
		glActiveTexture(GL_TEXTURE0);
		glEnable( GL_TEXTURE_2D );

		if(brush.tex[0]->flags&4){
			glEnable(GL_ALPHA_TEST);
		}

		switch(brush.tex[0]->blend){
			case 0: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
			break;
			case 1: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
			break;
			case 2: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
			//case 2 glTexEnvf(GL_TEXTURE_ENV,GL_COMBINE_RGB_EXT,GL_MODULATE);
			break;
			case 3: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_ADD);
			break;
			case 4:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
				glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB_EXT, GL_DOT3_RGB_EXT);
				break;
			case 5:
				glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
				glTexEnvi(GL_TEXTURE_ENV,GL_COMBINE_RGB,GL_MODULATE);
				glTexEnvi(GL_TEXTURE_ENV,GL_RGB_SCALE,2.0);
				break;
			default: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
		}


		glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, brush.tex[0]->texture);


	}

	glBindBuffer(GL_ARRAY_BUFFER,0); // reset - necessary for when non-vbo surf follows vbo surf
	glColorPointer(4,GL_FLOAT,0,&surf->vert_col[0]);

	glVertexPointer(3,GL_FLOAT,0,&surf->vert_coords[0]);
#else
		//glEnable( GL_PROGRAM_POINT_SIZE );
		glActiveTexture(GL_TEXTURE0);
		//glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, brush.tex[0]->texture);

		//surf->reset_vbo=9;
		//surf->UpdateVBO();
		glBindBuffer(GL_ARRAY_BUFFER,surf->vbo_id[0]);
		glBufferData(GL_ARRAY_BUFFER,(surf->no_verts*3*sizeof(float)),&surf->vert_coords[0],GL_STREAM_DRAW);
		glVertexAttribPointer(Global::shader->vposition, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(Global::shader->vposition);

		glBindBuffer(GL_ARRAY_BUFFER,surf->vbo_id[4]);
		glBufferData(GL_ARRAY_BUFFER,(surf->no_verts*4*sizeof(float)),&surf->vert_col[0],GL_STREAM_DRAW);
		/*glVertexAttribPointer(Global::shader->color, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(Global::shader->color);*/
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);
		glUniform1i(Global::shader->texflag, brush.tex[0]->flags&4);
	}

#endif
	glDrawArrays(GL_POINTS,0,surf->no_verts);

#ifndef GLES2
	glDisable( GL_POINT_SPRITE ); 
	glDisable( GL_POINT_SMOOTH );
#endif

	// enable depth mask again if it was disabled when blend was enabled
	if(depth_mask_disabled==true){
		glDepthMask(GL_TRUE);
		depth_mask_disabled=false; // set to false again for when we repeat loop
	}



	//Trails

	if (trail>1){
		float r=(brush.red-2)/trail;
		float g=(brush.green-2)/trail;
		float b=(brush.blue-2)/trail;
		float a=(brush.alpha-2)/trail;
		for(int i=0;i<=surf->no_verts-1;i++){
			surf->vert_col[i*4]+=r;
			surf->vert_col[i*4+1]+=g;
			surf->vert_col[i*4+2]+=b;
			surf->vert_col[i*4+3]+=a;
			surf->vert_coords[i*3]+=px;
			surf->vert_coords[i*3+1]+=py;
			surf->vert_coords[i*3+2]+=pz;

		}
	}


	int del_trail_points=surf->no_verts/trail;

	if (del_trail_points!=0){
		surf->vert_tex_coords0.clear();
		surf->vert_tex_coords1.clear();
		if (surf->no_verts<=del_trail_points){
			surf->vert_coords.clear();
			surf->vert_col.clear();
			surf->no_verts=0;
		}else{
			surf->vert_coords.erase(surf->vert_coords.begin(),surf->vert_coords.begin()+del_trail_points*3);
			surf->vert_col.erase(surf->vert_col.begin(),surf->vert_col.begin()+del_trail_points*4);
			surf->no_verts-=del_trail_points;
		}
	}
#ifndef GLES2
	if(surf->ShaderMat!=NULL){
		surf->ShaderMat->TurnOff();
	}
#else
	glDisableVertexAttribArray(Global::shader->vposition);
#endif

}


void ParticleEmitter::Update(){
	list<ParticleData>::iterator it;

	rate_counter++;
	if (hide==false && rate_counter>rate){
		rate_counter=0;
		ParticleData particle;
		particle.ent=particle_base->CopyEntity(0);
		particle.ent->hide=false;
		particle.particleLife=lifetime;
		particle.vx=0;
		particle.vy=0;
		particle.vz=particleSpeed;

		particle.ent->px=mat.grid[3][0];
		particle.ent->py=mat.grid[3][1];
		particle.ent->pz=-mat.grid[3][2];

		if (variance>.000000001){
			particle.vx+=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/variance))-variance/2;
			particle.vy+=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/variance))-variance/2;
			particle.vz+=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/variance))-variance/2;
		}
		mat.TransformVec(particle.vx,particle.vy,particle.vz);
		particles.push_back(particle);
	}

	for(it=particles.begin();it!=particles.end();it++){
		ParticleData &particle=*it;

		if (particle.particleLife<=0){
			particle.ent->FreeEntity();

			it=particles.erase(it);
			continue;
		}

		if (UpdateParticle!=0){
			UpdateParticle (particle.ent, particle.particleLife);
		}

		particle.vx+=gx;
		particle.vy+=gy;
		particle.vz+=gz;

		particle.ent->px+=particle.vx;
		particle.ent->py+=particle.vy;
		particle.ent->pz+=particle.vz;
		particle.ent->mat.SetTranslate(particle.ent->px, particle.ent->py, -particle.ent->pz);

		particle.particleLife--;

	}
}

ParticleEmitter* ParticleEmitter::CreateParticleEmitter(Entity* particle, Entity* parent_ent){

	ParticleEmitter* emitter=new ParticleEmitter;

	emitter->particle_base=particle;

	emitter->class_name="Emitter";
		
	emitter->AddParent(parent_ent);
	entity_list.push_back(emitter);

	// update matrix
	emitter->MQ_Update();

	emitter_list.push_back(emitter);

	return emitter;
}

ParticleEmitter* ParticleEmitter::CopyEntity(Entity* parent_ent){

	ParticleEmitter* emitter=new ParticleEmitter;

	list<Entity*>::iterator it;
	for(it=child_list.begin();it!=child_list.end();it++){
		Entity* ent=*it;
		ent->CopyEntity(emitter);
	}

	emitter->class_name="Emitter";
		
	emitter->AddParent(parent_ent);
	entity_list.push_back(emitter);

	// add to collision entity list
	if(collision_type!=0){
		CollisionPair::ent_lists[collision_type].push_back(emitter);
	}
	
	// add to pick entity list
	if(pick_mode){
		Pick::ent_list.push_back(emitter);
	}
	
	// update matrix
	if(emitter->parent){
		emitter->mat.Overwrite(emitter->parent->mat);
	}else{
		emitter->mat.LoadIdentity();
	}
	
	// copy entity info


	emitter->px=px;
	emitter->py=py;
	emitter->pz=pz;
	emitter->sx=sx;
	emitter->sy=sy;
	emitter->sz=sz;

	emitter->name=name;
	emitter->class_name=class_name;
	emitter->order=order;
	emitter->hide=false;


	emitter->radius_x=radius_x;
	emitter->radius_y=radius_y;
	emitter->box_x=box_x;
	emitter->box_y=box_y;
	emitter->box_z=box_z;
	emitter->box_w=box_w;
	emitter->box_h=box_h;
	emitter->box_d=box_d;
	emitter->collision_type=collision_type;
	emitter->pick_mode=pick_mode;
	emitter->obscurer=obscurer;


	emitter_list.push_back(emitter);

	emitter->particle_base=particle_base;


	emitter->rate=rate;
	emitter->lifetime=lifetime;

	emitter->gx=gx;
	emitter->gy=gy;
	emitter->gz=gz;
	emitter->variance=variance;
	emitter->particleSpeed=particleSpeed;

	emitter->UpdateParticle=UpdateParticle;

	return emitter;


}

void ParticleEmitter::FreeEntity (){
	emitter_list.remove(this);

	list<ParticleData>::iterator it;

	for(it=particles.begin();it!=particles.end();it++){
		ParticleData &particle=*it;

		particle.ent->FreeEntity();

	}
	particles.clear();


	Entity::FreeEntity();
	delete this;

	return;
}

void ParticleEmitter::EmitterVector(float x, float y, float z){
	gx=x;
	gy=y;
	gz=z;
}

void ParticleEmitter::EmitterRate (float r){
	rate=1.0/r;
}

void ParticleEmitter::EmitterVariance (float v){
	variance=v;
}

void ParticleEmitter::EmitterParticleLife (int l){
	lifetime=l;
}

void ParticleEmitter::EmitterParticleSpeed (float s){
	particleSpeed=s;
}

void ParticleEmitter::EmitterParticleFunction(void (*EmitterFunction)(Entity*, int)){
	UpdateParticle=EmitterFunction;
}
