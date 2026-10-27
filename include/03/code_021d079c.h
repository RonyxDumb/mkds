#pragma once

#include "types.h"

typedef struct Unk021da2a8 {
    /* 00 */ u8 pad_00[0x40];
    /* 40 */ s32 mUnk_40;
    /* 44 */ u8 pad_44[0x10];
    /* 54 */ s32 mUnk_54;
} Unk021da2a8;

extern Unk021da2a8 *data_ov003_021da2a8;

void func_ov003_021d079c(s32 value);
