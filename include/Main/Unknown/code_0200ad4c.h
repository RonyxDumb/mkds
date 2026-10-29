#pragma once

#include "types.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"
#include "code_02142eac.h"

// Object behind data_0216fda8: the halfwords at 0x526, 0x528 and 0x52a and the byte at 0x50c.
typedef struct Unk0216fda8 {
    /* 000 */ u8 mUnk_000[0x50c];
    /* 50c */ u8 mUnk_50c;
    /* 50d */ u8 mUnk_50d[0x19];
    /* 526 */ u16 mUnk_526;
    /* 528 */ u16 mUnk_528;
    /* 52a */ u16 mUnk_52a;
} Unk0216fda8;

// The halfword at 4.
typedef struct Unk0200ada4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0200ada4;

// 0x10-byte entries from 0x30 of Unk0200adfc.
typedef struct Unk0200adfc_30 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0200adfc_30;

typedef struct Unk0200adfc {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ Unk0200adfc_30 mUnk_30[4];
} Unk0200adfc;

u32 func_0200ad4c(void);
u32 func_0200ada4(Unk0200ada4 *a);
u32 func_0200adfc(Unk0200adfc *a, u32 b, void *c, u32 d);
void func_0200ae60(Unk0200adfc *a, u32 b, u32 c, u32 d, u32 e);
