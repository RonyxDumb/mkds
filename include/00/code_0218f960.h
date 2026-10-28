#pragma once

#include "types.h"
#include "00/types_021937c0.h"

// Object behind Unk0218f960.mUnk_00: func_ov000_0218f960 passes the address of 0x1f4 to func_ov000_02190b80 and
// func_ov000_02190b58, reads 0x198 and decrements 0x430.
typedef struct Unk0218f960_00 {
    /* 000 */ u8 mUnk_000[0x108];
    /* 108 */ u32 mUnk_108;
    /* 10c */ u8 mUnk_10c[0x8c];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u8 mUnk_19c[0x58];
    /* 1f4 */ u8 mUnk_1f4[0x230];
    /* 424 */ Unk021937c0Node *mUnk_424;
    /* 428 */ void *mUnk_428;
    /* 42c */ u8 mUnk_42c[4];
    /* 430 */ s32 mUnk_430;
    /* 434 */ Unk02193f2cNode *mUnk_434;
} Unk0218f960_00;

// Object passed to func_ov000_0218f960 as its first argument.
typedef struct Unk0218f960 {
    /* 00 */ Unk0218f960_00 *mUnk_00;
} Unk0218f960;

u32 func_ov000_0218f960(Unk0218f960 *p, u32 b);
