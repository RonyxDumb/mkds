#pragma once

#include "types.h"

// List node; the next node is at offset 0x28.
typedef struct Unk02007014 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x24];
    /* 28 */ struct Unk02007014 *mUnk_28;
    /* 2c */ u8 mUnk_2c[6];
    /* 32 */ u16 mUnk_32;
} Unk02007014;

Unk02007014 *func_02007014(u32 a);
