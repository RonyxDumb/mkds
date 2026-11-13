#include "Main/Menu/title_pair_new.h"
#include "Main/Menu/title_input.h"
#include "Main/Menu/data_02175628.h"
#include "Main/System/init_after_startup.h"

#pragma optimize_for_size on

u32 TitleIsPairRecentlyLost(InputSlotPair *inputSlotPair) {
    if (TitleGetPairHasPair(inputSlotPair) == 0) {
        if (inputSlotPair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 TitleIsPairNew(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 TitleIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair) {
    u32 result;

    if (TitleIsPairRecentlyLost(inputSlotPair) == 0 && TitleIsPairNew(inputSlotPair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 TitleIsSlotPairNew(u32 slotIndex) {
    return TitleIsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair);
}
