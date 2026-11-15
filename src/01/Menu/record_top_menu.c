#include "01/Menu/record_top_menu.h"
#include "Main/Menu/record_scene.h"

#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Menu/record_vs.h"
#include "Main/Menu/record_list.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/data_02175628.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Menu/select_return.h"
#include "01/code_0219c000.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/oam.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/code_0219a000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/MapObjects/data_0217a000.h"
#include "player.h"
#include "code_0212df7c.h"
#include "01/Menu/select_ghost.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u16 gRecordTopMenuGradeSTableIndices[3] = {2, 3, 4};
const u16 gRecordTopMenuRowCellIndices[3] = {9, 0xa, 0xb};
const u16 gRecordTopMenuLabelWidths[3][3] = {{0x70, 0x70, 0x70}, {0x20, 0x20, 0x20}, {0x20, 0x20, 0x20}};
const s32 gRecordTopMenuTouchRowIndices[3] = {0, 1, 2};
const u16 gRecordTopMenuLabelHeights[3][3] = {{0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}};
const s32 gRecordTopMenuRowRecordScreens[3] = {RECORD_SCREEN_GPX, RECORD_SCREEN_TIME_ATTACK, RECORD_SCREEN_VS};
const u16 gRecordTopMenuRecordMessageIndices[3] = {6, 7, 8};
const u16 gRecordTopMenuOffsetSTableIndices[3] = {3, 4, 5};
const u16 gRecordTopMenuRowSTableIndices[3] = {6, 7, 8};
const u16 gRecordTopMenuXluCellIndices[3] = {0, 1, 2};
const u16 gRecordTopMenuLabelIndices[3][3] = {{1, 2, 3}, {4, 6, 8}, {5, 7, 9}};
RecordTopMenu *gRecordTopMenu;

void LocateAndQueueRecordTopMenu(void) {
    Ncgr *recordTopMenuMNcgr;
    Nclr *recordTopMenuMONclr;
    Ncgr *recordTopMenuSNcgr;
    Nclr *recordTopMenuSONclr;
    Ncgr *recordTopMenuMBNcgr;
    Nclr *recordTopMenuMBNclr;
    Nscr *recordTopMenuMNscr;
    u16 *paletteData;

    recordTopMenuMNcgr = NULL;
    recordTopMenuMONclr = NULL;
    recordTopMenuSNcgr = NULL;
    recordTopMenuSONclr = NULL;
    recordTopMenuMBNcgr = NULL;
    recordTopMenuMBNclr = NULL;
    recordTopMenuMNscr = NULL;
    LocateNcgr(&recordTopMenuMBNcgr, FindSceneFile(gRecordTopMenuMBNcgrName));
    LocateNclr(&recordTopMenuMBNclr, FindSceneFile(gRecordTopMenuMBNclrName));
    LocateNscr(&recordTopMenuMNscr, FindSceneFile(gRecordTopMenuMNscrName));
    gRecordTopMenu->mSecondScreenMapBuffer = HeapAlloc(gRecordTopMenu->mHeap, SECOND_SCREEN_MAP_BYTES);
    gRecordTopMenu->mRecordTopMenuMBncl = FindSceneFile(gRecordTopMenuMBnclName);
    gRecordTopMenu->mRecordTopMenuMBnll = FindSceneFile(gRecordTopMenuMBnllName);
    LocateNcgr2(&recordTopMenuMNcgr, FindSceneFile(gRecordTopMenuMNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuMNcer, FindSceneFile(gRecordTopMenuMNcerName));
    LocateNclr(&recordTopMenuMONclr, FindSceneFile(gRecordTopMenuMONclrName));
    gRecordTopMenu->mRecordTopMenuSBncl = FindSceneFile(gRecordTopMenuSBnclName);
    gRecordTopMenu->mRecordTopMenuSBnbl = FindSceneFile(gRecordTopMenuSBnblName);
    LocateNcgr2(&recordTopMenuSNcgr, FindSceneFile(gRecordTopMenuSNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuSNcer, FindSceneFile(gRecordTopMenuSNcerName));
    LocateNclr(&recordTopMenuSONclr, FindSceneFile(gRecordTopMenuSONclrName));
    paletteData = recordTopMenuMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(4, 0, recordTopMenuMBNcgr->mData, recordTopMenuMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, recordTopMenuMBNclr->mData, 0x60);
    NNS_GfdRegisterNewVramTransferTask(8, 0, recordTopMenuMNscr->mData, recordTopMenuMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gRecordTopMenu->mSecondScreenMapBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, recordTopMenuMNcgr->mData, recordTopMenuMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(14, 0, recordTopMenuMONclr->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(14, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, recordTopMenuSNcgr->mData, recordTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, recordTopMenuSONclr->mData, recordTopMenuSONclr->mDataSize);
}

void SetRecordTopMenuRowOn(s32 row) {
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[row]].mVisible = 1;
    SetCellPaletteIndex(gRecordTopMenuRowCellIndices[row], 14, gRecordTopMenu->mRecordTopMenuSNcer,
                        gRecordTopMenu->mRecordTopMenuSBncl);
}

void SetRecordTopMenuRowOff(s32 row) {
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[row]].mVisible = 0;
    SetCellPaletteIndex(gRecordTopMenuRowCellIndices[row], 15, gRecordTopMenu->mRecordTopMenuSNcer,
                        gRecordTopMenu->mRecordTopMenuSBncl);
}

void ResetRecordTopMenu(void) {
    s32 rowIndex;
    s32 labelIndex;
    const u16 *labelRow;
    s32 mainLayoutCount;

    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_FADE;
    gRecordTopMenu->mStateFrames = 0;
    gRecordTopMenu->mBg0Offset = ~0xbf;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = ~0xbf;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[rowIndex]].mOffsetY = ~0xbf;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0, labelRow = gRecordTopMenuLabelIndices[rowIndex]; labelIndex < 3; labelIndex++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = ~0xbf;
            labelRow++;
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = 0xe0;
        SetRecordTopMenuRowOff(rowIndex);
    }
}

// Requests state 1 for the next update.
void RequestRecordTopMenuSlideIn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_SLIDE_IN;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 2 for the next update.
void RequestRecordTopMenuRowsSettle(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SETTLE;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuWaitSelectReturn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_SELECT_RETURN;
    gRecordTopMenu->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

// Requests state 4 for the next update.
void RequestRecordTopMenuInput(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_INPUT;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuRowPress(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROW_PRESS;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 6 for the next update.
void RequestRecordTopMenuSlideOut(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_SLIDE_OUT;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 7 for the next update.
void RequestRecordTopMenuRowsSlideOut(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SLIDE_OUT;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuWaitMessageOpen(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_MESSAGE_OPEN;
    gRecordTopMenu->mStateFrames = 0;
    SetupTxtSystemSubText(GetBmgEntry(gRecordTopMenu->mUnk_20, 0x76));
}

void RequestRecordTopMenuMessageInput(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_MESSAGE_INPUT;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
}

void RequestRecordTopMenuWaitMessageClose(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_MESSAGE_CLOSE;
    gRecordTopMenu->mStateFrames = 0;
    RequestTxtSystemClose();
}

// Requests state 11 for the next update.
void RequestRecordTopMenuRowsSlideIn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SLIDE_IN;
    gRecordTopMenu->mStateFrames = 0;
}

void IncrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex++;
    if (gRecordTopMenu->mIndex >= 3) {
        gRecordTopMenu->mIndex = 0;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void DecrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex--;
    if (gRecordTopMenu->mIndex < 0) {
        gRecordTopMenu->mIndex = 2;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void RefreshRecordTopMenuGradeCells(void) {
    s32 best = 7;
    s32 cup;
    s32 engineClass;

    for (cup = 0; cup < 8; cup++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            if (IsGrandPrixRecordFilled(cup, engineClass)) {
                s32 grade = GetGrandPrixRecordGrade(cup, engineClass);
                if (best > grade) {
                    best = grade;
                }
            } else {
                best = 0;
            }
        }
    }
    for (cup = 0; cup < 3; cup++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[cup]].mVisible = 0;
    }
    if (best > 4) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[best - 5]].mVisible = 1;
    }
}

void InitRecordTopMenu(void *heap) {
    u32 scores[3][3] = {0};
    u16 buf[16];
    s32 remainingSize;
    u16 labelEntryIndex;
    u16 mainLayoutCount;
    s32 rowIndex;
    s32 labelIndex;
    BackupFirstBlock **firstBlock;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x8800;
    reg_G2S_DB_BG1CNT =
        (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0x1018;
    gRecordTopMenu = HeapAlloc(heap, sizeof(RecordTopMenu));
    gRecordTopMenu->mHeap = heap;
    gRecordTopMenu->mState = RECORD_TOP_MENU_STATE_WAIT_FADE;
    switch (GetRecordPrevScreen()) {
        case RECORD_SCREEN_GPX:
        case RECORD_SCREEN_START:
            gRecordTopMenu->mIndex = 0;
            break;
        case RECORD_SCREEN_TIME_ATTACK:
            gRecordTopMenu->mIndex = 1;
            break;
        case RECORD_SCREEN_VS:
            if (GetRecordCount()) {
                gRecordTopMenu->mIndex = 2;
            } else {
                gRecordTopMenu->mIndex = 0;
            }
            break;
    }
    LocateAndQueueRecordTopMenu();
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        SetCellOamModeXlu(gRecordTopMenuXluCellIndices[rowIndex], 1, gRecordTopMenu->mRecordTopMenuSNcer,
                          gRecordTopMenu->mRecordTopMenuSBncl);
    }
    ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMBnll,
                    &gRecordTopMenu->mRecordTopMenuMTable);
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuSBncl, NULL, &gRecordTopMenu->mRecordTopMenuSTable);
    gRecordTopMenu->mUnk_20 = FindFileInLoadedArchives("common.bmg");
    gRecordTopMenu->mRecordMessages = FindSceneFile("record.bmg");
    remainingSize = 0x8000;
    remainingSize -=
        InitLabelCanvas(heap, 0, gRecordTopMenu->mRecordTopMenuMBnll, 0xaa, 0xe, 0, gRecordTopMenu->mRecordTopMenuMNcer,
                        gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordTopMenu->mRecordTopMenuMBnll,
                                       GetBmgEntry(gRecordTopMenu->mRecordMessages, 9),
                                       gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    labelEntryIndex = 1;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            remainingSize -= InitLabelCanvas(
                heap, gRecordTopMenuLabelIndices[rowIndex][labelIndex], gRecordTopMenu->mRecordTopMenuMBnll,
                gRecordTopMenuLabelWidths[rowIndex][labelIndex], gRecordTopMenuLabelHeights[rowIndex][labelIndex],
                labelEntryIndex, gRecordTopMenu->mRecordTopMenuMNcer, gRecordTopMenu->mRecordTopMenuMBncl,
                gRecordTopMenu->mRecordTopMenuMTable, remainingSize);
            labelEntryIndex = mainLayoutCount + gRecordTopMenuLabelIndices[rowIndex][labelIndex];
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(
            0, gRecordTopMenuLabelIndices[0][rowIndex], gRecordTopMenu->mRecordTopMenuMBnll,
            GetBmgEntry(gRecordTopMenu->mRecordMessages, gRecordTopMenuRecordMessageIndices[rowIndex]),
            gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    }
    firstBlock = &gBackupBuffers->mFirstBlock;
    scores[1][0] = (*firstBlock)->mTotals[0];
    scores[2][0] = (*firstBlock)->mTotals[1];
    scores[1][1] = (*firstBlock)->mTotals[2];
    scores[2][1] = (*firstBlock)->mTotals[3];
    scores[1][2] = (*firstBlock)->mTotals[4];
    scores[2][2] = (*firstBlock)->mTotals[5];
    for (rowIndex = 1; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            if (scores[rowIndex][labelIndex] > 9999) {
                scores[rowIndex][labelIndex] = 9999;
            }
            FormatAsciiNumber(scores[rowIndex][labelIndex], buf);
            PrintLabelLayoutTextFixedAdvance(
                0, gRecordTopMenuLabelIndices[rowIndex][labelIndex], gRecordTopMenu->mRecordTopMenuMBnll, buf,
                gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable, 6);
        }
    }
    RefreshRecordTopMenuGradeCells();
    ResetRecordTopMenu();
    SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
}

void ReleaseRecordTopMenu(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    gRecordTopMenu = NULL;
    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    mainDisplayBits &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    subDisplayBits &= ~0x1;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
}

void AdvanceRecordTopMenuWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestRecordTopMenuSlideIn();
    }
}

void AdvanceRecordTopMenuSlideIn(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 labelIndex;
    s16 offsetY;
    const u16 *labelRow;
    s32 mainLayoutCount;

    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[rowIndex]].mOffsetY = offsetY;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0, labelRow = gRecordTopMenuLabelIndices[rowIndex]; labelIndex < 3; labelIndex++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = offsetY;
            labelRow++;
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuRowsSettle();
    }
}

void AdvanceRecordTopMenuRowsSettle(void) {
    s16 offsetX;
    s32 rowIndex;

    gRecordTopMenu->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTopMenu->mStateFrames);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuWaitSelectReturn();
    }
}

void AdvanceRecordTopMenuWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        RequestRecordTopMenuInput();
    }
}

void AdvanceRecordTopMenuInput(void) {
    InputSlotIndex slotIndex;
    u16 keyBPressed;
    BOOL touchBegan;
    s32 touchedRect;
    BOOL recentlyLost;
    BOOL touchBeganAgain;
    BOOL recentlyLostAgain;
    s32 rowIndex;

    touchBegan = FALSE;
    touchedRect = -1;
    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
        touchBeganAgain = FALSE;
        recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto skip;
        }
    }
    SetSelectReturnSoundId(15);
    RequestRecordTopMenuSlideOut();
    gRecordTopMenu->mRecordScreen = RECORD_SCREEN_START;
    RequestSelectReturnPressWithSound(1);
    return;
skip:
    if ((u32) touchedRect <= 2) {
        rowIndex = gRecordTopMenuTouchRowIndices[touchedRect];
        if (gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mVisible != 0) {
            if (gRecordTopMenu->mIndex == rowIndex) {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = rowIndex;
            } else {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = rowIndex;
                SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
            }
            RequestRecordTopMenuRowPress();
        }
    } else {
        keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
        if (keyBPressed != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            RequestRecordTopMenuRowPress();
        } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            DecrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            IncrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        }
    }
}

void AdvanceRecordTopMenuRowPress(void) {
    s16 offsetX;

    gRecordTopMenu->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTopMenu->mStateFrames);
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    if (gRecordTopMenu->mStateFrames == 5) {
        SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        if (gRecordTopMenu->mIndex == 2 && GetRecordCount() == 0) {
            RequestRecordTopMenuRowsSlideOut();
            return;
        }
        gRecordTopMenu->mRecordScreen = gRecordTopMenuRowRecordScreens[gRecordTopMenu->mIndex];
        RequestRecordTopMenuSlideOut();
    }
}

void AdvanceRecordTopMenuSlideOut(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 labelIndex;
    s16 offsetY;
    const u16 *labelRow;
    s32 mainLayoutCount;

    if (GetRecordNextScene() == -1 && gRecordTopMenu->mRecordScreen == RECORD_SCREEN_START) {
        SetRecordNextScene(0);
    }
    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[rowIndex]].mOffsetY = offsetY;
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        for (labelIndex = 0, labelRow = gRecordTopMenuLabelIndices[rowIndex]; labelIndex < 3; labelIndex++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = offsetY;
            labelRow++;
        }
    }
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10 && GetRecordNextScene() == -1) {
        RequestRecordScreen(gRecordTopMenu->mRecordScreen);
    }
}

void AdvanceRecordTopMenuRowsSlideOut(void) {
    s16 offsetX;
    s32 rowIndex;

    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuWaitMessageOpen();
    }
}

void AdvanceRecordTopMenuWaitMessageOpen(void) {
    int txtSystemNoCloseRequest;
    txtSystemNoCloseRequest = IsTxtSystemOpenNoCloseRequest();
    if (txtSystemNoCloseRequest != 0) {
        RequestRecordTopMenuMessageInput();
    }
}

void AdvanceRecordTopMenuMessageInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u16 keyBPressed;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;

    RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                            gInputSlots[slotIndex].mPair.mPairY);
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
        touchBegan = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchBegan = TRUE;
        }
        if (touchBegan == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            return;
        }
    }
    RequestRecordTopMenuWaitMessageClose();
    RequestSelectReturnPressWithSound(0);
}

void AdvanceRecordTopMenuWaitMessageClose(void) {
    int txtSystemNoOpenRequest;
    txtSystemNoOpenRequest = IsTxtSystemClosedNoOpenRequest();
    if (txtSystemNoOpenRequest != 0) {
        RequestRecordTopMenuRowsSlideIn();
    }
}

void AdvanceRecordTopMenuRowsSlideIn(void) {
    s32 rowIndex;
    s16 offsetX;
    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuWaitSelectReturn();
    }
}

void AdvanceRecordTopMenu(void) {
    RecordTopMenu *recordTopMenu;
    gRecordTopMenu->mState = gRecordTopMenu->mNextState;
    switch (gRecordTopMenu->mState) {
        case RECORD_TOP_MENU_STATE_WAIT_FADE:
            AdvanceRecordTopMenuWaitFade();
            break;
        case RECORD_TOP_MENU_STATE_SLIDE_IN:
            AdvanceRecordTopMenuSlideIn();
            break;
        case RECORD_TOP_MENU_STATE_ROWS_SETTLE:
            AdvanceRecordTopMenuRowsSettle();
            break;
        case RECORD_TOP_MENU_STATE_WAIT_SELECT_RETURN:
            AdvanceRecordTopMenuWaitSelectReturn();
            break;
        case RECORD_TOP_MENU_STATE_INPUT:
            AdvanceRecordTopMenuInput();
            break;
        case RECORD_TOP_MENU_STATE_ROW_PRESS:
            AdvanceRecordTopMenuRowPress();
            break;
        case RECORD_TOP_MENU_STATE_SLIDE_OUT:
            AdvanceRecordTopMenuSlideOut();
            break;
        case RECORD_TOP_MENU_STATE_ROWS_SLIDE_OUT:
            AdvanceRecordTopMenuRowsSlideOut();
            break;
        case RECORD_TOP_MENU_STATE_WAIT_MESSAGE_OPEN:
            AdvanceRecordTopMenuWaitMessageOpen();
            break;
        case RECORD_TOP_MENU_STATE_MESSAGE_INPUT:
            AdvanceRecordTopMenuMessageInput();
            break;
        case RECORD_TOP_MENU_STATE_WAIT_MESSAGE_CLOSE:
            AdvanceRecordTopMenuWaitMessageClose();
            break;
        case RECORD_TOP_MENU_STATE_ROWS_SLIDE_IN:
            AdvanceRecordTopMenuRowsSlideIn();
            break;
    }
    recordTopMenu = gRecordTopMenu;
    DrawLayoutTable(recordTopMenu->mRecordTopMenuMBncl, recordTopMenu->mRecordTopMenuMNcer,
                    recordTopMenu->mRecordTopMenuMBnll, GetRecordMainOam(), recordTopMenu->mRecordTopMenuMTable);
    recordTopMenu = gRecordTopMenu;
    DrawLayoutTable(recordTopMenu->mRecordTopMenuSBncl, recordTopMenu->mRecordTopMenuSNcer, NULL, GetRecordSubOam(),
                    recordTopMenu->mRecordTopMenuSTable);
}

void WriteRecordTopMenuBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordTopMenu->mBg0Offset << 16) & 0x1ff0000;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordTopMenuRegisters(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;
    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((mainDisplayBits | 0x11) << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 0x1) << 8);
}

void RegisterRecordTopMenuCallbacks(void) {
    RecordScreenCallbacks tbl = {InitRecordTopMenu, ReleaseRecordTopMenu, AdvanceRecordTopMenu,
                                 WriteRecordTopMenuBgOffsets, WriteRecordTopMenuRegisters};
    SetRecordScreenCallbacks(&tbl);
}
