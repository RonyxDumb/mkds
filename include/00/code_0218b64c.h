#pragma once

#include "types.h"
#include "00/code_0218a000.h"
#include "00/code_0218acb0.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"

// Object of 0x638 bytes func_ov000_0218b668 allocates. func_ov000_0218acb0 passes 0x20 to func_ov000_0218e53c and
// the addresses of 0x14 and 0x08 to func_ov000_0218ae5c.
typedef struct Unk0218b668 {
    /* 000 */ u8 mUnk_000[0x8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u8 mUnk_00c[0x8];
    /* 014 */ u32 mUnk_014;
    /* 018 */ u8 mUnk_018[0x8];
    /* 020 */ u32 mUnk_020;
    /* 024 */ u8 mUnk_024[0x28];
    /* 04c */ u8 mUnk_04c[0x5d8];
    /* 624 */ u32 mUnk_624;
    /* 628 */ u8 mUnk_628[8];
    /* 630 */ UnkFunc *mUnk_630;
    /* 634 */ u32 mUnk_634;
} Unk0218b668;

void func_ov000_0218b64c(Unk0218b668 *p);

Unk0218b668 *func_ov000_0218b668(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                                 s32 param_7, UnkFunc *param_8, u32 param_9);
