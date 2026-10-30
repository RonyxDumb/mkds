#pragma once

#include "types.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02124094.h"

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Object behind data_ov000_021b4c6c; func_ov000_02181df8 fills 0x20 to 0x30.
typedef struct Unk021b4c6c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Unk020b4934 *mUnk_24;
    /* 28 */ struct Unk020b4a44 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0201ea30 *mUnk_30;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
} Unk021b4c6c;

extern Unk021b4c6c *data_ov000_021b4c6c;

void func_ov000_02181e8c(void);
