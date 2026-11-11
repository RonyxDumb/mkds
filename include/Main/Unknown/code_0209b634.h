#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct MapObjectList MapObjectList;

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
void DrawMapObjectModelWithPos(u32 unusedArg1, MapObjectModel *mapObjectModel, MapObject *mapObject);
void DrawMapObjectModel(MapObjectList *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject);
void QueueMapObjectModelMaterial(void *mapObjectList, MapObjectModel *mapObjectModel);
void *UnparkFirstParkedMapObject(MapObjectList *mapObjectList);
