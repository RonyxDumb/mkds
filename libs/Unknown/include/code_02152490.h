#pragma once

#include "types.h"

// 12 bytes: a word whose bits 0-10 are the top of a 64-bit value and whose bits 11-31 are another field (its low two
// bits are a tag, bit 2 is a flag), then two more words.
typedef struct Unk02152490 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk02152490;

// 0x40 bytes: a size word, two of the 12-byte objects, a count, flags, a seed, and a checksum of the first 0x3c bytes.
typedef struct Unk02152500 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02152490 mUnk_04;
    /* 10 */ Unk02152490 mUnk_10;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x14];
    /* 3c */ u32 mUnk_3c;
} Unk02152500;

void func_02152490(void *a, void *b);
