#pragma once

#include "types.h"
#include "Main/Course/MapObjectModel.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct MapObjectList MapObjectList;

u16 mobj_getModelNsbtpFrameCount(void *a);
void mobj_setModelNsbtpFrame(void *a, u16 frameIndex);
void mobj_setModelNsbtaFrame(void *a, s32 frameIndex);
u16 mobj_getModelNsbtaFrameCount(MapObjectModel *mapObjectModel);
s32 mobj_getModelNsbmaFrameCount(void *a);
void mobj_setModelNsbmaFrame(void *a, u32 frameIndex);
u16 mobj_getModelNsbcaFrameCount(MapObjectModel *mapObjectModel);
void mobj_setModelNsbcaFrame(MapObjectModel *mapObjectModel, u16 frameIndex);
void mobj_setModelFlip(void *a, s32 b, s32 c);
void mobj_setModelFogEnableFlag(void *a, u32 fogEnabled);
void mobj_setModelPolygonId(void *a, u32 polygonId, u16 matId);
void mobj_setModelPolygonIdAll(void *a, u32 polygonId);
void mobj_setModelAlpha(void *a, u16 alpha);
void mobj_setModelLightMask(void *a, u32 light);
void mobj_renderModel1Mat1Shp(void *a, void *b, void *c);
void mobj_renderModelInPlace(u32 a, MapObjectModel *mapObjectModel, MapObject *mapObject);
void mobj_renderModel(MapObjectList *mapObjectList, void *b, void *d);
void mobj_bbModelApplyMaterial(void *a, void *b);
void *mobj_acquireFreeObject(void *b);
