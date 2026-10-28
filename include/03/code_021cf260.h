#pragma once

#include "types.h"

typedef struct Unk021cf260 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mMask;
    /* 04 */ u8 mUnk_04[0xa];
    /* 0e */ u8 mRecords[1];
} Unk021cf260;

void *func_ov003_021cf260(u32 index);
