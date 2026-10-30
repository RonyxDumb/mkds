#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"

// Vectors at 0x00, 0x0c, 0x18, 0x24, 0xf4, 0x100, 0x10c, 0x118 and 0x124 and a byte at 0x130.
typedef struct Unk02073904 {
    /* 000 */ Vec3 mUnk_000;
    /* 00c */ Vec3 mUnk_00c;
    /* 018 */ Vec3 mUnk_018;
    /* 024 */ Vec3 mUnk_024;
    /* 030 */ u8 mUnk_030[0xc4];
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ Vec3 mUnk_100;
    /* 10c */ Vec3 mUnk_10c;
    /* 118 */ Vec3 mUnk_118;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ u8 mUnk_130;
} Unk02073904;

extern s32 data_usa_021656a4;
extern s32 data_usa_021656a8;
extern s32 data_usa_021656ac;
extern s32 data_usa_021656b0;
extern s32 data_usa_021656bc;
extern s32 data_usa_021656c8;
extern s32 data_usa_021656cc[];

void func_02073904(Unk02073904 *p);
