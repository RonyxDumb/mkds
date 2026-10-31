#pragma once

#include "types.h"
#include "00/code_0218ee1c.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_02190b80.h"
#include "00/code_02193000.h"
#include "00/code_02193e70.h"
#include "00/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"

// Message handed to func_ov000_02190ed4 by func_ov000_021941c4.
typedef struct Unk021941c4Msg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021941c4Msg;

// Entry of the list at 0x38 of Unk02193f2cNode.
typedef struct Unk02194370Entry {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02194370Entry;

extern u8 data_ov000_021b3490[];
extern u8 data_ov000_021b3494[];
extern u8 data_ov000_021b34a4[];
extern u8 data_ov000_021b34a8[];
extern u8 data_ov000_021b333c[];
extern u8 data_ov000_021b34c8[];
extern u8 data_ov000_021b34d0[];
extern u8 data_ov000_021b34d8[];
extern u8 data_ov000_021b34e0[];
extern u8 data_ov000_021b34e8[];
extern u8 data_ov000_021b34f0[];
extern u8 data_ov000_021b34f8[];
extern u8 data_ov000_021b3500[];
extern u8 data_ov000_021b3508[];
extern u8 data_ov000_021b352c[];
extern u8 data_ov000_021b33a0[];
extern u8 data_ov000_021b3440[];

s32 func_ov000_021941c4(Unk0218f960 *a, Unk02193f2cNode *b);
s32 func_ov000_02194370(Unk0218f960 *a, Unk02193f2cNode *b);
s32 func_ov000_021943f0(Unk0218f960 *a, Unk02193f2cNode *b);
s32 func_ov000_02194590(Unk0218f960 *a, Unk02193f2cNode *b);
