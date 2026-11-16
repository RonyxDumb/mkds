#pragma once

#include "types.h"

// Element of 8 bytes of Unk020ae630.field0.
typedef struct Unk020ae630_00 {
    /* 00 */ union {
        u32 field0;
        u8 field0_0;
    };
    /* 04 */ u32 field4;
} Unk020ae630_00;

// Object of 0x404 bytes: 0x80 elements of 8 bytes, then two halfwords.
typedef struct Unk020ae630 {
    /* 000 */ Unk020ae630_00 field0[0x80];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} Unk020ae630;

void oam_prepareBuffers(void *mainOam, void *subOam);
void oam_resetBuffers(void *mainOam, void *subOam);
void oam_clearResetBuffers(void *mainOam, void *subOam);
