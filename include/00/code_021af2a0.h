#pragma once

#include "types.h"
#include "00/code_021ae314.h"
#include "00/code_021aefc0.h"

typedef struct Unk021af3e8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08[3];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12[3];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} Unk021af3e8;

extern u16 data_ov000_021b63d0[3];
extern u8 data_ov000_021b6368;

void func_ov000_021af2a0(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
void func_ov000_021af348(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
void func_ov000_021af3e8(Unk021af3e8 *param_1, u32 param_2);
void func_ov000_021af4d4(Unk021af3e8 *param_1);
