#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// Row of the array at 0x00 of the object behind data_02175620.
typedef struct Unk020fa294 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[2];
    /* 28 */ s16 mUnk_28;
    /* 2a */ u8 mUnk_2a[0x12];
} Unk020fa294;

void func_020f9c6c(Unk020f41c4_A *param_1);
void func_020f9ca8(void *param_1);
s32 func_020f9ce8(Unk020f41c4_A *param_1);
s32 func_020f9dc8(Unk020f41c4_A *param_1);
void func_020f9f08(void *param_1, s32 param_2, s32 param_3);
void func_020f9fa8(Unk020f41c4_A *param_1);
void func_020fa030(Unk020f41c4_A *param_1);
s32 func_020fa0b8(void *param_1, s32 param_2, s32 param_3);
s32 func_020fa0e8(s32 param_1, s32 param_2);
void func_020fa13c(void);
void func_020fa294(void);
void *func_020fa3d0(s32 param_1, u16 param_2, void *param_3, void *param_4);
