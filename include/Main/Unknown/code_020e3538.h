#pragma once

#include "types.h"

typedef struct Unk020e3538 {
    /* 00 */ u8 field0[0x2];
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[0x4];
    /* 08 */ u32 field8;
    /* 0c */ u8 fieldC[0x8];
    /* 14 */ u32 field14;
    /* 18 */ u8 field18[0x94];
    /* ac */ u32 fieldAC;
    /* b0 */ u8 fieldB0[0x8];
    /* b8 */ u16 fieldB8;
} Unk020e3538;

void choro_state1Init(Unk020e3538 *choropu);
