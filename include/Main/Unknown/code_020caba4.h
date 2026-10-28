#pragma once

#include "types.h"

// Four halfwords passed by value to func_020ae244.
typedef struct Unk020ae244 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk020ae244;

s32 func_020cadac(s32 a);
s32 func_020cacc0(void);
void func_020cac9c(void);
void func_020cac68(u16 *a, s32 b, s32 c);
void func_020cac18(void);
void func_020caba4(s32 a);
