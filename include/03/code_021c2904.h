#pragma once

#include "types.h"

typedef struct Unk021c2904 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021c2904;

extern Unk021c2904 *data_ov003_021da198;

void func_ov003_021c2904(const Unk021c2904 *value);
