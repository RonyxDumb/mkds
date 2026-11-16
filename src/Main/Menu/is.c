#include "Main/Menu/is.h"
#include "Main/Menu/menu_sound.h"
#include "Main/System/input_slots.h"
#include "Main/System/init_after_startup.h"

#pragma optimize_for_size on

BOOL MenuIsPairRecentlyLost(InputSlotPair *pair) {
    if (MenuGetPairHasPair(pair) == 0 && pair->mNoPairCount < INPUT_PAIR_RECENTLY_LOST_FRAMES) {
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

u32 MenuGetPairX(InputSlotPair *pairAddress) {
    return pairAddress->mPairX;
}

u32 MenuGetSlotPairX(u32 slotIndex) {
    return MenuGetPairX(&gInputSlots[slotIndex].mPair);
}

u32 MenuGetPairY(InputSlotPair *pairAddress) {
    return pairAddress->mPairY;
}

u32 MenuGetSlotPairY(u32 slotIndex) {
    return MenuGetPairY(&gInputSlots[slotIndex].mPair);
}
