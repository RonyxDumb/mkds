#pragma once

#include "types.h"

#include "Main/MapObjects/attractor.h" // MapObject

#define BASABASA_BURST_TIMER_CYCLES 4
#define BASABASA_BURST_CYCLE_FRAMES 0x14

typedef struct MapObjectList MapObjectList;

// A Basabasa burst map object: the frame it is at in its cycle, a timer (frames before a burst in time attack, cycles
// while bursting), the burst count and its state.
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
