#pragma once

#include "types.h"
#include "00/code_021a377c.h"

// Local of func_ov000_021a3910, filled with zeros and then with two function addresses and two bytes.
typedef struct Unk021a3910 {
    /* 00 */ void *(*mUnk_00)(u32 a, u32 b);
    /* 04 */ void (*mUnk_04)(u32 a, u32 b, u32 c);
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 pad_0a[2];
} Unk021a3910;

void func_ov000_021a3910(void);
void func_ov000_021a397c(s32 a);
