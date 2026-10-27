#pragma once

#include "types.h"
#include "00/code_02182fdc.h" // Unk020b4a44, Unk020b4934
#include "code_02021db0.h" // Unk02021e40

// 16-byte element of the table at 0x7dc of an Unk0217b3c4.
typedef struct Unk0217b3c4_7dc {
    /* 00 */ Unk020b4a44 *mUnk_00;
    /* 04 */ Unk020b4934 *mUnk_04;
    /* 08 */ u8 mUnk_08[8];
} Unk0217b3c4_7dc;

// 0x88c bytes, allocated by func_020b8624; the pointer to it is held in data_0217b3c4.
typedef struct Unk0217b3c4 {
    /* 000 */ Unk02021e40 *mUnk_000[0x38];
    /* 0e0 */ Unk02021e40 *mUnk_0e0[0x44];
    /* 1f0 */ Unk02021e40 *mUnk_1f0[0xf];
    /* 22c */ Unk02021e40 *mUnk_22c[0xd];
    /* 260 */ Unk02021e40 *mUnk_260[0x16];
    /* 2b8 */ Unk02021e40 *mUnk_2b8[8];
    /* 2d8 */ Unk02021e40 *mUnk_2d8[0xc9];
    /* 5fc */ Unk02021e40 *mUnk_5fc[0x2c];
    /* 6ac */ Unk02021e40 *mUnk_6ac[0x28];
    /* 74c */ Unk02021e40 *mUnk_74c[0x21];
    /* 7d0 */ Unk02021e40 *mUnk_7d0[3];
    /* 7dc */ Unk0217b3c4_7dc mUnk_7dc[11];
} Unk0217b3c4;

void func_020b8624(void);
