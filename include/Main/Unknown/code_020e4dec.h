#pragma once

#include "types.h"

typedef struct Unk020e4dec {
    /* 00 */ u8 field0[0xac];
    /* ac */ u16 fieldAC;
} Unk020e4dec;

void puku_state0Init(Unk020e4dec *pukupuku);
