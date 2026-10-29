#pragma once

#include "types.h"

// Slot of data_02175628 that the code addresses through a constant.
typedef enum Unk02175628Index { UNK_02175628_INDEX_8 = 8 } Unk02175628Index;

// One 0x5c-byte element of the array at data_02175628.
typedef struct Unk02175628 {
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
    /* 16 */ u8 mUnk_16[0x2];
    /* 18 */ u64 mUnk_18;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ s32 mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 44 */ s32 mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u16 mUnk_52;
    /* 54 */ u16 mUnk_54;
    /* 56 */ u16 mUnk_56;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a;
    /* 5b */ u8 mUnk_5b;
} Unk02175628;

// The 0x14 bytes at 0x48 of an element of data_02175628 (the same bytes as its mUnk_48 to mUnk_5b).
typedef struct Unk02175628_48 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[0x2];
} Unk02175628_48;

extern Unk02175628 data_0217562c[];

extern Unk02175628 data_02175680[];

extern Unk02175628 data_0217567c[];

extern Unk02175628 data_02175674[];

extern Unk02175628 data_02175672[];

extern Unk02175628 data_02175670[];

extern Unk02175628 data_02175628[];
