#pragma once

#include "types.h"

typedef struct Unk020e58b8 {
    /* 00 */ u8 field0[0xc8];
    /* c8 */ u32 fieldC8;
} Unk020e58b8;

void shand_decelerateStateInit(Unk020e58b8 *secondHand);
