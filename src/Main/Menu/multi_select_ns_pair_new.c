#include "Main/Menu/multi_select_ns_pair_new.h"
#include "Main/Menu/multi_select_ns_has_pair.h"
#include "Main/System/input_slots.h"
#include "Main/System/init_after_startup.h"

#pragma optimize_for_size on

BOOL MultiSelectNSIsPairRecentlyLost(InputSlotPair *pair) {
    if (MultiSelectNSGetPairHasPair(pair) == 0 && pair->mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
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
