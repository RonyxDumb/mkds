#pragma once

#include "types.h"

typedef struct Pukupuku Pukupuku;

// 0x10-byte request built on the stack here.
typedef struct PukupukuShadowParams {
    /* 00 */ s32 mScale;
    /* 04 */ Vec3 mPos;
} PukupukuShadowParams;

void DrawPukupukuShadow(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u32 alpha);
