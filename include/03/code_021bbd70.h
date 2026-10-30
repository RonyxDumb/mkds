#pragma once

#include "types.h"

typedef struct Unk021bbd70 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x40];
} Unk021bbd70;

void func_ov003_021bbd70(Unk021bbd70 *a);
