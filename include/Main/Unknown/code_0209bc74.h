#pragma once

#include "types.h"

// Object the functions below receive: a value at 0x18.
typedef struct Unk0209bc74_a {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ s32 mUnk_18;
} Unk0209bc74_a;

// Three words written to the start of the objects of func_0209bc74, func_0209bd08, func_0209bd90 and func_0209be84.
typedef struct Unk0209bc74_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0209bc74_00;

// 0x2c-byte object of func_0209bc74 and func_0209bd08: the word at 0x10 and the word at 0x14 have their low bits changed.
typedef struct Unk0209bc74_0c {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0209bc74_0c;

// Object at 0x20 and 0x28 of Unk0209bc74: a word at 0x0c, a halfword at 0x1a and a table of word pointers at 0x1c.
typedef struct Unk0209bc74_20 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0209bc74_20;

// Object returned by func_0209bc74, func_0209bd08, func_0209bd90 and func_0209be84.
typedef struct Unk0209bc74 {
    /* 00 */ Unk0209bc74_00 mUnk_00;
    /* 0c */ Unk0209bc74_0c *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk0209bc74_20 *mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Unk0209bc74_20 *mUnk_28;
} Unk0209bc74;

extern Unk0209bc74_00 data_021565a0;
extern Unk0209bc74_00 data_021565ac;
extern Unk0209bc74_00 data_021565b8;
extern Unk0209bc74_00 data_021565c4;
