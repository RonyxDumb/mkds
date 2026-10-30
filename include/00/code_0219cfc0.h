#pragma once

#include "types.h"
#include "00/code_0219d934.h"

// 0x210 bytes: func_ov000_0218ec44 fills it, func_ov000_0219d9ec reads strings from it.
typedef struct Unk0218ec44 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x100];
    /* 108 */ char mUnk_108[0x108];
} Unk0218ec44;

int func_ov000_0219cfc0(int a);
int func_ov000_0219d034(int a);
u32 func_ov000_0219d094(void *a, Unk0218ec44 *b);

// Declared here until the code that defines them is decompiled.
s32 func_ov000_0218ebe8(struct Unk0218f960 *a, s32 b, s32 *c);
s32 func_ov000_0218ec44(struct Unk0218f960 *a, s32 b, Unk0218ec44 *c);
