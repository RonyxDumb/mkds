#pragma once

#include "types.h"

typedef struct Unk021b54c8 {
    /* 00 */ u8 pad_00[0x24];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
} Unk021b54c8;

extern Unk021b54c8 *data_ov000_021b54c8;

void func_ov000_0219b8a8(s32 value);
