#pragma once

#include "types.h"
#include "code_0212f788.h" // Unk0212f7c8

// 0x44 bytes; sixteen of them in data_0217d45c. Most functions take a pointer to a pointer to one.
typedef struct Unk0212c400 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x18];
    /* 1c */ Unk0212f7c8 mUnk_1c;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u8 mUnk_2e[6];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d[3];
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ u8 mUnk_42[2];
} Unk0212c400;

void func_0212c478(Unk0212c400 **a, u32 b);
void func_0212c494(Unk0212c400 **a, u32 b);
void func_0212c4c4(Unk0212c400 **a, u32 b, u32 c);
void func_0212c4f4(Unk0212c400 **a, u32 b, u32 c);
void func_0212c524(Unk0212c400 **a, u32 b, u32 c);
void func_0212c554(Unk0212c400 **a, u32 b, u32 c);
void func_0212c594(Unk0212c400 **a, u32 b, u32 c);
void func_0212c5c4(Unk0212c400 **a, u32 b);
void func_0212c5f4(Unk0212c400 **a, u8 b);
void func_0212c620(Unk0212c400 **a, s32 b, s32 c);
