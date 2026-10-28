#pragma once

#include "types.h"
#include "00/code_0218f000.h"
#include "00/code_02190000.h"
#include "00/code_02190b80.h"
#include "00/code_02194000.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"

// Object behind Unk0218f960.mUnk_00: func_ov000_0218f960 passes the address of 0x1f4 to func_ov000_02190b80 and
// func_ov000_02190b58, reads 0x198 and decrements 0x430.
typedef struct Unk0218f960_00 {
    /* 000 */ u8 mUnk_000[0x198];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u8 mUnk_19c[0x58];
    /* 1f4 */ u8 mUnk_1f4[0x23c];
    /* 430 */ s32 mUnk_430;
} Unk0218f960_00;

// Object passed to func_ov000_0218f960 as its first argument.
typedef struct Unk0218f960 {
    /* 00 */ Unk0218f960_00 *mUnk_00;
} Unk0218f960;

u32 func_ov000_0218f960(Unk0218f960 *p, u32 b);
