#pragma once

#include "types.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"

// Cell object from its first byte: a Unk020eda5c at 0x58, a Unk020f40dc at
// 0x030, a pointer at 0x1fc and words from 0x1f8 to 0x20c.
typedef struct Unk020ee684 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ struct Unk020ee684 *mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ u32 mUnk_028;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ Unk020f40dc mUnk_030;
    /* 058 */ Unk020eda5c mUnk_058;
    /* 1ec */ u16 mUnk_1ec;
    /* 1ee */ u8 mUnk_1ee[2];
    /* 1f0 */ Unk020f371c_Ref mUnk_1f0;
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ Unk0206bcb0 *mUnk_1fc;
    /* 200 */ s32 mUnk_200;
    /* 204 */ s32 mUnk_204;
    /* 208 */ s32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
} Unk020ee684;

// The Unk020eda5c of a cell from its first byte: five vectors from 0x090,
// three words at 0x0cc, the halfword at 0x028 and the counter at 0x16c.
typedef struct Unk020eda5c_090 {
    /* 000 */ u8 mUnk_000[0xc];
    /* 00c */ Unk020eda5c_1ec *mUnk_00c;
    /* 010 */ u8 mUnk_010[4];
    /* 014 */ Unk020f41c4_A *mUnk_014[3];
    /* 020 */ u8 mUnk_020[8];
    /* 028 */ u16 mUnk_028;
    /* 02a */ u8 mUnk_02a[2];
    /* 02c */ Unk020eda5c_02c mUnk_02c;
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ u8 mUnk_05c[0x1c];
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
} Unk020eda5c_090;

// The first object of a cell from its first byte, up to the vector at 0x09c.
typedef struct Unk020eda5c_09c {
    /* 000 */ u8 mUnk_000[0x9c];
    /* 09c */ Vec3 mUnk_09c;
} Unk020eda5c_09c;

// Element of the table behind data_0217562a.
typedef struct Unk0217562a {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x5a];
} Unk0217562a;

extern Unk0217562a data_0217562a[];

// Element at 0x7c of the object behind data_021759c0.
typedef struct Unk021759c0_7c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x2c];
} Unk021759c0_7c;

// The object behind data_021759c0 from its first byte: the elements at 0x7c.
typedef struct Unk021759c0_000 {
    /* 000 */ u8 mUnk_000[0x7c];
    /* 07c */ Unk021759c0_7c mUnk_07c[17];
} Unk021759c0_000;

// The object behind data_02175620 from its first byte: the halfword at 0x60
// and the word at 0xb0.
typedef struct Unk02175620_060 {
    /* 000 */ u8 mUnk_000[0x60];
    /* 060 */ u16 mUnk_060;
    /* 062 */ u8 mUnk_062[0x4e];
    /* 0b0 */ void *mUnk_0b0;
} Unk02175620_060;

// One element of the array at 0x04 of a Unk020f02c0.
typedef struct Unk020f02c0_04 {
    /* 000 */ u8 mUnk_000[0x4c];
    /* 04c */ u16 mUnk_04c;
} Unk020f02c0_04;

// Object with an allocated array of Unk020f02c0_04 pointers at 0x04.
typedef struct Unk020f02c0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020f02c0_04 **mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk020f02c0;

void func_020ee684(Unk020eda5c *a, Unk020eda5c_1ec *b);
void func_020ee6a8(Unk020eda5c *a);
void func_020ee6e8(Unk020eda5c *a, s32 i, Unk020f41c4_A *v);
void func_020ee748(Unk020eda5c *a);
void func_020ee9b0(Unk020eda5c *a);
void func_020eea6c(Unk020eda5c *a);
void func_020eec48(Unk020eda5c *a, s32 i, Unk020f41c4_A *v);
void func_020eecdc(Unk020eda5c *a);
void func_020ef1cc(Unk020eda5c_090 *p);
void func_020ef340(Unk020eda5c *a, Unk020f41c4_A *b, Unk020f41c4_A *c);
void func_020ef350(Unk020eda5c *a);
void func_020ef4a0(Unk020eda5c *a);
void func_020ef65c(Unk020eda5c *a, Vec3 *v, Vec3 *w);
void func_020ef8c4(Unk020eda5c *a);
void func_020ef9a8(Unk020eda5c *a);
void func_020efa48(Unk020eda5c *a, Unk020f41c4_A *v);
void func_020efa60(Unk020eda5c *a, s32 f);
void func_020efb84(Unk020eda5c *p, Unk020f41c4_A *v);
void func_020efbd4(Unk020ee684 *a, s32 n);
void func_020efc74(Unk020ee684 *p, s32 a);
void func_020efd1c(Unk020ee684 *p, Unk020f41c4_A *a);
s32 func_020efd84(Unk020ee684 *p, s32 a);
void func_020efea4(Unk020ee684 *p);
void func_020eff40(Unk020ee684 *p);
void func_020f0044(Unk020ee684 *p);
void func_020f00f0(Unk020ee684 *p);
s32 func_020f0154(Unk020ee684 *p);
void func_020f02c0(Unk020f02c0 *q, s32 a, s32 *b);
s32 func_020f03bc(Unk027e00cc *tab);
void func_020f03f8(Unk027e00cc *a);
void func_020f0684(Unk020f41c4_A **p, s32 i, s32 n, s32 step);
void func_020f0758(Unk027e00cc *a, s32 m, s32 b, u8 *c, s32 d);
s32 func_020f0898(Unk027e00cc *a, u8 *b);
s32 func_020f0950(Unk027e00cc *a, s32 b, s32 c);
void func_020f0b00(Unk027e00cc *tab, s32 a, void *b, s32 c);
void func_020f0d04(Unk020f41c4_A *p);
void func_020f0df8(Unk027e00cc *tab, void *a);
void func_020f0e2c(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f0ea0(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f0f70(Unk027e00cc *tab, Unk020f41c4_A *v);
void func_020f1048(Unk027e00cc *tab, s32 count, Unk020f41c4_A **out, u16 kind, Vec3 *v);
