#pragma once

#include "types.h"

#include "Main/Unknown/unk_0217b000.h"
#include "code_02021db0.h" // Unk02021dc8

// Objects stored through the first parameter: Unk020b47d8 by func_020b47d8 and func_020b4810, Unk020b4934 by
// func_020b4934, func_020b496c, func_020b49bc and func_020b49f4, Unk020b4a44 by func_020b4a44 and func_020b4a7c,
// Unk02021dc8 by func_020b486c, func_020b48b4 and func_020b48ec (func_020b486c passes it to func_02021dc8,
// func_020b48ec to func_02021e8c; func_020b48b4 looks up the same block tag as func_020b48ec).
typedef struct Unk020b4934 {
    /* 0000 */ u8 pad_00[0x10];
    /* 0010 */ u32 mUnk_10;
    /* 0014 */ void *mUnk_14;
} Unk020b4934;

typedef struct Unk020b47d8 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 mUnk_0c[1];
} Unk020b47d8;

typedef struct Unk020b4a44 {
    /* 0000 */ u8 pad_00[4];
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 *mUnk_0c;
} Unk020b4a44;

// One stack word whose address the functions above store different pointer types through.
typedef union Unk02111684_v {
    Unk020b4934 *m4934;
    Unk020b47d8 *m47d8;
    Unk020b4a44 *m4a44;
    Unk02021dc8 *m21dc8;
} Unk02111684_v;

// Declared here until the code that defines them is decompiled.
void *func_020b4000(int param_1);
void *func_020b400c(int param_1);
void *func_020b4018(int param_1);
void *func_020b4030(int param_1);
void func_020b41e8(int param_1, int param_2, int param_3, int param_4, int param_5);
void func_020b4810(Unk020b47d8 **param_1, void *param_2);
void func_020b48ec(Unk02021dc8 **param_1, void *param_2);
void func_020b496c(Unk020b4934 **param_1, void *param_2);
void func_020b49f4(Unk020b4934 **param_1, void *param_2);
void func_020b4a7c(Unk020b4a44 **param_1, void *param_2);
s32 func_020b4e70(const Vec3 *param_1);
void *func_020b403c(s32 index);
void func_020b486c(Unk02021dc8 **out, void *file);
u32 func_020b4024(u32 arg0);
void func_020b46d0(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g, s32 h);
s32 func_020b4acc(void);
s32 func_020b4b54(void);
void func_020b44a4(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 f);
void func_020b47d8(Unk020b47d8 **, void *);
void func_020b48b4(Unk02021dc8 **, void *);
void func_020b4934(Unk020b4934 **, void *);
void func_020b49bc(Unk020b4934 **, void *);
void func_020b4a44(Unk020b4a44 **, void *);
void func_020b4cec(void *p, s32 a);
void func_020b478c(void *a, void *b);
void func_020b4bf8(s32 *a, s32 b, s32 c);
void func_020b4cb0(s32 *a, s32 b);
s32 func_020b4b98(s32 a);
s32 func_020b4b10(void);
void func_020b4520(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 *f, s32 g, s32 h);
void func_020b4428(u16 *a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_020b4048(void);
void func_020b409c(void);
