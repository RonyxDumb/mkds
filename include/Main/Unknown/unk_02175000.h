#pragma once

#include "types.h"

// Object behind data_021759d0 (0x7c bytes); the 0x14 bytes at 0x2a are the source of a block move into
// data_0217aa08.
typedef struct Unk021759d0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c_0 : 1;
    /* 1c */ s32 mUnk_1c_1 : 1;
    /* 20 */ s32 mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ u16 mUnk_28;
    /* 2a */ u8 mUnk_2a[0x14];
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41[0x3];
    /* 44 */ void *mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
} Unk021759d0;

// Four callbacks and two numbers, passed to func_020487fc, which moves it to member 0xec of data_021759cc.
typedef struct Unk021a9034 {
    /* 00 */ void (*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ void (*mUnk_08)();
    /* 0c */ void (*mUnk_0c)();
    /* 10 */ int mUnk_10;
    /* 14 */ int mUnk_14;
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
    /* 1c */ int mUnk_1c;
} Unk021a9034;

// Object behind data_021759cc.
typedef struct Unk021759cc {
    /* 000 */ u8 mUnk_000[0xe4];
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ Unk021a9034 mUnk_0ec;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ u8 mUnk_114[4];
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s8 mUnk_120;
} Unk021759cc;

// Object behind data_021755a0.
typedef struct Unk021755a0 {
    /* 00 */ u8 mUnk_00[0xb8];
    /* b8 */ void (*mUnk_b8)(void);
} Unk021755a0;

// Objects whose layout isn't known yet.
extern Unk021755a0 *data_021755a0;
extern u8 data_021755a8[];
extern u8 data_021755b4[];
extern u16 data_021755dc;
extern u8 data_02175624[];
extern u8 data_021759c8[];
extern Unk021759cc *data_021759cc;
extern Unk021759d0 *data_021759d0;
extern vu16 data_021758e8[];
extern vu16 data_02175928[];
extern u8 data_02175ec0[];
extern u8 data_02175dd8[];
// Object at data_02175614: a word and a function pointer.
typedef struct Unk02175614 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 (*mUnk_04)();
} Unk02175614;

extern Unk02175614 data_02175614;
