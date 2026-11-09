#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct MapObjectList MapObjectList;

u16 GetMapObjectModelNsbtpFrameCount(MapObjectModel *o);
void SetMapObjectModelNsbtpFrameIndex(MapObjectModel *o, u16 frameIndex);
void SetMapObjectModelNsbtaFrameIndex(MapObjectModel *o, s32 frameIndex);
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *mapObjectModel);
s32 GetMapObjectModelNsbmaFrameCount(MapObjectModel *o);
void SetMapObjectModelNsbmaFrameIndex(MapObjectModel *o, u32 frameIndex);
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex);
void SetMapObjectModelMirror(MapObjectModel *mapObjectModel, s32 b, s32 c);
void SetMapObjectModelFogEnabled(MapObjectModel *mapObjectModel, u32 fogEnabled);
void SetMapObjectModelMaterialPolygonId(MapObjectModel *mapObjectModel, u32 polygonId, u16 matId);
void SetMapObjectModelPolygonId(MapObjectModel *mapObjectModel, u32 polygonId);
void SetMapObjectModelAlpha(MapObjectModel *mapObjectModel, u16 alpha);
void SetMapObjectModelLightEnableFlag(MapObjectModel *mapObjectModel, u32 light);
void DrawMapObjectModel1Mat1Shp(void *a, MapObjectModel *mapObjectModel, void *c);
void DrawMapObjectModelWithPos(u32 a, MapObjectModel *mapObjectModel, MapObject *mapObject);
void DrawMapObjectModel(MapObjectList *mapObjectList, MapObjectModel *mapObjectModel, void *d);
void QueueMapObjectModelMaterial(void *a, MapObjectModel *mapObjectModel);
void *UnparkFirstParkedMapObject(MapObjectList *mapObjectList);
