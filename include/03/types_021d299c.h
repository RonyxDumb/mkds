#pragma once

#include "types.h"

typedef struct Unk021d299c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021d299c;

typedef struct Unk021da2d4Input {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ u16 mUnk_28;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u8 mUnk_30[8];
    /* 38 */ union {
        u8 mUnk_38;
        struct {
            u8 mBit_0 : 1;
            u8 mOther : 7;
        } mBits;
    };
} Unk021da2d4Input;
