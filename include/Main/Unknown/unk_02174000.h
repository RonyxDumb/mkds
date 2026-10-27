#pragma once

#include "types.h"

// 0x18-byte elements of the table at member 0 of Unk02029930.
typedef struct Unk02029930_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
} Unk02029930_00;

// Object behind data_02174e1c, returned by func_02029930.
typedef struct Unk02029930 {
    /* 00 */ Unk02029930_00 mUnk_00[8];
    /* c0 */ u8 mUnk_c0[0x10];
    /* d0 */ s32 mUnk_d0;
} Unk02029930;

extern Unk02029930 *data_02174e1c;

// Objects whose layout isn't known yet.
extern u8 data_02174e14[];
extern u8 data_02174e18[];
extern u8 data_02174e24[];
extern u8 data_02174e28[];
extern u8 data_02174e3c[];
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
extern u8 data_02174e88[];

extern u8 data_02174e78[];

extern u8 data_02174e04[];
extern u8 data_02174e08[];
extern u8 data_02174e0c[];
extern u8 data_02174e10[];
