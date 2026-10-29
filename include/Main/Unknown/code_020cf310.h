#pragma once

#include "types.h"

// Halfwords written by func_020cf340 (it writes up to element 0xf5).
typedef struct Unk020cf340 {
    /* 000 */ u16 mUnk_00[0xf6];
} Unk020cf340;

s32 func_020cf310(void);
void func_020cf340(Unk020cf340 *a);
void func_020cfca4(void);
