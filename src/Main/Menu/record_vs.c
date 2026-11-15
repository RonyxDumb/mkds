#include "Main/Menu/record_vs.h"
#include "Main/System/heap.h"

#include "Main/Menu/record_list.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/data_0216d000.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/scene_numbers.h"
#include "Main/Menu/record_vs_erase.h"
#include "Main/Graphics/scene_text.h"
#include "01/Menu/record_top_menu.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/record_scene.h"
#include "01/Menu/option_select_menu.h"
#include "registers.h"
#include "code_0212df7c.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/select_return.h"
#include "Main/Item/item_pool.h"
#include "Main/Menu/data_0215c000.h"
#include "Main/Menu/data_02175628.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_gpx.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

char *gRecordVSMTransientBnclName = "Record_VS_m_transient.bncl";
const u16 gRecordVSGridLabelIndices[3][3] = {{2, 3, 4}, {5, 7, 9}, {6, 8, 0xa}};
const u16 gRecordVSPageButtonIndices[2] = {0x14, 0x15};
const s16 gRecordVSRectRowIndices[10] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
const u16 gRecordVSFriendKeyLabelHeights[12] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
const u16 gRecordVSRowLabelIndices[6] = {0, 1, 2, 3, 4, 0};
const u16 gRecordVSRowLabelWidths[6] = {0x78, 0x78, 0x78, 0x78, 0x78, 0};
char *gRecordVSMBnclName = "Record_VS_m.bncl";
char *gRecordVSMNscrName = "Record_VS_m.nscr";
char *gRecordVSMBNclrName = "Record_VS_m_b.nclr";
char *gRecordVSSONclrName = "Record_VS_s_o.nclr";
char *gRecordVSM03NscrName = "Record_VS_m03.nscr";
const u16 gRecordVSFriendKeyLabelWidths[12] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
const u16 gRecordVSUnhighlightedObjectIndices[6] = {0, 1, 2, 3, 4, 0};
const u16 gRecordVSHighlightObjectIndices[6] = {5, 6, 7, 8, 9, 0};
char *gRecordVSMNcgrName = "Record_VS_m.nce.ncgr";
const u16 gRecordVSUnflaggedObjectIndices[6] = {0xa, 0xb, 0xc, 0xd, 0xe, 0};
char *gRecordVSSBnclName = "Record_VS_s.bncl";
char *gRecordVSMONclrName = "Record_VS_m_o.nclr";
char *gRecordVSSNcerName = "Record_VS_s.nce.ncer";
const u16 gRecordVSGridLabelWidths[3][3] = {{0x70, 0x70, 0x70}, {0x20, 0x20, 0x20}, {0x20, 0x20, 0x20}};
const u16 gRecordVSFriendKeyLabelIndices[12] = {2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd};
char *gRecordVSSBnblName = "Record_VS_s.bnbl";
const u16 gRecordVSPageButtonPressedIndices[2] = {0x16, 0x17};
const u16 gRecordVSRowLabelHeights[6] = {0x10, 0x10, 0x10, 0x10, 0x10, 0};
char *gRecordVSSBnllName = "Record_VS_s.bnll";
const u16 gRecordVSGridLabelHeights[3][3] = {{0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}};
const u16 gRecordVSFlaggedObjectIndices[6] = {0xf, 0x10, 0x11, 0x12, 0x13, 0};
char *gRecordVSSNcgrName = "Record_VS_s.nce.ncgr";
char *gRecordVSMTransientBnllName = "Record_VS_m_transient.bnll";
const u16 gRecordVSGridRow0MessageIndices[4] = {6, 7, 8, 0};
char *gRecordVSM02NscrName = "Record_VS_m02.nscr";
char *gRecordVSMNcerName = "Record_VS_m.nce.ncer";
char *gRecordVSMBNcgrName = "Record_VS_m_b.ncgr";
char *gRecordVSMBnllName = "Record_VS_m.bnll";
struct RecordScene *gRecordScene;

#pragma thumb on

void AdvanceRecordVSWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestRecordVSSlideInMain();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSSlideInMain(void) {
    u16 transientBase;
    u16 mainBase;
    s32 rowIndex;
    s32 labelIndex;
    s16 offset;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, -192, 0, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    gRecordVS->mBg0OffsetY = offset;
    gRecordVS->mBg1OffsetY = offset;
    mainBase = gRecordVS->mRecordVSMBncl->mCount;
    gRecordVS->mRecordVSMTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetY = offset;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[rowIndex][labelIndex]].mOffsetY = offset;
        }
    }
    transientBase = gRecordVS->mRecordVSMTransientBncl->mCount;
    gRecordVS->mRecordVSMTransientTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetY = offset;
    for (labelIndex = 0; labelIndex < 12; labelIndex++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[labelIndex]].mOffsetY =
            offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSSlideInSubAndRefreshPage();
    }
}

void AdvanceRecordVSSlideInSub(void) {
    s16 offset;
    s32 rowIndex;
    u16 subBase;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, 0x100, 0, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[rowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSWaitReturnButton();
    }
    if (gRecordVS->mStateFrames == RECORD_VS_SUB_SLIDE_IN_SWAP_STEP) {
        gRecordVS->mRecordVSSTable[24].mVisible = 1;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSWaitReturnButton(void) {
    int selectReturnShownNoRequest;
    selectReturnShownNoRequest = IsSelectReturnShownNoRequest();
    if (selectReturnShownNoRequest != 0) {
        RequestRecordVSBrowse();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSBrowse(void) {
    s32 downRectIndex;
    s32 pressedRectIndex;
    InputSlotIndex inputSlotIndex;
    BOOL pressedFlag;
    BOOL releasedFlag;
    u16 pressedBits;
    InputSlotAtHasPair *touchSlot;
    InputSlot *keySlot;
    s16 rowIndex;
    downRectIndex = -1;
    pressedRectIndex = -1;
    inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    AdvanceRecordVSOffsetTimers();
    AdvanceRecordVSIndexChange();
    pressedFlag = TRUE;
    releasedFlag = FALSE;
    touchSlot = &gInputHasPairs[inputSlotIndex];
    pressedBits = gInputHasPairs[inputSlotIndex].mHasPair;
    if (pressedBits == 0 && gInputNoPairCounts[inputSlotIndex].mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        releasedFlag = TRUE;
    }
    if (releasedFlag == FALSE && pressedBits == 0) {
        pressedFlag = FALSE;
    }
    if (pressedFlag != FALSE) {
        downRectIndex = RectTableFindContaining(gRecordVS->mRecordVSSBnbl, gInputPairXs[inputSlotIndex].mPairX,
                                                gInputPairYs[inputSlotIndex].mPairY);
    }
    pressedFlag = FALSE;
    releasedFlag = FALSE;
    pressedBits = touchSlot->mHasPair;
    if (pressedBits == 0 && gInputNoPairCounts[inputSlotIndex].mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        releasedFlag = TRUE;
    }
    if (releasedFlag == FALSE && gInputPrevHasPairs[inputSlotIndex].mPrevHasPair == 0 && pressedBits != 0) {
        pressedFlag = TRUE;
    }
    if (pressedFlag != FALSE) {
        pressedRectIndex = RectTableFindContaining(gRecordVS->mRecordVSSBnbl, gInputPairXs[inputSlotIndex].mPairX,
                                                   gInputPairYs[inputSlotIndex].mPairY);
    }
    if (downRectIndex != 10) {
        gRecordVS->mPageDecrementRepeat = FALSE;
    }
    if (downRectIndex != 11) {
        gRecordVS->mPageIncrementRepeat = FALSE;
    }
    keySlot = &gInputSlots[inputSlotIndex];
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_B) == 0) {
        pressedFlag = FALSE;
        releasedFlag = FALSE;
        pressedBits = touchSlot->mHasPair;
        if (pressedBits == 0 && gInputNoPairCounts[inputSlotIndex].mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
            releasedFlag = TRUE;
        }
        if (releasedFlag == FALSE && gInputPrevHasPairs[inputSlotIndex].mPrevHasPair == 0 && pressedBits != 0) {
            pressedFlag = TRUE;
        }
        if (pressedFlag == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputPairXs[inputSlotIndex].mPairX,
                                                            gInputPairYs[inputSlotIndex].mPairY) == FALSE) {
            goto handlePageButtons;
        }
    }
    if (IsRecordVSIndexChangeRunning() != 0) {
        return;
    }
    RequestRecordVSSubSlideOut();
    if (GetRecordPrevScene() == 12) {
        gRecordVS->mNextScreen = RECORD_SCREEN_OUTSIDE;
        RequestSelectReturnPressWithSound(1);
        return;
    }
    gRecordVS->mNextScreen = RECORD_SCREEN_TOP_MENU;
    RequestSelectReturnPressWithSound(0);
    return;
handlePageButtons:
    if ((downRectIndex == 10 && gRecordVS->mPageDecrementRepeat != FALSE) ||
        (pressedRectIndex == 10 && gRecordVS->mPageDecrementRepeat == FALSE) ||
        (u16) (gInputSlots[inputSlotIndex].mBits & PAD_KEY_LEFT) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[20].mVisible == 0) {
            return;
        }
        gRecordVS->mPageDecrement = RECORD_VS_PAGE_DECREMENT;
        gRecordVS->mOffsetTimers[0] = RECORD_PAGE_ARROW_FRAMES;
        gRecordVS->mPageDecrementRepeat = TRUE;
        RequestRecordVSPageSlideOut();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if ((downRectIndex == 11 && gRecordVS->mPageIncrementRepeat != FALSE) ||
        (pressedRectIndex == 11 && gRecordVS->mPageIncrementRepeat == FALSE) ||
        (u16) (gInputSlots[inputSlotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[21].mVisible == 0) {
            return;
        }
        gRecordVS->mPageDecrement = RECORD_VS_PAGE_INCREMENT;
        gRecordVS->mOffsetTimers[1] = RECORD_PAGE_ARROW_FRAMES;
        gRecordVS->mPageIncrementRepeat = TRUE;
        RequestRecordVSPageSlideOut();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if ((u32) (pressedRectIndex - 5) <= 4) {
        rowIndex = gRecordVSRectRowIndices[pressedRectIndex];
        if (IsRecordVSRowFilled(rowIndex) == 0) {
            return;
        }
        gRecordVS->mIndex = rowIndex;
        ToggleRecordVSRowFlag(rowIndex);
        return;
    }
    if ((u32) pressedRectIndex <= 4) {
        rowIndex = gRecordVSRectRowIndices[pressedRectIndex];
        if (rowIndex == gRecordVS->mIndex) {
            ToggleRecordVSRowFlag(rowIndex);
            return;
        }
        if (IsRecordVSRowFilled(rowIndex) == 0) {
            return;
        }
        gRecordVS->mIndex = rowIndex;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (pressedRectIndex == 12 || (u16) (keySlot->mPressedBits & PAD_KEY_X) != 0) {
        RequestRecordVSPressButton();
        gRecordVS->mNextScreen = RECORD_SCREEN_VS_ERASE;
        return;
    }
    if ((u16) (keySlot->mPressedBits & PAD_KEY_A) != 0) {
        ToggleRecordVSRowFlag(gRecordVS->mIndex);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        DecrementRecordVSIndex();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        IncrementRecordVSIndex();
    }
}

void AdvanceRecordVSPageSlideOut(void) {
    s32 rowIndex;
    u16 transientBase;
    u16 subBase;
    s32 objectRowIndex;
    u16 mainBase;
    s32 labelIndex;
    s16 endOffset;
    s16 offset;
    endOffset = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mPageDecrement) {
        case RECORD_VS_PAGE_INCREMENT:
            endOffset = -256;
            break;
        case RECORD_VS_PAGE_DECREMENT:
            endOffset = 0x100;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    mainBase = gRecordVS->mRecordVSMBncl->mCount;
    transientBase = gRecordVS->mRecordVSMTransientBncl->mCount;
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    offset = InterpolateS16(1, 0, endOffset, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    gRecordVS->mBg0OffsetX = offset;
    gRecordVS->mBg1OffsetX = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[rowIndex][labelIndex]].mOffsetX = offset;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetX = offset;
    for (labelIndex = 0; labelIndex < 12; labelIndex++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[labelIndex]].mOffsetX =
            offset;
    }
    for (objectRowIndex = 0; objectRowIndex < 5; objectRowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[objectRowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSPageSlideInAndChangePage();
    }
}

void AdvanceRecordVSPageSlideIn(void) {
    s32 rowIndex;
    u16 transientBase;
    u16 subBase;
    s32 objectRowIndex;
    u16 mainBase;
    s32 labelIndex;
    s16 startOffset;
    s16 offset;
    startOffset = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mPageDecrement) {
        case RECORD_VS_PAGE_INCREMENT:
            startOffset = 0x100;
            break;
        case RECORD_VS_PAGE_DECREMENT:
            startOffset = -256;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    mainBase = gRecordVS->mRecordVSMBncl->mCount;
    transientBase = gRecordVS->mRecordVSMTransientBncl->mCount;
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    offset = InterpolateS16(1, startOffset, 0, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    gRecordVS->mBg0OffsetX = offset;
    gRecordVS->mBg1OffsetX = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[rowIndex][labelIndex]].mOffsetX = offset;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetX = offset;
    for (labelIndex = 0; labelIndex < 12; labelIndex++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[labelIndex]].mOffsetX =
            offset;
    }
    for (objectRowIndex = 0; objectRowIndex < 5; objectRowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[objectRowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[objectRowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSBrowse();
    }
}

void AdvanceRecordVSSubSlideOut(void) {
    s16 offset;
    s32 rowIndex;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, 0, 0x100, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[rowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSMainSlideOut();
    }
    if (gRecordVS->mStateFrames == RECORD_VS_SUB_SLIDE_OUT_HIDE_STEP) {
        gRecordVS->mRecordVSSTable[24].mVisible = 0;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVSMainSlideOut(void) {
    u16 transientBase;
    u16 mainBase;
    s32 rowIndex;
    s32 labelIndex;
    s16 offset;
    if (GetRecordNextScene() == -1 && gRecordVS->mNextScreen == RECORD_SCREEN_OUTSIDE) {
        SetRecordNextScene(12);
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, 0, -192, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    gRecordVS->mBg0OffsetY = offset;
    gRecordVS->mBg1OffsetY = offset;
    mainBase = gRecordVS->mRecordVSMBncl->mCount;
    gRecordVS->mRecordVSMTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetY = offset;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[rowIndex][labelIndex]].mOffsetY = offset;
        }
    }
    transientBase = gRecordVS->mRecordVSMTransientBncl->mCount;
    gRecordVS->mRecordVSMTransientTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetY = offset;
    for (labelIndex = 0; labelIndex < 12; labelIndex++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[labelIndex]].mOffsetY =
            offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS && gRecordVS->mNextScreen != RECORD_SCREEN_OUTSIDE) {
        RequestRecordScreen(gRecordVS->mNextScreen);
    }
}

void AdvanceRecordVSPressButton(void) {
    s16 offset;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = GetSelectedPressOffset(gRecordVS->mStateFrames);
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSSubSlideOutRequestScreen();
    }
}

void AdvanceRecordVSSubSlideOutRequestScreen(void) {
    s16 offset;
    s32 rowIndex;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, 0, 0x100, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[rowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordScreen(gRecordVS->mNextScreen);
    }
    if (gRecordVS->mStateFrames == RECORD_VS_SUB_SLIDE_OUT_HIDE_STEP) {
        gRecordVS->mRecordVSSTable[24].mVisible = 0;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVSSubSlideIn(void) {
    s16 offset;
    s32 rowIndex;
    u16 subBase;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = InterpolateS16(1, 0x100, 0, gRecordVS->mStateFrames, RECORD_SLIDE_STEPS);
    subBase = gRecordVS->mRecordVSSBncl->mCount;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[rowIndex]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[rowIndex]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= RECORD_SLIDE_STEPS) {
        RequestRecordVSBrowse();
    }
    if (gRecordVS->mStateFrames == RECORD_VS_SUB_RESLIDE_SWAP_STEP) {
        gRecordVS->mRecordVSSTable[24].mVisible = 1;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVS(void) {
    RecordVS *recordVS;
    gRecordVS->mState = gRecordVS->mNextState;
    switch (gRecordVS->mState) {
        case RECORD_VS_STATE_WAIT_FADE:
            AdvanceRecordVSWaitFade();
            break;
        case RECORD_VS_STATE_SLIDE_IN_MAIN:
            AdvanceRecordVSSlideInMain();
            break;
        case RECORD_VS_STATE_SLIDE_IN_SUB:
            AdvanceRecordVSSlideInSub();
            break;
        case RECORD_VS_STATE_WAIT_RETURN_BUTTON:
            AdvanceRecordVSWaitReturnButton();
            break;
        case RECORD_VS_STATE_BROWSE:
            AdvanceRecordVSBrowse();
            break;
        case RECORD_VS_STATE_PAGE_SLIDE_OUT:
            AdvanceRecordVSPageSlideOut();
            break;
        case RECORD_VS_STATE_PAGE_SLIDE_IN:
            AdvanceRecordVSPageSlideIn();
            break;
        case RECORD_VS_STATE_SUB_SLIDE_OUT:
            AdvanceRecordVSSubSlideOut();
            break;
        case RECORD_VS_STATE_MAIN_SLIDE_OUT:
            AdvanceRecordVSMainSlideOut();
            break;
        case RECORD_VS_STATE_PRESS_BUTTON:
            AdvanceRecordVSPressButton();
            break;
        case RECORD_VS_STATE_SUB_SLIDE_OUT_REQUEST_SCREEN:
            AdvanceRecordVSSubSlideOutRequestScreen();
            break;
        case RECORD_VS_STATE_SUB_SLIDE_IN:
            AdvanceRecordVSSubSlideIn();
            break;
    }
    AdvanceRecordVSRowObjects();
    recordVS = gRecordVS;
    switch (recordVS->mShowsFriendKey) {
        case FALSE:
            DrawLayoutTable(recordVS->mRecordVSMBncl, recordVS->mRecordVSMNcer, recordVS->mRecordVSMBnll,
                            GetRecordMainOam(), recordVS->mRecordVSMTable);
            break;
        case TRUE:
            DrawLayoutTable(recordVS->mRecordVSMTransientBncl, recordVS->mRecordVSMNcer,
                            recordVS->mRecordVSMTransientBnll, GetRecordMainOam(), recordVS->mRecordVSMTransientTable);
            break;
    }
    recordVS = gRecordVS;
    DrawLayoutTable(recordVS->mRecordVSSBncl, recordVS->mRecordVSSNcer, recordVS->mRecordVSSBnll, GetRecordSubOam(),
                    recordVS->mRecordVSSTable);
}

#pragma thumb off

#pragma thumb on

void WriteRecordVSBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordVS->mBg0OffsetX & 0x1ff) | ((-gRecordVS->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVS->mBg1OffsetX & 0x1ff) | ((-gRecordVS->mBg1OffsetY << 16) & 0x1ff0000);
    AdvanceRecordSceneRegistersTimer();
}

#pragma thumb off

#pragma thumb on

void WriteRecordVSRegisters(void) {
    u32 planeBits;
    if (GetRecordPrevScene() == 12) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1b00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1600;
    } else {
        planeBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((planeBits | 0x13) << 8);
    }
}

void RegisterRecordVSCallbacks(void) {
    RecordScreenCallbacks callbacks = {InitRecordVS, ReleaseRecordVS, AdvanceRecordVS, WriteRecordVSBgOffsets,
                                       WriteRecordVSRegisters};
    SetRecordScreenCallbacks(&callbacks);
}
// Clears four of the five screen callbacks; the register writer is left (a new set is registered next, or the scene is
// freed).

void ClearRecordScreenCallbacksKeepRegisters(void) {
    gRecordScene->mScreenCallbacks.mInit = NULL;
    gRecordScene->mScreenCallbacks.mRelease = NULL;
    gRecordScene->mScreenCallbacks.mAdvance = NULL;
    gRecordScene->mScreenCallbacks.mWriteOffsets = NULL;
}

#pragma thumb off

#pragma thumb on

void LoadRecordSceneData(void) {
    void *file;
    LoadedPartPointer loadedPart;
    loadedPart.mNcgr = NULL;
    file = FindSceneFile(gRecordTopMenuMBNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTopMenuMBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTopMenuMNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordTopMenuMNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTopMenuMNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordTopMenuMONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTopMenuSNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTopMenuSNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordTopMenuSONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordGpxMNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordGpxMNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordGpxMONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordGpxMBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordGpxMBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordGpxMNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordGpxSNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordGpxSNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordGpxSONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordGpxSBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordGpxSBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordGpxSNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordTrophyONcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTrophyONcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordTrophySONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTAttMNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTAttMNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordTAttMONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTAttMBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTAttMNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordTAttMScoreNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordTAttMBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTAttSNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTAttSNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordTAttSONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTAttSBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordTAttSBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordTAttSNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordVSMNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordVSMNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordVSMONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordVSMBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordVSMNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordVSM02NscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordVSMBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordVSSNcgrName);
    LoadNcgrData(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordVSSNcerName);
    LoadNcerData(&loadedPart.mNcer, file);
    file = FindSceneFile(gRecordVSSONclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    file = FindSceneFile(gRecordVSM03NscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordVSSBNcgrName);
    LoadNcgrData2(&loadedPart.mNcgr, file);
    file = FindSceneFile(gRecordVSSEraseNscrName);
    LoadNscrData(&loadedPart.mNscr, file);
    file = FindSceneFile(gRecordVSSBNclrName);
    LoadNclrData(&loadedPart.mNclr, file);
    LoadKartIconData();
    LoadCupMarkData();
}

#pragma thumb off

#pragma thumb on

void InitRecordSceneObject(void *heap, s16 previousScene) {
    SceneTextInitParams sceneTextInitParams;
    gRecordScene = HeapAlloc(heap, sizeof(*gRecordScene));
    gRecordScene->mHeap = heap;
    gRecordScene->mPageIndex = 0;
    gRecordScene->mIndex = 0;
    CreateSceneDisplaySettings(heap);
    InitLinkLevelIcons(heap, GetRecordMainOam());
    sceneTextInitParams.mUseTxtSystem = TRUE;
    sceneTextInitParams.mTxtSystemFont = GetFontByIndex(1);
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 1;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = FALSE;
    sceneTextInitParams.mUseSelectReturn = TRUE;
    sceneTextInitParams.mUseBackScreen = TRUE;
    sceneTextInitParams.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &sceneTextInitParams);
    CreateRecordList(gRecordScene->mHeap);
    BuildRecordList();
    gRecordScene->mStateHeap = CreateExpHeapFromMaxFree(gRecordScene->mHeap);
    LoadRecordSceneData();
    ClearRecordScreenCallbacksKeepRegisters();
    gRecordScene->mPrevScene = previousScene;
    gRecordScene->mNextScene = -1;
    gRecordScene->mNextScreen = RECORD_SCREEN_NONE;
    gRecordScene->mRegistersTimer = RECORD_REGISTERS_DELAY_FRAMES;
    if (gRecordScene->mPrevScene == SCENE_WIFI_MENU) {
        gRecordScene->mPrevScreen = RECORD_SCREEN_OUTSIDE;
        gRecordScene->mScreen = RECORD_SCREEN_VS;
        RegisterRecordVSCallbacks();
    } else {
        gRecordScene->mPrevScreen = RECORD_SCREEN_START;
        gRecordScene->mScreen = RECORD_SCREEN_TOP_MENU;
        RegisterRecordTopMenuCallbacks();
    }
    gRecordScene->mScreenCallbacks.mInit(gRecordScene->mStateHeap);
}

#pragma thumb off

#pragma thumb on

void ReleaseRecordSceneObject(void) {
    ClearRecordListPointer();
    gRecordScene->mScreenCallbacks.mRelease();
    ClearRecordScreenCallbacksKeepRegisters();
    ClearLinkLevelIconsPointer();
    ReleaseSceneText();
    *&gRecordScene = NULL;
}

#pragma thumb off

#pragma thumb on

// Switches to the requested screen when there is one, then runs the running screen's step.
void AdvanceRecordScene(void) {
    if (gRecordScene->mNextScreen != RECORD_SCREEN_NONE) {
        gRecordScene->mScreenCallbacks.mRelease();
        ClearRecordScreenCallbacksKeepRegisters();
        HeapDestroy(gRecordScene->mStateHeap);
        gRecordScene->mStateHeap = CreateExpHeapFromMaxFree(gRecordScene->mHeap);
        switch (gRecordScene->mNextScreen) {
            case RECORD_SCREEN_TOP_MENU:
                if (gRecordScene->mScreen == RECORD_SCREEN_VS) {
                    BuildRecordList();
                }
                RegisterRecordTopMenuCallbacks();
                break;
            case RECORD_SCREEN_GPX:
                RegisterRecordGpxCallbacks();
                break;
            case RECORD_SCREEN_TIME_ATTACK:
                RegisterRecordTAttCallbacks();
                break;
            case RECORD_SCREEN_VS:
                RegisterRecordVSCallbacks();
                break;
            case RECORD_SCREEN_VS_ERASE:
                RegisterRecordVSEraseCallbacks();
                break;
        }
        gRecordScene->mPrevScreen = gRecordScene->mScreen;
        gRecordScene->mScreen = gRecordScene->mNextScreen;
        gRecordScene->mNextScreen = RECORD_SCREEN_NONE;
        gRecordScene->mRegistersTimer = RECORD_REGISTERS_DELAY_FRAMES;
        gRecordScene->mScreenCallbacks.mInit(gRecordScene->mStateHeap);
    }
    gRecordScene->mScreenCallbacks.mAdvance();
    AdvanceSceneText();
    AdvanceLinkLevelIcons();
}

#pragma thumb off

#pragma thumb on

void WriteRecordSceneRegisters(void) {
    gRecordScene->mScreenCallbacks.mWriteOffsets();
    WriteSceneTextRegisters();
}

#pragma thumb off

#pragma thumb on

void SetRecordScreenCallbacks(const RecordScreenCallbacks *callbacks) {
    gRecordScene->mScreenCallbacks = *callbacks;
}

#pragma thumb off

#pragma thumb on
void RequestRecordScreen(s32 screen) {
    u32 screenCopy = screen;
    u32 unused;
    gRecordScene->mNextScreen = screenCopy;
}
#pragma thumb off

#pragma thumb on

u32 GetRecordPrevScreen(void) {
    return (gRecordScene->mPrevScreen);
}

u32 GetRecordPrevScene(void) {
    return (gRecordScene->mPrevScene);
}

u32 GetRecordNextScene(void) {
    return (gRecordScene->mNextScene);
}

void SetRecordNextScene(u32 scene) {
    gRecordScene->mNextScene = (u16) scene;
}

#pragma thumb off

#pragma thumb on

// Counts the registers timer down and calls the screen's register writer when it reaches 0.
void AdvanceRecordSceneRegistersTimer(void) {
    if (gRecordScene->mRegistersTimer > 0) {
        gRecordScene->mRegistersTimer = gRecordScene->mRegistersTimer - 1;
        if (gRecordScene->mRegistersTimer == 0) {
            gRecordScene->mScreenCallbacks.mWriteRegisters();
        }
    }
}

#pragma thumb off

#pragma thumb on
u32 GetRecordScenePageIndex(void) {
    return gRecordScene->mPageIndex;
}
#pragma thumb off

#pragma thumb on
u32 GetRecordSceneIndex(void) {
    return gRecordScene->mIndex;
}
#pragma thumb off

#pragma thumb on
void SetRecordScenePageIndex(u32 pageIndex) {
    u32 pageIndexCopy = pageIndex;
    u32 unused;
    gRecordScene->mPageIndex = (u16) pageIndexCopy;
}
#pragma thumb off

#pragma thumb on
void SetRecordSceneIndex(u32 index) {
    u32 indexCopy = index;
    u32 unused;
    gRecordScene->mIndex = (u16) indexCopy;
}
#pragma thumb off
