#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

BOOL SelectKartIsPairRecentlyLost(InputSlotPair *pair) {
    if (SelectKartGetPairHasPair(pair) == 0) {
        if (pair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

BOOL SelectKartIsPairNewUnlessLost(InputSlotPair *pair) {
    if (SelectKartIsPairRecentlyLost(pair) == 0) {
        if (SelectKartIsPairNew(pair) != 0) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsSlotPairNew(u32 slot) {
    return SelectKartIsPairNewUnlessLost(&gInputSlots[slot].mPair);
}
