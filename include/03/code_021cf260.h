#pragma once

#include "types.h"
#include "03/unk_021da000.h"

// One 0x1e-byte record of Unk021cf260.
typedef struct Unk021cf260_0e {
    /* 00 */ u8 mUnk_00[0x16];
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
} Unk021cf260_0e;

struct Unk021cf260 {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mMask;
    /* 0004 */ u16 mUnk_04;
    /* 0006 */ u16 mUnk_06;
    /* 0008 */ u16 mUnk_08;
    /* 000a */ u16 mUnk_0a;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ Unk021cf260_0e mRecords[15];
    /* 01d0 */ u8 mUnk_01d0[0xfe70];
    /* 10040 */ u8 mUnk_10040[0xb100];
    /* 1b140 */ void *mUnk_1b140;
    /* 1b144 */ void *mUnk_1b144;
};

void *func_ov003_021cf260(u32 index);
