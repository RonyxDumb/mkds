#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

// One entry of the array func_ov000_021a8b20 takes: an object, the bits asked for and the bits found.
typedef struct Unk021a8b20 {
    /* 00 */ Unk021a6fa8 *mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021a8b20;

s32 func_ov000_021a8b20(void *a, s32 b, s64 c);
