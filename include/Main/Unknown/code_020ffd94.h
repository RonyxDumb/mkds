#pragma once

#include "types.h"

typedef struct Unk020ffd94 {
    /* 00 */ u8 field0[0xac];
    /* ac */ u32 fieldAC;
} Unk020ffd94;

void dram_spinStartStateInit(Unk020ffd94 *dram);
