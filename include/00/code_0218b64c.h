#pragma once

#include "types.h"
#include "00/code_0218a000.h"
#include "00/code_0218acb0.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"

void func_ov000_0218b64c(int param_1);
// Object of 0x638 bytes func_ov000_0218b668 allocates.
typedef struct Unk0218b668 {
    /* 000 */ u8 mUnk_000[0x4c];
    /* 04c */ u8 mUnk_04c[0x5d8];
    /* 624 */ u32 mUnk_624;
    /* 628 */ u8 mUnk_628[8];
    /* 630 */ u32 mUnk_630;
    /* 634 */ u32 mUnk_634;
} Unk0218b668;

Unk0218b668 *func_ov000_0218b668(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                                 s32 param_7, u32 param_8, u32 param_9);
