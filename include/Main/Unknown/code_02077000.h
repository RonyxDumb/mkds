#pragma once

#include "types.h"
#include "Main/Unknown/code_02076cd0.h"

// Declared here until the code that defines them is decompiled.
void func_02077c1c(void);
void func_02077f5c(void);

// 0x20-byte entry: a halfword at 0x04.
typedef struct Unk02077f7c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x1a];
} Unk02077f7c;

Unk02077f7c *func_02077f7c(s32 a);
