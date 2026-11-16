#pragma once

#include "types.h"
#include "Main/Unknown/code_020ffc4c.h"

// The 0x40-byte object dram_setupConfig allocates and zeroes.
typedef struct Unk02100004 {
    /* 00 */ s32 mUnk_00[16];
} Unk02100004;

extern Unk02100004 data_0215a068;

// The 0x2c-byte object dram_setupRenderPart allocates (behind dram_sRenderPart, written from dram_renderPartData).
typedef struct Unk020fff4c {
    /* 00 */ s32 mUnk_00[11];
} Unk020fff4c;

extern Unk020fff4c *dram_sRenderPart;

extern Unk020fff4c dram_renderPartData;

// The 0x28-byte object dram_setupLogicPart allocates (behind dram_sLogicPart, written from dram_logicPartData).
typedef struct Unk020fffa8 {
    /* 00 */ s32 mUnk_00[10];
} Unk020fffa8;

extern Unk020fffa8 *dram_sLogicPart;

extern Unk020fffa8 dram_logicPartData;

Unk02100004 *dram_setupConfig(void);
Unk020fff4c *dram_setupRenderPart(void);
Unk020fffa8 *dram_setupLogicPart(void);
void dram_render(void *a, Dram *dram, void *c, s32 maxAlpha);
void dram_globalPreUpdate(MapObjectList *list);
