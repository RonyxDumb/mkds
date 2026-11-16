#pragma once

#include "types.h"
#include "01/MapObjects/map_object_model.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/map_objects_get.h"

typedef struct MapObjectModel MapObjectModel;

u32 GetMapObjectModelNsbtpFrameIndex(MapObjectModel *model);
u32 GetMapObjectModelNsbcaFrameIndex(MapObjectModel *model);

typedef struct MapObjectList MapObjectList;

void StructMapObject_AddAnimationNsbca_from_thumb(MapObjectModel *mapObjectModel, const char *name);
MapObjectModel *CreateMapObjectFromModel_from_thumb(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectFromModelAndAnimation_from_thumb(MapObjectList *mapObjectList, const char *modelName,
                                               const char *animationName);
MapObjectModel *CreateMapObjectFromModel_2_from_thumb(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *mapObjectList, const char *name);
void StructMapObject_AddAnimationNsbtp_from_thumb(MapObjectModel *mapObjectModel, const char *name);
void StructMapObject_AddAnimationNsbta_from_thumb(MapObjectModel *mapObjectModel, const char *name);

u16 StructMapObject_SomeFn_1(MapObjectModel *mapObjectModel);
void StructMapObject_SomeFn_0(MapObjectModel *mapObjectModel, u16 frameIndex);
void StructMapObject_SomeFn_3(MapObjectModel *mapObjectModel, s32 frameIndex);
u16 StructMapObject_SomeFn_2(MapObjectModel *mapObjectModel);
s32 GetMapObjectModelNsbmaFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbmaFrameIndex(MapObjectModel *mapObjectModel, u32 frameIndex);
u16 StructMapObject_GetAnimationBCAFrameCount(MapObjectModel *mapObjectModel);
void StructMapObject_MaybeSetNsbcaFrame(MapObjectModel *mapObjectModel, u16 frameIndex);
void StructMapObject_SomeFn_8(MapObjectModel *mapObjectModel, s32 mirrorX, s32 mirrorY);
void StructMapObject_SomeFn_7(MapObjectModel *mapObjectModel, u32 fogEnabled);
void SetMapObjectModelMaterialPolygonId(MapObjectModel *mapObjectModel, u32 polygonId, u16 matId);
void StructMapObject_MaybeSetPolygonId(MapObjectModel *mapObjectModel, u32 polygonId);
void StructMapObject_SomeFn_6(MapObjectModel *mapObjectModel, u16 alpha);
void SetMapObjectModelLightEnableFlag(MapObjectModel *mapObjectModel, u32 light);
void DrawMapObjectModel1Mat1Shp(void *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject);
void DrawMapObjectModelWithPos(u32 unusedMapObjectList, MapObjectModel *mapObjectModel, MapObject *mapObject);
void DrawMapObjectModel(MapObjectList *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject);
void StructMapObject_SomeFn_9(void *mapObjectList, MapObjectModel *mapObjectModel);
void *UnparkFirstParkedMapObject(MapObjectList *mapObjectList);

void *GetMapObjectFromList(MapObjectList *list, s32 index);

void *CreateAllocateMapObject_from_thumb(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects);
void *CreateMapObjectDrawList1(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects);
void *CreateMapObjectUpdateList(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects);

extern const Vec3 gMapObjectModelFrameShadowScale;
extern const Vec3 gMapObjectModelFrameNsbmdScale;
extern const Vec3 gMapObjectModelFrameNsbmdNsbtpScale;
extern const Vec3 gMapObjectModelFrameAnimatedScale;
