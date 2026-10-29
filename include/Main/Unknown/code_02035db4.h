#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h"

// Object behind data_02174e6c, 0x654 bytes: the halfwords from 0x34 are 32 per row.
typedef struct Unk02174e6c {
    /* 000 */ void *mUnk_000;
    /* 004 */ u8 mUnk_004[0x20];
    /* 024 */ Unk02180728 mUnk_024;
    /* 034 */ u16 mUnk_034[0x300];
    /* 634 */ void *mUnk_634;
    /* 638 */ void *mUnk_638;
    /* 63c */ u8 mUnk_63c[4];
    /* 640 */ s32 mUnk_640;
    /* 644 */ u8 mUnk_644[8];
    /* 64c */ s32 mUnk_64c;
    /* 650 */ void *mUnk_650;
} Unk02174e6c;

s32 func_02035db4(u32 a);
