#pragma once

#include "types.h"

typedef struct Unk021868a4Entry {
    /* 00 */ void *mFirst;
    /* 04 */ void *mSecond;
} Unk021868a4Entry;

typedef struct Unk021868a4 {
    /* 00 */ Unk021868a4Entry *mEntries;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mCount;
} Unk021868a4;

s32 func_ov000_021868a4(Unk021868a4 *list, void *first, void *second);
