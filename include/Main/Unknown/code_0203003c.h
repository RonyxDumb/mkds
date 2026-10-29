#pragma once

#include "types.h"

// Object behind data_02174e54; the word at 0x38 is read by func_020302a0.
typedef struct Unk02174e54 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
} Unk02174e54;

void func_0203003c(s32 a);
void func_02030200(void);
s32 func_0203023c(void);
s32 func_02030274(s32 a, s32 b);
void func_020302a0(void);
void func_020302f0(u32 a, u32 b, u32 c, u32 d);
