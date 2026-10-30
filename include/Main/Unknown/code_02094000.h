#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h"

// 0x20-byte part of Unk02094000 at 0xbc and 0xdc, written by func_02094000.
typedef struct Unk02094000_bc {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk02094000_bc;

// Object returned by func_0209bbfc for func_02100138(0x13b), filled by func_02094000.
typedef struct Unk02094000 {
    /* 000 */ Unk020e71a0 mUnk_00;
    /* 0a0 */ Vec3 mUnk_a0;
    /* 0ac */ u16 mUnk_ac;
    /* 0ae */ u16 mUnk_ae;
    /* 0b0 */ u16 mUnk_b0;
    /* 0b2 */ u8 mUnk_b2[2];
    /* 0b4 */ s32 mUnk_b4;
    /* 0b8 */ s32 mUnk_b8;
    /* 0bc */ Unk02094000_bc mUnk_bc;
    /* 0dc */ Unk02094000_bc mUnk_dc;
    /* 0fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
} Unk02094000;

void func_02094000(Vec3 *a);
