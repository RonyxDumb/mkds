#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
typedef struct Unk027e0000 Unk027e0000;
extern Unk027e0000 data_027e0000;
struct KartItems;
// Element 8 is used by code_021001ac.c for an owner flagged 0x8000
extern struct KartItems *it_sDriverItemStatus;
extern s32 col_sColResponseCount;
extern u16 col_sColResponsePrismAttributes[16];
extern u32 col_sColResponseColFlags[16];
extern u16 it_sDriverCount;
