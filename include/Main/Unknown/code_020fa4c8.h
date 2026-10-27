#pragma once

#include "types.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"

extern Unk020ea670 *data_0217bd38;

// Object func_020e6b38 returns: a vector at 0x18.
typedef struct Unk020e6b38 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Vec3 mUnk_18;
} Unk020e6b38;

// Stack object of func_020fb038: the two vectors func_02039860 and func_020d7b88 write.
typedef struct Unk020fb038 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[8];
} Unk020fb038;

s32 func_020fa4c8(Unk0206bcb0 *param_1);
void func_020fa78c(s32 param_1, s32 param_2, s32 param_3);
void func_020fa8ac(void);
void func_020fa920(void);
void func_020fa9e4(void);
s32 func_020faa78(s32 param_1);
s32 func_020fab34(s32 *param_1);
s32 func_020faca4(s32 param_1);
void func_020fad00(void);
Vec3 *func_020fad9c(Unk020f41c4_A *param_1, s32 *param_2, s32 *param_3);
s32 func_020fadcc(Unk020f41c4_A *param_1);
s32 func_020fade4(Unk020f41c4_A *param_1);
void func_020fae74(Unk020f41c4_A *param_1, s32 param_2, s32 param_3);
void func_020faed0(Unk020f41c4_A *param_1, s32 param_2, s32 param_3);
void func_020fb038(Unk020f41c4_A *param_1);
void *func_020fb208(void *param_1, Unk020f41c4_A *param_2, void *param_3);
void func_020fb2b4(Unk020f41c4_A *param_1);
void func_020fb35c(Unk020f41c4_A *param_1);
void func_020fb46c(Unk020f41c4_A *param_1);
void func_020fb5dc(Unk020f41c4_A *param_1);
void func_020fb61c(Unk020f41c4_A *param_1);
void func_020fb770(Unk020f41c4_A *param_1);
void func_020fb7f8(Unk020f41c4_A *param_1);
void func_020fba6c(Unk020f41c4_A *param_1);
void func_020fbae0(Unk020f41c4_A *param_1);
void func_020fbc18(Unk020f41c4_A *param_1);
void func_020fbd4c(Unk020f41c4_A *param_1);
void func_020fbd98(Unk020f41c4_A *param_1);
void func_020fc268(Unk020f41c4_A *param_1);
