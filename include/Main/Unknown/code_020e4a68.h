#pragma once

#include "types.h"
#include "Main/Unknown/code_020e43a8.h"

// Read through Unk020e43a8's mUnk_9c; only the s16 at 0x28 is seen.
struct Unk020e4a68 {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ s16 mUnk_28;
};

void func_020e4a68(Unk020e43a8 *p);
