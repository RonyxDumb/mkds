#pragma once

#include "types.h"

typedef struct Unk021a6fa8 {
    /* 00 */ u8 mUnk_00[0x64];
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
} Unk021a6fa8;

s32 func_ov000_021a6fa8(Unk021a6fa8 *object, void *request);
