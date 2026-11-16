#pragma once

#include "types.h"

typedef struct Unk0208ffd8 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ u32 field10;
} Unk0208ffd8;

void SetItemBitsEveryCall(Unk0208ffd8 *itemUse);
