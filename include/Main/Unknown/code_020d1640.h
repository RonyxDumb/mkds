#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind sStatic2dData, allocated 0x2c bytes long by s2d_init.
typedef struct Unk0217b4b0 {
    /* 00 */ void *field0;
    /* 04 */ void *field4;
    /* 08 */ Ncgr *field8;
    /* 0c */ Unk02021dc8 *fieldC;
    /* 10 */ Nclr *field10;
    /* 14 */ void *field14;
    /* 18 */ u8 field18[8];
    /* 20 */ struct Bmg *field20;
    /* 24 */ Ncgr *field24;
    /* 28 */ Nclr *field28;
} Unk0217b4b0;

void s2d_init(void *heap);
