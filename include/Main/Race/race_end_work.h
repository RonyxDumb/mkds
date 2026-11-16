#pragma once
#include "types.h"

// The race end: its frame counter, the stem set request and whether the results were set.
typedef struct RaceEnd {
    /* 00 */ s32 mEndFrames;
    /* 04 */ BOOL mStemSetRequested;
    // Calls counted while the request flag is set; never zeroed after allocation, so only the first request is served.
    /* 08 */ s32 mStemSetRequestFrames;
    /* 0c */ BOOL mResultsSet;
} RaceEnd;

