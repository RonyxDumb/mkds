#include "01/Menu/time_attack_top_menu.h"

#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/second_menu_scene.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Menu/menu_screen_switch.h"
#include "player.h"
#include "01/unk_021a8000.h"
#include "code_0212df7c.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

char *gTimeAttackTopMenuSNcgrName = "ta/TimeAttack_top_menu_s.nce.ncgr";
char *gTimeAttackTopMenuSNcerName = "ta/TimeAttack_top_menu_s.nce.ncer";
const u16 gTimeAttackTopMenuPaletteCellIndices[3] = {9, 0xa, 0xb};
char *gTimeAttackTopMenuMNscrName = "ta/TimeAttack_top_menu_m.nscr";
char *gTimeAttackTopMenuSBnblName = "ta/TimeAttack_top_menu_s.bnbl";
const u16 gTimeAttackTopMenuOffsetIndices[3] = {3, 4, 5};
char *gTimeAttackTopMenuMBNcgrName = "ta/TimeAttack_top_menu_m_b.ncgr";
char *gTimeAttackTopMenuMBNclrName = "ta/TimeAttack_top_menu_m_b.nclr";
const u16 gTimeAttackTopMenuVisibleTableIndices[3] = {6, 7, 8};
char *gTimeAttackTopMenuSONclrName = "ta/TimeAttack_top_menu_s_o.nclr";
char *gTimeAttackTopMenuSBnclName = "ta/TimeAttack_top_menu_s.bncl";
const u16 gTimeAttackTopMenuXluCellIndices[3] = {0, 1, 2};
TimeAttackTopMenu *gTimeAttackTopMenu;

void LoadTimeAttackTopMenuData(void) {
    Ncgr *sNcgr = NULL;
    NNSG2dCellDataBank *sNcer = NULL;
    Nclr *soNclr = NULL;
    Ncgr *mbNcgr = NULL;
    Nclr *mbNclr = NULL;
    Nscr *mNscr = NULL;

    LoadNcgrData(&mbNcgr, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LoadNclrData(&mbNclr, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LoadNscrData(&mNscr, FindSceneFile(gTimeAttackTopMenuMNscrName));
    LoadNcgrData2(&sNcgr, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LoadNcerData(&sNcer, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LoadNclrData(&soNclr, FindSceneFile(gTimeAttackTopMenuSONclrName));
}

void LocateAndQueueTimeAttackTopMenu(void) {
    Ncgr *sNcgr = NULL;
    Nclr *soNclr = NULL;
    Ncgr *mbNcgr = NULL;
    Nclr *mbNclr = NULL;
    Nscr *mNscr = NULL;

    LocateNcgr(&mbNcgr, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LocateNclr(&mbNclr, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LocateNscr(&mNscr, FindSceneFile(gTimeAttackTopMenuMNscrName));
    gTimeAttackTopMenu->mSecondScreenMapBuffer = HeapAlloc(gTimeAttackTopMenu->mHeap, SECOND_SCREEN_MAP_BYTES);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBncl = FindSceneFile(gTimeAttackTopMenuSBnclName);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl = FindSceneFile(gTimeAttackTopMenuSBnblName);
    LocateNcgr2(&sNcgr, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LocateNcer(&gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LocateNclr(&soNclr, FindSceneFile(gTimeAttackTopMenuSONclrName));
    NNS_GfdRegisterNewVramTransferTask(4, 0, mbNcgr->mData, mbNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, mbNclr->mData, 0x20);
    NNS_GfdRegisterNewVramTransferTask(8, 0, &mNscr->mData, mNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gTimeAttackTopMenu->mSecondScreenMapBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, sNcgr->mData, sNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, soNclr->mData, soNclr->mDataSize);
}

void RequestTimeAttackTopMenuSlideIn(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_SLIDE_IN;
    gTimeAttackTopMenu->mStateFrames = 0;
    gTimeAttackTopMenu->mBg0Offset = -192;
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuSettle.
void RequestTimeAttackTopMenuSettle(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_SETTLE;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void RequestTimeAttackTopMenuWaitSelectReturn(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_WAIT_SELECT_RETURN;
    gTimeAttackTopMenu->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuInput.
void RequestTimeAttackTopMenuInput(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_INPUT;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void RequestTimeAttackTopMenuPress(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_PRESS;
    gTimeAttackTopMenu->mStateFrames = 0;
    switch (gTimeAttackTopMenu->mIndex) {
        case TIME_ATTACK_TOP_ROW_SEND_GHOST:
        case TIME_ATTACK_TOP_ROW_RECEIVE_GHOST:
            RequestSelectReturnSlideOut();
            break;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuSlideOut.
void RequestTimeAttackTopMenuSlideOut(void) {
    gTimeAttackTopMenu->mNextState = TIME_ATTACK_TOP_STATE_SLIDE_OUT;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void ShowTimeAttackTopMenuHighlight(s32 index) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mVisible = 1;
    SetCellPaletteIndex(gTimeAttackTopMenuPaletteCellIndices[index], 0xe, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                        gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void HideTimeAttackTopMenuHighlight(s32 index) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mVisible = 0;
    SetCellPaletteIndex(gTimeAttackTopMenuPaletteCellIndices[index], 0xf, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                        gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void InitTimeAttackTopMenu(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    s32 index;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackTopMenu = HeapAlloc(heap, sizeof(TimeAttackTopMenu));
    gTimeAttackTopMenu->mHeap = heap;
    gTimeAttackTopMenu->mState = TIME_ATTACK_TOP_STATE_SLIDE_IN;
    gTimeAttackTopMenu->mMainOamList = mainOam;
    gTimeAttackTopMenu->mSubOamList = subOam;
    gTimeAttackTopMenu->mResult = TIME_ATTACK_TOP_RESULT_NONE;
    RequestTimeAttackTopMenuSlideIn();
    if (GetPreviousMenuScreenNumber() == 0x1f) {
        if (gMenuShared->mGhostSceneInitialCallbacksIndex == 0) {
            gTimeAttackTopMenu->mIndex = TIME_ATTACK_TOP_ROW_SEND_GHOST;
        } else {
            gTimeAttackTopMenu->mIndex = TIME_ATTACK_TOP_ROW_RECEIVE_GHOST;
        }
    } else {
        gTimeAttackTopMenu->mIndex = TIME_ATTACK_TOP_ROW_TIME_TRIALS;
    }
    LocateAndQueueTimeAttackTopMenu();
    for (index = 0; index < 3; index++) {
        SetCellOamModeXlu(gTimeAttackTopMenuXluCellIndices[index], 1, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                          gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
    }
    ResetOamLists(gTimeAttackTopMenu->mMainOamList, gTimeAttackTopMenu->mSubOamList);
    InitLayoutTable(gTimeAttackTopMenu->mHeap, gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, NULL,
                    &gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    for (index = 0; index < 3; index++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[index]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[index]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mOffsetX = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[index]].mOffsetX = 0xe0;
        HideTimeAttackTopMenuHighlight(index);
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = 0xe0;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = 0xe0;
    ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
    FrmHeapShrinkInParent(gTimeAttackTopMenu->mHeap);
}

void ReleaseTimeAttackTopMenu(void) {
    HeapDestroy(gTimeAttackTopMenu->mHeap);
    gTimeAttackTopMenu = NULL;
}

void AdvanceTimeAttackTopMenuSlideIn(void) {
    s16 offsetX;
    s32 index;

    gTimeAttackTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, -192, 0, gTimeAttackTopMenu->mStateFrames, 10);
    for (index = 0; index < 3; index++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[index]].mOffsetX = offsetX;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = offsetX;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = offsetX;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuSettle();
    }
}

void AdvanceTimeAttackTopMenuSettle(void) {
    s16 selectedPressOffset;
    s32 index;

    gTimeAttackTopMenu->mStateFrames++;
    selectedPressOffset = GetSelectedPressOffset(gTimeAttackTopMenu->mStateFrames);
    for (index = 0; index < 3; index++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[index]].mOffsetX =
            selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[index]].mOffsetX =
            selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mOffsetX =
            selectedPressOffset;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[index]].mOffsetX =
            selectedPressOffset;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = selectedPressOffset;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuWaitSelectReturn();
    }
}

void AdvanceTimeAttackTopMenuWaitSelectReturn(void) {
    if (IsSelectReturnShownNoRequest() != 0) {
        RequestTimeAttackTopMenuInput();
    }
}

void AdvanceTimeAttackTopMenuInput(void) {
    BOOL touchStarted = FALSE;
    u32 tappedRectIndex = -1;
    s32 newIndex = 3;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL flag1 = FALSE;
    InputSlot *inputSlot;
    s32 pressedBits;
    BOOL flag4;
    s32 flag3;

    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        flag1 = TRUE;
    }
    if (flag1 == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchStarted = TRUE;
    }
    if (touchStarted != FALSE) {
        tappedRectIndex =
            RectTableFindContaining(gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                    gInputSlots[slotIndex].mPair.mPairY);
    }
    inputSlot = &gInputSlots[slotIndex];
    pressedBits = inputSlot->mPressedBits & PAD_KEY_B;
    if ((u16) pressedBits == 0) {
        flag3 = flag4 = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE || IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                    gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    RequestTimeAttackTopMenuSlideOut();
    gTimeAttackTopMenu->mResult = TIME_ATTACK_TOP_RESULT_RETURN;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    pressedBits = inputSlot->mPressedBits & PAD_KEY_A;
    if ((u16) pressedBits != 0 || tappedRectIndex <= 2) {
        if ((u16) pressedBits == 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            switch (tappedRectIndex) {
                case TIME_ATTACK_TOP_ROW_TIME_TRIALS:
                    newIndex = TIME_ATTACK_TOP_ROW_TIME_TRIALS;
                    break;
                case TIME_ATTACK_TOP_ROW_SEND_GHOST:
                    newIndex = TIME_ATTACK_TOP_ROW_SEND_GHOST;
                    break;
                case TIME_ATTACK_TOP_ROW_RECEIVE_GHOST:
                    newIndex = TIME_ATTACK_TOP_ROW_RECEIVE_GHOST;
                    break;
            }
            if (gTimeAttackTopMenu->mIndex != newIndex) {
                gTimeAttackTopMenu->mIndex = newIndex;
                ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            }
        } else {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
        }
        switch (gTimeAttackTopMenu->mIndex) {
            case TIME_ATTACK_TOP_ROW_TIME_TRIALS:
                gTimeAttackTopMenu->mResult = TIME_ATTACK_TOP_RESULT_TIME_TRIALS;
                break;
            case TIME_ATTACK_TOP_ROW_SEND_GHOST:
                gTimeAttackTopMenu->mResult = TIME_ATTACK_TOP_RESULT_SEND_GHOST;
                break;
            case TIME_ATTACK_TOP_ROW_RECEIVE_GHOST:
                gTimeAttackTopMenu->mResult = TIME_ATTACK_TOP_RESULT_RECEIVE_GHOST;
                break;
        }
        RequestTimeAttackTopMenuPress();
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex--;
            if (gTimeAttackTopMenu->mIndex < 0) {
                gTimeAttackTopMenu->mIndex = TIME_ATTACK_TOP_ROW_RECEIVE_GHOST;
            }
            ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            HideTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex++;
            if (gTimeAttackTopMenu->mIndex >= 3) {
                gTimeAttackTopMenu->mIndex = TIME_ATTACK_TOP_ROW_TIME_TRIALS;
            }
            ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceTimeAttackTopMenuPress(void) {
    s16 selectedPressOffset;

    gTimeAttackTopMenu->mStateFrames++;
    selectedPressOffset = GetSelectedPressOffset(gTimeAttackTopMenu->mStateFrames);
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[gTimeAttackTopMenu->mIndex]].mOffsetX =
        selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[gTimeAttackTopMenu->mIndex]]
        .mOffsetX = selectedPressOffset;
    switch (gTimeAttackTopMenu->mIndex) {
        case TIME_ATTACK_TOP_ROW_SEND_GHOST:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = selectedPressOffset;
            break;
        case TIME_ATTACK_TOP_ROW_RECEIVE_GHOST:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = selectedPressOffset;
            break;
    }
    if (gTimeAttackTopMenu->mStateFrames == 5) {
        ShowTimeAttackTopMenuHighlight(gTimeAttackTopMenu->mIndex);
    }
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuSlideOut();
    }
}

void AdvanceTimeAttackTopMenuSlideOut(void) {
    s16 offsetX;
    s32 index;

    gTimeAttackTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, 0, -192, gTimeAttackTopMenu->mStateFrames, 10);
    for (index = 0; index < 3; index++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuOffsetIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuXluCellIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuVisibleTableIndices[index]].mOffsetX = offsetX;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[gTimeAttackTopMenuPaletteCellIndices[index]].mOffsetX = offsetX;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mOffsetX = offsetX;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mOffsetX = offsetX;
}

s32 AdvanceTimeAttackTopMenu(void) {
    gTimeAttackTopMenu->mState = gTimeAttackTopMenu->mNextState;
    switch (gTimeAttackTopMenu->mState) {
        case TIME_ATTACK_TOP_STATE_SLIDE_IN:
            AdvanceTimeAttackTopMenuSlideIn();
            break;
        case TIME_ATTACK_TOP_STATE_SETTLE:
            AdvanceTimeAttackTopMenuSettle();
            break;
        case TIME_ATTACK_TOP_STATE_WAIT_SELECT_RETURN:
            AdvanceTimeAttackTopMenuWaitSelectReturn();
            break;
        case TIME_ATTACK_TOP_STATE_INPUT:
            AdvanceTimeAttackTopMenuInput();
            break;
        case TIME_ATTACK_TOP_STATE_PRESS:
            AdvanceTimeAttackTopMenuPress();
            break;
        case TIME_ATTACK_TOP_STATE_SLIDE_OUT:
            AdvanceTimeAttackTopMenuSlideOut();
            break;
    }
    DrawLayoutTable(gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, NULL,
                    gTimeAttackTopMenu->mSubOamList, gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    if (gTimeAttackTopMenu->mState == TIME_ATTACK_TOP_STATE_SLIDE_OUT && gTimeAttackTopMenu->mStateFrames >= 10) {
        return gTimeAttackTopMenu->mResult;
    }
    return 0;
}

void WriteTimeAttackTopMenuBg0Offset(void) {
    reg_G2_BG0OFS = (-gTimeAttackTopMenu->mBg0Offset << 16) & 0x1ff0000;
}
