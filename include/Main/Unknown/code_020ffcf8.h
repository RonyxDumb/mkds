#pragma once

#include "types.h"

typedef struct Unk020ffcf8 {
    /* 00 */ u8 field0[0xac];
    /* ac */ u32 fieldAC;
} Unk020ffcf8;

void dram_spinStopStateInit(Unk020ffcf8 *dram);
