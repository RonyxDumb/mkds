#pragma once

#include "types.h"

// The seven decimal digits of a time: two for the minutes, two for the seconds, three for the milliseconds.
typedef struct TimeDigits {
    /* 00 */ s32 mDigits[7];
} TimeDigits;

void SortIndicesByKey(s32 *indices, s32 *keys, s32 count);
void SplitTimeDigits(s32 minute, s32 second, s32 millisecond, TimeDigits *timeDigits);
