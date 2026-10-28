#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"

// Object with an array of Unk020f41c4_A pointers at 0x04 and a word at 0x10.
typedef struct Unk020ed718 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ Unk020f41c4_A **mUnk_004;
    /* 008 */ u8 mUnk_008[8];
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
} Unk020ed718;

// The object behind the word at 0x20 of a Unk0206bcb0_590: the vectors from 0x48.
typedef struct Unk0206bcb0_590_20 {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ Vec3 mUnk_14[4];
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ Vec3 mUnk_48[1];
} Unk0206bcb0_590_20;

// The object behind the word at 0x590 of a Unk0206bcb0 from its first byte:
// the halfword at 0x40.
typedef struct Unk0206bcb0_590 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x1c];
    /* 020 */ Unk0206bcb0_590_20 *mUnk_020;
    /* 024 */ u8 mUnk_024[0x1c];
    /* 040 */ u16 mUnk_040;
} Unk0206bcb0_590;

// Three vectors at 0x00, 0x0c and 0x18.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020eda5c_02c;

// Object at 0x58 of a Unk020ee684 (that Unk020ee684 at 0x0c), passed first to the function pointers in the data_0217bc34 entries:
// three Unk020f41c4_A pointers at 0x14, vectors from 0x2c to 0x0e4.
typedef struct Unk020eda5c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ struct Unk020ee684 *mUnk_00c;
    /* 010 */ Unk0206bcb0 *mUnk_010;
    /* 014 */ Unk020f41c4_A *mUnk_014[3];
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ u16 mUnk_028;
    /* 02a */ u8 mUnk_02a[2];
    /* 02c */ Unk020eda5c_02c mUnk_02c;
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ s32 mUnk_068;
    /* 06c */ Vec3 mUnk_06c;
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 084 */ Vec3 mUnk_084;
    /* 090 */ Vec3 mUnk_090;
    /* 09c */ Vec3 mUnk_09c;
    /* 0a8 */ Vec3 mUnk_0a8;
    /* 0b4 */ Vec3 mUnk_0b4;
    /* 0c0 */ Vec3 mUnk_0c0;
    /* 0cc */ s32 mUnk_0cc[3];
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec[2][16];
    /* 16c */ s32 mUnk_16c;
    /* 170 */ void *mUnk_170;
    /* 174 */ u16 mUnk_174;
    /* 176 */ u16 mUnk_176;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ Vec3 mUnk_180;
    /* 18c */ u16 mUnk_18c[3];
} Unk020eda5c;

void func_020ed5c0(Unk020f41c4_A *p, Unk020e6488 *q, Vec3 *v);
void func_020ed718(Unk020ed718 *p, void *a, void (*cb)(void *, void *, void *));
void func_020ed79c(Unk020ed718 *p, Vec3 *v);
void *func_020ed98c(Unk020f41c4_A *p, Vec3 *v);
void func_020eda5c(Unk020eda5c *p, Unk020f41c4_A *q);
void func_020edad8(Unk020eda5c *p);
void func_020edb00(Unk020eda5c *p);
s32 func_020edb8c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
s32 func_020edc9c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
void func_020eddb4(Unk020eda5c *p);
void func_020ee2e4(Unk020eda5c *a, Unk020f40dc *b);
s32 func_020ee528(Unk020eda5c *a);
void func_020edf10(Unk020eda5c *p);
void func_020ee160(Unk020f41c4_A *a, Unk020f41c4_A *b);
s32 func_020ee284(Unk020f41c4_A *p, Vec3 *v, s32 d);
