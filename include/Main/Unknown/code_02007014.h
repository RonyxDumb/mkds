#pragma once

#include "types.h"

// List node; the next node is at offset 0x28.
typedef struct Unk02007014 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ struct Unk02007014 *mUnk_28;
    /* 2c */ u8 *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
} Unk02007014;

Unk02007014 *func_02007014(u32 a);
