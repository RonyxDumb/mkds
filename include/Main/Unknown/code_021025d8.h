#pragma once

#include "types.h"

typedef struct ItemTeresa ItemTeresa;

void ResetItemTeresa(ItemTeresa *teresa);
typedef struct Unk02102668 {
    /* 00 */ u8 mUnk_00[0x170];
    /* 170 */ u32 mUnk_170;
} Unk02102668;

void func_02102668(Unk02102668 *inUse);
