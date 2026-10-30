#pragma once

#include "types.h"
#include "00/code_02196960.h"
#include "00/code_0218d000.h"
#include "00/code_021970fc.h"
#include "code_0213a460.h"
#include "00/code_02196960.h"

extern const u8 data_ov000_021b3dc4[];

// Entry of the list at data_ov000_021b4e5c; only the words read here.
typedef struct Unk02196d84 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02196d84;

// Declared here until the code that defines them is decompiled.

extern const u8 data_ov000_021b3df0[];
extern const u8 data_ov000_021b3df8[];

void func_ov000_02196d0c(u8 *param_1, s32 param_2);
s32 func_ov000_02196d84(s32 a, s32 b, s32 c);
const s8 *func_ov000_02196df0(const s8 *a, s32 b);
