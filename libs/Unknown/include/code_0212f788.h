#pragma once

#include "types.h"
#include "code_0212d254.h" // Unk0212f788

// 16 bytes. func_0212f834 sets mUnk_00, mUnk_04 and mUnk_0c and clears mUnk_08; func_0212f7e0 raises mUnk_08 up to
// mUnk_0c; func_0212f7f8 returns mUnk_00 + mUnk_08 * (mUnk_04 - mUnk_00) / mUnk_0c, or mUnk_04 once mUnk_08 reaches
// mUnk_0c.
typedef struct Unk0212f7c8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0212f7c8;

u32 *func_0212f788(Unk0212f788 *a, s32 b);
u32 func_0212f7c8(Unk0212f7c8 *a);
void func_0212f7e0(Unk0212f7c8 *a);
s32 func_0212f7f8(Unk0212f7c8 *a);
void func_0212f834(Unk0212f7c8 *a, s32 b, s32 c);
