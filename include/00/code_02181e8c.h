#pragma once

#include "types.h"

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Object behind data_ov000_021b4c6c; func_ov000_02181df8 fills 0x20 to 0x30.
typedef struct Unk021b4c6c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[0xc];
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Unk020b4934 *mUnk_24;
    /* 28 */ struct Unk020b4a44 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
} Unk021b4c6c;

extern Unk021b4c6c *data_ov000_021b4c6c;

void func_ov000_02181e8c(void);
