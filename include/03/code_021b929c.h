#pragma once

#include "types.h"
#include "03/code_021b94b8.h"

typedef struct Unk021d8374 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x28];
    /* 30 */ u8 mUnk_30[0x40];
    /* 70 */ u8 mUnk_70[0x40];
    /* b0 */ u8 mUnk_b0[0x40];
    /* f0 */ u8 mUnk_f0[0x40];
} Unk021d8374;

extern Unk021d8374 data_ov003_021d8374;
extern Unk021d8374 data_ov003_021d84a4;
extern Unk021d8374 data_ov003_021d85d4;
extern Unk021d8374 data_ov003_021d8644;

s32 func_ov003_021b929c(Unk021b94c4 *a);
