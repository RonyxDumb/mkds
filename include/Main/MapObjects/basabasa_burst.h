#pragma once

#include "types.h"

#include "Main/MapObjects/attractor.h" // MapObject

typedef struct MapObjectList MapObjectList;

// Object of 0xb0 bytes: the MapObject it starts with, then a halfword and three words.
typedef struct BasabasaBurst {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mCycleFrames;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mBurstCount;
    /* ac */ s32 mState;
} BasabasaBurst;

MapObjectList *CreateBasabasaBurstUpdateList(void);
void UpdateBasabasaBurst(void *mapObjectList, BasabasaBurst *burstObject);
s16 BasabasaBurstFX_CosIdx(s32 angle);
s32 BasabasaBurstMulFixed12NoRound(s32 multiplicand, s32 multiplier);
s16 BasabasaBurstFX_SinIdx(s32 angle);
void InitBasabasaBurstObjects(MapObjectList *mapObjectList);
void InitBasabasaBurst(u32 mapObject);
