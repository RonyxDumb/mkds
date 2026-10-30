#pragma once

#include "types.h"
#include "00/types_021906e4.h"

// Object behind Unk021937c0Node.mUnk_04: func_ov000_02196240 clears and fills it, func_ov000_021962d4 sets the
// word at 0x04 and gives it the buffer at 0x08 of 0x0c bytes.
typedef struct Unk02196240 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ void *mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u32 mUnk_010;
    /* 014 */ u32 mUnk_014;
    /* 018 */ void *mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ u32 mUnk_020;
    /* 024 */ u32 mUnk_024;
    /* 028 */ u8 mUnk_028[0x114];
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
} Unk02196240;

typedef struct Unk021937c0Node {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02196240 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02190ed4Cb mUnk_0c;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ struct Unk021937c0Node *mNext;
} Unk021937c0Node;

typedef struct Unk02193f2cNode {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u8 mUnk_28[8];
    /* 30 */ s32 mUnk_30;
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ void *mUnk_38;
    /* 3c */ struct Unk02193f2cNode *mNext;
} Unk02193f2cNode;
