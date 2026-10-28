#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern u8 data_02155048[];
extern u8 data_02155098[];
extern u8 data_021550a8[];
extern void (*data_02155a20[])(void *param_1);
extern u8 data_02155a64[];
extern const Vec3 data_021557ec;
extern s32 data_02155854[];
struct Unk0201ca6c;

// Three pairs of words (func_02082e4c).
typedef struct Unk02155808 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void (*mUnk_04)(struct Unk0201ca6c *p, s32 a);
} Unk02155808;

extern Unk02155808 data_02155808[3];
extern Vec3 data_02155a08;
extern Vec3 data_02155a14;
extern Vec3 data_02155a48;
extern Vec3 data_02155eb0;
extern Vec3 data_02155ebc;
