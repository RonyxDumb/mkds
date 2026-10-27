#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e5d0c.h"

// Object updated through its flags word and three vectors; read by the
// functions below and by func_020ed718's third argument.
typedef struct Unk020ed5c0 {
    /* 000 */ u8 mUnk_000[0x44];
    /* 044 */ s32 mUnk_044;
    /* 048 */ s32 mUnk_048;
    /* 04c */ u8 mUnk_04c[4];
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ Vec3 mUnk_068;
    /* 074 */ u32 mUnk_074;
    /* 078 */ u16 mUnk_078;
    /* 07a */ u8 mUnk_07a[2];
    /* 07c */ u16 mUnk_07c;
    /* 07e */ u8 mUnk_07e[0x12];
    /* 090 */ u16 *mUnk_090;
    /* 094 */ Vec3 mUnk_094;
    /* 0a0 */ Vec3 mUnk_0a0;
    /* 0ac */ Vec3 mUnk_0ac;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ u8 mUnk_0c4[0xc];
    /* 0d0 */ Vec3 *mUnk_0d0;
    /* 0d4 */ u8 mUnk_0d4[4];
    /* 0d8 */ s16 mUnk_0d8;
    /* 0da */ s16 mUnk_0da;
    /* 0dc */ u8 mUnk_0dc[4];
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ Vec3 mUnk_0f0;
    /* 0fc */ u8 mUnk_0fc[0x1a];
    /* 116 */ u16 mUnk_116;
    /* 118 */ u8 mUnk_118[4];
    /* 11c */ s32 mUnk_11c;
    /* 120 */ u8 mUnk_120[0x50];
    /* 170 */ void *mUnk_170;
} Unk020ed5c0;

// Object with an array of Unk020ed5c0 pointers at 0x04 and a word at 0x10.
typedef struct Unk020ed718 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ Unk020ed5c0 **mUnk_004;
    /* 008 */ u8 mUnk_008[8];
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
} Unk020ed718;

// Object that holds a Unk020eda5c at 0x58: its word at 0x14 is written, and it
// holds the Unk0206bcb0 at 0x1fc, a u16 at 0x1f8 and words from 0x200 to 0x20c.
typedef struct Unk020eda5c_1ec {
    /* 000 */ u8 mUnk_000[0x14];
    /* 014 */ u32 mUnk_014;
    /* 018 */ u8 mUnk_018[0x1d4];
    /* 1ec */ u16 mUnk_1ec;
    /* 1ee */ u8 mUnk_1ee[0xa];
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ Unk0206bcb0 *mUnk_1fc;
    /* 200 */ s32 mUnk_200;
    /* 204 */ s32 mUnk_204;
    /* 208 */ s32 mUnk_208;
} Unk020eda5c_1ec;

// The object behind the word at 0x590 of a Unk0206bcb0 from its first byte:
// the halfword at 0x40.
typedef struct Unk0206bcb0_590 {
    /* 000 */ u8 mUnk_000[0x40];
    /* 040 */ u16 mUnk_040;
} Unk0206bcb0_590;

// Three vectors at 0x00, 0x0c and 0x18.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020eda5c_02c;

// Object with three Unk020ed5c0 pointers at 0x14.
typedef struct Unk020eda5c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ Unk020eda5c_1ec *mUnk_00c;
    /* 010 */ Unk0206bcb0 *mUnk_010;
    /* 014 */ Unk020ed5c0 *mUnk_014[3];
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
    /* 090 */ u16 *mUnk_090;
    /* 094 */ u8 mUnk_094[0x54];
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ u8 mUnk_0ec[0x84];
    /* 170 */ void *mUnk_170;
    /* 174 */ u16 mUnk_174;
    /* 176 */ u16 mUnk_176;
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ Vec3 mUnk_180;
    /* 18c */ u16 mUnk_18c[3];
} Unk020eda5c;

#include "Main/Unknown/code_020f36d8.h"

void func_020ed5c0(Unk020ed5c0 *p, Unk020e6488 *q, Vec3 *v);
void func_020ed718(Unk020ed718 *p, void *a, void (*cb)(void *, void *, void *));
void func_020ed79c(Unk020ed718 *p, Vec3 *v);
void *func_020ed98c(Unk020ed5c0 *p, Vec3 *v);
void func_020eda5c(Unk020eda5c *p, Unk020ed5c0 *q);
void func_020edad8(Unk020eda5c *p);
void func_020edb00(Unk020eda5c *p);
s32 func_020edb8c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
s32 func_020edc9c(Unk020eda5c *p, s32 a, s32 b, s32 c, Vec3 *d);
void func_020eddb4(Unk020eda5c *p);
void func_020ee2e4(Unk020eda5c *a, Unk020f40dc *b);
s32 func_020ee528(Unk020eda5c *a);
void func_020edf10(Unk020eda5c *p);
void func_020ee160(Unk020ed5c0 *a, Unk020ed5c0 *b);
s32 func_020ee284(Unk020ed5c0 *p, Vec3 *v, s32 d);
