#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "code_02004dc0.h" // Unk020055f0, Unk02003024
#include "code_0212da38.h" // Unk02017328

// Objects whose layout isn't known yet.
// What data_0217aa08 points to.
typedef struct Unk0217aa08_00 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u8 mUnk_20[0x11];
    /* 31 */ union {
        u8 mUnk_31;
        struct {
            u8 mUnk_31_0 : 1;
            u8 mUnk_31_1 : 2;
            u8 mUnk_31_3 : 1;
            u8 mUnk_31_4 : 1;
            u8 mUnk_31_5 : 3;
        };
    };
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x40];
} Unk0217aa08_00;

typedef struct Unk0217aa08_04 {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ u8 mUnk_004 : 1;
    /* 005 */ u8 mUnk_005[0x3];
    /* 008 */ u8 mUnk_008[0x200];
} Unk0217aa08_04;

typedef struct Unk0217aa08 {
    /* 00 */ Unk0217aa08_00 *mUnk_00;
    /* 04 */ Unk0217aa08_04 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ u8 mUnk_28;
} Unk0217aa08;

// Elements of the array at member 0x1e52 of data_0217aa00.
typedef struct Unk0217aa00_1e52 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
} Unk0217aa00_1e52;

// Object behind data_0217aa00.
typedef struct Unk0217aa00 {
    /* 0000 */ u32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ u8 mUnk_0008[0x42a];
    /* 0432 */ u16 mUnk_0432;
    /* 0434 */ u8 mUnk_0434[0x20];
    /* 0454 */ u16 mUnk_0454;
    /* 0456 */ u8 mUnk_0456[0x11a0];
    /* 15f6 */ u8 mUnk_15f6;
    /* 15f7 */ u8 mUnk_15f7[0x85b];
    /* 1e52 */ Unk0217aa00_1e52 mUnk_1e52[18];
    /* 1ee2 */ u8 mUnk_1ee2[6];
    /* 1ee8 */ Unk020f41c4_B mUnk_1ee8;
} Unk0217aa00;

extern Unk0217aa00 *data_0217aa00;
extern Unk0217aa08 *data_0217aa08;
extern u8 data_0217aa0c[];
// 0xc-byte entries from 0x08 of Unk0217aa10.
typedef struct Unk0217aa10_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk0217aa10_08;

struct Unk02017584;

// Object behind data_0217aa10; func_0212034c reads the word at 0. The objects at 0x2c and 0x58 are passed to
// func_02005314 and func_02004d80, the pointer at 0xa4 to func_0201797c.
typedef struct Unk0217aa10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217aa10_08 mUnk_08[3];
    /* 2c */ Unk020055f0 mUnk_2c;
    /* 58 */ Unk02003024 mUnk_58;
    /* a0 */ void *mUnk_a0;
    /* a4 */ struct Unk02017584 *mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk0217aa10;

extern Unk0217aa10 *data_0217aa10;
// Object behind data_0217aa14.
typedef struct Unk0217aa14 {
    /* 000 */ u8 mUnk_000[0x10];
    /* 010 */ u16 mUnk_010;
    /* 012 */ u16 mUnk_012;
    /* 014 */ u8 mUnk_014[0x710];
    /* 724 */ u16 mUnk_724;
    /* 726 */ u8 mUnk_726[0x36];
    /* 75c */ u16 mUnk_75c;
} Unk0217aa14;

extern Unk0217aa14 *data_0217aa14;
extern u8 data_0217aa54[];
extern u8 data_0217aa64[];
// Object behind data_0217aa6c, returned by func_02061808.
typedef struct Unk02061808 {
    /* 000 */ u8 mUnk_000[0xc];
    /* 00c */ s32 mUnk_0c;
    /* 010 */ u8 mUnk_010[0x4];
    /* 014 */ s32 mUnk_14;
    /* 018 */ u8 mUnk_018[0xc];
    /* 024 */ Vec3 mUnk_024;
    /* 030 */ u8 mUnk_030[0x38];
    /* 068 */ s16 mUnk_068;
    /* 06a */ s16 mUnk_06a;
    /* 06c */ u8 mUnk_06c[0xf0];
    /* 15c */ s32 mUnk_15c;
    /* 160 */ s32 mUnk_160;
    /* 164 */ s32 mUnk_164;
} Unk02061808;

extern Unk02061808 *data_0217aa6c;
extern u8 data_0217aa7c[];
extern u8 data_0217ac94[];
extern u8 data_0217aca8[];
extern u8 data_0217acb4[];
extern u8 data_0217acbc[];
extern u8 data_0217acc0[];
// Object behind data_0217ad00 (0x144 bytes); the addresses of 0x2c, 0x98 and 0x10c are passed on as objects.
typedef struct Unk0217ad00 {
    /* 000 */ void *mUnk_000;
    /* 004 */ void *mUnk_004;
    /* 008 */ u16 mUnk_008;
    /* 00a */ u8 mUnk_00a[2];
    /* 00c */ void *mUnk_00c;
    /* 010 */ void *mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ s16 mUnk_018[8];
    /* 028 */ void *mUnk_028;
    /* 02c */ u8 mUnk_02c[4];
    /* 030 */ s32 mUnk_030;
    /* 034 */ u8 mUnk_034[0x50];
    /* 084 */ s32 mUnk_084;
    /* 088 */ u8 mUnk_088[8];
    /* 090 */ void *mUnk_090;
    /* 094 */ void *mUnk_094;
    /* 098 */ u8 mUnk_098[4];
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ u8 mUnk_0a0[0x64];
    /* 104 */ u16 mUnk_104;
    /* 106 */ u16 mUnk_106;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u8 mUnk_10a[0xe];
    /* 118 */ s32 mUnk_118;
    /* 11c */ u8 mUnk_11c[4];
    /* 120 */ void *mUnk_120;
    /* 124 */ u16 mUnk_124;
    /* 126 */ u16 mUnk_126;
    /* 128 */ void *mUnk_128;
    /* 12c */ void *mUnk_12c;
    /* 130 */ u8 mUnk_130[4];
    /* 134 */ void *mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
} Unk0217ad00;

extern Unk0217ad00 *data_0217ad00;

// 0xb8-byte entries from 0x58 of Unk0217ad08.
typedef struct Unk0217ad08_058 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x8c];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
} Unk0217ad08_058;

struct Unk020136f0;

// 0x34-byte entries from 0x1f4 of Unk0217ad08; the pointers at 0x08 to 0x28 are passed to func_02012b30.
typedef struct Unk0217ad08_1f4 {
    /* 00 */ void *mUnk_00;
    /* 04 */ struct Unk02017584 *mUnk_04;
    /* 08 */ struct Unk020136f0 *mUnk_08;
    /* 0c */ struct Unk020136f0 *mUnk_0c;
    /* 10 */ struct Unk020136f0 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ struct Unk020136f0 *mUnk_18;
    /* 1c */ struct Unk020136f0 *mUnk_1c;
    /* 20 */ struct Unk020136f0 *mUnk_20;
    /* 24 */ struct Unk020136f0 *mUnk_24;
    /* 28 */ struct Unk020136f0 *mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[2];
} Unk0217ad08_1f4;

// Object behind data_0217ad08.
typedef struct Unk0217ad08 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s16 mUnk_00c;
    /* 00e */ s16 mUnk_00e;
    /* 010 */ s16 mUnk_010;
    /* 012 */ s16 mUnk_012;
    /* 014 */ s16 mUnk_014;
    /* 016 */ s16 mUnk_016;
    /* 018 */ void *mUnk_018;
    /* 01c */ void *mUnk_01c;
    /* 020 */ void *mUnk_020;
    /* 024 */ void *mUnk_024;
    /* 028 */ void *mUnk_028;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ s32 mUnk_030;
    /* 034 */ s32 mUnk_034;
    /* 038 */ u16 mUnk_038;
    /* 03a */ u16 mUnk_03a;
    /* 03c */ s16 mUnk_03c;
    /* 03e */ u16 mUnk_03e;
    /* 040 */ u8 mUnk_040[0x10];
    /* 050 */ s32 mUnk_050;
    /* 054 */ s32 mUnk_054;
    /* 058 */ Unk0217ad08_058 mUnk_058[2];
    /* 1c8 */ s32 mUnk_1c8;
    /* 1cc */ void *mUnk_1cc;
    /* 1d0 */ void *mUnk_1d0;
    /* 1d4 */ void *mUnk_1d4;
    /* 1d8 */ void *mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ void *mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ s16 mUnk_1f0;
    /* 1f2 */ u8 mUnk_1f2[2];
    /* 1f4 */ Unk0217ad08_1f4 mUnk_1f4[2];
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ s16 mUnk_264;
    /* 266 */ s16 mUnk_266;
    /* 268 */ void *mUnk_268;
} Unk0217ad08;

extern Unk0217ad08 *data_0217ad08;
extern u8 data_0217ad10[];
extern u8 data_0217ad24[];
extern u8 data_0217ad28[];
extern u8 data_0217ad2c[];
extern u8 data_0217ad30[];
struct Unk0201ca6c;

// 0x58-byte entries of the table behind data_0217ae84; the pointers at 0x0c and
// 0x10 to 0x30 hold objects returned by func_0208b7bc.
typedef struct Unk0217ae84 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ struct Unk0201ca6c *mUnk_0c;
    /* 10 */ struct Unk0201ca6c *mUnk_10[4];
    /* 20 */ struct Unk0201ca6c *mUnk_20;
    /* 24 */ struct Unk0201ca6c *mUnk_24;
    /* 28 */ struct Unk0201ca6c *mUnk_28;
    /* 2c */ struct Unk0201ca6c *mUnk_2c;
    /* 30 */ struct Unk0201ca6c *mUnk_30;
    /* 34 */ u8 mUnk_34[0x18];
    /* 4c */ u8 mUnk_4c[0xc];
} Unk0217ae84;

extern Unk0217ae84 *data_0217ae84;
extern u16 data_0217ae6c;
extern struct Unk0201ca6c **data_0217ae74;
extern struct Unk0201ca6c **data_0217ae7c;
extern u16 *data_0217ae8c;
extern s32 data_0217ae90;
extern struct Unk0201ca6c **data_0217ae94;
extern s32 data_0217ae98;

// Object behind data_0217aebc, 0x144 bytes: word tables of eight entries, the eight
// 0xc-byte entries at 0xb0 passed to func_020174a4, and the list at 0x12c.
typedef struct Unk0217aebc {
    /* 000 */ s32 mUnk_000[8];
    /* 020 */ s32 mUnk_020[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ s32 mUnk_060[8];
    /* 080 */ s32 mUnk_080;
    /* 084 */ s32 mUnk_084;
    /* 088 */ s32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090[8];
    /* 0b0 */ u8 mUnk_0b0[8][0xc];
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114[2];
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s16 mUnk_124;
    /* 126 */ u8 mUnk_126[2];
    /* 128 */ void *mUnk_128;
    /* 12c */ Unk02017328 mUnk_12c;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s16 mUnk_13c;
    /* 13e */ s16 mUnk_13e[3];
} Unk0217aebc;

extern Unk0217aebc *data_0217aebc;
extern u8 data_0217aec0[];
extern u8 data_0217aec4[];
extern u8 data_0217aec8[];
extern u8 *data_0217aecc;
extern Vec3 *data_0217aed8;
extern u8 data_0217aee0[];

// Object behind data_0217aed0, 0x194 bytes: tables of eight entries.
typedef struct Unk0217aed0 {
    /* 000 */ s32 mUnk_000[8];
    /* 020 */ s32 mUnk_020;
    /* 024 */ s16 mUnk_024[8];
    /* 034 */ s16 mUnk_034[8];
    /* 044 */ u16 mUnk_044[8];
    /* 054 */ s32 mUnk_054[8];
    /* 074 */ u16 mUnk_074[8];
    /* 084 */ s16 mUnk_084[8];
    /* 094 */ u16 mUnk_094[8];
    /* 0a4 */ s32 mUnk_0a4[8];
    /* 0c4 */ s32 mUnk_0c4[8];
    /* 0e4 */ s32 mUnk_0e4[8];
    /* 104 */ s32 mUnk_104[8];
    /* 124 */ void *mUnk_124[8];
    /* 144 */ void *mUnk_144[8];
    /* 164 */ void *mUnk_164[8];
    /* 184 */ s32 mUnk_184;
    /* 188 */ s32 mUnk_188;
    /* 18c */ u8 mUnk_18c[8];
} Unk0217aed0;

extern Unk0217aed0 *data_0217aed0;
extern s32 data_0217af24;
extern u8 data_0217af28[];

extern u8 data_0217aa04[];
extern u8 data_0217aa24[];
extern u8 data_0217aa2c[];
extern u8 data_0217acac[];

extern u8 data_0217aa18[];
// 0xa-byte elements of the rows (eight each) of the table at member 0 of Unk0217aa1c.
typedef struct Unk0217aa1c_00 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06[4];
} Unk0217aa1c_00;

// 4-byte object, two of which make an element of the table at member 0x144 of Unk0217aa1c.
typedef struct Unk0217aa1c_144_00 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0217aa1c_144_00;

// 8-byte elements of the table at member 0x144 of Unk0217aa1c.
typedef struct Unk0217aa1c_144 {
    /* 00 */ Unk0217aa1c_144_00 mUnk_00[2];
} Unk0217aa1c_144;

// Object behind data_0217aa1c.
typedef struct Unk0217aa1c {
    /* 000 */ Unk0217aa1c_00 mUnk_000[4][8];
    /* 140 */ u8 mUnk_140[4];
    /* 144 */ Unk0217aa1c_144 mUnk_144[4];
} Unk0217aa1c;

extern Unk0217aa1c *data_0217aa1c;
extern u8 data_0217ad18[];
extern u8 data_0217aeb0[];
