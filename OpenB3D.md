<div id="Section2" dir="ltr">

<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">OpenB3d
1.2</span></span></span><span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">6</span></span></span><span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">
Guide</span></span></span>

([<span style="font-variant: normal">https://sourceforge.net/projects/minib3d/files/</span>](https://sourceforge.net/projects/minib3d/files/)
)

</div>

<div id="Section1" dir="ltr" data-gutter="0" style="column-count: 2">

Global

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AmbientLight</span></span></span>](#AmbientLight)

[<span class="smallcaps">AmbientShader</span>](#AmbientShader)

[<span class="smallcaps">AntiAlias</span>](#AntiAlias)

[<span class="smallcaps">ClearWorld</span>](#ClearWorld)

[<span class="smallcaps">Graphics3D</span>](#Graphics3D)

[<span class="smallcaps">RenderWorld</span>](#RenderWorld)

[<span class="smallcaps">UpdateWorld</span>](#UpdateWorld)

[<span class="smallcaps">Wireframe</span>](#Wireframe)

Texture

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateTexture</span></span></span>](#CreateTexture)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadAnimTexture</span></span></span>](#LoadAnimTexture)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadTexture</span></span></span>](#LoadTexture)

[<span class="smallcaps">LoadMaterial</span>](#LoadMaterial)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">GetBrushTexture</span></span></span>](#GetBrushTexture)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">BackBufferToTex</span></span></span>](#BackBufferToTex)

[<span class="smallcaps">BufferToTex</span>](#BufferToTex)

[<span class="smallcaps">TexToBuffer</span>](#TexToBuffer)

[<span class="smallcaps">CameraToTex</span>](#CameraToTex)

[<span class="smallcaps">DepthBufferToTex</span>](#DepthBufferToTex)

[<span class="smallcaps">TextureFilter</span>](#TextureFilter)

[<span class="smallcaps">ClearTextureFilters</span>](#ClearTextureFilters)

[<span class="smallcaps">PositionTexture</span>](#PositionTexture)

[<span class="smallcaps">RotateTexture</span>](#RotateTexture)

[<span class="smallcaps">ScaleTexture</span>](#ScaleTexture)

[<span class="smallcaps">TextureHeight</span>](#TextureHeight)

[<span class="smallcaps">TextureWidth</span>](#TextureWidth)

[<span class="smallcaps">TextureName</span>](#TextureName)

[<span class="smallcaps">FreeTexture</span>](#FreeTexture)

[<span class="smallcaps">TextureBlend</span>](#TextureBlend)

[<span class="smallcaps">TextureCoords</span>](#TextureCoords)

[<span class="smallcaps">SetCubeFace</span>](#SetCubeFace)

[<span class="smallcaps">SetCubeMode</span>](#SetCubeMode)

Brush

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateBrush</span></span></span>](#CreateBrush)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadBrush</span></span></span>](#LoadBrush)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">BrushAlpha</span></span></span>](#BrushAlpha)

[<span class="smallcaps">BrushBlend</span>](#BrushBlend)

[<span class="smallcaps">BrushColor</span>](#BrushColor)

[<span class="smallcaps">BrushFX</span>](#BrushFX)

[<span class="smallcaps">BrushShininess</span>](#BrushShininess)

[<span class="smallcaps">BrushTexture</span>](#BrushTexture)

[<span class="smallcaps">GetEntityBrush</span>](#GetEntityBrush)

[<span class="smallcaps">GetSurfaceBrush</span>](#GetSurfaceBrush)

[<span class="smallcaps">FreeBrush</span>](#FreeBrush)

Shader

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateShader</span></span></span>](#CreateShader)

[<span class="smallcaps">CreateShaderVGF</span>](#CreateShaderVGF)

[<span class="smallcaps">LoadShader</span>](#LoadShader)

[<span class="smallcaps">LoadShaderVGF</span>](#LoadShaderVGF)

[<span class="smallcaps">F</span>](#FreeShader)[<span class="smallcaps">reeShader</span>](#FreeShader)

[<span class="smallcaps">GetShaderProgram</span>](#GetShaderProgram)

[<span class="smallcaps">SetFloat</span>](#SetFloat)<span class="smallcaps">,
</span>[<span class="smallcaps">SetFloat2</span>](#SetFloat2)<span class="smallcaps">,
</span>[<span class="smallcaps">SetFloat3</span>](#SetFloat3)<span class="smallcaps">,
</span>[<span class="smallcaps">SetFloat4</span>](#SetFloat4)

[<span class="smallcaps">SetInteger</span>](#SetInteger)<span class="smallcaps">,
</span><span class="smallcaps">[SetInteger2](#SetInteger2),
[SetInteger3](#SetInteger3)</span><span class="smallcaps">,
</span>[<span class="smallcaps">SetInteger4</span>](#SetInteger4)

[<span class="smallcaps">UseFloat</span>](#UseFloat)<span class="smallcaps">,
</span>[<span class="smallcaps">UseFloat2</span>](#UseFloat2)<span class="smallcaps">,
</span>[<span class="smallcaps">UseFloat3</span>](#UseFloat3)<span class="smallcaps">,
</span>[<span class="smallcaps">UseFloat4</span>](#UseFloat4)

[<span class="smallcaps">UseInteger</span>](#UseInteger)<span class="smallcaps">,
</span>[<span class="smallcaps">UseInteger2</span>](#UseInteger2)<span class="smallcaps">,
</span>[<span class="smallcaps">UseInteger3</span>](#UseInteger3)<span class="smallcaps">,
</span>[<span class="smallcaps">UseInteger4</span>](#UseInteger4)

[<span class="smallcaps">UseEntity</span>](#UseEntity)

[<span class="smallcaps">UseMatrix</span>](#UseMatrix)

[<span class="smallcaps">UseSurface</span>](#UseSurface)

[<span class="smallcaps">ShadeEntity</span>](#ShadeEntity)

[<span class="smallcaps">ShadeMesh</span>](#ShadeMesh)

[<span class="smallcaps">ShaderFunction</span>](#ShaderFunction)

[<span class="smallcaps">ShaderMaterial</span>](#ShaderMaterial)

[<span class="smallcaps">ShaderTexture</span>](#ShaderTexture)

[<span class="smallcaps">ShadeSurface</span>](#ShadeSurface)

Mesh

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateMesh</span></span></span>](#CreateMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadAnimMesh</span></span></span>](#LoadAnimMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadMesh</span></span></span>](#LoadMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CopyMesh</span></span></span>](#CopyMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">RepeatMesh</span></span></span>](#RepeatMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateCone</span></span></span>](#CreateCone)

[<span class="smallcaps">CreateCube</span>](#CreateCube)

[<span class="smallcaps">CreateCylinder</span>](#CreateCylinder)

[<span class="smallcaps">CreateSphere</span>](#CreateSphere)

[<span class="smallcaps">CreateQuad</span>](#CreateQuad)

[<span class="smallcaps">PaintMesh</span>](#PaintMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AddMesh</span></span></span>](#AddMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PositionMesh</span></span></span>](#PositionMesh)

[<span class="smallcaps">RotateMesh</span>](#RotateMesh)

[<span class="smallcaps">ScaleMesh</span>](#ScaleMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">MeshCSG</span></span></span>](#MeshCSG)

[<span class="smallcaps">MeshCullRadius</span>](#MeshCullRadius)

[<span class="smallcaps">CountSurfaces</span>](#CountSurfaces)

[<span class="smallcaps">CreateBone</span>](#CreateBone)

[<span class="smallcaps">SkinMesh</span>](#SkinMesh)

[<span class="smallcaps">FitMesh</span>](#FitMesh)

[<span class="smallcaps">FlipMesh</span>](#FlipMesh)

[<span class="smallcaps">UpdateNormals</span>](#UpdateNormals)

[<span class="smallcaps">UpdateTexCoords</span>](#UpdateTexCoords)

[<span class="smallcaps">MeshesIntersect</span>](#MeshesIntersect)

[<span class="smallcaps">MeshDepth</span>](#MeshDepth)

[<span class="smallcaps">MeshHeight</span>](#MeshHeight)

[<span class="smallcaps">MeshWidth</span>](#MeshWidth)

[<span class="smallcaps">GetSurface</span>](#GetSurface)

Surface

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateSurface</span></span></span>](#CreateSurface)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AddTriangle</span></span></span>](#AddTriangle)

[<span class="smallcaps">AddVertex</span>](#AddVertex)

[<span class="smallcaps">TriangleVertex</span>](#TriangleVertex)

[<span class="smallcaps">CountTriangles</span>](#CountTriangles)

[<span class="smallcaps">CountVertices</span>](#CountVertices)

[<span class="smallcaps">PaintSurface</span>](#PaintSurface)

[<span class="smallcaps">ClearSurface</span>](#ClearSurface)

[<span class="smallcaps">FindSurface</span>](#FindSurface)

[<span class="smallcaps">VertexAlpha</span>](#VertexAlpha)

[<span class="smallcaps">VertexColor</span>](#VertexColor)

[<span class="smallcaps">VertexRed</span>](#VertexRed)

[<span class="smallcaps">VertexBlue</span>](#VertexBlue)

[<span class="smallcaps">VertexGreen</span>](#VertexGreen)

[<span class="smallcaps">VertexNormal</span>](#VertexNormal)

[<span class="smallcaps">VertexNX</span>](#VertexNX)

[<span class="smallcaps">VertexNY</span>](#VertexNY)

[<span class="smallcaps">VertexNZ</span>](#VertexNZ)

[<span class="smallcaps">VertexCoords</span>](#VertexCoords)

[<span class="smallcaps">VertexX</span>](#VertexX)

[<span class="smallcaps">VertexY</span>](#VertexY)

[<span class="smallcaps">VertexZ</span>](#VertexZ)

[<span class="smallcaps">VertexTexCoords</span>](#VertexTexCoords)

[<span class="smallcaps">VertexU</span>](#VertexU)

[<span class="smallcaps">VertexV</span>](#VertexV)

[<span class="smallcaps">VertexW</span>](#VertexW)

Camera

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateCamera</span></span></span>](#CreateCamera)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CameraClsColor</span></span></span>](#CameraClsColor)

[<span class="smallcaps">CameraClsMode</span>](#CameraClsMode)

[<span class="smallcaps">CameraFogColor</span>](#CameraFogColor)

[<span class="smallcaps">CameraFogMode</span>](#CameraFogMode)

[<span class="smallcaps">CameraFogRange</span>](#CameraFogRange)

[<span class="smallcaps">CameraPick</span>](#CameraPick)

[<span class="smallcaps">CameraProject</span>](#CameraProject)

[<span class="smallcaps">ProjectedX</span>](#ProjectedX)

[<span class="smallcaps">ProjectedY</span>](#ProjectedY)

[<span class="smallcaps">ProjectedZ</span>](#ProjectedZ)

[<span class="smallcaps">CameraProjMatrix</span>](#CameraProjMatrix)

[<span class="smallcaps">CameraProjMode</span>](#CameraProjMode)

[<span class="smallcaps">CameraRange</span>](#CameraRange)

[<span class="smallcaps">CameraViewport</span>](#CameraViewport)

[<span class="smallcaps">CameraZoom</span>](#CameraZoom)

[<span class="smallcaps">EntityInView</span>](#EntityInView)

[<span class="smallcaps">PickedEntity</span>](#PickedEntity)

[<span class="smallcaps">PickedSurface</span>](#PickedSurface)

[<span class="smallcaps">PickedTriangle</span>](#PickedTriangle)

[<span class="smallcaps">PickedX</span>](#PickedX)

[<span class="smallcaps">PickedY</span>](#PickedY)

[<span class="smallcaps">PickedZ</span>](#PickedZ)

[<span class="smallcaps">PickedNX</span>](#PickedNX)

[<span class="smallcaps">PickedNY</span>](#PickedNY)

[<span class="smallcaps">PickedNZ</span>](#PickedNZ)

[<span class="smallcaps">PickedTime</span>](#PickedTime)

Light

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateLight</span></span></span>](#CreateLight)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LightColor</span></span></span>](#LightColor)

[<span class="smallcaps">LightConeAngles</span>](#LightConeAngles)

[<span class="smallcaps">LightRange</span>](#LightRange)

Pivot

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreatePivot</span></span></span>](#CreatePivot)

Sprite

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateSprite</span></span></span>](#CreateSprite)

[<span class="smallcaps">CreateVoxelSprite</span>](#CreateVoxelSprite)

[<span class="smallcaps">LoadSprite</span>](#LoadSprite)

[<span class="smallcaps">HandleSprite</span>](#HandleSprite)

[<span class="smallcaps">RotateSprite</span>](#RotateSprite)

[<span class="smallcaps">ScaleSprite</span>](#ScaleSprite)

[<span class="smallcaps">SpriteRenderMode</span>](#SpriteRenderMode)

[<span class="smallcaps">SpriteViewMode</span>](#SpriteViewMode)

[<span class="smallcaps">VoxelSpriteMaterial</span>](#VoxelSpriteMaterial)

Shadow

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateShadow</span></span></span>](#CreateShadow)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">FreeShadow</span></span></span>](#FreeShadow)

[<span class="smallcaps">ResetShadow</span>](#ResetShadow)

Plane

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreatePlane</span></span></span>](#CreatePlane)

Terrain

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateTerrain</span></span></span>](#CreateTerrain)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateGeosphere</span></span></span>](#CreateGeosphere)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadTerrain</span></span></span>](#LoadTerrain)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">LoadGeosphere</span></span></span>](#LoadGeosphere)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">GeosphereHeight</span></span></span>](#GeosphereHeight)

[<span class="smallcaps">ModifyTerrain</span>](#ModifyTerrain)

[<span class="smallcaps">ModifyGeosphere</span>](#ModifyGeosphere)

[<span class="smallcaps">TerrainHeight</span>](#TerrainHeight)

[<span class="smallcaps">TerrainX</span>](#TerrainX)

[<span class="smallcaps">TerrainY</span>](#TerrainY)

[<span class="smallcaps">TerrainZ</span>](#TerrainZ)

fluid

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateFluid</span></span></span>](#CreateFluid)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateBlob</span></span></span>](#CreateBlob)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">FluidArray</span></span></span>](#FluidArray)

[<span class="smallcaps">FluidFunction</span>](#FluidFunction)

[<span class="smallcaps">FluidThreshold</span>](#FluidThreshold)

Octree

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateOcTree</span></span></span>](#CreateOcTree)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">OctreeBlock</span></span></span>](#OctreeBlock)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">OctreeMesh</span></span></span>](#OctreeMesh)

Particle System

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateParticleEmitter</span></span></span>](#CreateParticleEmitter)

[<span class="smallcaps">EmitterParticleFunction</span>](#EmitterParticleFunction)

[<span class="smallcaps">EmitterParticleLife</span>](#EmitterParticleLife)

[<span class="smallcaps">EmitterParticleSpeed</span>](#EmitterParticleSpeed)

[<span class="smallcaps">EmitterRate</span>](#EmitterRate)

[<span class="smallcaps">EmitterVariance</span>](#EmitterVariance)

[<span class="smallcaps">EmitterVector</span>](#EmitterVector)

[<span class="smallcaps">ParticleColor</span>](#ParticleColor)

[<span class="smallcaps">ParticleTrail</span>](#ParticleTrail)

[<span class="smallcaps">ParticleVector</span>](#ParticleVector)

Entity Movement

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">MoveEntity</span></span></span>](#MoveEntity)

[<span class="smallcaps">PointEntity</span>](#PointEntity)

[<span class="smallcaps">PositionEntity</span>](#PositionEntity)

[<span class="smallcaps">TranslateEntity</span>](#TranslateEntity)

[<span class="smallcaps">RotateEntity</span>](#RotateEntity)

[<span class="smallcaps">TurnEntity</span>](#TurnEntity)

[<span class="smallcaps">ScaleEntity</span>](#ScaleEntity)

Entity Animation

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AddAnimSeq</span></span></span>](#AddAnimSeq)

[<span class="smallcaps">LoadAnimSeq</span>](#LoadAnimSeq)

[<span class="smallcaps">AnimSeq</span>](#AnimSeq)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">Animate</span></span></span>](#Animate)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AnimLength</span></span></span>](#AnimLength)

[<span class="smallcaps">AnimTime</span>](#AnimTime)

[<span class="smallcaps">Animating</span>](#Animating)

[<span class="smallcaps">SetAnimKey</span>](#SetAnimKey)

[<span class="smallcaps">SetAnimTime</span>](#SetAnimTime)

[<span class="smallcaps">ExtractAnimSeq</span>](#ExtractAnimSeq)

Entity Control

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">FreeEntity</span></span></span>](#FreeEntity)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CopyEntity</span></span></span>](#CopyEntity)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityAlpha</span></span></span>](#EntityAlpha)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityColor</span></span></span>](#EntityColor)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityShininess</span></span></span>](#EntityShininess)

[<span class="smallcaps">EntityTexture</span>](#EntityTexture)

[<span class="smallcaps">PaintEntity</span>](#PaintEntity)

[<span class="smallcaps">EntityFX</span>](#EntityFX)

[<span class="smallcaps">EntityAutoFade</span>](#EntityAutoFade)

[<span class="smallcaps">EntityBlend</span>](#EntityBlend)

[<span class="smallcaps">EntityOrder</span>](#EntityOrder)

[<span class="smallcaps">NameEntity</span>](#NameEntity)

[<span class="smallcaps">HideEntity</span>](#HideEntity)

[<span class="smallcaps">ShowEntity</span>](#ShowEntity)

[<span class="smallcaps">EntityParent</span>](#EntityParent)

[<span class="smallcaps">GetParentEntity</span>](#GetParentEntity)

[<span class="smallcaps">TFormNormal</span>](#TFormNormal)

[<span class="smallcaps">TFormPoint</span>](#TFormPoint)

[<span class="smallcaps">TFormVector</span>](#TFormVector)

[<span class="smallcaps">TFormedX</span>](#TFormedX)

[<span class="smallcaps">TFormedY</span>](#TFormedY)

[<span class="smallcaps">TFormedZ</span>](#TFormedZ)

Entity State

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CountChildren</span></span></span>](#CountChildren)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityDistance</span></span></span>](#EntityDistance)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityVisible</span></span></span>](#EntityVisible)

[<span class="smallcaps">EntityX</span>](#EntityX)

[<span class="smallcaps">EntityY</span>](#EntityY)

[<span class="smallcaps">EntityZ</span>](#EntityZ)

[<span class="smallcaps">EntityPitch</span>](#EntityPitch)

[<span class="smallcaps">EntityRoll</span>](#EntityRoll)

[<span class="smallcaps">EntityYaw</span>](#EntityYaw)

[<span class="smallcaps">EntityScaleX</span>](#EntityScaleX)

[<span class="smallcaps">EntityScaleY</span>](#EntityScaleY)

[<span class="smallcaps">EntityScaleZ</span>](#EntityScaleZ)

[<span class="smallcaps">FindChild</span>](#FindChild)

[<span class="smallcaps">GetChild</span>](#GetChild)

[<span class="smallcaps">DeltaPitch</span>](#DeltaPitch)

[<span class="smallcaps">DeltaYaw</span>](#DeltaYaw)

[<span class="smallcaps">EntityClass</span>](#EntityClass)

[<span class="smallcaps">EntityName</span>](#EntityName)

[<span class="smallcaps">EntityMatrix</span>](#EntityMatrix)

[<span class="smallcaps">EntityPick</span>](#EntityPick)

[<span class="smallcaps">LinePick</span>](#LinePick)

Entity Collision

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">EntityRadius</span></span></span>](#EntityRadius)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">ResetEntity</span></span></span>](#ResetEntity)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">Collisions</span></span></span>](#Collisions)

[<span class="smallcaps">CountCollisions</span>](#CountCollisions)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CollisionEntity</span></span></span>](#CollisionEntity)

[<span class="smallcaps">CollisionNX</span>](#CollisionNX)

[<span class="smallcaps">CollisionNY</span>](#CollisionNY)

[<span class="smallcaps">CollisionNZ</span>](#CollisionNZ)

[<span class="smallcaps">CollisionX</span>](#CollisionX)

[<span class="smallcaps">CollisionY</span>](#CollisionY)

[<span class="smallcaps">CollisionZ</span>](#CollisionZ)

[<span class="smallcaps">CollisionSurface</span>](#CollisionSurface)

[<span class="smallcaps">CollisionTriangle</span>](#CollisionTriangle)

[<span class="smallcaps">CollisionTime</span>](#CollisionTime)

[<span class="smallcaps">EntityCollided</span>](#EntityCollided)

[<span class="smallcaps">EntityBox</span>](#EntityBox)

[<span class="smallcaps">EntityType</span>](#EntityType)

[<span class="smallcaps">EntityPickMode</span>](#EntityPickMode)

[<span class="smallcaps">GetEntityType</span>](#GetEntityType)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">ClearCollisions</span></span></span>](#ClearCollisions)

Actions

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">ActFadeTo</span></span></span>](#ActFadeTo)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">ActMoveBy</span></span></span>](#ActMoveBy)

[<span class="smallcaps">ActNewtonian</span>](#ActNewtonian)

[<span class="smallcaps">ActScaleTo</span>](#ActScaleTo)

[<span class="smallcaps">ActTintTo</span>](#ActTintTo)

[<span class="smallcaps">ActTrackByDistance</span>](#ActTrackByDistance)

[<span class="smallcaps">ActTrackByPoint</span>](#ActTrackByPoint)

[<span class="smallcaps">ActTurnBy</span>](#ActTurnBy)

[<span class="smallcaps">ActTurnTo</span>](#ActTurnTo)

[<span class="smallcaps">ActVector</span>](#ActVector)

[<span class="smallcaps">AppendAction</span>](#AppendAction)

[<span class="smallcaps">FreeAction</span>](#FreeAction)

Physics

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateConstraint</span></span></span>](#CreateConstraint)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateRigidBody</span></span></span>](#CreateRigidBody)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">FreeConstraint</span></span></span>](#FreeConstraint)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">FreeRigidBody</span></span></span>](#FreeRigidBody)

Stencil

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreateStencil</span></span></span>](#CreateStencil)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">UseStencil</span></span></span>](#UseStencil)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">StencilAlpha</span></span></span>](#StencilAlpha)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">StencilClsColor</span></span></span>](#StencilClsColor)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">StencilClsMode</span></span></span>](#StencilClsMode)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">StencilMesh</span></span></span>](#StencilMesh)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">StencilMode</span></span></span>](#StencilMode)

Post Processing

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">CreatePostFX</span></span></span>](#CreatePostFX)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">AddRenderTarget</span></span></span>](#AddRenderTarget)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PostFXBuffer</span></span></span>](#PostFXBuffer)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PostFXFunction</span></span></span>](#PostFXFunction)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PostFXShader</span></span></span>](#PostFXShader)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PostFXShaderPass</span></span></span>](#PostFXShaderPass)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">PostFXTexture</span></span></span>](#PostFXTexture)

3D Maths

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">VectorPitch</span></span></span>](#VectorPitch)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">VectorYaw</span></span></span>](#VectorYaw)

[<span class="smallcaps"><span lang="en-US"><span style="font-weight: normal">GetMatElement</span></span></span>](#GetMatElement)

  

</div>

  

  

  

<span id="ActFadeTo"></span> **Action\* ActFadeTo(Entity\* entity, float
a, float rate)**

<span lang="en-US">Creates an action that will
</span><span lang="en-US">set the alpha level
of</span><span lang="en-US"> the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">to
</span><span lang="en-US">*a*</span><span lang="en-US">*.*</span><span lang="en-US">
T</span><span lang="en-US">he </span><span lang="en-US">fading
</span><span lang="en-US">will happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster
</span><span lang="en-US">change</span><span lang="en-US">), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">. </span>

More actions can be performed on the same entity at the same time.

  

<span id="ActMoveBy"></span> **Action\* ActMoveBy(Entity\* entity, float
x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected
</span><span lang="en-US">*entity*</span><span lang="en-US">. It is the
equivalent of “MoveEntity entity, x, y, z”, but the movement will happen
gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster movement), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActMoveTo"></span> **Action\* ActMoveTo(Entity\* entity, float
x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">to the
absolute coordinates</span><span lang="en-US">
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">,
</span><span lang="en-US">*z.*</span><span lang="en-US">
T</span><span lang="en-US">he movement will happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster movement), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.
</span><span lang="en-US">If the entity is moved before it reaches its
destination by other command, it will keep that in account and correct
its trajectory.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActNewtonian"></span> **<span lang="en-US">Action\*
ActNewtonian(Entity\*
ent</span><span lang="en-US">ity</span><span lang="en-US">, float
</span><span lang="en-US">percentage</span><span lang="en-US">)</span>**

<span lang="en-US">Creates an action that will move the selected
</span><span lang="en-US">*entity*</span><span lang="en-US"><span style="font-style: normal">
</span></span><span lang="en-US"><span style="font-style: normal">in the
same direction it moved the last time, simulating momentum.
</span></span><span lang="en-US"><span style="font-style: normal">At
each frame, the movement will be a
</span></span><span lang="en-US">*percentage*</span><span lang="en-US"><span style="font-style: normal">
of the last one. Note that this action won’t handle rotations or
collisions. Collisions can be handled separately, and rotations can be
achieved by applying this action to several pivots constrained together
with
</span></span>[CreateConstraint](#CreateConstraint)<span lang="en-US"><span style="font-style: normal">,
and then applying an entity controlled by them with
</span></span>[CreateRigidBody](#CreateRigidBody)<span lang="en-US"><span style="font-style: normal">.
That would allow to create a lightweight physics engine without needing
external libraries.</span></span>

This action is never completed, and will continue until it’s stopped
with [FreeAction](#FreeAction).

More actions can be performed on the same entity at the same time.

  

<span id="ActScaleTo"></span> **Action\* ActScaleTo(Entity\* entity,
float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will
</span><span lang="en-US">scale</span><span lang="en-US"> the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">to
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">,
</span><span lang="en-US">*z.*</span><span lang="en-US">
T</span><span lang="en-US">he </span><span lang="en-US">scaling
</span><span lang="en-US">will happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster
</span><span lang="en-US">scaling</span><span lang="en-US">), at the
next </span>[UpdateWorld](#UpdateWorld)<span lang="en-US">. </span>

More actions can be performed on the same entity at the same time.

  

<span id="ActTintTo"></span> **Action\* ActTintTo(Entity\* entity, float
r, float g, float b, float rate)**

<span lang="en-US">Creates an action that will
</span><span lang="en-US">set the </span><span lang="en-US">color
</span><span lang="en-US">of</span><span lang="en-US"> the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">to
</span><span lang="en-US">*r*</span><span lang="en-US"><span style="font-style: normal">,</span></span><span lang="en-US">
*g*</span><span lang="en-US"><span style="font-style: normal">,</span></span><span lang="en-US">
*b*</span><span lang="en-US">*.*</span><span lang="en-US">
T</span><span lang="en-US">he </span><span lang="en-US">change in
color</span><span lang="en-US"> </span><span lang="en-US">will happen
gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster
</span><span lang="en-US">change</span><span lang="en-US">), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">. </span>

More actions can be performed on the same entity at the same time.

  

<span id="ActTrackByDistance"></span> **Action\*
ActTrackByDistance(Entity\* entity, Entity\* target, float distance,
float rate)**

<span lang="en-US">Creates an action that will move the selected
</span><span lang="en-US">*entity*
</span><span lang="en-US">to</span><span lang="en-US">ward</span><span lang="en-US">
</span><span lang="en-US">*target*</span><span lang="en-US">
</span><span lang="en-US">until it is at the given
</span><span lang="en-US">*distance*</span><span lang="en-US">.
</span><span lang="en-US">
</span><span lang="en-US">T</span><span lang="en-US">he movement will
happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster movement), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.
</span><span lang="en-US">The entity will
</span><span lang="en-US">always point at the
</span><span lang="en-US">target entity. </span><span lang="en-US">If
the entity is moved before it reaches its destination by other command,
it will keep that in account and correct its trajectory.
</span><span lang="en-US">This action is never completed, and will
continue until it’s stopped with
</span>[FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActTrackByPoint"></span> **Action\* ActTrackByPoint(Entity\*
entity, Entity\* target, float x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will move the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">to the
coordinates</span><span lang="en-US">
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">,
</span><span lang="en-US">*z* </span><span lang="en-US">related to
</span><span lang="en-US">*target*</span><span lang="en-US">.
</span><span lang="en-US">T</span><span lang="en-US">he movement will
happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster movement), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.
</span><span lang="en-US">The entity will also attempt to turn at the
same direction that the target entity is oriented.
</span><span lang="en-US">If the entity is moved before it reaches its
destination by other command, it will keep that in account and correct
its trajectory. </span><span lang="en-US">This action is never
completed, and will continue until it’s stopped with
</span>[FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActTurnBy"></span> **Action\* ActTurnBy(Entity\* entity, float
x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will turn the selected
</span><span lang="en-US">*entity*</span><span lang="en-US">. It is the
equivalent of “TurnEntity entity, x, y, z”, but the movement will happen
gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster movement), at the next
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActTurnTo"></span> **Action\* ActTurnTo(Entity\* entity, float
x, float y, float z, float rate)**

<span lang="en-US">Creates an action that will
</span><span lang="en-US">turn </span><span lang="en-US">the selected
</span><span lang="en-US">*entity* </span><span lang="en-US">toward the
absolute coordinates</span><span lang="en-US">
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">,
</span><span lang="en-US">*z.*</span><span lang="en-US">
T</span><span lang="en-US">he </span><span lang="en-US">rotation
</span><span lang="en-US">will happen gradually, at a given
</span><span lang="en-US">*rate*</span><span lang="en-US"> (a higher
rate means a faster
</span><span lang="en-US">rotation</span><span lang="en-US">), at the
next </span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.
</span><span lang="en-US">If the entity is moved before it points at its
destination by other command, it will keep that in account and correct
its rotation.</span>

More actions can be performed on the same entity at the same time.

  

<span id="ActVector"></span> **Action\* ActVector(Entity\* entity, float
x, float y, float z)**

<span lang="en-US">Creates an action that will
</span><span lang="en-US">move</span><span lang="en-US"> the selected
</span><span lang="en-US">*entity*</span><span lang="en-US">
</span><span lang="en-US">by</span><span lang="en-US">
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">,
</span><span lang="en-US">*z*</span><span lang="en-US">
</span><span lang="en-US">at each</span><span lang="en-US">
</span>[UpdateWorld](#UpdateWorld)<span lang="en-US">.
</span><span lang="en-US">The movement is always in the world
coordinates, and is independent from the entity rotation or parent. This
action is useful to simulate wind or gravity. This action is never
completed, and will continue until it’s stopped with
</span>[FreeAction](#FreeAction)<span lang="en-US">.</span>

More actions can be performed on the same entity at the same time.

  

<span id="AddAnimSeq"></span> **int AddAnimSeq(Entity\* ent,int
length)**

Creates an animation sequence for an entity. This must be done before
any animation keys set by [SetAnimKey](#SetAnimKey) can be used in an
actual animation however this is optional. You may use it to "bake" the
frames you have added previously using SetAnimKey.  
  
Returns the animation sequence number added.

  

<span id="AddMesh"></span> **void AddMesh(Mesh\* mesh1,Mesh\* mesh2)**

Add *source\_mesh* to *dest\_mesh*. All mesh data are copied to the
destination mesh, so you can also delete the source mesh, after this
command.

The size and rotation of the entity won't apply to the mesh: so, if you
have used commands like [RotateEntity](#RotateEntity), or
[ScaleEntity](#ScaleEntity), they won't affect the copied mesh; use
[RotateMesh](#RotateMesh) and [ScaleMesh](#ScaleMesh), instead.

  

<span id="AddRenderTarget"></span> **void AddRenderTarget(PostFX\* fx,
int pass\_no, int numColBufs, bool depth, int format=8, float
scale=1.0)**

<span lang="en-US">Defines the output buffer generated by a pass,
</span><span lang="en-US">in a post processing effect
</span><span lang="en-US">*fx*</span><span lang="en-US">: it allows to
create one or more color buffers (those buffer contain the rendered
image), with different bit depth, and specifies if a separate depth
buffer is needed or not. The parameter
</span><span lang="en-US">*pass\_no*</span><span lang="en-US"> defines
which stage will create the buffers (stage 0 is the scene rendering,
stage 1 is the first shader, and so on). </span><span lang="en-US">The
parameter
</span><span lang="en-US">*numColBufs*</span><span lang="en-US"> sets
how many color buffers must be created (this is useful when using a
shader than outputs different information on different buffers: for
example, in deferred shading one buffer can contain the normal data,
another the actual colors). The parameter
</span><span lang="en-US">*depth*</span><span lang="en-US">, if true,
specifies that the depth buffer must be included, as well. The parameter
</span><span lang="en-US">*format*</span><span lang="en-US"> specifies
the bit depth (8, 16 or 32) </span><span lang="en-US">that must be used
for the buffer (higher means more video memory usage, and more precise
color rendering: usually the improved quality cannot be seen on the
monitor, but it can be useful in HDR renderings). The parameter
</span><span lang="en-US">*scale*</span><span lang="en-US"> allows to
scale the rendering (a blurring shader, for example, won’t need a full
scale buffer)</span>

  

  

<span id="AddTriangle"></span> **int AddTriangle(Surface\* surf,int
v0,int v1,int v2)**

Creates a new triangle, and adds it to *surface*; also, it returns the
triangle index number (first triangle is 0).

Parameters *v0*, *v1* and *v2* are handles to the three vertices of the
triangle: to create vertices, the command [AddVertex](#AddVertex) can be
used (it will also return the handle of the created vertex). Of course,
a vertex can also be used in more than one triangle (so, if two
triangles are adiacent, they can share one or two vertices).

Every triangle is visible only from one side (backface culling): to
render an image faster, there is generally no need to draw the polygons
on the sides of the buildings facing away from the camera; they are
completely occluded by the sides facing the camera; the order of
vertices will determine wich side will be visible; the command
[FlipMesh](#FlipMesh) will swap sides. To make a triangle visible at
both sides, the simplest solution is to create a copy of the mesh, and
flip it (it will require a double number of triangles, one for each
side).

  

<span id="AddVertex"></span> **int AddVertex(Surface\* surf,float x,
float y,float z,float u, float v,float w)**

Add a vertex to *surface*; vertex coordinates are defined by *x\!*,
*y\!* and *z\!* (floating-point parameters); if the surface has a
texture, texture mapping coordinates can be specified with the optional
parameters *u\!*, *v\!* and *w\!*.

The function will return an handle to the created vertex; this handle
can be used with the [AddTriangle](#AddTriangle) command.

  

  

<span id="AmbientLight"></span> **void AmbientLight(float r,float
g,float b)**

Sets the ambient light, that will affect every object on the scene, from
all sides.

It's possible to set a value for every color component: for example,

``` western
AmbientLight 255,0,0
```

Makes the light red; instead,

``` western
AmbientLight 0,0,0
```

will turn off the ambient light: so, unless there are other lights, the
scene will be black, and no object will be visible.

The ambient light is, by default, at 127,127,127; so, it will make
possible to see on the scene, even if there aren't other lights; anyway,
since the light comes from every side, there will be no shading, and
objects will look "flat".

  

<span id="AmbientShader"></span> **void AmbientShader(Shader\*
material)**

Sets a default shader to be used for all the entities that don’t have
their own shader attached.

  

<span id="AntiAlias"></span> **void AntiAlias(int samples)**

*samples* - true to enable fullscreen antialiasing, false to disable.
Defaults to false

  

If your OpenGL context supports multisample, this command allows to
enable it to make jagged lines and other artifacts less noticeable, at
expenses of a slower rendering speed

  

<span id="Animate"></span><span class="smallcaps">**void
Animate(Entity\* ent,int mode,float speed,int seq,int trans)**</span>

  

Animate an entity, if the entity has animation sequences.

*mode* is the mode of animation.

  - 0: stop animation

  - 1: loop animation (default)

  - 2: ping-pong animation

  - 3: one-shot animation

  - 4: manual animation (only for skeletal based animation)

*speed*: an higher value means a faster animation. A negative value
means a backward animation. Default is 1

*sequence*: set which animation sequence will be played. The same entity
can have many sequences (walk, idle, jump, swim, climb...). Default is
0.

*transition*: used to tween between an entities current position
rotation and the first frame of animation. Default is 0

  

  

<span id="Animating"></span> **int Animating(Entity\* ent)**

Returns **true** if the specified entity is currently animating.

  

<span id="AnimLength"></span> **int AnimLength(Entity\* ent)**

Returns the length of the specified entity's current animation sequence.

  

  

<span id="AnimSeq"></span> **int AnimSeq(Entity\* ent)**

Returns the specified entity's current animation sequence

  

  

<span id="AnimTime"></span> **float AnimTime(Entity\* ent)**

Returns the current animation time of an entity.

  

<span id="AppendAction"></span> **void AppendAction(Action\* first,
Action\* second)**

Appends an action to another: the *second* action will be performed only
when the *first* action has completed. Several actions can be appended
in chain: if you append action B to action A, and action C to action B,
they will be performed in sequence A → B → C.

More than one action can be appended to the same action: if you append
both action B and action C to action A, once A has completed both B and
C will start at the same time.

Appended actions don’t necessarily have to apply to the same entity of
the action that triggered them, they can apply to different entities as
well.

  

<span id="BackBufferToTex"></span> **void BackBufferToTex(Texture\*
tex,int frame)**

  

It converts the current screen back buffer (usually, the rendered image)
to a texture. The texture must be created with
[CreateTexture](#CreateTexture). If its size is smaller than the screen
size, only a portion of the screen will be copied. The argument *tex*
<span style="font-style: normal">is the texture handle. </span>Argument
*frame* <span style="font-style: normal">is currently unused. </span>

  

<span id="BrushAlpha"></span> **void BrushAlpha(Brush\* brush, float
a)**

Set the alpha level (the transparency) of a brush: *alphalevel\!* is a
floating point value, and it must be in the range from 0 (completely
transparent, invisible) to 1 (normal, no transparency at all).

  

<span id="BrushBlend"></span> **void BrushBlend(Brush\* brush,int
blend)**

Set the blending mode of a brush: *blend* value can be:

  - 1: alpha (default)

  - 2: multiply

  - 3: add

  

<span id="BrushColor"></span> **void BrushColor(Brush\* brush,float
r,float g,float b)**

Set the color of a brush: *red\!*, *green\!* and *blue\!* are floating
point values, ranging from 0 to 255, that set colour levels.

  

<span id="BrushFX"></span> **void BrushFX(Brush\* brush,int fx)**

*brush* - brush handle

*fx* -

  - 0: nothing (default)

  - 1: full-bright

  - 2: use vertex colors instead of brush color

  - 4: flatshaded

  - 8: disable fog

  - 16: disable backface culling

Sets miscellaneous effects for a brush.

Flags can be added to combine two or more effects. For example,
specifying a flag of 3 (1+2) will result in a full-bright and
vertex-coloured brush.

  

  

<span id="BrushShininess"></span> **void BrushShininess(Brush\*
brush,float s)**

Set the shininess of a brush: it means, how brighter a surface will look
when a light hits it. The value *shininess* must be in a range from 0 to
1.

  

  

<span id="BrushTexture"></span> **void BrushTexture(Brush\*
brush,Texture\* tex,int frame,int index)**

  

*brush* - brush handle  
*texture* - texture handle  
*frame* (optional) - texture frame. Defaults to 0.  
*index* (optional) - texture index. Defaults to 0.

  
  

Assigns a texture to a brush.

The optional frame parameter specifies which animation frame, if any
exist, should be assigned to the brush.

The optional index parameter specifies texture layer that the texture
should be assigned to. Brushes have up to four texture layers, 0-3
inclusive.

  

  

<span id="BufferToTex"></span> **void BufferToTex(Texture\* tex,unsigned
char\* buffer, int frame)**

  

It converts an image buffer to a texture. The texture must be created
with [CreateTexture](#CreateTexture). The image buffer must be in format
RGBA (each pixel is represented by 4 bytes: red, green, blue and alpha
values), and it must have the same width and height of the texture. The
argument *tex* <span style="font-style: normal">is the texture handle,
the argument </span>*buffer*<span style="font-style: normal"> is a
pointer to the image buffer. </span>Argument *frame*
<span style="font-style: normal">is currently unused. </span>

  

  

  

  

<span id="CameraClsColor"></span> **void CameraClsColor(Camera\* cam,
float r,float g,float b)**

Set the color that the camera will use for background; usually, it is
black (0,0,0).

  

<span id="CameraClsMode"></span> **void CameraClsMode(Camera\* cam,int
cls\_depth,int cls\_zbuffer)**

Every time an image is rendered, just before rendering the new image,
the old image is usually deleted (color buffer and z-buffer are erased).
Setting flags to 0 will keep the old data (it could be useful to achieve
some strange effects, or to combine two or more renderings in one)

  

<span id="CameraFogColor"></span> **void CameraFogColor(Camera\*
cam,float r,float g,float b)**

Set the color that the camera will use for fog: it affects all the
object that are "fading away" in the distance, but not the background
itself; usually, it is black (0,0,0).

  

<span id="CameraFogMode"></span> **void CameraFogMode(Camera\* cam,int
mode)**

  

*camera* - sets camera fog mode  
*mode* - fog mode  
0: no fog  
1: linear fog

  
  

Sets the camera fog mode.

This will enable/disable fogging, a technique used to gradually fade out
graphics the further they are away from the camera. The can be used to
avoid 'pop-up', the moment at which 3D objects suddenly appear on the
horizon.

The default fog color is black and the default fog range is 1-1000,
although these can be changed by using [CameraFogColor](#CameraFogColor)
and [CameraFogRange](#CameraFogRange) respectively.

Each camera can have its own fog mode, for multiple on-screen fog
effects.

  

  

<span id="CameraFogRange"></span> **void CameraFogRange(Camera\*
cam,float near,float far)**

Set the fog range of the camera; since the range of the camera is not
infinite, object that are outside of the range will disappear
(otherwise, the system will have too many polygons to render); the fog
allows to slowly fade an object away, giving it the same color of the
background, to avoid a sudden disappearing.

The *near\!* parameter is a floating point variable that specify the
minimum range of the fog effect; any object closer to the camera won't
be affected by fog.

The *far\!* parameter is a floating point variable that specify the
maximum range of the fog; any object that is outside this range will
have the maximum fog effect, and will have the same color of the
background (thus being invisible).

See also [CameraFogColor](#CameraFogColor), [CameraRange](#CameraRange).

  

  

<span id="CameraPick"></span> **Entity\* CameraPick(Camera\* cam,float
x,float y)**

Return the entity that is at the coordinates *x* and *y* of the viewport
(be careful: coordinates 0,0 point to the bottom left angle of the
viewport). If no entity is at the given coordinates, it returns 0.

Not all entities can be picked with this method: to make an entity
"pickable", the command [EntityPickMode](#EntityPickMode) is used.

Pitfall: if a mouse is used, mouse coordinates 0,0 refer to the top left
angle of a window: so, to get the correct *y* coordinate, you need to
use *screen\_height* - *y* (*screen\_height*, of course, is the height
of the viewport in pixels)

  

  

<span id="CameraProject"></span> **void CameraProject(Camera\* cam,float
x,float y,float z)**

Projects the world coordinates x,y,z on to the 2D screen.

  

  

<span id="CameraProjMatrix"></span> **float\* CameraProjMatrix(Camera\*
camera)**

Returns a pointer to the projection matrix of a given camera

  

  

<span id="CameraProjMode"></span> **void CameraProjMode(Camera\* cam,int
mode)**

*mode* - projection mode:

  - 0: no projection - disables camera (faster than HideEntity)

  - 1: perspective projection (default)

  - 2: orthographic projection

Description:

Sets the camera projection mode.

The projection mode is the the technique used by OpenB3D to display 3D
graphics on the screen. Using projection mode 0, nothing is displayed on
the screen, and this is the fastest method of hiding a camera. Using
camera projection mode 1, the graphics are displayed in their 'correct'
form - and this is the default mode for a camera. Camera projection mode
2 is a special type of projection, used for displaying 3D graphics on
screen, but in a 2D form - that is, no sense of perspective will be
given to the graphics. Two identical objects at varying distances from
the camera will both appear to be the same size. Orthographic projection
is useful for 3D editors, where a sense of perspective is unimportant,
and also certain games.

Use '[CameraZoom](#CameraZoom)' to control the scale of graphics
rendered with orthographic projection. As a general rule, using
orthographic projection with the default camera zoom setting of 1 will
result in graphics that are too 'zoomed-in' - changing the camera zoom
to 0.1 should fix this.

One thing to note with using camera project mode 2, is that terrains
will not be displayed correctly - this is because the level of detail
algorithm used by terrains relies on perspective in order to work
properly. Same limits apply to geospheres and isosurfaces

  

<span id="CameraRange"></span><span class="smallcaps">**void
CameraRange(Camera\* cam,float near,float far)**</span>

Sets camera range; any object with a distance from the camera lower than
*near* or higher than *far* won't be drawn; this will make rendering
faster.

  

<span id="CameraToTex"></span> **void CameraToTex(Texture\* tex,
Camera\* cam, int frame)**

Renders the output of a camera on a texture. Shadows are rendered as
well, other informations related to stencils, or to postprocessing are
ignored. The camera viewport is ignored, as well. The texture must be
created with [CreateTexture](#CreateTexture). The argument *tex*
<span style="font-style: normal">is the texture handle, the argument
</span>*cam*<span style="font-style: normal"> is the camera handle.
</span>Argument *frame* <span style="font-style: normal">is currently
unused. </span>

  

  

<span id="CameraViewport"></span> **void CameraViewport(Camera\* cam,int
x,int y,int width,int height)**

Set the camera viewport (the area of the screen where a camera image is
rendered); by default, all the screen (or window) is used.

This command allows to use only part of the screen, and so the rest of
the screen can be used to show panels, or also other camera image (i.e.
to achieve split-screen effect). Also, a smaller viewport can be used to
make a rear-view effect.

  

<span id="CameraZoom"></span><span class="smallcaps">**void
CameraZoom(Camera\* cam,float zoom)**</span>

<span lang="en-US">Set the zoom factor of a camera: default is 1. A
value lower than 1 will provide a
</span><span lang="en-US">wide</span><span lang="en-US">-</span><span lang="en-US">angle</span><span lang="en-US">
effect, a value greater than 1 will give a teleobjective effect.</span>

  

  

<span id="ClearCollisions"></span> **void ClearCollisions()**

Clears the collision information list.

Whenever you use the [Collisions](#Collisions) command to enable
collisions between two different entity types, information is added to
the collision list. This command clears that list, so that no collisions
will be detected until the Collisions command is used again.

The command will not clear entity collision information. For example,
entity radius, type etc.

  

<span id="ClearSurface"></span> **void ClearSurface(Surface\* surf,bool
clear\_verts,bool clear\_tris)**

  

*surface* - surface handle  
*clear\_verts* (optional) - true to remove all vertices from the
specified surface, false not to. Defaults to true.  
*clear\_triangles* (optional) - true to remove all triangles from the
specified surface, false not to. Defaults to true.

Description:

Removes all vertices and/or triangles from a surface.

This is useful for deleting sections of mesh. The results will be
instantly visible.

  
  

<span id="ClearTextureFilters"></span> **void ClearTextureFilters()**

Clears the current texture filter list.

  

<span id="ClearWorld"></span> **void ClearWorld(bool entities,bool
brushes,bool textures)**

  

Clears a world of all entities, brushes and/or textures.

This is useful for when a game level may have finished and you wish to
free everything up in preparation for loading new
entities/brushes/textures without having to free every
entity/brush/texture individually.

  

  

<span id="CollisionEntity"></span> **Entity\* CollisionEntity(Entity\*
ent,int index)**

Returns the other entity involved in a particular collision. Index
should be in the range 1...[CountCollisions](#CountCollisions)( entity
), inclusive.

  

<span id="Collisions"></span> **void Collisions(int src\_no,int
dest\_no,int method\_no,int response\_no)**

Enable collision detecting; every time an [UpdateWorld](#UpdateWorld)
command is performed, the library will automatically check if two or
more entities are colliding, and will react to that (so, you don't need
to check at every cycle if there are some colliding entity, the library
will do that for you)

Not all entities will be checked: only collision between entity of type
*src\_type* with entities of type *dest\_type* will be detected (since
some entities might not need to be checked for collisions, or might need
to react in a different way)

You can set the type of an entity with [EntityType](#EntityType) (the
type is a simple number: all entities of the same type will behave in
the same way): a negative type would mean that the entity has to be
checked for dynamic collisions (slower, but it works even when the
target is moving)

*method* is the collision detection method:

1: ellipsoid-to-ellipsoid collisions (fastest, but not much accurate:
you need to set ellipsoid radius with *[EntityRadius](#EntityRadius)*)

2: ellipsoid-to-polygon collisions (the most precise, but slower)

3: ellipsoid-to-box collisions (need to set box size with
*[EntityBox](#EntityBox)*)

*response* is what the source entity does when a collision occurs:

1: entity will stop

2: slide1 - full sliding collision

3: slide2 - prevent entities from sliding down slopes

  

  

<span id="CollisionNX"></span> **float CollisionNX(Entity\* ent,int
index)**

Returns the x component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

  

<span id="CollisionNY"></span> **float CollisionNY(Entity\* ent,int
index)**

Returns the y component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

  

<span id="CollisionNZ"></span> **float CollisionNZ(Entity\* ent,int
index)**

Returns the z component of the normal of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionSurface"></span> **Surface\*
CollisionSurface(Entity\* ent,int index)**

Returns the handle of the surface belonging to the specified entity that
was closest to the point of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionTime"></span> **float CollisionTime(Entity\* ent,int
index)**

Returns the time taken to calculate a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionTriangle"></span> **int CollisionTriangle(Entity\*
ent,int index)**

Returns the index number of the triangle belonging to the specified
entity that was closest to the point of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionX"></span> **float CollisionX(Entity\* ent,int
index)**

Returns the world x coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionY"></span> **float CollisionY(Entity\* ent,int
index)**

Returns the world y coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

<span id="CollisionZ"></span> **float CollisionZ(Entity\* ent,int
index)**

Returns the world z coordinate of a particular collision.

Index should be in the range 1...[CountCollisions](#CountCollisions)(
entity ) inclusive.

  

  

<span id="CopyMesh"></span> **Mesh\* CopyMesh(Mesh\* mesh,Entity\*
parent)**

Creates a copy of a mesh and returns the newly-created mesh's handle.

The difference between CopyMesh and [CopyEntity](#CopyEntity) is that
children entities are not copied (and that includes bones, or attached
entities). So, CopyMesh is not recommended for animated meshes.

CopyMesh is identical to performing new\_mesh=CreateMesh() : AddMesh
mesh,new\_mesh

  

  

<span id="CountChildren"></span> **int CountChildren(Entity\* ent)**

Returns the number of children of an entity.

  

<span id="CountCollisions"></span> **int CountCollisions(Entity\* ent)**

Returns how many collisions an entity was involved in during the last
UpdateWorld.

  

<span id="CopyEntity"></span> **Entity\* CopyEntity(Entity\*
ent,Entity\* parent)**

Creates a copy of an entity and returns the handle of the newly created
copy. Any entity (a mesh, a light, a pivot, a terrain...) can be copied.
Children entities are copied as well.

If a parent entity is specified, the copied entity will be created at
the parent entity's position. Otherwise, it will be created at 0,0,0.

  

<span id="CountSurfaces"></span> **int CountSurfaces(Mesh\* mesh)**

Returns the number of surfaces that are used in *mesh* (a mesh can have
more than one surface)

  

<span id="CountTriangles"></span> **int CountTriangles(Surface\* surf)**

Returns the number of triangles in a surface.

  

<span id="CountVertices"></span> **int CountVertices(Surface\* surf)**

<span lang="en-US">Returns the number of
</span><span lang="en-US">vertices</span><span lang="en-US"> in a
surface.</span>

  

  

<span id="CreateBlob"></span><span class="smallcaps">**Blob\*
CreateBlob(Fluid\* fluid, float radius, Entity\* parent\_ent)**</span>

<span lang="en-US">Creates a “blob”, also called a “metaball”, from a
given fluid. A blob will react only with other blobs of the same
isosurface, and it is basically </span><span lang="en-US">similar to a
sphere made of goo, that can stick to other ones and merge with them.
The size is determined by the
</span><span lang="en-US">*radius*</span><span lang="en-US">; if the
radius is negative, the blob won’t be visible, but if it is moved close
to other ones it can repel them, or appear like a hole.</span>

<span lang="en-US">B</span><span lang="en-US">lobs are useful to show
fluids, atoms and molecules, or organic-like structures. They cannot
have a color or a texture, and they will use the parameters of their
fluid entity</span>

  

<span id="CreateBone"></span> **Bone\* CreateBone(Mesh\* mesh, Entity\*
parent\_ent)**

<span lang="en-US">Creates a Bone entity, that will be used for the
animation of </span><span lang="en-US">*mesh.*
</span><span lang="en-US"><span style="font-style: normal">Bones can
later be set to affect the mesh vertices with the command
</span></span>[SkinMesh](#SkinMesh)<span lang="en-US"><span style="font-style: normal">.
</span></span>

  

<span id="CreateBrush"></span> **Brush\* CreateBrush(float r,float
g,float b)**

Creates a brush and returns a brush handle.

The optional green, red and blue values allow you to set the colour of
the brush. Values should be in the range 0-255. If omitted the values
default to 255.  
  
A brush is a collection of properties such as Colour, Alpha, Shininess,
Texture etc that are all stored as part of the brush. Then, all these
properties can be applied to an entity, mesh or surface at once just by
using [PaintEntity](#PaintEntity), [PaintMesh](#PaintMesh) or
[PaintSurface](#PaintSurface).

When creating your own mesh, if you wish for certain surfaces to look
differently from one another, then you will need to use brushes to paint
individual surfaces. Using commands such as EntityColor, EntityAlpha
will apply the effect to all surfaces at once, which may not be what you
wish to achieve.

  

<span id="CreateCamera"></span> **Camera\* CreateCamera(Entity\*
parent)**

Creates a camera entity and returns its handle.

Without at least one camera, you won't be able to see anything in your
3D world. With more than one camera, you will be to achieve effect such
as split-screen modes and rear-view mirrors.

A camera by default renders to the backbuffer. If you wish to display 3D
graphics on a texture you can use [CameraToTex](#CameraToTex).

The optional *parent* parameter allow you to specify a parent entity for
the camera so that when the parent is moved the child camera will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  
  

<span id="CreateConstraint"></span> **Constraint\*
CreateConstraint(Entity\* p1, Entity\* p2, float length)**

<span lang="en-US">It creates a bound between the entities p1 and p2,
forcing them to maintain a distance of
</span><span lang="en-US">*length*</span><span lang="en-US"> between
them. Both entities can still be moved, but the movements of one will
influence the movement of the other. An entity can have more than one
constraint, with different entities. Constraints can be very useful in
physics simulation</span>

  

  

<span id="CreateCone"></span> **Mesh\* CreateCone(int segments,bool
solid,Entity\* parent)**

*segments* (optional) - cone detail. Defaults to 8.  
*parent* (optional) - parent entity of cone  
*solid* (optional) - true for a cone with a base, false for a cone
without a base. Defaults to true.

  

**Description**

  

Creates a cone mesh/entity and returns its handle.

The cone will be centred at 0,0,0 and the base of the cone will have a
radius of 1.

The *segments* value must be in the range 3-100 inclusive.

Example segments values (solid=true):  
4: 6 polygons - a pyramid  
8: 14 polygons - bare minimum amount of polygons for a cone  
16: 30 polygons - smooth cone at medium-high distances  
32: 62 polygons - smooth cone at close distances

The optional *parent* parameter allow you to specify a parent entity for
the cone so that when the parent is moved the child cone will move with
it. However, this relationship is one way; applying movement commands to
the child will not affect the parent.

  
  

  
  

<span id="CreateCube"></span> **Mesh\* CreateCube(Entity\* parent)**

Creates a cube mesh/entity and returns its handle.

The cube will extend from -1,-1,-1 to +1,+1,+1.

The optional *parent* parameter allow you to specify a parent entity for
the cube so that when the parent is moved the child cube will move with
it. However, this relationship is one way; applying movement commands to
the child will not affect the parent.

  

  

  

<span id="CreateCylinder"></span> **Mesh\* CreateCylinder(int
segments,bool solid,Entity\* parent)**

<span lang="en-US">segments (optional) -
</span><span lang="en-US">cylinder</span><span lang="en-US"> detail.
Defaults to 8.  
parent (optional) - parent entity of cone  
solid (optional) - true for a
c</span><span lang="en-US">ylinder</span><span lang="en-US"> with a
base, false for a
</span><span lang="en-US">tube</span><span lang="en-US">. Defaults to
true.</span>

  

Description

  

Creates a cylinder mesh/entity and returns its handle.

The cylinder will be centred at 0,0,0 and will have a radius of 1.

The *segments* value must be in the range 3-100 inclusive.

Example segments values (solid=true):  
3: 8 polygons - a prism  
8: 28 polygons - bare minimum amount of polygons for a cylinder  
16: 60 polygons - smooth cylinder at medium-high distances  
32: 124 polygons - smooth cylinder at close distances

The optional *parent* parameter allow you to specify a parent entity for
the cylinder so that when the parent is moved the child cone will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  

  

<span id="CreateFluid"></span> **Fluid\* CreateFluid()**

Creates a fluid entity, or, more specifically, an isosurface.
Isosurfaces are 3d objects that are not defined by a list of triangles,
but by a 3d field, that can be based on a given array, or on a
mathematical function: the isosurface represents points of constant
value inside that field.

An application for isosurfaces is the rendering of metaballs, or blobs,
with the command [CreateBlob](#CreateBlob).

To create textured blobs, the texture, brush, or shader has to be
applied to the fluid entity, and not to the blob entity.

  

  

<span id="CreateGeosphere"></span> **Terrain\* CreateGeosphere(int size,
Entity\* parent)**

<span lang="en-US">Creates a
</span><span lang="en-US">geosphere</span><span lang="en-US">
</span><span lang="en-US">(planet) </span><span lang="en-US">entity and
returns its handle.</span>

A geosphere is a special type of polygon object that uses real-time
level of detail (LOD) to display a spherical landscape which should
theoretically consist of over millions polygons with only a few
thousand. The way it does this is by constantly rearranging a certain
amount of polygons to display high levels of detail close to the viewer
and low levels further away.

This constant rearrangement of polygons is noticeable however, and is an
well-known side-effect of all LOD landscapes. This 'pop-in' effect can
be reduced though in lots of ways, as the other terrain help files will
go on to explain.

The optional *parent* parameter allow you to specify a parent entity for
the terrain so that when the parent is moved the child terrain will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  
  

<span id="CreateMesh"></span> **Mesh\* CreateMesh(Entity\* parent)**

Create a 'blank' mesh entity and returns its handle.  
  
When a mesh is first created it has no surfaces, vertices or triangles
associated with it.  
  
To add geometry to this mesh, you will need to:  
  
CreateSurface() ; To make a surface  
AddVertex ; You will need to add at least 3 to make a Triangle  
AddTriangle ; This will add a triangle by connecting the Vertices
(points) you added to the mesh.

  

<span id="CreateLight"></span> **Light\* CreateLight(int
light\_type,Entity\* parent)**

Creates a light.

Lights work by affecting the colour of all vertices within the light's
range. You need at to create at least one light if you wish to use 3D
graphics otherwise everything will appear flat.  
  
The optional type parameter allows you to specify the type of light you
wish to create. A value of 1 creates a directional light. This works
similar to a sun shining on a house. All walls facing a certain
direction are lit the same. How much they are lit by depends on the
angle of the light reaching them.  
  
A value of 2 creates a point light. This works a little bit like a light
bulb in a house, starting from a central point and gradually fading
outwards.  
  
A value of 3 creates a spot light. This is a cone of light. This works
similar to shining a torch in a house. It starts with an inner angle of
light, and then extends towards an outer angle of light.

For a light of type 1, only direction is used to calculate the light,
while the light position is ignored. For a light of type 2, only
position is used to calculate the light, direction is ignored. A light
of type 3 is calculated using both direction and position.

A high number of light affects rendering speed. Usually 8 lights can be
supported, no more.

A light can cast shadows, although they have to be created with
CreateShadow.

The optional *parent* parameter allow you to specify a parent entity for
the light so that when the parent is moved the child light will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  

<span id="CreateOcTree"></span> **OcTree\* CreateOcTree(float width,
float height, float depth, Entity\* parent\_ent=0)**

<span lang="en-US">Creates an octree of given
</span><span lang="en-US">*width*</span><span lang="en-US">,
</span><span lang="en-US">*height*</span><span lang="en-US"> and
</span><span lang="en-US">*depth*</span><span lang="en-US">.
</span><span lang="en-US">An octree </span><span lang="en-US">allows to
manage several static entities, allowing to create complex structures
made of blocks (in a way similar to what tilemaps do in 2d graphics),
</span><span lang="en-US">and also allowing LOD (by showing smaller
blocks only when they are close enough). An octree can be imagined as a
cube subdivided in eight smaller cubes, each one subdivided again. So,
the first level will be a 2x2x2=8 blocks structure, at the second level
it will be a 4x4x4=64 blocks structure, and so on.</span>

  

<span lang="en-US">The optional
</span><span lang="en-US">*parent*</span><span lang="en-US"> parameter
allow you to specify a parent entity for the terrain so that when the
parent is moved the child terrain will move with it. However, this
relationship is one way; applying movement commands to the child will
not affect the parent.</span>

  

<span id="CreateParticleEmitter"></span> **ParticleEmitter\*
CreateParticleEmitter(Entity\* particle, Entity\* parent\_ent=0)**

Creates an emitter entity. An emitter is an entity that periodically
produces new entities of a given kind (usually particle sprites), and
launches them: those entities have a limited lifespan, then they are
automatically removed. They are produced by duplicating a given
*particle* entity: the recommended entity to be used for that is a
sprite with [SpriteRenderMode](#SpriteRenderMode) set to 3, but any kind
of entity can be used, including blobs (for water simulation) or even
other emitters (for firework effects, for example)

  

<span lang="en-US">The optional
</span><span lang="en-US">*parent*</span><span lang="en-US"> parameter
allow you to specify a parent entity for the terrain so that when the
parent is moved the child terrain will move with it. However, this
relationship is one way; applying movement commands to the child will
not affect the parent.</span>

  

<span id="CreatePivot"></span> **Pivot\* CreatePivot(Entity\* parent)**

Creates a pivot entity.  
  
A pivot entity is an invisible point in 3D space that's main use is to
act as a parent entity to other entities. The pivot can then be used to
control lots of entities at once, or act as new centre of rotation for
other entities.  
  
To enforce this relationship; use EntityParent or make use of the
optional parent entity parameter available with all entity load/creation
commands.  
  
Indeed, this parameter is also available with the CreatePivot command if
you wish for the pivot to have a parent entity itself.

  

  

<span id="CreatePlane"></span> **Mesh\* CreatePlane(int
divisions,Entity\* parent)**

<span lang="en-US">Creates a plane entity and returns its handle.  
  
A plane entity is basically a flat, infinite 'ground'. It is useful for
outdoor games where you never want the player to see/reach the edge of
the game world.  
  
The optional
</span><span lang="en-US">*div*</span><span lang="en-US">*ision*</span><span lang="en-US">*s*</span><span lang="en-US">
parameter </span><span lang="en-US">is currently
unused.</span><span lang="en-US">  
  
The
</span><span lang="en-US"><span style="font-style: normal">optional</span></span><span lang="en-US">
</span><span lang="en-US">*parent*</span><span lang="en-US"> parameter
allows you to specify a parent entity for the plane so that when the
parent is moved the child plane will move with it. However, this
relationship is one way; applying movement commands to the child will
not affect the parent.  
</span>  

<span id="CreatePostFX"></span> **PostFX\* CreatePostFX(Camera\* camera,
int passes=1)**

<span lang="en-US">Creates a post-processing effect. Post-processing
effects are a special kind of shaders that are applied on the entire
visible area, after the scene has been rendered, and not on the single
entity. They can be applied even on scene that feature entities using
custom shaders (they can also cooperate with entity shaders in some
special cases, like deferred </span><span lang="en-US">shading). They
can be used, for example, to render a scene in black and white, or to
simulate a night vision device, or a fisheye lens, and so on. </span>

<span lang="en-US">A post-processing effect works by rendering the scene
on a texture, then applying that texture to a rectangular surface as big
as the visible area, and rendering it using a custom shader. This
operation can be performed more than once, to use different shader
programs (for example, in one step colors are changed, in the next step
the image is blurred, and so on). The parameter
</span><span lang="en-US">*passes*</span><span lang="en-US"> specifies
how many steps are needed.</span>

  

<span id="CreateQuad"></span> **Mesh\* CreateQuad(Entity\* parent)**

<span lang="en-US">Creates a
</span><span lang="en-US">quad</span><span lang="en-US"> entity and
returns its handle.  
  
A </span><span lang="en-US">quad </span><span lang="en-US">entity is
basically a flat </span><span lang="en-US">square, useful for
tiles.</span><span lang="en-US">  
  
The optional
</span><span lang="en-US">*parent*</span><span lang="en-US"> parameter
allows you to specify a parent entity for the plane so that when the
parent is moved the child plane will move with it. However, this
relationship is one way; applying movement commands to the child will
not affect the parent.  
</span>  

  

<span id="CreateRigidBody"></span> **RigidBody\*
CreateRigidBody(Entity\* body, Entity\* p1, Entity\* p2, Entity\* p3,
Entity\* p4)**

<span lang="en-US">A RigidBody is a particular kind of entity: it is not
affected anymore by commands like TurnEntity, MoveEntity,
PositionEntity, RotateEntity, or ScaleEntity;
</span><span lang="en-US">its behavior is determined by the four
entities </span><span lang="en-US">*p1*</span><span lang="en-US">,
</span><span lang="en-US">*p2*</span><span lang="en-US">,
</span><span lang="en-US">*p3* </span><span lang="en-US">and
</span><span lang="en-US">*p4* </span><span lang="en-US">(usually those
entities are pivots).</span><span lang="en-US"> Its position is
determined by p1’s position, and its orientation is determined by the
other entities that will point where </span><span lang="en-US">the
forward, the top, and the right are; if the entities are not correctly
aligned, the </span><span lang="en-US">*body*</span><span lang="en-US">
entity might be deformed. For that reason, the entities used as
</span><span lang="en-US">
</span><span lang="en-US">*p1*</span><span lang="en-US">,
</span><span lang="en-US">*p2*</span><span lang="en-US">,
</span><span lang="en-US">*p3* </span><span lang="en-US">and
</span><span lang="en-US">*p4*
</span><span lang="en-US"><span style="font-style: normal">should be
connected using constraints made with
</span></span>[CreateConstraint](#CreateConstraint)<span lang="en-US"><span style="font-style: normal">,
to ensure they will always move together.</span></span>

  

Combined with constraints, CreateRigidBody allows to build a simple
physics engine

  

<span id="CreateShader"></span> **Shader\* CreateShader(char\*
ShaderName, char\* VshaderString, char\* FshaderString)**

Creates a shader. A shader is a special program that is not run on the
CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It
requires a name, and two strings containing the source codes of the two
shaders, called Vertex Shader and Fragment Shader

  

<span id="CreateShaderVGF"></span> **Shader\* CreateShaderVGF(char\*
ShaderName, char\* VshaderString, char\* GshaderString, char\*
FshaderString)**

Creates a shader. A shader is a special program that is not run on the
CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It
requires a name, and three strings containing the source codes of the
two shaders, called Vertex Shader, Geometry Shader and Fragment Shader

  

  

  

<span id="CreateShadow"></span> **ShadowObject\* CreateShadow(Mesh\*
parent, char Static)**

<span lang="en-US">Cause the
</span><span lang="en-US">*parent*</span><span lang="en-US"> mesh to
cast a shadow. The shadow is automatically calculated from the light
position, and if there is more than one light active, more shadows are
produced. The
</span><span lang="en-US">*Static*</span><span lang="en-US"><span style="font-style: normal">
parameter, if true, is used to specify that the shadow must not be
updated after its creation; normally, a shadow is updated each frame
according to light and mesh position, and to mesh animation. Static
shadows are not updated, so they should be used only for static meshes,
and only if the light is not moved as well. Rendering of a static shadow
is of course much faster.</span></span>

  

<span lang="en-US"><span style="font-style: normal">T</span></span><span lang="en-US"><span style="font-style: normal">o
render shadows, stencil buffer must be enabled. Shadows could interfere
with other stencil operations. The algorithm used (Z Fail) has some
side-effects, like the fact that shadows are rendered through objects,
as well (that issue can be fixed by ensuring that any object that
receives a shadow is a shadow caster as well). The choice of stencil
shadows allows entities that are supposed to receive a shadow to use
custom shaders with no interferences.</span></span>

  

<span id="CreateSphere"></span> **Mesh\* CreateSphere(int
segments,Entity\* parent)**

Creates a sphere mesh/entity and returns its handle.

The sphere will be centred at 0,0,0 and will have a radius of 1.

The *segments* value must be in the range 2-100 inclusive.

Example segments values:  
8: 224 polygons - bare minimum amount of polygons for a sphere  
16: 960 polygons - smooth looking sphere at medium-high distances  
32: 3968 polygons - smooth sphere at close distances

The optional *parent* parameter allow you to specify a parent entity for
the sphere so that when the parent is moved the child sphere will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  

<span id="CreateSprite"></span> **Sprite\* CreateSprite(Entity\*
parent)**

Creates a sprite entity and returns its handle.

The sprite will be positioned at 0,0,0 and extend from 1,-1 to +1,+1.

A sprite entity is a flat, square (which can be made rectangular by
scaling it) 3D object.

Sprites have two real strengths. The first is that they consist of only
two polygons; meaning you can use many of them at once. This makes them
ideal for particle effects and 2D-using-3D games where you want lots of
sprites on-screen at once.

Secondly, sprites can be assigned a view mode using
[SpriteViewMode](#SpriteViewMode). By default this view mode is set to
1, which means the sprite will always face the camera. So no matter what
the orientation of the camera is relative to the sprite, you will never
actually notice that they are flat; by giving them a spherical texture,
you can make them appear to look no different than a normal sphere.

The optional *parent* parameter allow you to specify a parent entity for
the sprite so that when the parent is moved the child sprite will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

<span id="CreateStencil"></span> **Stencil\* CreateStencil()**

<span lang="en-US">Creates a stencil: stencils are used to limit the
next rendering to only a portion of the visible area: that portion can
be shaped through one or more meshes built for that purpose. Stencils
can be useful to simulate shadows, or light spots (by rendering part of
a scene with different light conditions), </span><span lang="en-US">or
also to simulate a “portal” leading to a different place (by rendering a
different scene, viewed by a different camera, inside the
stencil)</span>

  

  

<span id="CreateSurface"></span> **Surface\* CreateSurface(Mesh\*
mesh,Brush\* brush)**

Creates a surface attached to a mesh and returns the surface's handle.

Surfaces are sections of mesh which are then used to attach triangles
to. You must have at least one surface per mesh in order to create a
visible mesh, however you can use as many as you like. Splitting a mesh
up into lots of sections allows you to affect those sections
individually, which can be a lot more useful than if all the surfaces
are combined into just one.

  

<span id="CreateTerrain"></span> **Terrain\* CreateTerrain(int size,
Entity\* parent)**

Creates a terrain entity and returns its handle.

The terrain extends from 0,0,0 to *grid\_size*,1,*grid\_size*.

A terrain is a special type of polygon object that uses real-time level
of detail (LOD) to display landscapes which should theoretically consist
of over a million polygons with only a few thousand. The way it does
this is by constantly rearranging a certain amount of polygons to
display high levels of detail close to the viewer and low levels further
away.

This constant rearrangement of polygons is noticeable however, and is an
well-known side-effect of all LOD landscapes. This 'pop-in' effect can
be reduced though in lots of ways, as the other terrain help files will
go on to explain.

The optional *parent* parameter allow you to specify a parent entity for
the terrain so that when the parent is moved the child terrain will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  

<span id="CreateTexture"></span><span class="smallcaps">**Texture\*
CreateTexture(int width,int height,int flags,int frames)**</span>

*Width* and *height* are the size of the texture. Note that the actual
texture size may be different from the width and height requested, as
different types of 3D hardware support different sizes of texture.

The optional *flags* parameter allows you to apply certain effects to
the texture. Flags can be added to combine two or more effects, e.g. 3
(1+2) = texture with color and alpha maps.

Here some more detailed descriptions of the flags:

**1**: **Color** - colour map, what you see is what you get.

**2**: **Alpha** - alpha map. If an image contains an alpha map, this
will be used to make certain areas of the texture transparent.
Otherwise, the colour map will be used as an alpha map. With alpha maps,
the dark areas always equal high-transparency, light areas equal
low-transparency.

**4**: **Masked** - all areas of a texture coloured 0,0,0 will not be
drawn to the screen.

**8**: **Mipmapped** - low detail versions of the texture will be used
at high distance. Results in a smooth, blurred look.

**16**: **Clamp u** - Any part of a texture that lies outsides the U
coordinates of 0-1 will not be drawn. Prevents texture-wrapping.

**32**: **Clamp v** - Any part of a texture that lies outsides the v
coordinates of 0-1 will not be drawn. Prevents texture-wrapping.

**64**: **Spherical environment map** - a form of environment mapping.
This works by taking a single image, and then applying it to a 3D mesh
in such a way that the image appears to be reflected. When used with a
texture that contains light sources, it can give some meshes such as a
teapot a shiny appearance.

**128**: **Cubic environment map** - a form of environment mapping. Cube
mapping is similar to spherical mapping, except it uses six images each
representing a particular 'face' of an imaginary cube, to give the
appearance of an image that perfectly reflects its surroundings.

When creating cubic environment maps with the CreateTexture command,
cubemap textures *must* be square 'power of 2' sizes. See the
SetCubeFace command for information on how to then draw to the cubemap.

When loading cubic environments maps into OpenB3D using
[LoadAnimTexture](#LoadAnimTexture), all six images relating to the six
faces of the cube must be contained within the one texture, and be laid
out in a horizontal strip in the following order - left, forward, right,
backward, up, down. The images comprising the cubemap must all be power
of two sizes.

Please note that not some older graphics cards do not support cubic
mapping.

Once you have created a texture, use [BufferToTex](#BufferToTex) to copy
an image to it. To display 3D graphics on a texture, one option is to
copy from the backbuffer to the texturebuffer, another is to directly
render the image from a camera to the texture.

  

<span id="CreateVoxelSprite"></span> **VoxelSprite\*
CreateVoxelSprite(int slices, Entity\* parent)**

Creates a voxel sprite and returns its handle.

  

A voxel sprite works more or less like a regular sprites, but it uses a
3d texture instead of a 2d one, and it is not square, but cubic. It can
be seen as a pile of different quads, each one with a different texture,
that represent a slice of the complete object. The slice parameter sets
the number of quads used.

  

<span lang="en-US">As result, the voxel sprite</span><span lang="en-US">
</span><span lang="en-US">can be turned, showing different sides, as a
true 3d object.</span>

  

The optional *parent* parameter allow you to specify a parent entity for
the terrain so that when the parent is moved the child terrain will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  

  

  

<span id="DeltaPitch"></span> **<span lang="en-US">float
DeltaPitch(Entity\* src\_entity,Entity\*
</span><span lang="en-US">dest</span><span lang="en-US">\_entity)</span>**

Returns the pitch angle, that *src\_entity* should be rotated by in
order to face *dest\_entity*.  
  
This command can be used to be point one entity at another, rotating on
the x axis only.

  

<span id="DeltaYaw"></span> **float DeltaYaw(Entity\*
src\_entity,Entity\* dest\_entity)**

<span lang="en-US">Returns the
</span><span lang="en-US">yaw</span><span lang="en-US"> angle, that
</span><span lang="en-US">*src\_entity*</span><span lang="en-US"> should
be rotated by in order to face
</span><span lang="en-US">*dest\_entity*</span><span lang="en-US">.  
  
This command can be used to be point one entity at another, rotating on
the </span><span lang="en-US">y</span><span lang="en-US"> axis only.
</span>

  

  

<span id="DepthBufferToTex"></span> **void DepthBufferToTex( Texture\*
tex, Camera\* camera=0 )**

It converts the depth buffer to a texture. If a *camera* is specified,
it will use the depth buffer of the picture rendered from that camera,
otherwise, if no camera is specified, it will use the current depth
buffer. The texture must be created with
[CreateTexture](#CreateTexture). The argument *tex*
<span style="font-style: normal">is the texture handle.</span>

  

Rendering a depth buffer to a texture (that will look like a gray scale
image) can be useful for some shaders that need that information, since
shaders by default cannot read the depth buffer directly.

  

  

<span id="EmitterVector"></span> **void EmitterVector(ParticleEmitter\*
emitter, float x, float y, float z)**

<span lang="en-US">Provides an acceleration to the particles coming from
</span><span lang="en-US">*emitter*</span><span lang="en-US">, to
simulate the effects of gravity, or of wind. The three components
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US"> and
</span><span lang="en-US">*z*</span><span lang="en-US"> of such
acceleration are added to the absolute speed of each particle at each
frame, for all the particle life.</span>

<span id="EmitterRate"></span> **void EmitterRate(ParticleEmitter\*
emitter, float r)**

Sets the frequency of emission of new particle for
*emitter*<span style="font-style: normal">. The parameter
</span>*r*<span style="font-style: normal"> is the emission rate: a
value of 1 means a new particle is emitted at each update, a lower value
means a lower rate. A value of 0 disables the emitter.</span>

  

<span id="EmitterParticleLife"></span> **void
EmitterParticleLife(ParticleEmitter\* emitter, int l)**

Sets the lifetime of particles emitted by
*emitter*<span style="font-style: normal">. The parameter
</span>*l*<span style="font-style: normal"> is the number of frames
after a particle is removed. </span>

  

<span id="EmitterParticleFunction"></span> **void
EmitterParticleFunction(ParticleEmitter\* emitter, void
(\*EmitterFunction)(Entity\*, int))**

<span lang="en-US">S</span><span lang="en-US">ets a
</span><span lang="en-US">custom </span><span lang="en-US">function that
will manage every particle produced by
</span><span lang="en-US">*emitter*</span><span lang="en-US">. must be
declared using C calling convention, and must accept an entity and an
integer number as pa</span><span lang="en-US">rameters.</span>

<span lang="en-US">T</span><span lang="en-US">he entity is the particle,
and the numeric parameter is its current lifetime: the custom function
can be used to control the fading, the orientation, the scaling factor,
and almost every other parameter, based on the particle lifetime (it
must not use static variables, since it is called for each particle).
</span>

  

  

<span id="EmitterParticleSpeed"></span> **void
EmitterParticleSpeed(ParticleEmitter\* emitter, float speed)**

Sets the *speed* of a particle, when it is produced by
*emitter*<span style="font-style: normal">. The particle will move in
the same direction of the emitter, at the given speed, that will remain
constant for all its lifetime unless it’s affected by
EmitterVector</span>

  

  

<span id="EmitterVariance"></span> **void
EmitterVariance(ParticleEmitter\* emitter, float variance)**

Set the *variance* in speed and direction of particles coming from
*emitter*. A variance of zero means that all particles will go exactly
in the same direction at the same speed. Any value greater than zero
will introduce a random change, different for each particle, in their
speed and direction, to cause them to spread more. The variation will be
random, but never greater than *variance*.

  

  

  

<span id="EntityAlpha"></span> **void EntityAlpha(Entity\* ent,float
alpha)**

Sets the entity alpha level of an entity.  
  
The *alpha* value should be in a floating point value in the range 0-1.
The default entity alpha setting is 1.  
  
The alpha level is how transparent an entity is. A value of 1 will mean
the entity is opaque. A value of 0 will mean the entity is completely
transparent, i.e. invisible. Values between 0 and 1 will cause varying
amount of transparency. This is useful for imitating the look of objects
such as glass and other translucent materials.  
  
An EntityAlpha value of 0 is especially useful as OpenB3D will not
render entities with such a value, but will still involve the entities
in collision tests. This is unlike HideEntity, which doesn't involve
entities in collisions.

  

<span id="EntityAutoFade"></span> **void EntityAutoFade(Entity\*
ent,float near,float far)**

Currently not implemented

  

<span id="EntityBlend"></span> **void EntityBlend(Entity\* ent, int
blend)**

*Blend* - Blend mode of the entity.  
1: Alpha (default)  
2: Multiply  
3: Add

  

**Description**

Sets the blending mode of an entity. This blending mode determines the
way in which the new RGBA of the pixel being rendered is combined with
the RGB of the background.  
  
To calculate the new RGBA of the pixel being rendered, the texture RGBA
for the pixel (see [TextureBlend](#TextureBlend) for more information on
how the texture RGBA is calculated) is taken, its alpha component
multiplied by the entities/brushes (where applicable) alpha value and
its color compentent multiplied by the entities/brushes colour. This is
the RGBA which will then be blended into the background pixel, and how
this is done depends on the EntityBlend value.  
  
Alpha:  
This blends the pixels according to the Alpha value. This is rougly done
to the formula:  
  
Rr = ( An \* Rn ) + ( ( 1.0 - An ) \* Ro )  
Gr = ( An \* Gn ) + ( ( 1.0 - An ) \* Go )  
Br = ( An \* Bn ) + ( ( 1.0 - An ) \* Bo )  
  
Where R = Red, G = Green, B = Blue, n = new pixel colour values, r =
resultant colour values, o = old pixel colour values.  
  
Alpha blending is the default blending mode and is used with most world
objects.  
  
Multiply:  
This blend mode will darken the underlying pixels. If you think of each
RGB value as being on a scale from 0% to 100%, where 0 = 0% and 255 =
100%, the multiply blend mode will multiply the red, green and blue
values individually together in order to get the new RGB value, roughly
according to:  
  
Rr = ( ( Rn / 255.0 ) \* ( Ro / 255.0 ) ) \* 255.0  
Gr = ( ( Gn / 255.0 ) \* ( Go / 255.0 ) ) \* 255.0  
Br = ( ( Bn / 255.0 ) \* ( Bo / 255.0 ) ) \* 255.0  
  
The alpha value has no effect with multiplicative blending. Blending a
RGB value of 255, 255, 255 will make no difference, while an RGB value
of 128, 128, 128 will darken the pixels by a factor of 2 and an RGB
value of 0, 0, 0 will completely blacken out the resultant pixels. An
RGB value of 0, 255, 255 will remove the red component of the underlying
pixel while leaving the other color values  
untouched.  
  
Multiply blending is most often used for lightmaps, shadows or anything
else that needs to 'darken' the resultant pixels.  
  
Add:  
Additive blending will add the new color values to the old, roughly
according to:  
  
Rr = ( Rn \* An ) + Ro  
Gr = ( Gn \* An ) + Go  
Br = ( Bn \* An ) + Bo  
  
The resultant RGB values are clipped out at 255, meaning that multiple
additive effects can quickly cause visible banding from smooth
gradients.  
  
Additive blending is extremely useful for effects such as laser shots
and fire.

  

  

  

<span id="EntityBox"></span> **void EntityBox(Entity\* ent,float x,float
y,float z,float width,float height,float depth)**

entity - entity handle\#

*x* - x position of entity's collision box

*y* - y position of entity's collision box

*z* - z position of entity's collision box

*width* - width of entity's collision box

*height* - height of entity's collision box

*depth* - depth of entity's collision box

  

**Description**

  

Sets the dimensions of an entity's collision box.

  

<span id="EntityClass"></span> **const char\* EntityClass(Entity\*
ent)**

Returns the class name of an entity (“Bone”, “Mesh”, “Light”...)

  

<span id="EntityCollided"></span> **Entity\* EntityCollided(Entity\*
ent,int type)**

Returns the handle of the entity of the specified *type* that collided
with the specified *entity*.

  

  

<span id="EntityColor"></span> **void EntityColor(Entity\* ent,float
red,float green,float blue)**

Set the color of an entity. The *red*, *green* and *blue* value of the
color have to be in the range 0-255; 0,0,0 is black; 255,255,255 is
white (default).

  

<span id="EntityDistance"></span> **<span lang="en-US">float
EntityDistance(Entity\* src\_entity,Entity\*
</span><span lang="en-US">dest</span><span lang="en-US">\_entity)</span>**

Returns the distance between *src\_entity* and *dest\_entity*.

  

  

<span id="EntityFX"></span> **void EntityFX(Entity\* entity,int fx)**

*entity* - entity handle

  

*fx* -

0: nothing (default)

1: full-bright

2: use vertex colors instead of brush color

4: flatshaded

8: disable fog

16: disable backface culling

32: force alpha-blending

  

**Description**

Sets miscellaneous effects for an entity.

  

Flags can be added to combine two or more effects. For example,
specifying a flag of 3 (1+2) will result in a full-bright and
vertex-coloured brush.

  

Flag 32, to force alpha-blending, must be used in order to enable vertex
alpha (see [VertexColor](#VertexColor)).

  

<span id="EntityInView"></span> **int EntityInView(Entity\* ent,Camera\*
cam)**

Returns true if the specified entity is visible to the specified
*camera*.  
  
If the entity is a mesh, its bounding box will be checked for
visibility.  
  
For all other types of entities, only their centre position will be
checked.

  

  

<span id="EntityMatrix"></span> **float\* EntityMatrix(Entity\*
entity)**

Returns a pointer to the model matrix of a given entity (if the entity
is a camera, by inverting that matrix it’s possible to get the view
matrix of that camera)

  

  

<span id="EntityName"></span> **const char\* EntityName(Entity\* ent)**

Returns the name of an entity. An entity's name may be set in a
modelling program, or manually set using [NameEntity](#NameEntity).

  

<span id="EntityOrder"></span> **void EntityOrder(Entity\* ent,int
order)**

Sets the drawing order for an entity.

An order value of 0 will mean the entity is drawn normally. A value
greater than 0 will mean that entity is drawn first, behind everything
else. A value less than 0 will mean the entity is drawn last, in front
of everything else.

Setting an entity's order to non-0 also disables z-buffering for the
entity, so should be only used for simple, convex entities like
skyboxes, sprites etc.

EntityOrder affects the specified entity but none of its child entities,
if any exist.

  

  

<span id="EntityParent"></span> **void EntityParent(Entity\*
ent,Entity\* parent\_ent,bool global)**

<span lang="en-US">*ent*</span><span lang="en-US"> - entity
handle</span>

*parent* - parent entity handle

*global* (optional) - true for the child entity to retain its global
position and orientation. Defaults to true.

**Description**

Attaches an entity to a parent.

  

Parent may be 0, in which case the entity will have no parent.

  

<span id="EntityPick"></span> **Entity\* EntityPick(Entity\* ent,float
range)**

Returns the nearest entity 'ahead' of the specified entity, within given
*range*. An entity must have a non-zero
[EntityPickMode](#EntityPickMode) to be pickable.

  

<span id="EntityPickMode"></span> **void EntityPickMode(Entity\* ent,int
pick\_mode,bool obscurer)**

Make an entity pickable (with [EntityPick](#EntityPick),
[CameraPick](#CameraPick) or [LinePick](#LinePick));

*_pick\_mode_* is the picking detection method:

1: ellipsoid picking (fastest, but not much accurate: you need to set
ellipsoid radius with *EntityRadius*)

2: polygon picking (the most precise, but slower)

3: box picking (need to set box size with *EntityBox*)

*obscurer* is an optional parameter: it is used with
[EntityVisible](#EntityVisible) to determine just what can get in the
way of the line-of-sight between 2 entities. This allows some entities
to be pickable using the other pick commands, but to be ignored (i.e.
'transparent') when using [EntityVisible](#EntityVisible)

  

  

<span id="EntityPitch"></span><span class="smallcaps">**float
EntityPitch(Entity\* ent,bool
glob**</span><span class="smallcaps">**al**</span><span class="smallcaps">**)**</span>

<span lang="en-US">Returns the pitch angle of an entity. </span>The
parameter *global,* if true, means the pitch angle returned should be
relative to 0 rather than a parent entity's pitch angle. It is false by
default.

  

The pitch angle is also the x angle of an entity.

  

<span id="EntityRadius"></span> **void EntityRadius(Entity\* ent,float
radius\_x,float radius\_y)**

Sets the radius of an entity's collision ellipsoid.  
  
An entity radius should be set for all entities involved in ellipsoidal
collisions, which is all source entities (as collisions are always
ellipsoid-to-something), and whatever destination entities are involved
in ellipsoid-to-ellipsoid collisions (collision method No.1).

  

<span lang="en-US">*radius\_y*</span><span lang="en-US">
</span><span lang="en-US">is optional, if omitted the value of
</span><span lang="en-US">*radius\_x*</span><span lang="en-US"> will be
used</span>

  

<span id="EntityRoll"></span> **float EntityRoll(Entity\* ent,bool
global)**

<span lang="en-US">Returns the
</span><span lang="en-US">roll</span><span lang="en-US"> angle of an
entity. </span>The parameter *global,* if true, means the roll angle
returned should be relative to 0 rather than a parent entity's roll
angle. It is false by default.

  

The roll angle is also the z angle of an entity.

  

<span id="EntityScaleX"></span> **float EntityScaleX(Entity\* ent,bool
glob)**

Gets the x scale factor of an entity

  

<span id="EntityScaleY"></span> **float EntityScaleY(Entity\* ent,bool
glob)**

Gets the y scale factor of an entity

  

<span id="EntityScaleZ"></span> **float EntityScaleZ(Entity\* ent,bool
glob)**

Gets the z scale factor of an entity

  

<span id="EntityShininess"></span> **void EntityShininess(Entity\*
ent,float shininess)**

Sets the specular shininess of an entity.  
  
The *shininess* value should be a floting point number in the range 0-1.
The default shininess setting is 0.  
  
Shininess is how much brighter certain areas of an object will appear to
be when a light is shone directly at them.  
  
Setting a shininess value of 1 for a medium to high poly sphere,
combined with the creation of a light shining in the direction of it,
will give it the appearance of a shiny snooker ball.

  

  

<span id="EntityTexture"></span> **void EntityTexture(Entity\*
ent,Texture\* tex,int frame,int index)**

*entity* - entity handle

*texture* - texture handle

*frame* (optional) - frame of texture. Defaults to 0.

*index* (optional) - index number of texture. Should be in the range to
0-7. Defaults to 0.

**Description**

Applies a texture to an entity.

  

The optional frame parameter specifies which texture animation frame
should be used as the texture.

  

The optional index parameter specifies which index number should be
assigned to the texture. Index numbers are used for the purpose of
multitexturing. See [TextureBlend](#TextureBlend).

  

A little note about multitexturing and slowdown. Graphics cards support
a maximum amount of textures per object, which can be used with very
little, if any, slowdown.

  

  

<span id="EntityType"></span> **void EntityType(Entity\* entity,int
collision\_type,bool recursive)**

*entity* - entity handle

*collision\_type* - collision type of entity. Must be in the range 0-99
for standard collision checking.

*recursive* (optional) - true to apply collision type to entity's
children. Defaults to false.

**Description**

Sets the collision type for an entity.

  

A collision\_type value of 0 indicates that no collision checking will
occur with that entity. A collision value of 1-99 will mean collision
checking will occur. A negative value (range -1 to -99) will work
exactly like the equivalent positive value (so, entities of type 1 and
-1 will be checked for collisions at the same time), but specifies that
the collision must be evaluated dynamically. Dynamic collisions are
slower to evaluate, but work even when the destination entity is moving.

  

  

<span id="EntityVisible"></span> **int EntityVisible(Entity\*
src\_ent,Entity\* dest\_ent)**

Returns true if src\_entity and dest\_entity can 'see' each other.

  

<span id="EntityX"></span> **float EntityX(Entity\* ent,bool global)**

<span lang="en-US">The X-coordinate of the entity.  
If the </span><span lang="en-US">*global*</span><span lang="en-US"> flag
is set to False then the parent's local coordinate system is used.  
  
NOTE: If the entity has no parent then local and global coordinates are
the same.  
In this case you can think of the 3d world as the parent.  
  
Global coordinates refer to the 3d world.
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> uses a
left-handed system:  
  
X+ is to the right  
Y+ is up  
Z+ is forward ( into the screen )  
  
Every entity also has its own Local coordinate system.  
  
The global system never changes.  
But the local system is carried along as an entity moves and turns.  
  
This same concept is used in the entity movement commands:  
  
MoveEntity entity, 0,0,1  
  
No matter what the orientation this moves one unit forward. </span>

  

<span id="EntityY"></span> **float EntityY(Entity\* ent,bool global)**

The Y-coordinate of the entity.  
If the *global* flag is set to False then the parent's local coordinate
system is used.  
  
See [EntityX](#EntityX)() for an overview of Local and Global
coordinates.

  

<span id="EntityYaw"></span> **float EntityYaw(Entity\* ent,bool glob)**

Returns the roll angle of an entity. The parameter *global,* if true,
means the roll angle returned should be relative to 0 rather than a
parent entity's roll angle. It is false by default.

  

The roll angle is also the y angle of an entity.

  

  

<span id="EntityZ"></span> **float EntityZ(Entity\* ent,bool global)**

<span lang="en-US">The
</span><span lang="en-US">Z</span><span lang="en-US">-coordinate of the
entity.  
If the </span><span lang="en-US">*global*</span><span lang="en-US"> flag
is set to False then the parent's local coordinate system is used.  
  
See </span>[EntityX](#EntityX)<span lang="en-US">() for an overview of
Local and Global coordinates.</span>

  

<span id="ExtractAnimSeq"></span> **int ExtractAnimSeq(Entity\* ent,int
first\_frame,int last\_frame,int seq)**

<span lang="en-US">On an animated mesh, it selects only a part of the
animation, that is included between
</span><span lang="en-US">*first\_frame*</span><span lang="en-US"><span style="font-style: normal">
and </span></span><span lang="en-US">*last
frame*</span><span lang="en-US"><span style="font-style: normal">, and
returns the corresponding number, that can be used with the
</span></span>[Animate](#Animate)<span lang="en-US"><span style="font-style: normal">
command. The parameter
</span></span><span lang="en-US">*seq*</span><span lang="en-US"><span style="font-style: normal">
specifies the sequence to extract from (if it’s 0, the sequence is
extracted by the whole animation)</span></span>

<span lang="en-US"><span style="font-style: normal">T</span></span><span lang="en-US"><span style="font-style: normal">his
command is useful because animated meshes often pack several different
actions in a single sequence (jumping, walking, running, and so on);
this command allows to separate them into different
sequences.</span></span>

  

<span id="FindChild"></span> **Entity\* FindChild(Entity\* ent,char\*
child\_name)**

Returns the first child of the specified entity with name matching
*child\_name*.

  

  

<span id="FindSurface"></span> **Surface\* FindSurface(Mesh\*
mesh,Brush\* brush)**

Currently unsupported

  

<span id="FitMesh"></span> **void FitMesh(Mesh\* mesh,float x,float
y,float z,float width,float height,float depth,bool uniform)**

*mesh* - mesh handle

*x* - x position of mesh

*y* - y position of mesh

*z* - z position of mesh

*width* - width of mesh

*height* - height of mesh

*depth* - depth of mesh

*uniform* (optional) - if true, the mesh will be scaled by the same
amounts in x, y and z, so will not be distorted. Defaults to false.

**Description**

Scales and translates all vertices of a mesh so that the mesh occupies
the specified box.

  

Do not use a *width*, *height* or *depth* value of 0, otherwise all mesh
data will be destroyed and your mesh will not be displayed. Use a value
of 0.001 instead for a flat mesh along one axis.

  

  

<span id="FlipMesh"></span> **void FlipMesh(Mesh\* mesh)**

*mesh* - mesh handle

Flips all the triangles in a mesh.

This is useful for a couple of reasons. Firstly though, it is important
to understand a little bit of the theory behind 3D graphics. A 3D
triangle is represented by three points; only when these points are
presented to the viewer in a clockwise-fashion is the triangle visible.
So really, triangles only have one side.

Normally, for example in the case of a sphere, a model's triangles face
the inside of the model, so it doesn't matter that you can't see them.
However, what about if you wanted to use the sphere as a huge sky for
your world, i.e. so you only needed to see the inside? In this case you
would just use FlipMesh.

Another use for FlipMesh is to make objects two-sided, so you can see
them from the inside and outside if you can't already. In this case, you
can copy the original mesh using CopyEntity, specifying the original
mesh as the parent, and flip it using FlipMesh. You will now have two
meshes occupying the same space - this will make it double-sided, but
beware, it will also double the polygon count\!

The above technique is worth trying when an external modelling program
has exported a model in such a way that some of the triangles appear to
be missing.

  

  

<span id="FluidArray"></span> **void FluidArray(Fluid\* fluid, float\*
Array, int width, int height, int depth)**

<span lang="en-US">This is an advanced function, to
</span><span lang="en-US">make an isosurface based on a custom data set.
It accepts a pointer to 3d array, of given
</span><span lang="en-US">*width*</span><span lang="en-US">,
</span><span lang="en-US">*height*</span><span lang="en-US"> and
</span><span lang="en-US">*depth*</span><span lang="en-US">.
</span><span lang="en-US">The data set must be of single precision
floating-point numbers, and it will be represented as a box of voxels,
that will be visible for values that are greater than a given threshold
(by default 0.5). Interpolation is used to provide a smoother
look.</span>

  

<span id="FluidFunction"></span> **void FluidFunction(Fluid\* fluid,
float (\*FieldFunction)(float, float, float))**

<span lang="en-US">This is an advanced function, to
</span><span lang="en-US">make an isosurface based on a custom
</span><span lang="en-US">function</span><span lang="en-US">. It accepts
a pointer to </span><span lang="en-US">a callback function, that will
accept the single precision floating-point parameters
</span><span lang="en-US">*x*</span><span lang="en-US">,
</span><span lang="en-US">*y*</span><span lang="en-US">, and
</span><span lang="en-US">*z*</span><span lang="en-US">.
</span><span lang="en-US">The function must return a single precision
floating-point value, that will be calculated according
</span><span lang="en-US">to the given coordinates. The resulting 3d
objects </span><span lang="en-US">will be visible for values that are
greater than a given threshold (by default 0.5).</span>

  

  

<span id="FluidThreshold"></span> **void FluidThreshold(Fluid\* fluid,
float threshold)**

Allows to change the threshold of a fluid object (isosurface). It will
affect the behavior of blobs, and of custom data sets or custom
functions.

  

<span id="FreeAction"></span> **void FreeAction(Action\* act)**

Terminates an action immediately. If the action has any appended
actions, they will start. If the action has not yet been executed
(because it was appended to another action), it will be skipped and any
action scheduled after it will be activated in its place.

  

<span id="FreeBrush"></span> **void FreeBrush(Brush\* brush)**

Frees up a brush

  

<span id="FreeConstraint"></span> **void FreeConstraint(Constraint\*
con)**

Frees up a constraint

  

<span id="FreeEntity"></span> **void FreeEntity(Entity\* ent)**

|                     |
| ------------------- |
| Frees up an entity. |

  

  

<span id="FreeRigidBody"></span> **void FreeRigidBody(RigidBody\*
body)**

Frees up a rigid body

  

  

<span id="FreeShadow"></span> **void FreeShadow(ShadowObject\* shad)**

Frees up a shadow

  

<span id="FreeShader"></span><span id="FreeShadow1"></span>
<span class="smallcaps"><span lang="en-US">**void
FreeShad**</span></span><span class="smallcaps"><span lang="en-US">**er**</span></span><span class="smallcaps"><span lang="en-US">**(Shad**</span></span><span class="smallcaps"><span lang="en-US">**er**</span></span><span class="smallcaps"><span lang="en-US">**\*
shad)**</span></span>

Frees up a shader

  

<span id="FreeTexture"></span> **void FreeTexture(Texture\* tex)**

Frees up a texture

  

<span id="GeosphereHeight"></span> **void GeosphereHeight(Geosphere\*
geo, float h)**

Sets the maximum height of mountains on a geosphere terrain

  

<span id="GetBrushTexture"></span> **Texture\* GetBrushTexture(Brush\*
brush,int index)**

Returns the texture that is applied to the specified brush.  
  
The optional *index* parameter allows you to specify which particular
texture you'd like returning, if there are more than one textures
applied to a brush.

  

  

<span id="GetChild"></span> **Entity\* GetChild(Entity\* ent,int
child\_no)**

Returns a child of an entity.

  

<span id="GetEntityBrush"></span> **Brush\* GetEntityBrush(Entity\*
ent)**

Returns a brush with the same properties as is applied to the specified
entity.  
  
If this command does not appear to be returning a valid brush, try using
[GetSurfaceBrush](#GetSurfaceBrush) instead with the first surface
available.  
  
Remember, GetEntityBrush actually creates a new brush so don't forget to
free it afterwards using FreeBrush to prevent memory leaks.  
  
Once you have got the brush handle from an entity, you can use
GetBrushTexture and TextureName to get the details of what texture(s)
are applied to the brush.

  

<span id="GetEntityType"></span> **int GetEntityType(Entity\* ent)**

Returns the collision type of an entity as set by the EntityType
command.  
  

<span id="GetMatElement"></span> **float GetMatElement(Entity\* ent,int
row,int col)**

unsupported

  

<span id="GetParentEntity"></span> **Entity\* GetParentEntity(Entity\*
ent)**

Returns an entity's parent

  

<span id="GetShaderProgram"></span> **int GetShaderProgram(Shader\*
material)**

Returns the number of the OpenGL program object, in case you need to
access it directly

  

<span id="GetSurface"></span> **<span lang="en-US">Surface\*
GetSurface(Mesh\* mesh,int
</span><span lang="en-US">index</span><span lang="en-US">)</span>**

<span lang="en-US">Returns the handle of the surface attached to the
specified mesh and with the specified index number.  
  
</span><span lang="en-US">*Index*</span><span lang="en-US"> should be in
the range 1...CountSurfaces( mesh ), inclusive.  
  
You need to 'get a surface', i.e. get its handle, in order to be able to
then use that particular surface with other commands.  
</span>  

<span id="GetSurfaceBrush"></span> **Brush\* GetSurfaceBrush(Surface\*
surf)**

Returns a brush with the same properties as is applied to the specified
mesh surface.  
  
If this command does not appear to be returning a valid brush, try using
[GetEntityBrush](#GetEntityBrush) instead.  
  
Remember, GetSurfaceBrush actually creates a new brush so don't forget
to free it afterwards using [FreeBrush](#FreeBrush) to prevent memory
leaks.  
  
Once you have got the brush handle from a surface, you can use
[GetBrushTexture](#GetBrushTexture) and [TextureName](#TextureName) to
get the details of what texture(s) are applied to the brush.  
  

  

<span id="Graphics3D"></span> **void Graphics3D(int width,int height,int
depth,int mode,int rate)**

Initialise the library; this command will set horizontal and vertical
resolution with *width* and *height*. Other parameters (*depth*, *mode*,
*rate*) are optional, and currently unused.

**ATTENTION**: this command **does not** create an openGL context (that
is, a place where the 3d image is rendered: it can be the full screen, a
window, or a place inside a window); you'll need to create it manually:
in FreeBasic, the simplest way to do that is with **SCREEN** command:

``` western
SCREEN 18, 32, , &h02

Graphics3d 640,480,32,1,1
```

(the \&h02 parameter in SCREEN command specify to use openGL); of
course, SCREENRES, too, can be used:

``` western
SCREENRES 640, 480, 32, , &h02  
Graphics3d 640,480,32,1,1
```

Otherwise, external libraries like GluT can be used, or system-specific
APIs can be called.

  

  

<span id="HandleSprite"></span> **void HandleSprite(Sprite\*
sprite,float h\_x,float h\_y)**

Sets a sprite handle. Defaults to 0,0.  
  
A sprite extends from -1,-1 to +1,+1. If it is scaled or rotated, the
handle is the center of rotation

  

<span id="HideEntity"></span> **void HideEntity(Entity\* ent)**

  

Hides an entity, so that it is no longer visible, and is no longer
involved in collisions. Hidden cameras won’t be used in rendering.

  
The main purpose of hide entity is to allow you to create entities at
the beginning of a program, hide them, then copy them and show as
necessary in the main game. This is more efficient than creating
entities mid-game.  
  
If you wish to hide an entity so that it is no longer visible but still
involved in collisions, then use EntityAlpha 0 instead. This will make
an entity completely transparent.  
  
HideEntity <span lang="en-US">affects the specified entity only - child
entities are not affected. </span>

  

  

<span id="LightColor"></span> **void LightColor(Light\* light,float
red,float green,float blue)**

Sets the color of a light.  
  
An r,g,b value of 255,255,255 will brighten anything the light shines
on.  
  
An r,g,b value of 0,0,0 will have no affect on anything it shines on.  
  
An r,g,b value of -255,-255,-255 will darken anything it shines on. This
is known as 'negative lighting', and is useful for shadow effects.

  

<span id="LightConeAngles"></span><span class="smallcaps">**void
LightConeAngles(Light\* light,float
inner\_ang**</span><span class="smallcaps">**le**</span><span class="smallcaps">**,float
outer\_ang**</span><span class="smallcaps">**le**</span><span class="smallcaps">**)**</span>

*light* - light handle

*inner\_angle* - inner angle of cone

*outer\_angle* - outer angle of cone

**Description**

Sets the 'cone' angle for a 'spot' light.

  

The default light cone angles setting is 0,90.

  

  

<span id="LightRange"></span> **void LightRange(Light\* light,float
range)**

Sets the range of a light.  
  
The range of a light is how far it reaches. Everything outside the range
of the light will not be affected by it.  
  
The value is very approximate, and should be experimented with for best
results.

  

<span id="LinePick"></span> **Entity\* LinePick(float x,float y,float
z,float dx,float dy,float dz,float radius)**

*x* - x coordinate of start of line pick

*y* - y coordinate of start of line pick

*z* - z coordinate of start of line pick

*dx* - distance x of line pick

*dy* - distance y of line pick

*dz* - distance z of line pick

*radius* (optional) - radius of line pick

**Description**

Returns the first entity between<span style="font-style: normal"> x,y,z
to x+d</span>x,y+dy,z+dz.

  

<span id="LoadAnimMesh"></span> **Mesh\* LoadAnimMesh(char\*
file,Entity\* parent)**

LoadAnimMesh, similar to LoadMesh, Loads a mesh from an .X, .3DS, MD2 or
.B3D file and returns a mesh handle.  
  
The difference between [LoadMesh](#LoadMesh) and LoadAnimMesh is that
any hierarchy and animation information present in the file is retained.
You can then either activate the animation by using the Animate command
or find child entities within the hierarchy by using the FindChild(),
GetChild() functions. Animation is available only in .B3D and .MD2
files, not in .3DS or .X  
  
The optional parent parameter allows you to specify a parent entity for
the mesh so that when the parent is moved the child mesh will move with
it. However, this relationship is one way; applying movement commands to
the child will not affect the parent.

  

<span id="LoadAnimSeq"></span> **int LoadAnimSeq(Entity\* ent, char\*
file)**

Appends an animation sequence from a file to an entity.

  

<span id="LoadAnimTexture"></span> **Texture\* LoadAnimTexture(char\*
file,int flags,int frame\_width,int frame\_height,int first\_frame,int
frame\_count)**

*file* - name of image file with animation frames laid out in
left-right, top-to-bottom order

  

*flags* (optional) - texture flag:

1: Color (default)

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

128: Cubic environment map

  

*frame\_width* - width of each animation frame

*frame\_height* - height of each animation frame

*first\_frame* - the first frame to be used as an animation frame

*frame\_count* - the amount of frames to be used

**Description**

Loads an animated texture from an image file and returns the texture's
handle.

  

The flags parameter allows you to apply certain effects to the texture.
Flags can be added to combine two or more effects, e.g. 3 (1+2) =
texture with colour and alpha maps.

  

See [CreateTexture](#CreateTexture) for more detailed descriptions of
the texture flags.

  

<span lang="en-US">The
</span><span lang="en-US">*frame\_width*</span><span lang="en-US">,
</span><span lang="en-US">*frame\_height*</span><span lang="en-US">,
</span><span lang="en-US">*first\_frame*</span><span lang="en-US"> and
</span><span lang="en-US">*frame\_count*</span><span lang="en-US">
parameters determine how
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> will
separate the image file into individual animation frames.</span>

  

  

<span id="LoadBrush"></span><span class="smallcaps">**Brush\*
LoadBrush(char \*file,int flags,float u\_scale,float v\_scale)**</span>

*file* - filename of texture

  

*flags* (optional) - flags can be added to combine effects:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

128: cube reflection map

  

*u\_scale* - brush u\_scale

*v\_scale* - brush v\_scale

**Description**

Creates a brush, loads and assigns a texture to it, and returns a brush
handle.

  

<span id="LoadGeosphere"></span><span class="smallcaps">**Terrain\*
LoadGeosphere(char\* file,Entity\* parent)**</span>

<span lang="en-US">Loads a </span><span lang="en-US">spherical
</span><span lang="en-US">terrain </span><span lang="en-US">(also called
planet, or geosphere) </span><span lang="en-US">from an image file and
returns the terrain's handle.  
  
The image's red channel is used to determine heights.
</span><span lang="en-US">Geosphere</span><span lang="en-US"> is
initially the </span><span lang="en-US">same size as the height
of</span><span lang="en-US"> the image.  
  
Tips on generating nice terrain:  
  
\* Smooth or blur the height map  
\* Reduce the camera range  
  
When texturing an entity, a texture with a scale of 1,1,1 (default) will
be the same size as one of the terrain's grid squares. A texture that is
scaled to the same size as the
</span><span lang="en-US">height</span><span lang="en-US"> of the bitmap
used to load it or the no. of grid square used to create it, will be the
same size as the terrain.  
  
The optional parent parameter allows you to specify a parent entity for
the terrain so that when the parent is moved the child terrain will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent. </span>

  

<span lang="en-US">A heightmaps width must be twice the height, since
equirectangular projection will be used: each horizontal unit will
correspond to one unit of longitude, each vertical unit will correspond
to one unit of latitude. Since latitude is 180° (from one pole to the
other, </span><span lang="en-US">90° north to 90°
south</span><span lang="en-US">) and longitude is 360° (equatorial
circumference, </span><span lang="en-US">from 180° east to 180°
west</span><span lang="en-US">), </span><span lang="en-US">width must be
twice the height.</span><span lang="en-US">  
</span>  

  

<span id="LoadMaterial"></span><span class="smallcaps">**Material\*
LoadMaterial(char\* filename,int flags, int frame\_width,int
frame\_height,int first\_frame,int frame\_count)**</span>

<span lang="en-US">*file*</span><span lang="en-US"> - name of image file
with </span><span lang="en-US">slices </span><span lang="en-US">laid out
in left-right, top-to-bottom order</span>

  

*flags* (optional) - texture flag:

1: Color (default)

2: Alpha

4: Masked

8: Mipmapped

  

*frame\_width* - width of each animation frame

*frame\_height* - height of each animation frame

*first\_frame* - the first frame to be used as an animation frame

*frame\_count* - the amount of frames to be used

**Description**

Loads a 3d texture from an image file and returns the texture's handle.

  

The flags parameter allows you to apply certain effects to the texture.
Flags can be added to combine two or more effects, e.g. 3 (1+2) =
texture with colour and alpha maps.

  

<span lang="en-US">The
</span><span lang="en-US">*frame\_width*</span><span lang="en-US">,
</span><span lang="en-US">*frame\_height*</span><span lang="en-US">,
</span><span lang="en-US">*first\_frame*</span><span lang="en-US"> and
</span><span lang="en-US">*frame\_count*</span><span lang="en-US">
parameters determine how
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> will
separate the image file into individual animation frames.</span>

  

  

<span id="LoadMesh"></span> **Mesh\* LoadMesh(char\* file,Entity\*
parent)**

LoadMesh, as the name suggests, Loads a mesh from an .X, .3DS or .B3D
file (Usually created in advance by one of a number of 3D model creation
packages) and returns the mesh handle.  
  
Any hierarchy and animation information in the file will be ignored. Use
[LoadAnimMesh](#LoadAnimMesh) to maintain hierarchy and animation
information.  
  
The optional parent parameter allows you to specify a parent entity for
the mesh so that when the parent is moved the child mesh will move with
it. However, this relationship is one way; applying movement commands to
the child will not affect the parent.  
  

<span id="LoadShader"></span> **Shader\* LoadShader(char\* ShaderName,
char\* VshaderFileName, char\* FshaderFileName)**

Loads a shader. A shader is a special program that is not run on the
CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It
requires a name, and two files, called Vertex Shader and Fragment Shader

  

  

<span id="LoadShaderVGF"></span> **Shader\* LoadShaderVGF(char\*
ShaderName, char\* VshaderFileName, char\* GshaderFileName, char\*
FshaderFileName)**

Loads a shader. A shader is a special program that is not run on the
CPU, but on the GPU, and it’s written in GLSL (GL Shading Language). It
requires a name, and three files, called Vertex Shader, Geometry Shader
and Fragment Shader.

  

  

<span id="LoadSprite"></span> **Sprite\* LoadSprite(char\* tex\_file,int
tex\_flag,Entity\* parent)**

*text\_file* - filename of image file to be used as sprite

  

*tex\_flag* (optional) - texture flag:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

  

*parent* - parent of entity

**Description**

Creates a sprite entity, and assigns a texture to it.

  

  

  

<span id="LoadTerrain"></span> **Terrain\* LoadTerrain(char\*
file,Entity\* parent)**

<span lang="en-US">Loads a terrain from an image file and returns the
terrain's handle.  
  
The image's red channel is used to determine heights. Terrain is
initially the same width and depth as the image, and 1 unit high.  
  
Tips on generating nice terrain:  
  
\* Smooth or blur the height map  
\* Reduce the y scale of the terrain  
\* Increase the x/z scale of the terrain  
\* Reduce the camera range  
  
When texturing an entity, a texture with a scale of 1,1,1 (default) will
be the same size as one of the terrain's grid squares. A texture that is
scaled to the same size as the size of the bitmap used to load it or the
no. of grid square used to create it, will be the same size as the
terrain.  
  
The optional parent parameter allows you to specify a parent entity for
the terrain so that when the parent is moved the child terrain will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.  
  
Specifying a parent entity will still result in the terrain being
created at position 0,0,0 rather than at the parent entity's position.  
  
A heightmaps dimensions (width and height) must be the same and
</span><span lang="en-US">should</span><span lang="en-US"> be a power of
2, e.g. 32, 64, 128, 256, 512, 1024. </span>

  

  

  

<span id="LoadTexture"></span> **Texture\* LoadTexture(char\* file,int
flags)**

Load a texture from an image file and returns the texture's handle.
Supported file formats include: BMP, PNG, TGA and JPG. Only PNG and TGA
support alpha.

The optional flags parameter allows you to apply certain effects to the
texture. Flags can be added to combine two or more effects, e.g. 3 (1+2)
= texture with colour and alpha maps.

See [CreateTexture](#CreateTexture) for more detailed descriptions of
the texture flags.

Something to consider when applying texture flags to loaded textures is
that the texture may have already had certain flags applied to it via
the [TextureFilter](#TextureFilter) command. The default for the
[TextureFilter](#TextureFilter) command is 9 (1+8), which is a coloured,
mipmapped texture. This cannot be overridden via the flags parameter of
the LoadTexture command - if you wish for the filters to be removed you
will need to use the [ClearTextureFilters](#ClearTextureFilters)
command, which must be done after setting the graphics mode (setting the
graphics mode restores the default texture filters).

  

<span id="MeshCSG"></span> **Mesh\* MeshCSG(Mesh\* m1, Mesh\* m2, int
method = 1)**

*m1* first mesh

*m2* second mesh

*method* CSG operation:

0: subtraction

1: union

2: intersection

  

**Description**

Creates a new mesh by performing a CSG (Constructive Solid Geometry)
operation on two given meshes *m1* and *m2*. Those meshes are not
modified, and might need to be removed with FreeEntity at the end of the
CSG operations.

  

<span lang="en-US">The
</span><span lang="en-US">*method*</span><span lang="en-US"> parameter
specifies which CSG operation must be performed: a subtraction removes
the second mesh from the first, basically creating a hole inside m1,
shaped like m2; an union combines the two meshes into one, removing all
the superfluous geometry: in that, it differs from AddMesh, that
includes also the intersecting parts of meshes, that should never be
visible anyway </span><span lang="en-US">(</span><span lang="en-US">if
you use this operation to add many boxes and cylinders, then you flip
the result with FlipMesh, you will get a set of
corridors/dungeon</span><span lang="en-US">)</span><span lang="en-US">;
an intersection creates a mesh that is made only by the intersecting
parts of </span><span lang="en-US">*m1*</span><span lang="en-US"> and
</span><span lang="en-US">*m2*</span><span lang="en-US"> (the
intersection of two spheres can be used to produce a lens shaped mesh,
for example)</span>

  

<span id="MeshCullRadius"></span> **void MeshCullRadius(Entity\* ent,
float radius)**

<span lang="en-US">This command is the equivalent of
</span><span lang="en-US">Blitz</span><span lang="en-US">3D's
MeshCullBox command. </span>

It is used to set the radius of a mesh's 'cull sphere' - if the 'cull
sphere' is not inside the viewing area, the mesh will not be rendered.

A mesh's cull radius is set automatically, therefore in most cases you
will not have to use this command.

One time you may have to use it is for animated meshes where the default
cull radius may not take into account all animation positions, resulting
in the mesh being wrongly culled at extreme positions.

  

  

<span id="MeshDepth"></span><span class="smallcaps">**float
MeshDepth(Mesh\* mesh)**</span>

Returns the depth of a mesh. This is calculated by the actual vertex
positions and so the scale of the entity (set by ScaleEntity) will not
have an effect on the resultant depth. Mesh operations, on the other
hand, will effect the result.  
  

<span id="MeshesIntersect"></span> **int MeshesIntersect(Mesh\*
mesh1,Mesh\* mesh2)**

<span lang="en-US">Returns true if the specified meshes are currently
intersecting.  
  
This is a fairly slow routine - use with discretion...  
  
This command is currently the only polygon-\>polygon collision checking
routine available in
</span><span lang="en-US">OpenB3D</span><span lang="en-US">. </span>

  

<span id="MeshHeight"></span><span class="smallcaps">**float
MeshHeight(Mesh\* mesh)**</span>

<span lang="en-US">Returns the
</span><span lang="en-US">height</span><span lang="en-US"> of a mesh.
This is calculated by the actual vertex positions and so the scale of
the entity (set by ScaleEntity) will not have an effect on the resultant
</span><span lang="en-US">height</span><span lang="en-US">. Mesh
operations, on the other hand, will effect the result.  
</span>  

<span id="MeshWidth"></span> **float MeshWidth(Mesh\* mesh)**

<span lang="en-US">Returns the
</span><span lang="en-US">width</span><span lang="en-US"> of a mesh.
This is calculated by the actual vertex positions and so the scale of
the entity (set by ScaleEntity) will not have an effect on the resultant
</span><span lang="en-US">width</span><span lang="en-US">. Mesh
operations, on the other hand, will effect the result.  
</span>  

  

<span id="ModifyGeosphere"></span> **void ModifyGeosphere(Geosphere\*
geo, int x, int z, float new\_height)**

<span lang="en-US">Sets the height of a point on a
</span><span lang="en-US">geosphere</span><span lang="en-US">. </span>

  

  

<span id="ModifyTerrain"></span> **void ModifyTerrain(Terrain\* terr,
int x, int z, float new\_height)**

Sets the height of a point on a terrain.

  

<span id="MoveEntity"></span> **void MoveEntity(Entity\* ent,float
x,float y,float z)**

<span lang="en-US">Moves an entity relative to its current position and
orientation.  
  
What this means is that an entity will move in whatever direction it is
facing. So for example if you have an game character is upright when
first loaded into
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> and it
remains upright (i.e. turns left or right only), then moving it by a z
amount will always see it move forward or backward, moving it by a y
amount will always see it move up or down, and moving it by an x amount
will always see it strafe.</span>

  

  

<span id="NameEntity"></span> **void NameEntity(Entity\* ent,char\*
name)**

Sets an entity's name.

  

<span id="OctreeBlock"></span> **void OctreeBlock(OcTree\* octree,
Mesh\* mesh, int level, float X, float Y, float Z, float Near=0.0, float
Far=1000.0)**

Adds a block to an octree, shaped like a given *mesh*. The size of the
mesh should fit between -1,-1,-1 and 1,1,1. A block is supposed to be
used to set the "bricks", to create more complex levels.

<span lang="en-US">An octree can be imagined as a cube subdivided in
eight smaller cubes, each one subdivided again. So, the first level will
be a 2x2x2=8 </span><span lang="en-US">cubes</span><span lang="en-US">
structure, at the second level it will be a 4x4x4=64
</span><span lang="en-US">cubes</span><span lang="en-US"> structure, and
so on . </span><span lang="en-US">If the block
</span><span lang="en-US">is </span><span lang="en-US">a cube made with
CreateCube, it will be scaled to fit that cell size perfectly. Meshes
created with the graphic primitives (CreateSphere, CreateCone,
CreateCube and so on) usually fit between -1,-1,-1 and 1,1,1, so the
octree expects a mesh of that size (a mesh of different size
</span><span lang="en-US">c</span><span lang="en-US">an
</span><span lang="en-US">be
</span><span lang="en-US">scale</span><span lang="en-US">d</span><span lang="en-US">
using FitMesh</span><span lang="en-US">).</span>

<span lang="en-US">The block is placed inside the octree, at the chosen
</span><span lang="en-US">*level*</span><span lang="en-US"><span style="font-style: normal">
(a higher level means smaller block size, and higher number of blocks),
and at a position that tries to match the given coordinates
</span></span><span lang="en-US">*X*</span><span lang="en-US"><span style="font-style: normal">,
</span></span><span lang="en-US">*Y*</span><span lang="en-US"><span style="font-style: normal">,
</span></span><span lang="en-US">*Z*</span><span lang="en-US"><span style="font-style: normal">
(referred to the octree, not to the world). It will be scaled
automatically. The same mesh could be used as block in more than one
position (for example, a cubic mesh that is supposed to work as a wall
can be used many times to build a complex maze, and it will be stored in
memory only once).</span></span>

If the mesh is animated, all the blocks based on it will be animated,
too, and this can be useful to show flags, fans, or any other animated
item that needs to be used more than once.

<span lang="en-US"><span style="font-style: normal">A
</span></span><span lang="en-US"><span style="font-style: normal">mesh
</span></span><span lang="en-US"><span style="font-style: normal">that
doesn’t fit the recommended size
</span></span><span lang="en-US"><span style="font-style: normal">will
be rendered anyway, it will just be larger than the octree cell. It
shouldn't cause problem, since the octree cell is virtual, it is not
something visible on the screen, although it might disappear if the cell
is completely out of view (the scene manager, expecting that the mesh is
completely inside the cell, would conclude that the mesh is not visible
and so it would not render it, not knowing that the overlapping part of
the mesh might be still in view)</span></span>

<span lang="en-US"><span style="font-style: normal">Parameters
</span></span><span lang="en-US">*Near*</span><span lang="en-US"><span style="font-style: normal">
and
</span></span><span lang="en-US">*Far*</span><span lang="en-US"><span style="font-style: normal">
are used in case you need a LOD (Level Of Detail) rendering, to specify
a distance range from the camera: any block closer than
</span></span><span lang="en-US">*Near*</span><span lang="en-US"><span style="font-style: normal">
won’t be rendered. Any block farther
</span></span><span lang="en-US"><span style="font-style: normal">than
</span></span><span lang="en-US">*Far*</span><span lang="en-US"><span style="font-style: normal">
will stop the recursive rendering, so blocks smaller than it won’t be
rendered. In that way it is possible to render a large block with a low
detail geometry, and when the camera gets closer, the block would
disappear and be replaced by several smaller blocks with more
details.</span></span>

  

<span id="OctreeMesh"></span> **void OctreeMesh(OcTree\* octree, Mesh\*
mesh, int level, float X, float Y, float Z, float Near=0.0, float
Far=1000.0)**

Attaches a *mesh* to an octree. The octree will become its parent. The
mesh can be used only in one position, inside the octree, and must be
placed and scaled manually with PositionEntity and ScaleEntity. It will
be attached to a node inside the octree, at the chosen
*level*<span style="font-style: normal"> (a higher level means smaller
block size, and higher number of blocks), and at a position that tries
to match the given coordinates
</span>*X*<span style="font-style: normal">,
</span>*Y*<span style="font-style: normal">,
</span>*Z*<span style="font-style: normal"> (referred to the octree, not
to the world).</span>

<span style="font-style: normal">This commands allows to use the octree
as a scene manager, In </span><span style="font-style: normal">a complex
scene, with thousands or more of meshes, the default scene manager would
be pretty slow, since it checks for each mesh if it is in view of the
camera before rendering it: an octree can be faster, because it can
group several meshes at once: if one section of the octree is out of
view, all the meshes assigned to that section will be out of view too,
and there is no need to check them one by one.</span>

<span lang="en-US"><span style="font-style: normal">Parameters
</span></span><span lang="en-US">*Near*</span><span lang="en-US"><span style="font-style: normal">
and
</span></span><span lang="en-US">*Far*</span><span lang="en-US"><span style="font-style: normal">
are used in case you need a LOD (Level Of Detail) rendering, to specify
a distance range from the camera: any
</span></span><span lang="en-US"><span style="font-style: normal">node</span></span><span lang="en-US"><span style="font-style: normal">
closer than
</span></span><span lang="en-US">*Near*</span><span lang="en-US"><span style="font-style: normal">
won’t be rendered. Any
</span></span><span lang="en-US"><span style="font-style: normal">node
</span></span><span lang="en-US"><span style="font-style: normal">farther
</span></span><span lang="en-US"><span style="font-style: normal">than
</span></span><span lang="en-US">*Far*</span><span lang="en-US"><span style="font-style: normal">
will stop the recursive rendering, so blocks smaller than it won’t be
rendered. In that way it is possible to render a large block with a low
detail geometry, and when the camera gets closer, the block would
disappear and be replaced by several smaller blocks with more
details.</span></span>

  

<span id="PaintEntity"></span> **void PaintEntity(Entity\* ent,Brush\*
brush)**

<table>
<tbody>
<tr class="odd">
<td><p>Paints a entity with a brush.<br />
<br />
The reason for using PaintEntity to apply specific properties to a entity using a brush rather than just using EntityTexture, EntityColor, EntityShininess etc, is that you can pre-define one brush, and then paint entities over and over again using just the one command rather than lots of separate ones.</p></td>
</tr>
</tbody>
</table>

  

<span id="PaintMesh"></span><span class="smallcaps">**void
PaintMesh(Mesh\* mesh,Brush\* brush)**</span>

Paints a mesh with a brush.

This has the effect of instantly altering the visible appearance of the
mesh, assuming the brush's properties are different to what was was
applied to the surface before.

The reason for using PaintMesh to apply specific properties to a mesh
using a brush rather than just using EntityTexture, EntityColor,
EntityShininess etc, is that you can pre-define one brush, and then
paint meshes over and over again using just the one command rather than
lots of separate ones.

  

<span id="PaintSurface"></span> **void PaintSurface(Surface\*
surf,Brush\* brush)**

Paints a surface with a brush.  
  
This has the effect of instantly altering the visible appearance of that
particular surface, i.e. section of mesh, assuming the brush's
properties are different to what was applied to the surface before.

  

<span id="ParticleColor"></span> **void ParticleColor(Sprite\* sprite,
float red, float green, float blue, float alpha)**

<span lang="en-US">It affects the fading color of
</span><span lang="en-US">particle trails (particles are sprites with
</span>[SpriteRenderMode](#SpriteRenderMode)<span lang="en-US"> set to
3): those particles can leave a trail behind them, and it is possible to
set the fading color of it (setting it to gray, for a red particle,
allows to produce a flame turning to smoke effect)</span>

  

<span id="ParticleVector"></span> **void ParticleVector(Sprite\* sprite,
float x, float y, float z)**

<span lang="en-US">It affects the
</span><span lang="en-US">direction</span><span lang="en-US"> of
</span><span lang="en-US">particle trails (particles are sprites with
</span>[SpriteRenderMode](#SpriteRenderMode)<span lang="en-US"> set to
3): those particles can leave a trail behind them, and it is possible to
set the </span><span lang="en-US">direction the trail will move to, even
when the particle itself is not moving. This is useful to simulate a
wind effect.</span>

  

<span id="ParticleTrail"></span> **void ParticleTrail(Sprite\*
sprite,int length)**

<span lang="en-US">It </span><span lang="en-US">sets the length
</span><span lang="en-US">of </span><span lang="en-US">particle trails
(particles are sprites with
</span>[SpriteRenderMode](#SpriteRenderMode)<span lang="en-US"> set to
3): those particles can leave a trail behind them.</span>

  

<span id="PickedEntity"></span><span class="smallcaps">**Entity\*
PickedEntity()**</span>

Returns the entity ‘picked’ by the most recently executed Pick command.
This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).  
  
Returns 0 if no entity was picked.

  

<span id="PickedNX"></span> **float PickedNX()**

Returns the x component of the normal of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).

  

<span id="PickedNY"></span> **float PickedNY()**

Returns the y component of the normal of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).

  

<span id="PickedNZ"></span> **float PickedNZ()**

Returns the z component of the normal of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).

  

<span id="PickedSurface"></span><span class="smallcaps">**Surface\*
PickedSurface()**</span>

Returns the handle of the surface that was ‘picked’ by the most recently
executed Pick command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).

  

<span id="PickedTime"></span> **float PickedTime()**

Returns the time taken to calculate the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).

  

<span id="PickedTriangle"></span> **int PickedTriangle()**

Returns the index number of the triangle that was ‘picked’ by the most
recently executed Pick command. This might have been
[CameraPick](#CameraPick), [EntityPick](#EntityPick) or
[LinePick](#LinePick).

  

<span id="PickedX"></span> **float PickedX()**

Returns the world x coordinate of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).  
  
The coordinate represents the exact point of where something was picked.

  

<span id="PickedY"></span> **float PickedY()**

Returns the world x coordinate of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).  
  
The coordinate represents the exact point of where something was picked.

  

<span id="PickedZ"></span> **float PickedZ()**

Returns the world x coordinate of the most recently executed Pick
command. This might have been [CameraPick](#CameraPick),
[EntityPick](#EntityPick) or [LinePick](#LinePick).  
  
The coordinate represents the exact point of where something was picked.

  

<span id="PointEntity"></span> **void PointEntity(Entity\* ent,Entity\*
target\_ent,float roll)**

<table>
<tbody>
<tr class="odd">
<td><p>Points one entity at another.<br />
<br />
The optional <em>roll</em> parameter allows you to specify a roll angle as pointing an entity only sets pitch and yaw angles.<br />
<br />
If you wish for an entity to point at a certain position rather than another entity, simply create a pivot entity at your desired position, point the entity at this and then free the pivot.</p></td>
</tr>
</tbody>
</table>

  

  

<span id="PositionEntity"></span> **void PositionEntity(Entity\*
ent,float x,float y,float z,bool global)**

  

<table>
<tbody>
<tr class="odd">
<td><p>Positions an entity at an absolute position in 3D space.<br />
<br />
Entities are positioned using an <em>x</em>,<em>y</em>,<em>z</em> coordinate system. x, y and z each have their own axis, and each axis has its own set of values. By specifying a value for each axis, you can position an entity anywhere in 3D space. 0,0,0 is the centre of 3D space, and if the camera is pointing in the default positive z direction, then positioning an entity with a z value of above 0 will make it appear in front of the camera, whereas a negative z value would see it disappear behind the camera. Changing the x value would see it moving sideways, and changing the y value would see it moving up/down.<br />
<br />
Of course, the direction in which entities appear to move is relative to the position and orientation of the camera.</p></td>
</tr>
</tbody>
</table>

  

<span style="font-style: normal">The optional parameter
</span>*global*<span style="font-style: normal">,</span> ** if true
states that the position should be relative to 0,0,0 rather than a
parent entity's position. False by default.

  

<span id="PositionMesh"></span> **void PositionMesh(Mesh\* mesh,float
px,float py,float pz)**

Moves all vertices of a mesh

  

  

<span id="PositionTexture"></span> **void PositionTexture(Texture\*
tex,float u\_pos,float v\_pos)**

Positions a texture at an absolute position.  
  
This will have an immediate effect on all instances of the texture being
used.  
  
Positioning a texture is useful for performing scrolling texture
effects, such as for water etc.

  

<span id="PostFXBuffer"></span> **void PostFXBuffer(PostFX\* fx, int
pass\_no, int source\_pass, int index, int slot)**

<span lang="en-US">Attaches the output buffer generated by one
pass,</span><span lang="en-US"> </span><span lang="en-US">in a post
processing effect
</span><span lang="en-US">*fx*</span><span lang="en-US"><span style="font-style: normal">,
</span></span><span lang="en-US"><span style="font-style: normal">to be
used as input for another step</span></span><span lang="en-US">: it
allows to </span><span lang="en-US">use one of the
</span><span lang="en-US">color buffers (those buffer contain the
rendered image), </span><span lang="en-US">or the
</span><span lang="en-US">depth buffer </span><span lang="en-US">as
texture attached to a shader (shaders can use textures as input, so
images must be passed to them as textures)</span><span lang="en-US">.
The </span><span lang="en-US">output buffer
create</span><span lang="en-US">d</span><span lang="en-US"> by the stage
</span><span lang="en-US">*source\_pass*</span><span lang="en-US">
(stage 0 is the scene rendering, stage 1 is the first shader,
an</span><span lang="en-US"><span style="font-style: normal">d so
on</span></span><span lang="en-US">) </span><span lang="en-US">will be
used as input </span><span lang="en-US">texture
</span><span lang="en-US">for the </span><span lang="en-US">shader in
</span><span lang="en-US">stage
</span><span lang="en-US">*pass\_no*</span><span lang="en-US">
</span><span lang="en-US">(0 is the first shader, 1 is the second
shader, and so on): </span><span lang="en-US">for example, a
source\_pass =0 and a pass\_no = 0 mean to use the output of the scene
rendering as input for the first shader; values of 1 and 1 mean to use
the output of the first shader as input for the second
one</span><span lang="en-US">. </span>

<span lang="en-US">The parameter
</span><span lang="en-US">*index*</span><span lang="en-US"> sets
</span><span lang="en-US">which texture should be used: 0 is the depth
buffer, 1 or more identifies a </span><span lang="en-US">color buffer
(this is useful when using a shader than outputs different information
on different buffers: for example, in deferred shading one buffer can
contain the normal data, another the actual colors)</span>

<span lang="en-US">T</span><span lang="en-US">he parameter
</span><span lang="en-US">*slot*</span><span lang="en-US"> sets the
texture slot to be used, for the shader to identify it.</span>

  

<span id="PostFXFunction"></span> **void PostFXFunction(PostFX\* fx, int
pass\_no, void (\*PassFunction)(void))**

Attaches a custom function to a post processing effect
*fx*<span style="font-style: normal">,
</span><span style="font-style: normal">to be executed at step
</span>*pass\_no*<span style="font-style: normal">, to apply custom
post-processing.</span>

  

<span id="PostFXShader"></span> **void PostFXShader(PostFX\* fx, int
pass\_no, Shader\* shader)**

Attaches a shader program (created with [CreateShader](#CreateShader) or
loaded with [LoadShader](#LoadShader)) to the post processing effect
*fx*. The parameter *pass\_no* specifies at which step the shader will
be used (0 is the first one)

  

  

<span id="PostFXShaderPass"></span> **void PostFXShaderPass(PostFX\* fx,
int pass\_no, char\* name, int v)**

Passes the numeric parameter *v* to the shader attached to the post
processing effect *fx*<span style="font-style: normal">
</span><span style="font-style: normal">at the step identified by
</span>*pass\_no*<span style="font-style: normal">. The string
</span>*name*<span style="font-style: normal"> identifies the uniform
used internally by the shader.
</span><span style="font-style: normal">This command is useful when the
same shader is used in more steps of the post-processing</span>

  

  

<span id="PostFXTexture"></span> **void PostFXTexture(PostFX\* fx, int
pass\_no, Texture\* tex, int slot, int frame=0)**

Attaches a texture *tex* to a pass, in a post processing effect
*fx*<span style="font-style: normal">,
</span><span style="font-style: normal">to be used as input.
</span><span style="font-style: normal">It
</span><span style="font-style: normal">will be used as input
</span><span style="font-style: normal">texture
</span><span style="font-style: normal">for the
</span><span style="font-style: normal">shader in
</span><span style="font-style: normal">stage
</span>*pass\_no*<span style="font-style: normal">
</span><span style="font-style: normal">(0 is the first shader, 1 is the
second shader, and so on).</span>

<span style="font-style: normal">P</span><span style="font-style: normal">assing
a texture is useful to simulate vignetting, or to add a “mask” to the
picture.</span>

<span style="font-style: normal">T</span><span style="font-style: normal">he
parameter </span>*slot*<span style="font-style: normal"> sets the
texture slot to be used, for the shader to identify it.</span>

<span style="font-style: normal">The parameter
</span>*frame*<span style="font-style: normal"> is used to select the
frame in animated textures.</span>

  

<span id="ProjectedX"></span> **float ProjectedX()**

Returns the viewport x coordinate of the most recently executed
[CameraProject](#CameraProject).

  

  

<span id="ProjectedY"></span> **float ProjectedY()**

Returns the viewport y coordinate of the most recently executed
[CameraProject](#CameraProject).

  

<span id="ProjectedZ"></span> **float ProjectedZ()**

Returns the viewport z coordinate of the most recently executed
[CameraProject](#CameraProject).

  

<span id="RenderWorld"></span> **void RenderWorld()**

Renders the current scene to the BackBuffer onto the rectangle defined
by each cameras [CameraViewport](#CameraViewport). Every camera not
hidden by [HideEntity](#HideEntity) or with a
[CameraProjMode](#CameraProjMode) of 0 is rendered.

  

<span id="RepeatMesh"></span> **Mesh\* RepeatMesh(Mesh\* mesh,Entity\*
parent)**

Creates an instance of a given mesh: the instance is a copy of the mesh
that does not duplicate all its data, but uses the same data from the
original: in this way, it will need less memory, but changes made to the
original mesh (like ScaleMesh or RotateMesh) will affect the duplicate
as well.

  

In case of animated meshes, all the frames of the mesh will be rendered
in memory as separate surface, and they will be used for the animation:
as result, the animation will be less smooth, and it won’t be possible
to animate bones manually; on the other hand, it will be possible to
render hundreds or thousands of animated meshes at different stages of
the animation with less significant impact on speed and memory usage.

  

The optional *parent* parameter allow you to specify a parent entity for
the camera so that when the parent is moved the child camera will move
with it. However, this relationship is one way; applying movement
commands to the child will not affect the parent.

  
  

<span id="ResetEntity"></span> **void ResetEntity(Entity\* ent)**

Resets the collision state of an entity.

  

<span id="ResetShadow"></span> **void ResetShadow(ShadowObject\* shad)**

Forces a static shadow (created with the static flag) to be recalculated
(useful when the mesh is moved or deformed). Not needed for dynamic
shadows.

  

  

<span id="RotateEntity"></span> **void RotateEntity(Entity\* ent,float
pitch,float yaw,float roll,bool global)**

entity - name of the entity to be rotated

*pitch* - angle in degrees of pitch rotation

*yaw* - angle in degrees of yaw rotation

*roll* - angle in degrees of roll rotation

*global* (optional) - true if the angle rotated should be relative to
0,0,0 rather than a parent entity's orientation. False by default.

**Description**

Rotates an entity so that it is at an absolute orientation.

  

*Pitch* is the same as the x angle of an entity, and is equivalent to
tilting forward/backwards.

  

*Yaw* is the same as the y angle of an entity, and is equivalent to
turning left/right.

  

*Roll* is the same as the z angle of an entity, and is equivalent to
tilting left/right.

  

<span id="RotateMesh"></span> **void RotateMesh(Mesh\* mesh,float
pitch,float yaw,float roll)**

Rotates all vertices of a mesh by the specified rotation.

  

<span id="RotateSprite"></span> **void RotateSprite(Sprite\*
sprite,float ang)**

Rotates a sprite

  

<span id="RotateTexture"></span> **void RotateTexture(Texture\*
tex,float ang)**

Rotates a texture.  
  
This will have an immediate effect on all instances of the texture being
used.  
  
Rotating a texture is useful for performing swirling texture effects,
such as for smoke etc.

  

<span id="ScaleEntity"></span> **void ScaleEntity(Entity\* ent,float
x,float y,float z,bool glob)**

Scales an entity so that it is of an absolute size.  
  
Scale values of 1,1,1 are the default size when creating/loading
entities.  
  
Scale values of 2,2,2 will double the size of an entity.  
  
Scale values of 0,0,0 will make an entity disappear.  
  
Scale values of less than 0,0,0 will invert an entity and make it
bigger.

  

<span id="ScaleMesh"></span> **void ScaleMesh(Mesh\* mesh,float sx,float
sy,float sz)**

Scales all vertices of a mesh by the specified scaling factors.  
  

  

<span id="ScaleSprite"></span> **void ScaleSprite(Sprite\* sprite,float
s\_x,float s\_y)**

Scales a sprite

  

<span id="ScaleTexture"></span> **void ScaleTexture(Texture\* tex,float
u\_scale,float v\_scale)**

Scales a texture by an absolute amount.  
  
This will have an immediate effect on all instances of the texture being
used.

  

<span id="SetAnimKey"></span> **void SetAnimKey(Entity\* ent, float
frame, int pos\_key=true, int rot\_key=true, int scale\_key=true)**

*entity* - entity handle

*frame* - frame of animation to be used as anim key

*pos\_key* (optional) - true to include entity position information when
setting key. Defaults to true.

*rot\_key* (optional) - true to include entity rotation information when
setting key. Defaults to true.

*scale\_key* (optional) - true to include entity scale information when
setting key. Defaults to true.

**Description**

Sets an animation key for the specified entity at the specified frame.
The entity must have a valid animation sequence to work with.

  

This is most useful when you've got a character, or a complete set of
complicated moves to perform, and you want to perform them en-masse.

  

<span id="SetAnimTime"></span> **void SetAnimTime(Entity\* ent,float
time,int seq)**

*entity* - a valid entity handle.

*time* - a floating point time value.

*anim\_seq* - an optional animation sequence number.

**Description**

SetAnimTime allows you to manually animate entities.

  

<span id="SetCubeFace"></span> **void SetCubeFace(Texture\* tex,int
face)**

*texture* - texture  
*face* - face of cube to select. This should be one of the following
values:  
0: left (negative X) face  
1: forward (positive Z) face - this is the default.  
2: right (positive X) face  
3: backward (negative Z) face  
4: up (positive Y) face  
5: down (negative Y) face

**Description**

<span lang="en-US">Selects a cube face for direct rendering to a
texture.  
  
This command should only be used when you wish to draw directly to a
cube map texture in real-time. Otherwise, just loading a pre-rendered
cube map with a flag of 128 will suffice.  
  
To understand how this command works exactly it is important to
recognise that
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> treats
cubemap textures slightly differently to how it treats other textures.
Here's how it works...  
  
A cubemap texture in
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> actually
consists of six images, each of which corresponds to a particular cube
face. These images are stored internally by
</span><span lang="en-US">OpenB3D</span><span lang="en-US">, and the
texture handle that is returned by LoadTexture/CreateTexture when
specifying the cube map flag, only provides access to one of these six
images at once (by default the first one, or '0' face).  
  
This is why, when loading a cubemap texture into
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> using
LoadTexture, all the six cube map images must be laid out in a specific
order (0-5, as described above), in a horizontal strip. Then
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> takes this
texture and internally converts it into six separate images. </span>

  

<span lang="en-US">So seeing as the texture handle returned by
CreateTexture / LoadTexture only provides access to one of these images
at once (no. 1 by default), how do we get access to the other five
images? This is where SetCubeFace comes in. It will tell
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> that
whenever you next draw to a cubemap texture, to draw to the particular
image representing the face you have specified with the face
parameter.</span>

  

<span lang="en-US">Now you have the ability to draw to a cube map in
real-time, </span><span lang="en-US">using either BufferToTex,
BackBufferToTex, or CameraToTex</span><span lang="en-US">  
</span>  

  

<span id="SetCubeMode"></span> **void SetCubeMode(Texture\* tex,int
mode)**

Set the rendering mode of a cubemap texture.  
  
The available rendering modes are as follows:  
  
1: Specular (default). Use this to give your cubemapped objects a shiny
effect.  
  
2: Diffuse. Use this to give your cubemapped objects a non-shiny,
realistic lighting effect.  
  

<span id="SetFloat"></span> **void SetFloat(Shader\* material, char\*
name, float v1)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a float parameter to be used inside a shader, where it will be
accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="SetFloat2"></span> **void SetFloat2(Shader\* material, char\*
name, float v1, float v2)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a float vector with 2 elements to be used inside a shader, where it will
be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

  

<span id="SetFloat3"></span> **void SetFloat3(Shader\* material, char\*
name, float v1, float v2, float v3)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a float vector with 3 elements to be used inside a shader, where it will
be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="SetFloat4"></span> **void SetFloat4(Shader\* material, char\*
name, float v1, float v2, float v3, float v4)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a float vector with 4 elements to be used inside a shader, where it will
be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

  

<span id="SetInteger"></span> **void SetInteger(Shader\* material,
char\* name, int v1)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
</span><span lang="en-US">an integer </span><span lang="en-US">parameter
to be used inside a shader, where it will be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="SetInteger2"></span> **void SetInteger2(Shader\* material,
char\* name, int v1, int v2)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a</span><span lang="en-US">n integer</span><span lang="en-US"> vector
with 2 elements to be used inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="SetInteger3"></span> **void SetInteger3(Shader\* material,
char\* name, int v1, int v2, int v3)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a</span><span lang="en-US">n integer </span><span lang="en-US">vector
with </span><span lang="en-US">3</span><span lang="en-US"> elements to
be used inside a shader, where it will be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="SetInteger4"></span> **void SetInteger4(Shader\* material,
char\* name, int v1, int v2, int v3, int v4)**

<span lang="en-US">Set</span><span lang="en-US">s</span><span lang="en-US">
a</span><span lang="en-US">n integer </span><span lang="en-US">vector
with </span><span lang="en-US">4</span><span lang="en-US"> elements to
be used inside a shader, where it will be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">.</span>

  

<span id="ShadeEntity"></span> **void ShadeEntity(Entity\* ent, Shader\*
material)**

Applies a shader to an entity. A shader can be seen as a more advanced
form of brush, that allows to render an object using a custom program

  

<span id="ShadeMesh"></span> **void ShadeMesh(Mesh\* mesh, Shader\*
material)**

Applies a shader to a mesh, affecting all its surfaces. A shader can be
seen as a more advanced form of brush, that allows to render an object
using a custom program

  

<span id="ShadeSurface"></span> **void ShadeSurface(Surface\* surf,
Shader\* material)**

Applies a shader to a surface. A shader can be seen as a more advanced
form of brush, that allows to render an object using a custom program

  

<span id="ShaderFunction"></span> **void ShaderFunction(Shader\*
material, void (\*EnableFunction)(void), void
(\*DisableFunction)(void))**

Sets callback functions that are executed when a shader is used. The
first one *EnableFunction* is executed when the shader is enabled, the
second one *DisableFunction* is executed when the shader is disabled.

It can be used to enable specific OpenGL parameters, for example
glPolygonStipple (an old way to render transparency without using alpha
blending); of course they need to be disable when the shader is
disabled.

  

  

  

<span id="ShaderMaterial"></span> **void ShaderMaterial(Shader\*
material, Material\* tex, char\* name, int index)**

<span lang="en-US">Attaches a </span><span lang="en-US">3d
</span><span lang="en-US">texture to a shader. Up to 255 textures can be
attached. The </span><span lang="en-US">*name*</span><span lang="en-US">
parameter allows the texture to be retrieved inside the shader program,
using the same name. The
</span><span lang="en-US">*index*</span><span lang="en-US"> parameter
</span><span lang="en-US">sets to which slot the texture must be
attached (never use the same slot for more than one texture in the same
shader)</span>

  

<span id="ShaderTexture"></span> **void ShaderTexture(Shader\* material,
Texture\* tex, char\* name, int index)**

<span lang="en-US">Attaches a texture to a shader. Up to 255 textures
can be attached. The
</span><span lang="en-US">*name*</span><span lang="en-US"> parameter
allows the texture to be retrieved inside the shader program, using the
same name. The
</span><span lang="en-US">*index*</span><span lang="en-US"> parameter
</span><span lang="en-US">sets to which slot the texture must be
attached (never use the same slot for more than one texture in the same
shader)</span>

  

  

<span id="ShowEntity"></span> **void ShowEntity(Entity\* ent)**

Shows an entity. Very much the opposite of [HideEntity](#HideEntity).  
  
Once an entity has been hidden using HideEntity, use show entity to make
it visible and involved in collisions again. Note that ShowEntity has no
effect if the enitities parent object is hidden.  
  
Entities are shown by default after creating/loading them, so you should
only need to use ShowEntity after using HideEntity.  
  
ShowEntity affects the specified entity only - child entities are not
affected.

  

<span id="SkinMesh"></span> **void SkinMesh(Mesh\* mesh, int surf\_no,
int vid, int bone1, float weight1=1.0, int bone2=0, float weight2=0, int
bone3=0, float weight3=0, int bone4=0, float weight4=0)**

*mesh* - mesh

*surf\_no*<span style="font-style: normal"> – the number of the surface
inside the mesh (not the surface handle)</span>

*vid*<span style="font-style: normal"> – number of the vertex inside the
surface</span>

*bone1*<span style="font-style: normal"> – the bone number (not the bone
handle) of the first bone affecting the vertex, or 0</span>

*weight1*<span style="font-style: normal"> – how much bone1 affects the
vertex deformation</span>

<span lang="en-US">*bone2*</span><span lang="en-US"><span style="font-style: normal">
– the bone number (not the bone handle) of the second bone affecting the
vertex, or 0</span></span>

*weight2*<span style="font-style: normal"> – how much bone2 affects the
vertex deformation</span>

<span lang="en-US">*bone3*</span><span lang="en-US"><span style="font-style: normal">
– the bone number (not the bone handle) of the third bone affecting the
vertex, or 0</span></span>

*weight3*<span style="font-style: normal"> – how much bone3 affects the
vertex deformation</span>

<span lang="en-US">*bone4*
</span><span lang="en-US"><span style="font-style: normal">– the bone
number (not the bone handle) of the fourth bone affecting the vertex, or
0</span></span>

*weight4*<span style="font-style: normal"> – how much bone4 affects the
vertex deformation</span>

**Description**

Manually binds a vertex from a mesh to its bones, for skeletal
animation. It can be used to build a loader for animated mesh from
different format, or for procedural generation of animations.

<span lang="en-US">E</span><span lang="en-US">ach bone will have a
consecutive number, depending on the order they have been created with
CreateBone (the first bone created will be number 1)</span>

  

  

  

<span id="SpriteRenderMode"></span> **void SpriteRenderMode(Sprite\*
sprite,int mode)**

Sets how sprites are rendered:

1: default. Each sprite is an independent surface. It is the simplest
rendering method, but also the slowest

2: batch sprites. If there are several identical sprites is is more
efficient to combine all visible ones into a single surface and render
it at once. Functionally, batch sprites are manipulated exactly like
default ones

3: particles. This mode is generally the fastest one, although it might
not be supported on some older versions of OpenGL. Particle sprites lack
some functions (mainly scaling and rotation) but on the other hand they
support trails

  

<span id="SpriteViewMode"></span> **void SpriteViewMode(Sprite\*
sprite,int mode)**

*sprite* - sprite handle

  

*view\_mode* - view\_mode of sprite

1: fixed (sprite always faces camera - default)

2: free (sprite is independent of camera)

3: upright1 (sprite always faces camera, but rolls with camera as well,
unlike mode no.1)

4: upright2 (sprite always remains upright. Gives a 'billboard' effect.
Good for trees, spectators etc.)

**Description**

Sets the view mode of a sprite.

  

The view mode determines how a sprite alters its orientation in respect
to the camera. This allows the sprite to in some instances give the
impression that it is more than two dimensional.

  

In technical terms, the four sprite modes perform the following changes:

  

1: Sprite changes its pitch and yaw values to face camera, but doesn't
roll.

2: Sprite does not change either its pitch, yaw or roll values.

3: Sprite changes its yaw and pitch to face camera, and changes its roll
value to match cameras.

4: Sprite changes its yaw value to face camera, but not its pitch value,
and changes its roll value to match cameras.

  

Note that if you use sprite view mode 2, then because it is independent
from the camera, you will only be able to see it from one side unless
you use EntityFx flag 16 with it to disable backface culling.

  

<span id="StencilAlpha"></span> **void StencilAlpha(Stencil\* stencil,
float a)**

Sets the alpha level of a stencil clear operation: a lower value allows
to preserve the older background

  

<span id="StencilClsColor"></span> **void StencilClsColor(Stencil\*
stencil, float r,float g,float b)**

Sets the color to use to clear the area affected by a stencil, when it
is activated

  

<span id="StencilClsMode"></span> **void StencilClsMode(Stencil\*
stencil,int cls\_depth,int cls\_zbuffer)**

Every time a stencil is activated the area affected by it is usually
deleted (color buffer and z-buffer are erased). Setting flags to 0 will
keep the old data (it could be useful to achieve some strange effects,
or to combine two or more renderings in one)

  

  

<span id="StencilMesh"></span> **void StencilMesh(Stencil\* stencil,
Mesh\* mesh, int mode=1)**

<span lang="en-US">Assigns a mesh to a stencil, to be used to define the
stencil shape. More meshes can be assigned to the same stencil. Meshes
assigned to stencils cannot have parent entities, and cannot be rendered
with RenderWorld. They are rendered with the command
</span>[UseStencil](#UseStencil)<span lang="en-US">,
</span><span lang="en-US">and they affect only the stencil buffer. The
parameter </span><span lang="en-US">*mode*</span><span lang="en-US">
states how the stencil buffer is affected: </span>

1: stencil buffer is increased in the area where the mesh is rendered
(the stencil will look like a “hole” shaped like the mesh)

\-1: stencil buffer is decreased in the area where the mesh is rendered

2: stencil buffer is increased where the front face of the mesh are
rendered, and decreased where the back faces are rendered. As result,
the mesh won’t affect the stencil buffer, but the intersections between
the mesh and regular 3d objects in the scene will.

\-2 stencil buffer is decreased where the front face of the mesh are
rendered, and increased where the back faces are rendered

  

<span id="StencilMode"></span> **<span lang="en-US">void
StencilMode(Stencil\* stencil, int
m</span><span lang="en-US">ode</span><span lang="en-US">, int
o</span><span lang="en-US">perator=1</span><span lang="en-US">)</span>**

*stencil*: the stencil

<span lang="en-US">*mode*</span><span lang="en-US">: the value the
stencil level will be compared to</span>

<span lang="en-US">*operator*</span><span lang="en-US">:</span>

0: We Draw Only Where The Stencil Is Not Equal to *mode*

1: We Draw Only Where The Stencil Is Equal to *mode*

2: We Draw Only Where The Stencil Is Smaller or Equal to *mode*

3: We Draw Only Where The Stencil Is Greater or Equal to *mode*

**Description**

Sets the stencil operation that will be computer to decide whether to
draw or not on a portion of the screen.

A stencil buffer can be seen as a 2d matrix, containing as many elements
as the pixels on the screen: each element is an integer number, that is
set to zero, and can be increased or decreased when a stencil mesh is
rendered on it. The stencil buffer is not visible, but affects the next
rendering operation, that will happen only on the “allowed” areas. The
command StencilMode allows to decide which comparison must be done to
decide if a certain pixel is allowed to be plot on, or not.

  

<span id="TerrainHeight"></span> **float TerrainHeight (Terrain\* terr,
int x, int z)**

Returns the height of the terrain at terrain grid coordinates *x*,*z*.
The value returned is in the range 0 to 1.

  

<span id="TerrainX"></span> **float TerrainX (Terrain\* terr, float x,
float y, float z)**

Returns the interpolated x coordinate on a terrain.

  

<span id="TerrainY"></span> **float TerrainY (Terrain\* terr, float x,
float y, float z)**

Returns the interpolated y coordinate on a terrain.

Gets the ground's height, basically.

  

<span id="TerrainZ"></span> **float TerrainZ (Terrain\* terr, float x,
float y, float z)**

Returns the interpolated z coordinate on a terrain.

  

<span id="TexToBuffer"></span> **void TexToBuffer(Texture\* tex,unsigned
char\* buffer, int frame)**

Converts a texture to an image buffer. The image buffer must be
allocated in advance. The image buffer will be in format RGBA (each
pixel is represented by 4 bytes: red, green, blue and alpha values), and
it will have the same width and height of the texture. The argument
*tex* <span style="font-style: normal">is the texture handle, the
argument </span>*buffer*<span style="font-style: normal"> is a pointer
to the image buffer. </span>Argument *frame*
<span style="font-style: normal">is currently unused. </span>

  

<span id="TextureBlend"></span> **void TextureBlend(Texture\* tex,int
blend)**

*Texture* - Texture handle.

*Blend* - Blend mode of texture.

  

0: Do not blend

1: No blend or Alpha (alpha when texture loaded with alpha flag - not
recommended for multitexturing - see below)

2: Multiply (default)

3: Add

**Description**

Sets the blending mode for a texture.

  

The texture blend mode determines how the texture will blend with the
texture or polygon which is 'below' it. Texture 0 will blend with the
polygons of the entity it is applied to. Texture 1 will blend with
texture 0. Texture 2 will blend with texture 1. And so on.

  

<span lang="en-US">Texture blending in
</span><span lang="en-US">OpenB3D</span><span lang="en-US"> effectively
takes the highest order texture (the one with the highest index) and it
blends with the texture below it, then that result to the texture
directly below again, and so on until texture 0 which is blended with
the polygons of the entity it is applied to and thus the world,
depending on the EntityBlend of the object.</span>

  

Each of the blend modes are identical to their EntityBlend counterparts.

  

In the case of multitexturing (more than one texture applied to an
entity), it is not recommended you blend textures that have been loaded
with the alpha flag, as this can cause unpredictable results on a
variety of different graphics cards.

  

<span id="TextureCoords"></span> **void TextureCoords(Texture\* tex,int
coords)**

*texture* - name of texture

*coords* -

0: UV coordinates are from first UV set in vertices (default)

1: UV coordinates are from second UV set in vertices

**Description**

Sets the texture coordinate mode for a texture.

  

This determines where the UV values used to look up a texture come from.

  

<span id="TextureHeight"></span> **int TextureHeight(Texture\* tex)**

Returns the height of a texture.

  

<span id="TextureFilter"></span> **void TextureFilter(char\*
match\_text,int flags)**

*match\_text* - text that, if found in texture filename, will activate
certain filters

  

*flags* - filter texture flags:

1: Color

2: Alpha

4: Masked

8: Mipmapped

16: Clamp U

32: Clamp V

64: Spherical reflection map

**Description**

Adds a texture filter. Any textures loaded that contain the text
specified by *match\_text* will have the provided flags added.

  

This is mostly of use when loading a mesh.

  

<span id="TextureName"></span> **const char\* TextureName(Texture\*
tex)**

Returns a texture's filename.  
  

  

<span id="TextureWidth"></span> **int TextureWidth(Texture\* tex)**

Returns the width of a texture.

  

<span id="TFormedX"></span> **float TFormedX()**

Returns the X component of the last [TFormPoint](#TFormPoint),
[TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  
  

  

<span id="TFormedY"></span> **float TFormedY()**

Returns the Y component of the last [TFormPoint](#TFormPoint),
[TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  
  

  

<span id="TFormedZ"></span> **float TFormedZ()**

Returns the Z component of the last [TFormPoint](#TFormPoint),
[TFormVector](#TFormVector) or [TFormNormal](#TFormNormal) operation.  
  

<span id="TFormNormal"></span> **void TFormNormal(float x,float y,float
z, Entity\* source\_entity,Entity\* dest\_entity)**

*x*, *y*, *z* = components of a vector in 3d space

  

*source\_entity* = handle of source entity, or 0 for 3d world

*dest\_entity* = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormNormal the new

components can be read with TFormedX(), TFormedY() and TFormedZ().

  

This is exactly the same as [TFormVector](#TFormVector) but with one
added feature.

After the transformation the new vector is 'normalized', meaning it

is scaled to have length 1.

  

For example, suppose the result of TFormVector is (1,2,2).

This vector has length Sqr( 1\*1 + 2\*2 + 2\*2 ) = Sqr( 9 ) = 3.

  

This means TFormNormal would produce ( 1/3, 2/3, 2/3 ).

  

<span id="TFormPoint"></span> **void TFormPoint(float x,float y,float z,
Entity\* source\_entity,Entity\* dest\_entity)**

*x*, *y*, *z* = coordinates of a point in 3d space

  

*source\_entity* = handle of source entity, or 0 for 3d world

*dest\_entity* = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormPoint the new

coordinates can be read with TFormedX(), TFormedY() and TFormedZ().

  

  

See EntityX() for details about local coordinates.

  

Consider a sphere built with CreateSphere(). The 'north pole' is at
(0,1,0).

At first, local and global coordinates are the same. As the sphere is
moved,

turned and scaled the global coordinates of the point change.

  

But it is always at (0,1,0) in the sphere's local space.

  

<span id="TFormVector"></span> **void TFormVector(float x,float y,float
z, Entity\* source\_entity,Entity\* dest\_entity)**

*x*, *y*<span style="font-style: normal">,</span> *z* = components of a
vector in 3d space

  

*source\_entity* = handle of source entity, or 0 for 3d world

*dest\_entity* = handle of destination entity, or 0 for 3d world

**Description**

Transforms between coordinate systems. After using TFormVector the new

components can be read with TFormedX(), TFormedY() and TFormedZ().

  

  

See EntityX() for details about local coordinates.

  

  

Similar to TFormPoint, but operates on a vector. A vector can be thought
of

as 'displacement relative to current location'.

  

For example, vector (1,2,3) means one step to the right, two steps up

and three steps forward.

  

This is analogous to PositionEntity and MoveEntity:

  

PositionEntity entity, x,y,z ; put entity at point (x,y,z)

  

MoveEntity entity, x,y,z ; add vector (x,y,z) to current position

  

  

<span id="TranslateEntity"></span> **void TranslateEntity(Entity\*
ent,float x,float y,float z,bool glob)**

Translates an entity relative to its current position and not its
orientation.  
  
What this means is that an entity will move in a certain direction
despite where it may be facing. Imagine that you have a game character
that you want to make jump in the air at the same time as doing a triple
somersault. Translating the character by a positive y amount will mean
the character will always travel directly up in their air, regardless of
where it may be facing due to the somersault action.  
  

  

<span id="TriangleVertex"></span> **int TriangleVertex(Surface\*
surf,int tri\_no,int corner)**

*surface* - surface handle

*triangle\_index* - triangle index

*corner* - corner of triangle. Should be 0, 1 or 2.

**Description**

Returns the vertex of a triangle corner.

  

<span id="TurnEntity"></span> **void TurnEntity(Entity\* ent,float
x,float y,float z,bool glob)**

*entity* - name of entity to be rotated

*pitch* - angle in degrees that entity will be pitched

*yaw* - angle in degrees that entity will be yawed

*roll* - angle in degrees that entity will be rolled

global (optional) -

**Description**

Turns an entity relative to its current orientation.

  

*Pitch* is the same as the x angle of an entity, and is equivalent to
tilting forward/backwards.

  

*Yaw* is the same as the y angle of an entity, and is equivalent to
turning left/right.

  

*Roll* is the same as the z angle of an entity, and is equivalent to
tilting left/right.

  

  

<span id="UpdateNormals"></span> **void UpdateNormals(Entity\* ent)**

Recalculates all normals in a mesh, terrain, or geosphere. In a mesh
this is necessary for correct lighting if you have not set surface
normals using 'VertexNormals' commands. In a geosphere or a terrain this
is necessary after a command like ModifyTerrain or ModifyGeosphere is
used.

  

  

<span id="UpdateTexCoords"></span> **void UpdateTexCoords(Surface\*
surf)**

Recalculates the second set of texture coordinates, replacing them with
3d texture coordinates. These coordinates will work only with 3d
textures (loaded with [LoadMaterial](#LoadMaterial))

  

  

<span id="UpdateWorld"></span> **void UpdateWorld(float anim\_speed)**

Animates all entities in the world, and performs collision checking. It
also updates particles, actions, and constraints.

The optional *anim\_speed\!* parameter allows you affect the animation
speed of all entities at once. A value of 1 (default) will animate
entities at their usual animation speed, a value of 2 will animate
entities at double their animation speed, and so on.

For best results use this command once per main loop, just before
calling [RenderWorld](#RenderWorld).

  

<span id="UseEntity"></span> **void UseEntity(Shader\* material, char\*
name, Entity\* ent, int mode)**

<span lang="en-US">Assigns a matrix </span><span lang="en-US">coming
from a specific entity, </span><span lang="en-US">calculated
automatically by OpenB3D, to the vertex shader.
</span><span lang="en-US">A typical use is passing the matrix from a
light entity.</span><span lang="en-US"> The parameter
</span><span lang="en-US">*mode*</span><span lang="en-US"> tells which
matrix must be associated with
</span><span lang="en-US">*name*</span><span lang="en-US">: </span>

<span lang="en-US">0: </span><span lang="en-US">matrix</span>

1: inverse matrix

  

<span id="UseFloat"></span> **void UseFloat(Shader\* material, char\*
name, float\* v1)**

<span lang="en-US">Assigns a variable of single precision to be used as
a float parameter inside a shader, where it will be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">. The value of
the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

<span id="UseFloat2"></span> **void UseFloat2(Shader\* material, char\*
name, float\* v1, float\* v2)**

<span lang="en-US">Assigns
</span><span lang="en-US">two</span><span lang="en-US">
variable</span><span lang="en-US">s</span><span lang="en-US"> of single
precision to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

  

<span id="UseFloat3"></span> **void UseFloat3(Shader\* material, char\*
name, float\* v1, float\* v2, float\* v3)**

<span lang="en-US">Assigns </span><span lang="en-US">three
</span><span lang="en-US">variable</span><span lang="en-US">s</span><span lang="en-US">
of single precision to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

  

<span id="UseFloat4"></span> **void UseFloat4(Shader\* material, char\*
name, float\* v1, float\* v2, float\* v3, float\* v4)**

<span lang="en-US">Assigns </span><span lang="en-US">four
</span><span lang="en-US">variable</span><span lang="en-US">s</span><span lang="en-US">
of single precision to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

<span id="UseInteger"></span> **void UseInteger(Shader\* material,
char\* name, int\* v1)**

<span lang="en-US">Assigns a</span><span lang="en-US">n
integer</span><span lang="en-US"> variable to be used as a float
parameter inside a shader, where it will be accessible as
</span><span lang="en-US">*name*</span><span lang="en-US">. The value of
the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

  

<span id="UseInteger2"></span> **void UseInteger2(Shader\* material,
char\* name, int\* v1, int\* v2)**

<span lang="en-US">Assigns </span><span lang="en-US">two integer
</span><span lang="en-US">variable</span><span lang="en-US">s</span><span lang="en-US">
to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

  

<span id="UseInteger3"></span> **void UseInteger3(Shader\* material,
char\* name, int\* v1, int\* v2, int\* v3)**

<span lang="en-US">Assigns </span><span lang="en-US">three integer
</span><span lang="en-US">variable</span><span lang="en-US">s</span><span lang="en-US">
to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

  

<span id="UseInteger4"></span> **void UseInteger4(Shader\* material,
char\* name, int\* v1, int\* v2, int\* v3, int\* v4)**

<span lang="en-US">Assigns </span><span lang="en-US">four integer
</span><span lang="en-US">variable</span><span lang="en-US">s</span><span lang="en-US">
to be used as </span><span lang="en-US">elements of
a</span><span lang="en-US"> float </span><span lang="en-US">vector
</span><span lang="en-US">inside a shader, where it will be accessible
as </span><span lang="en-US">*name*</span><span lang="en-US">. The value
of the variable will be automatically passed to the shader
</span><span lang="en-US">each time the shader is used for
rendering.</span>

  

<span id="UseMatrix"></span> **void UseMatrix(Shader\* material, char\*
name, int mode)**

<span lang="en-US">Assigns a matrix calculated automatically by OpenB3D
to the vertex shader. The parameter
</span><span lang="en-US">*mode*</span><span lang="en-US"> tells which
matrix must be associated with
</span><span lang="en-US">*name*</span><span lang="en-US">: </span>

0: model matrix (based on the object’s position, scale and rotation)

1: view matrix (based on the camera’s position and rotation)

2: projection matrix (based on camera zoom, used for perspective
deformation)

3: model-view matrix (1 and 2 combined)

  

  

<span id="UseStencil"></span> **void UseStencil(Stencil\* stencil)**

Activates a stencil. A stencil affects the next
[RenderWorld](#RenderWorld) operation (and in general, any other opengl
drawing operation), that won’t happen anymore on the whole drawable
area, but only on part of it, as if a physical stencil with holes in it
were placed on the canvas, to affect any painting attempts. Using 0 as
argument will disable the active stencil, returning to normal mode.

  

Stencils should not be used on a scene that uses also shadows.

  

<span id="UseSurface"></span> **void UseSurface(Shader\* material,
char\* name, Surface\* surface, int vbo)**

<span lang="en-US">Tells the shader to bind the data from a surface to
an attribute identified by
</span><span lang="en-US">*name*</span><span lang="en-US">. If
</span><span lang="en-US">*surface*</span><span lang="en-US"> is set to
0, the current surface that is being rendered will be used. The
parameter </span><span lang="en-US">*vbo*</span><span lang="en-US">
states which array has to be passed:</span>

1: vertex coordinates

2: texture mapping coordinates (first set)

3: texture mapping coordinates (second set), or 3d texture mapping
coordinates on a mesh where UpdateTexCoords has been used

4: vertex normals

5: vertex color, in RGB format

6: vertex color, in RGBA format (vec4, including also alpha channel)

  

<span id="VectorPitch"></span> **float VectorPitch(float vx,float
vy,float vz)**

Returns the pitch value of a vector.  
  
Using this command will return the same result as using
[EntityPitch](#EntityPitch) to get the pitch value of an entity that is
pointing in the vector's direction.

  

<span id="VectorYaw"></span> **float VectorYaw(float vx,float vy,float
vz)**

Returns the yaw value of a vector.  
  
Using this command will return the same result as using
[EntityYaw](#EntityYaw) to get the yaw value of an entity that is
pointing in the vector's direction.  
  

  

<span id="VertexAlpha"></span> **float VertexAlpha(Surface\* surf,int
vid)**

Returns the alpha component of a vertices color, set using
[VertexColor](#VertexColor)

  

<span id="VertexBlue"></span> **float VertexBlue(Surface\* surf,int
vid)**

Returns the blue component of a vertices color.

  

<span id="VertexColor"></span> **void VertexColor(Surface\* surf,int
vid,float r,float g,float b,float a)**

Sets the color of an existing vertex.  
  
NB. If you want to set the alpha individually for vertices using the
*alpha* parameter then you need to use EntityFX 32 (to force
alpha-blending) on the entity.

  

<span id="VertexCoords"></span> **void VertexCoords(Surface\* surf,int
vid,float x,float y,float z)**

Sets the geometric coordinates of an existing vertex.  
  
This is the command used to perform what is commonly referred to as
'dynamic mesh deformation'. It will reposition a vertex so that all the
triangle edges connected to it, will move also. This will give the
effect of parts of the mesh suddenly deforming.

  

<span id="VertexGreen"></span> **float VertexGreen(Surface\* surf,int
vid)**

<span lang="en-US">Returns the </span><span lang="en-US">green
</span><span lang="en-US">component of a vertices color. </span>

  

  

<span id="VertexNormal"></span> **void VertexNormal(Surface\* surf,int
vid,float nx,float ny,float nz)**

Sets the normal of an existing vertex.

  

<span id="VertexNX"></span> **float VertexNX(Surface\* surf,int vid)**

Returns the x component of a vertices normal.

  

<span id="VertexNY"></span> **float VertexNY(Surface\* surf,int vid)**

Returns the y component of a vertices normal.

  

<span id="VertexNZ"></span> **float VertexNZ(Surface\* surf,int vid)**

Returns the z component of a vertices normal.

  

<span id="VertexRed"></span> **float VertexRed(Surface\* surf,int vid)**

<span lang="en-US">Returns the </span><span lang="en-US">red
</span><span lang="en-US">component of a vertices color. </span>

  

<span id="VertexTexCoords"></span> **void VertexTexCoords(Surface\*
surf,int vid,float u,float v,float w,int coord\_set)**

*surface* - surface handle

*index* - index of vertex

*u* - u coordinate of vertex

*v* - v coordinate of vertex

*w* (optional) - w coordinate of vertex. It is valid only in 3d texture
mode

coord\_set (optional) - co\_oord set. Should be set to 0, 1 or 2.

**Description**

<span lang="en-US">Sets the texture coordinates of an existing vertex.
</span><span lang="en-US">Use a value of 2 for
</span><span lang="en-US">*coord\_set*</span><span lang="en-US"> to
specify that the coordinates are in 3d format (used only for 3d
textures, loaded with LoadMaterial).
</span><span lang="en-US">Coordinates in 3d format can be used only
after using
</span>[UpdateTexCoords](#UpdateTexCoords)<span lang="en-US"> on the
mesh.</span>

  

<span id="VertexU"></span> **float VertexU(Surface\* surf,int vid,int
coord\_set)**

Returns the texture u coordinate of a vertex.  
  

  

<span id="VertexV"></span> **float VertexV(Surface\* surf,int vid,int
coord\_set)**

Returns the texture v coordinate of a vertex.  
  

  

<span id="VertexW"></span> **float VertexW(Surface\* surf,int vid,int
coord\_set)**

Returns the texture w coordinate of a vertex. It will usually return 0,
since the coordinate system used by default is 2d. If the command
[UpdateTexCoords](#UpdateTexCoords) has been used on the mesh, and a
value of 2 is used for *coord\_set*<span style="font-style: normal">,
the w coordinate is used too.</span>  
  

  

<span id="VertexX"></span> **float VertexX(Surface\* surf,int vid)**

This function return the **X** coordinate of a vertex. The vertex has to
be specified with *index* variable; every surface has its own vertices,
so *surface* handle must be specified, too.

  

<span id="VertexY"></span> **float VertexY(Surface\* surf,int vid)**

<span lang="en-US">This function return the
</span>**<span lang="en-US">**Y**</span>**<span lang="en-US"> coordinate
of a vertex. The vertex has to be specified with
</span>*<span lang="en-US">index</span>*<span lang="en-US"> variable;
every surface has its own vertices, so
</span>*<span lang="en-US">surface</span>*<span lang="en-US"> handle
must be specified, too. </span>

  

<span id="VertexZ"></span> **float VertexZ(Surface\* surf,int vid)**

<span lang="en-US">This function return the
</span>**<span lang="en-US">**Z**</span>**<span lang="en-US"> coordinate
of a vertex. The vertex has to be specified with
</span>*<span lang="en-US">index</span>*<span lang="en-US"> variable;
every surface has its own vertices, so
</span>*<span lang="en-US">surface</span>*<span lang="en-US"> handle
must be specified, too. </span>

  

<span id="VoxelSpriteMaterial"></span> **void
VoxelSpriteMaterial(VoxelSprite\* voxelspr, Material\* mat)**

Applies a 3d texture (loaded with [LoadMaterial](#LoadMaterial)) to a 3d
sprite. The texture will be rendered as a set of voxels, so the sprite
will have a solid look, that changes according to the observer’s
direction.

  

  

<span id="Wireframe"></span> **void Wireframe(int enable)**

With *enable*=1, it set wireframe mode (only outlines will be visible:
it's useful for debug); with *enable*=0 will set back normal mode
