#include "global.h"
#include "entity.h"
#include "camera.h"
#include "brush.h"
#include "pick.h"
#include "lightprobes.h"







//I mesh che devono essere colorati saranno tutti child della griglia


void ProbeVolume::UpdateTerrain(){
	float rx=EntityScaleX(true);
	float ry=EntityScaleY(true);
	float rz=EntityScaleZ(true);
	if(rx<=ry && rx<=rz){
		GridSpacing=abs(rx);
	}else if(ry<=rx && ry<=rz){
		GridSpacing=abs(ry);
	}else{
		GridSpacing=abs(rz);
	}

	UpdateChildrenColor(this);
}



ProbeVolume* ProbeVolume::CreateProbeVolume(float w, float h, float d, Entity* parent_ent){

	ProbeVolume* probe=new ProbeVolume;
	probe->class_name="ProbeVolume";
		
	probe->AddParent(parent_ent);
	entity_list.push_back(probe);

	// update matrix
	probe->MQ_Update();

	probe->probes=new ProbeVolume::probe[(int)w*(int)h*(int)d];
	probe->width=w;
	probe->height=h;
	probe->depth=d;

/*probe->probes[0].face[0]={255,0,0};
probe->probes[0].face[1]={0,255,0};
probe->probes[0].face[2]={0,0,255};
probe->probes[0].face[3]={0,255,255};
probe->probes[0].face[4]={255,0,255};
probe->probes[0].face[5]={255,255,0};*/
	
	return probe;

}

ProbeVolume* ProbeVolume::CopyEntity(Entity* parent_ent){

	// new terr
	ProbeVolume* probe=new ProbeVolume;

	// copy contents of child list before adding parent
	list<Entity*>::iterator it;
	for(it=child_list.begin();it!=child_list.end();it++){
		Entity* ent=*it;
		ent->CopyEntity(probe);
	}

	// lists

	// add parent, add to list
	probe->AddParent(parent_ent);
	entity_list.push_back(probe);

/*	// add to collision entity list
	if(collision_type!=0){
		CollisionPair::ent_lists[collision_type].push_back(terr);
	}

	// add to pick entity list
	if(pick_mode){
		Pick::ent_list.push_back(terr);
	}*/

	// update matrix
	if(probe->parent){
		probe->mat.Overwrite(probe->parent->mat);
	}else{
		probe->mat.LoadIdentity();
	}

	// copy entity info

	probe->mat.Multiply(mat);

	probe->px=px;
	probe->py=py;
	probe->pz=pz;
	probe->sx=sx;
	probe->sy=sy;
	probe->sz=sz;

	probe->name=name;
	probe->class_name=class_name;
	probe->order=order;
	probe->hide=false;

	probe->probes=new ProbeVolume::probe[(int)width*(int)height*(int)depth];
	probe->width=width;
	probe->height=height;
	probe->depth=depth;

	for (int i=0;i<width*height*depth;i++){
		for (int i2=0;i2<6;i2++){
			probe->probes[i].face[i2].r=probes[i].face[i2].r;
			probe->probes[i].face[i2].g=probes[i].face[i2].g;
			probe->probes[i].face[i2].b=probes[i].face[i2].b;
		}		
	}


/*	terr->cull_radius=cull_radius;
	terr->radius_x=radius_x;
	terr->radius_y=radius_y;
	terr->box_x=box_x;
	terr->box_y=box_y;
	terr->box_z=box_z;
	terr->box_w=box_w;
	terr->box_h=box_h;
	terr->box_d=box_d;
	terr->collision_type=collision_type;
	terr->pick_mode=pick_mode;
	terr->obscurer=obscurer;*/





	return probe;

}


void ProbeVolume::FreeEntity(){

	Entity::FreeEntity();

	delete[] probes;
	
	delete this;
	
	return;

}


void ProbeVolume::ClearProbes(){
	for (int i=0;i<width*height*depth;i++){
		for (int i2=0;i2<6;i2++){
			probes[i].face[i2].r=0;
			probes[i].face[i2].g=0;
			probes[i].face[i2].b=0;
		}		
	}
}


void ProbeVolume::UpdateLightProbe (float x, float y, float z){
	int X,Y,Z;
	X=(int)x;
	Y=(int)y;
	Z=(int)z;

	int Offset=X + Y*width + Z*width*height;


	Camera cam;
	Global::camera_in_use=&cam;

	float DirMatrix[6][16]={
	{ 0, 0,-1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0,-1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{-1, 0, 0, 0, 0, 1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 1},
	{ 0, 0, 1, 0, 0, 1, 0, 0,-1, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0,-1, 0, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};


	cam.vx=0;
	cam.vy=0;
	cam.vwidth=16;
	cam.vheight=16;
	cam.UpdateProjMatrix();

	unsigned char buffer[16*16*4];

	for (int i=0; i<6; i++){
		cam.mat.grid[0][0]=DirMatrix[i][0];
		cam.mat.grid[0][1]=DirMatrix[i][1];
		cam.mat.grid[0][2]=DirMatrix[i][2];
		cam.mat.grid[0][3]=DirMatrix[i][3];
		cam.mat.grid[1][0]=DirMatrix[i][4];
		cam.mat.grid[1][1]=DirMatrix[i][5];
		cam.mat.grid[1][2]=DirMatrix[i][6];
		cam.mat.grid[1][3]=DirMatrix[i][7];
		cam.mat.grid[2][0]=DirMatrix[i][8];
		cam.mat.grid[2][1]=DirMatrix[i][9];
		cam.mat.grid[2][2]=DirMatrix[i][10];
		cam.mat.grid[2][3]=DirMatrix[i][11];
		cam.mat.grid[3][0]=X;
		cam.mat.grid[3][1]=Y;
		cam.mat.grid[3][2]=-Z;
		cam.mat.grid[3][3]=DirMatrix[i][15];
		cam.mat.Multiply2(mat);

		cam.Render();
		glReadPixels(0, 0, 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

		int r=0, g=0, b=0;
		for (int i2=0; i2<256; i2++){
			r += buffer[i2*4 + 0];
			g += buffer[i2*4 + 1];
			b += buffer[i2*4 + 2];
		}
		probes[Offset].face[i].r=r/256;
		probes[Offset].face[i].g=g/256;
		probes[Offset].face[i].b=b/256;

	}

/*	Matrix mat2;
	mat2.LoadIdentity();
	mat2.SetTranslate(X, Y, Z);

	cam.rotmat.LoadIdentity();
	cam.rotmat.Rotate(0, 0, 0);

	cam.mat.Multiply2(rotmat);
	cam.mat.Multiply2(mat2);
	cam.mat.Multiply2(mat);*/




}

void ProbeVolume::SetLightProbe (float x, float y, float z, int face, unsigned char r, unsigned char g, unsigned char b ){
	int X,Y,Z;
	X=(int)x;
	Y=(int)y;
	Z=(int)z;

	int Offset=X + Y*width + Z*width*height;
	probes[Offset].face[face].r=r;
	probes[Offset].face[face].g=g;
	probes[Offset].face[face].b=b;
	
}

void ProbeVolume::SetValidProbe (float x, float y, float z){
	if (isValid.empty()) isValid.resize(width * height * depth,0);
	int X,Y,Z;
	X=(int)x;
	Y=(int)y;
	Z=(int)z;

	isValid[X + Y*width + Z*width*height]=1;

}

void ProbeVolume::SetLight(float x, float y, float z, float range, float r, float g, float b, bool obscurer){
	float lx, ly, lz;
	if (obscurer) {
		lx=x; ly=y; lz=z;
		mat.TransformVec(lx, ly, lz,1);
	}

	int minX = max(0, (int)(x - range));
	int maxX = min(width- 1, (int)(x + range));
	int minY = max(0, (int)(y - range));
	int maxY = min(height- 1, (int)(y + range));
	int minZ = max(0, (int)(z - range));
	int maxZ = min(depth- 1, (int)(z + range));
	for (int Z = minZ; Z <= maxZ; Z++) {
		for (int Y= minY; Y <= maxY; Y++) {
			for (int X = minX; X <= maxX; X++) {
				int Offset=X + Y*width + Z*width*height;
				Vector dir(x-X,y-Y,z-Z);
				float dist = dir.length();
				if (dist < range && dist > 0.001f) {
					if (obscurer) {
						float px, py, pz;
						px=X; py=Y; pz=Z;
						mat.TransformVec(px, py, pz,1);
						Entity* pick=Pick::PickMain(lx, ly, lz, px, py, pz);
						if (pick!=NULL) continue;
					}


					dir /= dist;

					float atten = 1.0f - (dist / range);
					float red=r*atten;
					float green=g*atten;
					float blue=b*atten;
					if (dir.x<0){
						probes[Offset].face[0].r+=red;
						probes[Offset].face[0].g+=green;
						probes[Offset].face[0].b+=blue;
					}else{
						probes[Offset].face[3].r+=red;
						probes[Offset].face[3].g+=green;
						probes[Offset].face[3].b+=blue;
					}						
					if (dir.y<0){
						probes[Offset].face[1].r+=red;
						probes[Offset].face[1].g+=green;
						probes[Offset].face[1].b+=blue;
					}else{
						probes[Offset].face[4].r+=red;
						probes[Offset].face[4].g+=green;
						probes[Offset].face[4].b+=blue;
					}
					if (dir.z<0){
						probes[Offset].face[2].r+=red;
						probes[Offset].face[2].g+=green;
						probes[Offset].face[2].b+=blue;
					}else{
						probes[Offset].face[5].r+=red;
						probes[Offset].face[5].g+=green;
						probes[Offset].face[5].b+=blue;
					}						
						
				}
			}
		}
	}
}

void ProbeVolume::ApplyDiffusion(int numPassages) {
    int totalProbes = width * height * depth;
    
    // Se non ci sono sonde o il vettore dei flag non è pronto, esci
    if (totalProbes <= 0 || isValid.empty() || !probes) return;

    // Creiamo un buffer temporaneo per salvare i nuovi colori calcolati
    // in modo da non sovrascrivere l'array originale mentre lo stiamo ancora leggendo
    std::vector<probe> nextProbes(totalProbes);
    for (int i = 0; i < totalProbes; ++i) {
        nextProbes[i] = probes[i]; // Copia diretta della struct
    }
    // Numero di passaggi di diffusione. 2 o 3 di solito sono il compromesso perfetto.

    for (int passage = 0; passage < numPassages; ++passage) {
        // Creiamo una copia temporanea dello stato dei flag per questo passaggio
        std::vector<bool> nextValid = isValid;

        for (int z = 0; z < depth; ++z) {
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    
                    int currentOffset = x + y * width + z * width * height;

                    // Se la sonda è già valida (cotta da GPU o da un passaggio precedente), la saltiamo
                    if (isValid[currentOffset]) continue;

                    // Accumulatori per fare la media dei canali RGB di ogni faccia
                    int sumR[6] = {0}, sumG[6] = {0}, sumB[6] = {0};
                    int validNeighborsCount = 0;

                    // --- CONTROLLO DEI 6 VICINI CON BOUNDS CHECKING ---

                    // Vicino 0: Left (-X)
                    if (x > 0) {
                        int nOffset = (x - 1) + y * width + z * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }
                    // Vicino 3: Right (+X)
                    if (x < width - 1) {
                        int nOffset = (x + 1) + y * width + z * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }
                    // Vicino 1: Down (-Y)
                    if (y > 0) {
                        int nOffset = x + (y - 1) * width + z * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }
                    // Vicino 4: Up (+Y)
                    if (y < height - 1) {
                        int nOffset = x + (y + 1) * width + z * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }
                    // Vicino 2: Backward (-Z)
                    if (z > 0) {
                        int nOffset = x + y * width + (z - 1) * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }
                    // Vicino 5: Forward (+Z)
                    if (z < depth - 1) {
                        int nOffset = x + y * width + (z + 1) * width * height;
                        if (isValid[nOffset]) {
                            for(int f = 0; f < 6; ++f) {
                                sumR[f] += probes[nOffset].face[f].r;
                                sumG[f] += probes[nOffset].face[f].g;
                                sumB[f] += probes[nOffset].face[f].b;
                            }
                            validNeighborsCount++;
                        }
                    }

                    // --- APPLICAZIONE DELLA MEDIA ---
                    if (validNeighborsCount > 0) {
                        for (int f = 0; f < 6; ++f) {
                            nextProbes[currentOffset].face[f].r = (unsigned char)(sumR[f] / validNeighborsCount);
                            nextProbes[currentOffset].face[f].g = (unsigned char)(sumG[f] / validNeighborsCount);
                            nextProbes[currentOffset].face[f].b = (unsigned char)(sumB[f] / validNeighborsCount);
                        }
                        // Segnamo questa sonda come valida per il prossimo passaggio di diffusione
                        nextValid[currentOffset] = true;
                    }
                }
            }
        }

        // Applichiamo i cambiamenti alla griglia principale e ai flag di validità
        // prima del prossimo eventuale passaggio
        for (int i = 0; i < totalProbes; ++i) {
            probes[i] = nextProbes[i];
        }
        isValid = nextValid;
    }
    isValid.clear();
    isValid.shrink_to_fit();
}



void ProbeVolume::GetCol (float x, float y, float z, col l[]){

	//mat.TransformVec(x, y, z, 1);
	if (x<0 || x>=width) return ;
	if (y<0 || y>=height) return ;
	if (z<0 || z>=depth) return ;

	int X,Y,Z;
	X=(int)x;
	Y=(int)y;
	Z=(int)z;

	int w=width;
	int h=height;
	//int d=depth;
	int Offset=X + Y*w + Z*w*h;


	probe *a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8;
	a1=&probes[Offset];
	a2=&probes[Offset + 1];
	a3=&probes[Offset + w];
	a4=&probes[Offset + 1 + w];
	a5=&probes[Offset + w*h];
	a6=&probes[Offset + 1 + w*h];
	a7=&probes[Offset + w + w*h];
	a8=&probes[Offset + 1 +w + w*h];

	float x0,x1,y0,y1,z0,z1;
	x1=x-X; x0=1.0-x1;
	y1=y-Y; y0=1.0-y1;
	z1=z-Z; z0=1.0-z1;


	//col l[6);
	for(int i=0;i<6;i++){
		col i1,i2,i3,i4,i5,i6;
		i1.r=a1->face[i].r*x0+a2->face[i].r*x1;
		i1.g=a1->face[i].g*x0+a2->face[i].g*x1;
		i1.b=a1->face[i].b*x0+a2->face[i].b*x1;

		i2.r=a3->face[i].r*x0+a4->face[i].r*x1;
		i2.g=a3->face[i].g*x0+a4->face[i].g*x1;
		i2.b=a3->face[i].b*x0+a4->face[i].b*x1;

		i3.r=a5->face[i].r*x0+a6->face[i].r*x1;
		i3.g=a5->face[i].g*x0+a6->face[i].g*x1;
		i3.b=a5->face[i].b*x0+a6->face[i].b*x1;

		i4.r=a7->face[i].r*x0+a8->face[i].r*x1;
		i4.g=a7->face[i].g*x0+a8->face[i].g*x1;
		i4.b=a7->face[i].b*x0+a8->face[i].b*x1;

		i5.r=i1.r*y0+i2.r*y1;
		i5.g=i1.g*y0+i2.g*y1;
		i5.b=i1.b*y0+i2.b*y1;

		i6.r=i3.r*y0+i4.r*y1;
		i6.g=i3.g*y0+i4.g*y1;
		i6.b=i3.b*y0+i4.b*y1;

		l[i].r=i5.r*z0+i6.r*z1;
		l[i].g=i5.g*z0+i6.g*z1;
		l[i].b=i5.b*z0+i6.b*z1;
	}
	/*float i1,i2,i3,i4,i5,i6;

	i1=a1+(a2-a1)*(x-X);
	i2=a3+(a4-a3)*(x-X);
	i3=a5+(a6-a5)*(x-X);
	i4=a7+(a8-a7)*(x-X);
	i5=i1+(i2-i1)*(y-Y);
	i6=i3+(i4-i3)*(y-Y);

	return i5+(i6-i5)*(z-Z);*/

}


void ProbeVolume::UpdateChildrenColor(Entity* ent_p){

	list<Entity*>::iterator it;
	for(it=ent_p->child_list.begin();it!=ent_p->child_list.end();it++){
		Entity* p=*it;
		//p->mat.Overwrite(ent_p->mat);
		if(dynamic_cast<Mesh*>(p)){
			float radius=abs(p->cull_radius); // use absolute value as cull_radius will be negative value if set by MeshCullRadius (manual cull)
			// radius - apply entity scale
			float rx=radius*p->EntityScaleX(true);
			float ry=radius*p->EntityScaleY(true);
			float rz=radius*p->EntityScaleZ(true);
			if(rx>=ry && rx>=rz){
				radius=abs(rx);
			}else if(ry>=rx && ry>=rz){
				radius=abs(ry);
			}else{
				radius=abs(rz);
			}

			UpdateMeshColor (dynamic_cast<Mesh*>(p),(radius>GridSpacing)?1:0);
		}
		UpdateChildrenColor(p);
	}
}


void ProbeVolume::UpdateMeshColor (Mesh* mesh, bool mode){
	col color[6];
	/*color[0]={255,0,0};
	color[1]={0,255,0};
	color[2]={0,0,255};
	color[3]={0,255,255};
	color[4]={255,0,255};
	color[5]={255,255,0};*/
	Matrix mat0;
	MQ_GetInvMatrix(mat0);
	float x, y, z;
	x= mesh->mat.grid[3][0];
	y= mesh->mat.grid[3][1];
	z= -mesh->mat.grid[3][2];
	mat0.TransformVec(x, y, z, 1);
	GetCol (x,y,z,color);

	mat0.Multiply(mesh->mat);


	Matrix mat1;
	mat1.Overwrite(mat);
	mat1.grid[3][0] = 0; //remove translation
	mat1.grid[3][1] = 0;
	mat1.grid[3][2] = 0;

	Matrix mat2;
	mesh->MQ_GetInvMatrix(mat2);
	mat2.grid[3][0] = 0; //remove translation
	mat2.grid[3][1] = 0;
	mat2.grid[3][2] = 0;

	mat2.Multiply(mat1);


	Vector lv[3];
	float vx, vy, vz;
	vx=-1.0; vy=0.0; vz=0.0;
	mat2.TransformVec(vx, vy, vz, 1);
	lv[0]=Vector(vx, vy, -vz);
	vx=0.0; vy=-1.0; vz=0.0;
	mat2.TransformVec(vx, vy, vz, 1);
	lv[1]=Vector(vx, vy, -vz);
	vx=0.0; vy=0.0; vz=-1.0;
	mat2.TransformVec(vx, vy, vz, 1);
	lv[2]=Vector(vx, vy, -vz);

	list<Surface*>::iterator surf_it;
	surf_it=mesh->surf_list.begin();

		// cycle through all surfs
		for(surf_it=mesh->surf_list.begin();surf_it!=mesh->surf_list.end();surf_it++){
		Surface& surf=**surf_it;
			int v;
			for(v=0;v<surf.no_verts;v++){

				if (mode){
					x=surf.vert_coords[v*3];
					y=surf.vert_coords[v*3+1];
					z=-surf.vert_coords[v*3+2];
					//mesh->mat.TransformVec(x, y, z, 1);
					mat0.TransformVec(x, y, z, 1);
//if (v==0) cout<<x<<" "<<y<<" "<<z<<" "<<endl;
//for (int zz=0;zz<6;zz++) {color[zz].r=0; color[zz].g=0;color[zz].b=0;}
					GetCol (x,y,z,color);
				}
				float r=0,g=0,b=0;

				Vector vert_norm(surf.vert_norm[v*3], surf.vert_norm[v*3+1], surf.vert_norm[v*3+2]);
				for (int i=0;i<3;i++){
					int i2=i;
					float dp=vert_norm.normalized().dot( lv[i] );
					if( dp<=0 ) {
						dp=-dp;
						i2+=3;
					}
					r+=color[i2].r/255.0*dp;
					g+=color[i2].g/255.0*dp;
					b+=color[i2].b/255.0*dp;
				}

				surf.vert_col[v*4]=r;
				surf.vert_col[v*4+1]=g;
				surf.vert_col[v*4+2]=b;

			}
			surf.reset_vbo|=128;
		}

}




