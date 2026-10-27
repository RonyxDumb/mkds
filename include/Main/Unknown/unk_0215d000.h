#pragma once

#include "types.h"

// Four bytes: two column bounds, then two row bounds (inclusive).
typedef struct Unk0215d064 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0215d064;

extern s16 data_0215d040[];
extern u8 data_0215d044[][2];
extern u16 data_0215d054[];
extern Unk0215d064 data_0215d064[];
extern Unk0215d064 data_0215d080[];
extern u8 data_0215d09c[][2];
extern Unk0215d064 data_0215d0a0;
extern Unk0215d064 data_0215d0a4[];
extern Unk0215d064 data_0215d0ac[];

// Objects whose layout isn't known yet.
extern const s16 data_0215d4b4[];

extern u8 data_0215d00c[];
extern u8 data_0215d014[];
extern u8 data_0215d024[];
extern u8 data_0215d030[];
extern u8 data_0215d034[];
extern u8 data_0215d038[];
extern u8 data_0215d03c[];
extern u8 data_0215d03d[];
extern u8 data_0215d0c0[];
extern u8 data_0215d0cc[];
extern u8 data_0215d0e0[];
extern s8 data_0215d0b4[];
extern u8 data_0215d0e8[];
extern u8 data_0215d0f0[];
extern s16 data_0215d100[];
extern s16 data_0215d108[];
extern u8 data_0215d11c[];
extern u8 data_0215d122[];
extern u8 data_0215d128[];
extern u8 data_0215d134[][12];
extern u8 data_0215d14c[][12];
