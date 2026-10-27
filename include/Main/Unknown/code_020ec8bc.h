#pragma once

#include "types.h"

// Object allocated by func_020ed4d0 (0x2c bytes); two words are updated there.
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u32 mUnk_0c;
    /* 10 */ volatile u32 mUnk_10;
    /* 14 */ volatile u32 mUnk_14;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ u32 *mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ u8 mUnk_24[8];
} Unk020ed4d0;

// Object behind the first parameter of the functions below from its first
// byte: the pointer at 0x00c, the vectors at 0x050, 0x05c, 0x0e4, 0x0f0,
// 0x130, 0x13c and 0x148, the pointer at 0x168 and the words from 0x214.
typedef struct Unk020ec8bc {
    /* 000 */ u8 mUnk_000[0xc];
    /* 00c */ struct Unk020ec8bc_00c *mUnk_00c;
    /* 010 */ u8 mUnk_010[0x34];
    /* 044 */ s32 mUnk_044;
    /* 048 */ u8 mUnk_048[8];
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ u8 mUnk_068[0xc];
    /* 074 */ u32 mUnk_074;
    /* 078 */ u16 mUnk_078;
    /* 07a */ u8 mUnk_07a[0x60];
    /* 0da */ s16 mUnk_0da;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ u8 mUnk_0e0[4];
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ Vec3 mUnk_0f0;
    /* 0fc */ u32 mUnk_0fc;
    /* 100 */ u8 mUnk_100[0x2c];
    /* 12c */ s32 mUnk_12c;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ Vec3 mUnk_13c;
    /* 148 */ Vec3 mUnk_148;
    /* 154 */ u8 mUnk_154[4];
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ u8 mUnk_160[8];
    /* 168 */ void *mUnk_168;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ u8 mUnk_170[0xa4];
    /* 214 */ s32 mUnk_214;
    /* 218 */ s32 mUnk_218;
    /* 21c */ s32 mUnk_21c;
    /* 220 */ s32 mUnk_220;
    /* 224 */ s32 mUnk_224;
} Unk020ec8bc;

// Object the word at 0x00c of a Unk020ec8bc points at: the words at 0x1f0.
typedef struct Unk020ec8bc_00c {
    /* 000 */ u8 mUnk_000[0x1f0];
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ s32 mUnk_1f4;
} Unk020ec8bc_00c;

// Object behind data_0217bbfc from its first byte: the pointers at 0x00 to 0x34.
typedef struct {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
} Unk0217bbfc;

// One element of the table behind data_0217bc34 from its first byte: the
// pointer at 0x14.
typedef struct {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ void (*mUnk_14)(void);
} Unk0217bc34_14;

void func_020ec8bc(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, s32 g);
void func_020ec918(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d);
void func_020ec9c0(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 e);
void func_020ece1c(Unk020ec8bc *p, s32 a, s32 b, s32 c);
s32 func_020ed0f4(Unk020ec8bc *p);
void func_020ed268(Unk020ec8bc *p, u8 *q, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, u16 g, s32 h);
void func_020ed2f8(void);
void *func_020ed490(u8 *a);
Unk020ed4d0 *func_020ed4d0(u8 *a, u8 *b, u8 *c);
void *func_020ed548(u8 *a);
