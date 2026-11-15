#include "Main/Menu/scroll_list_state.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/System/input_slots.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "gfd_VramTransferManager.h"
#include "player.h"
#include "sound_archive_load_result.h"
#include "Main/Graphics/oam.h"
#include "cpu_copy_fill.h"
#include "cpu_copy_clear_16.h"
#include "Main/System/heap.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

ScrollList *gScrollList;

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

u32 ScrollListGetPairX(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 ScrollListGetSlotPairX(u32 slot) {
    return ScrollListGetPairX(&gInputSlots[slot].mPair);
}

u32 ScrollListGetPairY(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 ScrollListGetSlotPairY(u32 slot) {
    return ScrollListGetPairY(&gInputSlots[slot].mPair);
}

#pragma optimize_for_size on

u32 ScrollListIsPairRecentlyLost(InputSlotPair *pair) {
    u32 result = 0;
    if (ScrollListGetPairHasPair(pair) == 0 && pair->mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        result = 1;
    }
    return result;
}

u32 ScrollListGetPairHasPair(InputSlotPair *pair) {
    return pair->mHasPair;
}

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
    u32 slotIndex = GetPadInputSlot();
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
#pragma thumb off

#pragma thumb on

u32 GetScrollListHiddenBottomSlot(void) {
    u32 slot;
    slot = (gScrollList->mHiddenTopSlot + 6) % (7);
    return slot;
}

#pragma thumb off

#pragma optimize_for_size on

#pragma thumb on

void SetScrollListSlotVisible(s32 slot, s32 visible) {
    s32 group;
    for (group = 0; group < gScrollList->mGroupCount; group++) {
        ScrollList *scrollList = gScrollList;
        scrollList->mEntries[slot + scrollList->mGroupFirstEntries[group]].mVisible = visible;
    }
}

#pragma thumb off

#pragma thumb on

u32 GetScrollListPositionYDifference(u32 first, u32 second) {
    return (((gScrollList->mEntries[second].mPositionY)) - ((gScrollList->mEntries[first].mPositionY)));
}

u32 GetScrollListSelectedSlot(void) {
    u32 slot;
    slot = (gScrollList->mHiddenTopSlot + gScrollList->mSelectedVisibleRow + 1) % (7);
    return slot;
}

#pragma thumb off

#pragma optimize_for_size on

#pragma thumb on

void PlaceScrollListCursor(void) {
    ScrollList *scrollList = gScrollList;
    s32 entryIndex;
    s16 positionY;
    entryIndex = scrollList->mGroupFirstEntries[0] + GetScrollListSelectedSlot();
    positionY = scrollList->mEntries[entryIndex].mPositionY;
    scrollList->mEntries[scrollList->mCursorEntry].mPositionY = positionY;
}

void SetScrollListRightColumnHighBits(s32 highBits) {
    s32 column;
    s32 row;
    for (row = 1; row < 0x13; row++) {
        for (column = 0x1c; column < 0x20; column++) {
            u8 *halfwordPointer = (u8 *) gScrollList + (column + row * 0x20) * 2;
            halfwordPointer += 0x58;
            *(u16 *) halfwordPointer = *(u16 *) halfwordPointer & 0xfff;
            halfwordPointer = (u8 *) gScrollList + (column + row * 0x20) * 2;
            halfwordPointer += 0x58;
            *(u16 *) halfwordPointer = *(u16 *) halfwordPointer | (highBits << 12);
        }
    }
    gScrollList->mRightColumnHighBitsTimer = SCROLL_LIST_HIGH_BITS_FRAMES;
    gScrollList->mRightColumnHighBits = highBits;
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, 0, gScrollList->mScreenMap, 0x600);
}

void AdvanceScrollListRightColumnTimer(void) {
    if (gScrollList->mRightColumnHighBits != 0) {
        if (gScrollList->mRightColumnHighBitsTimer == 0) {
            SetScrollListRightColumnHighBits(0);
            gScrollList->mRightColumnHighBits = 0;
        } else {
            gScrollList->mRightColumnHighBitsTimer = gScrollList->mRightColumnHighBitsTimer - 1;
        }
    } else {
        gScrollList->mRightColumnHighBitsTimer = 0;
    }
}

#pragma thumb off

u16 ScrollListGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 ScrollListGetNewBits(u32 slotIndex, u32 mask) {
    return ScrollListGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 ScrollListStartSeqArc(u32 index, u32 archiveNo) {
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, archiveNo, index);
}

u32 ScrollListStartSeqArcWrapper(u32 index) {
    return ScrollListStartSeqArc(index, 0u);
}

#pragma optimize_for_size on

u16 GetSlotDownBits(InputSlot *slot, u32 mask) {
    return slot->mBits & mask;
}

u16 ScrollListGetDownBits(u32 slotIndex, u32 mask) {
    return GetSlotDownBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

// Idle state: starts a pick, a selection move or a scroll from the keys and the touch.
void AdvanceScrollListIdle(void) {
    u32 slotIndex = GetPadInputSlot();
    BOOL rowChanged;
    if (gScrollList->mEnabled == 0) {
        return;
    }
    gScrollList->mScrollFrameCount = gScrollList->mHeldMoveCount > SCROLL_LIST_FAST_HELD_MOVES
                                         ? SCROLL_LIST_FAST_SCROLL_FRAMES
                                         : SCROLL_LIST_SLOW_SCROLL_FRAMES;
    if (ScrollListGetNewBits(slotIndex, PAD_KEY_A) != 0) {
        gScrollList->mState = SCROLL_LIST_STATE_PICK;
        gScrollList->mPickedVisibleRow = gScrollList->mSelectedVisibleRow;
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
        gScrollList->mTimer = SCROLL_LIST_PICK_FRAMES;
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mUpHeldFrames = gScrollList->mDownHeldFrames;
        gScrollList->mHeldMoveCount = 0;
        PlaceScrollListCursor();
        CallScrollListCallback(0, -1, -1, -1);
        return;
    }
    if (gScrollList->mFirstRowRectIndex <= gScrollList->mPressedRectIndex &&
        gScrollList->mPressedRectIndex < gScrollList->mFirstRowRectIndex + 5 &&
        gScrollList->mPressedRectIndex - gScrollList->mFirstRowRectIndex < gScrollList->mRowCount) {
        gScrollList->mState = SCROLL_LIST_STATE_PICK;
        gScrollList->mPickedVisibleRow = gScrollList->mPressedRectIndex - gScrollList->mFirstRowRectIndex;
        rowChanged = gScrollList->mPickedVisibleRow != gScrollList->mSelectedVisibleRow;
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = rowChanged;
        gScrollList->mTimer = SCROLL_LIST_PICK_FRAMES;
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mUpHeldFrames = gScrollList->mDownHeldFrames;
        gScrollList->mHeldMoveCount = 0;
        gScrollList->mSelectedRow =
            gScrollList->mSelectedRow + (gScrollList->mPickedVisibleRow - gScrollList->mSelectedVisibleRow);
        gScrollList->mSelectedVisibleRow = gScrollList->mPickedVisibleRow;
        PlaceScrollListCursor();
        CallScrollListCallback(0, -1, -1, rowChanged != FALSE ? GetScrollListSelectedSlot() : -1);
        return;
    }
    if ((ScrollListGetNewBits(slotIndex, PAD_KEY_UP) != 0 ||
         gScrollList->mPressedRectIndex == gScrollList->mUpRectIndex ||
         gScrollList->mUpHeldFrames > gScrollList->mScrollFrameCount) &&
        gScrollList->mSelectedRow > 0) {
        if (gScrollList->mSelectedVisibleRow == 0) {
            gScrollList->mTimer = gScrollList->mScrollFrameCount;
            gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
            gScrollList->mState = SCROLL_LIST_STATE_SCROLL_UP;
            SetScrollListSlotVisible(gScrollList->mHiddenTopSlot, 1);
            CallScrollListCallback(0, -1, -1, -1);
            CallScrollListCallback(2, gScrollList->mHiddenTopSlot,
                                   gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow - 1, -1);
        } else {
            gScrollList->mState = SCROLL_LIST_STATE_SELECT_UP;
        }
        gScrollList->mUpHeldFrames = 0;
        gScrollList->mHeldMoveCount = gScrollList->mHeldMoveCount + 1;
        if (gScrollList->mTouchRectIndex == gScrollList->mUpRectIndex) {
            SetScrollListRightColumnHighBits(1);
        }
        ScrollListStartSeqArcWrapper(3);
        return;
    }
    if ((ScrollListGetNewBits(slotIndex, PAD_KEY_DOWN) != 0 ||
         gScrollList->mPressedRectIndex == gScrollList->mDownRectIndex ||
         gScrollList->mDownHeldFrames > gScrollList->mScrollFrameCount) &&
        gScrollList->mSelectedRow < gScrollList->mRowCount - 1) {
        if (gScrollList->mSelectedVisibleRow == 4) {
            gScrollList->mTimer = gScrollList->mScrollFrameCount;
            gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
            gScrollList->mState = SCROLL_LIST_STATE_SCROLL_DOWN;
            SetScrollListSlotVisible(GetScrollListHiddenBottomSlot(), 1);
            CallScrollListCallback(0, -1, -1, -1);
            {
                ScrollList *list = gScrollList;
                CallScrollListCallback(2, GetScrollListHiddenBottomSlot(),
                                       list->mSelectedRow - list->mSelectedVisibleRow + 5, -1);
            }
        } else {
            gScrollList->mState = SCROLL_LIST_STATE_SELECT_DOWN;
        }
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mHeldMoveCount = gScrollList->mHeldMoveCount + 1;
        if (gScrollList->mTouchRectIndex == gScrollList->mDownRectIndex) {
            SetScrollListRightColumnHighBits(2);
        }
        ScrollListStartSeqArcWrapper(3);
        return;
    }
    if (ScrollListGetDownBits(slotIndex, PAD_KEY_UP | PAD_KEY_DOWN) == 0 &&
        gScrollList->mTouchRectIndex != gScrollList->mUpRectIndex &&
        gScrollList->mTouchRectIndex != gScrollList->mDownRectIndex) {
        gScrollList->mHeldMoveCount = 0;
    }
}

void AdvanceScrollListSelectUp(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow - 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
    PlaceScrollListCursor();
    CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = SCROLL_LIST_STATE_IDLE;
}

void AdvanceScrollListSelectDown(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow + 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
    PlaceScrollListCursor();
    CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = SCROLL_LIST_STATE_IDLE;
}

void AdvanceScrollListScrollUp(void) {
    s32 groupIndex;
    s32 slotIndex;
    s32 firstEntry;
    s32 distance;
    LayoutTableEntry *entry;
    BOOL zero = FALSE;
    s32 hiddenBottomSlot = GetScrollListHiddenBottomSlot();
    gScrollList->mTimer = gScrollList->mTimer - 1;
    for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
        for (slotIndex = zero; slotIndex < 7; slotIndex++) {
            firstEntry = gScrollList->mGroupFirstEntries[groupIndex];
            distance = GetScrollListPositionYDifference(slotIndex + firstEntry, (slotIndex + 1) % 7 + firstEntry);
            entry = &gScrollList->mEntries[slotIndex + firstEntry];
            if (slotIndex == hiddenBottomSlot) {
                entry->mOffsetY = distance;
            } else {
                entry->mOffsetY =
                    InterpolateS16(1, distance, zero, gScrollList->mTimer, gScrollList->mScrollFrameCount);
            }
        }
    }
    if (gScrollList->mTimer == 0) {
        for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
            for (slotIndex = zero; slotIndex < 7; slotIndex++) {
                entry = &gScrollList->mEntries[slotIndex + gScrollList->mGroupFirstEntries[groupIndex]];
                entry->mPositionY = entry->mPositionY + entry->mOffsetY;
                entry->mOffsetY = 0;
            }
        }
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
        gScrollList->mHiddenTopSlot = hiddenBottomSlot;
        CallScrollListCallback(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow - 1, -1);
        {
            ScrollList *list = gScrollList;
            CallScrollListCallback(0, list->mHiddenTopSlot, list->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = SCROLL_LIST_STATE_IDLE;
        SetScrollListSlotVisible(gScrollList->mHiddenTopSlot, 0);
    }
}

void AdvanceScrollListScrollDown(void) {
    s32 groupIndex;
    s32 slotIndex;
    s32 firstEntry;
    s32 distance;
    LayoutTableEntry *entry;
    BOOL zero = FALSE;
    gScrollList->mTimer = gScrollList->mTimer - 1;
    for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
        for (slotIndex = zero; slotIndex < 7; slotIndex++) {
            firstEntry = gScrollList->mGroupFirstEntries[groupIndex];
            distance = GetScrollListPositionYDifference(slotIndex + firstEntry, (slotIndex + 6) % 7 + firstEntry);
            entry = &gScrollList->mEntries[slotIndex + firstEntry];
            if (slotIndex == gScrollList->mHiddenTopSlot) {
                entry->mOffsetY = distance;
            } else {
                entry->mOffsetY =
                    InterpolateS16(1, distance, zero, gScrollList->mTimer, gScrollList->mScrollFrameCount);
            }
        }
    }
    if (gScrollList->mTimer == 0) {
        for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
            for (slotIndex = zero; slotIndex < 7; slotIndex++) {
                entry = &gScrollList->mEntries[slotIndex + gScrollList->mGroupFirstEntries[groupIndex]];
                entry->mPositionY = entry->mPositionY + entry->mOffsetY;
                entry->mOffsetY = 0;
            }
        }
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
        CallScrollListCallback(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow + 1, -1);
        {
            ScrollList *list = gScrollList;
            list->mHiddenTopSlot = (list->mHiddenTopSlot + 1) % 7;
        }
        {
            ScrollList *list = gScrollList;
            CallScrollListCallback(0, list->mHiddenTopSlot, list->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = SCROLL_LIST_STATE_IDLE;
        SetScrollListSlotVisible(GetScrollListHiddenBottomSlot(), 0);
    }
}

void AdvanceScrollListPick(void) {
    if (gScrollList->mTimer == SCROLL_LIST_PICK_FRAMES) {
        gScrollList->mPickStarted = 1;
    }
    gScrollList->mTimer = gScrollList->mTimer - 1;
    if (gScrollList->mTimer == 0) {
        CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mState = SCROLL_LIST_STATE_IDLE;
        gScrollList->mPickFinished = 1;
    }
}

#pragma thumb off

void ScrollListMI_CpuFillFast(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void ScrollListMI_CpuClearFast(void *dest, u32 size) {
    ScrollListMI_CpuFillFast(dest, 0, size);
}

void ScrollListMI_CpuCopy16(const void *src, void *dst, u32 size) {
    MIi_CpuCopy16(src, dst, size);
}

#pragma optimize_for_size on

#pragma thumb on

void InitScrollList(void *heap, s32 groupCount, const void *groupFirstEntries, u16 cursorEntry, u16 scrollEntry,
                    s32 scrollOffsetRange, LayoutTableEntry *entries, void *rects, const void *screenMap,
                    s32 upRectIndex, s32 downRectIndex, s32 firstRowRectIndex, s32 rowCount,
                    void (*callback)(int action, int slot, int row, int selectedSlot)) {
    s32 row;
    gScrollList = HeapAlloc(heap, sizeof(*gScrollList));
    ScrollListMI_CpuClearFast(gScrollList, 0x674);
    gScrollList->mGroupCount = groupCount;
    groupCount = groupCount * 2;
    gScrollList->mGroupFirstEntries = HeapAllocAligned(heap, groupCount, HEAP_ALIGN_CACHE_LINE);
    ScrollListMI_CpuCopy16(groupFirstEntries, gScrollList->mGroupFirstEntries, groupCount);
    ScrollListMI_CpuCopy16(screenMap, gScrollList->mScreenMap, 0x600);
    gScrollList->mCursorEntry = cursorEntry;
    gScrollList->mScrollEntry = scrollEntry;
    gScrollList->mScrollOffsetRange = scrollOffsetRange;
    gScrollList->mEntries = entries;
    gScrollList->mRowCount = rowCount;
    gScrollList->mCallback = callback;
    gScrollList->mRects = rects;
    gScrollList->mUpRectIndex = upRectIndex;
    gScrollList->mDownRectIndex = downRectIndex;
    gScrollList->mFirstRowRectIndex = firstRowRectIndex;
    gScrollList->mEnabled = 1;
    gScrollList->mTouchRectIndex = -1;
    gScrollList->mPressedRectIndex = gScrollList->mTouchRectIndex;
    PlaceScrollListCursor();
    CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
    for (row = 0; row < 6 && row < gScrollList->mRowCount; row++) {
        CallScrollListCallback(1, row + 1, row, -1);
    }
    SetScrollListSlotVisible(0, 0);
    SetScrollListSlotVisible(6, 0);
    for (row = gScrollList->mRowCount; row < 5; row++) {
        SetScrollListSlotVisible(row + 1, 0);
    }
    gScrollList->mEntries[gScrollList->mScrollEntry].mVisible = gScrollList->mRowCount > 5;
    if (gScrollList->mRowCount == 0) {
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
    }
    gScrollList->mScrollFrameCount = SCROLL_LIST_SLOW_SCROLL_FRAMES;
}

void AdvanceScrollList(void) {
    gScrollList->mPickStarted = 0;
    gScrollList->mPickFinished = gScrollList->mPickStarted;
    AdvanceScrollListInput();
    AdvanceScrollListRightColumnTimer();
    switch (gScrollList->mState) {
        case SCROLL_LIST_STATE_IDLE:
            AdvanceScrollListIdle();
            break;
        case SCROLL_LIST_STATE_SELECT_UP:
            AdvanceScrollListSelectUp();
            break;
        case SCROLL_LIST_STATE_SELECT_DOWN:
            AdvanceScrollListSelectDown();
            break;
        case SCROLL_LIST_STATE_SCROLL_UP:
            AdvanceScrollListScrollUp();
            break;
        case SCROLL_LIST_STATE_SCROLL_DOWN:
            AdvanceScrollListScrollDown();
            break;
        case SCROLL_LIST_STATE_PICK:
            AdvanceScrollListPick();
            break;
    }
    PlaceScrollListScrollEntry();
}

#pragma thumb off

#pragma thumb on

u32 GetScrollListSelectedRow(void) {
    return (gScrollList->mSelectedRow);
}

void SetScrollListEnabled(u32 enabled) {
    gScrollList->mEnabled = enabled;
}

u32 IsScrollListPickFinished(void) {
    return (gScrollList->mPickFinished);
}

u32 IsScrollListPickStarted(void) {
    return (gScrollList->mPickStarted);
}

#pragma thumb off
