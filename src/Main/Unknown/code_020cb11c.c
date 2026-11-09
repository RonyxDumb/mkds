#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1c4.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

BOOL MenuIsPairRecentlyLost(u16 *pair) {
    if (MenuGetPairHasPair(pair) == 0 && pair[8] < 5) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsPairNew(u16 *pair) {
    if (pair[6] == 0 && pair[2] != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsPairNewUnlessRecentlyLost(u16 *pair) {
    if (MenuIsPairRecentlyLost(pair) == FALSE && MenuIsPairNew(pair) != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL MenuIsSlotPairNew(u32 slotIndex) {
    return MenuIsPairNewUnlessRecentlyLost(&gInputSlots[slotIndex].mPair.mPairX);
}
