#pragma once

#include "types.h"

typedef struct Unk020e4428 {
    /* 00 */ u8 field0[0x14c];
    /* 14c */ u32 field14C;
} Unk020e4428;

void rotcyl_state2Init(Unk020e4428 *object);
