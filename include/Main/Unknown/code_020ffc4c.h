#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of kind 0xd2 (Dram) and the functions of this file: 0xc0 bytes.
typedef struct Dram {
    /* 00 */ MapObject field0;
    /* a0 */ u16 fieldA0;
    /* a2 */ u16 fieldA2;
    /* a4 */ u16 fieldA4;
    /* a6 */ u16 fieldA6;
    /* a8 */ s16 fieldA8;
    /* aa */ u8 fieldAA[2];
    /* ac */ s32 fieldAC;
    /* b0 */ s32 fieldB0;
    /* b4 */ s16 fieldB4[3];
    /* ba */ u8 fieldBA[2];
    /* bc */ s32 fieldBC;
} Dram;

void dram_spinStopStateUpdate(Dram *dram);
void dram_alignStateInit(Dram *dram);
