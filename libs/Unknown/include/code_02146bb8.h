#pragma once

#include "types.h"

// Words and halfwords that func_02146c24 reads from, and func_02146bb8 writes to, 0x04000280-0x040002bf.
typedef struct Unk02146bb8 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} Unk02146bb8;

void func_02146bb8(const Unk02146bb8 *a);
void func_02146c24(Unk02146bb8 *a);
