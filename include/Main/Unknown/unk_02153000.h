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

// 8-byte entries of the table at data_usa_02153554.
typedef struct Unk02153554 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk02153554;

// 8-byte entries at 0x90 of Unk02174e14, filled from data_021535b4.
typedef struct Unk021535b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk021535b4;

// 4-byte entries of the tables at data_021534bc, data_021534dc, data_02153500 and data_02153528.
typedef struct Unk021534bc {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021534bc;

extern Unk02153c1c data_02153c1c[];
extern Unk02153554 data_usa_02153554[];
extern Unk021534bc data_021534bc[];
extern Unk021534bc data_021534dc[];
extern Unk021534bc data_02153500[];
extern Unk021534bc data_02153528[];
extern Unk021535b4 data_021535b4[];
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
