#pragma once

#include "types.h"
#include "Main/Unknown/code_021001ac.h"

// First argument of func_02101d18: objects at 0x0c and 0x10.
typedef struct Unk02101d18 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ Unk0206bcb0 *mUnk_10;
} Unk02101d18;

s32 func_02101014(Unk020f41c4_A *p);
void func_02101178(Unk020f41c4_A *p);
s32 func_021014a0(Unk020f41c4_A *p, s32 param_2, s32 param_3);
s32 func_02101618(Unk020f41c4_A *p, s32 param_2, s32 param_3);
void func_0210174c(Unk020f41c4_A *p);
void func_021018a0(Unk020f41c4_A *p);
void func_02101964(Unk020f41c4_A *p, s32 param_2);
void func_0210140c(Unk020f41c4_A *p);
void func_021013bc(Unk020f41c4_A *p);
void func_0210136c(Unk020f41c4_A *p);
void func_02101d90(Unk020f41c4_A *p, s32 param_2);
void func_02101f7c(Unk020f41c4_A *p, s32 param_2);
void func_02100de4(Unk020f41c4_A *p);
void func_02101c84(Unk020f41c4_A *p);
void func_02101d18(Unk02101d18 *x, Unk020f41c4_A *p);
