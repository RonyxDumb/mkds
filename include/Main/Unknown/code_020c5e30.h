#pragma once

#include "types.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/unk_0217b000.h"

// Four bytes read by func_020adc24 and written by func_0214d1fc.
typedef struct Unk020adc24 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020adc24;

// 0x20-byte elements at 0x1c of the object behind data_0217b3f4.
typedef struct Unk0217b3f4_1c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a;
    /* 1b */ u8 mUnk_1b[5];
} Unk0217b3f4_1c;

// Object behind data_0217b3f4, 0xe8 bytes allocated by func_020c6fac; mUnk_00 holds the function the object runs.
typedef struct Unk0217b3f4 {
    /* 00 */ void (*mUnk_00)(void);
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18;
    /* 1c */ Unk0217b3f4_1c mUnk_1c[6];
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
} Unk0217b3f4;

s32 func_020c70bc(void);
s32 func_020c70a0(void);
void func_020c6fac(void);
void func_020c6f84(void);
void func_020c6f14(void);
void func_020c6adc(Unk020c06c4 *a, s32 b, s32 c, Unk0217b3f4_1c *d);
void func_020c692c(Unk020c06c4 *a, s32 b, s32 c, s32 d);
void func_020c676c(Unk020c06c4 *a);
s32 func_020c657c(s32 a);
s32 func_020c6428(s32 a);
void func_020c610c(void);
void func_020c5f7c(void);
void func_020c5f08(void);
void func_020c5eb8(void);
void func_020c5e30(void);
