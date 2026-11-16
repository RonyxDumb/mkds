#pragma once
#include "types.h"

// One row of the kart icon table: the BNCL index and the NCLR index and start.
typedef struct KartIconRow {
    /* 00 */ u16 mBnclIndex;
    /* 02 */ u16 mSize;
    /* 04 */ u32 mNclrIndex;
    /* 08 */ u16 mNclrStart;
    /* 0a */ u16 mUnk_0a;
} KartIconRow;

