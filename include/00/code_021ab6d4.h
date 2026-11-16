#pragma once

#include "types.h"

typedef struct Unk021ab728 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u8 field18[0x40];
} Unk021ab728;

typedef struct Unk021ab728 Unk021ab728;

void func_ov000_021ab6d4(Unk021ab728 *a, u8 *b);
void func_ov000_021ab728(void *f, const u8 *b, u32 c);
void func_ov000_021ab7b4(Unk021ab728 *a);
void func_ov000_021ab7e8(Unk021ab728 *a, const u8 *b);
