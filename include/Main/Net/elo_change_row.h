#pragma once
#include "types.h"

// One row of gEloChangeTable: mDifferenceAbove is the Elo difference the row applies above, mWinChange and mLossChange
// the Elo change.
typedef struct EloChangeRow {
    /* 00 */ s16 mDifferenceAbove;
    /* 02 */ s8 mWinChange;
    /* 03 */ s8 mLossChange;
} EloChangeRow;

