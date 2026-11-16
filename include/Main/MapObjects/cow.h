#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_park.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/map_object_model.h"

// A Kanoke64 map object: its animation frame, a timer, the burst count and its state.
typedef struct Kanoke64 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mBurstCount;
    /* ac */ s32 mState;
} Kanoke64;

MapObjectList *CreateCowDrawList(void);
void DrawCow(void *mapObjectList, MapObject *mapObject);
void SetupDrawCow(void *mapObjectList);
void CreateCow(void *mapObjectList);
MapObjectList *CreateKanoke64UpdateList(void);
MapObjectList *CreateKanoke64DrawList(void);
void UpdateKanoke64(void *mapObjectList, Kanoke64 *kanoke64);
s16 Kanoke64FX_CosIdx(s32 angle);
s32 Kanoke64MulFixed12NoRound(s32 multiplicand, s32 multiplier);
s16 Kanoke64FX_SinIdx(s32 angle);
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit);
void InitKanoke64Objects(MapObjectList *mapObjectList);
void DrawKanoke64(void *mapObjectList, Kanoke64 *kanoke64);
void CreateKanoke64(void *mapObjectList);

extern struct MapObjectModel *gCow;
