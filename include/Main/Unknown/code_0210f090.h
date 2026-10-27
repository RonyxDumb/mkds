#pragma once

#include "types.h"

// Object at 0x400 of Unk0210f090: func_0210f130 writes its seven words and passes its address to func_02020430.
typedef struct Unk0210f130 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk0210f130;

// Object func_0210f090 and func_0210f130 take, 0x420 bytes: func_0210f130 zeroes 0x400 bytes and sets up the words
// at 0x400..0x418; func_0210f090 steps a signed number at 0x41c to 0x1e and then resets it.
typedef struct Unk0210f090 {
    /* 000 */ u8 mUnk_000[0x400];
    /* 400 */ Unk0210f130 mUnk_400;
    /* 41c */ s32 mUnk_41c;
} Unk0210f090;

u32 func_0210f090(Unk0210f090 *p);
