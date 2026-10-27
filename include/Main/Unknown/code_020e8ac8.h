#pragma once

#include "types.h"

// Object at 0x00 of a data_0217bae8 row, as func_020e9810 reads it: the word at 0x04.
typedef struct Unk020e9810 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ void *mUnk_04;
} Unk020e9810;

void func_020e8ac8(void);
void func_020e9658(void);
void func_020e9810(void);
void func_020e9d10(void);
void func_020ea1d4(Vec3 *param_1, const Vec3 *param_2, const Vec3 *param_3);
void func_020ea37c(void);
void func_020ea4bc(u32 param_1, void *param_2, void **param_3, void *param_4, void *param_5);
