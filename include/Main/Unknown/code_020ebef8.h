#pragma once

#include "types.h"

// Object returned by func_020d22c0: two 64-bit words updated from a third.
typedef struct Unk020d22c0 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk020d22c0;

// Object Unk020ebef8::mUnk_09c points to.
typedef struct Unk020ebef8_9c {
    /* 000 */ u8 mUnk_000[0x2c];
    /* 02c */ s16 mUnk_02c;
} Unk020ebef8_9c;

// First argument of func_020ebef8.
typedef struct Unk020ebef8 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u16 mUnk_002;
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ u8 mUnk_020[8];
    /* 028 */ Vec3 mUnk_028[3];
    /* 04c */ u8 mUnk_04c[0xc];
    /* 058 */ s32 mUnk_058;
    /* 05c */ u8 mUnk_05c[0xa];
    /* 066 */ u16 mUnk_066;
    /* 068 */ u8 mUnk_068[0x10];
    /* 078 */ u32 mUnk_078;
    /* 07c */ u8 mUnk_07c[4];
    /* 080 */ u8 mUnk_080[4];
    /* 084 */ u32 mUnk_084;
    /* 088 */ u8 mUnk_088[8];
    /* 090 */ u16 mUnk_090;
    /* 092 */ u16 mUnk_092;
    /* 094 */ u8 mUnk_094[8];
    /* 09c */ Unk020ebef8_9c *mUnk_09c;
    /* 0a0 */ Vec3 mUnk_0a0;
    /* 0ac */ u16 mUnk_0ac;
    /* 0ae */ u16 mUnk_0ae;
    /* 0b0 */ Vec3 mUnk_0b0;
    /* 0bc */ Vec3 mUnk_0bc;
    /* 0c8 */ u16 mUnk_0c8;
    /* 0ca */ u8 mUnk_0ca[2];
    /* 0cc */ Vec3 mUnk_0cc;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ u16 mUnk_0f0;
    /* 0f2 */ u8 mUnk_0f2[2];
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ Vec3 mUnk_100;
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u16 mUnk_10e;
    /* 110 */ u16 mUnk_110;
    /* 112 */ u8 mUnk_112[2];
    /* 114 */ u8 mUnk_114[4];
} Unk020ebef8;

extern Unk020ebef8 *data_0217bbf0;

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
