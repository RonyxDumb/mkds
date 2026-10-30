#pragma once

#include "types.h"
#include "00/types_021906e4.h"

typedef struct Unk021937c0Node {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02191284Data *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02190ed4Cb mUnk_0c;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ struct Unk021937c0Node *mNext;
} Unk021937c0Node;

typedef struct Unk02193f2cNode {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ void *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[8];
    /* 28 */ void *mUnk_28;
    /* 2c */ u8 mUnk_2c[0xc];
    /* 38 */ void *mUnk_38;
    /* 3c */ struct Unk02193f2cNode *mNext;
} Unk02193f2cNode;
