#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

// Object behind data_02174e24, 0x80c bytes (func_0202a658 allocates it).
typedef struct Unk0202a658 {
    /* 000 */ u8 mUnk_000[0x404];
    /* 404 */ u8 mUnk_404[0x404];
    /* 808 */ s32 mUnk_808;
} Unk0202a658;

void func_0202a658(void *a);
