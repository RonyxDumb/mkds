#pragma once

#include "types.h"

typedef struct Pukupuku Pukupuku;

// 0x10-byte request built on the stack here.
typedef struct Unk020e4e08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e4e08;

void DrawPukupukuShadow(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u32 alpha);
