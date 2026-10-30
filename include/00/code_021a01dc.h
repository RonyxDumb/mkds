#pragma once

#include "types.h"
#include "00/code_02198000.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/unk_021b5000.h"

// 8-byte local of func_ov000_021a01dc passed to func_ov000_0219db18.
typedef struct Unk021a01dc {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021a01dc;

void func_ov000_0219bbac(s32 a);
void func_ov000_0219f8b0(void);
void func_ov000_0219ff0c(u32 a, u32 *b);
void func_ov000_0219ff54(u32 a, u32 b, u32 c);
s32 func_ov000_021a0064(u32 a, u32 b, s32 c);
s32 func_ov000_021a01dc(s32 a, u32 b, u32 c, u32 d, u32 *e, s32 f);
s32 func_ov000_021a0cac(s32 a, s32 b, u32 c);
void func_ov000_021a1a38(s32 a, s32 b);
u64 func_ov000_021a350c(void);
