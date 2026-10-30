#pragma once

#include "types.h"
#include "00/types_021937c0.h"
#include "00/types_021906e4.h"

// Object behind Unk0218f960.mUnk_00: func_ov000_0218f960 passes the address of 0x1f4 to func_ov000_02190b80 and
// func_ov000_02190b58, reads 0x198 and decrements 0x430.
typedef struct Unk0218f960_00 {
    /* 000 */ u8 mUnk_000[0x100];
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u32 mUnk_108;
    /* 10c */ u8 mUnk_10c[4];
    /* 110 */ u8 mUnk_110[0x1f];
    /* 12f */ s8 mUnk_12f[0x15];
    /* 144 */ u8 mUnk_144[0x33];
    /* 177 */ s8 mUnk_177[0x21];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u32 mUnk_19c;
    /* 1a0 */ u32 mUnk_1a0;
    /* 1a4 */ Unk02190ed4Cb mUnk_1a4;
    /* 1ac */ u8 mUnk_1ac[0x28];
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ void *mUnk_1dc;
    /* 1e0 */ u8 mUnk_1e0[0xc];
    /* 1ec */ void *mUnk_1ec;
    /* 1f0 */ u8 mUnk_1f0[4];
    /* 1f4 */ Unk021906e4 mUnk_1f4;
    /* 204 */ s32 mUnk_204;
    /* 208 */ u8 mUnk_208[0x210];
    /* 418 */ u32 mUnk_418;
    /* 41c */ s32 mUnk_41c;
    /* 420 */ u8 mUnk_420[4];
    /* 424 */ Unk021937c0Node *mUnk_424;
    /* 428 */ void *mUnk_428;
    /* 42c */ u8 mUnk_42c[4];
    /* 430 */ s32 mUnk_430;
    /* 434 */ Unk02193f2cNode *mUnk_434;
    /* 438 */ Unk02190ed4Node *mUnk_438;
    /* 43c */ Unk02190ed4Node *mUnk_43c;
    /* 440 */ void *mUnk_440;
    /* 444 */ u8 mUnk_444[0xc];
    /* 450 */ void *mUnk_450;
    /* 454 */ u8 mUnk_454[0x18];
    /* 46c */ s32 mUnk_46c;
    /* 470 */ s32 mUnk_470;
    /* 474 */ s8 mUnk_474[0x19];
} Unk0218f960_00;

// Object passed to func_ov000_0218f960 as its first argument.
typedef struct Unk0218f960 {
    /* 00 */ Unk0218f960_00 *mUnk_00;
} Unk0218f960;

u32 func_ov000_0218f960(Unk0218f960 *p, u32 b);
