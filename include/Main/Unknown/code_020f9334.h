#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// Object behind the pointer at 0x98 of Unk020f944c.
typedef struct Unk020f944c_98 {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ s32 mUnk_28;
} Unk020f944c_98;

// Object func_020f944c acts on and passes as the fifth argument of func_020f77f8.
typedef struct Unk020f944c {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ u8 mUnk_1c[0x5c];
    /* 78 */ u32 mUnk_78;
    /* 7c */ u8 mUnk_7c[0x1c];
    /* 98 */ Unk020f944c_98 *mUnk_98;
} Unk020f944c;

s32 func_020f9c08(Unk020f41c4_A *param_1);
void func_020f9ba8(Unk020f41c4_A *param_1);
void func_020f9b0c(Unk020f41c4_A *param_1);
void func_020f9a14(Unk020f41c4_A *param_1, s32 param_2);
void func_020f99b8(Unk020f41c4_A *param_1, s32 param_2, u16 param_3, Vec3 *param_4);
void func_020f992c(Unk020f41c4_A *param_1);
void func_020f98a0(void *param_1, Vec3 *param_2, Vec3 *param_3, u16 *param_4, s32 param_5);
s32 func_020f9880(Unk020f41c4_A *param_1);
s32 func_020f97e0(Unk020f41c4_A *param_1, Unk0206bcb0 *param_2);
s32 func_020f9780(Unk020f41c4_A *param_1, Vec3 *param_2, s32 param_3);
void func_020f95d4(Unk020f41c4_A *param_1, Unk020f41c4_A *param_2);
void func_020f944c(void *param_1, void *param_2);
void func_020f9334(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, Vec3 *param_5);
