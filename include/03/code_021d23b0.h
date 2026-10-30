#pragma once

#include "types.h"
#include "03/code_021d2fa0.h"

typedef struct Unk021d23b0 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct Unk021d23b0 *a, u32 b);
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ struct Unk021d23b0 *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ Unk021d309c *mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
} Unk021d23b0;

Unk021d23b0 *func_ov003_021d23b0(u32 a, u8 b, u8 c, s32 d, u32 *e, s32 f);
