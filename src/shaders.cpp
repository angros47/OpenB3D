#include "shaders.h"

const char *GLES2_Shader::version="#version 100\r\n";


const char *GLES2_Shader::vert_flags[]={"", "#define Lights 1\r\n","#define Lights 2\r\n","#define Lights 3\r\n","#define Lights 4\r\n","#define Lights 5\r\n","#define Lights 6\r\n","#define Lights 7\r\n","#define Lights 8\r\n"};

const char *GLES2_Shader::fog_flags[]={"", "#define Fog\r\n"};

const char *GLES2_Shader::vert_shader=
"  attribute highp vec3 aVertexNormal;"
"  attribute highp vec3 aVertexPosition;"
"  attribute highp vec4 aVertexColor;"
"  attribute highp vec2 aTextureCoord;"
"  attribute highp vec2 aTextureCoord2;"

"  uniform lowp float uShine;\r\n"
"  uniform highp mat4 uMMatrix;"
"  uniform highp mat4 uVMatrix;"
"  uniform highp mat4 uPMatrix;"
"  uniform lowp vec3 AmbLight;\r\n"
"  uniform lowp vec2 fogRange;\r\n"

"#ifdef Lights\r\n"
"  uniform highp mat4 LightMatrix[Lights];\r\n"
"  uniform lowp float LightType[Lights];\r\n"
"  uniform lowp vec3 LightColor[Lights];\r\n"
"  uniform lowp float LightOuterCone[Lights];\r\n"
"#endif\r\n"
  
"  varying highp vec2 vTextureCoord;"
"  varying highp vec2 vTextureCoord2;"
"  varying lowp vec3 vLighting;"
"  varying lowp vec4 vColor;"
"  varying lowp vec3 vNormal;\r\n"
"  varying lowp float fogBlend;\r\n"

"  void main(void) {"
"    vec4 vertpos = uPMatrix * uVMatrix * uMMatrix * vec4(aVertexPosition, 1.0);"
"    gl_Position = vertpos;"
"    vTextureCoord = aTextureCoord;"
"    vTextureCoord2 = aTextureCoord2;"

"    lowp vec3 pos_eye=normalize(vec3(uVMatrix * uMMatrix * vec4(aVertexPosition, 1.0)));"
"    lowp vec3 norm_eye=normalize(vec3(uVMatrix * uMMatrix * vec4(aVertexNormal, 0.0)));"
"    vNormal = vec3(vec4(reflect( pos_eye, norm_eye),0.0)*uVMatrix);"
"    vColor = aVertexColor;\r\n"
    
"#ifdef Lights\r\n"
"    lowp vec3 lightSum=vec3(0.0,0.0,0.0);"
"    lowp vec3 specSum=vec3(0.0,0.0,0.0);"
"    highp vec3 eye = (vec4(0.0, 0.0, 1.0,0.0)*uVMatrix).xyz;\r\n"
"    highp vec3 aVNormal = normalize(aVertexNormal);\r\n"
"    for (int i=0; i<Lights; ++i){"
"    	if (LightType[i]==1.0){"
"    		highp vec4 lightdir = LightMatrix[i]*vec4(0.0, 0.0, 1.0,0.0);\r\n"
"    		highp vec3 directionalVector = normalize(vec3(lightdir*uMMatrix));\r\n"
"    		highp float directional = clamp(dot(aVNormal, directionalVector), 0.0, 1.0);\r\n"
"    		lightSum += LightColor[i] * directional;\r\n"
"    		highp float specDirectional = clamp(pow(max(dot(reflect(-directionalVector, aVNormal),eye),0.0),100.0),0.0,1.0);\r\n"
"    		specSum += vec3(uShine) * specDirectional;\r\n"
"    	}else if (LightType[i]==2.0){\r\n"
"    		highp vec4 lightPos= LightMatrix[i][3];\r\n"
"    		highp vec3 PositionalVector = normalize((lightPos-uMMatrix*vec4(aVertexPosition, 1.0))*uMMatrix).xyz;\r\n"
"    		highp float point = clamp(dot(aVNormal, PositionalVector), 0.0, 1.0);\r\n"
"    		lightSum += LightColor[i] * point;\r\n"
"    		highp float specPoint = pow(max(dot(reflect(-PositionalVector, aVNormal),eye),0.0),100.0);\r\n"
"    		specSum += vec3(uShine) * specPoint;\r\n"
"    	}else if (LightType[i]==3.0){\r\n"
"    		highp vec4 lightPos= LightMatrix[i][3];\r\n"
"    		highp vec4 lightdir = LightMatrix[i]*vec4(0.0, 0.0, 1.0,0.0);\r\n"
"    		highp vec3 directionalVector = vec3(lightdir*uMMatrix);\r\n"
"    		highp vec3 PositionalVector = normalize((lightPos-uMMatrix*vec4(aVertexPosition, 1.0))*uMMatrix).xyz;\r\n"
"    		highp float point = clamp(dot(aVNormal, PositionalVector), 0.0, 1.0);\r\n"
"    		highp float spot = step(LightOuterCone[i],dot(directionalVector, PositionalVector)/length(directionalVector));\r\n"
"    		point *= spot;\r\n"
"    		lightSum += LightColor[i] * point;\r\n"
"    		highp float specSpot = clamp(pow(max(dot(reflect(-PositionalVector, aVNormal),eye),0.0),100.0),0.0,1.0);\r\n"
"    		specSpot *= spot;\r\n"
"    		specSum += vec3(uShine) * specSpot;\r\n"
"    	}\r\n"
"    }\r\n"
"    vLighting = clamp(AmbLight + lightSum + specSum,0.0, 1.0);\r\n"
"#else\r\n"
"    vLighting = AmbLight;\r\n"
"#endif\r\n"
"#ifdef Fog\r\n"
"    fogBlend=clamp((length(vertpos.xyz) - fogRange.x) / (fogRange.y - fogRange.x), 0.0, 1.0);\r\n"
"#endif\r\n"
"  }\r\n";




const char *GLES2_Shader::frag_flags[]={"", "#define Textures 1\r\n","#define Textures 2\r\n","#define Textures 3\r\n","#define Textures 4\r\n","#define Textures 5\r\n","#define Textures 6\r\n","#define Textures 7\r\n","#define Textures 8\r\n"};


const char *GLES2_Shader::frag_shader=
"  varying highp vec2 vTextureCoord;\r\n"
"  varying highp vec2 vTextureCoord2;\r\n"
"  varying lowp vec3 vLighting;\r\n"
"  varying lowp vec4 vColor;\r\n"
"  varying lowp vec3 vNormal;\r\n"
  
"#ifdef Textures\r\n"
"  uniform sampler2D uSampler0;\r\n"
"  uniform ivec2 texFlag[Textures];\r\n"
"  uniform lowp mat3 texMat[Textures];\r\n"
"  uniform lowp float tex_coord_set[Textures];\r\n"
"  uniform samplerCube uSamplerC0;\r\n"
"    #if (Textures>1)\r\n"
"	  uniform sampler2D uSampler1;\r\n"
"	  uniform samplerCube uSamplerC1;\r\n"
"    #endif\r\n"
"    #if (Textures>2)\r\n"
"	  uniform sampler2D uSampler2;\r\n"
"	  uniform samplerCube uSamplerC2;\r\n"
"    #endif\r\n"
"    #if (Textures>3)\r\n"
"	  uniform sampler2D uSampler3;\r\n"
"	  uniform samplerCube uSamplerC3;\r\n"
"    #endif\r\n"
"    #if (Textures>4)\r\n"
"	  uniform sampler2D uSampler4;\r\n"
"	  uniform samplerCube uSamplerC4;\r\n"
"    #endif\r\n"
"    #if (Textures>5)\r\n"
"	  uniform sampler2D uSampler5;\r\n"
"	  uniform samplerCube uSamplerC5;\r\n"
"    #endif\r\n"
"    #if (Textures>6)\r\n"
"	  uniform sampler2D uSampler6;\r\n"
"	  uniform samplerCube uSamplerC6;\r\n"
"    #endif\r\n"
"    #if (Textures>7)\r\n"
"	  uniform sampler2D uSampler7;\r\n"
"	  uniform samplerCube uSamplerC7;\r\n"
"    #endif\r\n"
"    #if (Textures>8)\r\n"
"	  uniform sampler2D uSampler8;\r\n"
"	  uniform samplerCube uSamplerC8;\r\n"
"    #endif\r\n"
"#endif\r\n"

"  uniform lowp vec3 fogColor;\r\n"
"  varying lowp float fogBlend;\r\n"
  
"  void main(void) {\r\n"
"#ifdef Textures\r\n"
"    mediump vec4 pixColor = vColor;\r\n"
"    mediump vec4 texColor[Textures];\r\n"
"      texColor[0] = texture2D(uSampler0, (texMat[0]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[0]),1.0)).xy);\r\n"
"    #if (Textures>1)\r\n"
"      texColor[1] = texture2D(uSampler1, (texMat[1]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[1]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>2)\r\n"
"      texColor[2] = texture2D(uSampler2, (texMat[2]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[2]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>3)\r\n"
"      texColor[3] = texture2D(uSampler3, (texMat[3]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[3]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>4)\r\n"
"      texColor[4] = texture2D(uSampler4, (texMat[4]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[4]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>5)\r\n"
"      texColor[5] = texture2D(uSampler5, (texMat[5]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[5]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>6)\r\n"
"      texColor[6] = texture2D(uSampler6, (texMat[6]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[6]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>7)\r\n"
"      texColor[7] = texture2D(uSampler7, (texMat[7]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[7]),1.0)).xy);\r\n"
"    #endif\r\n"
"    #if (Textures>8)\r\n"
"      texColor[8] = texture2D(uSampler8, (texMat[8]*vec3(mix(vTextureCoord,vTextureCoord2,tex_coord_set[8]),1.0)).xy);\r\n"
"    #endif\r\n"
"    mediump vec4 cubeColor[Textures];\r\n"
"      cubeColor[0] = textureCube(uSamplerC0, vNormal);\r\n"
"    #if (Textures>1)\r\n"
"      cubeColor[1] = textureCube(uSamplerC1, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>2)\r\n"
"      cubeColor[2] = textureCube(uSamplerC2, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>3)\r\n"
"      cubeColor[3] = textureCube(uSamplerC3, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>4)\r\n"
"      cubeColor[4] = textureCube(uSamplerC4, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>5)\r\n"
"      cubeColor[5] = textureCube(uSamplerC5, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>6)\r\n"
"      cubeColor[6] = textureCube(uSamplerC6, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>7)\r\n"
"      cubeColor[7] = textureCube(uSamplerC7, vNormal);\r\n"
"    #endif\r\n"
"    #if (Textures>8)\r\n"
"      cubeColor[8] = textureCube(uSamplerC8, vNormal);\r\n"
"    #endif\r\n"
"    mediump vec4 texelColor;\r\n"
"    for (int i=0; i<Textures; ++i){"
"    	if (texFlag[i][1]==128) {"
"    	  texelColor = cubeColor[i];\r\n"
"       }else{"
"    	  texelColor = texColor[i];"
"    	}\r\n"
"    	if (texFlag[i][1]==4 && texelColor.a<0.5) {discard;}\r\n"
"    	if (texFlag[i][0]==0) pixColor = texelColor;\r\n"
"    	else if (texFlag[i][0]==1) pixColor = mix(pixColor, texelColor,texelColor.a);\r\n"
"    	else if (texFlag[i][0]==2) pixColor *= texelColor;\r\n"
"    	else if (texFlag[i][0]==3) pixColor += texelColor;\r\n"
"    }\r\n"
"#else\r\n"
"    mediump vec4 pixColor = vColor;\r\n"
"#endif\r\n"

"#ifdef Fog\r\n"
"    gl_FragColor =  vec4(mix(pixColor.rgb * vLighting, fogColor, fogBlend) * pixColor.a, pixColor.a);\r\n"
"#else\r\n"
"    gl_FragColor =  vec4(pixColor.rgb * vLighting * pixColor.a, pixColor.a);\r\n"
"#endif\r\n"
"  }\r\n";




const char *GLES2_Shader::vert_stencil=
"  attribute highp vec2 aVertexPosition;\r\n"
"  void main(void) {"
"    gl_Position = vec4(aVertexPosition, 0.0, 1.0);"
"  }\r\n";

const char *GLES2_Shader::frag_stencil=
"  uniform lowp vec4 uColor;\r\n"
"  void main(void) {"
"    gl_FragColor = uColor;"
"  }\r\n";

const char *GLES2_Shader::vert_particle=
"  attribute highp vec3 aVertexPosition;\r\n"
"  attribute highp vec4 aVertexColor;"
"  uniform highp mat4 uVMatrix;"
"  uniform highp mat4 uPMatrix;"

"  varying lowp vec4 vColor;\r\n"
"  void main(void) {"
"    highp vec4 position=uVMatrix * vec4(aVertexPosition, 1.0);"
"    gl_PointSize = - 1000.0/position.z;"
"    gl_Position = uPMatrix * position;"
"    vColor = aVertexColor;"

"  }\r\n";

const char *GLES2_Shader::frag_particle=
"  varying lowp vec4 vColor;\r\n"
"  uniform sampler2D uSampler0;\r\n"
"  uniform int texFlag;\r\n"
"  void main(void) {"
"    lowp vec4 fColor=vColor*texture2D(uSampler0, gl_PointCoord);"
"    if (texFlag==4 && fColor.a<0.5) {discard;}\r\n"
"    gl_FragColor = fColor;"
"  }\r\n";

const char *GLES2_Shader::vert_voxel=
"  attribute highp vec3 aVertexPosition;\r\n"
"  attribute highp vec3 aVertexNormal;"
"  uniform highp mat4 uMMatrix;"
"  uniform highp mat4 uVMatrix;"
"  uniform highp mat4 uPMatrix;"
"  varying highp vec3 texcoords;"
"  varying highp vec3 ray;"

"  varying lowp vec4 vColor;\r\n"
"highp mat4 InverseMatrix( mat4 A ) {"

"	highp float s0 = A[0][0] * A[1][1] - A[1][0] * A[0][1];"
"	highp float s1 = A[0][0] * A[1][2] - A[1][0] * A[0][2];"
"	highp float s2 = A[0][0] * A[1][3] - A[1][0] * A[0][3];"
"	highp float s3 = A[0][1] * A[1][2] - A[1][1] * A[0][2];"
"	highp float s4 = A[0][1] * A[1][3] - A[1][1] * A[0][3];"
"	highp float s5 = A[0][2] * A[1][3] - A[1][2] * A[0][3];"
		     
"	highp float c5 = A[2][2] * A[3][3] - A[3][2] * A[2][3];"
"	highp float c4 = A[2][1] * A[3][3] - A[3][1] * A[2][3];"
"	highp float c3 = A[2][1] * A[3][2] - A[3][1] * A[2][2];"
"	highp float c2 = A[2][0] * A[3][3] - A[3][0] * A[2][3];"
"	highp float c1 = A[2][0] * A[3][2] - A[3][0] * A[2][2];"
"	highp float c0 = A[2][0] * A[3][1] - A[3][0] * A[2][1];"
		     
"	highp float invdet = 1.0 / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);"
		     
"	highp mat4 B;"
		     
"	B[0][0] = ( A[1][1] * c5 - A[1][2] * c4 + A[1][3] * c3) * invdet;"
"	B[0][1] = (-A[0][1] * c5 + A[0][2] * c4 - A[0][3] * c3) * invdet;"
"	B[0][2] = ( A[3][1] * s5 - A[3][2] * s4 + A[3][3] * s3) * invdet;"
"	B[0][3] = (-A[2][1] * s5 + A[2][2] * s4 - A[2][3] * s3) * invdet;"
		     
"	B[1][0] = (-A[1][0] * c5 + A[1][2] * c2 - A[1][3] * c1) * invdet;"
"	B[1][1] = ( A[0][0] * c5 - A[0][2] * c2 + A[0][3] * c1) * invdet;"
"	B[1][2] = (-A[3][0] * s5 + A[3][2] * s2 - A[3][3] * s1) * invdet;"
"	B[1][3] = ( A[2][0] * s5 - A[2][2] * s2 + A[2][3] * s1) * invdet;"
		     
"	B[2][0] = ( A[1][0] * c4 - A[1][1] * c2 + A[1][3] * c0) * invdet;"
"	B[2][1] = (-A[0][0] * c4 + A[0][1] * c2 - A[0][3] * c0) * invdet;"
"	B[2][2] = ( A[3][0] * s4 - A[3][1] * s2 + A[3][3] * s0) * invdet;"
"	B[2][3] = (-A[2][0] * s4 + A[2][1] * s2 - A[2][3] * s0) * invdet;"
		     
"	B[3][0] = (-A[1][0] * c3 + A[1][1] * c1 - A[1][2] * c0) * invdet;"
"	B[3][1] = ( A[0][0] * c3 - A[0][1] * c1 + A[0][2] * c0) * invdet;"
"	B[3][2] = (-A[3][0] * s3 + A[3][1] * s1 - A[3][2] * s0) * invdet;"
"	B[3][3] = ( A[2][0] * s3 - A[2][1] * s1 + A[2][2] * s0) * invdet;"
		     
"	return B;"
"}\r\n"
"  void main(void) {"
"    vec4 vertpos = uPMatrix * uVMatrix * uMMatrix * vec4(aVertexPosition, 1.0);"
"    texcoords = aVertexPosition;"
"    gl_Position = vertpos;"
"	highp mat4 modelViewMatrixInverse = InverseMatrix( uVMatrix * uMMatrix );"

"    lowp vec3 pos_eye=vec3(uVMatrix * uMMatrix * vec4(aVertexPosition, 1.0));"
"    lowp vec3 norm_eye=normalize(vec3(vec4(aVertexNormal, 0.0)*uVMatrix * uMMatrix));"
"    highp vec3 worldpos = aVertexPosition-modelViewMatrixInverse[3].xyz;"
"    ray = worldpos;"



"  }\r\n";

const char *GLES2_Shader::frag_voxel=
"  uniform sampler2D uSampler0;\r\n"
"  uniform int texFlag;\r\n"
"  varying highp vec3 texcoords;"
"  uniform highp float slices;"
"  varying highp vec3 ray;"

"  void main(void) {"
"    highp vec3 tex_coords=texcoords;"
"    for (int i=0; i<48; ++i){"
"      highp vec3 tcoords=(tex_coords+1.0)/2.0;"
"      if (tcoords!=clamp(tcoords,0.0,1.0)) {discard;}"
"      highp vec2 texc=vec2(tcoords.x/slices + floor(tcoords.z*slices)/slices, tcoords.y);"
"      lowp vec4 texel = texture2D(uSampler0, texc);"
"      if (texel.a>0.5) {gl_FragColor = texel; return;}\r\n"
"      tex_coords+=normalize(ray)/16.0;"
"    }"
"    discard;"
"  }\r\n";

