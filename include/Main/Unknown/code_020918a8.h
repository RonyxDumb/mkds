#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then a halfword and three words.
typedef struct Kanoke64 {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mBurstCount;
    /* ac */ s32 mState;
} Kanoke64;

void CreateCowDrawList(void);
void DrawCow(void *mapObjectList, MapObject *mapObject);
void SetupDrawCow(void *mapObjectList);
void CreateCow(void *mapObjectList);
void CreateKanoke64UpdateList(void);
void CreateKanoke64DrawList(void);
void UpdateKanoke64(void *mapObjectList, Kanoke64 *kanoke64);
s16 Kanoke64FX_CosIdx(s32 angle);
s32 Kanoke64MulFixed12NoRound(s32 multiplicand, s32 multiplier);
s16 Kanoke64FX_SinIdx(s32 angle);
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit);
void InitKanoke64Objects(MapObjectList *mapObjectList);
void DrawKanoke64(void *mapObjectList, Kanoke64 *kanoke64);
void CreateKanoke64(void *mapObjectList);
