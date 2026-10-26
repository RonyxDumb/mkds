#pragma once

#include "types.h"

// Two words.
typedef struct Unk02021e40 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02021e40;

// 16 bytes: mUnk_00 elements of 8 bytes at mUnk_0c.
typedef struct Unk02021e1c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02021e1c;

// Header: mUnk_04, mUnk_08 and mUnk_0c are offsets from the start that func_02021dc8 turns into addresses.
// mUnk_04 holds mUnk_00 entries (16 bytes, or 8 bytes without bit 0 of mUnk_02, see func_02021f1c).
typedef struct Unk02021dc8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02021e40 *mUnk_0c;
} Unk02021dc8;

void *func_02021db0(void *a, u32 b);
void func_02021dc8(Unk02021dc8 *a);
