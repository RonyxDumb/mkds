#pragma once

#include "types.h"

struct Unk02003a6c;
struct Unk02003670;

// Two words moved as a whole (func_02003234 reads one into mUnk_30 of Unk02003024, func_02003670 stores one).
typedef struct Unk02003234 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02003234;

// 12 bytes at 0x20 and at 0x30 of Unk02003024 (assigned as a whole by func_0200399c). Different functions write the
// region with different types: an Unk02003a6c pointer (func_02003aa4, func_0200388c), an Unk02003670 pointer
// (func_02003670, func_020032b0), two words (func_02003234) and a u8 pointer with two lengths (func_020032b0).
typedef union Unk02003024U {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } w;
    struct {
        /* 00 */ Unk02003234 mUnk_00;
        /* 08 */ u32 mUnk_08;
    } d;
    struct {
        /* 00 */ struct Unk02003a6c *mUnk_00;
        /* 04 */ u16 mUnk_04;
        /* 06 */ u16 mUnk_06;
        /* 08 */ u32 mUnk_08;
    } h;
    struct {
        /* 00 */ struct Unk02003670 *mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } e;
    struct {
        /* 00 */ u8 *mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u16 mUnk_08;
        /* 0a */ u16 mUnk_0a;
    } b;
} Unk02003024U;

// Object passed to func_02003024; mUnk_08 is the Unk02003a6c it works through.
typedef struct Unk02003024 {
    // func_020031a0 links mUnk_00 and mUnk_04 to each other, then clears both.
    /* 00 */ struct Unk02003024 *mUnk_00;
    /* 04 */ struct Unk02003024 *mUnk_04;
    /* 08 */ struct Unk02003a6c *mUnk_08;
    /* 0c */ u32 mUnk_0c; // bit 2 selects the path in func_02003024; func_020031a0 clears 0x4f
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14; // set from a return value in func_02003024 and func_020031a0
    /* 18 */ u8 mUnk_18[0x8];
    /* 20 */ Unk02003024U mUnk_20;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ Unk02003024U mUnk_30;
    /* 3c */ const u8 *mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ Unk02003024U *mUnk_44;
    /* 48 */ u32 mUnk_48;
} Unk02003024;

// Object at mUnk_08 of Unk02003024. mUnk_1c holds bits 0x100 and 0x200 that func_02003024 and func_02003ad8 set and
// clear; the address of mUnk_0c goes to func_0200e01c; mUnk_48 to mUnk_54 are called from func_02003024,
// func_02003a34, func_02003a6c and func_02003ad8.
typedef struct Unk02003a6c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x08];
    /* 0c */ u8 mUnk_0c[0x10];
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x0c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u8 mUnk_38[0x10];
    /* 48 */ s32 (*mUnk_48)(struct Unk02003a6c *a, u32 b);
    /* 4c */ s32 (*mUnk_4c)(struct Unk02003a6c *a, u32 b);
    /* 50 */ s32 (*mUnk_50)(struct Unk02003a6c *a, void *b, u32 c, u32 d);
    /* 54 */ s32 (*mUnk_54)(Unk02003024 *a, u32 b);
    /* 58 */ u32 mUnk_58;
} Unk02003a6c;

// Called by func_02003024 with its second argument as the index.
extern s32 (*data_02152b5c[])(Unk02003024 *a);

s32 func_02003024(Unk02003024 *a, u32 b);
void func_020031a0(Unk02003024 *a, s32 b);
s32 func_02003204(Unk02003024 *a);
