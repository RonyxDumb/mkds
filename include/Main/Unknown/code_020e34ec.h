#pragma once

#include "types.h"

typedef struct Unk020e34ec {
    /* 00 */ u8 field0[0x14];
    /* 14 */ u32 field14;
} Unk020e34ec;

void choro_state2Init(Unk020e34ec *choropu);
