#pragma once

#include "types.h"

// Object passed to func_ov003_021d34e0, which stores its second argument at 0x08.
typedef struct Unk021d34e0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ UnkFunc *mUnk_08;
} Unk021d34e0;

void func_ov003_021d34e0(Unk021d34e0 *param_1, UnkFunc *param_2);
