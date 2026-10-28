#pragma once

#include "types.h"

typedef struct Unk021937c0Node {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ struct Unk021937c0Node *mNext;
} Unk021937c0Node;

typedef struct Unk02193f2cNode {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0x2c];
    /* 3c */ struct Unk02193f2cNode *mNext;
} Unk02193f2cNode;
