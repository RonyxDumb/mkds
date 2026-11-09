#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1c4.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

BOOL MenuIsPairRecentlyLost(InputSlotPair *pair) {
    if (MenuGetPairHasPair(pair) == 0 && pair->mNoPairCount < 5) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsPairNewUnlessRecentlyLost(InputSlotPair *pair) {
    if (MenuIsPairRecentlyLost(pair) == FALSE && MenuIsPairNew(pair) != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsSlotPairNew(u32 slotIndex) {
    return MenuIsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair);
}
