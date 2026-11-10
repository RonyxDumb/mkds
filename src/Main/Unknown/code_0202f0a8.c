#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void CallScrollListCallback(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    void (*callback)(int, int, int, int) = gScrollList->mCallback;
    if (callback != NULL) {
        if (action == 1) {
            if (row < 0 || row >= gScrollList->mRowCount) {
                return;
            }
        }
        callback(action, slot, row, selectedSlot);
    }
}

#pragma thumb off

u32 ScrollListIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 ScrollListIsPairNewUnlessLost(InputSlotPair *pair) {
    u32 result = 0;
    if (ScrollListIsPairRecentlyLost(pair) == 0 && ScrollListIsPairNew(pair) != 0) {
        result = 1;
    }
    return result;
}

u32 ScrollListIsSlotPairNew(u32 slotIndex) {
    return ScrollListIsPairNewUnlessLost(&gInputSlots[slotIndex].mPair);
}
