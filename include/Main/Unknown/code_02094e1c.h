#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then four words.
typedef struct Unk02094e8c {
    /* 00 */ MapObject field0;
    /* a0 */ s32 fieldA0;
    /* a4 */ BOOL fieldA4;
    /* a8 */ s32 fieldA8;
    /* ac */ s32 fieldAC;
} Unk02094e8c;

#include "Main/Unknown/code_020d22c0.h"

void tsacnt_setupLogicPart(void);
u32 tsacnt_setupConfig(void);
void tsacnt_update(void *a, Unk02094e8c *o);
s16 tsacnt_FX_GetCosIdx(s32 a);
s32 tsacnt_FX_TRUNC_MUL(s32 a, s32 b);
s16 tsacnt_FX_GetSinIdx(s32 a);
u16 sub_20951B4(RandomState64 *randomState64);
RandomState64 *GetRaceLocalRandom(void);
void tsacnt_globalLogicInit(MapObjectList *mapObjectList);
void sub_20952DC(Unk02094e8c *a, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit, s32 timerLimit);
void tsacnt_init(u32 mapObject);
