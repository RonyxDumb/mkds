#pragma once

#include "types.h"

// Object func_ov000_021a8f84 returns; mUnk_0c points at a table of pointers to a word.
typedef struct Unk021a8f84 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ u32 **mUnk_0c;
} Unk021a8f84;

extern Unk021a8f84 data_ov000_021b4e0c;
extern u8 data_ov000_021b4e04[];
extern u32 *data_ov000_021b4e30[2];
extern u32 data_ov000_021b4e1c;

s32 func_ov000_0218e57c(u32 *param_1);
Unk021a8f84 *func_ov000_0218e5e4(void);
