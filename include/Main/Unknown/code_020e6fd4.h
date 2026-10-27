#pragma once

#include "types.h"
#include "code_02146d78.h"

// Object behind Unk020e71a0.mUnk_94, passed to func_0210cfbc.
typedef struct Unk020e71a0_94 {
    /* 00 */ u8 mUnk_00[0x34];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[0x0a];
    /* 40 */ s32 mUnk_40;
} Unk020e71a0_94;

// Element object up to 0xa0: func_020e705c and func_020e71a0 read 0x78 and 0x94 of every object; 0x80 to 0x92 are
// read only by the functions of Unk020ffb1c so far. From 0xa0 on, the objects of func_020e72cc, func_020ffb1c and
// func_020ff97c use the bytes in different ways.
typedef struct Unk020e71a0 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ Unk02012f58 mUnk_28;
    /* 58 */ u8 mUnk_58[0x20];
    /* 78 */ u32 mUnk_78;
    /* 7c */ u8 mUnk_7c[4];
    /* 80 */ u8 mUnk_80[4];
    /* 84 */ u32 mUnk_84;
    /* 88 */ u8 mUnk_88[6];
    /* 8e */ u16 mUnk_8e;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u16 mUnk_92;
    /* 94 */ Unk020e71a0_94 *mUnk_94;
    /* 98 */ u8 mUnk_98[8];
} Unk020e71a0;

// Object of func_020e72cc and func_020e730c: two u16s after the shared part.
typedef struct Unk020e730c {
    /* 00 */ Unk020e71a0 mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
} Unk020e730c;

// Container used by func_020e6fd4: a pointer array at 0x00, a u16 at 0x04, a
// function pointer at 0x1c and a word at 0x20.
typedef struct Unk020e6fd4 {
    /* 00 */ void **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x16];
    /* 1c */ void (*mUnk_1c)(Unk020e71a0 *e, s32 z, u8 *a, u8 *b);
    /* 20 */ s32 mUnk_20;
} Unk020e6fd4;

// Container used by func_020e705c: a pointer array at 0x00, a u16 at 0x04, a
// function pointer at 0x10 and a word at 0x18.
typedef struct Unk020e705c {
    /* 00 */ void **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x0a];
    /* 10 */ void (*mUnk_10)(void *p, Unk020e71a0 *e);
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c[8];
    /* 24 */ void **mUnk_24;
} Unk020e705c;

// Second argument of func_020e72cc.
typedef struct Unk020e72cc {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
} Unk020e72cc;

void func_020e6fd4(Unk020e6fd4 *p);
void func_020e705c(Unk020e705c *p);
void func_020e71a0(Unk020e71a0 *p);
void func_020e72cc(Unk020e730c *p, Unk020e72cc *q);
void func_020e730c(void);
