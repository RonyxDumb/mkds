#pragma once

#include "types.h"

// Two-byte element of Unk021a9b88::mUnk_2c; func_ov001_02180ce8 copies it whole.
typedef struct Unk02180ce8 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
} Unk02180ce8;

s32 func_ov001_02180ce8(s32 p0, s32 p1, s32 p2);
s32 func_ov001_02180eec(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4);
