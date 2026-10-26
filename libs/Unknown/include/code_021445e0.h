#pragma once

#include "types.h"

// Pointed to by the word func_02142aa8 returns.
typedef struct Unk02142988 {
    /* 000 */ u16 mUnk_000;
    /* 002 */ u8 mUnk_002[0xa];
    /* 00c */ void *mUnk_00c;
    /* 010 */ u8 mUnk_010[0x76];
    /* 086 */ u16 mUnk_086;
    /* 088 */ u8 mUnk_088[0xfc];
    /* 184 */ u16 mUnk_184;
} Unk02142988;

// func_02142c0c stores a word at offset 0x18 + 4 * n; func_0214358c stores a function and its argument at
// mUnk_0c4[n] and mUnk_104[n].
typedef struct Unk02142aa8 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ Unk02142988 *mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ u16 *mUnk_00c;
    /* 010 */ u8 mUnk_010[0xb4];
    /* 0c4 */ UnkFunc *mUnk_0c4[16];
    /* 104 */ void *mUnk_104[16];
} Unk02142aa8;

// Pair of masks followed by the data that func_0214461c returns the address of.
typedef struct Unk0214461c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x1fc];
} Unk0214461c;

// 0x820 bytes set up by func_021450ec: four 0x200-byte blocks, then the words at mUnk_800.
typedef struct Unk021450ec {
    /* 000 */ Unk0214461c mUnk_000[4];
    /* 800 */ u16 mUnk_800[4];
    /* 808 */ u16 mUnk_808;
    /* 80a */ u16 mUnk_80a;
    /* 80c */ u16 mUnk_80c;
    /* 80e */ u16 mUnk_80e;
    /* 810 */ u16 mUnk_810;
    /* 812 */ u16 mUnk_812;
    /* 814 */ u16 mUnk_814;
    /* 816 */ u16 mUnk_816;
    /* 818 */ u16 mUnk_818;
    /* 81a */ u16 mUnk_81a;
    /* 81c */ u16 mUnk_81c;
    /* 81e */ u16 mUnk_81e;
} Unk021450ec;

// Argument of the functions that func_0214358c is given and that func_021450ec stores; func_02144048 passes it back.
typedef struct Unk02144920 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ Unk021450ec *mUnk_1c;
    /* 20 */ Unk021450ec *mUnk_20;
} Unk02144920;

u8 *func_021445e0(Unk021450ec *p, u32 mask, u8 *base, u32 bit);
u8 *func_0214461c(Unk021450ec *p, Unk0214461c *q, u32 bit);
void func_02144688(Unk021450ec *p, u32 f);
void func_02144814(Unk021450ec *p, u32 bit, const void *src);
void func_02144920(Unk02144920 *a);
void func_02144a50(Unk02144920 *a);
void func_02144b64(Unk02144920 *a);
int func_02144c6c(Unk021450ec *p, void *a, void *b);
int func_02145030(Unk021450ec *p);
int func_021450ec(Unk021450ec *p, u32 n, u32 mask, u32 k, u32 flag);
int func_021453b4(Unk021450ec *p);
int func_021453c0(Unk021450ec *p, u32 n);
