#pragma once

#include "types.h"

typedef struct Unk021cca74 {
    /* 00 */ u32 mResource;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u16 mX;
    /* 12 */ u16 mY;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u8 mOffset;
} Unk021cca74;

void func_ov003_021cca74(s32 offset);
