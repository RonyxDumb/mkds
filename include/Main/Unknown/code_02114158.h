#pragma once

#include "types.h"

// Object with 0x200 bytes followed by a byte.
typedef struct Unk021141c8 {
    /* 000 */ u8 mUnk_000[0x200];
    /* 200 */ u8 mUnk_200;
} Unk021141c8;

void func_021143f4(void);
u16 func_021143b4(void);
s32 func_02114398(u16 a);
s32 func_0211437c(u16 a);
s32 func_02114360(u16 a);
s32 func_02114344(u16 a);
s32 func_02114328(u16 a);
s32 func_0211430c(u16 a);
s32 func_021142f0(u16 a);
s32 func_021142d4(u16 a, void *b);
void func_02114298(u16 a, void *b, u32 c);
s32 func_0211427c(u16 a);
s32 func_02114260(u16 a);
void func_021141c8(u16 a, Unk021141c8 *b, void *c);
void func_02114174(u16 a);
s32 func_02114158(u16 a, void *b);
