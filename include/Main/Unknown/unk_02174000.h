#pragma once

#include "types.h"
#include "Main/Unknown/code_02036588.h" // Unk02036590

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

// Objects whose layout isn't known yet.
extern u8 data_02174e14[];
extern u8 data_02174e18[];
extern u8 data_02174e24[];
extern u8 data_02174e28[];
extern u8 data_02174e40[];
extern u8 data_02174e44[];
extern u8 data_02174e48[];
extern u8 data_02174e4c[];
extern u8 data_02174e50[];
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
