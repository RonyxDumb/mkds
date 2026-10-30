#pragma once

#include "types.h"

// Object with a halfword at 0x04.
typedef struct Unk020aca24 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020aca24;

void func_020aca24(Unk020aca24 *a);
