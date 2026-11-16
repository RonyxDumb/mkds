#pragma once

#include "types.h"

typedef struct Hash20Context {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u8 field1C[0x40];
} Hash20Context;

void func_ov000_021abca0(void *f, const u8 *b, u32 c);
