#pragma once

#include "types.h"

typedef struct Unk021b5664 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 pad_04[0x19];
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 pad_1e[0xe];
    /* 2c */ void (*mUnk_2c)(s32, u8, void *);
    /* 30 */ void *mUnk_30;
    /* 34 */ u8 pad_34[0x10];
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
} Unk021b5664;

extern Unk021b5664 *data_ov000_021b5664;

void func_ov000_0219d934(void *first, void *second);
