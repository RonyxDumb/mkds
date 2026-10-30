#pragma once

#include "types.h"

#include "00/code_0218f960.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e68c.h"

// Declared here until the code that defines them is decompiled.
s32 func_ov000_02194590(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
s32 func_ov000_021943f0(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
s32 func_ov000_021941c4(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
void func_ov000_0218fbe0(Unk0218f960 *param_1, u32 param_2, s32 param_3, u32 param_4);

// Entry of the list behind Unk02193f2cNode.mUnk_38.
typedef struct Unk0219405c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0219405c;

s32 func_ov000_02193f50(Unk0218f960 *param_1);
void func_ov000_02193ff4(s32 param_1);
void func_ov000_0219405c(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
void func_ov000_02194120(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
s32 func_ov000_02194160(Unk0218f960 *param_1, Unk02193f2cNode *param_2);
