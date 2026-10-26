#pragma once

#include "types.h"

typedef struct Unk020108bc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c; // size in units of 8 bytes
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u16 mUnk_10; // bit 0 set by func_020108bc
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ u32 mUnk_14; // byte offset from this struct
    /* 18 */ u32 mUnk_18;
    /* 1c */ u16 mUnk_1c; // size in units of 8 bytes
    /* 1e */ u8 mUnk_1e[2];
    /* 20 */ u16 mUnk_20; // bit 0 set by func_020108bc
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u32 mUnk_24; // byte offset from this struct
    /* 28 */ u32 mUnk_28; // byte offset from this struct
} Unk020108bc;

void func_020108bc(Unk020108bc *a, int b);
