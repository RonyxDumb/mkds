#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b0.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

BOOL MultiSelectNSIsPairRecentlyLost(InputSlotPair *pair) {
    if (MultiSelectNSGetPairHasPair(pair) == 0 && pair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

BOOL MultiSelectNSIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

BOOL MultiSelectNSIsPairNewUnlessLost(InputSlotPair *pair) {
    if (MultiSelectNSIsPairRecentlyLost(pair) == 0 && MultiSelectNSIsPairNew(pair) != 0) {
        return 1;
    }
    return 0;
}

BOOL MultiSelectNSIsSlotPairNew(u32 slotIndex) {
    return MultiSelectNSIsPairNewUnlessLost(&gInputSlots[slotIndex].mPair);
}
