#pragma once

#include "types.h"
#include "Main/Unknown/code_02025ebc.h" // Unk02025ebc
#include "Main/Unknown/code_02036588.h" // Unk02036590
#include "Main/Unknown/unk_02153000.h" // Unk021535b4

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

// 0x40-byte entries of the table at member 0x18 of Unk02174e14_00.
typedef struct Unk02174e14_00_18 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[0x20];
    /* 34 */ s32 mUnk_34;
    /* 38 */ u8 mUnk_38[8];
} Unk02174e14_00_18;

// 0x1c-byte part of Unk02174e14, at 0x00, 0x1c and 0x38; func_02026910 has two on the stack, one filled by
// func_02025b84.
typedef struct Unk02174e14_00 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ Unk02174e14_00_18 *mUnk_18;
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

// Objects whose layout isn't known yet.
extern u8 data_02174e18[];
extern u8 data_02174e24[];
extern u8 data_02174e28[];
extern u8 data_02174e40[];
extern u8 data_02174e44[];
extern u8 data_02174e48[];
extern struct Unk02174e4c *data_02174e4c;
extern struct Unk02174e50 *data_02174e50;
extern u8 data_02174e54[];
extern u8 data_02174e58[];
extern u8 data_02174e60[];
extern u8 data_02174e64[];
extern u8 data_02174e68[];
extern u8 data_02174e6c[];
extern u8 data_02174e70[];

extern u8 data_02174e78[];

extern u8 data_02174e04[];
extern u8 data_02174e08[];
extern u8 data_02174e0c[];
extern u8 data_02174e10[];
