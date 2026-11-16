#pragma once
#include "types.h"

// One row of the Elo change table: the rating difference above and the points a win and a loss change.
typedef struct EloChangeRow {
    /* 00 */ s16 mDifferenceAbove;
    /* 02 */ s8 mWinChange;
    /* 03 */ s8 mLossChange;
} EloChangeRow;

