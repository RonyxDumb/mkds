#pragma once

#include "types.h"
#include "code_02022aa8.h"

// 12-byte entries of the table at data_02153c1c.
typedef struct Unk02153c1c {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s32 mUnk_08;
} Unk02153c1c;

// 0x32-byte entries of the table at data_02153c58.
typedef struct Unk02153c58 {
    /* 00 */ u16 mUnk_00[0x18];
    /* 30 */ u16 mUnk_30;
} Unk02153c58;

extern Unk02153c1c data_02153c1c[];
extern Unk02153c58 data_02153c58[];

// Objects whose layout isn't known yet.
extern u8 data_021533fc[];

extern u8 data_0215316c[];

extern u8 data_021532a8[];
extern u8 data_021532dc[];
extern u8 data_0215336c[];
extern u16 data_021530b8[4][4];
extern u16 data_021530d0[4][4];
extern Unk02022aa8_f *data_021530e8[];
extern u32 data_02153118[][4];
