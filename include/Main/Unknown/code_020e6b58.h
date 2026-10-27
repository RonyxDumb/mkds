#pragma once

#include "types.h"

// Object holding four vectors, 0x30 bytes.
typedef struct Unk020e6b58 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
} Unk020e6b58;

Unk020e6b58 *func_020e6b58(Vec3 *param_1);
Unk020e6b58 *func_020e6b94(Vec3 *param_1);
Unk020e6b58 *func_020e6bd0(Vec3 *param_1);
void func_020e6c0c(void);
Unk020e6b58 *func_020e6c3c(Vec3 *v, s32 a1, s32 a2);
Unk020e6b58 *func_020e6cbc(Vec3 *param_1);
Unk020e6b58 *func_020e6cf8(Vec3 *param_1);
s32 func_020e6d34(Vec3 *v, Unk020e6b58 *h);
s32 func_020e6d88(Vec3 *v);
void func_020e6df0(Unk020e6b58 *p);
