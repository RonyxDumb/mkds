#pragma once

#include "types.h"

typedef struct Unk021d2060 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mCallback)(struct Unk021d2060 *, u32);
} Unk021d2060;

void func_ov003_021d2060(Unk021d2060 *object, u32 value);
