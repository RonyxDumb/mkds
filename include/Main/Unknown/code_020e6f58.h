#pragma once

#include "types.h"

// Element container: pointer array at 0x00, a u16 at 0x04, three s32 at 0x18,
// 0x1c and 0x20.
typedef struct Unk020e6f58 {
    /* 00 */ u8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x12];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk020e6f58;

// Object reached through the second argument's 0x98 pointer.
typedef struct Unk020e6f58_98 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ s32 mUnk_20;
} Unk020e6f58_98;

void func_020e6f58(Unk020e6f58 *p, u8 *q);
