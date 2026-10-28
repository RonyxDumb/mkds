#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020ee684.h"

// Element of data_027e00cc[3]: 0x138 bytes (the size in data_0217bc34[3]), handled by func_020f4dfc to
// func_020f5040: the Unk020f2df0 part and words at 0x130 and 0x134.
typedef struct Unk020f5008 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
} Unk020f5008;

void func_020f49bc(Unk020f40dc *a);
void func_020f4b20(Unk020f40dc *a, Unk020ee684 *b);
void func_020f4b8c(void);
void func_020f4dfc(void **a, Vec3 *b, s32 c);
void func_020f4e78(Unk020f5008 *a, Vec3 *b, Vec3 *c);
Unk020f5008 *func_020f4ee8(void);
void func_020f4f44(Unk020f5008 *a);
void func_020f4fd0(Unk020f5008 *a);
void func_020f5008(Unk020f5008 *a, void *b, void *c);
