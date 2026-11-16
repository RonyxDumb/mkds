#include "Main/System/time_digits.h"

#pragma optimize_for_size on

#pragma thumb on

// Splits minutes, seconds and milliseconds into the seven digits of a TimeDigits (no clamping; the callers pass minutes
// < 100).
void SplitTimeDigits(s32 minute, s32 second, s32 millisecond, TimeDigits *timeDigits) {
    timeDigits->mDigits[0] = minute / 10;
    timeDigits->mDigits[1] = minute % 10;
    timeDigits->mDigits[2] = second / 10;
    timeDigits->mDigits[3] = second % 10;
    timeDigits->mDigits[4] = millisecond / 100;
    timeDigits->mDigits[5] = (millisecond - timeDigits->mDigits[4] * 100) / 10;
    timeDigits->mDigits[6] = millisecond % 10;
}

// Exchange sort in place: afterwards keys[indices[0]] <= keys[indices[1]] <= ... for the first count entries (a smaller
// key first; unstable); all callers pass 0..mKartCount-1 in indices and negate the keys for a descending order.
void SortIndicesByKey(s32 *indices, s32 *keys, s32 count) {
    s32 outerIndex;
    s32 innerIndex;
    s32 *outerSlot;
    s32 *innerSlot;
    s32 innerEntry;
    s32 outerEntry;
    s32 outerKey;
    s32 innerKey;

    for (outerIndex = 0; outerIndex < count - 1; outerIndex++) {
        innerIndex = count - 1;
        outerSlot = &indices[outerIndex];
        for (; innerIndex > outerIndex; innerIndex--) {
            innerSlot = &indices[innerIndex];
            innerEntry = indices[innerIndex];
            outerEntry = *outerSlot;
            outerKey = keys[outerEntry];
            innerKey = keys[innerEntry];
            if (outerKey > innerKey) {
                *outerSlot = innerEntry;
                *innerSlot = outerEntry;
            }
        }
    }
}

#pragma thumb off
