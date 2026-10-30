#pragma once

#include "types.h"
#include "00/unk_021b4000.h"

// Object func_ov000_0218ce14 builds.
typedef struct Unk0218ce14 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218ce14;

void func_ov000_0218cdd8(u8 **a, const u8 *b, s32 *c);
s32 func_ov000_0218ce14(Unk021b4d24 *p);
u32 func_ov000_0218cef4(const s8 *a, u32 b);
void func_ov000_0218cf30(Unk021b4d24 *p);
void func_ov000_0218cfb8(Unk021b4d24 *p, const u8 *a, const u8 *b, const u8 *c, u32 d, s32 e, UnkFunc *f, void *g);
