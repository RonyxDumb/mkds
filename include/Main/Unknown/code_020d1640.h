#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind sStatic2dData, allocated 0x2c bytes long by s2d_init.
typedef struct Unk0217b4b0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Ncgr *mUnk_08;
    /* 0c */ Unk02021dc8 *mUnk_0c;
    /* 10 */ Nclr *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ struct Bmg *mUnk_20;
    /* 24 */ Ncgr *mUnk_24;
    /* 28 */ Nclr *mUnk_28;
} Unk0217b4b0;

void s2d_init(void *heap);
