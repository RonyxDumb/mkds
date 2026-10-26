#pragma once

#include "types.h"
#include "code_0212c478.h" // Unk0212c400
#include "code_0212da38.h" // Unk0212d9dc

// Memory func_0212c700 gets from func_0212db7c: mUnk_08 is the Unk0212d9dc it sets up on mUnk_14, mUnk_10 the index
// of the data_0217d89c element whose list receives it.
typedef struct Unk0212c700 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk0212d9dc *mUnk_08;
    /* 0c */ Unk0212c400 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[1];
} Unk0212c700;

void func_0212c6ac(u32 a);
void func_0212c6f0(Unk0212c400 **a, u32 b);
s32 func_0212c700(u32 a, Unk0212d9dc *b, u32 c);
