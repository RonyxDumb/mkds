#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b1c.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair) {
    if (ChoisesSGetPairHasPair(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair) {
    if (ChoisesSIsPairRecentlyLost(inputSlotPair) == 0 && ChoisesSIsPairNew(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

u32 ChoisesSIsSlotPairNew(s32 slotIndex) {
    return ChoisesSIsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair);
}
