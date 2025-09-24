#define CGLTF_IMPLEMENTATION
#include "cgltf.h"

#include "model.h"

#include "entity.h"
#include "bone.h"
#include "mesh.h"
#include "texture.h"
#include "animation_keys.h"
//#include "quaternion.h"
//#include "file.h"
#include "stb_image.h"


namespace loadGLtf{
const float frame_rate=24.0;

static cgltf_data* data = NULL;

static Mesh* root;

static vector<Mesh*> mesh_list;

static Texture* LoadTexture(cgltf_texture* texture){
	cgltf_image* image = texture->image;
	if (image==0) return 0;
	unsigned char* img_data;

	Texture* tex=Texture::CreateTexture(1,1,1,1);
	if (image->uri) {

		if (strncmp(image->uri, "data:image/", 11) == 0) {

			// Extract the Base64 data (after the comma in the URI)
			const char* base64_data = strchr(image->uri, ',');
			if (!base64_data) return 0;
			base64_data++; // Skip the comma

			// Decode the Base64 data using cgltf_load_buffer_base64
			void* decoded_data = NULL;
			cgltf_size decoded_size = 0;
			cgltf_options options = {};
			cgltf_result result = cgltf_load_buffer_base64(&options, strlen(base64_data), base64_data, &decoded_data);
			if (result != cgltf_result_success || !decoded_data) {
				return tex;
			}

			// Decode the image using stb_image
			int width, height, channels;
			img_data = stbi_load_from_memory((const uint8_t*)decoded_data, decoded_size, &width, &height, &channels, 4);
			if (img_data) {
				tex->width=width;
				tex->height=height;
				tex->BufferToTex(img_data,0);
				stbi_image_free(img_data);
				return tex;
			} else {
				fprintf(stderr, "  Failed to decode image with stb_image\n");
			}

			// Free the decoded Base64 data
			free(decoded_data);
		} else {
			// Load the image from an external file using stb_image
			int width, height, channels;
			img_data = stbi_load(image->uri, &width, &height, &channels, 4);
			if (img_data) {
				tex->width=width;
				tex->height=height;
				tex->BufferToTex(img_data,0);
				stbi_image_free(img_data);
				return tex;
			} else {
				fprintf(stderr, "  Failed to load image: %s\n", image->uri);
			}
		}
	} else if (image->buffer_view) {
		// Embedded binary image data
		const uint8_t* image_data = cgltf_buffer_view_data(image->buffer_view);

		// Decode the embedded image data with stb_image
		int width, height, channels;
                img_data = stbi_load_from_memory(image_data, image->buffer_view->size, &width, &height, &channels, 4);
                if (img_data) {
			tex->width=width;
			tex->height=height;
			tex->BufferToTex(img_data,0);
			stbi_image_free(img_data);
			return tex;
		}
	} 
	return tex;

}

static void LoadMeshNode(cgltf_mesh* mesh, Entity* parent){
	Mesh* model = Mesh::CreateMesh((root==NULL)?parent:root);

	for (cgltf_size j = 0; j < mesh->primitives_count; ++j) {
		cgltf_primitive* primitive = &mesh->primitives[j];

		Surface* surf=model->CreateSurface();
		Surface* anim_surf=NULL;

		int tex_coords=0;

		if (primitive->material!=0 && primitive->material->has_pbr_metallic_roughness!=0){
			surf->brush->red=pow(primitive->material->pbr_metallic_roughness.base_color_factor[0],1/2.2);
			surf->brush->green=pow(primitive->material->pbr_metallic_roughness.base_color_factor[1],1/2.2);
			surf->brush->blue=pow(primitive->material->pbr_metallic_roughness.base_color_factor[2],1/2.2);
			surf->brush->alpha=pow(primitive->material->pbr_metallic_roughness.base_color_factor[3],1/2.2);
			if (primitive->material->pbr_metallic_roughness.base_color_texture.texture!=0) {
				Texture* tex=LoadTexture(primitive->material->pbr_metallic_roughness.base_color_texture.texture);
				if (primitive->material->alpha_mode==1) tex->flags|=2;
				if (primitive->material->alpha_mode==2) tex->flags|=4;
				surf->brush->tex[0]=tex;
				surf->brush->cache_frame[0]=tex->texture;
				surf->brush->no_texs=1;
			}

		}


		for (cgltf_size k = 0; k < primitive->attributes_count; ++k) {
			cgltf_attribute* attribute = &primitive->attributes[k];

			cgltf_accessor* accessor = attribute->data;
			cgltf_size vertex_count = accessor->count;
			cgltf_buffer_view* buffer_view = accessor->buffer_view;
			cgltf_buffer* buffer = buffer_view->buffer;

			if (vertex_count!=(unsigned int)surf->no_verts){
				surf->no_verts=vertex_count;
				surf->vert_coords.resize(vertex_count*3);
				surf->vert_col.resize(vertex_count*4);
				surf->vert_norm.resize(vertex_count*3);
				surf->vert_tex_coords0.resize(vertex_count*2);
				surf->vert_tex_coords1.resize(vertex_count*2);

			}

			if (attribute->type == cgltf_attribute_type_position) {
				const void* data_ptr = ((const uint8_t*)buffer->data) + buffer_view->offset + accessor->offset;

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					const float* vertex = (const float*)((const uint8_t*)data_ptr + v * accessor->stride);
					surf->vert_coords[v*3  ]=vertex[0];
					surf->vert_coords[v*3+1]=vertex[1];
					surf->vert_coords[v*3+2]=vertex[2];
					//surf->AddVertex(vertex[0], vertex[1], -vertex[2]);
				}
			}
			if (attribute->type == cgltf_attribute_type_normal) {
				const void* data_ptr = ((const uint8_t*)buffer->data) + buffer_view->offset + accessor->offset;

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					const float* normal = (const float*)((const uint8_t*)data_ptr + v * accessor->stride);
					surf->vert_norm[v*3  ]=normal[0];
					surf->vert_norm[v*3+1]=normal[1];
					surf->vert_norm[v*3+2]=normal[2];
					//surf->VertexNormal(v, normal[0], normal[1], normal[2]);
				}
			}
			if (attribute->type == cgltf_attribute_type_texcoord) {

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					cgltf_float uv[2];
					cgltf_accessor_read_float(accessor, v, uv, 2);

					if (tex_coords==0){
						surf->vert_tex_coords0[v*2  ]=uv[0];
						surf->vert_tex_coords0[v*2+1]=uv[1];
					}else{
						surf->vert_tex_coords1[v*2  ]=uv[0];
						surf->vert_tex_coords1[v*2+1]=uv[1];
					}
				}
				tex_coords=1;

			}
			if (attribute->type == cgltf_attribute_type_color) {
				const void* data_ptr = ((const uint8_t*)buffer->data) + buffer_view->offset + accessor->offset;

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					const float* vertex = (const float*)((const uint8_t*)data_ptr + v * accessor->stride);
					surf->VertexColor(v, vertex[0]*255.0, vertex[1]*255.0, vertex[2]*255.0);
				}
			}
			if (attribute->type == cgltf_attribute_type_joints) {
				if (!anim_surf){
					anim_surf=new Surface();

					model->anim_surf_list.push_back(anim_surf);
				}

				anim_surf->vert_bone1_no.resize(surf->no_verts+1);
				anim_surf->vert_bone2_no.resize(surf->no_verts+1);
				anim_surf->vert_bone3_no.resize(surf->no_verts+1);
				anim_surf->vert_bone4_no.resize(surf->no_verts+1);

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					cgltf_uint joints[4];
					cgltf_accessor_read_uint(accessor, v, joints, 4);
					anim_surf->vert_bone1_no[v]=joints[0]+1;
					anim_surf->vert_bone2_no[v]=joints[1]+1;
					anim_surf->vert_bone3_no[v]=joints[2]+1;
					anim_surf->vert_bone4_no[v]=joints[3]+1;

				}
			}
			if (attribute->type == cgltf_attribute_type_weights) {
				if (!anim_surf){
					anim_surf=new Surface();

					model->anim_surf_list.push_back(anim_surf);
				}

				anim_surf->vert_weight1.resize(surf->no_verts+1);
				anim_surf->vert_weight2.resize(surf->no_verts+1);
				anim_surf->vert_weight3.resize(surf->no_verts+1);
				anim_surf->vert_weight4.resize(surf->no_verts+1);

				for (cgltf_size v = 0; v < vertex_count; ++v) {
					cgltf_float weights[4];
					cgltf_accessor_read_float(accessor, v, weights, 4);
					anim_surf->vert_weight1[v]=weights[0];
					anim_surf->vert_weight2[v]=weights[1];
					anim_surf->vert_weight3[v]=weights[2];
					anim_surf->vert_weight4[v]=weights[3];

				}
			}
		}

		if (anim_surf!=0){
			anim_surf->no_verts=surf->no_verts;
			anim_surf->vert_coords=surf->vert_coords;
		}



		if (primitive->indices) {
			cgltf_accessor* accessor = primitive->indices;
			cgltf_size index_count = accessor->count;
			cgltf_buffer_view* buffer_view = accessor->buffer_view;
			cgltf_buffer* buffer = buffer_view->buffer;

			const void* data_ptr = ((const uint8_t*)buffer->data) + buffer_view->offset + accessor->offset;

			for (cgltf_size idx = 0; idx < index_count; idx+=3) {
				uint32_t index[3];
				switch (accessor->component_type) {
					case cgltf_component_type_r_8:
					case cgltf_component_type_r_8u:
						index[0] = ((const uint8_t*)data_ptr)[idx];
						index[1] = ((const uint8_t*)data_ptr)[idx+1];
						index[2] = ((const uint8_t*)data_ptr)[idx+2];
						break;
					case cgltf_component_type_r_16:
					case cgltf_component_type_r_16u:
						index[0] = ((const uint16_t*)data_ptr)[idx];
						index[1] = ((const uint16_t*)data_ptr)[idx+1];
						index[2] = ((const uint16_t*)data_ptr)[idx+2];
						break;
					case cgltf_component_type_r_32u:
						index[0] = ((const uint32_t*)data_ptr)[idx];
						index[1] = ((const uint32_t*)data_ptr)[idx+1];
						index[2] = ((const uint32_t*)data_ptr)[idx+2];
						break;
					default:
						continue;
				}
				surf->AddTriangle(index[2], index[1], index[0]);
			}
		}
	}

	mesh_list.push_back(model);

	if (root==NULL) {
		root=model;
	}else{
		if (root->anim_surf_list.size()==root->surf_list.size() && model->anim_surf_list.size()==model->surf_list.size() ){
			root->anim_surf_list.splice(root->anim_surf_list.end(), model->anim_surf_list);
			root->surf_list.splice(root->surf_list.end(), model->surf_list);
			root->no_surfs+=model->no_surfs;
			model->no_surfs=0;
			model->FreeEntity();
			mesh_list.back()=0;
		}//else model->AddParent(root);
	}
}

static void LoadNode(const cgltf_node* node, Entity* ent){

	ent->name=node->name;

	if (node->has_matrix){
		ent->rotmat.grid[0][0]=node->matrix[0];
		ent->rotmat.grid[0][1]=node->matrix[1];
		ent->rotmat.grid[0][2]=node->matrix[2];
		ent->rotmat.grid[0][3]=node->matrix[3];
		ent->rotmat.grid[1][0]=node->matrix[4];
		ent->rotmat.grid[1][1]=node->matrix[5];
		ent->rotmat.grid[1][2]=node->matrix[6];
		ent->rotmat.grid[1][3]=node->matrix[7];
		ent->rotmat.grid[2][0]=node->matrix[8];
		ent->rotmat.grid[2][1]=node->matrix[9];
		ent->rotmat.grid[2][2]=node->matrix[10];
		ent->rotmat.grid[2][3]=node->matrix[11];
		ent->px=node->matrix[12];
		ent->py=node->matrix[13];
		ent->pz=-node->matrix[14];
		ent->rotmat.ToRotMat();
	}

	if (node->has_rotation){
		ent->rotmat.FromQuaternion(node->rotation[0], node->rotation[1], node->rotation[2], node->rotation[3]);
	}
	if (node->has_translation){
		ent->px=node->translation[0];
		ent->py=node->translation[1];
		ent->pz=-node->translation[2];
	}
	if (node->has_scale){
		ent->sx=node->scale[0];
		ent->sy=node->scale[1];
		ent->sz=node->scale[2];
	}


	/*if(dynamic_cast<Bone*>(bone->parent)!=NULL){
		bone->mat2.Multiply2(dynamic_cast<Bone*>(bone->parent)->mat2);
	}

	for (cgltf_size i = 0; i < node->children_count; ++i) {
        	LoadBoneNode(node->children[i], bone);
	}*/
	//return bone;

}

/*static void LoadNode(const cgltf_node* node){
	Entity* p=last_ent;

	if (node->mesh!=0) {
		LoadMeshNode(node->mesh);
	}


	if (node->skin!=0) {
		for (cgltf_size i = 0; i < node->skin->joints_count; ++i) {
			LoadBoneNode(node->skin->joints[i]);
		}

	}

	for (cgltf_size i = 0; i < node->children_count; ++i) {
        	LoadNode(node->children[i]);
	}




	last_ent=p;
}*/



Mesh* LoadGLtf(string filename, Entity* parent_ent){
	cgltf_options options = {};
	cgltf_result result = cgltf_parse_file(&options, filename.c_str(), &data);
	if (result != cgltf_result_success) {
		return NULL;
	}

	result = cgltf_load_buffers(&options, data, filename.c_str());
	if (result != cgltf_result_success) {
		cgltf_free(data);
		return NULL;
	}

	root=NULL;

	cgltf_skin* r_skin = NULL;

	for (cgltf_size i = 0; i < data->meshes_count; ++i) {
		cgltf_mesh* mesh = &data->meshes[i];

		LoadMeshNode(mesh, parent_ent);

	}

	if (root==NULL) root=Mesh::CreateMesh(parent_ent);

	//for (cgltf_size i0 = 0; i0 < data->skins_count; ++i0) {
	if (data->skins_count>0){
		cgltf_skin* skin = &data->skins[0];
		//vector<Bone*> s_bone(skin->joints_count);
		for (cgltf_size i = 0; i < skin->joints_count; ++i) {
			Bone* bone=new Bone;

			root->bones.push_back(bone);
			bone->class_name="Bone";
			bone->keys=new AnimationKeys();
			
			// add parent, add to list
			bone->AddParent(root);

			Entity::entity_list.push_back(bone);

			LoadNode(skin->joints[i], bone);
		}

		//Rebuild hierarchy
		for (cgltf_size i = 0; i < skin->joints_count; ++i) {
			//hierarchy of bones
			for (cgltf_size i2 = 0; i2 < skin->joints_count; ++i2) {
				if (skin->joints[i]->parent==skin->joints[i2]) {
					root->bones[i]->parent->child_list.remove(root->bones[i]);
					root->bones[i]->AddParent(root->bones[i2]);
				}
			}
			//meshes attached to bones
			for (cgltf_size i2 = 0; i2 < skin->joints[i]->children_count; ++i2) {
				cgltf_mesh* mesh=skin->joints[i]->children[i2]->mesh;
				if (mesh!=0){
					for (cgltf_size i3 = 0; i3 < data->meshes_count; ++i3) {
						if (&data->meshes[i3]==mesh){
							mesh_list[i3]->parent->child_list.remove(mesh_list[i3]);
							mesh_list[i3]->AddParent(root->bones[i]);
							LoadNode(skin->joints[i]->children[i2], mesh_list[i3]);
						}
					}
				}

			}

		}

		if (skin->inverse_bind_matrices) {
			cgltf_accessor* accessor = skin->inverse_bind_matrices;
			cgltf_size matrix_count = accessor->count;
			cgltf_buffer_view* buffer_view = accessor->buffer_view;
			cgltf_buffer* buffer = buffer_view->buffer;

			const void* data_ptr = ((const uint8_t*)buffer->data) + buffer_view->offset + accessor->offset;

			for (cgltf_size k = 0; k < matrix_count; ++k) {
				const float* matrix = (const float*)((const uint8_t*)data_ptr + k * accessor->stride);
				for (cgltf_size row = 0; row < 4; ++row) {
					for (cgltf_size col = 0; col < 4; ++col) {
						root->bones[k]->inv_mat.grid[row][col]= matrix[row * 4 + col];
					}
				}
				root->anim=1;
				root->anim_render=true;
			}
		}
		if (r_skin==NULL) r_skin=skin;

		/*list<Entity*>::iterator it;
		for(it=root->child_list.begin();it!=root->child_list.end();it++){
			Entity* ent=*it;
			if(dynamic_cast<Mesh*>(ent)){
				Mesh* mesh=dynamic_cast<Mesh*>(ent);
				mesh->bones=root->bones;
				mesh->anim=1;
				mesh->anim_render=true;

			}

		}*/


	}


	unsigned int frame_start=0;

	for (cgltf_size i = 0; i < data->animations_count; ++i) {
		cgltf_animation* animation = &data->animations[i];
		//printf("Animation %zu: %s\n", i, animation->name ? animation->name : "Unnamed");

		float start_time = FLT_MAX;
		float end_time = FLT_MIN;

		for (cgltf_size j = 0; j < animation->samplers_count; ++j) {
			cgltf_animation_sampler* sampler = &animation->samplers[j];

			// Find the minimum and maximum keyframe times in the input accessor
			for (cgltf_size k = 0; k < sampler->input->count; ++k) {
				float time;
				cgltf_accessor_read_float(sampler->input, k, &time, 1);
				if (time < start_time) start_time = time;
				if (time > end_time) end_time = time;
			}
		}

		int duration = (int) ((end_time - start_time) * frame_rate);

		root->no_seqs=root->no_seqs+1;

		// expand anim_seqs array
		root->anim_seqs_first.push_back(root->anim_seqs_last[0]);
		root->anim_seqs_last.push_back(root->anim_seqs_last[0]+duration);

		root->anim_seqs_last[0]=root->anim_seqs_last[0]+duration;

			vector<Bone*>::iterator it;

			for(it=root->bones.begin();it!=root->bones.end();it++){

				Bone& bone=**it;
				bone.keys->frames=root->anim_seqs_last[0];;
				bone.keys->flags.resize(root->anim_seqs_last[0]+1);
				bone.keys->px.resize(root->anim_seqs_last[0]+1);
				bone.keys->py.resize(root->anim_seqs_last[0]+1);
				bone.keys->pz.resize(root->anim_seqs_last[0]+1);
				bone.keys->sx.resize(root->anim_seqs_last[0]+1);
				bone.keys->sy.resize(root->anim_seqs_last[0]+1);
				bone.keys->sz.resize(root->anim_seqs_last[0]+1);
				bone.keys->qw.resize(root->anim_seqs_last[0]+1);
				bone.keys->qx.resize(root->anim_seqs_last[0]+1);
				bone.keys->qy.resize(root->anim_seqs_last[0]+1);
				bone.keys->qz.resize(root->anim_seqs_last[0]+1);


			}


		for (cgltf_size j = 0; j < animation->channels_count; ++j) {
			cgltf_animation_channel* channel = &animation->channels[j];
			cgltf_animation_sampler* sampler = channel->sampler;


			int bone_found=0;
			cgltf_size no_bone;
			for (no_bone = 0; no_bone < r_skin->joints_count; ++no_bone) {
				if (r_skin->joints[no_bone]==channel->target_node){
					bone_found=1;
					break;
				}
			}

			if (bone_found!=0 && sampler->input->count==sampler->output->count){
				for (cgltf_size k = 0; k < sampler->input->count; ++k) {
					// Read input (keyframe times)
					unsigned int frame;
					float time;
					cgltf_accessor_read_float(sampler->input, k, &time, 1);
					frame = time * frame_rate;
					frame+=frame_start;

					// Read output (keyframe values)
					float value[4]; // Max size for quaternion
					cgltf_accessor_read_float(sampler->output, k, value, sampler->output->type == cgltf_type_vec3 ? 3 : 4);

					Bone* bone=root->bones[no_bone];

					if (channel->target_path==cgltf_animation_path_type_translation){
						bone->keys->flags[frame] |= 1;
						bone->keys->px[frame]=value[0];
						bone->keys->py[frame]=value[1];
						bone->keys->pz[frame]=value[2];
					}
					if (channel->target_path==cgltf_animation_path_type_rotation){
						bone->keys->flags[frame] |= 4;
						bone->keys->qx[frame]=value[0];
						bone->keys->qy[frame]=value[1];
						bone->keys->qz[frame]=value[2];
						bone->keys->qw[frame]=value[3];
					}
					if (channel->target_path==cgltf_animation_path_type_scale){
						bone->keys->flags[frame] |= 2;
						bone->keys->sx[frame]=value[0];
						bone->keys->sy[frame]=value[1];
						bone->keys->sz[frame]=value[2];
					}

				}
			}

		}
		frame_start+=duration;		//next animation will start after the current one
	}


	//root->AddAnimSeq(1);
	/*for (cgltf_size i = 0; i < data->scenes_count; ++i) {
		cgltf_scene* scene = &data->scenes[i];

		for (cgltf_size j = 0; j < scene->nodes_count; ++j) {
			LoadNode(scene->nodes[j]);
		}
	}*/
/*    for (cgltf_size i = 0; i < data->textures_count; ++i) {
        cgltf_texture* texture = &data->textures[i];
        printf("Texture %zu:\n", i);

        if (texture->image) {
            cgltf_image* image = texture->image;

            if (image->uri) {
                printf("  Image URI: %s\n", image->uri);

                if (strncmp(image->uri, "data:image/", 11) == 0) {
                  printf("  Base64-encoded image found\n");

                  // Extract the Base64 data (after the comma in the URI)
                  const char* base64_data = strchr(image->uri, ',');
                  if (!base64_data) {
                      fprintf(stderr, "  Invalid Base64 URI\n");
                      continue;
                  }
                  base64_data++; // Skip the comma

                  // Decode the Base64 data using cgltf_load_buffer_base64
                  void* decoded_data = NULL;
                  cgltf_size decoded_size = 0;
                  cgltf_options options = {};
                  cgltf_result result = cgltf_load_buffer_base64(&options, strlen(base64_data), base64_data, &decoded_data);
                  if (result != cgltf_result_success || !decoded_data) {
                      fprintf(stderr, "  Failed to decode Base64 data\n");
                      continue;
                  }

                  // Decode the image using stb_image
                  int width, height, channels;
                  unsigned char* img_data = stbi_load_from_memory((const uint8_t*)decoded_data, decoded_size, &width, &height, &channels, 4);
                  if (img_data) {
                      printf("  Image decoded: %dx%d, Channels: %d\n", width, height, channels);
                      stbi_image_free(img_data);
                  } else {
                      fprintf(stderr, "  Failed to decode image with stb_image\n");
                  }

                  // Free the decoded Base64 data
                  free(decoded_data);
                } else {
                    // Load the image from an external file using stb_image
                    int width, height, channels;
                    unsigned char* img_data = stbi_load(image->uri, &width, &height, &channels, 4);
                    if (img_data) {
                        printf("  Image loaded: %dx%d, Channels: %d\n", width, height, channels);
                        stbi_image_free(img_data);
                    } else {
                        fprintf(stderr, "  Failed to load image: %s\n", image->uri);
                    }
                }
            } else if (image->buffer_view) {
                // Embedded binary image data
                const uint8_t* image_data = cgltf_buffer_view_data(image->buffer_view);
                printf("  Image data found in buffer view (size: %zu bytes)\n", image->buffer_view->size);

                // Decode the embedded image data with stb_image
                int width, height, channels;
                unsigned char* img_data = stbi_load_from_memory(image_data, image->buffer_view->size, &width, &height, &channels, 4);
                if (img_data) {
                    printf("  Image decoded: %dx%d, Channels: %d\n", width, height, channels);
                    stbi_image_free(img_data);
                } else {
                    fprintf(stderr, "  Failed to decode image data from buffer view\n");
                }
            } else {
                printf("  Image has no URI or buffer view\n");
            }
        } else {
            printf("  No image associated with the texture\n");
        }
    }

    for (cgltf_size i = 0; i < data->materials_count; ++i) {
        cgltf_material* material = &data->materials[i];
        printf("Material %zu:\n", i);
        printf("  Name: %s\n", material->name ? material->name : "Unnamed");

        if (material->has_pbr_metallic_roughness) {
            printf("  PBR Metallic Roughness:\n");
            printf("    Base Color Factor: [%f, %f, %f, %f]\n",
                   material->pbr_metallic_roughness.base_color_factor[0],
                   material->pbr_metallic_roughness.base_color_factor[1],
                   material->pbr_metallic_roughness.base_color_factor[2],
                   material->pbr_metallic_roughness.base_color_factor[3]);
            printf("    Metallic Factor: %f\n",
                   material->pbr_metallic_roughness.metallic_factor);
            printf("    Roughness Factor: %f\n",
                   material->pbr_metallic_roughness.roughness_factor);
        }

        if (material->normal_texture.texture) {
            printf("  Normal Texture: Yes\n");
        } else {
            printf("  Normal Texture: No\n");
        }

        if (material->occlusion_texture.texture) {
            printf("  Occlusion Texture: Yes\n");
        } else {
            printf("  Occlusion Texture: No\n");
        }

        if (material->emissive_texture.texture) {
            printf("  Emissive Texture: Yes\n");
        } else {
            printf("  Emissive Texture: No\n");
        }

        printf("  Emissive Factor: [%f, %f, %f]\n",
               material->emissive_factor[0],
               material->emissive_factor[1],
               material->emissive_factor[2]);

        printf("  Alpha Mode: %d\n", material->alpha_mode);
        printf("  Alpha Cutoff: %f\n", material->alpha_cutoff);
        printf("  Double Sided: %s\n", material->double_sided ? "Yes" : "No");
    }*/
	cgltf_free(data);
	mesh_list.clear();

	root->MQ_Update();
	return root;
}

}
