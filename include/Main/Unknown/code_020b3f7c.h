#pragma once

#include "types.h"

// Section header: two words; func_020b3fb0 adds the second to the section address to move on.
typedef struct Unk020b3fb0_20 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk020b3fb0_20;

// Object func_020b3fb0 walks: the number of sections at 0x0c, the first section at 0x20.
typedef struct Unk020b3fb0 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0x10];
    /* 20 */ Unk020b3fb0_20 mUnk_20;
} Unk020b3fb0;

// Section of func_020b3fb0 whose first word is 0x494e4631 (data_0217b360): words from 0x10.
typedef struct Unk0217b340 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ u32 mUnk_10[1];
} Unk0217b340;

// Section of func_020b3fb0 whose first word is 0x44415431 (data_0217b364): bytes from 8.
typedef struct Unk0217b344 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[1];
} Unk0217b344;

void func_020b3fb0(Unk020b3fb0 *a);
void *func_020b3f7c(Unk020b3fb0 *a, s32 b);
