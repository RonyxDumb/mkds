#pragma once

#include "types.h"

typedef struct Unk020e35a0 {
    /* 00 */ u8 field0[0x2];
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[0x4];
    /* 08 */ u32 field8;
    /* 0c */ u8 fieldC[0x8];
    /* 14 */ u32 field14;
    /* 18 */ u8 field18[0x94];
    /* ac */ u32 fieldAC;
} Unk020e35a0;

void choro_state0Init(Unk020e35a0 *choropu);
