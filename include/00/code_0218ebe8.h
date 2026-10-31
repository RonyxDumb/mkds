#pragma once

#include "types.h"
#include "00/code_0218f960.h"

// Output of func_ov000_0218ec44: a copy of the entry's fields, two 0x100-byte strings included.
typedef struct Unk0218ec44 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x100];
    /* 108 */ u8 mUnk_108[0x100];
    /* 208 */ u32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
} Unk0218ec44;

u32 func_ov000_0218ebe8(Unk0218f960 *a, u32 b, s32 *c);
u32 func_ov000_0218ec44(Unk0218f960 *a, s32 b, Unk0218ec44 *c);
