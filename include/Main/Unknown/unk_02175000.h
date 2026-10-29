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

// Part of Unk021755a0 at 0x28, 0x38, 0x70 and 0x80: seven halfwords.
typedef struct Unk021755a0_28 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[0x2];
} Unk021755a0_28;

// Object behind member 0x6c of Unk021755a0.
typedef struct Unk021755a0_6c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk021755a0_6c;

// Object behind data_021755a0.
typedef struct Unk021755a0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ Unk021755a0_28 mUnk_28;
    /* 38 */ Unk021755a0_28 mUnk_38;
    /* 48 */ u8 mUnk_48[0x10];
    /* 58 */ u8 mUnk_58[0x10];
    /* 68 */ u16 mUnk_68;
    /* 6a */ u16 mUnk_6a;
    /* 6c */ Unk021755a0_6c *mUnk_6c;
    /* 70 */ Unk021755a0_28 mUnk_70;
    /* 80 */ Unk021755a0_28 mUnk_80;
    /* 90 */ u8 mUnk_90[0x10];
    /* a0 */ u8 mUnk_a0[0x10];
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u16 mUnk_b2;
    /* b4 */ u8 mUnk_b4[0x4];
    /* b8 */ void (*mUnk_b8)(void);
} Unk021755a0;

// Objects whose layout isn't known yet.
extern Unk021755a0 *data_021755a0;
extern u8 data_021755a8[];
extern u8 data_021755b4[];
extern u16 data_021755dc;
extern u8 data_02175624[];
// 0x5c-byte entries; func_020708a4 writes the halfword at 0x00 of entry Unk0206bcb0::mUnk_78.
typedef struct Unk0217566a {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x5a];
} Unk0217566a;

extern Unk0217566a data_0217566a[];
extern u8 data_021759c8[];
extern Unk021759cc *data_021759cc;
extern Unk021759d0 *data_021759d0;
extern vu16 data_021758e8[];
extern vu16 data_02175928[];
extern u8 data_02175dd8[];
// Object at data_02175614: a word and a function pointer.
typedef struct Unk02175614 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 (*mUnk_04)();
} Unk02175614;

extern Unk02175614 data_02175614;

// Read as words by func_0204a650 (word 2 compared with 3).
extern s32 data_02175650[];

// Entry of the table at 0x440 of data_02175ec0: a four-bit part in the low bits of the first word, then two words.
typedef struct Unk02175ec0_440 {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 28;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02175ec0_440;

// Nine bytes that func_0204d28c builds on the stack and passes to func_02006d3c: two four-bit parts, a 24-bit part,
// a word and a byte.
typedef struct Unk02175ec0_msg {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 4;
    /* 00 */ u32 mUnk_00_8 : 24;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08;
} Unk02175ec0_msg;

// Part of data_02175ec0 from 0x440: the table, then nine words at 0x46cc.
typedef struct Unk02175ec0_440s {
    /* 0000 */ Unk02175ec0_440 mUnk_0000[32];
    /* 0180 */ u8 mUnk_0180[0x454c];
    /* 46cc */ s32 mUnk_46cc;
    /* 46d0 */ s32 mUnk_46d0;
    /* 46d4 */ s32 mUnk_46d4;
    /* 46d8 */ s32 mUnk_46d8;
    /* 46dc */ s32 mUnk_46dc;
    /* 46e0 */ s32 mUnk_46e0;
    /* 46e4 */ s32 mUnk_46e4;
    /* 46e8 */ s32 mUnk_46e8;
    /* 46ec */ s32 mUnk_46ec;
} Unk02175ec0_440s;

// Object at data_02175ec0.
typedef struct Unk02175ec0 {
    /* 0000 */ u32 mUnk_0000;
    /* 0004 */ u8 mUnk_0004[8];
    /* 000c */ s32 mUnk_000c;
    /* 0010 */ u8 mUnk_0010[4];
    /* 0014 */ void *(*mUnk_0014)(s32 a, u32 b, u32 c);
    /* 0018 */ s32 mUnk_0018;
    /* 001c */ u8 mUnk_001c[4];
    /* 0020 */ void *mUnk_0020;
    /* 0024 */ u32 mUnk_0024;
    /* 0028 */ s32 mUnk_0028;
    /* 002c */ s32 mUnk_002c;
    /* 0030 */ u8 mUnk_0030[0x410];
    /* 0440 */ Unk02175ec0_440s mUnk_0440;
} Unk02175ec0;

extern Unk02175ec0 data_02175ec0;
extern void (*data_usa_02175584)(s32);
