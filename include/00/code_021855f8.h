#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Object behind data_ov000_021b4c88; func_ov000_0218554c fills 0x34 to 0x48.
typedef struct Unk021b4c88 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ u16 mUnk_0e[12];
    /* 26 */ u8 pad_26[2];
    /* 28 */ s32 mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk02124b1c *mUnk_30;
    /* 34 */ struct Unk02021dc8 *mUnk_34;
    /* 38 */ struct Unk020b4934 *mUnk_38;
    /* 3c */ struct Unk020b4a44 *mUnk_3c;
    /* 40 */ Unk0201ea30 *mUnk_40;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ void *mUnk_50;
} Unk021b4c88;

extern Unk021b4c88 *data_ov000_021b4c88;

void func_ov000_021855f8(void);
