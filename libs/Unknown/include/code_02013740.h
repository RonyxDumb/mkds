#pragma once

#include "types.h"

// Argument of func_02013754 and func_020138b4: a byte count at 0x01, at 0x06 the offset of a block holding the
// stride of a table of 16-byte entries, and from 0x08 a table of 4-byte nodes (used when the count is 0x10 or more).
typedef struct Unk02013754 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[4];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[1];
} Unk02013754;

void *func_02013740(void *a, u32 b);
int func_02013754(const void *a, const u32 *key);
void *func_020138b4(const void *a, const u32 *key);
void *func_02013a30(void *a);
void *func_02013a4c(void *a, u32 b);
void *func_02013a6c(void *a);
void *func_02013a88(void *a, u32 b);
void *func_02013aa8(void *a);
void *func_02013ac4(void *a, u32 b);
void *func_02013ae4(void *a);
void *func_02013b00(void *a, u32 b);
