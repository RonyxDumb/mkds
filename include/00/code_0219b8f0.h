#pragma once

#include "types.h"

typedef struct Unk021b5550 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021b5550;

extern Unk021b5550 data_ov000_021b5550[32];

Unk021b5550 *func_ov000_0219b8f0(s32 index);
