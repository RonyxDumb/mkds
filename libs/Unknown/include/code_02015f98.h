#pragma once

#include "types.h"

// 0x18-byte entry of the table at data_02161a18.
typedef struct Unk02015fa0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u32 mUnk_14;
} Unk02015fa0;

extern UnkFunc *data_021619ec;
extern UnkFunc *data_021619f0;
extern Unk02015fa0 *data_021619fc[2];
extern Unk02015fa0 *data_02161a04[5];
extern Unk02015fa0 data_02161a18[5];
extern u16 data_02173210;

s32 func_02015f98(void);
u32 func_02015fa0(u32 a, u32 b);
void func_02016134(void);
void func_020161b4(u32 a, u32 b);
void func_0201625c(u32 a, u32 b, u32 c, u32 d, u32 e);
