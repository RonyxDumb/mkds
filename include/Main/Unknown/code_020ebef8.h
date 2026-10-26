#pragma once

#include "types.h"

// Object returned by func_020d22c0: two 64-bit words updated from a third.
typedef struct Unk020d22c0 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk020d22c0;

// First argument of func_020ebef8.
typedef struct Unk020ebef8 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u16 mUnk_002;
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ u8 mUnk_010[0xac];
    /* 0bc */ Vec3 mUnk_0bc;
    /* 0c8 */ u8 mUnk_0c8[0x46];
    /* 10e */ u16 mUnk_10e;
    /* 110 */ u16 mUnk_110;
} Unk020ebef8;

// Object returned by func_020fa3d0.
typedef struct Unk020fa3d0 {
    /* 00 */ u8 mUnk_000[0x50];
    /* 50 */ Vec3 mUnk_050;
    /* 5c */ Vec3 mUnk_05c;
    /* 68 */ s32 mUnk_068;
    /* 6c */ s32 mUnk_06c;
    /* 70 */ s32 mUnk_070;
} Unk020fa3d0;

// Argument of func_020ec194.
typedef struct Unk020ec194 {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ u8 mUnk_01c[0xc];
    /* 028 */ u8 mUnk_028[0x88];
    /* 0b0 */ Vec3 mUnk_0b0;
    /* 0bc */ u8 mUnk_0bc[0xc];
    /* 0c8 */ u16 mUnk_0c8;
} Unk020ec194;

void func_020ebef8(Unk020ebef8 *param_1, Vec3 *param_2);
void func_020ec194(Unk020ec194 *param_1);
