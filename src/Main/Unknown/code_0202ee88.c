#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

u32 ScrollListHasPairOrLost(InputSlotPair *pair) {
    u32 result;
    if (ScrollListIsPairRecentlyLost(pair) != 0 || ScrollListGetPairHasPair(pair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 ScrollListSlotHasPairOrLost(u32 slotIndex) {
    return ScrollListHasPairOrLost(&gInputSlots[slotIndex].mPair);
}

#pragma thumb on

void AdvanceScrollListInput(void) {
    u32 slotIndex = func_020435bc();
    u32 pairX;
    u32 pairY;
    s32 rectIndex;
    if (ScrollListIsSlotPairNew(slotIndex) != 0) {
        pairX = ScrollListGetSlotPairX(slotIndex);
        pairY = ScrollListGetSlotPairY(slotIndex);
        gScrollList->mTouchRectIndex = FindRectContainingPoint(pairX, pairY, gScrollList->mRects);
        gScrollList->mPressedRectIndex = gScrollList->mTouchRectIndex;
        gScrollList->mTouchHeld = TRUE;
    } else {
        gScrollList->mPressedRectIndex = -1;
    }
    if (gScrollList->mTouchHeld != FALSE) {
        if (ScrollListSlotHasPairOrLost(slotIndex) != 0) {
            pairX = ScrollListGetSlotPairX(slotIndex);
            pairY = ScrollListGetSlotPairY(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, gScrollList->mRects);
            if (rectIndex != gScrollList->mTouchRectIndex) {
                gScrollList->mTouchRectIndex = -1;
                gScrollList->mTouchHeld = FALSE;
            }
        } else {
            gScrollList->mTouchRectIndex = -1;
            gScrollList->mTouchHeld = FALSE;
        }
    }
    if (ScrollListGetDownBits(slotIndex, PAD_KEY_UP) != 0 ||
        gScrollList->mTouchRectIndex == gScrollList->mUpRectIndex) {
        gScrollList->mUpHeldFrames = gScrollList->mUpHeldFrames + 1;
    } else {
        gScrollList->mUpHeldFrames = 0;
    }
    if (ScrollListGetDownBits(slotIndex, PAD_KEY_DOWN) != 0 ||
        gScrollList->mTouchRectIndex == gScrollList->mDownRectIndex) {
        gScrollList->mDownHeldFrames = gScrollList->mDownHeldFrames + 1;
    } else {
        gScrollList->mDownHeldFrames = 0;
    }
}

void PlaceScrollListScrollEntry(void) {
    if (gScrollList->mEntries[gScrollList->mScrollEntry].mVisible != 0) {
        gScrollList->mEntries[gScrollList->mScrollEntry].mOffsetY =
            gScrollList->mScrollOffsetRange * (gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow) /
            (gScrollList->mRowCount - 5);
    }
}
