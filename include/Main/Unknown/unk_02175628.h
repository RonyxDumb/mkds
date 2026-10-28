#pragma once

#include "types.h"

// Slot of data_02175628 that the code addresses through a constant.
typedef enum Unk02175628Index { UNK_02175628_INDEX_8 = 8 } Unk02175628Index;

// One 0x5c-byte element of the array at data_02175628.
typedef struct Unk02175628 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[2];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x40];
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u8 mUnk_4e[6];
    /* 54 */ u16 mUnk_54;
    /* 56 */ u8 mUnk_56[2];
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a;
    /* 5b */ u8 mUnk_5b;
} Unk02175628;

extern Unk02175628 data_0217562c[];

extern Unk02175628 data_02175680[];

extern Unk02175628 data_0217567c[];

extern Unk02175628 data_02175674[];

extern Unk02175628 data_02175672[];

extern Unk02175628 data_02175670[];

extern Unk02175628 data_02175628[];
