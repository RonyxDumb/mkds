#pragma once

#include "types.h"

typedef struct Unk020e44d8 {
    /* 00 */ u8 field0[0x14c];
    /* 14c */ u32 field14C;
} Unk020e44d8;

void rotcyl_state0Init(Unk020e44d8 *object);
