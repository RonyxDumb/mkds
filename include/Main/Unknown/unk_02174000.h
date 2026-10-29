#pragma once

#include "types.h"
#include "Main/Unknown/code_02025ebc.h" // Unk02025ebc
#include "Main/Unknown/code_02036588.h" // Unk02036590
#include "Main/Unknown/unk_02153000.h" // Unk021535b4
#include "Main/Unknown/code_020b4000.h" // Unk020b4934, Unk020b47d8, Unk020b4a44
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30
#include "Main/Unknown/code_020b3f7c.h" // Unk020b3fb0

// 0x18-byte elements of the table at member 0 of Unk02029930.
typedef struct Unk02029930_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk02029930_00;

// 0x2c-byte rows of the table at member 0xf8 of Unk02029930.
typedef struct Unk02029930_f8 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07[0x25];
} Unk02029930_f8;

// Object behind data_02174e1c, returned by func_02029930.
typedef struct Unk02029930 {
    /* 00 */ Unk02029930_00 mUnk_00[8];
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ u16 mUnk_e8;
    /* ea */ u8 mUnk_ea[2];
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ u8 mUnk_f4[4];
    /* f8 */ Unk02029930_f8 *mUnk_f8;
    /* fc */ s8 mUnk_fc;
    /* fd */ s8 mUnk_fd;
    /* fe */ u8 mUnk_fe[6];
    /* 104 */ u16 mUnk_104;
    /* 106 */ u8 mUnk_106[2];
    /* 108 */ s32 mUnk_108;
} Unk02029930;

extern Unk02029930 *data_02174e1c;

// Four words at 0x04 of Unk02174e3c_4c.
typedef struct Unk02174e3c_4c_04 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk02174e3c_4c_04;

// 0x2c-byte entries from 0x4c of Unk02174e3c.
typedef struct Unk02174e3c_4c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk02174e3c_4c_04 mUnk_04;
    /* 14 */ u8 mUnk_14[0x18];
} Unk02174e3c_4c;

// Object behind data_02174e3c.
typedef struct Unk02174e3c {
    /* 00 */ u8 mUnk_00[0x4c];
    /* 4c */ Unk02174e3c_4c mUnk_4c[8];
} Unk02174e3c;

extern Unk02174e3c *data_02174e3c;
extern Unk02036590 data_02174e88;

// 0x1c-byte part of Unk02174e14, at 0x00, 0x1c and 0x38; func_02026910 has two on the stack, one filled by
// func_02025b84. Unk02174e60 has four from 0x48.
typedef struct Unk02174e14_00 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk0201ea30 *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk0201ea30 *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
} Unk02174e14_00;

// Object behind data_02174e14.
typedef struct Unk02174e14 {
    /* 000 */ Unk02174e14_00 mUnk_000;
    /* 01c */ Unk02174e14_00 mUnk_01c;
    /* 038 */ Unk02174e14_00 mUnk_038;
    /* 054 */ void *mUnk_054;
    /* 058 */ void *mUnk_058;
    /* 05c */ void *mUnk_05c;
    /* 060 */ s32 mUnk_060;
    /* 064 */ s32 mUnk_064;
    /* 068 */ s32 mUnk_068;
    /* 06c */ s32 mUnk_06c;
    /* 070 */ s32 mUnk_070;
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[2];
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 084 */ s16 mUnk_084;
    /* 086 */ s16 mUnk_086;
    /* 088 */ s16 mUnk_088;
    /* 08a */ s16 mUnk_08a;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ Unk021535b4 mUnk_090[12];
    /* 0f0 */ s32 mUnk_0f0;
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ Unk02025ebc mUnk_0f8;
    /* 108 */ Unk02025ebc mUnk_108;
    /* 118 */ Unk02025ebc mUnk_118;
    /* 128 */ s32 mUnk_128;
} Unk02174e14;

extern Unk02174e14 *data_02174e14;

// 0x24-byte part of Unk02174e60, at 0x00 and 0x24, filled by func_02025884.
typedef struct Unk02174e60_00 {
    /* 00 */ Unk020b4934 *mUnk_00[4];
    /* 10 */ Unk020b4a44 *mUnk_10;
    /* 14 */ Unk020b47d8 *mUnk_14[4];
} Unk02174e60_00;

// 0xc-byte entries from 0xe4 of Unk02174e60.
typedef struct Unk02174e60_e4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02174e60_e4;

// Object behind data_02174e60: 0x154 bytes allocated by func_02032f94.
typedef struct Unk02174e60 {
    /* 000 */ Unk02174e60_00 mUnk_000[2];
    /* 048 */ Unk02174e14_00 mUnk_048[4];
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ u32 mUnk_0c0;
    /* 0c4 */ u32 mUnk_0c4;
    /* 0c8 */ void *mUnk_0c8;
    /* 0cc */ u8 mUnk_0cc[4];
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ Unk02174e60_e4 mUnk_0e4[8];
    /* 144 */ u8 mUnk_144[4];
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
} Unk02174e60;

extern Unk02174e60 *data_02174e60;

// 0x28-byte part of the entries from 0x9c of Unk02174e64; func_02034370 fills one on the stack through
// func_0204ebb8 and func_02034e68 compares two.
typedef struct Unk02174e64_9c_00 {
    /* 00 */ u16 mUnk_00[11];
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26;
    /* 27 */ u8 mUnk_27;
} Unk02174e64_9c_00;

// 0x3c-byte entries from 0x9c of Unk02174e64.
typedef struct Unk02174e64_9c {
    /* 00 */ Unk02174e64_9c_00 mUnk_00;
    /* 28 */ s32 mUnk_28;
    /* 2c */ Unk02025ebc mUnk_2c;
} Unk02174e64_9c;

// Object behind data_02174e64.
typedef struct Unk02174e64 {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ void *mUnk_024[2];
    /* 02c */ Unk02174e14_00 mUnk_02c[2];
    /* 064 */ u8 mUnk_064[0x1c];
    /* 080 */ s32 mUnk_080;
    /* 084 */ Unk020b3fb0 *mUnk_084;
    /* 088 */ Unk020b3fb0 *mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090;
    /* 094 */ s32 mUnk_094;
    /* 098 */ s32 mUnk_098;
    /* 09c */ Unk02174e64_9c mUnk_09c[4];
    /* 18c */ s32 mUnk_18c;
    /* 190 */ s32 mUnk_190;
    /* 194 */ Unk02025ebc mUnk_194;
    /* 1a4 */ void *mUnk_1a4;
} Unk02174e64;

extern Unk02174e64 *data_02174e64;

// Objects whose layout isn't known yet.
extern u8 data_02174e18[];
extern u8 data_02174e24[];
extern u8 data_02174e28[];
typedef struct Unk02174e40 {
    /* 000 */ u8 mUnk_000[0xc];
    /* 00c */ void *mUnk_00c;
    /* 010 */ void *mUnk_010;
    /* 014 */ u8 mUnk_014[8];
    /* 01c */ void *mUnk_01c;
    /* 020 */ void *mUnk_020;
    /* 024 */ u8 mUnk_024[0xc];
    /* 030 */ void *mUnk_030;
    /* 034 */ void *mUnk_034;
    /* 038 */ u8 mUnk_038[0xc];
    /* 044 */ void *mUnk_044;
    /* 048 */ s32 mUnk_048;
    /* 04c */ s32 mUnk_04c;
    /* 050 */ s32 mUnk_050;
    /* 054 */ void *mUnk_054;
    /* 058 */ u8 mUnk_058[4];
    /* 05c */ void *mUnk_05c;
    /* 060 */ void *mUnk_060;
    /* 064 */ void *mUnk_064;
    /* 068 */ void *mUnk_068;
    /* 06c */ s32 mUnk_06c;
    /* 070 */ void *mUnk_070;
    /* 074 */ s32 mUnk_074;
    /* 078 */ void *mUnk_078;
    /* 07c */ void *mUnk_07c;
    /* 080 */ void *mUnk_080;
    /* 084 */ void *mUnk_084;
    /* 088 */ u8 mUnk_088[0x1c];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ u8 mUnk_0b4[4];
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ void *mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ u16 mUnk_0cc;
    /* 0ce */ u16 mUnk_0ce;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ u8 mUnk_0e8[0x34];
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ u8 mUnk_12c[0x38];
    /* 164 */ s32 mUnk_164;
    /* 168 */ u8 mUnk_168[0x14];
    /* 17c */ s32 mUnk_17c;
    /* 180 */ u8 mUnk_180[0x38];
    /* 1b8 */ s32 mUnk_1b8;
} Unk02174e40;

extern Unk02174e40 *data_02174e40;
extern u8 data_02174e44[];
typedef struct Unk02174e48 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} Unk02174e48;

extern Unk02174e48 *data_02174e48;
extern struct Unk02174e4c *data_02174e4c;
extern struct Unk02174e50 *data_02174e50;
extern struct Unk02174e54 *data_02174e54;
extern u8 data_02174e58[];
// Object behind data_02174e68, 0xa8 bytes.
typedef struct Unk02174e68 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 *mUnk_20;
    /* 24 */ void *mUnk_24[2];
    /* 2c */ Unk02174e14_00 mUnk_2c[2];
    /* 64 */ u8 mUnk_64[0x1c];
    /* 80 */ s32 mUnk_80;
    /* 84 */ Unk020b3fb0 *mUnk_84;
    /* 88 */ Unk020b3fb0 *mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ Unk02025ebc mUnk_90;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ void *mUnk_a4;
} Unk02174e68;

extern Unk02174e68 *data_02174e68;
extern u8 data_02174e6c[];
extern u8 data_02174e70[];

extern u8 data_02174e78[];

extern u8 data_02174e04[];
extern u8 data_02174e08[];
extern u8 data_02174e0c[];
extern u8 data_02174e10[];
