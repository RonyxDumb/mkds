#pragma once

#include "types.h"

typedef struct Unk021d34e4 {
    /* 00 */ struct Unk021d34e4 *mUnk_00;
    /* 04 */ struct Unk021d34e4 *mUnk_04;
    /* 08 */ void (*mUnk_08)(struct Unk021d34e4 *a, u32 b);
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u8 mUnk_12[2];
} Unk021d34e4;

Unk021d34e4 *func_ov003_021d34e4(u32 a, void (*b)(Unk021d34e4 *a, u32 b), u32 c, u32 d, u8 e);
