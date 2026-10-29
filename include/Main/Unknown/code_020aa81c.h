#pragma once

#include "types.h"
#include "code_02022aa8.h"
#include "code_0214e6e4.h"
#include "Main/Unknown/unk_0217b000.h"

// 0x20-byte object on the stack of func_020aad9c, set up by func_02023408; the function at 0x14 draws into it.
struct Unk020aad9c;

// Two pointers, passed by address to the function at 0x14 of Unk020aad9c.
typedef struct Unk020aad9c_24 {
    /* 00 */ Unk02022c80 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
} Unk020aad9c_24;

typedef struct Unk020aad9c {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ void (*mUnk_14)(struct Unk020aad9c *, Unk02022aa8 *, s32, s32, s32, Unk020aad9c_24 *);
    /* 18 */ u8 mUnk_18[8];
} Unk020aad9c;

void func_020aa81c(void);
void func_020aa89c(u16 a, Unk0214e334_b b);
u32 func_020aab40(Unk0217b278 *a);
void func_020aab70(Unk0217b278 *a);
void func_020aad9c(Unk0217b278 *a);
Unk0217b278_10 *func_020aaea0(Unk0217b278 *a, s32 b, s32 c);
u16 func_020aaf70(Unk0217b278_1c *a);
void func_020aafa8(Unk0217b278 *a);
void func_020ab028(s32 a);
