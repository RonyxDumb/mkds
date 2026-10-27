#pragma once

#include "types.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020f36d8.h"

// Object behind data_0217b4f0, allocated 0x2bc bytes long: the Unk020e71a0 objects at 0x000 (count at 0x004),
// Unk020e6fd4 pointer arrays at 0x008, 0x068, 0x0c8 and 0x134 and a Unk020f41c4_A at 0x18c.
typedef struct Unk0217b4f0 {
    /* 000 */ Unk020e71a0 **mUnk_000;
    /* 004 */ vu16 mUnk_004;
    /* 006 */ u8 mUnk_006[2];
    /* 008 */ Unk020e6fd4 *mUnk_008[24];
    /* 068 */ Unk020e6fd4 *mUnk_068[24];
    /* 0c8 */ Unk020e6fd4 *mUnk_0c8[24];
    /* 128 */ u16 mUnk_128;
    /* 12a */ u16 mUnk_12a;
    /* 12c */ u16 mUnk_12c;
    /* 12e */ u8 mUnk_12e[2];
    /* 130 */ s32 mUnk_130;
    /* 134 */ Unk020e6fd4 *mUnk_134[16];
    /* 174 */ u16 mUnk_174;
    /* 176 */ u8 mUnk_176[2];
    /* 178 */ s32 mUnk_178;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mUnk_180;
    /* 184 */ s32 mUnk_184;
    /* 188 */ s32 mUnk_188;
    /* 18c */ Unk020f41c4_A mUnk_18c;
    /* 2b8 */ s32 mUnk_2b8;
} Unk0217b4f0;

// Declared here until the code that defines them is decompiled.
u32 func_020d2178(u32 param_1);
void *func_020d21ec(const char *param_1);
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d26e0.h"
unsigned int func_020d2398(void *param_1);
u32 func_020d26f8(void *param_1, void *param_2);
unsigned int func_020d28e0(unsigned int);
int func_020d2c2c(u32 *param_1, u32 *param_2, u32 param_3, u32 param_4, u32 param_5, int *param_6);
void func_020d2950(void *param_1, s32 param_2);
void func_020d2584(void *param_1, s32 param_2);
void func_020d2600(s32 param_1, Vec3 *param_2, s32 param_3);
void func_020d278c(void *p0);
u32 func_020d286c(void *param_1);
void func_020d27fc(void *a);
s32 func_020d2234(void *a, struct Unk020f41c4_A *b);
void *func_020d2210(const char *param_1);
void func_020d29cc(void *param_1, void *param_2);
void func_020d233c(Unk021052fc *p);
