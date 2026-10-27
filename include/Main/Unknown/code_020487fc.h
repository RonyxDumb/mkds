#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // Unk021a9034

// Object passed as the first argument of func_020487fc.
typedef struct Unk020487fc {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
} Unk020487fc;

void func_020487fc(Unk020487fc *param_1, const Unk021a9034 *param_2);
