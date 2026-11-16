#include "01/Menu/record_top_menu.h"
#include "Main/Menu/record_scene.h"

#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/System/heap.h"
#include "Main/Menu/record_vs.h"
#include "Main/Menu/record_list.h"
#include "Main/Menu/txt_system.h"
#include "Main/System/input_slots.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/oam.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/backup_net_camera_work.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "01/Menu/select_ghost.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"
#include "Main/Race/results_gp.h"

const u16 gRecordTopMenuGradeSTableIndices[3] = {2, 3, 4};
const u16 gRecordTopMenuRowCellIndices[3] = {9, 0xa, 0xb};
const u16 gRecordTopMenuLabelWidths[3][3] = {{0x70, 0x70, 0x70}, {0x20, 0x20, 0x20}, {0x20, 0x20, 0x20}};
const s32 gRecordTopMenuTouchRowIndices[RECORD_TOP_ROW_COUNT] =
    {RECORD_TOP_ROW_GPX, RECORD_TOP_ROW_TIME_ATTACK, RECORD_TOP_ROW_VS};
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
    s32 i;
    s32 j;
    const u16 *labelRow;
    s32 mainLayoutCount;

    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_FADE;
    gRecordTopMenu->mStateFrames = 0;
    gRecordTopMenu->mBg0Offset = -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mOffsetY =
            -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
    }
    for (i = 0; i < RECORD_TOP_ROW_COUNT; i++) {
        for (j = 0, labelRow = gRecordTopMenuLabelIndices[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY =
                -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE;
            labelRow++;
        }
    }
    for (i = 0; i < RECORD_TOP_ROW_COUNT; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX =
            RECORD_TOP_MENU_SLIDE_DISTANCE;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX =
            RECORD_TOP_MENU_SLIDE_DISTANCE;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX =
            RECORD_TOP_MENU_SLIDE_DISTANCE;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX =
            RECORD_TOP_MENU_SLIDE_DISTANCE;
        SetRecordTopMenuRowOff(i);
    }
}

void RequestRecordTopMenuSlideIn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_SLIDE_IN;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuRowsPressOffsetAfterSlideIn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SETTLE;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuWaitSelectReturn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_SELECT_RETURN;
    gRecordTopMenu->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

void RequestRecordTopMenuInput(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_INPUT;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuRowPress(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROW_PRESS;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestRecordTopMenuSlideOut(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_SLIDE_OUT;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuRowsSlideOut(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SLIDE_OUT;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuWaitMessageOpen(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_WAIT_MESSAGE_OPEN;
    gRecordTopMenu->mStateFrames = 0;
    SetupTxtSystemSubText(GetBmgEntry(gRecordTopMenu->mCommonMessages, 0x76));
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

void RequestRecordTopMenuRowsSlideIn(void) {
    gRecordTopMenu->mNextState = RECORD_TOP_MENU_STATE_ROWS_SLIDE_IN;
    gRecordTopMenu->mStateFrames = 0;
}

void IncrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex++;
    if (gRecordTopMenu->mIndex >= RECORD_TOP_ROW_COUNT) {
        gRecordTopMenu->mIndex = RECORD_TOP_ROW_GPX;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void DecrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex--;
    if (gRecordTopMenu->mIndex < 0) {
        gRecordTopMenu->mIndex = RECORD_TOP_ROW_VS;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void RefreshRecordTopMenuGradeCells(void) {
    s32 lowestGrade = RESULTS_GP_GRADE_BEST;
    s32 i;
    s32 engineClass;

    for (i = 0; i < 8; i++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            if (IsGrandPrixRecordFilled(i, engineClass)) {
                s32 grade = GetGrandPrixRecordGrade(i, engineClass);
                if (lowestGrade > grade) {
                    lowestGrade = grade;
                }
            } else {
                lowestGrade = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mVisible = 0;
    }
    if (lowestGrade > RESULTS_GP_GRADE_THIRD_BEST - 1) {
        gRecordTopMenu
            ->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[lowestGrade - RESULTS_GP_GRADE_THIRD_BEST]]
            .mVisible = 1;
    }
}

void InitRecordTopMenu(void *heap) {
    u32 totals[3][3] = {0};
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
            gRecordTopMenu->mIndex = RECORD_TOP_ROW_GPX;
            break;
        case RECORD_SCREEN_TIME_ATTACK:
            gRecordTopMenu->mIndex = RECORD_TOP_ROW_TIME_ATTACK;
            break;
        case RECORD_SCREEN_VS:
            if (GetRecordCount()) {
                gRecordTopMenu->mIndex = RECORD_TOP_ROW_VS;
            } else {
                gRecordTopMenu->mIndex = RECORD_TOP_ROW_GPX;
            }
            break;
    }
    LocateAndQueueRecordTopMenu();
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        SetCellOamModeXlu(gRecordTopMenuXluCellIndices[rowIndex], 1, gRecordTopMenu->mRecordTopMenuSNcer,
                          gRecordTopMenu->mRecordTopMenuSBncl);
    }
    ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMBnll,
                    &gRecordTopMenu->mRecordTopMenuMTable);
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuSBncl, NULL, &gRecordTopMenu->mRecordTopMenuSTable);
    gRecordTopMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
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
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            remainingSize -= InitLabelCanvas(
                heap, gRecordTopMenuLabelIndices[rowIndex][labelIndex], gRecordTopMenu->mRecordTopMenuMBnll,
                gRecordTopMenuLabelWidths[rowIndex][labelIndex], gRecordTopMenuLabelHeights[rowIndex][labelIndex],
                labelEntryIndex, gRecordTopMenu->mRecordTopMenuMNcer, gRecordTopMenu->mRecordTopMenuMBncl,
                gRecordTopMenu->mRecordTopMenuMTable, remainingSize);
            labelEntryIndex = mainLayoutCount + gRecordTopMenuLabelIndices[rowIndex][labelIndex];
        }
    }
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(
            0, gRecordTopMenuLabelIndices[0][rowIndex], gRecordTopMenu->mRecordTopMenuMBnll,
            GetBmgEntry(gRecordTopMenu->mRecordMessages, gRecordTopMenuRecordMessageIndices[rowIndex]),
            gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    }
    firstBlock = &gBackupBuffers->mFirstBlock;
    totals[1][0] = (*firstBlock)->mTotals[0];
    totals[2][0] = (*firstBlock)->mTotals[1];
    totals[1][1] = (*firstBlock)->mTotals[2];
    totals[2][1] = (*firstBlock)->mTotals[3];
    totals[1][2] = (*firstBlock)->mTotals[4];
    totals[2][2] = (*firstBlock)->mTotals[5];
    for (rowIndex = 1; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        for (labelIndex = 0; labelIndex < 3; labelIndex++) {
            if (totals[rowIndex][labelIndex] > 9999) {
                totals[rowIndex][labelIndex] = 9999;
            }
            FormatAsciiNumber(totals[rowIndex][labelIndex], buf);
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
    offsetX = InterpolateS16(1, RECORD_TOP_MENU_SLIDE_DISTANCE, 0, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    offsetY = InterpolateS16(1, -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE, 0, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[rowIndex]].mOffsetY = offsetY;
    }
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        for (labelIndex = 0, labelRow = gRecordTopMenuLabelIndices[rowIndex]; labelIndex < 3; labelIndex++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = offsetY;
            labelRow++;
        }
    }
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= RECORD_TOP_MENU_SLIDE_FRAMES) {
        RequestRecordTopMenuRowsPressOffsetAfterSlideIn();
    }
}

void AdvanceRecordTopMenuRowsPressOffsetAfterSlideIn(void) {
    s16 offsetX;
    s32 rowIndex;

    gRecordTopMenu->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTopMenu->mStateFrames);
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= SELECTED_PRESS_FRAMES) {
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
    u16 pressedKeyBits;
    BOOL touchBegan;
    s32 touchedRectIndex;
    BOOL recentlyLost;
    BOOL touchBeganAgain;
    BOOL recentlyLostAgain;
    s32 rowIndex;

    touchBegan = FALSE;
    touchedRectIndex = -1;
    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRectIndex = RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    pressedKeyBits = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (pressedKeyBits == 0) {
        touchBeganAgain = FALSE;
        recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
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
    if ((u32) touchedRectIndex <= RECORD_TOP_ROW_COUNT - 1) {
        rowIndex = gRecordTopMenuTouchRowIndices[touchedRectIndex];
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
        pressedKeyBits = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
        if (pressedKeyBits != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            RequestRecordTopMenuRowPress();
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            DecrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN) != 0) {
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
    if (gRecordTopMenu->mStateFrames == RECORD_TOP_MENU_ROW_ON_FRAME) {
        SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
    }
    if (gRecordTopMenu->mStateFrames >= SELECTED_PRESS_FRAMES) {
        if (gRecordTopMenu->mIndex == RECORD_TOP_ROW_VS && GetRecordCount() == 0) {
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
    offsetX = InterpolateS16(1, 0, RECORD_TOP_MENU_SLIDE_DISTANCE, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    offsetY = InterpolateS16(1, 0, -RECORD_TOP_MENU_BG0_SLIDE_DISTANCE, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[rowIndex]].mOffsetY = offsetY;
    }
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        for (labelIndex = 0, labelRow = gRecordTopMenuLabelIndices[rowIndex]; labelIndex < 3; labelIndex++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = offsetY;
            labelRow++;
        }
    }
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= RECORD_TOP_MENU_SLIDE_FRAMES && GetRecordNextScene() == -1) {
        RequestRecordScreen(gRecordTopMenu->mRecordScreen);
    }
}

void AdvanceRecordTopMenuRowsSlideOut(void) {
    s16 offsetX;
    s32 rowIndex;

    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, RECORD_TOP_MENU_SLIDE_DISTANCE, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= RECORD_TOP_MENU_SLIDE_FRAMES) {
        RequestRecordTopMenuWaitMessageOpen();
    }
}

void AdvanceRecordTopMenuWaitMessageOpen(void) {
    int txtSystemOpenNoCloseRequest;
    txtSystemOpenNoCloseRequest = IsTxtSystemOpenNoCloseRequest();
    if (txtSystemOpenNoCloseRequest != 0) {
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
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
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
    int txtSystemClosedNoOpenRequest;
    txtSystemClosedNoOpenRequest = IsTxtSystemClosedNoOpenRequest();
    if (txtSystemClosedNoOpenRequest != 0) {
        RequestRecordTopMenuRowsSlideIn();
    }
}

void AdvanceRecordTopMenuRowsSlideIn(void) {
    s32 rowIndex;
    s16 offsetX;
    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, RECORD_TOP_MENU_SLIDE_DISTANCE, 0, gRecordTopMenu->mStateFrames,
                             RECORD_TOP_MENU_SLIDE_FRAMES);
    for (rowIndex = 0; rowIndex < RECORD_TOP_ROW_COUNT; rowIndex++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= RECORD_TOP_MENU_SLIDE_FRAMES) {
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
            AdvanceRecordTopMenuRowsPressOffsetAfterSlideIn();
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
    RecordScreenCallbacks callbacks = {InitRecordTopMenu, ReleaseRecordTopMenu, AdvanceRecordTopMenu,
                                 WriteRecordTopMenuBgOffsets, WriteRecordTopMenuRegisters};
    SetRecordScreenCallbacks(&callbacks);
}
