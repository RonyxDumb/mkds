#pragma once

#include "types.h"

// Entries reached through Unk02080b1c: a table of pointers to further entries at 0x00 (the count is the halfword at
// 0x24), a vector pointer at 0x18 and a word at 0x1c.
typedef struct Unk02080b1c_00 {
    /* 00 */ struct Unk02080b1c_00 *mUnk_00[6];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20[4];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[2];
} Unk02080b1c_00;

// Current entry at 0x00, previous entry at 0x04, a vector at 0x08 and the halfword at 0x1c given to func_0207a974.
typedef struct Unk02080b1c {
    /* 00 */ Unk02080b1c_00 *mUnk_00;
    /* 04 */ Unk02080b1c_00 *mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ u8 mUnk_14[8];
    /* 1c */ u16 mUnk_1c;
} Unk02080b1c;

// Object of 0x2a bytes: an Unk02080b1c at 0x00, a word at 0x20, the halfword at 0x24 given to func_0207a974 and
// halfwords at 0x26 and 0x28.
typedef struct Unk020905a8 {
    /* 00 */ Unk02080b1c mUnk_00;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
} Unk020905a8;

void func_02080b1c(Unk02080b1c *p);
s32 func_02080bf4(Unk02080b1c *p, Vec3 *a);
s32 func_02080c64(Unk02080b1c *p, Vec3 *a);
