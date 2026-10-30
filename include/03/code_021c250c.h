#pragma once

#include "types.h"

typedef struct Unk021c250c {
    /* 00 */ u32 *mOffsets;
    /* 04 */ u8 *mData;
    /* 08 */ u8 *mUnk_08;
} Unk021c250c;

void *func_ov003_021c250c(Unk021c250c *table, u32 index, s32 column, s32 value);
