#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
void func_02077c1c(void);
u16 func_02077a5c(void);
u16 func_02077a4c(void);
void func_02077a28(void *a);
void func_02077f5c(void);

// 0x20-byte entry: a halfword at 0x04.
typedef struct Unk02077f7c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x1a];
} Unk02077f7c;

Unk02077f7c *func_02077f7c(s32 a);
