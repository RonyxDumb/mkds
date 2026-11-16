#pragma once

#include "types.h"

typedef struct Unk02089ecc {
    /* 00 */ u16 mTimer;
    /* 02 */ u16 field2;
    /* 04 */ u16 mColor;
    /* 06 */ u8 field6[0x2];
    /* 08 */ u32 mEnabled;
} Unk02089ecc;

void StartTimedQuad(Unk02089ecc *timedQuad);
