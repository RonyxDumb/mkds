#pragma once

#include "types.h"

// 16 bytes: an index into data_02152c54 and three words passed to the function it selects.
typedef struct Unk02016638 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02016638;

void func_02016638(Unk02016638 *p);
