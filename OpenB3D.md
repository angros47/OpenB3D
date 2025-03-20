<div id="Section2" dir="ltr">

<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">OpenB3d 1.</span></span></span><span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">4</span></span></span><span style="font-variant: small-caps"><span lang="en-US"> <span style="font-weight: normal">Guide</span></span></span>

([<span style="font-variant: normal"><font size="1" style="font-size: 8pt">https://sourceforge.net/projects/minib3d/files/</font></span>](https://sourceforge.net/projects/minib3d/files/) )

</div>

<div id="Section1" dir="ltr" gutter="0" style="column-count: 2">

Global

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AmbientLight</span></span></span>](#AmbientLight)

[<span style="font-variant: small-caps">AmbientShader</span>](#AmbientShader)

[<span style="font-variant: small-caps">AntiAlias</span>](#AntiAlias)

[<span style="font-variant: small-caps">ClearWorld</span>](#ClearWorld)

[<span style="font-variant: small-caps">Graphics3D</span>](#Graphics3D)

[<span style="font-variant: small-caps">RenderWorld</span>](#RenderWorld)

[<span style="font-variant: small-caps">UpdateWorld</span>](#UpdateWorld)

[<span style="font-variant: small-caps">Wireframe</span>](#Wireframe)

Texture

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateTexture</span></span></span>](#CreateTexture)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadAnimTexture</span></span></span>](#LoadAnimTexture)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadTexture</span></span></span>](#LoadTexture)

[<span style="font-variant: small-caps">LoadMaterial</span>](#LoadMaterial)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">GetBrushTexture</span></span></span>](#GetBrushTexture)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">BackBufferToTex</span></span></span>](#BackBufferToTex)

[<span style="font-variant: small-caps">BufferToTex</span>](#BufferToTex)

[<span style="font-variant: small-caps">TexToBuffer</span>](#TexToBuffer)

[<span style="font-variant: small-caps">CameraToTex</span>](#CameraToTex)

[<span style="font-variant: small-caps">DepthBufferToTex</span>](#DepthBufferToTex)

[<span style="font-variant: small-caps">TextureFilter</span>](#TextureFilter)

[<span style="font-variant: small-caps">ClearTextureFilters</span>](#ClearTextureFilters)

[<span style="font-variant: small-caps">PositionTexture</span>](#PositionTexture)

[<span style="font-variant: small-caps">RotateTexture</span>](#RotateTexture)

[<span style="font-variant: small-caps">ScaleTexture</span>](#ScaleTexture)

[<span style="font-variant: small-caps">TextureHeight</span>](#TextureHeight)

[<span style="font-variant: small-caps">TextureWidth</span>](#TextureWidth)

[<span style="font-variant: small-caps">TextureName</span>](#TextureName)

[<span style="font-variant: small-caps">FreeTexture</span>](#FreeTexture)

[<span style="font-variant: small-caps">TextureBlend</span>](#TextureBlend)

[<span style="font-variant: small-caps">TextureCoords</span>](#TextureCoords)

[<span style="font-variant: small-caps">SetCubeFace</span>](#SetCubeFace)

[<span style="font-variant: small-caps">SetCubeMode</span>](#SetCubeMode)

Brush

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateBrush</span></span></span>](#CreateBrush)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadBrush</span></span></span>](#LoadBrush)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">BrushAlpha</span></span></span>](#BrushAlpha)

[<span style="font-variant: small-caps">BrushBlend</span>](#BrushBlend)

[<span style="font-variant: small-caps">BrushColor</span>](#BrushColor)

[<span style="font-variant: small-caps">BrushFX</span>](#BrushFX)

[<span style="font-variant: small-caps">BrushShininess</span>](#BrushShininess)

[<span style="font-variant: small-caps">BrushTexture</span>](#BrushTexture)

[<span style="font-variant: small-caps">GetEntityBrush</span>](#GetEntityBrush)

[<span style="font-variant: small-caps">GetSurfaceBrush</span>](#GetSurfaceBrush)

[<span style="font-variant: small-caps">FreeBrush</span>](#FreeBrush)

Shader

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateShader</span></span></span>](#CreateShader)

[<span style="font-variant: small-caps">CreateShaderVGF</span>](#CreateShaderVGF)

[<span style="font-variant: small-caps">LoadShader</span>](#LoadShader)

[<span style="font-variant: small-caps">LoadShaderVGF</span>](#LoadShaderVGF)

[<span style="font-variant: small-caps">F</span><span style="font-variant: small-caps">reeShader</span>](#FreeShader)

[<span style="font-variant: small-caps">GetShaderProgram</span>](#GetShaderProgram)

[<span style="font-variant: small-caps">SetFloat</span>](#SetFloat)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">SetFloat2</span>](#SetFloat2)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">SetFloat3</span>](#SetFloat3)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">SetFloat4</span>](#SetFloat4)

[<span style="font-variant: small-caps">SetInteger</span>](#SetInteger)<span style="font-variant: small-caps">,</span> <span style="font-variant: small-caps">[SetInteger2](#SetInteger2), [SetInteger3](#SetInteger3)</span><span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">SetInteger4</span>](#SetInteger4)

[<span style="font-variant: small-caps">UseFloat</span>](#UseFloat)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseFloat2</span>](#UseFloat2)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseFloat3</span>](#UseFloat3)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseFloat4</span>](#UseFloat4)

[<span style="font-variant: small-caps">UseInteger</span>](#UseInteger)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseInteger2</span>](#UseInteger2)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseInteger3</span>](#UseInteger3)<span style="font-variant: small-caps">,</span> [<span style="font-variant: small-caps">UseInteger4</span>](#UseInteger4)

[<span style="font-variant: small-caps">UseEntity</span>](#UseEntity)

[<span style="font-variant: small-caps">UseMatrix</span>](#UseMatrix)

[<span style="font-variant: small-caps">UseSurface</span>](#UseSurface)

[<span style="font-variant: small-caps">ShadeEntity</span>](#ShadeEntity)

[<span style="font-variant: small-caps">ShadeMesh</span>](#ShadeMesh)

[<span style="font-variant: small-caps">ShaderFunction</span>](#ShaderFunction)

[<span style="font-variant: small-caps">ShaderMaterial</span>](#ShaderMaterial)

[<span style="font-variant: small-caps">ShaderTexture</span>](#ShaderTexture)

[<span style="font-variant: small-caps">ShadeSurface</span>](#ShadeSurface)

Mesh

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateMesh</span></span></span>](#CreateMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadAnimMesh</span></span></span>](#LoadAnimMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadMesh</span></span></span>](#LoadMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CopyMesh</span></span></span>](#CopyMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">RepeatMesh</span></span></span>](#RepeatMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateCone</span></span></span>](#CreateCone)

[<span style="font-variant: small-caps">CreateCube</span>](#CreateCube)

[<span style="font-variant: small-caps">CreateCylinder</span>](#CreateCylinder)

[<span style="font-variant: small-caps">CreateSphere</span>](#CreateSphere)

[<span style="font-variant: small-caps">CreateQuad</span>](#CreateQuad)

[<span style="font-variant: small-caps">PaintMesh</span>](#PaintMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AddMesh</span></span></span>](#AddMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PositionMesh</span></span></span>](#PositionMesh)

[<span style="font-variant: small-caps">RotateMesh</span>](#RotateMesh)

[<span style="font-variant: small-caps">ScaleMesh</span>](#ScaleMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">MeshCSG</span></span></span>](#MeshCSG)

[<span style="font-variant: small-caps">MeshCullRadius</span>](#MeshCullRadius)

[<span style="font-variant: small-caps">C</span><span style="font-variant: small-caps">ountBones</span>](#CountBones)

[<span style="font-variant: small-caps">CountSurfaces</span>](#CountSurfaces)

[<span style="font-variant: small-caps">SkinMesh</span>](#SkinMesh)

[<span style="font-variant: small-caps">FitMesh</span>](#FitMesh)

[<span style="font-variant: small-caps">FlipMesh</span>](#FlipMesh)

[<span style="font-variant: small-caps">UpdateNormals</span>](#UpdateNormals)

[<span style="font-variant: small-caps">UpdateTexCoords</span>](#UpdateTexCoords)

[<span style="font-variant: small-caps">MeshesIntersect</span>](#MeshesIntersect)

[<span style="font-variant: small-caps">MeshDepth</span>](#MeshDepth)

[<span style="font-variant: small-caps">MeshHeight</span>](#MeshHeight)

[<span style="font-variant: small-caps">MeshWidth</span>](#MeshWidth)

[<span style="font-variant: small-caps">GetSurface</span>](#GetSurface)

Bone

<font color="#000080"><u>[CreateBone](#CreateBone)</u></font>

<font color="#000080"><u>[GetBone](#GetBone)</u></font>

<font color="#000080"><u>[MoveBone](#MoveBone)</u></font>

<font color="#000080"><u>[PositionBone](#PositionBone)</u></font>

<font color="#000080"><u>[RotateBone](#RotateBone)</u></font>

Surface

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateSurface</span></span></span>](#CreateSurface)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AddTriangle</span></span></span>](#AddTriangle)

[<span style="font-variant: small-caps">AddVertex</span>](#AddVertex)

[<span style="font-variant: small-caps">TriangleVertex</span>](#TriangleVertex)

[<span style="font-variant: small-caps">CountTriangles</span>](#CountTriangles)

[<span style="font-variant: small-caps">CountVertices</span>](#CountVertices)

[<span style="font-variant: small-caps">PaintSurface</span>](#PaintSurface)

[<span style="font-variant: small-caps">ClearSurface</span>](#ClearSurface)

[<span style="font-variant: small-caps">FindSurface</span>](#FindSurface)

[<span style="font-variant: small-caps">VertexAlpha</span>](#VertexAlpha)

[<span style="font-variant: small-caps">VertexColor</span>](#VertexColor)

[<span style="font-variant: small-caps">VertexRed</span>](#VertexRed)

[<span style="font-variant: small-caps">VertexBlue</span>](#VertexBlue)

[<span style="font-variant: small-caps">VertexGreen</span>](#VertexGreen)

[<span style="font-variant: small-caps">VertexNormal</span>](#VertexNormal)

[<span style="font-variant: small-caps">VertexNX</span>](#VertexNX)

[<span style="font-variant: small-caps">VertexNY</span>](#VertexNY)

[<span style="font-variant: small-caps">VertexNZ</span>](#VertexNZ)

[<span style="font-variant: small-caps">VertexCoords</span>](#VertexCoords)

[<span style="font-variant: small-caps">VertexX</span>](#VertexX)

[<span style="font-variant: small-caps">VertexY</span>](#VertexY)

[<span style="font-variant: small-caps">VertexZ</span>](#VertexZ)

[<span style="font-variant: small-caps">VertexTexCoords</span>](#VertexTexCoords)

[<span style="font-variant: small-caps">VertexU</span>](#VertexU)

[<span style="font-variant: small-caps">VertexV</span>](#VertexV)

[<span style="font-variant: small-caps">VertexW</span>](#VertexW)

Camera

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateCamera</span></span></span>](#CreateCamera)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CameraClsColor</span></span></span>](#CameraClsColor)

[<span style="font-variant: small-caps">CameraClsMode</span>](#CameraClsMode)

[<span style="font-variant: small-caps">CameraFogColor</span>](#CameraFogColor)

[<span style="font-variant: small-caps">CameraFogMode</span>](#CameraFogMode)

[<span style="font-variant: small-caps">CameraFogRange</span>](#CameraFogRange)

[<span style="font-variant: small-caps">CameraPick</span>](#CameraPick)

[<span style="font-variant: small-caps">CameraProject</span>](#CameraProject)

[<span style="font-variant: small-caps">ProjectedX</span>](#ProjectedX)

[<span style="font-variant: small-caps">ProjectedY</span>](#ProjectedY)

[<span style="font-variant: small-caps">ProjectedZ</span>](#ProjectedZ)

[<span style="font-variant: small-caps">CameraProjMatrix</span>](#CameraProjMatrix)

[<span style="font-variant: small-caps">CameraProjMode</span>](#CameraProjMode)

[<span style="font-variant: small-caps">CameraRange</span>](#CameraRange)

[<span style="font-variant: small-caps">CameraViewport</span>](#CameraViewport)

[<span style="font-variant: small-caps">CameraZoom</span>](#CameraZoom)

[<span style="font-variant: small-caps">EntityInView</span>](#EntityInView)

[<span style="font-variant: small-caps">PickedEntity</span>](#PickedEntity)

[<span style="font-variant: small-caps">PickedSurface</span>](#PickedSurface)

[<span style="font-variant: small-caps">PickedTriangle</span>](#PickedTriangle)

[<span style="font-variant: small-caps">PickedX</span>](#PickedX)

[<span style="font-variant: small-caps">PickedY</span>](#PickedY)

[<span style="font-variant: small-caps">PickedZ</span>](#PickedZ)

[<span style="font-variant: small-caps">PickedNX</span>](#PickedNX)

[<span style="font-variant: small-caps">PickedNY</span>](#PickedNY)

[<span style="font-variant: small-caps">PickedNZ</span>](#PickedNZ)

[<span style="font-variant: small-caps">PickedTime</span>](#PickedTime)

Light

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateLight</span></span></span>](#CreateLight)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LightColor</span></span></span>](#LightColor)

[<span style="font-variant: small-caps">LightConeAngles</span>](#LightConeAngles)

[<span style="font-variant: small-caps">LightRange</span>](#LightRange)

Pivot

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreatePivot</span></span></span>](#CreatePivot)

Sprite

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateSprite</span></span></span>](#CreateSprite)

[<span style="font-variant: small-caps">CreateVoxelSprite</span>](#CreateVoxelSprite)

[<span style="font-variant: small-caps">LoadSprite</span>](#LoadSprite)

[<span style="font-variant: small-caps">HandleSprite</span>](#HandleSprite)

[<span style="font-variant: small-caps">RotateSprite</span>](#RotateSprite)

[<span style="font-variant: small-caps">ScaleSprite</span>](#ScaleSprite)

[<span style="font-variant: small-caps">SpriteRenderMode</span>](#SpriteRenderMode)

[<span style="font-variant: small-caps">SpriteViewMode</span>](#SpriteViewMode)

[<span style="font-variant: small-caps">VoxelSpriteMaterial</span>](#VoxelSpriteMaterial)

Shadow

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateShadow</span></span></span>](#CreateShadow)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">FreeShadow</span></span></span>](#FreeShadow)

[<span style="font-variant: small-caps">ResetShadow</span>](#ResetShadow)

Plane

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreatePlane</span></span></span>](#CreatePlane)

Terrain

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateTerrain</span></span></span>](#CreateTerrain)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateGeosphere</span></span></span>](#CreateGeosphere)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadTerrain</span></span></span>](#LoadTerrain)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">LoadGeosphere</span></span></span>](#LoadGeosphere)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">GeosphereHeight</span></span></span>](#GeosphereHeight)

[<span style="font-variant: small-caps">ModifyTerrain</span>](#ModifyTerrain)

[<span style="font-variant: small-caps">ModifyGeosphere</span>](#ModifyGeosphere)

[<span style="font-variant: small-caps">TerrainHeight</span>](#TerrainHeight)

[<span style="font-variant: small-caps">TerrainX</span>](#TerrainX)

[<span style="font-variant: small-caps">TerrainY</span>](#TerrainY)

[<span style="font-variant: small-caps">TerrainZ</span>](#TerrainZ)

fluid

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateFluid</span></span></span>](#CreateFluid)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateBlob</span></span></span>](#CreateBlob)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">FluidArray</span></span></span>](#FluidArray)

[<span style="font-variant: small-caps">FluidFunction</span>](#FluidFunction)

[<span style="font-variant: small-caps">FluidThreshold</span>](#FluidThreshold)

Octree

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateOcTree</span></span></span>](#CreateOcTree)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">OctreeBlock</span></span></span>](#OctreeBlock)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">OctreeMesh</span></span></span>](#OctreeMesh)

Particle System

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateParticleEmitter</span></span></span>](#CreateParticleEmitter)

[<span style="font-variant: small-caps">EmitterParticleFunction</span>](#EmitterParticleFunction)

[<span style="font-variant: small-caps">EmitterParticleLife</span>](#EmitterParticleLife)

[<span style="font-variant: small-caps">EmitterParticleSpeed</span>](#EmitterParticleSpeed)

[<span style="font-variant: small-caps">EmitterRate</span>](#EmitterRate)

[<span style="font-variant: small-caps">EmitterVariance</span>](#EmitterVariance)

[<span style="font-variant: small-caps">EmitterVector</span>](#EmitterVector)

[<span style="font-variant: small-caps">ParticleColor</span>](#ParticleColor)

[<span style="font-variant: small-caps">ParticleTrail</span>](#ParticleTrail)

[<span style="font-variant: small-caps">ParticleVector</span>](#ParticleVector)

Entity Movement

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">MoveEntity</span></span></span>](#MoveEntity)

[<span style="font-variant: small-caps">PointEntity</span>](#PointEntity)

[<span style="font-variant: small-caps">PositionEntity</span>](#PositionEntity)

[<span style="font-variant: small-caps">TranslateEntity</span>](#TranslateEntity)

[<span style="font-variant: small-caps">RotateEntity</span>](#RotateEntity)

[<span style="font-variant: small-caps">TurnEntity</span>](#TurnEntity)

[<span style="font-variant: small-caps">ScaleEntity</span>](#ScaleEntity)

Entity Animation

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AddAnimSeq</span></span></span>](#AddAnimSeq)

[<span style="font-variant: small-caps">LoadAnimSeq</span>](#LoadAnimSeq)

[<span style="font-variant: small-caps">AnimSeq</span>](#AnimSeq)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">Animate</span></span></span>](#Animate)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AnimLength</span></span></span>](#AnimLength)

[<span style="font-variant: small-caps">AnimTime</span>](#AnimTime)

[<span style="font-variant: small-caps">Animating</span>](#Animating)

[<span style="font-variant: small-caps">SetAnimKey</span>](#SetAnimKey)

[<span style="font-variant: small-caps">SetAnimTime</span>](#SetAnimTime)

[<span style="font-variant: small-caps">ExtractAnimSeq</span>](#ExtractAnimSeq)

Entity Control

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">FreeEntity</span></span></span>](#FreeEntity)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CopyEntity</span></span></span>](#CopyEntity)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityAlpha</span></span></span>](#EntityAlpha)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityColor</span></span></span>](#EntityColor)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityShininess</span></span></span>](#EntityShininess)

[<span style="font-variant: small-caps">EntityTexture</span>](#EntityTexture)

[<span style="font-variant: small-caps">PaintEntity</span>](#PaintEntity)

[<span style="font-variant: small-caps">EntityFX</span>](#EntityFX)

[<span style="font-variant: small-caps">EntityAutoFade</span>](#EntityAutoFade)

[<span style="font-variant: small-caps">EntityBlend</span>](#EntityBlend)

[<span style="font-variant: small-caps">EntityOrder</span>](#EntityOrder)

[<span style="font-variant: small-caps">NameEntity</span>](#NameEntity)

[<span style="font-variant: small-caps">HideEntity</span>](#HideEntity)

[<span style="font-variant: small-caps">ShowEntity</span>](#ShowEntity)

[<span style="font-variant: small-caps">EntityParent</span>](#EntityParent)

[<span style="font-variant: small-caps">GetParentEntity</span>](#GetParentEntity)

[<span style="font-variant: small-caps">TFormNormal</span>](#TFormNormal)

[<span style="font-variant: small-caps">TFormPoint</span>](#TFormPoint)

[<span style="font-variant: small-caps">TFormVector</span>](#TFormVector)

[<span style="font-variant: small-caps">TFormedX</span>](#TFormedX)

[<span style="font-variant: small-caps">TFormedY</span>](#TFormedY)

[<span style="font-variant: small-caps">TFormedZ</span>](#TFormedZ)

Entity State

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CountChildren</span></span></span>](#CountChildren)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityDistance</span></span></span>](#EntityDistance)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityVisible</span></span></span>](#EntityVisible)

[<span style="font-variant: small-caps">EntityX</span>](#EntityX)

[<span style="font-variant: small-caps">EntityY</span>](#EntityY)

[<span style="font-variant: small-caps">EntityZ</span>](#EntityZ)

[<span style="font-variant: small-caps">EntityPitch</span>](#EntityPitch)

[<span style="font-variant: small-caps">EntityRoll</span>](#EntityRoll)

[<span style="font-variant: small-caps">EntityYaw</span>](#EntityYaw)

[<span style="font-variant: small-caps">EntityScaleX</span>](#EntityScaleX)

[<span style="font-variant: small-caps">EntityScaleY</span>](#EntityScaleY)

[<span style="font-variant: small-caps">EntityScaleZ</span>](#EntityScaleZ)

[<span style="font-variant: small-caps">FindChild</span>](#FindChild)

[<span style="font-variant: small-caps">GetChild</span>](#GetChild)

[<span style="font-variant: small-caps">DeltaPitch</span>](#DeltaPitch)

[<span style="font-variant: small-caps">DeltaYaw</span>](#DeltaYaw)

[<span style="font-variant: small-caps">EntityClass</span>](#EntityClass)

[<span style="font-variant: small-caps">EntityName</span>](#EntityName)

[<span style="font-variant: small-caps">EntityMatrix</span>](#EntityMatrix)

[<span style="font-variant: small-caps">EntityPick</span>](#EntityPick)

[<span style="font-variant: small-caps">LinePick</span>](#LinePick)

Entity Collision

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">EntityRadius</span></span></span>](#EntityRadius)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ResetEntity</span></span></span>](#ResetEntity)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">Collisions</span></span></span>](#Collisions)

[<span style="font-variant: small-caps">CountCollisions</span>](#CountCollisions)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CollisionEntity</span></span></span>](#CollisionEntity)

[<span style="font-variant: small-caps">CollisionNX</span>](#CollisionNX)

[<span style="font-variant: small-caps">CollisionNY</span>](#CollisionNY)

[<span style="font-variant: small-caps">CollisionNZ</span>](#CollisionNZ)

[<span style="font-variant: small-caps">CollisionX</span>](#CollisionX)

[<span style="font-variant: small-caps">CollisionY</span>](#CollisionY)

[<span style="font-variant: small-caps">CollisionZ</span>](#CollisionZ)

[<span style="font-variant: small-caps">CollisionSurface</span>](#CollisionSurface)

[<span style="font-variant: small-caps">CollisionTriangle</span>](#CollisionTriangle)

[<span style="font-variant: small-caps">CollisionTime</span>](#CollisionTime)

[<span style="font-variant: small-caps">EntityCollided</span>](#EntityCollided)

[<span style="font-variant: small-caps">EntityBox</span>](#EntityBox)

[<span style="font-variant: small-caps">EntityType</span>](#EntityType)

[<span style="font-variant: small-caps">EntityPickMode</span>](#EntityPickMode)

[<span style="font-variant: small-caps">GetEntityType</span>](#GetEntityType)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ClearCollisions</span></span></span>](#ClearCollisions)

Actions

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ActExecute</span></span></span>](#ActExecute)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ActFadeTo</span></span></span>](#ActFadeTo)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">A</span></span></span><span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ctIterator</span></span></span>](#ActIterator)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">ActMoveBy</span></span></span>](#ActMoveBy)

[<span style="font-variant: small-caps">ActNewtonian</span>](#ActNewtonian)

[<span style="font-variant: small-caps">ActScaleTo</span>](#ActScaleTo)

[<span style="font-variant: small-caps">A</span><span style="font-variant: small-caps">ctStop</span>](#ActStop)

[<span style="font-variant: small-caps">ActTintTo</span>](#ActTintTo)

[<span style="font-variant: small-caps">ActTrackByDistance</span>](#ActTrackByDistance)

[<span style="font-variant: small-caps">ActTrackByPoint</span>](#ActTrackByPoint)

[<span style="font-variant: small-caps">ActTurnBy</span>](#ActTurnBy)

[<span style="font-variant: small-caps">ActTurnTo</span>](#ActTurnTo)

[<span style="font-variant: small-caps">ActVector</span>](#ActVector)

[<span style="font-variant: small-caps">A</span><span style="font-variant: small-caps">ctWait</span>](#ActWait)

[<span style="font-variant: small-caps">TriggerCloseTo</span>](#TriggerCloseTo)

[<span style="font-variant: small-caps">TriggerCollision</span>](#TriggerCollision)

[<span style="font-variant: small-caps">TriggerDistance</span>](#TriggerDistance)

[<span style="font-variant: small-caps">AppendAction</span>](#AppendAction)

[<span style="font-variant: small-caps">FreeAction</span>](#FreeAction)

Physics

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateConstraint</span></span></span>](#CreateConstraint)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateRigidBody</span></span></span>](#CreateRigidBody)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">FreeConstraint</span></span></span>](#FreeConstraint)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">FreeRigidBody</span></span></span>](#FreeRigidBody)

Stencil

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreateStencil</span></span></span>](#CreateStencil)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">UseStencil</span></span></span>](#UseStencil)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">StencilAlpha</span></span></span>](#StencilAlpha)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">StencilClsColor</span></span></span>](#StencilClsColor)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">StencilClsMode</span></span></span>](#StencilClsMode)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">StencilMesh</span></span></span>](#StencilMesh)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">StencilMode</span></span></span>](#StencilMode)

Post Processing

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">CreatePostFX</span></span></span>](#CreatePostFX)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">AddRenderTarget</span></span></span>](#AddRenderTarget)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">F</span></span></span><span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">reePostFX</span></span></span>](#FreePostFX)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PostFXBuffer</span></span></span>](#PostFXBuffer)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PostFXFunction</span></span></span>](#PostFXFunction)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PostFXShader</span></span></span>](#PostFXShader)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PostFXShaderPass</span></span></span>](#PostFXShaderPass)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">PostFXTexture</span></span></span>](#PostFXTexture)

3D Maths

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">VectorPitch</span></span></span>](#VectorPitch)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">VectorYaw</span></span></span>](#VectorYaw)

[<span style="font-variant: small-caps"><span lang="en-US"><span style="font-weight: normal">GetMatElement</span></span></span>](#GetMatElement)

</div>

<a name="ActExecute"></a>**Action* ActExecute(void (*func)(void))**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">call the function</span> <span lang="en-US">_func_</span> <span lang="en-US">at the next</span> [UpdateWorld](#UpdateWorld), and complete immediately after<span lang="en-US">.</span>

If the action is appended to another one with [AppendAction](#AppendAction), the function will be executed only after the previous action is completed, and this makes event-based programming possible

<a name="ActFadeTo"></a>**Action* ActFadeTo(Entity* entity, float a, float rate)**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">set the alpha level of</span> <span lang="en-US">the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to</span> <span lang="en-US">_a_</span><span lang="en-US">_._</span> <span lang="en-US">T</span><span lang="en-US">he</span> <span lang="en-US">fading</span> <span lang="en-US">will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster</span> <span lang="en-US">change</span><span lang="en-US">), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActIterator"></a>**Action* ActIterator()**

Creates a special action that does nothing, but repeats one or more actions in an infinite loop at each [UpdateWorld](#UpdateWorld). All the actions that need to be repeated can be added to the iterator action using [AppendAction](#AppendAction): they must **not** be appended to each other, but have to be appended to the iterator action. If more than one action is appended to an iterator, they will be executed in sequence.

<a name="ActMoveBy"></a>**Action* ActMoveBy(Entity* entity, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected</span> <span lang="en-US">_entity_</span><span lang="en-US">. It is the equivalent of “MoveEntity entity, x, y, z”, but the movement will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster movement), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActMoveTo"></a>**Action* ActMoveTo(Entity* entity, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to the absolute coordinates</span> <span lang="en-US"></span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">,</span> <span lang="en-US">_z._</span> <span lang="en-US">T</span><span lang="en-US">he movement will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster movement), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span> <span lang="en-US">If the entity is moved before it reaches its destination by other command, it will keep that in account and correct its trajectory.</span>

More actions can be performed on the same entity at the same time.

<a name="ActNewtonian"></a>**<span lang="en-US">Action* ActNewtonian(Entity* ent</span><span lang="en-US">ity</span><span lang="en-US">, float</span> <span lang="en-US">percentage</span><span lang="en-US">)</span>**

<span lang="en-US">Creates an action that will move the selected</span> <span lang="en-US">_entity_</span><span lang="en-US"> <span style="font-style: normal"></span> </span><span lang="en-US"><span style="font-style: normal">in the same direction it moved the last time, simulating momentum.</span> </span><span lang="en-US"><span style="font-style: normal">At each frame, the movement will be a</span> </span><span lang="en-US">_percentage_</span><span lang="en-US"> <span style="font-style: normal">of the last one. Note that this action won’t handle rotations or collisions. Collisions can be handled separately, and rotations can be achieved by applying this action to several pivots constrained together with</span> </span>[CreateConstraint](#CreateConstraint)<span lang="en-US"><span style="font-style: normal">, and then applying an entity controlled by them with</span> </span>[CreateRigidBody](#CreateRigidBody)<span lang="en-US"><span style="font-style: normal">. That would allow to create a lightweight physics engine without needing external libraries.</span></span>

This action is never completed, and will continue until it’s stopped with [FreeAction](#FreeAction).

More actions can be performed on the same entity at the same time.

<a name="ActScaleTo"></a>**Action* ActScaleTo(Entity* entity, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">scale</span> <span lang="en-US">the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to</span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">,</span> <span lang="en-US">_z._</span> <span lang="en-US">T</span><span lang="en-US">he</span> <span lang="en-US">scaling</span> <span lang="en-US">will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster</span> <span lang="en-US">scaling</span><span lang="en-US">), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActStop"></a>**Action* ActStop(Action* act2)**

Creates an action that will stop the given action, and all actions appended to it, at the next [UpdateWorld](#UpdateWorld). It is useful in particular to stop actions like [ActTrackByDistance](#ActTrackByDistance), or [ActTrackByPoint](#ActTrackByPoint), that never complete on their own.

**Warning**: this action does not check if _act2_ <span style="font-style: normal">has already been terminated by another occurrence of ActStop, or if it has already completed on its own: in case, the behavior is undefined and will likely lead to a crash of the program, so there should be no more than one occurrence of StopAction targeting the same action. Instead, it’s perfectly safe to use it to stop an action that has not started yet.</span>

<a name="ActTintTo"></a>**Action* ActTintTo(Entity* entity, float r, float g, float b, float rate)**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">set the</span> <span lang="en-US">color</span> <span lang="en-US">of</span> <span lang="en-US">the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to</span> <span lang="en-US">_r_</span><span lang="en-US"><span style="font-style: normal">,</span></span><span lang="en-US"> _g_</span><span lang="en-US"><span style="font-style: normal">,</span></span><span lang="en-US"> _b_</span><span lang="en-US">_._</span> <span lang="en-US">T</span><span lang="en-US">he</span> <span lang="en-US">change in color</span> <span lang="en-US"></span> <span lang="en-US">will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster</span> <span lang="en-US">change</span><span lang="en-US">), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActTrackByDistance"></a>**Action* ActTrackByDistance(Entity* entity, Entity* target, float distance, float rate)**

<span lang="en-US">Creates an action that will move the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to</span><span lang="en-US">ward</span> <span lang="en-US"></span> <span lang="en-US">_target_</span> <span lang="en-US"></span> <span lang="en-US">until it is at the given</span> <span lang="en-US">_distance_</span><span lang="en-US">.</span> <span lang="en-US"></span><span lang="en-US">T</span><span lang="en-US">he movement will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster movement), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span> <span lang="en-US">The entity will</span> <span lang="en-US">always point at the</span> <span lang="en-US">target entity.</span> <span lang="en-US">If the entity is moved before it reaches its destination by other command, it will keep that in account and correct its trajectory.</span> <span lang="en-US">This action is never completed, and will continue until it’s stopped with</span> [FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActTrackByPoint"></a>**Action* ActTrackByPoint(Entity* entity, Entity* target, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">to the coordinates</span> <span lang="en-US"></span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">,</span> <span lang="en-US">_z_ </span><span lang="en-US">related to</span> <span lang="en-US">_target_</span><span lang="en-US">.</span> <span lang="en-US">T</span><span lang="en-US">he movement will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster movement), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span> <span lang="en-US">The entity will also attempt to turn at the same direction that the target entity is oriented.</span> <span lang="en-US">If the entity is moved before it reaches its destination by other command, it will keep that in account and correct its trajectory.</span> <span lang="en-US">This action is never completed, and will continue until it’s stopped with</span> [FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActTurnBy"></a>**Action* ActTurnBy(Entity* entity, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will turn the selected</span> <span lang="en-US">_entity_</span><span lang="en-US">. It is the equivalent of “TurnEntity entity, x, y, z”, but the movement will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster movement), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActTurnTo"></a>**Action* ActTurnTo(Entity* entity, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">turn</span> <span lang="en-US">the selected</span> <span lang="en-US">_entity_ </span><span lang="en-US">toward the absolute coordinates</span> <span lang="en-US"></span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">,</span> <span lang="en-US">_z._</span> <span lang="en-US">T</span><span lang="en-US">he</span> <span lang="en-US">rotation</span> <span lang="en-US">will happen gradually, at a given</span> <span lang="en-US">_rate_</span> <span lang="en-US">(a higher rate means a faster</span> <span lang="en-US">rotation</span><span lang="en-US">), at the next</span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span> <span lang="en-US">If the entity is moved before it points at its destination by other command, it will keep that in account and correct its rotation.</span>

More actions can be performed on the same entity at the same time.

<a name="ActVector"></a>**Action* ActVector(Entity* entity, float x, float y, float z)**

<span lang="en-US">Creates an action that will</span> <span lang="en-US">move</span> <span lang="en-US">the selected</span> <span lang="en-US">_entity_</span> <span lang="en-US"></span> <span lang="en-US">by</span> <span lang="en-US"></span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">,</span> <span lang="en-US">_z_</span> <span lang="en-US"></span> <span lang="en-US">at each</span> <span lang="en-US"></span> [UpdateWorld](#UpdateWorld)<span lang="en-US">.</span> <span lang="en-US">The movement is always in the world coordinates, and is independent from the entity rotation or parent. This action is useful to simulate wind or gravity. This action is never completed, and will continue until it’s stopped with</span> [FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

<a name="ActWait"></a><span style="font-variant: small-caps">**Action* Act**</span><span style="font-variant: small-caps">**Wait**</span><span style="font-variant: small-caps">**(float** </span><span style="font-variant: small-caps">**time**</span><span style="font-variant: small-caps">**)**</span>

Creates an action that does nothing, and completes after a given number of [UpdateWorld](#UpdateWorld) cycles. If other actions are added to it with [AppendAction](#AppendAction), they will be executed after the delay.

<a name="AddAnimSeq"></a>**int AddAnimSeq(Entity* ent,int length)**

Creates an animation sequence for an entity. This must be done before any animation keys set by [SetAnimKey](#SetAnimKey) can be used in an actual animation however this is optional. You may use it to "bake" the frames you have added previously using SetAnimKey.  

Returns the animation sequence number added.

<a name="AddMesh"></a>**void AddMesh(Mesh* mesh1,Mesh* mesh2)**

Add _source_mesh_ to _dest_mesh_. All mesh data are copied to the destination mesh, so you can also delete the source mesh, after this command.

The size and rotation of the entity won't apply to the mesh: so, if you have used commands like [RotateEntity](#RotateEntity), or [ScaleEntity](#ScaleEntity), they won't affect the copied mesh; use [RotateMesh](#RotateMesh) and [ScaleMesh](#ScaleMesh), instead.

<a name="AddRenderTarget"></a>**void AddRenderTarget(PostFX* fx, int pass_no, int numColBufs, bool depth, int format=8, float scale=1.0)**

<span lang="en-US">Defines the output buffer generated by a pass,</span> <span lang="en-US">in a post processing effect</span> <span lang="en-US">_fx_</span><span lang="en-US">: it allows to create one or more color buffers (those buffer contain the rendered image), with different bit depth, and specifies if a separate depth buffer is needed or not. The parameter</span> <span lang="en-US">_pass_no_</span> <span lang="en-US">defines which stage will create the buffers (stage 0 is the scene rendering, stage 1 is the first shader, and so on).</span> <span lang="en-US">The parameter</span> <span lang="en-US">_numColBufs_</span> <span lang="en-US">sets how many color buffers must be created (this is useful when using a shader than outputs different information on different buffers: for example, in deferred shading one buffer can contain the normal data, another the actual colors). The parameter</span> <span lang="en-US">_depth_</span><span lang="en-US">, if true, specifies that the depth buffer must be included, as well. The parameter</span> <span lang="en-US">_format_</span> <span lang="en-US">specifies the bit depth (8, 16 or 32)</span> <span lang="en-US">that must be used for the buffer (higher means more video memory usage, and more precise color rendering: usually the improved quality cannot be seen on the monitor, but it can be useful in HDR renderings). The parameter</span> <span lang="en-US">_scale_</span> <span lang="en-US">allows to scale the rendering (a blurring shader, for example, won’t need a full scale buffer)</span>

<a name="AddTriangle"></a>**int AddTriangle(Surface* surf,int v0,int v1,int v2)**

Creates a new triangle, and adds it to _surface_; also, it returns the triangle index number (first triangle is 0).

Parameters _v0_, _v1_ and _v2_ are handles to the three vertices of the triangle: to create vertices, the command [AddVertex](#AddVertex) can be used (it will also return the handle of the created vertex). Of course, a vertex can also be used in more than one triangle (so, if two triangles are adiacent, they can share one or two vertices).

Every triangle is visible only from one side (backface culling): to render an image faster, there is generally no need to draw the polygons on the sides of the buildings facing away from the camera; they are completely occluded by the sides facing the camera; the order of vertices will determine wich side will be visible; the command [FlipMesh](#FlipMesh) will swap sides. To make a triangle visible at both sides, the simplest solution is to create a copy of the mesh, and flip it (it will require a double number of triangles, one for each side).

<a name="AddVertex"></a>**int AddVertex(Surface* surf,float x, float y,float z,float u, float v,float w)**

Add a vertex to _surface_; vertex coordinates are defined by _x!_, _y!_ and _z!_ (floating-point parameters); if the surface has a texture, texture mapping coordinates can be specified with the optional parameters _u!_, _v!_ and _w!_.

The function will return an handle to the created vertex; this handle can be used with the [AddTriangle](#AddTriangle) command.

<a name="AmbientLight"></a>**void AmbientLight(float r,float g,float b)**

Sets the ambient light, that will affect every object on the scene, from all sides.

It's possible to set a value for every color component: for example,

<pre class="western" style="margin-bottom: 0.5cm">AmbientLight 255,0,0</pre>

Makes the light red; instead,

<pre class="western" style="margin-bottom: 0.5cm">AmbientLight 0,0,0</pre>

will turn off the ambient light: so, unless there are other lights, the scene will be black, and no object will be visible.

The ambient light is, by default, at 127,127,127; so, it will make possible to see on the scene, even if there aren't other lights; anyway, since the light comes from every side, there will be no shading, and objects will look "flat".

<a name="AmbientShader"></a>**void AmbientShader(Shader* material)**

Sets a default shader to be used for all the entities that don’t have their own shader attached.

<a name="AntiAlias"></a>**void AntiAlias(int samples)**

_samples_ - true to enable fullscreen antialiasing, false to disable. Defaults to false

If your OpenGL context supports multisample, this command allows to enable it to make jagged lines and other artifacts less noticeable, at expenses of a slower rendering speed

<a name="Animate"></a><span style="font-variant: small-caps">**void Animate(Entity* ent,int mode,float speed,int seq,int trans)**</span>

Animate an entity, if the entity has animation sequences.

_mode_ is the mode of animation.

*   0: stop animation

*   1: loop animation (default)

*   2: ping-pong animation

*   3: one-shot animation

*   4: manual animation (only for skeletal based animation)

_speed_: an higher value means a faster animation. A negative value means a backward animation. Default is 1

_sequence_: set which animation sequence will be played. The same entity can have many sequences (walk, idle, jump, swim, climb...). Default is 0\.

_transition_: used to tween between an entities current position rotation and the first frame of animation. Default is 0

<a name="Animating"></a>**int Animating(Entity* ent)**

Returns **true** if the specified entity is currently animating.

<a name="AnimLength"></a>**int AnimLength(Entity* ent)**

Returns the length of the specified entity's current animation sequence.

<a name="AnimSeq"></a>**int AnimSeq(Entity* ent)**

Returns the specified entity's current animation sequence

<a name="AnimTime"></a>**float AnimTime(Entity* ent)**

Returns the current animation time of an entity.

<a name="AppendAction"></a>**void AppendAction(Action* first, Action* second)**

Appends an action to another: the _second_ action will be performed only when the _first_ action has completed. Several actions can be appended in chain: if you append action B to action A, and action C to action B, they will be performed in sequence A → B → C.

More than one action can be appended to the same action: if you append both action B and action C to action A, once A has completed both B and C will start at the same time (the only exception happens when action A is an [ActIterator](#ActIterator): in this case action B will be performed, then action C, then B again, then C again and so on).

Appended actions don’t necessarily have to apply to the same entity of the action that triggered them, they can apply to different entities as well.

<a name="BackBufferToTex"></a>**void BackBufferToTex(Texture* tex,int frame)**

It converts the current screen back buffer (usually, the rendered image) to a texture. The texture must be created with [CreateTexture](#CreateTexture). If its size is smaller than the screen size, only a portion of the screen will be copied. The argument _tex_ <span style="font-style: normal">is the texture handle.</span> Argument _frame_ <span style="font-style: normal">is currently unused.</span>

<a name="BrushAlpha"></a>**void BrushAlpha(Brush* brush, float a)**

Set the alpha level (the transparency) of a brush: _alphalevel!_ is a floating point value, and it must be in the range from 0 (completely transparent, invisible) to 1 (normal, no transparency at all).

<a name="BrushBlend"></a>**void BrushBlend(Brush* brush,int blend)**

Set the blending mode of a brush: _blend_ value can be:

*   1: alpha (default)

*   2: multiply

*   3: add

<a name="BrushColor"></a>**void BrushColor(Brush* brush,float r,float g,float b)**

Set the color of a brush: _red!_, _green!_ and _blue!_ are floating point values, ranging from 0 to 255, that set colour levels.

<a name="BrushFX"></a>**void BrushFX(Brush* brush,int fx)**

_brush_ - brush handle

_fx_ -

*   0: nothing (default)

*   1: full-bright

*   2: use vertex colors instead of brush color

*   4: flatshaded

*   8: disable fog

*   16: disable backface culling

Sets miscellaneous effects for a brush.

Flags can be added to combine two or more effects. For example, specifying a flag of 3 (1+2) will result in a full-bright and vertex-coloured brush.

<a name="BrushShininess"></a>**void BrushShininess(Brush* brush,float s)**

Set the shininess of a brush: it means, how brighter a surface will look when a light hits it. The value _shininess_ must be in a range from 0 to 1\.

<a name="BrushTexture"></a>**void BrushTexture(Brush* brush,Texture* tex,int frame,int index)**

_brush_ - brush handle  
_texture_ - texture handle  
_frame_ (optional) - texture frame. Defaults to 0.  
_index_ (optional) - texture index. Defaults to 0.

Assigns a texture to a brush.

The optional frame parameter specifies which animation frame, if any exist, should be assigned to the brush.

The optional index parameter specifies texture layer that the texture should be assigned to. Brushes have up to four texture layers, 0-3 inclusive.

<a name="BufferToTex"></a>**void BufferToTex(Texture* tex,unsigned char* buffer, int frame)**

It converts an image buffer to a texture. The texture must be created with [CreateTexture](#CreateTexture). The image buffer must be in format RGBA (each pixel is represented by 4 bytes: red, green, blue and alpha values), and it must have the same width and height of the texture. The argument _tex_ <span style="font-style: normal">is the texture handle, the argument</span> _buffer_ <span style="font-style: normal">is a pointer to the image buffer.</span> Argument _frame_ <span style="font-style: normal">is currently unused.</span>

<a name="CameraClsColor"></a>**void CameraClsColor(Camera* cam, float r,float g,float b)**

Set the color that the camera will use for background; usually, it is black (0,0,0).

<a name="CameraClsMode"></a>**void CameraClsMode(Camera* cam,int cls_depth,int cls_zbuffer)**

Every time an image is rendered, just before rendering the new image, the old image is usually deleted (color buffer and z-buffer are erased). Setting flags to 0 will keep the old data (it could be useful to achieve some strange effects, or to combine two or more renderings in one)

<a name="CameraFogColor"></a>**void CameraFogColor(Camera* cam,float r,float g,float b)**

Set the color that the camera will use for fog: it affects all the object that are "fading away" in the distance, but not the background itself; usually, it is black (0,0,0).

<a name="CameraFogMode"></a>**void CameraFogMode(Camera* cam,int mode)**

_camera_ - sets camera fog mode  
_mode_ - fog mode  
0: no fog  
1: linear fog

Sets the camera fog mode.

This will enable/disable fogging, a technique used to gradually fade out graphics the further they are away from the camera. The can be used to avoid 'pop-up', the moment at which 3D objects suddenly appear on the horizon.

The default fog color is black and the default fog range is 1-1000, although these can be changed by using [CameraFogColor](#CameraFogColor) and [CameraFogRange](#CameraFogRange) respectively.

Each camera can have its own fog mode, for multiple on-screen fog effects.

<a name="CameraFogRange"></a>**void CameraFogRange(Camera* cam,float near,float far)**

Set the fog range of the camera; since the range of the camera is not infinite, object that are outside of the range will disappear (otherwise, the system will have too many polygons to render); the fog allows to slowly fade an object away, giving it the same color of the background, to avoid a sudden disappearing.

The _near!_ parameter is a floating point variable that specify the minimum range of the fog effect; any object closer to the camera won't be affected by fog.

The _far!_ parameter is a floating point variable that specify the maximum range of the fog; any object that is outside this range will have the maximum fog effect, and will have the same color of the background (thus being invisible).

See also [CameraFogColor](#CameraFogColor), [CameraRange](#CameraRange).

<a name="CameraPick"></a>**Entity* CameraPick(Camera* cam,float x,float y)**

Return the entity that is at the coordinates _x_ and _y_ of the viewport (be careful: coordinates 0,0 point to the bottom left angle of the viewport). If no entity is at the given coordinates, it returns 0\.

Not all entities can be picked with this method: to make an entity "pickable", the command [EntityPickMode](#EntityPickMode) is used.

Pitfall: if a mouse is used, mouse coordinates 0,0 refer to the top left angle of a window: so, to get the correct _y_ coordinate, you need to use _screen_height_ - _y_ (_screen_height_, of course, is the height of the viewport in pixels)

<a name="CameraProject"></a>**void CameraProject(Camera* cam,float x,float y,float z)**

Projects the world coordinates x,y,z on to the 2D screen.

<a name="CameraProjMatrix"></a>**float* CameraProjMatrix(Camera* camera)**

Returns a pointer to the projection matrix of a given camera

<a name="CameraProjMode"></a>**void CameraProjMode(Camera* cam,int mode)**

_mode_ - projection mode:

*   0: no projection - disables camera (faster than HideEntity)

*   1: perspective projection (default)

*   2: orthographic projection

Description:

Sets the camera projection mode.

The projection mode is the the technique used by OpenB3D to display 3D graphics on the screen. Using projection mode 0, nothing is displayed on the screen, and this is the fastest method of hiding a camera. Using camera projection mode 1, the graphics are displayed in their 'correct' form - and this is the default mode for a camera. Camera projection mode 2 is a special type of projection, used for displaying 3D graphics on screen, but in a 2D form - that is, no sense of perspective will be given to the graphics. Two identical objects at varying distances from the camera will both appear to be the same size. Orthographic projection is useful for 3D editors, where a sense of perspective is unimportant, and also certain games.

Use '[CameraZoom](#CameraZoom)' to control the scale of graphics rendered with orthographic projection. As a general rule, using orthographic projection with the default camera zoom setting of 1 will result in graphics that are too 'zoomed-in' - changing the camera zoom to 0.1 should fix this.

One thing to note with using camera project mode 2, is that terrains will not be displayed correctly - this is because the level of detail algorithm used by terrains relies on perspective in order to work properly. Same limits apply to geospheres and isosurfaces

<a name="CameraRange"></a><span style="font-variant: small-caps">**void CameraRange(Camera* cam,float near,float far)**</span>

Sets camera range; any object with a distance from the camera lower than _near_ or higher than _far_ won't be drawn; this will make rendering faster.

<a name="CameraToTex"></a>**void CameraToTex(Texture* tex, Camera* cam, int frame)**

Renders the output of a camera on a texture. Shadows are rendered as well, other informations related to stencils, or to postprocessing are ignored. The camera viewport is ignored, as well. The texture must be created with [CreateTexture](#CreateTexture). The argument _tex_ <span style="font-style: normal">is the texture handle, the argument</span> _cam_ <span style="font-style: normal">is the camera handle.</span> Argument _frame_ <span style="font-style: normal">is currently unused.</span>

<a name="CameraViewport"></a>**void CameraViewport(Camera* cam,int x,int y,int width,int height)**

Set the camera viewport (the area of the screen where a camera image is rendered); by default, all the screen (or window) is used.

This command allows to use only part of the screen, and so the rest of the screen can be used to show panels, or also other camera image (i.e. to achieve split-screen effect). Also, a smaller viewport can be used to make a rear-view effect.

<a name="CameraZoom"></a><span style="font-variant: small-caps">**void CameraZoom(Camera* cam,float zoom)**</span>

<span lang="en-US">Set the zoom factor of a camera: default is 1\. A value lower than 1 will provide a</span> <span lang="en-US">wide</span><span lang="en-US">-</span><span lang="en-US">angle</span> <span lang="en-US">effect, a value greater than 1 will give a teleobjective effect.</span>

<a name="ClearCollisions"></a>**void ClearCollisions()**

Clears the collision information list.

Whenever you use the [Collisions](#Collisions) command to enable collisions between two different entity types, information is added to the collision list. This command clears that list, so that no collisions will be detected until the Collisions command is used again.

The command will not clear entity collision information. For example, entity radius, type etc.

<a name="ClearSurface"></a>**void ClearSurface(Surface* surf,bool clear_verts,bool clear_tris)**

_surface_ - surface handle  
_clear_verts_ (optional) - true to remove all vertices from the specified surface, false not to. Defaults to true.  
_clear_triangles_ (optional) - true to remove all triangles from the specified surface, false not to. Defaults to true.

Description:

Removes all vertices and/or triangles from a surface.

This is useful for deleting sections of mesh. The results will be instantly visible.

<a name="ClearTextureFilters"></a>**void ClearTextureFilters()**

Clears the current texture filter list.

<a name="ClearWorld"></a>**void ClearWorld(bool entities,bool brushes,bool textures)**

Clears a world of all entities, brushes and/or textures.

This is useful for when a game level may have finished and you wish to free everything up in preparation for loading new entities/brushes/textures without having to free every entity/brush/texture individually.

<a name="CollisionEntity"></a>**Entity* CollisionEntity(Entity* ent,int index)**

Returns the other entity involved in a particular collision. Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ), inclusive.

<a name="Collisions"></a>**void Collisions(int src_no,int dest_no,int method_no,int response_no)**

Enable collision detecting; every time an [UpdateWorld](#UpdateWorld) command is performed, the library will automatically check if two or more entities are colliding, and will react to that (so, you don't need to check at every cycle if there are some colliding entity, the library will do that for you)

Not all entities will be checked: only collision between entity of type _src_type_ with entities of type _dest_type_ will be detected (since some entities might not need to be checked for collisions, or might need to react in a different way)

You can set the type of an entity with [EntityType](#EntityType) (the type is a simple number: all entities of the same type will behave in the same way): a negative type would mean that the entity has to be checked for dynamic collisions (slower, but it works even when the target is moving)

_method_ is the collision detection method:

1: ellipsoid-to-ellipsoid collisions (fastest, but not much accurate: you need to set ellipsoid radius with _[EntityRadius](#EntityRadius)_)

2: ellipsoid-to-polygon collisions (the most precise, but slower)

3: ellipsoid-to-box collisions (need to set box size with _[EntityBox](#EntityBox)_)

_response_ is what the source entity does when a collision occurs:

1: entity will stop

2: slide1 - full sliding collision

3: slide2 - prevent entities from sliding down slopes

<a name="CollisionNX"></a>**float CollisionNX(Entity* ent,int index)**

Returns the x component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionNY"></a>**float CollisionNY(Entity* ent,int index)**

Returns the y component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionNZ"></a>**float CollisionNZ(Entity* ent,int index)**

Returns the z component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionSurface"></a>**Surface* CollisionSurface(Entity* ent,int index)**

Returns the handle of the surface belonging to the specified entity that was closest to the point of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionTime"></a>**float CollisionTime(Entity* ent,int index)**

Returns the time taken to calculate a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionTriangle"></a>**int CollisionTriangle(Entity* ent,int index)**

Returns the index number of the triangle belonging to the specified entity that was closest to the point of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionX"></a>**float CollisionX(Entity* ent,int index)**

Returns the world x coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionY"></a>**float CollisionY(Entity* ent,int index)**

Returns the world y coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CollisionZ"></a>**float CollisionZ(Entity* ent,int index)**

Returns the world z coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)( entity ) inclusive.

<a name="CopyMesh"></a>**Mesh* CopyMesh(Mesh* mesh,Entity* parent)**

Creates a copy of a mesh and returns the newly-created mesh's handle.

The difference between CopyMesh and [CopyEntity](#CopyEntity) is that children entities are not copied (and that includes bones, or attached entities). So, CopyMesh is not recommended for animated meshes.

CopyMesh is identical to performing new_mesh=CreateMesh() : AddMesh mesh,new_mesh

<a name="CountChildren"></a>**int CountChildren(Entity* ent)**

Returns the number of children of an entity.

<a name="CountCollisions"></a>**int CountCollisions(Entity* ent)**

Returns how many collisions an entity was involved in during the last UpdateWorld.

<a name="CopyEntity"></a>**Entity* CopyEntity(Entity* ent,Entity* parent)**

Creates a copy of an entity and returns the handle of the newly created copy. Any entity (a mesh, a light, a pivot, a terrain...) can be copied. Children entities are copied as well.

If a parent entity is specified, the copied entity will be created at the parent entity's position. Otherwise, it will be created at 0,0,0\.

<a name="CountBones"></a>**int CountBones(Mesh* mesh)**

Returns the number of bones that are used in _mesh_

<a name="CountSurfaces"></a>**int CountSurfaces(Mesh* mesh)**

Returns the number of surfaces that are used in _mesh_ (a mesh can have more than one surface)

<a name="CountTriangles"></a>**int CountTriangles(Surface* surf)**

Returns the number of triangles in a surface.

<a name="CountVertices"></a>**int CountVertices(Surface* surf)**

<span lang="en-US">Returns the number of</span> <span lang="en-US">vertices</span> <span lang="en-US">in a surface.</span>

<a name="CreateBlob"></a><span style="font-variant: small-caps">**Blob* CreateBlob(Fluid* fluid, float radius, Entity* parent_ent)**</span>

<span lang="en-US">Creates a “blob”, also called a “metaball”, from a given fluid. A blob will react only with other blobs of the same isosurface, and it is basically</span> <span lang="en-US">similar to a sphere made of goo, that can stick to other ones and merge with them. The size is determined by the</span> <span lang="en-US">_radius_</span><span lang="en-US">; if the radius is negative, the blob won’t be visible, but if it is moved close to other ones it can repel them, or appear like a hole.</span>

Blobs are useful to show fluids, atoms and molecules, or organic-like structures. They cannot have a color or a texture, and they will use the parameters of their fluid entity

<a name="CreateBone"></a>**Bone* CreateBone(Mesh* mesh, Entity* parent_ent)**

<span lang="en-US">Creates a Bone entity, that will be used for the animation of</span> <span lang="en-US">_mesh._ </span><span lang="en-US"><span style="font-style: normal">Bones can later be set to affect the mesh vertices with the command</span> </span>[SkinMesh](#SkinMesh)<span lang="en-US"><span style="font-style: normal">.</span></span>

<a name="CreateBrush"></a>**Brush* CreateBrush(float r,float g,float b)**

Creates a brush and returns a brush handle.

The optional green, red and blue values allow you to set the colour of the brush. Values should be in the range 0-255\. If omitted the values default to 255.  

A brush is a collection of properties such as Colour, Alpha, Shininess, Texture etc that are all stored as part of the brush. Then, all these properties can be applied to an entity, mesh or surface at once just by using [PaintEntity](#PaintEntity), [PaintMesh](#PaintMesh) or [PaintSurface](#PaintSurface).

When creating your own mesh, if you wish for certain surfaces to look differently from one another, then you will need to use brushes to paint individual surfaces. Using commands such as EntityColor, EntityAlpha will apply the effect to all surfaces at once, which may not be what you wish to achieve.

<a name="CreateCamera"></a>**Camera* CreateCamera(Entity* parent)**

Creates a camera entity and returns its handle.

Without at least one camera, you won't be able to see anything in your 3D world. With more than one camera, you will be to achieve effect such as split-screen modes and rear-view mirrors.

A camera by default renders to the backbuffer. If you wish to display 3D graphics on a texture you can use [CameraToTex](#CameraToTex).

The optional _parent_ parameter allow you to specify a parent entity for the camera so that when the parent is moved the child camera will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateConstraint"></a>**Constraint* CreateConstraint(Entity* p1, Entity* p2, float length)**

<span lang="en-US">It creates a bound between the entities p1 and p2, forcing them to maintain a distance of</span> <span lang="en-US">_length_</span> <span lang="en-US">between them. Both entities can still be moved, but the movements of one will influence the movement of the other. An entity can have more than one constraint, with different entities. Constraints can be very useful in physics simulation</span>

<a name="CreateCone"></a>**Mesh* CreateCone(int segments,bool solid,Entity* parent)**

_segments_ (optional) - cone detail. Defaults to 8.  
_parent_ (optional) - parent entity of cone  
_solid_ (optional) - true for a cone with a base, false for a cone without a base. Defaults to true.

**Description**

Creates a cone mesh/entity and returns its handle.

The cone will be centred at 0,0,0 and the base of the cone will have a radius of 1.

The _segments_ value must be in the range 3-100 inclusive.

Example segments values (solid=true):  
4: 6 polygons - a pyramid  
8: 14 polygons - bare minimum amount of polygons for a cone  
16: 30 polygons - smooth cone at medium-high distances  
32: 62 polygons - smooth cone at close distances

<font size="3" style="font-size: 12pt">The optional _parent_ parameter allow you to specify a parent entity for the cone so that when the parent is moved the child cone will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</font>

<a name="CreateCube"></a>**Mesh* CreateCube(Entity* parent)**

Creates a cube mesh/entity and returns its handle.

The cube will extend from -1,-1,-1 to +1,+1,+1.

The optional _parent_ parameter allow you to specify a parent entity for the cube so that when the parent is moved the child cube will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateCylinder"></a>**Mesh* CreateCylinder(int segments,bool solid,Entity* parent)**

<span lang="en-US">segments (optional) -</span> <span lang="en-US">cylinder</span> <span lang="en-US">detail. Defaults to 8.  
parent (optional) - parent entity of cone  
solid (optional) - true for a c</span><span lang="en-US">ylinder</span> <span lang="en-US">with a base, false for a</span> <span lang="en-US">tube</span><span lang="en-US">. Defaults to true.</span>

Description

Creates a cylinder mesh/entity and returns its handle.

The cylinder will be centred at 0,0,0 and will have a radius of 1.

The _segments_ value must be in the range 3-100 inclusive.

Example segments values (solid=true):  
<font size="3" style="font-size: 12pt">3: 8 polygons - a prism  
8: 28 polygons - bare minimum amount of polygons for a cylinder  
16: 60 polygons - smooth cylinder at medium-high distances  
32: 124 polygons - smooth cylinder at close distances</font>

<font size="3" style="font-size: 12pt">The optional</font> <font size="3" style="font-size: 12pt">_parent_</font> <font size="3" style="font-size: 12pt">parameter allow you to specify a parent entity for the</font> <font size="3" style="font-size: 12pt">cylinder</font> <font size="3" style="font-size: 12pt">so that when the parent is moved the child cone will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</font>

<a name="CreateFluid"></a>**Fluid* CreateFluid()**

Creates a fluid entity, or, more specifically, an isosurface. Isosurfaces are 3d objects that are not defined by a list of triangles, but by a 3d field, that can be based on a given array, or on a mathematical function: the isosurface represents points of constant value inside that field.

An application for isosurfaces is the rendering of metaballs, or blobs, with the command [CreateBlob](#CreateBlob).

To create textured blobs, the texture, brush, or shader has to be applied to the fluid entity, and not to the blob entity.

<a name="CreateGeosphere"></a>**Terrain* CreateGeosphere(int size, Entity* parent)**

<span lang="en-US">Creates a</span> <span lang="en-US">geosphere</span> <span lang="en-US"></span> <span lang="en-US">(planet)</span> <span lang="en-US">entity and returns its handle.</span>

A geosphere is a special type of polygon object that uses real-time level of detail (LOD) to display a spherical landscape which should theoretically consist of over millions polygons with only a few thousand. The way it does this is by constantly rearranging a certain amount of polygons to display high levels of detail close to the viewer and low levels further away.

This constant rearrangement of polygons is noticeable however, and is an well-known side-effect of all LOD landscapes. This 'pop-in' effect can be reduced though in lots of ways, as the other terrain help files will go on to explain.

The optional _parent_ parameter allow you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateMesh"></a>**Mesh* CreateMesh(Entity* parent)**

Create a 'blank' mesh entity and returns its handle.  

When a mesh is first created it has no surfaces, vertices or triangles associated with it.  

To add geometry to this mesh, you will need to:  

CreateSurface() ; To make a surface  
AddVertex ; You will need to add at least 3 to make a Triangle  
AddTriangle ; This will add a triangle by connecting the Vertices (points) you added to the mesh.

<a name="CreateLight"></a>**Light* CreateLight(int light_type,Entity* parent)**

Creates a light.

Lights work by affecting the colour of all vertices within the light's range. You need at to create at least one light if you wish to use 3D graphics otherwise everything will appear flat.  

The optional type parameter allows you to specify the type of light you wish to create. A value of 1 creates a directional light. This works similar to a sun shining on a house. All walls facing a certain direction are lit the same. How much they are lit by depends on the angle of the light reaching them.  

A value of 2 creates a point light. This works a little bit like a light bulb in a house, starting from a central point and gradually fading outwards.  

A value of 3 creates a spot light. This is a cone of light. This works similar to shining a torch in a house. It starts with an inner angle of light, and then extends towards an outer angle of light.

For a light of type 1, only direction is used to calculate the light, while the light position is ignored. For a light of type 2, only position is used to calculate the light, direction is ignored. A light of type 3 is calculated using both direction and position.

A high number of light affects rendering speed. Usually 8 lights can be supported, no more.

A light can cast shadows, although they have to be created with CreateShadow.

The optional _parent_ parameter allow you to specify a parent entity for the light so that when the parent is moved the child light will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateOcTree"></a>**OcTree* CreateOcTree(float width, float height, float depth, Entity* parent_ent=0)**

<span lang="en-US">Creates an octree of given</span> <span lang="en-US">_width_</span><span lang="en-US">,</span> <span lang="en-US">_height_</span> <span lang="en-US">and</span> <span lang="en-US">_depth_</span><span lang="en-US">.</span> <span lang="en-US">An octree</span> <span lang="en-US">allows to manage several static entities, allowing to create complex structures made of blocks (in a way similar to what tilemaps do in 2d graphics),</span> <span lang="en-US">and also allowing LOD (by showing smaller blocks only when they are close enough). An octree can be imagined as a cube subdivided in eight smaller cubes, each one subdivided again. So, the first level will be a 2x2x2=8 blocks structure, at the second level it will be a 4x4x4=64 blocks structure, and so on.</span>

<span lang="en-US">The optional</span> <span lang="en-US">_parent_</span> <span lang="en-US">parameter allow you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</span>

<a name="CreateParticleEmitter"></a>**ParticleEmitter* CreateParticleEmitter(Entity* particle, Entity* parent_ent=0)**

Creates an emitter entity. An emitter is an entity that periodically produces new entities of a given kind (usually particle sprites), and launches them: those entities have a limited lifespan, then they are automatically removed. They are produced by duplicating a given _particle_ entity: the recommended entity to be used for that is a sprite with [SpriteRenderMode](#SpriteRenderMode) set to 3, but any kind of entity can be used, including blobs (for water simulation) or even other emitters (for firework effects, for example)

<span lang="en-US">The optional</span> <span lang="en-US">_parent_</span> <span lang="en-US">parameter allow you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</span>

<a name="CreatePivot"></a>**Pivot* CreatePivot(Entity* parent)**

Creates a pivot entity.  

A pivot entity is an invisible point in 3D space that's main use is to act as a parent entity to other entities. The pivot can then be used to control lots of entities at once, or act as new centre of rotation for other entities.  

To enforce this relationship; use EntityParent or make use of the optional parent entity parameter available with all entity load/creation commands.  

Indeed, this parameter is also available with the CreatePivot command if you wish for the pivot to have a parent entity itself.

<a name="CreatePlane"></a>**Mesh* CreatePlane(int divisions,Entity* parent)**

<span lang="en-US">Creates a plane entity and returns its handle.  

A plane entity is basically a flat, infinite 'ground'. It is useful for outdoor games where you never want the player to see/reach the edge of the game world.  

The optional</span> <span lang="en-US">_div_</span><span lang="en-US">_ision_</span><span lang="en-US">_s_</span> <span lang="en-US">parameter</span> <span lang="en-US">is currently unused.</span><span lang="en-US">The</span> <span lang="en-US"><span style="font-style: normal">optional</span></span> <span lang="en-US"></span> <span lang="en-US">_parent_</span> <span lang="en-US">parameter allows you to specify a parent entity for the plane so that when the parent is moved the child plane will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</span>  

<a name="CreatePostFX"></a>**PostFX* CreatePostFX(Camera* camera, int passes=1)**

<span lang="en-US">Creates a post-processing effect. Post-processing effects are a special kind of shaders that are applied on the entire visible area, after the scene has been rendered, and not on the single entity. They can be applied even on scene that feature entities using custom shaders (they can also cooperate with entity shaders in some special cases, like deferred</span> <span lang="en-US">shading). They can be used, for example, to render a scene in black and white, or to simulate a night vision device, or a fisheye lens, and so on.</span>

<span lang="en-US">A post-processing effect works by rendering the scene on a texture, then applying that texture to a rectangular surface as big as the visible area, and rendering it using a custom shader. This operation can be performed more than once, to use different shader programs (for example, in one step colors are changed, in the next step the image is blurred, and so on). The parameter</span> <span lang="en-US">_passes_</span> <span lang="en-US">specifies how many steps are needed.</span>

<a name="CreateQuad"></a>**Mesh* CreateQuad(Entity* parent)**

<span lang="en-US">Creates a</span> <span lang="en-US">quad</span> <span lang="en-US">entity and returns its handle.  

A</span> <span lang="en-US">quad</span> <span lang="en-US">entity is basically a flat</span> <span lang="en-US">square, useful for tiles.</span><span lang="en-US">The optional</span> <span lang="en-US">_parent_</span> <span lang="en-US">parameter allows you to specify a parent entity for the plane so that when the parent is moved the child plane will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</span>  

<a name="CreateRigidBody"></a>**RigidBody* CreateRigidBody(Entity* body, Entity* p1, Entity* p2, Entity* p3, Entity* p4)**

<span lang="en-US">A RigidBody is a particular kind of entity: it is not affected anymore by commands like TurnEntity, MoveEntity, PositionEntity, RotateEntity, or ScaleEntity;</span> <span lang="en-US">its behavior is determined by the four entities</span> <span lang="en-US">_p1_</span><span lang="en-US">,</span> <span lang="en-US">_p2_</span><span lang="en-US">,</span> <span lang="en-US">_p3_ </span><span lang="en-US">and</span> <span lang="en-US">_p4_ </span><span lang="en-US">(usually those entities are pivots).</span> <span lang="en-US">Its position is determined by p1’s position, and its orientation is determined by the other entities that will point where</span> <span lang="en-US">the forward, the top, and the right are; if the entities are not correctly aligned, the</span> <span lang="en-US">_body_</span> <span lang="en-US">entity might be deformed. For that reason, the entities used as</span> <span lang="en-US"></span><span lang="en-US">_p1_</span><span lang="en-US">,</span> <span lang="en-US">_p2_</span><span lang="en-US">,</span> <span lang="en-US">_p3_ </span><span lang="en-US">and</span> <span lang="en-US">_p4_ </span><span lang="en-US"><span style="font-style: normal">should be connected using constraints made with</span> </span>[CreateConstraint](#CreateConstraint)<span lang="en-US"><span style="font-style: normal">, to ensure they will always move together.</span></span>

Combined with constraints, CreateRigidBody allows to build a simple physics engine

<a name="CreateShader"></a>**Shader* CreateShader(char* ShaderName, char* VshaderString, char* FshaderString)**

Creates a shader. A shader is a special program that is not run on the CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It requires a name, and two strings containing the source codes of the two shaders, called Vertex Shader and Fragment Shader

<a name="CreateShaderVGF"></a>**Shader* CreateShaderVGF(char* ShaderName, char* VshaderString, char* GshaderString, char* FshaderString)**

Creates a shader. A shader is a special program that is not run on the CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It requires a name, and three strings containing the source codes of the two shaders, called Vertex Shader, Geometry Shader and Fragment Shader

<a name="CreateShadow"></a>**ShadowObject* CreateShadow(Mesh* parent, char Static)**

<span lang="en-US">Cause the</span> <span lang="en-US">_parent_</span> <span lang="en-US">mesh to cast a shadow. The shadow is automatically calculated from the light position, and if there is more than one light active, more shadows are produced. The</span> <span lang="en-US">_Static_</span><span lang="en-US"> <span style="font-style: normal">parameter, if true, is used to specify that the shadow must not be updated after its creation; normally, a shadow is updated each frame according to light and mesh position, and to mesh animation. Static shadows are not updated, so they should be used only for static meshes, and only if the light is not moved as well. Rendering of a static shadow is of course much faster.</span></span>

<span lang="en-US"><span style="font-style: normal">T</span></span><span lang="en-US"><span style="font-style: normal">o render shadows, stencil buffer must be enabled. Shadows could interfere with other stencil operations. The algorithm used (Z Fail) has some side-effects, like the fact that shadows are rendered through objects, as well (that issue can be fixed by ensuring that any object that receives a shadow is a shadow caster as well). The choice of stencil shadows allows entities that are supposed to receive a shadow to use custom shaders with no interferences.</span></span>

<a name="CreateSphere"></a>**Mesh* CreateSphere(int segments,Entity* parent)**

Creates a sphere mesh/entity and returns its handle.

The sphere will be centred at 0,0,0 and will have a radius of 1.

The _segments_ value must be in the range 2-100 inclusive.

Example segments values:  
8: 224 polygons - bare minimum amount of polygons for a sphere  
16: 960 polygons - smooth looking sphere at medium-high distances  
32: 3968 polygons - smooth sphere at close distances

<font size="3" style="font-size: 12pt">The optional _parent_ parameter allow you to specify a parent entity for the sphere so that when the parent is moved the child sphere will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</font>

<a name="CreateSprite"></a>**Sprite* CreateSprite(Entity* parent)**

Creates a sprite entity and returns its handle.

The sprite will be positioned at 0,0,0 and extend from 1,-1 to +1,+1.

A sprite entity is a flat, square (which can be made rectangular by scaling it) 3D object.

Sprites have two real strengths. The first is that they consist of only two polygons; meaning you can use many of them at once. This makes them ideal for particle effects and 2D-using-3D games where you want lots of sprites on-screen at once.

Secondly, sprites can be assigned a view mode using [SpriteViewMode](#SpriteViewMode). By default this view mode is set to 1, which means the sprite will always face the camera. So no matter what the orientation of the camera is relative to the sprite, you will never actually notice that they are flat; by giving them a spherical texture, you can make them appear to look no different than a normal sphere.

The optional _parent_ parameter allow you to specify a parent entity for the sprite so that when the parent is moved the child sprite will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateStencil"></a>**Stencil* CreateStencil()**

<span lang="en-US">Creates a stencil: stencils are used to limit the next rendering to only a portion of the visible area: that portion can be shaped through one or more meshes built for that purpose. Stencils can be useful to simulate shadows, or light spots (by rendering part of a scene with different light conditions),</span> <span lang="en-US">or also to simulate a “portal” leading to a different place (by rendering a different scene, viewed by a different camera, inside the stencil)</span>

<a name="CreateSurface"></a>**Surface* CreateSurface(Mesh* mesh,Brush* brush)**

Creates a surface attached to a mesh and returns the surface's handle.

Surfaces are sections of mesh which are then used to attach triangles to. You must have at least one surface per mesh in order to create a visible mesh, however you can use as many as you like. Splitting a mesh up into lots of sections allows you to affect those sections individually, which can be a lot more useful than if all the surfaces are combined into just one.

<a name="CreateTerrain"></a>**Terrain* CreateTerrain(int size, Entity* parent)**

Creates a terrain entity and returns its handle.

The terrain extends from 0,0,0 to _grid_size_,1,_grid_size_.

A terrain is a special type of polygon object that uses real-time level of detail (LOD) to display landscapes which should theoretically consist of over a million polygons with only a few thousand. The way it does this is by constantly rearranging a certain amount of polygons to display high levels of detail close to the viewer and low levels further away.

This constant rearrangement of polygons is noticeable however, and is an well-known side-effect of all LOD landscapes. This 'pop-in' effect can be reduced though in lots of ways, as the other terrain help files will go on to explain.

The optional _parent_ parameter allow you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="CreateTexture"></a><span style="font-variant: small-caps">**Texture* CreateTexture(int width,int height,int flags,int frames)**</span>

_Width_ and _height_ are the size of the texture. Note that the actual texture size may be different from the width and height requested, as different types of 3D hardware support different sizes of texture.

The optional _flags_ parameter allows you to apply certain effects to the texture. Flags can be added to combine two or more effects, e.g. 3 (1+2) = texture with color and alpha maps.

Here some more detailed descriptions of the flags:

**1**: **Color** - colour map, what you see is what you get.

**2**: **Alpha** - alpha map. If an image contains an alpha map, this will be used to make certain areas of the texture transparent. Otherwise, the colour map will be used as an alpha map. With alpha maps, the dark areas always equal high-transparency, light areas equal low-transparency.

**4**: **Masked** - all areas of a texture coloured 0,0,0 will not be drawn to the screen.

**8**: **Mipmapped** - low detail versions of the texture will be used at high distance. Results in a smooth, blurred look.

**16**: **Clamp u** - Any part of a texture that lies outsides the U coordinates of 0-1 will not be drawn. Prevents texture-wrapping.

**32**: **Clamp v** - Any part of a texture that lies outsides the v coordinates of 0-1 will not be drawn. Prevents texture-wrapping.

**64**: **Spherical environment map** - a form of environment mapping. This works by taking a single image, and then applying it to a 3D mesh in such a way that the image appears to be reflected. When used with a texture that contains light sources, it can give some meshes such as a teapot a shiny appearance.

**128**: **Cubic environment map** - a form of environment mapping. Cube mapping is similar to spherical mapping, except it uses six images each representing a particular 'face' of an imaginary cube, to give the appearance of an image that perfectly reflects its surroundings.

When creating cubic environment maps with the CreateTexture command, cubemap textures _must_ be square 'power of 2' sizes. See the SetCubeFace command for information on how to then draw to the cubemap.

When loading cubic environments maps into OpenB3D using [LoadAnimTexture](#LoadAnimTexture), all six images relating to the six faces of the cube must be contained within the one texture, and be laid out in a horizontal strip in the following order - left, forward, right, backward, up, down. The images comprising the cubemap must all be power of two sizes.

Please note that not some older graphics cards do not support cubic mapping.

Once you have created a texture, use [BufferToTex](#BufferToTex) to copy an image to it. To display 3D graphics on a texture, one option is to copy from the backbuffer to the texturebuffer, another is to directly render the image from a camera to the texture.

<a name="CreateVoxelSprite"></a>**VoxelSprite* CreateVoxelSprite(int slices, Entity* parent)**

Creates a voxel sprite and returns its handle.

A voxel sprite works more or less like a regular sprites, but it uses a 3d texture instead of a 2d one, and it is not square, but cubic. It can be seen as a pile of different quads, each one with a different texture, that represent a slice of the complete object. The slice parameter sets the number of quads used.

<span lang="en-US">As result, the voxel sprite</span> <span lang="en-US"></span> <span lang="en-US">can be turned, showing different sides, as a true 3d object.</span>

The optional _parent_ parameter allow you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="DeltaPitch"></a>**<span lang="en-US">float DeltaPitch(Entity* src_entity,Entity*</span> <span lang="en-US">dest</span><span lang="en-US">_entity)</span>**

Returns the pitch angle, that _src_entity_ should be rotated by in order to face _dest_entity_.  

This command can be used to be point one entity at another, rotating on the x axis only.

<a name="DeltaYaw"></a>**float DeltaYaw(Entity* src_entity,Entity* dest_entity)**

<span lang="en-US">Returns the</span> <span lang="en-US">yaw</span> <span lang="en-US">angle, that</span> <span lang="en-US">_src_entity_</span> <span lang="en-US">should be rotated by in order to face</span> <span lang="en-US">_dest_entity_</span><span lang="en-US">.  

This command can be used to be point one entity at another, rotating on the</span> <span lang="en-US">y</span> <span lang="en-US">axis only.</span>

<a name="DepthBufferToTex"></a>**void DepthBufferToTex( Texture* tex, Camera* camera=0 )**

It converts the depth buffer to a texture. If a _camera_ is specified, it will use the depth buffer of the picture rendered from that camera, otherwise, if no camera is specified, it will use the current depth buffer. The texture must be created with [CreateTexture](#CreateTexture). The argument _tex_ <span style="font-style: normal">is the texture handle.</span>

Rendering a depth buffer to a texture (that will look like a gray scale image) can be useful for some shaders that need that information, since shaders by default cannot read the depth buffer directly.

<a name="EmitterVector"></a>**void EmitterVector(ParticleEmitter* emitter, float x, float y, float z)**

<span lang="en-US">Provides an acceleration to the particles coming from</span> <span lang="en-US">_emitter_</span><span lang="en-US">, to simulate the effects of gravity, or of wind. The three components</span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span> <span lang="en-US">and</span> <span lang="en-US">_z_</span> <span lang="en-US">of such acceleration are added to the absolute speed of each particle at each frame, for all the particle life.</span>

<a name="EmitterRate"></a>**void EmitterRate(ParticleEmitter* emitter, float r)**

Sets the frequency of emission of new particle for _emitter_<span style="font-style: normal">. The parameter</span> _r_ <span style="font-style: normal">is the emission rate: a value of 1 means a new particle is emitted at each update, a lower value means a lower rate. A value of 0 disables the emitter.</span>

<a name="EmitterParticleLife"></a>**void EmitterParticleLife(ParticleEmitter* emitter, int l)**

Sets the lifetime of particles emitted by _emitter_<span style="font-style: normal">. The parameter</span> _l_ <span style="font-style: normal">is the number of frames after a particle is removed.</span>

<a name="EmitterParticleFunction"></a>**void EmitterParticleFunction(ParticleEmitter* emitter, void (*EmitterFunction)(Entity*, int))**

<span lang="en-US">S</span><span lang="en-US">ets a</span> <span lang="en-US">custom</span> <span lang="en-US">function that will manage every particle produced by</span> <span lang="en-US">_emitter_</span><span lang="en-US">. must be declared using C calling convention, and must accept an entity and an integer number as pa</span><span lang="en-US">rameters.</span>

The entity is the particle, and the numeric parameter is its current lifetime: the custom function can be used to control the fading, the orientation, the scaling factor, and almost every other parameter, based on the particle lifetime (it must not use static variables, since it is called for each particle).

<a name="EmitterParticleSpeed"></a>**void EmitterParticleSpeed(ParticleEmitter* emitter, float speed)**

Sets the _speed_ of a particle, when it is produced by _emitter_<span style="font-style: normal">. The particle will move in the same direction of the emitter, at the given speed, that will remain constant for all its lifetime unless it’s affected by EmitterVector</span>

<a name="EmitterVariance"></a>**void EmitterVariance(ParticleEmitter* emitter, float variance)**

Set the _variance_ in speed and direction of particles coming from _emitter_. A variance of zero means that all particles will go exactly in the same direction at the same speed. Any value greater than zero will introduce a random change, different for each particle, in their speed and direction, to cause them to spread more. The variation will be random, but never greater than _variance_.

<a name="EntityAlpha"></a>**void EntityAlpha(Entity* ent,float alpha)**

Sets the entity alpha level of an entity.  

The _alpha_ value should be in a floating point value in the range 0-1\. The default entity alpha setting is 1.  

The alpha level is how transparent an entity is. A value of 1 will mean the entity is opaque. A value of 0 will mean the entity is completely transparent, i.e. invisible. Values between 0 and 1 will cause varying amount of transparency. This is useful for imitating the look of objects such as glass and other translucent materials.  

An EntityAlpha value of 0 is especially useful as OpenB3D will not render entities with such a value, but will still involve the entities in collision tests. This is unlike HideEntity, which doesn't involve entities in collisions.

<a name="EntityAutoFade"></a>**void EntityAutoFade(Entity* ent,float near,float far)**

Currently not implemented

<a name="EntityBlend"></a>**void EntityBlend(Entity* ent, int blend)**

_Blend_ - Blend mode of the entity.  
1: Alpha (default)  
2: Multiply  
3: Add

**Description**

Sets the blending mode of an entity. This blending mode determines the way in which the new RGBA of the pixel being rendered is combined with the RGB of the background.  

To calculate the new RGBA of the pixel being rendered, the texture RGBA for the pixel (see [TextureBlend](#TextureBlend) for more information on how the texture RGBA is calculated) is taken, its alpha component multiplied by the entities/brushes (where applicable) alpha value and its color compentent multiplied by the entities/brushes colour. This is the RGBA which will then be blended into the background pixel, and how this is done depends on the EntityBlend value.  

Alpha:  
This blends the pixels according to the Alpha value. This is rougly done to the formula:  

Rr = ( An * Rn ) + ( ( 1.0 - An ) * Ro )  
Gr = ( An * Gn ) + ( ( 1.0 - An ) * Go )  
Br = ( An * Bn ) + ( ( 1.0 - An ) * Bo )  

Where R = Red, G = Green, B = Blue, n = new pixel colour values, r = resultant colour values, o = old pixel colour values.  

Alpha blending is the default blending mode and is used with most world objects.  

Multiply:  
This blend mode will darken the underlying pixels. If you think of each RGB value as being on a scale from 0% to 100%, where 0 = 0% and 255 = 100%, the multiply blend mode will multiply the red, green and blue values individually together in order to get the new RGB value, roughly according to:  

Rr = ( ( Rn / 255.0 ) * ( Ro / 255.0 ) ) * 255.0  
Gr = ( ( Gn / 255.0 ) * ( Go / 255.0 ) ) * 255.0  
Br = ( ( Bn / 255.0 ) * ( Bo / 255.0 ) ) * 255.0  

The alpha value has no effect with multiplicative blending. Blending a RGB value of 255, 255, 255 will make no difference, while an RGB value of 128, 128, 128 will darken the pixels by a factor of 2 and an RGB value of 0, 0, 0 will completely blacken out the resultant pixels. An RGB value of 0, 255, 255 will remove the red component of the underlying pixel while leaving the other color values  
untouched.  

Multiply blending is most often used for lightmaps, shadows or anything else that needs to 'darken' the resultant pixels.  

Add:  
Additive blending will add the new color values to the old, roughly according to:  

Rr = ( Rn * An ) + Ro  
Gr = ( Gn * An ) + Go  
Br = ( Bn * An ) + Bo  

The resultant RGB values are clipped out at 255, meaning that multiple additive effects can quickly cause visible banding from smooth gradients.  

Additive blending is extremely useful for effects such as laser shots and fire.

<a name="EntityBox"></a>**void EntityBox(Entity* ent,float x,float y,float z,float width,float height,float depth)**

entity - entity handle#

_x_ - x position of entity's collision box

_y_ - y position of entity's collision box

_z_ - z position of entity's collision box

_width_ - width of entity's collision box

_height_ - height of entity's collision box

_depth_ - depth of entity's collision box

**Description**

Sets the dimensions of an entity's collision box.

<a name="EntityClass"></a>**const char* EntityClass(Entity* ent)**

Returns the class name of an entity (“Bone”, “Mesh”, “Light”...)

<a name="EntityCollided"></a>**Entity* EntityCollided(Entity* ent,int type)**

Returns the handle of the entity of the specified _type_ that collided with the specified _entity_.

<a name="EntityColor"></a>**void EntityColor(Entity* ent,float red,float green,float blue)**

Set the color of an entity. The _red_, _green_ and _blue_ value of the color have to be in the range 0-255; 0,0,0 is black; 255,255,255 is white (default).

<a name="EntityDistance"></a>**<span lang="en-US">float EntityDistance(Entity* src_entity,Entity*</span> <span lang="en-US">dest</span><span lang="en-US">_entity)</span>**

Returns the distance between _src_entity_ and _dest_entity_.

<a name="EntityFX"></a>**void EntityFX(Entity* entity,int fx)**

_ent__ity_ - entity handle

_fx_ -

0: nothing (default)

1: full-bright

2: use vertex colors instead of brush color

4: flatshaded

8: disable fog

16: disable backface culling

32: force alpha-blending

**Description**

Sets miscellaneous effects for an entity.

Flags can be added to combine two or more effects. For example, specifying a flag of 3 (1+2) will result in a full-bright and vertex-coloured brush.

Flag 32, to force alpha-blending, must be used in order to enable vertex alpha (see [VertexColor](#VertexColor)).

<a name="EntityInView"></a>**int EntityInView(Entity* ent,Camera* cam)**

Returns true if the specified entity is visible to the specified _camera_.  

If the entity is a mesh, its bounding box will be checked for visibility.  

For all other types of entities, only their centre position will be checked.

<a name="EntityMatrix"></a>**float* EntityMatrix(Entity* entity)**

Returns a pointer to the model matrix of a given entity (if the entity is a camera, by inverting that matrix it’s possible to get the view matrix of that camera)

<a name="EntityName"></a>**const char* EntityName(Entity* ent)**

Returns the name of an entity. An entity's name may be set in a modelling program, or manually set using [NameEntity](#NameEntity).

<a name="EntityOrder"></a>**void EntityOrder(Entity* ent,int order)**

Sets the drawing order for an entity.

An order value of 0 will mean the entity is drawn normally. A value greater than 0 will mean that entity is drawn first, behind everything else. A value less than 0 will mean the entity is drawn last, in front of everything else.

Setting an entity's order to non-0 also disables z-buffering for the entity, so should be only used for simple, convex entities like skyboxes, sprites etc.

EntityOrder affects the specified entity but none of its child entities, if any exist.

<a name="EntityParent"></a>**void EntityParent(Entity* ent,Entity* parent_ent,bool global)**

<span lang="en-US">_ent_</span> <span lang="en-US">- entity handle</span>

_parent_ - parent entity handle

_global_ (optional) - true for the child entity to retain its global position and orientation. Defaults to true.

**Description**

Attaches an entity to a parent.

Parent may be 0, in which case the entity will have no parent.

<a name="EntityPick"></a>**Entity* EntityPick(Entity* ent,float range)**

Returns the nearest entity 'ahead' of the specified entity, within given _range_. An entity must have a non-zero [EntityPickMode](#EntityPickMode) to be pickable.

<a name="EntityPickMode"></a>**void EntityPickMode(Entity* ent,int pick_mode,bool obscurer)**

Make an entity pickable (with [EntityPick](#EntityPick), [CameraPick](#CameraPick) or [LinePick](#LinePick));

__pick_mode__ is the picking detection method:

1: ellipsoid picking (fastest, but not much accurate: you need to set ellipsoid radius with _EntityRadius_)

2: polygon picking (the most precise, but slower)

3: box picking (need to set box size with _EntityBox_)

_obscurer_ is an optional parameter: it is used with [EntityVisible](#EntityVisible) to determine just what can get in the way of the line-of-sight between 2 entities. This allows some entities to be pickable using the other pick commands, but to be ignored (i.e. 'transparent') when using [EntityVisible](#EntityVisible)

<a name="EntityPitch"></a><span style="font-variant: small-caps">**float EntityPitch(Entity* ent,bool glob**</span><span style="font-variant: small-caps">**al**</span><span style="font-variant: small-caps">**)**</span>

<span lang="en-US">Returns the pitch angle of an entity.</span> The parameter _global,_ if true, means the pitch angle returned should be relative to 0 rather than a parent entity's pitch angle. It is false by default.

The pitch angle is also the x angle of an entity.

<a name="EntityRadius"></a>**void EntityRadius(Entity* ent,float radius_x,float radius_y)**

Sets the radius of an entity's collision ellipsoid.  

An entity radius should be set for all entities involved in ellipsoidal collisions, which is all source entities (as collisions are always ellipsoid-to-something), and whatever destination entities are involved in ellipsoid-to-ellipsoid collisions (collision method No.1).

<span lang="en-US">_radius_y_</span> <span lang="en-US"></span> <span lang="en-US">is optional, if omitted the value of</span> <span lang="en-US">_radius_x_</span> <span lang="en-US">will be used</span>

<a name="EntityRoll"></a>**float EntityRoll(Entity* ent,bool global)**

<span lang="en-US">Returns the</span> <span lang="en-US">roll</span> <span lang="en-US">angle of an entity.</span> The parameter _global,_ if true, means the roll angle returned should be relative to 0 rather than a parent entity's roll angle. It is false by default.

The roll angle is also the z angle of an entity.

<a name="EntityScaleX"></a>**float EntityScaleX(Entity* ent,bool glob)**

Gets the x scale factor of an entity

<a name="EntityScaleY"></a>**float EntityScaleY(Entity* ent,bool glob)**

Gets the y scale factor of an entity

<a name="EntityScaleZ"></a>**float EntityScaleZ(Entity* ent,bool glob)**

Gets the z scale factor of an entity

<a name="EntityShininess"></a>**void EntityShininess(Entity* ent,float shininess)**

Sets the specular shininess of an entity.  

The _shininess_ value should be a floating point number in the range 0-1\. The default shininess setting is 0.  

Shininess is how much brighter certain areas of an object will appear to be when a light is shone directly at them.  

Setting a shininess value of 1 for a medium to high poly sphere, combined with the creation of a light shining in the direction of it, will give it the appearance of a shiny snooker ball.

<a name="EntityTexture"></a>**void EntityTexture(Entity* ent,Texture* tex,int frame,int index)**

_entity_ - entity handle

_texture_ - texture handle

_frame_ (optional) - frame of texture. Defaults to 0.

_index_ (optional) - index number of texture. Should be in the range to 0-7\. Defaults to 0.

**Description**

Applies a texture to an entity.

The optional frame parameter specifies which texture animation frame should be used as the texture.

The optional index parameter specifies which index number should be assigned to the texture. Index numbers are used for the purpose of multitexturing. See [TextureBlend](#TextureBlend).

A little note about multitexturing and slowdown. Graphics cards support a maximum amount of textures per object, which can be used with very little, if any, slowdown.

<a name="EntityType"></a>**void EntityType(Entity* entity,int collision_type,int flags)**

_entity_ - entity handle

_collision_type_ - collision type of entity. Must be in the range 0-99 for standard collision checking.

_flags_ (optional):

0: nothing (default)

1: recursive, to apply collision type to entity's children.

2: dynamic. Specifies that the collision must be evaluated dynamically

**Description**

Sets the collision type for an entity.

A collision_type value of 0 indicates that no collision checking will occur with that entity. A collision value of 1-99 will mean collision checking will occur.

Flags can be added to combine two or more effects. For example, specifying a flag of 3 (1+2) will

result in recursive, dynamic collisions.

Dynamic collisions are slower to evaluate, but work even when the destination entity is moving.

<a name="EntityVisible"></a>**int EntityVisible(Entity* src_ent,Entity* dest_ent)**

Returns true if src_entity and dest_entity can 'see' each other.

<a name="EntityX"></a>**float EntityX(Entity* ent,bool global)**

<span lang="en-US">The X-coordinate of the entity.  
If the</span> <span lang="en-US">_global_</span> <span lang="en-US">flag is set to False then the parent's local coordinate system is used.  

NOTE: If the entity has no parent then local and global coordinates are the same.  
In this case you can think of the 3d world as the parent.  

Global coordinates refer to the 3d world.</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">uses a left-handed system:  

X+ is to the right  
Y+ is up  
Z+ is forward ( into the screen )  

Every entity also has its own Local coordinate system.  

The global system never changes.  
But the local system is carried along as an entity moves and turns.  

This same concept is used in the entity movement commands:  

MoveEntity entity, 0,0,1  

No matter what the orientation this moves one unit forward.</span>

<a name="EntityY"></a>**float EntityY(Entity* ent,bool global)**

The Y-coordinate of the entity.  
If the _global_ flag is set to False then the parent's local coordinate system is used.  

See [EntityX](#EntityX)() for an overview of Local and Global coordinates.

<a name="EntityYaw"></a>**float EntityYaw(Entity* ent,bool glob)**

Returns the roll angle of an entity. The parameter _global,_ if true, means the roll angle returned should be relative to 0 rather than a parent entity's roll angle. It is false by default.

The roll angle is also the y angle of an entity.

<a name="EntityZ"></a>**float EntityZ(Entity* ent,bool global)**

<span lang="en-US">The</span> <span lang="en-US">Z</span><span lang="en-US">-coordinate of the entity.  
If the</span> <span lang="en-US">_global_</span> <span lang="en-US">flag is set to False then the parent's local coordinate system is used.  

See</span> [EntityX](#EntityX)<span lang="en-US">() for an overview of Local and Global coordinates.</span>

<a name="ExtractAnimSeq"></a>**int ExtractAnimSeq(Entity* ent,int first_frame,int last_frame,int seq)**

<span lang="en-US">On an animated mesh, it selects only a part of the animation, that is included between</span> <span lang="en-US">_first_frame_</span><span lang="en-US"> <span style="font-style: normal">and</span> </span><span lang="en-US">_last frame_</span><span lang="en-US"><span style="font-style: normal">, and returns the corresponding number, that can be used with the</span> </span>[Animate](#Animate)<span lang="en-US"> <span style="font-style: normal">command. The parameter</span> </span><span lang="en-US">_seq_</span><span lang="en-US"> <span style="font-style: normal">specifies the sequence to extract from (if it’s 0, the sequence is extracted by the whole animation)</span></span>

<span lang="en-US"><span style="font-style: normal">T</span></span><span lang="en-US"><span style="font-style: normal">his command is useful because animated meshes often pack several different actions in a single sequence (jumping, walking, running, and so on); this command allows to separate them into different sequences.</span></span>

<a name="FindChild"></a>**Entity* FindChild(Entity* ent,char* child_name)**

Returns the first child of the specified entity with name matching _child_name_.

<a name="FindSurface"></a>**Surface* FindSurface(Mesh* mesh,Brush* brush)**

Currently unsupported

<a name="FitMesh"></a>**void FitMesh(Mesh* mesh,float x,float y,float z,float width,float height,float depth,bool uniform)**

_mesh_ - mesh handle

_x_ - x position of mesh

_y_ - y position of mesh

_z_ - z position of mesh

_width_ - width of mesh

_height_ - height of mesh

_depth_ - depth of mesh

_uniform_ (optional) - if true, the mesh will be scaled by the same amounts in x, y and z, so will not be distorted. Defaults to false.

**Description**

Scales and translates all vertices of a mesh so that the mesh occupies the specified box.

Do not use a _width_, _height_ or _depth_ value of 0, otherwise all mesh data will be destroyed and your mesh will not be displayed. Use a value of 0.001 instead for a flat mesh along one axis.

<a name="FlipMesh"></a>**void FlipMesh(Mesh* mesh)**

_mesh_ - mesh handle

Flips all the triangles in a mesh.

This is useful for a couple of reasons. Firstly though, it is important to understand a little bit of the theory behind 3D graphics. A 3D triangle is represented by three points; only when these points are presented to the viewer in a clockwise-fashion is the triangle visible. So really, triangles only have one side.

Normally, for example in the case of a sphere, a model's triangles face the inside of the model, so it doesn't matter that you can't see them. However, what about if you wanted to use the sphere as a huge sky for your world, i.e. so you only needed to see the inside? In this case you would just use FlipMesh.

Another use for FlipMesh is to make objects two-sided, so you can see them from the inside and outside if you can't already. In this case, you can copy the original mesh using CopyEntity, specifying the original mesh as the parent, and flip it using FlipMesh. You will now have two meshes occupying the same space - this will make it double-sided, but beware, it will also double the polygon count!

The above technique is worth trying when an external modelling program has exported a model in such a way that some of the triangles appear to be missing.

<a name="FluidArray"></a>**void FluidArray(Fluid* fluid, float* Array, int width, int height, int depth)**

<span lang="en-US">This is an advanced function, to</span> <span lang="en-US">make an isosurface based on a custom data set. It accepts a pointer to 3d array, of given</span> <span lang="en-US">_width_</span><span lang="en-US">,</span> <span lang="en-US">_height_</span> <span lang="en-US">and</span> <span lang="en-US">_depth_</span><span lang="en-US">.</span> <span lang="en-US">The data set must be of single precision floating-point numbers, and it will be represented as a box of voxels, that will be visible for values that are greater than a given threshold (by default 0.5). Interpolation is used to provide a smoother look.</span>

<a name="FluidFunction"></a>**void FluidFunction(Fluid* fluid, float (*FieldFunction)(float, float, float))**

<span lang="en-US">This is an advanced function, to</span> <span lang="en-US">make an isosurface based on a custom</span> <span lang="en-US">function</span><span lang="en-US">. It accepts a pointer to</span> <span lang="en-US">a callback function, that will accept the single precision floating-point parameters</span> <span lang="en-US">_x_</span><span lang="en-US">,</span> <span lang="en-US">_y_</span><span lang="en-US">, and</span> <span lang="en-US">_z_</span><span lang="en-US">.</span> <span lang="en-US">The function must return a single precision floating-point value, that will be calculated according</span> <span lang="en-US">to the given coordinates. The resulting 3d objects</span> <span lang="en-US">will be visible for values that are greater than a given threshold (by default 0.5).</span>

<a name="FluidThreshold"></a>**void FluidThreshold(Fluid* fluid, float threshold)**

Allows to change the threshold of a fluid object (isosurface). It will affect the behavior of blobs, and of custom data sets or custom functions.

<a name="FreeAction"></a>**void FreeAction(Action* act, int global)**

Terminates an action immediately. When _global_ is set to _false_, if the action has any appended actions, they will start. If the action has not yet been executed (because it was appended to another action), it will be skipped and any action scheduled after it will be activated in its place.

When _global_ is set to _true_, any appended action is also terminated.

<a name="FreeBrush"></a>**void FreeBrush(Brush* brush)**

Frees up a brush

<a name="FreeConstraint"></a>**void FreeConstraint(Constraint* con)**

Frees up a constraint

<a name="FreeEntity"></a>**void FreeEntity(Entity* ent)**

<center>

<table width="100%" cellpadding="2" cellspacing="0"><colgroup><col width="256*"></colgroup>

<tbody>

<tr>

<td width="100%" style="border: none; padding: 0cm">

Frees up an entity.

</td>

</tr>

</tbody>

</table>

</center>

<a name="FreeRigidBody"></a>**void FreeRigidBody(RigidBody* body)**

Frees up a rigid body

<a name="FreeShadow"></a>**void FreeShadow(ShadowObject* shad)**

Frees up a shadow

<a name="FreeShader"></a><span style="font-variant: small-caps"><span lang="en-US">**void FreeShad**</span></span><span style="font-variant: small-caps"><span lang="en-US">**er**</span></span><span style="font-variant: small-caps"><span lang="en-US">**(Shad**</span></span><span style="font-variant: small-caps"><span lang="en-US">**er**</span></span><span style="font-variant: small-caps"><span lang="en-US">*** shad)**</span></span>

Frees up a shader

<a name="FreeTexture"></a>**void FreeTexture(Texture* tex)**

Frees up a texture

<a name="FreePostFX"></a>**void FreePostFX(Texture* tex)**

Frees up a post-processing effect

<a name="GeosphereHeight"></a>**void GeosphereHeight(Geosphere* geo, float h)**

Sets the maximum height of mountains on a geosphere terrain

<a name="GetBrushTexture"></a>**Texture* GetBrushTexture(Brush* brush,int index)**

Returns the texture that is applied to the specified brush.  

The optional _index_ parameter allows you to specify which particular texture you'd like returning, if there are more than one textures applied to a brush.

<a name="GetBone"></a>**<span lang="en-US">Bone</span><span lang="en-US">* Get</span><span lang="en-US">Bone</span><span lang="en-US">(Mesh* mesh,int</span> <span lang="en-US">index</span><span lang="en-US">)</span>**

Returns the handle of the bone attached to the specified mesh and with the specified index number.  

_Index_ should be in the range 1...CountBones( mesh ), inclusive.

<a name="GetChild"></a>**Entity* GetChild(Entity* ent,int child_no)**

Returns a child of an entity.

<a name="GetEntityBrush"></a>**Brush* GetEntityBrush(Entity* ent)**

Returns a brush with the same properties as is applied to the specified entity.  

If this command does not appear to be returning a valid brush, try using [GetSurfaceBrush](#GetSurfaceBrush) instead with the first surface available.  

Remember, GetEntityBrush actually creates a new brush so don't forget to free it afterwards using FreeBrush to prevent memory leaks.  

Once you have got the brush handle from an entity, you can use GetBrushTexture and TextureName to get the details of what texture(s) are applied to the brush.

<a name="GetEntityType"></a>**int GetEntityType(Entity* ent)**

Returns the collision type of an entity as set by the EntityType command.  

<a name="GetMatElement"></a>**float GetMatElement(Entity* ent,int row,int col)**

unsupported

<a name="GetParentEntity"></a>**Entity* GetParentEntity(Entity* ent)**

Returns an entity's parent

<a name="GetShaderProgram"></a>**int GetShaderProgram(Shader* material)**

Returns the number of the OpenGL program object, in case you need to access it directly

<a name="GetSurface"></a>**<span lang="en-US">Surface* GetSurface(Mesh* mesh,int</span> <span lang="en-US">index</span><span lang="en-US">)</span>**

<span lang="en-US">Returns the handle of the surface attached to the specified mesh and with the specified index number.  

</span><span lang="en-US">_Index_</span> <span lang="en-US">should be in the range 1...CountSurfaces( mesh ), inclusive.  

You need to 'get a surface', i.e. get its handle, in order to be able to then use that particular surface with other commands.</span>  

<a name="GetSurfaceBrush"></a>**Brush* GetSurfaceBrush(Surface* surf)**

Returns a brush with the same properties as is applied to the specified mesh surface.  

If this command does not appear to be returning a valid brush, try using [GetEntityBrush](#GetEntityBrush) instead.  

Remember, GetSurfaceBrush actually creates a new brush so don't forget to free it afterwards using [FreeBrush](#FreeBrush) to prevent memory leaks.  

Once you have got the brush handle from a surface, you can use [GetBrushTexture](#GetBrushTexture) and [TextureName](#TextureName) to get the details of what texture(s) are applied to the brush.  

<a name="Graphics3D"></a>**void Graphics3D(int width,int height,int depth,int mode,int rate)**

Initialise the library; this command will set horizontal and vertical resolution with _width_ and _height_. Other parameters (_depth_, _mode_, _rate_) are optional, and currently unused.

**ATTENTION**: this command **does not** create an openGL context (that is, a place where the 3d image is rendered: it can be the full screen, a window, or a place inside a window); you'll need to create it manually: in FreeBasic, the simplest way to do that is with **SCREEN** command:

<pre class="western">SCREEN 18, 32, , &h02

Graphics3d 640,480,32,1,1</pre>

(the &h02 parameter in SCREEN command specify to use openGL); of course, SCREENRES, too, can be used:

<pre class="western">SCREENRES 640, 480, 32, , &h02  
Graphics3d 640,480,32,1,1</pre>

Otherwise, external libraries like GluT can be used, or system-specific APIs can be called.

<a name="HandleSprite"></a>**void HandleSprite(Sprite* sprite,float h_x,float h_y)**

Sets a sprite handle. Defaults to 0,0.  

A sprite extends from -1,-1 to +1,+1\. If it is scaled or rotated, the handle is the center of rotation

<a name="HideEntity"></a>**void HideEntity(Entity* ent)**

Hides an entity, so that it is no longer visible, and is no longer involved in collisions. Hidden cameras won’t be used in rendering.

The main purpose of hide entity is to allow you to create entities at the beginning of a program, hide them, then copy them and show as necessary in the main game. This is more efficient than creating entities mid-game.  

If you wish to hide an entity so that it is no longer visible but still involved in collisions, then use EntityAlpha 0 instead. This will make an entity completely transparent.  

HideEntity <span lang="en-US">affects the specified entity only - child entities are not affected.</span>

<a name="LightColor"></a>**void LightColor(Light* light,float red,float green,float blue)**

Sets the color of a light.  

An r,g,b value of 255,255,255 will brighten anything the light shines on.  

An r,g,b value of 0,0,0 will have no affect on anything it shines on.  

An r,g,b value of -255,-255,-255 will darken anything it shines on. This is known as 'negative lighting', and is useful for shadow effects.

<a name="LightConeAngles"></a><span style="font-variant: small-caps">**void LightConeAngles(Light* light,float inner_ang**</span><span style="font-variant: small-caps">**le**</span><span style="font-variant: small-caps">**,float outer_ang**</span><span style="font-variant: small-caps">**le**</span><span style="font-variant: small-caps">**)**</span>

_light_ - light handle

_inner_angle_ - inner angle of cone

_outer_angle_ - outer angle of cone

**Description**

Sets the 'cone' angle for a 'spot' light.

The default light cone angles setting is 0,90\.

<a name="LightRange"></a>**void LightRange(Light* light,float range)**

Sets the range of a light.  

The range of a light is how far it reaches. Everything outside the range of the light will not be affected by it.  

The value is very approximate, and should be experimented with for best results.

<a name="LinePick"></a>**Entity* LinePick(float x,float y,float z,float dx,float dy,float dz,float radius)**

_x_ - x coordinate of start of line pick

_y_ - y coordinate of start of line pick

_z_ - z coordinate of start of line pick

_dx_ - distance x of line pick

_dy_ - distance y of line pick

_dz_ - distance z of line pick

_radius_ (optional) - radius of line pick

**Description**

Returns the first entity between <span style="font-style: normal">x,y,z to x+d</span>x,y+dy,z+dz.

<a name="LoadAnimMesh"></a>**Mesh* LoadAnimMesh(char* file,Entity* parent)**

LoadAnimMesh, similar to LoadMesh, Loads a mesh from an .X, .3DS, MD2 or .B3D file and returns a mesh handle.  

The difference between [LoadMesh](#LoadMesh) and LoadAnimMesh is that any hierarchy and animation information present in the file is retained. You can then either activate the animation by using the Animate command or find child entities within the hierarchy by using the FindChild(), GetChild() functions. Animation is available only in .B3D and .MD2 files, not in .3DS or .X  

The optional parent parameter allows you to specify a parent entity for the mesh so that when the parent is moved the child mesh will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="LoadAnimSeq"></a>**int LoadAnimSeq(Entity* ent, char* file)**

Appends an animation sequence from a file to an entity.

<a name="LoadAnimTexture"></a>**Texture* LoadAnimTexture(char* file,int flags,int frame_width,int frame_height,int first_frame,int frame_count)**

_file_ - name of image file with animation frames laid out in left-right, top-to-bottom order

_flags_ (optional) - texture flag:

1: Color (default)

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

128: Cubic environment map

_frame_width_ - width of each animation frame

_frame_height_ - height of each animation frame

_first_frame_ - the first frame to be used as an animation frame

_frame_count_ - the amount of frames to be used

**Description**

Loads an animated texture from an image file and returns the texture's handle.

The flags parameter allows you to apply certain effects to the texture. Flags can be added to combine two or more effects, e.g. 3 (1+2) = texture with colour and alpha maps.

See [CreateTexture](#CreateTexture) for more detailed descriptions of the texture flags.

<span lang="en-US">The</span> <span lang="en-US">_frame_width_</span><span lang="en-US">,</span> <span lang="en-US">_frame_height_</span><span lang="en-US">,</span> <span lang="en-US">_first_frame_</span> <span lang="en-US">and</span> <span lang="en-US">_frame_count_</span> <span lang="en-US">parameters determine how</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">will separate the image file into individual animation frames.</span>

<a name="LoadBrush"></a><span style="font-variant: small-caps">**Brush* LoadBrush(char *file,int flags,float u_scale,float v_scale)**</span>

_file_ - filename of texture

_flags_ (optional) - flags can be added to combine effects:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

128: cube reflection map

_u_scale_ - brush u_scale

_v_scale_ - brush v_scale

**Description**

Creates a brush, loads and assigns a texture to it, and returns a brush handle.

<a name="LoadGeosphere"></a><span style="font-variant: small-caps">**Terrain* LoadGeosphere(char* file,Entity* parent)**</span>

<span lang="en-US">Loads a</span> <span lang="en-US">spherical</span> <span lang="en-US">terrain</span> <span lang="en-US">(also called planet, or geosphere)</span> <span lang="en-US">from an image file and returns the terrain's handle.  

The image's red channel is used to determine heights.</span> <span lang="en-US">Geosphere</span> <span lang="en-US">is initially the</span> <span lang="en-US">same size as the height of</span> <span lang="en-US">the image.  

Tips on generating nice terrain:  

* Smooth or blur the height map  
* Reduce the camera range  

When texturing an entity, a texture with a scale of 1,1,1 (default) will be the same size as one of the terrain's grid squares. A texture that is scaled to the same size as the</span> <span lang="en-US">height</span> <span lang="en-US">of the bitmap used to load it or the no. of grid square used to create it, will be the same size as the terrain.  

The optional parent parameter allows you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.</span>

<span lang="en-US">A heightmaps width must be twice the height, since equirectangular projection will be used: each horizontal unit will correspond to one unit of longitude, each vertical unit will correspond to one unit of latitude. Since latitude is 180° (from one pole to the other,</span> <span lang="en-US">90° north to 90° south</span><span lang="en-US">) and longitude is 360° (equatorial circumference,</span> <span lang="en-US">from 180° east to 180° west</span><span lang="en-US">),</span> <span lang="en-US">width must be twice the height.</span><span lang="en-US">  
</span>  

<a name="LoadMaterial"></a><span style="font-variant: small-caps">**Material* LoadMaterial(char* filename,int flags, int frame_width,int frame_height,int first_frame,int frame_count)**</span>

<span lang="en-US">_file_</span> <span lang="en-US">- name of image file with</span> <span lang="en-US">slices</span> <span lang="en-US">laid out in left-right, top-to-bottom order</span>

_flags_ (optional) - texture flag:

1: Color (default)

2: Alpha

4: Masked

8: Mipmapped

_frame_width_ - width of each animation frame

_frame_height_ - height of each animation frame

_first_frame_ - the first frame to be used as an animation frame

_frame_count_ - the amount of frames to be used

**Description**

Loads a 3d texture from an image file and returns the texture's handle.

The flags parameter allows you to apply certain effects to the texture. Flags can be added to combine two or more effects, e.g. 3 (1+2) = texture with colour and alpha maps.

<span lang="en-US">The</span> <span lang="en-US">_frame_width_</span><span lang="en-US">,</span> <span lang="en-US">_frame_height_</span><span lang="en-US">,</span> <span lang="en-US">_first_frame_</span> <span lang="en-US">and</span> <span lang="en-US">_frame_count_</span> <span lang="en-US">parameters determine how</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">will separate the image file into individual animation frames.</span>

<a name="LoadMesh"></a>**Mesh* LoadMesh(char* file,Entity* parent)**

LoadMesh, as the name suggests, Loads a mesh from an .X, .3DS or .B3D file (Usually created in advance by one of a number of 3D model creation packages) and returns the mesh handle.  

Any hierarchy and animation information in the file will be ignored. Use [LoadAnimMesh](#LoadAnimMesh) to maintain hierarchy and animation information.  

The optional parent parameter allows you to specify a parent entity for the mesh so that when the parent is moved the child mesh will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.  

<a name="LoadShader"></a>**Shader* LoadShader(char* ShaderName, char* VshaderFileName, char* FshaderFileName)**

Loads a shader. A shader is a special program that is not run on the CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It requires a name, and two files, called Vertex Shader and Fragment Shader

<a name="LoadShaderVGF"></a>**Shader* LoadShaderVGF(char* ShaderName, char* VshaderFileName, char* GshaderFileName, char* FshaderFileName)**

Loads a shader. A shader is a special program that is not run on the CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It requires a name, and three files, called Vertex Shader, Geometry Shader and Fragment Shader.

<a name="LoadSprite"></a>**Sprite* LoadSprite(char* tex_file,int tex_flag,Entity* parent)**

_text_file_ - filename of image file to be used as sprite

_tex_flag_ (optional) - texture flag:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

_parent_ - parent of entity

**Description**

Creates a sprite entity, and assigns a texture to it.

<a name="LoadTerrain"></a>**Terrain* LoadTerrain(char* file,Entity* parent)**

<span lang="en-US">Loads a terrain from an image file and returns the terrain's handle.  

The image's red channel is used to determine heights. Terrain is initially the same width and depth as the image, and 1 unit high.  

Tips on generating nice terrain:  

* Smooth or blur the height map  
* Reduce the y scale of the terrain  
* Increase the x/z scale of the terrain  
* Reduce the camera range  

When texturing an entity, a texture with a scale of 1,1,1 (default) will be the same size as one of the terrain's grid squares. A texture that is scaled to the same size as the size of the bitmap used to load it or the no. of grid square used to create it, will be the same size as the terrain.  

The optional parent parameter allows you to specify a parent entity for the terrain so that when the parent is moved the child terrain will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.  

Specifying a parent entity will still result in the terrain being created at position 0,0,0 rather than at the parent entity's position.  

A heightmaps dimensions (width and height) must be the same and</span> <span lang="en-US">should</span> <span lang="en-US">be a power of 2, e.g. 32, 64, 128, 256, 512, 1024\.</span>

<a name="LoadTexture"></a>**Texture* LoadTexture(char* file,int flags)**

Load a texture from an image file and returns the texture's handle. Supported file formats include: BMP, PNG, TGA and JPG. Only PNG and TGA support alpha.

The optional flags parameter allows you to apply certain effects to the texture. Flags can be added to combine two or more effects, e.g. 3 (1+2) = texture with colour and alpha maps.

See [CreateTexture](#CreateTexture) for more detailed descriptions of the texture flags.

Something to consider when applying texture flags to loaded textures is that the texture may have already had certain flags applied to it via the [TextureFilter](#TextureFilter) command. The default for the [TextureFilter](#TextureFilter) command is 9 (1+8), which is a coloured, mipmapped texture. This cannot be overridden via the flags parameter of the LoadTexture command - if you wish for the filters to be removed you will need to use the [ClearTextureFilters](#ClearTextureFilters) command, which must be done after setting the graphics mode (setting the graphics mode restores the default texture filters).

<a name="MeshCSG"></a>**Mesh* MeshCSG(Mesh* m1, Mesh* m2, int method = 1)**

_m1_ first mesh

_m2_ second mesh

_method_ CSG operation:

0: subtraction

1: union

2: intersection

3: decal

**Description**

Creates a new mesh by performing a CSG (Constructive Solid Geometry) operation on two given meshes _m1_ and _m2_. Those meshes are not modified, and might need to be removed with FreeEntity at the end of the CSG operations.

<span lang="en-US">The</span> <span lang="en-US">_method_</span> <span lang="en-US">parameter specifies which CSG operation must be performed: a subtraction removes the second mesh from the first, basically creating a hole inside m1, shaped like m2; an union combines the two meshes into one, removing all the superfluous geometry: in that, it differs from AddMesh, that includes also the intersecting parts of meshes, that should never be visible anyway</span> <span lang="en-US">(</span><span lang="en-US">if you use this operation to add many boxes and cylinders, then you flip the result with FlipMesh, you will get a set of corridors/dungeon</span><span lang="en-US">)</span><span lang="en-US">; an intersection creates a mesh that is made only by the intersecting parts of</span> <span lang="en-US">_m1_</span> <span lang="en-US">and</span> <span lang="en-US">_m2_</span> <span lang="en-US">(the intersection of two spheres can be used to produce a lens shaped mesh, for example);</span> <span lang="en-US">a decal produces a decal mesh, that is basically a very thin mesh that adheres to the surface of m1, and is delimited by m2:</span> <span lang="en-US">by setting a negative rendering order with</span> [EntityOrder](#EntityOrder) <span lang="en-US">it’s possible to render it after m1, so it will always be visible over it, and it can be useful to apply a different texture or material to a selected part of a mesh.</span><span lang="en-US"></span>

<a name="MeshCullRadius"></a>**void MeshCullRadius(Entity* ent, float radius)**

<span lang="en-US">This command is the equivalent of</span> <span lang="en-US">Blitz</span><span lang="en-US">3D's MeshCullBox command.</span>

It is used to set the radius of a mesh's 'cull sphere' - if the 'cull sphere' is not inside the viewing area, the mesh will not be rendered.

A mesh's cull radius is set automatically, therefore in most cases you will not have to use this command.

One time you may have to use it is for animated meshes where the default cull radius may not take into account all animation positions, resulting in the mesh being wrongly culled at extreme positions.

<a name="MeshDepth"></a><span style="font-variant: small-caps">**float MeshDepth(Mesh* mesh)**</span>

Returns the depth of a mesh. This is calculated by the actual vertex positions and so the scale of the entity (set by ScaleEntity) will not have an effect on the resultant depth. Mesh operations, on the other hand, will effect the result.  

<a name="MeshesIntersect"></a>**int MeshesIntersect(Mesh* mesh1,Mesh* mesh2)**

<span lang="en-US">Returns true if the specified meshes are currently intersecting.  

This is a fairly slow routine - use with discretion...  

This command is currently the only polygon->polygon collision checking routine available in</span> <span lang="en-US">OpenB3D</span><span lang="en-US">.</span>

<a name="MeshHeight"></a><span style="font-variant: small-caps">**float MeshHeight(Mesh* mesh)**</span>

<span lang="en-US">Returns the</span> <span lang="en-US">height</span> <span lang="en-US">of a mesh. This is calculated by the actual vertex positions and so the scale of the entity (set by ScaleEntity) will not have an effect on the resultant</span> <span lang="en-US">height</span><span lang="en-US">. Mesh operations, on the other hand, will effect the result.  
</span>  

<a name="MeshWidth"></a>**float MeshWidth(Mesh* mesh)**

<span lang="en-US">Returns the</span> <span lang="en-US">width</span> <span lang="en-US">of a mesh. This is calculated by the actual vertex positions and so the scale of the entity (set by ScaleEntity) will not have an effect on the resultant</span> <span lang="en-US">width</span><span lang="en-US">. Mesh operations, on the other hand, will effect the result.  
</span>  

<a name="ModifyGeosphere"></a>**void ModifyGeosphere(Geosphere* geo, int x, int z, float new_height)**

<span lang="en-US">Sets the height of a point on a</span> <span lang="en-US">geosphere</span><span lang="en-US">.</span>

<a name="ModifyTerrain"></a>**void ModifyTerrain(Terrain* terr, int x, int z, float new_height)**

Sets the height of a point on a terrain.

<a name="MoveBone"></a><span style="font-variant: small-caps"><span lang="en-US">**int**</span></span><span style="font-variant: small-caps"><span lang="en-US"> **Move**</span></span><span style="font-variant: small-caps"><span lang="en-US">**Bone**</span></span><span style="font-variant: small-caps"><span lang="en-US">**(**</span></span><span style="font-variant: small-caps"><span lang="en-US">**Bone**</span></span><span style="font-variant: small-caps"><span lang="en-US">***** </span></span><span style="font-variant: small-caps"><span lang="en-US">**bone**</span></span><span style="font-variant: small-caps"><span lang="en-US">**,float x,float y,float z,** </span></span><span style="font-variant: small-caps"><span lang="en-US">**int segments**</span></span><span style="font-variant: small-caps"><span lang="en-US">**=2**</span></span><span style="font-variant: small-caps">**)**</span>

Attempts to move a bone to a given position by modifying the orientation of the other bones. Coordinates _x_, _y_ and _z_ are relative to the current position and orientation of its mesh.

Imagine moving your hand to grab something: to achieve that, you turn your arm and forearm, bending the joints of your elbow and shoulder; the same is true in a skeletal based animation (just moving the hand with commands like MoveEntity or PositionEntity would not move the elbow, and would change the length of the forearm). While bones could be easily rotated by commands like TurnEntity or RotateEntity, it’s not easy to figure the correct rotation to make the hand reach a chosen position: calculating the final position of the hand from given angles is called forward kinematics; the inverse process (calculating the angles required to move the hand in a wanted position) is called inverse kinematics.

The command MoveBone does exactly that: it rotates the joints of a limb to move a specified bone (usually the end of that limb) to a given position; this is not always possible (sometimes the destination is just out of reach), so the function will return **true** in case of success, **false** otherwise.

The optional _parameter_ segments determines how many joints must be computed: in the example of the hand, the value is usually 2 (the elbow and the shoulder joint); a higher value is accepted, but in some cases it could lead to unpredictable effects caused by cumulative rounding errors.

Since animated meshes don’t contain information about limits or degrees of freedom of a joint, some movements might result in unnatural poses, like knees bent backward. This can be prevented by starting from an anatomically correct position, because the algorithm tries to minimize the changes from the current position.

<a name="MoveEntity"></a>**void MoveEntity(Entity* ent,float x,float y,float z)**

<span lang="en-US">Moves an entity relative to its current position and orientation.  

What this means is that an entity will move in whatever direction it is facing. So for example if you have an game character is upright when first loaded into</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">and it remains upright (i.e. turns left or right only), then moving it by a z amount will always see it move forward or backward, moving it by a y amount will always see it move up or down, and moving it by an x amount will always see it strafe.</span>

<a name="NameEntity"></a>**void NameEntity(Entity* ent,char* name)**

Sets an entity's name.

<a name="OctreeBlock"></a>**void OctreeBlock(OcTree* octree, Mesh* mesh, int level, float X, float Y, float Z, float Near=0.0, float Far=1000.0, int Solid=1)**

Adds a block to an octree, shaped like a given _mesh_. The size of the mesh should fit between -1,-1,-1 and 1,1,1\. A block is supposed to be used to set the "bricks", to create more complex levels.

<span lang="en-US">An octree can be imagined as a cube subdivided in eight smaller cubes, each one subdivided again. So, the first level will be a 2x2x2=8</span> <span lang="en-US">cubes</span> <span lang="en-US">structure, at the second level it will be a 4x4x4=64</span> <span lang="en-US">cubes</span> <span lang="en-US">structure, and so on .</span> <span lang="en-US">If the block</span> <span lang="en-US">is</span> <span lang="en-US">a cube made with CreateCube, it will be scaled to fit that cell size perfectly. Meshes created with the graphic primitives (CreateSphere, CreateCone, CreateCube and so on) usually fit between -1,-1,-1 and 1,1,1, so the octree expects a mesh of that size (a mesh of different size</span> <span lang="en-US">c</span><span lang="en-US">an</span> <span lang="en-US">be</span> <span lang="en-US">scale</span><span lang="en-US">d</span> <span lang="en-US">using FitMesh</span><span lang="en-US">).</span>

<span lang="en-US">The block is placed inside the octree, at the chosen</span> <span lang="en-US">_level_</span><span lang="en-US"> <span style="font-style: normal">(a higher level means smaller block size, and higher number of blocks), and at a position that tries to match the given coordinates</span> </span><span lang="en-US">_X_</span><span lang="en-US"><span style="font-style: normal">,</span> </span><span lang="en-US">_Y_</span><span lang="en-US"><span style="font-style: normal">,</span> </span><span lang="en-US">_Z_</span><span lang="en-US"> <span style="font-style: normal">(referred to the octree, not to the world). It will be scaled automatically. The same mesh could be used as block in more than one position (for example, a cubic mesh that is supposed to work as a wall can be used many times to build a complex maze, and it will be stored in memory only once).</span></span>

If the mesh is animated, all the blocks based on it will be animated, too, and this can be useful to show flags, fans, or any other animated item that needs to be used more than once.

<span lang="en-US"><span style="font-style: normal">A</span> </span><span lang="en-US"><span style="font-style: normal">mesh</span> </span><span lang="en-US"><span style="font-style: normal">that doesn’t fit the recommended size</span> </span><span lang="en-US"><span style="font-style: normal">will be rendered anyway, it will just be larger than the octree cell. It shouldn't cause problem, since the octree cell is virtual, it is not something visible on the screen, although it might disappear if the cell is completely out of view (the scene manager, expecting that the mesh is completely inside the cell, would conclude that the mesh is not visible and so it would not render it, not knowing that the overlapping part of the mesh might be still in view)</span></span>

<span lang="en-US"><span style="font-style: normal">Parameters</span> </span><span lang="en-US">_Near_</span><span lang="en-US"> <span style="font-style: normal">and</span> </span><span lang="en-US">_Far_</span><span lang="en-US"> <span style="font-style: normal">are used in case you need a LOD (Level Of Detail) rendering, to specify a distance range from the camera: any block closer than</span> </span><span lang="en-US">_Near_</span><span lang="en-US"> <span style="font-style: normal">won’t be rendered. Any block farther</span> </span><span lang="en-US"><span style="font-style: normal">than</span> </span><span lang="en-US">_Far_</span><span lang="en-US"> <span style="font-style: normal">will stop the recursive rendering, so blocks smaller than it won’t be rendered. In that way it is possible to render a large block with a low detail geometry, and when the camera gets closer, the block would disappear and be replaced by several smaller blocks with more details.</span></span>

<span lang="en-US"><span style="font-style: normal">P</span></span><span lang="en-US"><span style="font-style: normal">arameter</span> </span><span lang="en-US">_Solid_ </span><span lang="en-US"><span style="font-style: normal">determines if the geometry of the block is used in picking or collisions: a value of zero causes the block to be displayed, but to be ignored by collision system (this is useful for decorative blocks that contain grass, or curtains, or vines, or for alpha blocks used to create volumetric fog or water)</span></span>

<a name="OctreeMesh"></a>**void OctreeMesh(OcTree* octree, Mesh* mesh, int level, float X, float Y, float Z, float Near=0.0, float Far=1000.0)**

Attaches a _mesh_ to an octree. The octree will become its parent. The mesh can be used only in one position, inside the octree, and must be placed and scaled manually with PositionEntity and ScaleEntity. It will be attached to a node inside the octree, at the chosen _level_ <span style="font-style: normal">(a higher level means smaller block size, and higher number of blocks), and at a position that tries to match the given coordinates</span> _X_<span style="font-style: normal">,</span> _Y_<span style="font-style: normal">,</span> _Z_ <span style="font-style: normal">(referred to the octree, not to the world).</span>

<span style="font-style: normal">This commands allows to use the octree as a scene manager, In</span> <span style="font-style: normal">a complex scene, with thousands or more of meshes, the default scene manager would be pretty slow, since it checks for each mesh if it is in view of the camera before rendering it: an octree can be faster, because it can group several meshes at once: if one section of the octree is out of view, all the meshes assigned to that section will be out of view too, and there is no need to check them one by one.</span>

<span lang="en-US"><span style="font-style: normal">Parameters</span> </span><span lang="en-US">_Near_</span><span lang="en-US"> <span style="font-style: normal">and</span> </span><span lang="en-US">_Far_</span><span lang="en-US"> <span style="font-style: normal">are used in case you need a LOD (Level Of Detail) rendering, to specify a distance range from the camera: any</span> </span><span lang="en-US"><span style="font-style: normal">node</span></span><span lang="en-US"> <span style="font-style: normal">closer than</span> </span><span lang="en-US">_Near_</span><span lang="en-US"> <span style="font-style: normal">won’t be rendered. Any</span> </span><span lang="en-US"><span style="font-style: normal">node</span> </span><span lang="en-US"><span style="font-style: normal">farther</span> </span><span lang="en-US"><span style="font-style: normal">than</span> </span><span lang="en-US">_Far_</span><span lang="en-US"> <span style="font-style: normal">will stop the recursive rendering, so blocks smaller than it won’t be rendered. In that way it is possible to render a large block with a low detail geometry, and when the camera gets closer, the block would disappear and be replaced by several smaller blocks with more details.</span></span>

<a name="PaintEntity"></a>**void PaintEntity(Entity* ent,Brush* brush)**

<table width="643" cellpadding="2" cellspacing="0"><colgroup><col width="639"></colgroup>

<tbody>

<tr>

<td width="639" style="border: none; padding: 0cm">

Paints a entity with a brush.  

The reason for using PaintEntity to apply specific properties to a entity using a brush rather than just using EntityTexture, EntityColor, EntityShininess etc, is that you can pre-define one brush, and then paint entities over and over again using just the one command rather than lots of separate ones.

</td>

</tr>

</tbody>

</table>

<a name="PaintMesh"></a><span style="font-variant: small-caps">**void PaintMesh(Mesh* mesh,Brush* brush)**</span>

Paints a mesh with a brush.

This has the effect of instantly altering the visible appearance of the mesh, assuming the brush's properties are different to what was was applied to the surface before.

The reason for using PaintMesh to apply specific properties to a mesh using a brush rather than just using EntityTexture, EntityColor, EntityShininess etc, is that you can pre-define one brush, and then paint meshes over and over again using just the one command rather than lots of separate ones.

<a name="PaintSurface"></a>**void PaintSurface(Surface* surf,Brush* brush)**

Paints a surface with a brush.  

This has the effect of instantly altering the visible appearance of that particular surface, i.e. section of mesh, assuming the brush's properties are different to what was applied to the surface before.

<a name="ParticleColor"></a>**void ParticleColor(Sprite* sprite, float red, float green, float blue, float alpha)**

<span lang="en-US">It affects the fading color of</span> <span lang="en-US">particle trails (particles are sprites with</span> [SpriteRenderMode](#SpriteRenderMode) <span lang="en-US">set to 3): those particles can leave a trail behind them, and it is possible to set the fading color of it (setting it to gray, for a red particle, allows to produce a flame turning to smoke effect)</span>

<a name="ParticleVector"></a>**void ParticleVector(Sprite* sprite, float x, float y, float z)**

<span lang="en-US">It affects the</span> <span lang="en-US">direction</span> <span lang="en-US">of</span> <span lang="en-US">particle trails (particles are sprites with</span> [SpriteRenderMode](#SpriteRenderMode) <span lang="en-US">set to 3): those particles can leave a trail behind them, and it is possible to set the</span> <span lang="en-US">direction the trail will move to, even when the particle itself is not moving. This is useful to simulate a wind effect.</span>

<a name="ParticleTrail"></a>**void ParticleTrail(Sprite* sprite,int length)**

<span lang="en-US">It</span> <span lang="en-US">sets the length</span> <span lang="en-US">of</span> <span lang="en-US">particle trails (particles are sprites with</span> [SpriteRenderMode](#SpriteRenderMode) <span lang="en-US">set to 3): those particles can leave a trail behind them.</span>

<a name="PickedEntity"></a><span style="font-variant: small-caps">**Entity* PickedEntity()**</span>

Returns the entity ‘picked’ by the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).  

Returns 0 if no entity was picked.

<a name="PickedNX"></a>**float PickedNX()**

Returns the x component of the normal of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedNY"></a>**float PickedNY()**

Returns the y component of the normal of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedNZ"></a>**float PickedNZ()**

Returns the z component of the normal of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedSurface"></a><span style="font-variant: small-caps">**Surface* PickedSurface()**</span>

Returns the handle of the surface that was ‘picked’ by the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedTime"></a>**float PickedTime()**

Returns the time taken to calculate the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedTriangle"></a>**int PickedTriangle()**

Returns the index number of the triangle that was ‘picked’ by the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).

<a name="PickedX"></a>**float PickedX()**

Returns the world x coordinate of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).  

The coordinate represents the exact point of where something was picked.

<a name="PickedY"></a>**float PickedY()**

Returns the world x coordinate of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).  

The coordinate represents the exact point of where something was picked.

<a name="PickedZ"></a>**float PickedZ()**

Returns the world x coordinate of the most recently executed Pick command. This might have been [CameraPick](#CameraPick), [EntityPick](#EntityPick) or [LinePick](#LinePick).  

The coordinate represents the exact point of where something was picked.

<a name="PointEntity"></a>**void PointEntity(Entity* ent,Entity* target_ent,float roll)**

<table width="643" cellpadding="2" cellspacing="0"><colgroup><col width="639"></colgroup>

<tbody>

<tr>

<td width="639" style="border: none; padding: 0cm">

Points one entity at another.  

The optional _roll_ parameter allows you to specify a roll angle as pointing an entity only sets pitch and yaw angles.  

If you wish for an entity to point at a certain position rather than another entity, simply create a pivot entity at your desired position, point the entity at this and then free the pivot.

</td>

</tr>

</tbody>

</table>

<a name="PositionBone"></a>**void PositionBone(Bone* bone,float x,float y,float z)**

Set the position of a bone, related to its parent. It doesn’t deform the vertices of the mesh, so it’s useful to set the starting position of a bone.

This command is supposed to be used immediately after the creation of the bone, because it doesn’t update the children entities of the bone.

<a name="PositionEntity"></a>**void PositionEntity(Entity* ent,float x,float y,float z,bool global)**

<table width="643" cellpadding="2" cellspacing="0"><colgroup><col width="639"></colgroup>

<tbody>

<tr>

<td width="639" style="border: none; padding: 0cm">

Positions an entity at an absolute position in 3D space.  

Entities are positioned using an _x_,_y_,_z_ coordinate system. x, y and z each have their own axis, and each axis has its own set of values. By specifying a value for each axis, you can position an entity anywhere in 3D space. 0,0,0 is the centre of 3D space, and if the camera is pointing in the default positive z direction, then positioning an entity with a z value of above 0 will make it appear in front of the camera, whereas a negative z value would see it disappear behind the camera. Changing the x value would see it moving sideways, and changing the y value would see it moving up/down.  

Of course, the direction in which entities appear to move is relative to the position and orientation of the camera.

</td>

</tr>

</tbody>

</table>

<span style="font-style: normal">The optional parameter</span> _global_<span style="font-style: normal">,</span>if true states that the position should be relative to 0,0,0 rather than a parent entity's position. False by default.

<a name="PositionMesh"></a>**void PositionMesh(Mesh* mesh,float px,float py,float pz)**

Moves all vertices of a mesh

<a name="PositionTexture"></a>**void PositionTexture(Texture* tex,float u_pos,float v_pos)**

Positions a texture at an absolute position.  

This will have an immediate effect on all instances of the texture being used.  

Positioning a texture is useful for performing scrolling texture effects, such as for water etc.

<a name="PostFXBuffer"></a>**void PostFXBuffer(PostFX* fx, int pass_no, int source_pass, int index, int slot)**

<span lang="en-US">Attaches the output buffer generated by one pass,</span> <span lang="en-US"></span> <span lang="en-US">in a post processing effect</span> <span lang="en-US">_fx_</span><span lang="en-US"><span style="font-style: normal">,</span> </span><span lang="en-US"><span style="font-style: normal">to be used as input for another step</span></span><span lang="en-US">: it allows to</span> <span lang="en-US">use one of the</span> <span lang="en-US">color buffers (those buffer contain the rendered image),</span> <span lang="en-US">or the</span> <span lang="en-US">depth buffer</span> <span lang="en-US">as texture attached to a shader (shaders can use textures as input, so images must be passed to them as textures)</span><span lang="en-US">. The</span> <span lang="en-US">output buffer create</span><span lang="en-US">d</span> <span lang="en-US">by the stage</span> <span lang="en-US">_source_pass_</span> <span lang="en-US">(stage 0 is the scene rendering, stage 1 is the first shader, an</span><span lang="en-US"><span style="font-style: normal">d so on</span></span><span lang="en-US">)</span> <span lang="en-US">will be used as input</span> <span lang="en-US">texture</span> <span lang="en-US">for the</span> <span lang="en-US">shader in</span> <span lang="en-US">stage</span> <span lang="en-US">_pass_no_</span> <span lang="en-US"></span> <span lang="en-US">(0 is the first shader, 1 is the second shader, and so on):</span> <span lang="en-US">for example, a source_pass =0 and a pass_no = 0 mean to use the output of the scene rendering as input for the first shader; values of 1 and 1 mean to use the output of the first shader as input for the second one</span><span lang="en-US">.</span>

<span lang="en-US">The parameter</span> <span lang="en-US">_index_</span> <span lang="en-US">sets</span> <span lang="en-US">which texture should be used: 0 is the depth buffer, 1 or more identifies a</span> <span lang="en-US">color buffer (this is useful when using a shader than outputs different information on different buffers: for example, in deferred shading one buffer can contain the normal data, another the actual colors)</span>

<span lang="en-US">T</span><span lang="en-US">he parameter</span> <span lang="en-US">_slot_</span> <span lang="en-US">sets the texture slot to be used, for the shader to identify it.</span>

<a name="PostFXFunction"></a>**void PostFXFunction(PostFX* fx, int pass_no, void (*PassFunction)(void))**

Attaches a custom function to a post processing effect _fx_<span style="font-style: normal">,</span> <span style="font-style: normal">to be executed at step</span> _pass_no_<span style="font-style: normal">, to apply custom post-processing.</span>

<a name="PostFXShader"></a>**void PostFXShader(PostFX* fx, int pass_no, Shader* shader)**

Attaches a shader program (created with [CreateShader](#CreateShader) or loaded with [LoadShader](#LoadShader)) to the post processing effect _fx_. The parameter _pass_no_ specifies at which step the shader will be used (0 is the first one)

<a name="PostFXShaderPass"></a>**void PostFXShaderPass(PostFX* fx, int pass_no, char* name, int v)**

Passes the numeric parameter _v_ to the shader attached to the post processing effect _fx_ <span style="font-style: normal"></span> <span style="font-style: normal">at the step identified by</span> _pass_no_<span style="font-style: normal">. The string</span> _name_ <span style="font-style: normal">identifies the uniform used internally by the shader.</span> <span style="font-style: normal">This command is useful when the same shader is used in more steps of the post-processing</span>

<a name="PostFXTexture"></a>**void PostFXTexture(PostFX* fx, int pass_no, Texture* tex, int slot, int frame=0)**

Attaches a texture _tex_ to a pass, in a post processing effect _fx_<span style="font-style: normal">,</span> <span style="font-style: normal">to be used as input.</span> <span style="font-style: normal">It</span> <span style="font-style: normal">will be used as input</span> <span style="font-style: normal">texture</span> <span style="font-style: normal">for the</span> <span style="font-style: normal">shader in</span> <span style="font-style: normal">stage</span> _pass_no_ <span style="font-style: normal"></span> <span style="font-style: normal">(0 is the first shader, 1 is the second shader, and so on).</span>

<span style="font-style: normal">P</span><span style="font-style: normal">assing a texture is useful to simulate vignetting, or to add a “mask” to the picture.</span>

<span style="font-style: normal">T</span><span style="font-style: normal">he parameter</span> _slot_ <span style="font-style: normal">sets the texture slot to be used, for the shader to identify it.</span>

<span style="font-style: normal">The parameter</span> _frame_ <span style="font-style: normal">is used to select the frame in animated textures.</span>

<a name="ProjectedX"></a>**float ProjectedX()**

Returns the viewport x coordinate of the most recently executed [CameraProject](#CameraProject).

<a name="ProjectedY"></a>**float ProjectedY()**

Returns the viewport y coordinate of the most recently executed [CameraProject](#CameraProject).

<a name="ProjectedZ"></a>**float ProjectedZ()**

Returns the viewport z coordinate of the most recently executed [CameraProject](#CameraProject).

<a name="RenderWorld"></a>**void RenderWorld()**

Renders the current scene to the BackBuffer onto the rectangle defined by each cameras [CameraViewport](#CameraViewport). Every camera not hidden by [HideEntity](#HideEntity) or with a [CameraProjMode](#CameraProjMode) of 0 is rendered.

<a name="RepeatMesh"></a>**Mesh* RepeatMesh(Mesh* mesh,Entity* parent)**

Creates an instance of a given mesh: the instance is a copy of the mesh that does not duplicate all its data, but uses the same data from the original: in this way, it will need less memory, but changes made to the original mesh (like ScaleMesh or RotateMesh) will affect the duplicate as well.

In case of animated meshes, all the frames of the mesh will be rendered in memory as separate surface, and they will be used for the animation: as result, the animation will be less smooth, and it won’t be possible to animate bones manually; on the other hand, it will be possible to render hundreds or thousands of animated meshes at different stages of the animation with less significant impact on speed and memory usage.

The optional _parent_ parameter allow you to specify a parent entity for the camera so that when the parent is moved the child camera will move with it. However, this relationship is one way; applying movement commands to the child will not affect the parent.

<a name="ResetEntity"></a>**void ResetEntity(Entity* ent)**

Resets the collision state of an entity.

<a name="ResetShadow"></a>**void ResetShadow(ShadowObject* shad)**

Forces a static shadow (created with the static flag) to be recalculated (useful when the mesh is moved or deformed). Not needed for dynamic shadows.

<a name="RotateBone"></a>**void RotateBone(Bone* bone,float pitch,float yaw,float roll)**

Set the rotation of a bone, related to its parent. It doesn’t deform the vertices of the mesh, so it’s useful to set the starting rotation of a bone.

This command is supposed to be used immediately after the creation of the bone, because it doesn’t update the children entities of the bone.

<a name="RotateEntity"></a>**void RotateEntity(Entity* ent,float pitch,float yaw,float roll,bool global)**

entity - name of the entity to be rotated

_pitch_ - angle in degrees of pitch rotation

_yaw_ - angle in degrees of yaw rotation

_roll_ - angle in degrees of roll rotation

_global_ (optional) - true if the angle rotated should be relative to 0,0,0 rather than a parent entity's orientation. False by default.

**Description**

Rotates an entity so that it is at an absolute orientation.

_Pitch_ is the same as the x angle of an entity, and is equivalent to tilting forward/backwards.

_Yaw_ is the same as the y angle of an entity, and is equivalent to turning left/right.

_Roll_ is the same as the z angle of an entity, and is equivalent to tilting left/right.

<a name="RotateMesh"></a>**void RotateMesh(Mesh* mesh,float pitch,float yaw,float roll)**

Rotates all vertices of a mesh by the specified rotation.

<a name="RotateSprite"></a>**void RotateSprite(Sprite* sprite,float ang)**

Rotates a sprite

<a name="RotateTexture"></a>**void RotateTexture(Texture* tex,float ang)**

Rotates a texture.  

This will have an immediate effect on all instances of the texture being used.  

Rotating a texture is useful for performing swirling texture effects, such as for smoke etc.

<a name="ScaleEntity"></a>**void ScaleEntity(Entity* ent,float x,float y,float z,bool glob)**

Scales an entity so that it is of an absolute size.  

Scale values of 1,1,1 are the default size when creating/loading entities.  

Scale values of 2,2,2 will double the size of an entity.  

Scale values of 0,0,0 will make an entity disappear.  

Scale values of less than 0,0,0 will invert an entity and make it bigger.

<a name="ScaleMesh"></a>**void ScaleMesh(Mesh* mesh,float sx,float sy,float sz)**

Scales all vertices of a mesh by the specified scaling factors.  

<a name="ScaleSprite"></a>**void ScaleSprite(Sprite* sprite,float s_x,float s_y)**

Scales a sprite

<a name="ScaleTexture"></a>**void ScaleTexture(Texture* tex,float u_scale,float v_scale)**

Scales a texture by an absolute amount.  

This will have an immediate effect on all instances of the texture being used.

<a name="SetAnimKey"></a>**void SetAnimKey(Entity* ent, float frame, int pos_key=true, int rot_key=true, int scale_key=true)**

_entity_ - entity handle

_frame_ - frame of animation to be used as anim key

_pos_key_ (optional) - true to include entity position information when setting key. Defaults to true.

_rot_key_ (optional) - true to include entity rotation information when setting key. Defaults to true.

_scale_key_ (optional) - true to include entity scale information when setting key. Defaults to true.

**Description**

Sets an animation key for the specified entity at the specified frame. The entity must have a valid animation sequence to work with.

This is most useful when you've got a character, or a complete set of complicated moves to perform, and you want to perform them en-masse.

<a name="SetAnimTime"></a>**void SetAnimTime(Entity* ent,float time,int seq)**

_entity_ - a valid entity handle.

_time_ - a floating point time value.

_anim_seq_ - an optional animation sequence number.

**Description**

SetAnimTime allows you to manually animate entities.

<a name="SetCubeFace"></a>**void SetCubeFace(Texture* tex,int face)**

_texture_ - texture  
_face_ - face of cube to select. This should be one of the following values:  
0: left (negative X) face  
1: forward (positive Z) face - this is the default.  
2: right (positive X) face  
3: backward (negative Z) face  
4: up (positive Y) face  
5: down (negative Y) face

**Description**

<span lang="en-US">Selects a cube face for direct rendering to a texture.  

This command should only be used when you wish to draw directly to a cube map texture in real-time. Otherwise, just loading a pre-rendered cube map with a flag of 128 will suffice.  

To understand how this command works exactly it is important to recognise that</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">treats cubemap textures slightly differently to how it treats other textures. Here's how it works...  

A cubemap texture in</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">actually consists of six images, each of which corresponds to a particular cube face. These images are stored internally by</span> <span lang="en-US">OpenB3D</span><span lang="en-US">, and the texture handle that is returned by LoadTexture/CreateTexture when specifying the cube map flag, only provides access to one of these six images at once (by default the first one, or '0' face).  

This is why, when loading a cubemap texture into</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">using LoadTexture, all the six cube map images must be laid out in a specific order (0-5, as described above), in a horizontal strip. Then</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">takes this texture and internally converts it into six separate images.</span>

<span lang="en-US">So seeing as the texture handle returned by CreateTexture / LoadTexture only provides access to one of these images at once (no. 1 by default), how do we get access to the other five images? This is where SetCubeFace comes in. It will tell</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">that whenever you next draw to a cubemap texture, to draw to the particular image representing the face you have specified with the face parameter.</span>

<span lang="en-US">Now you have the ability to draw to a cube map in real-time,</span> <span lang="en-US">using either BufferToTex, BackBufferToTex, or CameraToTex</span><span lang="en-US">  
</span>  

<a name="SetCubeMode"></a>**void SetCubeMode(Texture* tex,int mode)**

Set the rendering mode of a cubemap texture.  

The available rendering modes are as follows:  

1: Specular (default). Use this to give your cubemapped objects a shiny effect.  

2: Diffuse. Use this to give your cubemapped objects a non-shiny, realistic lighting effect.  

<a name="SetFloat"></a>**void SetFloat(Shader* material, char* name, float v1)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a float parameter to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetFloat2"></a>**void SetFloat2(Shader* material, char* name, float v1, float v2)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a float vector with 2 elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetFloat3"></a>**void SetFloat3(Shader* material, char* name, float v1, float v2, float v3)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a float vector with 3 elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetFloat4"></a>**void SetFloat4(Shader* material, char* name, float v1, float v2, float v3, float v4)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a float vector with 4 elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetInteger"></a>**void SetInteger(Shader* material, char* name, int v1)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US"></span> <span lang="en-US">an integer</span> <span lang="en-US">parameter to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetInteger2"></a>**void SetInteger2(Shader* material, char* name, int v1, int v2)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a</span><span lang="en-US">n integer</span> <span lang="en-US">vector with 2 elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetInteger3"></a>**void SetInteger3(Shader* material, char* name, int v1, int v2, int v3)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a</span><span lang="en-US">n integer</span> <span lang="en-US">vector with</span> <span lang="en-US">3</span> <span lang="en-US">elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="SetInteger4"></a>**void SetInteger4(Shader* material, char* name, int v1, int v2, int v3, int v4)**

<span lang="en-US">Set</span><span lang="en-US">s</span> <span lang="en-US">a</span><span lang="en-US">n integer</span> <span lang="en-US">vector with</span> <span lang="en-US">4</span> <span lang="en-US">elements to be used inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">.</span>

<a name="ShadeEntity"></a>**void ShadeEntity(Entity* ent, Shader* material)**

Applies a shader to an entity. A shader can be seen as a more advanced form of brush, that allows to render an object using a custom program

<a name="ShadeMesh"></a>**void ShadeMesh(Mesh* mesh, Shader* material)**

Applies a shader to a mesh, affecting all its surfaces. A shader can be seen as a more advanced form of brush, that allows to render an object using a custom program

<a name="ShadeSurface"></a>**void ShadeSurface(Surface* surf, Shader* material)**

Applies a shader to a surface. A shader can be seen as a more advanced form of brush, that allows to render an object using a custom program

<a name="ShaderFunction"></a>**void ShaderFunction(Shader* material, void (*EnableFunction)(void), void (*DisableFunction)(void))**

Sets callback functions that are executed when a shader is used. The first one _EnableFunction_ is executed when the shader is enabled, the second one _DisableFunction_ is executed when the shader is disabled.

It can be used to enable specific OpenGL parameters, for example glPolygonStipple (an old way to render transparency without using alpha blending); of course they need to be disable when the shader is disabled.

<a name="ShaderMaterial"></a>**void ShaderMaterial(Shader* material, Material* tex, char* name, int index)**

<span lang="en-US">Attaches a</span> <span lang="en-US">3d</span> <span lang="en-US">texture to a shader. Up to 255 textures can be attached. The</span> <span lang="en-US">_name_</span> <span lang="en-US">parameter allows the texture to be retrieved inside the shader program, using the same name. The</span> <span lang="en-US">_index_</span> <span lang="en-US">parameter</span> <span lang="en-US">sets to which slot the texture must be attached (never use the same slot for more than one texture in the same shader)</span>

<a name="ShaderTexture"></a>**void ShaderTexture(Shader* material, Texture* tex, char* name, int index)**

<span lang="en-US">Attaches a texture to a shader. Up to 255 textures can be attached. The</span> <span lang="en-US">_name_</span> <span lang="en-US">parameter allows the texture to be retrieved inside the shader program, using the same name. The</span> <span lang="en-US">_index_</span> <span lang="en-US">parameter</span> <span lang="en-US">sets to which slot the texture must be attached (never use the same slot for more than one texture in the same shader)</span>

<a name="ShowEntity"></a>**void ShowEntity(Entity* ent)**

Shows an entity. Very much the opposite of [HideEntity](#HideEntity).  

Once an entity has been hidden using HideEntity, use show entity to make it visible and involved in collisions again. Note that ShowEntity has no effect if the enitities parent object is hidden.  

Entities are shown by default after creating/loading them, so you should only need to use ShowEntity after using HideEntity.  

ShowEntity affects the specified entity only - child entities are not affected.

<a name="SkinMesh"></a>**void SkinMesh(Mesh* mesh, int surf_no, int vid, int bone1, float weight1=1.0, int bone2=0, float weight2=0, int bone3=0, float weight3=0, int bone4=0, float weight4=0)**

_mesh_ - mesh

_surf_no_ <span style="font-style: normal">– the number of the surface inside the mesh (not the surface handle)</span>

_vid_ <span style="font-style: normal">– number of the vertex inside the surface</span>

_bone1_ <span style="font-style: normal">– the bone number (not the bone handle) of the first bone affecting the vertex, or 0</span>

_weight1_ <span style="font-style: normal">– how much bone1 affects the vertex deformation</span>

<span lang="en-US">_bone2_</span><span lang="en-US"> <span style="font-style: normal">– the bone number (not the bone handle) of the second bone affecting the vertex, or 0</span></span>

_weight2_ <span style="font-style: normal">– how much bone2 affects the vertex deformation</span>

<span lang="en-US">_bone3_</span><span lang="en-US"> <span style="font-style: normal">– the bone number (not the bone handle) of the third bone affecting the vertex, or 0</span></span>

_weight3_ <span style="font-style: normal">– how much bone3 affects the vertex deformation</span>

<span lang="en-US">_bone4_ </span><span lang="en-US"><span style="font-style: normal">– the bone number (not the bone handle) of the fourth bone affecting the vertex, or 0</span></span>

_weight4_ <span style="font-style: normal">– how much bone4 affects the vertex deformation</span>

**Description**

Manually binds a vertex from a mesh to its bones, for skeletal animation. It can be used to build a loader for animated mesh from different format, or for procedural generation of animations.

<span lang="en-US">E</span><span lang="en-US">ach bone will have a consecutive number, depending on the order they have been created with CreateBone (the first bone created will be number 1)</span>

<a name="SpriteRenderMode"></a>**void SpriteRenderMode(Sprite* sprite,int mode)**

Sets how sprites are rendered:

1: default. Each sprite is an independent surface. It is the simplest rendering method, but also the slowest

2: batch sprites. If there are several identical sprites is is more efficient to combine all visible ones into a single surface and render it at once. Functionally, batch sprites are manipulated exactly like default ones

3: particles. This mode is generally the fastest one, although it might not be supported on some older versions of OpenGL. Particle sprites lack some functions (mainly scaling and rotation) but on the other hand they support trails

<a name="SpriteViewMode"></a>**void SpriteViewMode(Sprite* sprite,int mode)**

_sprite_ - sprite handle

_view_mode_ - view_mode of sprite

1: fixed (sprite always faces camera - default)

2: free (sprite is independent of camera)

3: upright1 (sprite always faces camera, but rolls with camera as well, unlike mode no.1)

4: upright2 (sprite always remains upright. Gives a 'billboard' effect. Good for trees, spectators etc.)

**Description**

Sets the view mode of a sprite.

The view mode determines how a sprite alters its orientation in respect to the camera. This allows the sprite to in some instances give the impression that it is more than two dimensional.

In technical terms, the four sprite modes perform the following changes:

1: Sprite changes its pitch and yaw values to face camera, but doesn't roll.

2: Sprite does not change either its pitch, yaw or roll values.

3: Sprite changes its yaw and pitch to face camera, and changes its roll value to match cameras.

4: Sprite changes its yaw value to face camera, but not its pitch value, and changes its roll value to match cameras.

Note that if you use sprite view mode 2, then because it is independent from the camera, you will only be able to see it from one side unless you use EntityFx flag 16 with it to disable backface culling.

<a name="StencilAlpha"></a>**void StencilAlpha(Stencil* stencil, float a)**

Sets the alpha level of a stencil clear operation: a lower value allows to preserve the older background

<a name="StencilClsColor"></a>**void StencilClsColor(Stencil* stencil, float r,float g,float b)**

Sets the color to use to clear the area affected by a stencil, when it is activated

<a name="StencilClsMode"></a>**void StencilClsMode(Stencil* stencil,int cls_depth,int cls_zbuffer)**

Every time a stencil is activated the area affected by it is usually deleted (color buffer and z-buffer are erased). Setting flags to 0 will keep the old data (it could be useful to achieve some strange effects, or to combine two or more renderings in one)

<a name="StencilMesh"></a>**void StencilMesh(Stencil* stencil, Mesh* mesh, int mode=1)**

<span lang="en-US">Assigns a mesh to a stencil, to be used to define the stencil shape. More meshes can be assigned to the same stencil. Meshes assigned to stencils cannot have parent entities, and cannot be rendered with RenderWorld. They are rendered with the command</span> [UseStencil](#UseStencil)<span lang="en-US">,</span> <span lang="en-US">and they affect only the stencil buffer. The parameter</span> <span lang="en-US">_mode_</span> <span lang="en-US">states how the stencil buffer is affected:</span>

1: stencil buffer is increased in the area where the mesh is rendered (the stencil will look like a “hole” shaped like the mesh)

-1: stencil buffer is decreased in the area where the mesh is rendered

2: stencil buffer is increased where the front face of the mesh are rendered, and decreased where the back faces are rendered. As result, the mesh won’t affect the stencil buffer, but the intersections between the mesh and regular 3d objects in the scene will.

-2 stencil buffer is decreased where the front face of the mesh are rendered, and increased where the back faces are rendered

<a name="StencilMode"></a>**<span lang="en-US">void StencilMode(Stencil* stencil, int m</span><span lang="en-US">ode</span><span lang="en-US">, int o</span><span lang="en-US">perator=1</span><span lang="en-US">)</span>**

_stencil_: the stencil

<span lang="en-US">_mode_</span><span lang="en-US">: the value the stencil level will be compared to</span>

<span lang="en-US">_operator_</span><span lang="en-US">:</span>

0: We Draw Only Where The Stencil Is Not Equal to _mode_

1: We Draw Only Where The Stencil Is Equal to _mode_

2: We Draw Only Where The Stencil Is Smaller or Equal to _mode_

3: We Draw Only Where The Stencil Is Greater or Equal to _mode_

**Description**

Sets the stencil operation that will be computer to decide whether to draw or not on a portion of the screen.

A stencil buffer can be seen as a 2d matrix, containing as many elements as the pixels on the screen: each element is an integer number, that is set to zero, and can be increased or decreased when a stencil mesh is rendered on it. The stencil buffer is not visible, but affects the next rendering operation, that will happen only on the “allowed” areas. The command StencilMode allows to decide which comparison must be done to decide if a certain pixel is allowed to be plot on, or not.

<a name="TerrainHeight"></a>**float TerrainHeight (Terrain* terr, int x, int z)**

Returns the height of the terrain at terrain grid coordinates _x_,_z_. The value returned is in the range 0 to 1\.

<a name="TerrainX"></a>**float TerrainX (Terrain* terr, float x, float y, float z)**

Returns the interpolated x coordinate on a terrain.

<a name="TerrainY"></a>**float TerrainY (Terrain* terr, float x, float y, float z)**

Returns the interpolated y coordinate on a terrain.

Gets the ground's height, basically.

<a name="TerrainZ"></a>**float TerrainZ (Terrain* terr, float x, float y, float z)**

Returns the interpolated z coordinate on a terrain.

<a name="TexToBuffer"></a>**void TexToBuffer(Texture* tex,unsigned char* buffer, int frame)**

Converts a texture to an image buffer. The image buffer must be allocated in advance. The image buffer will be in format RGBA (each pixel is represented by 4 bytes: red, green, blue and alpha values), and it will have the same width and height of the texture. The argument _tex_ <span style="font-style: normal">is the texture handle, the argument</span> _buffer_ <span style="font-style: normal">is a pointer to the image buffer.</span> Argument _frame_ <span style="font-style: normal">is currently unused.</span>

<a name="TextureBlend"></a>**void TextureBlend(Texture* tex,int blend)**

_Texture_ - Texture handle.

_Blend_ - Blend mode of texture.

0: Do not blend

1: No blend or Alpha (alpha when texture loaded with alpha flag - not recommended for multitexturing - see below)

2: Multiply (default)

3: Add

**Description**

Sets the blending mode for a texture.

The texture blend mode determines how the texture will blend with the texture or polygon which is 'below' it. Texture 0 will blend with the polygons of the entity it is applied to. Texture 1 will blend with texture 0\. Texture 2 will blend with texture 1\. And so on.

<span lang="en-US">Texture blending in</span> <span lang="en-US">OpenB3D</span> <span lang="en-US">effectively takes the highest order texture (the one with the highest index) and it blends with the texture below it, then that result to the texture directly below again, and so on until texture 0 which is blended with the polygons of the entity it is applied to and thus the world, depending on the EntityBlend of the object.</span>

Each of the blend modes are identical to their EntityBlend counterparts.

In the case of multitexturing (more than one texture applied to an entity), it is not recommended you blend textures that have been loaded with the alpha flag, as this can cause unpredictable results on a variety of different graphics cards.

<a name="TextureCoords"></a>**void TextureCoords(Texture* tex,int coords)**

_texture_ - name of texture

_coords_ -

0: UV coordinates are from first UV set in vertices (default)

1: UV coordinates are from second UV set in vertices

**Description**

Sets the texture coordinate mode for a texture.

This determines where the UV values used to look up a texture come from.

<a name="TextureHeight"></a>**int TextureHeight(Texture* tex)**

Returns the height of a texture.

<a name="TextureFilter"></a>**void TextureFilter(char* match_text,int flags)**

_match_text_ - text that, if found in texture filename, will activate certain filters

_flags_ - filter texture flags:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

**Description**

Adds a texture filter. Any textures loaded that contain the text specified by _match_text_ will have the provided flags added.

This is mostly of use when loading a mesh.

<a name="TextureName"></a>**const char* TextureName(Texture* tex)**

Returns a texture's filename.  

<a name="TextureWidth"></a>**int TextureWidth(Texture* tex)**

Returns the width of a texture.

<a name="TFormedX"></a>**float TFormedX()**

Returns the X component of the last [TFormPoint](#TFormPoint), [TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  

<a name="TFormedY"></a>**float TFormedY()**

Returns the Y component of the last [TFormPoint](#TFormPoint), [TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  

<a name="TFormedZ"></a>**float TFormedZ()**

Returns the Z component of the last [TFormPoint](#TFormPoint), [TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  

<a name="TFormNormal"></a>**void TFormNormal(float x,float y,float z, Entity* source_entity,Entity* dest_entity)**

_x_, _y_, _z_ = components of a vector in 3d space

_source_entity_ = handle of source entity, or 0 for 3d world

_dest_entity_ = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormNormal the new

components can be read with TFormedX(), TFormedY() and TFormedZ().

This is exactly the same as [TFormVector](#TFormVector) but with one added feature.

After the transformation the new vector is 'normalized', meaning it

is scaled to have length 1.

For example, suppose the result of TFormVector is (1,2,2).

This vector has length Sqr( 1*1 + 2*2 + 2*2 ) = Sqr( 9 ) = 3.

This means TFormNormal would produce ( 1/3, 2/3, 2/3 ).

<a name="TFormPoint"></a>**void TFormPoint(float x,float y,float z, Entity* source_entity,Entity* dest_entity)**

_x_, _y_, _z_ = coordinates of a point in 3d space

_source_entity_ = handle of source entity, or 0 for 3d world

_dest_entity_ = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormPoint the new

coordinates can be read with TFormedX(), TFormedY() and TFormedZ().

See EntityX() for details about local coordinates.

Consider a sphere built with CreateSphere(). The 'north pole' is at (0,1,0).

At first, local and global coordinates are the same. As the sphere is moved,

turned and scaled the global coordinates of the point change.

But it is always at (0,1,0) in the sphere's local space.

<a name="TFormVector"></a>**void TFormVector(float x,float y,float z, Entity* source_entity,Entity* dest_entity)**

_x_, _y_<span style="font-style: normal">,</span> _z_ = components of a vector in 3d space

_source_entity_ = handle of source entity, or 0 for 3d world

_dest_entity_ = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormVector the new

components can be read with TFormedX(), TFormedY() and TFormedZ().

See EntityX() for details about local coordinates.

Similar to TFormPoint, but operates on a vector. A vector can be thought of

as 'displacement relative to current location'.

For example, vector (1,2,3) means one step to the right, two steps up

and three steps forward.

This is analogous to PositionEntity and MoveEntity:

PositionEntity entity, x,y,z ; put entity at point (x,y,z)

MoveEntity entity, x,y,z ; add vector (x,y,z) to current position

<a name="TranslateEntity"></a>**void TranslateEntity(Entity* ent,float x,float y,float z,bool glob)**

Translates an entity relative to its current position and not its orientation.  

What this means is that an entity will move in a certain direction despite where it may be facing. Imagine that you have a game character that you want to make jump in the air at the same time as doing a triple somersault. Translating the character by a positive y amount will mean the character will always travel directly up in their air, regardless of where it may be facing due to the somersault action.  

<a name="TriangleVertex"></a>**int TriangleVertex(Surface* surf,int tri_no,int corner)**

_surface_ - surface handle

_triangle_index_ - triangle index

_corner_ - corner of triangle. Should be 0, 1 or 2.

**Description**

Returns the vertex of a triangle corner.

<a name="TriggerCloseTo"></a><span style="font-variant: small-caps">**Action* TriggerCloseTo(Entity* ent, float** </span><span style="font-variant: small-caps">**x**</span><span style="font-variant: small-caps">**, float** </span><span style="font-variant: small-caps">**y**</span><span style="font-variant: small-caps">**, float** </span><span style="font-variant: small-caps">**z**</span><span style="font-variant: small-caps">**, float** </span><span style="font-variant: small-caps">**d**</span><span style="font-variant: small-caps">**istance**</span><span style="font-variant: small-caps">**)**</span>

Creates a trigger that will activate when the distance between the entity _ent_ and the point specified by the coordinates _x_, _y_ and _z_ <span style="font-style: normal">is smaller than</span> _distance_. The check will happen each time [UpdateWorld](#UpdateWorld) is called. If the command [AppendAction](#AppendAction), is used to append some actions to the trigger, those actions will be executed as soon as the condition of the trigger is met.

<a name="TriggerCollision"></a><span style="font-variant: small-caps">**Action* TriggerCollision(Entity* ent,** </span><span style="font-variant: small-caps">**int type**</span><span style="font-variant: small-caps">**)**</span>

Creates a trigger that will activate when the a collision between the entity _ent_ and an entity of _type_ happens (see [EntityType](#EntityType)). The collision must be enabled with [Collisions](#Collisions). The check will happen each time [UpdateWorld](#UpdateWorld) is called. If the command [AppendAction](#AppendAction), is used to append some actions to the trigger, those actions will be executed as soon as the condition of the trigger is met.

<a name="TriggerDistance"></a><span style="font-variant: small-caps">**Action* Trigger**</span><span style="font-variant: small-caps">**Distance**</span><span style="font-variant: small-caps">**(Entity* ent,** </span><span style="font-variant: small-caps">**Entity* target**</span><span style="font-variant: small-caps">**, float** </span><span style="font-variant: small-caps">**d**</span><span style="font-variant: small-caps">**istance**</span><span style="font-variant: small-caps">**)**</span>

Creates a trigger that will activate when the distance between the entity _ent_ and the <span style="font-style: normal"></span> <span style="font-style: normal">entity</span> _target_ <span style="font-style: normal">is smaller than</span> _distance_. The check will happen each time [UpdateWorld](#UpdateWorld) is called. If the command [AppendAction](#AppendAction), is used to append some actions to the trigger, those actions will be executed as soon as the condition of the trigger is met.

<a name="TurnEntity"></a>**void TurnEntity(Entity* ent,float x,float y,float z,bool glob)**

_entity_ - name of entity to be rotated

_pitch_ - angle in degrees that entity will be pitched

_yaw_ - angle in degrees that entity will be yawed

_roll_ - angle in degrees that entity will be rolled

_global_ (optional) -

**Description**

Turns an entity relative to its current orientation.

_Pitch_ is the same as the x angle of an entity, and is equivalent to tilting forward/backwards.

_Yaw_ is the same as the y angle of an entity, and is equivalent to turning left/right.

_Roll_ is the same as the z angle of an entity, and is equivalent to tilting left/right.

If _global_ is 0 the rotation will be relative to the entity’s current rotation, otherwise fixed rotation axis will be used.

<a name="UpdateNormals"></a>**void UpdateNormals(Entity* ent)**

Recalculates all normals in a mesh, terrain, or geosphere. In a mesh this is necessary for correct lighting if you have not set surface normals using 'VertexNormals' commands. In a geosphere or a terrain this is necessary after a command like ModifyTerrain or ModifyGeosphere is used.

<a name="UpdateTexCoords"></a>**void UpdateTexCoords(Surface* surf)**

Recalculates the second set of texture coordinates, replacing them with 3d texture coordinates. These coordinates will work only with 3d textures (loaded with [LoadMaterial](#LoadMaterial))

<a name="UpdateWorld"></a>**void UpdateWorld(float anim_speed)**

Animates all entities in the world, and performs collision checking. It also updates particles, actions, and constraints.

The optional _anim_speed!_ parameter allows you affect the animation speed of all entities at once. A value of 1 (default) will animate entities at their usual animation speed, a value of 2 will animate entities at double their animation speed, and so on.

For best results use this command once per main loop, just before calling [RenderWorld](#RenderWorld).

<a name="UseEntity"></a>**void UseEntity(Shader* material, char* name, Entity* ent, int mode)**

<span lang="en-US">Assigns a matrix</span> <span lang="en-US">coming from a specific entity,</span> <span lang="en-US">calculated automatically by OpenB3D, to the vertex shader.</span> <span lang="en-US">A typical use is passing the matrix from a light entity.</span> <span lang="en-US">The parameter</span> <span lang="en-US">_mode_</span> <span lang="en-US">tells which matrix must be associated with</span> <span lang="en-US">_name_</span><span lang="en-US">:</span>

<span lang="en-US">0:</span> <span lang="en-US">matrix</span>

1: inverse matrix

<a name="UseFloat"></a>**void UseFloat(Shader* material, char* name, float* v1)**

<span lang="en-US">Assigns a variable of single precision to be used as a float parameter inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseFloat2"></a>**void UseFloat2(Shader* material, char* name, float* v1, float* v2)**

<span lang="en-US">Assigns</span> <span lang="en-US">two</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">of single precision to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseFloat3"></a>**void UseFloat3(Shader* material, char* name, float* v1, float* v2, float* v3)**

<span lang="en-US">Assigns</span> <span lang="en-US">three</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">of single precision to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseFloat4"></a>**void UseFloat4(Shader* material, char* name, float* v1, float* v2, float* v3, float* v4)**

<span lang="en-US">Assigns</span> <span lang="en-US">four</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">of single precision to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseInteger"></a>**void UseInteger(Shader* material, char* name, int* v1)**

<span lang="en-US">Assigns a</span><span lang="en-US">n integer</span> <span lang="en-US">variable to be used as a float parameter inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseInteger2"></a>**void UseInteger2(Shader* material, char* name, int* v1, int* v2)**

<span lang="en-US">Assigns</span> <span lang="en-US">two integer</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseInteger3"></a>**void UseInteger3(Shader* material, char* name, int* v1, int* v2, int* v3)**

<span lang="en-US">Assigns</span> <span lang="en-US">three integer</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseInteger4"></a>**void UseInteger4(Shader* material, char* name, int* v1, int* v2, int* v3, int* v4)**

<span lang="en-US">Assigns</span> <span lang="en-US">four integer</span> <span lang="en-US">variable</span><span lang="en-US">s</span> <span lang="en-US">to be used as</span> <span lang="en-US">elements of a</span> <span lang="en-US">float</span> <span lang="en-US">vector</span> <span lang="en-US">inside a shader, where it will be accessible as</span> <span lang="en-US">_name_</span><span lang="en-US">. The value of the variable will be automatically passed to the shader</span> <span lang="en-US">each time the shader is used for rendering.</span>

<a name="UseMatrix"></a>**void UseMatrix(Shader* material, char* name, int mode)**

<span lang="en-US">Assigns a matrix calculated automatically by OpenB3D to the vertex shader. The parameter</span> <span lang="en-US">_mode_</span> <span lang="en-US">tells which matrix must be associated with</span> <span lang="en-US">_name_</span><span lang="en-US">:</span>

0: model matrix (based on the object’s position, scale and rotation)

1: view matrix (based on the camera’s position and rotation)

2: projection matrix (based on camera zoom, used for perspective deformation)

3: model-view matrix (1 and 2 combined)

<a name="UseStencil"></a>**void UseStencil(Stencil* stencil)**

Activates a stencil. A stencil affects the next [RenderWorld](#RenderWorld) operation (and in general, any other opengl drawing operation), that won’t happen anymore on the whole drawable area, but only on part of it, as if a physical stencil with holes in it were placed on the canvas, to affect any painting attempts. Using 0 as argument will disable the active stencil, returning to normal mode.

Stencils should not be used on a scene that uses also shadows.

<a name="UseSurface"></a>**void UseSurface(Shader* material, char* name, Surface* surface, int vbo)**

<span lang="en-US">Tells the shader to bind the data from a surface to an attribute identified by</span> <span lang="en-US">_name_</span><span lang="en-US">.</span> <span lang="en-US">In current version, the parameter</span> <span lang="en-US">_surface_</span> <span lang="en-US"></span> <span lang="en-US">has no meaning</span><span lang="en-US">, the current surface that is being rendered will be used. The parameter</span> <span lang="en-US">_vbo_</span> <span lang="en-US">states which array has to be passed:</span>

1: vertex coordinates

2: texture mapping coordinates (first set)

3: texture mapping coordinates (second set), or 3d texture mapping coordinates on a mesh where UpdateTexCoords has been used

4: vertex normals

5: vertex color, in RGB format

6: vertex color, in RGBA format (vec4, including also alpha channel)

<a name="VectorPitch"></a>**float VectorPitch(float vx,float vy,float vz)**

Returns the pitch value of a vector.  

Using this command will return the same result as using [EntityPitch](#EntityPitch) to get the pitch value of an entity that is pointing in the vector's direction.

<a name="VectorYaw"></a>**float VectorYaw(float vx,float vy,float vz)**

Returns the yaw value of a vector.  

Using this command will return the same result as using [EntityYaw](#EntityYaw) to get the yaw value of an entity that is pointing in the vector's direction.  

<a name="VertexAlpha"></a>**float VertexAlpha(Surface* surf,int vid)**

Returns the alpha component of a vertices color, set using [VertexColor](#VertexColor)

<a name="VertexBlue"></a>**float VertexBlue(Surface* surf,int vid)**

Returns the blue component of a vertices color.

<a name="VertexColor"></a>**void VertexColor(Surface* surf,int vid,float r,float g,float b,float a)**

Sets the color of an existing vertex.  

NB. If you want to set the alpha individually for vertices using the _alpha_ parameter then you need to use EntityFX 32 (to force alpha-blending) on the entity.

<a name="VertexCoords"></a>**void VertexCoords(Surface* surf,int vid,float x,float y,float z)**

Sets the geometric coordinates of an existing vertex.  

This is the command used to perform what is commonly referred to as 'dynamic mesh deformation'. It will reposition a vertex so that all the triangle edges connected to it, will move also. This will give the effect of parts of the mesh suddenly deforming.

<a name="VertexGreen"></a>**float VertexGreen(Surface* surf,int vid)**

<span lang="en-US">Returns the</span> <span lang="en-US">green</span> <span lang="en-US">component of a vertices color.</span>

<a name="VertexNormal"></a>**void VertexNormal(Surface* surf,int vid,float nx,float ny,float nz)**

Sets the normal of an existing vertex.

<a name="VertexNX"></a>**float VertexNX(Surface* surf,int vid)**

Returns the x component of a vertices normal.

<a name="VertexNY"></a>**float VertexNY(Surface* surf,int vid)**

Returns the y component of a vertices normal.

<a name="VertexNZ"></a>**float VertexNZ(Surface* surf,int vid)**

Returns the z component of a vertices normal.

<a name="VertexRed"></a>**float VertexRed(Surface* surf,int vid)**

<span lang="en-US">Returns the</span> <span lang="en-US">red</span> <span lang="en-US">component of a vertices color.</span>

<a name="VertexTexCoords"></a>**void VertexTexCoords(Surface* surf,int vid,float u,float v,float w,int coord_set)**

_surface_ - surface handle

_index_ - index of vertex

_u_ - u coordinate of vertex

_v_ - v coordinate of vertex

_w_ (optional) - w coordinate of vertex. It is valid only in 3d texture mode

coord_set (optional) - co_oord set. Should be set to 0, 1 or 2.

**Description**

<span lang="en-US">Sets the texture coordinates of an existing vertex.</span> <span lang="en-US">Use a value of 2 for</span> <span lang="en-US">_coord_set_</span> <span lang="en-US">to specify that the coordinates are in 3d format (used only for 3d textures, loaded with LoadMaterial).</span> <span lang="en-US">Coordinates in 3d format can be used only after using</span> [UpdateTexCoords](#UpdateTexCoords) <span lang="en-US">on the mesh.</span>

<a name="VertexU"></a>**float VertexU(Surface* surf,int vid,int coord_set)**

Returns the texture u coordinate of a vertex.  

<a name="VertexV"></a>**float VertexV(Surface* surf,int vid,int coord_set)**

Returns the texture v coordinate of a vertex.  

<a name="VertexW"></a>**float VertexW(Surface* surf,int vid,int coord_set)**

Returns the texture w coordinate of a vertex. It will usually return 0, since the coordinate system used by default is 2d. If the command [UpdateTexCoords](#UpdateTexCoords) has been used on the mesh, and a value of 2 is used for _coord_set_<span style="font-style: normal">, the w coordinate is used too.</span>  

<a name="VertexX"></a>**float VertexX(Surface* surf,int vid)**

This function return the **X** coordinate of a vertex. The vertex has to be specified with _index_ variable; every surface has its own vertices, so _surface_ handle must be specified, too.

<a name="VertexY"></a>**float VertexY(Surface* surf,int vid)**

<span lang="en-US">This function return the</span> **<span lang="en-US">**Y**</span>** <span lang="en-US">coordinate of a vertex. The vertex has to be specified with</span> _<span lang="en-US">index</span>_ <span lang="en-US">variable; every surface has its own vertices, so</span> _<span lang="en-US">surface</span>_ <span lang="en-US">handle must be specified, too.</span>

<a name="VertexZ"></a>**float VertexZ(Surface* surf,int vid)**

<span lang="en-US">This function return the</span> **<span lang="en-US">**Z**</span>** <span lang="en-US">coordinate of a vertex. The vertex has to be specified with</span> _<span lang="en-US">index</span>_ <span lang="en-US">variable; every surface has its own vertices, so</span> _<span lang="en-US">surface</span>_ <span lang="en-US">handle must be specified, too.</span>

<a name="VoxelSpriteMaterial"></a>**void VoxelSpriteMaterial(VoxelSprite* voxelspr, Material* mat)**

Applies a 3d texture (loaded with [LoadMaterial](#LoadMaterial)) to a 3d sprite. The texture will be rendered as a set of voxels, so the sprite will have a solid look, that changes according to the observer’s direction.

<a name="Wireframe"></a>**void Wireframe(int enable)**

With _enable_=1, it set wireframe mode (only outlines will be visible: it's useful for debug); with _enable_=0 will set back normal mode