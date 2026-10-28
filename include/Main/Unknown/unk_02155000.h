#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern u8 data_02155048[];
extern u8 data_02155098[];
extern u8 data_021550a8[];
extern u8 data_02155a20[];
extern u8 data_02155a64[];
extern Vec3 data_021557ec;
// Three pairs of words (func_02082e4c).
typedef struct Unk02155808 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk02155808;

extern Unk02155808 data_02155808[3];
extern Vec3 data_02155a14;
extern Vec3 data_02155a48;
