#pragma once

#include "types.h"

typedef struct Unk021d1da8 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s16 mFrames;
    /* 06 */ u16 mFrameCount;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mEnabled;
} Unk021d1da8;

void func_ov003_021d1da8(u32 task, Unk021d1da8 *state);
