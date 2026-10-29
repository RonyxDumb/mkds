#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"

// Three values that func_020565e4 and func_0205660c fill: a halfword and two bytes.
typedef struct Unk020565e4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020565e4;

void func_02056464(Unk0217aa00_45c *a);
s32 func_02056574(s32 a, Unk020565e4 *b);
s32 func_020565ac(s32 a, s32 b, Unk020565e4 *c);
s32 func_020565e4(Unk0217aa08_14 *a, Unk020565e4 *b);
s32 func_0205660c(Unk0217aa08_14 *a, s32 b, Unk020565e4 *c);
void func_02056670(u32 a);
