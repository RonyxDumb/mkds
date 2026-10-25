#pragma once

#include "types.h"
#include "00/code_02182fdc.h"

// Objects whose layout isn't known yet.
// Object behind data_ov001_021ca410.
typedef struct Unk021ca410 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ u8 mUnk_1c[0x2e];
    /* 4a */ s16 mUnk_4a;
} Unk021ca410;

// Object behind data_ov001_021ca414.
typedef struct Unk021ca414 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk021b4c74_16f0 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk021b4c74_16f0 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ u8 mUnk_1c[0x24];
    /* 40 */ Unk02124b1c *mUnk_40;
    /* 44 */ Unk02124b1c *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ u8 mUnk_4c[0x14];
    /* 60 */ u32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c[9];
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s16 mUnk_9c;
    /* 9e */ s16 mUnk_9e;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u8 mUnk_a4[4];
    /* a8 */ s32 mUnk_a8;
    /* ac */ u8 mUnk_ac[8];
    /* b4 */ void *mUnk_b4;
    /* b8 */ void *mUnk_b8;
    /* bc */ s32 mUnk_bc;
} Unk021ca414;

// One 0x40-byte element of the tables behind Unk021ca418::mUnk_14 and mUnk_18.
typedef struct Unk021ca418_Cell {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x3c];
} Unk021ca418_Cell;

// Object behind data_ov001_021ca418.
typedef struct Unk021ca418 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk021ca418_Cell *mUnk_14;
    /* 18 */ Unk021ca418_Cell *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ u8 mUnk_24[0x10];
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
} Unk021ca418;

extern u8 data_ov001_021ca400[];
extern u8 *data_ov001_021ca404;
extern u8 *data_ov001_021ca408;
extern u8 data_ov001_021ca40c[];
extern Unk021ca410 *data_ov001_021ca410;
extern Unk021ca414 *data_ov001_021ca414;
extern Unk021ca418 *data_ov001_021ca418;
extern u8 data_ov001_021ca424[];
