#pragma once

#include "types.h"
#include "Main/Unknown/code_0200ad4c.h"

// Object behind data_0216fdac. The members from 0x1788 on are reached from a pointer advanced in steps of 0x5d4
// bytes, so their offsets here include the 0x1788.
typedef struct Unk0216fdac {
    /* 0000 */ u8 mUnk_0000[0x14e8];
    /* 14e8 */ u32 mUnk_14e8[15];
    /* 1524 */ u8 mUnk_1524;
    /* 1525 */ u8 mUnk_1525;
    /* 1526 */ s8 mUnk_1526[16];
    /* 1536 */ u8 mUnk_1536[0x252];
    /* 1788 */ u8 mUnk_1788[0x5a4];
    /* 1d2c */ u8 mUnk_1d2c[0x1c];
    /* 1d48 */ u16 mUnk_1d48;
    /* 1d4a */ u16 mUnk_1d4a;
    /* 1d4c */ u16 mUnk_1d4c;
    /* 1d4e */ u8 mUnk_1d4e[4];
    /* 1d52 */ u8 mUnk_1d52;
    /* 1d53 */ u8 mUnk_1d53;
    /* 1d54 */ Unk0200adfc *mUnk_1d54;
    /* 1d58 */ u32 *mUnk_1d58;
    /* 1d5c */ u8 mUnk_1d5c[0x7ce0 - 0x1d5c];
    /* 7ce0 */ u8 mUnk_7ce0[0x18];
} Unk0216fdac;

u32 func_02007148(u32 a, u32 b);
void func_02007154(u32 a);
