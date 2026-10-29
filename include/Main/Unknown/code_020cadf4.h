#pragma once

#include "types.h"

// Object with a halfword at 0x04 that func_020cadf4, func_020cae6c and func_020cae7c set.
typedef struct Unk020cadf4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020cadf4;

void func_020cadf4(Unk020cadf4 *a);
