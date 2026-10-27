#pragma once

#include "types.h"

#include "Main/Unknown/unk_0217b000.h"

// Objects returned by func_020b47d8, func_020b4934, func_020b49bc and func_020b4a44.
typedef struct Unk020b4934 {
    /* 0000 */ u8 pad_00[0x10];
    /* 0010 */ u32 mUnk_10;
    /* 0014 */ void *mUnk_14;
} Unk020b4934;

typedef struct Unk020b47d8 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u8 mUnk_0c[1];
} Unk020b47d8;

typedef struct Unk020b4a44 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 *mUnk_0c;
} Unk020b4a44;

// Declared here until the code that defines them is decompiled.
void *func_020b4000(int param_1);
void *func_020b400c(int param_1);
void *func_020b4018(int param_1);
void *func_020b4030(int param_1);
void func_020b41e8(int param_1, int param_2, int param_3, int param_4, int param_5);
void func_020b4810(void **param_1, void *param_2);
void func_020b48ec(void **param_1, void *param_2);
void func_020b496c(void **param_1, void *param_2);
void func_020b49f4(void **param_1, void *param_2);
void func_020b4a7c(void **param_1, void *param_2);
s32 func_020b4e70(const Vec3 *param_1);
void *func_020b403c(s32 index);
void func_020b486c(void **out, void *file);
u32 func_020b4024(u32 arg0);
void func_020b46d0(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g, s32 h);
s32 func_020b4acc(void);
s32 func_020b4b54(void);
void func_020b44a4(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 f);
void func_020b47d8(Unk020b47d8 **, void *);
void func_020b48b4(void **, void *);
void func_020b4934(Unk020b4934 **, void *);
void func_020b49bc(Unk020b4934 **, void *);
void func_020b4a44(Unk020b4a44 **, void *);
