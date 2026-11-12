#pragma once
#include "types.h"

// Table of entries of 4 bytes.
typedef struct EloChangeRow {
    /* 00 */ s16 mDifferenceAbove;
    /* 02 */ s8 mWinChange;
    /* 03 */ s8 mLossChange;
} EloChangeRow;

extern EloChangeRow gEloChangeTable[9];
