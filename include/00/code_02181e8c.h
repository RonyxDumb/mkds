#pragma once

#include "types.h"

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Element of 0x40 bytes of the table at member 0x1c of Unk021b4c6c.
typedef struct Unk021b4c6c_1c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 pad_06[0x3a];
} Unk021b4c6c_1c;

// Object behind data_ov000_021b4c6c; func_ov000_02181df8 fills 0x20 to 0x30.
typedef struct Unk021b4c6c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ s32 mUnk_18;
    /* 1c */ Unk021b4c6c_1c *mUnk_1c;
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Unk020b4934 *mUnk_24;
    /* 28 */ struct Unk020b4a44 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mUnk_38;
} Unk021b4c6c;

extern Unk021b4c6c *data_ov000_021b4c6c;

void func_ov000_02181e8c(void);
