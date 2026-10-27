#pragma once

#include "types.h"

// First parameter of func_020e6fc4 and func_020e6fcc; the halfword at 0x04.
typedef struct Unk020e6fc4 {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ u16 mUnk_004;
} Unk020e6fc4;

void func_020e6fc4(Unk020e6fc4 *p, s32 n);
void func_020e6fcc(Unk020e6fc4 *p);
