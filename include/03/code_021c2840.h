#pragma once

#include "types.h"
#include "03/code_021c25e0.h"

typedef struct Unk021d6e24 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 pad_0c[0xc];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 pad_19[3];
} Unk021d6e24;

extern Unk021d6e24 data_ov003_021d6e24;

void func_ov003_021c2840(u32 a);

// Not decompiled yet.
u32 func_ov003_021d11d4(void);
