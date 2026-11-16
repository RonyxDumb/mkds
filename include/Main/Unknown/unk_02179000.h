#pragma once

#include "types.h"

struct RomArchiveFileNode;

// Object behind data_02179ec0: the list head at 0xb04 is the word at 0x46c4 of data_02176300.
typedef struct Unk02179ec0 {
    /* 000 */ u8 field0[0xb04];
    /* b04 */ struct RomArchiveFileNode *fieldB04;
    /* b08 */ u8 fieldB08[8];
    /* b10 */ u32 fieldB10;
} Unk02179ec0;

extern Unk02179ec0 data_02179ec0;
