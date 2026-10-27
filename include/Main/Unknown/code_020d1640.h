#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind data_0217b4b0, allocated 0x2c bytes long by func_020d1640.
typedef struct Unk0217b4b0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk020b4934 *mUnk_08;
    /* 0c */ Unk02021dc8 *mUnk_0c;
    /* 10 */ Unk020b4a44 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ void *mUnk_20;
    /* 24 */ Unk020b4934 *mUnk_24;
    /* 28 */ Unk020b4a44 *mUnk_28;
} Unk0217b4b0;

void func_020d1fd4(Unk020d029c *param_1);
void func_020d1de8(Unk020d029c *param_1, s32 param_2);
void func_020d1a98(Unk020d029c *param_1);
void func_020d18d4(Unk020d029c *param_1);
void func_020d1640(void *param_1);
