#pragma once

#include "types.h"
#include "01/MapObjects/data_0209bc74.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/map_objects_get.h"

typedef struct MapObjectModel MapObjectModel;

u32 GetMapObjectModelNsbtpFrameIndex(MapObjectModel *model);
u32 GetMapObjectModelNsbcaFrameIndex(MapObjectModel *model);

typedef struct MapObjectList MapObjectList;

void CreateMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *name);
MapObjectModel *CreateMapObjectModelAnimated(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectModelNsbmdNsbtp(MapObjectList *mapObjectList, const char *modelName,
                                               const char *animationName);
MapObjectModel *CreateMapObjectModelNsbmd(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *mapObjectList, const char *name);
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *name);
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *name);

u16 GetMapObjectModelNsbtpFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbtpFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex);
void SetMapObjectModelNsbtaFrameIndex(MapObjectModel *mapObjectModel, s32 frameIndex);
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *mapObjectModel);
s32 GetMapObjectModelNsbmaFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbmaFrameIndex(MapObjectModel *mapObjectModel, u32 frameIndex);
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex);
void SetMapObjectModelMirror(MapObjectModel *mapObjectModel, s32 mirrorX, s32 mirrorY);
void SetMapObjectModelFogEnabled(MapObjectModel *mapObjectModel, u32 fogEnabled);
void SetMapObjectModelMaterialPolygonId(MapObjectModel *mapObjectModel, u32 polygonId, u16 matId);
void SetMapObjectModelPolygonId(MapObjectModel *mapObjectModel, u32 polygonId);
void SetMapObjectModelAlpha(MapObjectModel *mapObjectModel, u16 alpha);
void SetMapObjectModelLightEnableFlag(MapObjectModel *mapObjectModel, u32 light);
void DrawMapObjectModel1Mat1Shp(void *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject);
void DrawMapObjectModelWithPos(u32 unusedMapObjectList, MapObjectModel *mapObjectModel, MapObject *mapObject);
void DrawMapObjectModel(MapObjectList *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject);
void QueueMapObjectModelMaterial(void *mapObjectList, MapObjectModel *mapObjectModel);
void *UnparkFirstParkedMapObject(MapObjectList *mapObjectList);

void *GetMapObjectFromList(MapObjectList *list, s32 index);

void *CreateMapObjectDrawList2(void *init, void *forEachObject, void *beforeObjects);
void *CreateMapObjectDrawList1(void *init, void *forEachObject, void *beforeObjects);
void *CreateMapObjectUpdateList(void *init, void *forEachObject, void *beforeObjects);

extern const Vec3 gMapObjectModelFrameShadowScale;
extern const Vec3 gMapObjectModelFrameNsbmdScale;
extern const Vec3 gMapObjectModelFrameNsbmdNsbtpScale;
extern const Vec3 gMapObjectModelFrameAnimatedScale;
