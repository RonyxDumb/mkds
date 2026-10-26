#pragma once

#include "types.h"
#include "Main/Unknown/code_02100000.h"

// Entry of the list returned by func_02100138(0x6c).
typedef struct Unk021816b4_ent {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk021816b4_ent;

// List of entries: an array of pointers and its length.
typedef struct Unk021816b4 {
    /* 00 */ Unk021816b4_ent **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021816b4;

s32 func_ov001_021816b4(void);
