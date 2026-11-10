#pragma once

#include "types.h"
#include "Main/Unknown/code_020ffc4c.h"

// The 0x40-byte object CreateDramKindData allocates and zeroes.
typedef struct Unk02100004 {
    /* 00 */ s32 mUnk_00[16];
} Unk02100004;

extern Unk02100004 gMissionRunBoxKindData;

// The 0x2c-byte object CreateDramDrawList allocates (behind gDramDrawList, written from data_0215a100).
typedef struct Unk020fff4c {
    /* 00 */ s32 mUnk_00[11];
} Unk020fff4c;

extern Unk020fff4c *gDramDrawList;

extern Unk020fff4c data_0215a100;

// The 0x28-byte object CreateDramUpdateList allocates (behind gDramUpdateList, written from data_0215a12c).
typedef struct Unk020fffa8 {
    /* 00 */ s32 mUnk_00[10];
} Unk020fffa8;

extern Unk020fffa8 *gDramUpdateList;

extern Unk020fffa8 data_0215a12c;

Unk02100004 *CreateDramKindData(void);
Unk020fff4c *CreateDramDrawList(void);
Unk020fffa8 *CreateDramUpdateList(void);
void DrawDram(void *unusedFirst, Dram *dram, void *unusedThird, s32 maxAlpha);
void PickDramAngleChoices(MapObjectList *list);
