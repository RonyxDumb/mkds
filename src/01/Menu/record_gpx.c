#include "01/Menu/record_gpx.h"

#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Menu/record_vs.h"
#include "Main/Graphics/layout_rect_table.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/cup_mark.h"
#include "code_02148950.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "01/Menu/record_gpx_cell_tables.h"
#include "Main/System/init_after_startup.h"

const u16 gRecordGpxRunningSTableIndices[2] = {0x2e, 0x2f};
const u16 gRecordGpxTimeLabelIndices[4] = {0, 1, 2, 3};
const u16 gRecordGpxTrophyCellIndices[4] = {0, 1, 2, 3};
const u16 gRecordGpxCharacterKartCellIndices[4][2] = {{0x24, 0x28}, {0x25, 0x29}, {0x26, 0x2a}, {0x27, 0x2b}};
const u16 gRecordGpxHighSTableIndices[4] = {0x14, 0x15, 0x16, 0x17};
const u16 gRecordGpxTimeLabelHeights[4] = {0x10, 0x10, 0x10, 0x10};
const u16 gRecordGpxGradeLabelIndices[4] = {8, 9, 0xa, 0xb};
const u16 gRecordGpxGradeLabelWidths[4] = {0xe, 0xe, 0xe, 0xe};
const u16 gRecordGpxLowSTableIndices[4] = {4, 5, 6, 7};
const u16 gRecordGpxTotalPointsLabelWidths[4] = {0x10, 0x10, 0x10, 0x10};
const u16 gRecordGpxTotalPointsLabelIndices[4] = {4, 5, 6, 7};
const u16 gRecordGpxTrophyPaletteIndices[4] = {2, 0xb, 0xc, 0};
const u16 gRecordGpxTrophyNclrPaletteIndices[4] = {0, 1, 2, 0};
const u16 gRecordGpxTimerZeroSTableIndices[2] = {0x2c, 0x2d};
const u16 gRecordGpxTimeLabelWidths[4] = {0x41, 0x41, 0x41, 0x41};
const u16 gRecordGpxTotalPointsLabelHeights[4] = {0x10, 0x10, 0x10, 0x10};
const u16 gRecordGpxGradeLabelHeights[4] = {0x10, 0x10, 0x10, 0x10};
u16 gRecordGpxGradeTextB[2] = {0x42, 0};
u16 gRecordGpxGradeTextD[2] = {0x44, 0};
u16 gRecordGpxGradeTextC[2] = {0x43, 0};
u16 gRecordGpxGradeTextE[2] = {0x45, 0};
u16 gRecordGpxGradeTextA[2] = {0x41, 0};
u16 *gRecordGpxGradeStrings[5] = {gRecordGpxGradeTextE, gRecordGpxGradeTextD, gRecordGpxGradeTextC,
                                  gRecordGpxGradeTextB, gRecordGpxGradeTextA};
RecordScreenCallbacks gRecordGpxCallbacks = {InitRecordGpx, ReleaseRecordGpx, AdvanceRecordGpx, WriteRecordGpxBgOffsets,
                                             WriteRecordGpxRegisters};
RecordGpx *gRecordGpx;

void RequestRecordGpxCellsSlideInAndSetup(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_CELLS_SLIDE_IN;
    gRecordGpx->mStateFrames = 0;
    SetupRecordGpx();
}

// Requests state 2: stores mNextState and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxSelect.
void RequestRecordGpxSelect(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_SELECT;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 3: stores mNextState and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxPageSlideOut.
void RequestRecordGpxPageSlideOut(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_PAGE_SLIDE_OUT;
    gRecordGpx->mStateFrames = 0;
}

void RequestRecordGpxPageSlideInAndMoveIndex(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_PAGE_SLIDE_IN;
    gRecordGpx->mStateFrames = 0;
    switch (gRecordGpx->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            IncrementRecordGpxIndex();
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            DecrementRecordGpxIndex();
            break;
    }
    SetupRecordGpx();
}

// Requests state 5: stores mNextState and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxCellsSlideOut.
void RequestRecordGpxCellsSlideOut(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_CELLS_SLIDE_OUT;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 6: stores mNextState and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxBgSlideOut.
void RequestRecordGpxBgSlideOut(void) {
    gRecordGpx->mNextState = RECORD_GPX_STATE_BG_SLIDE_OUT;
    gRecordGpx->mStateFrames = 0;
}

void InitRecordGpx(void *heap) {
    u32 anyFlagSet = 0;
    s32 index;
    s32 remainingSize;
    void *recordMainOam;
    vu16 zero;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x8800;
    reg_G2S_DB_BG1CNT =
        (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0x1018;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x5810;
    gRecordGpx = HeapAlloc(heap, sizeof(RecordGpx));
    gRecordGpx->mHeap = heap;
    gRecordGpx->mState = RECORD_GPX_STATE_BG_SLIDE_IN;
    gRecordGpx->mIndex = 0;
    gRecordGpx->mIndexMoveDirection = RECORD_INDEX_MOVE_NEXT;
    gRecordGpx->mLeftRepeat = FALSE;
    gRecordGpx->mRightRepeat = FALSE;
    for (index = 0; index < 2; index++) {
        gRecordGpx->mOffsetTimers[index] = 0;
    }
    LocateAndQueueRecordGpx();
    CreateKartIcon(heap);
    CreateCupMark(heap);
    recordMainOam = GetRecordMainOam();
    ResetOamLists(recordMainOam, GetRecordSubOam());
    InitLayoutTable(heap, gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMBnll, &gRecordGpx->mRecordGpxMTable);
    InitLayoutTable(heap, gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSBnll, &gRecordGpx->mRecordGpxSTable);
    gRecordGpx->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitLabelCanvas(heap, 0, gRecordGpx->mRecordGpxMBnll, 200, 16, 0, gRecordGpx->mRecordGpxMNcer,
                    gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMTable, 0x8000);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (index = 0; index < 4; index++) {
        remainingSize -= InitLabelCanvas(heap, gRecordGpxTimeLabelIndices[index], gRecordGpx->mRecordGpxSBnll,
                                         gRecordGpxTimeLabelWidths[index], gRecordGpxTimeLabelHeights[index], index,
                                         gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                                         gRecordGpx->mRecordGpxSTable, remainingSize);
        remainingSize -= InitLabelCanvas(
            heap, gRecordGpxTotalPointsLabelIndices[index], gRecordGpx->mRecordGpxSBnll,
            gRecordGpxTotalPointsLabelWidths[index], gRecordGpxTotalPointsLabelHeights[index], index + 4,
            gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, remainingSize);
        remainingSize -= InitLabelCanvas(heap, gRecordGpxGradeLabelIndices[index], gRecordGpx->mRecordGpxSBnll,
                                         gRecordGpxGradeLabelWidths[index], gRecordGpxGradeLabelHeights[index],
                                         index + 12, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                                         gRecordGpx->mRecordGpxSTable, remainingSize);
    }
    gRecordGpx->mBg3OffsetY = 0;
    for (index = 0; index < 8; index++) {
        anyFlagSet |= IsRecordGpxCupBackupFlagSet(index);
    }
    if (anyFlagSet == 0) {
        gRecordGpx->mBg3OffsetY = RECORD_GPX_NO_CUP_BG3_OFFSET_Y;
    }
    gRecordGpx->mZeroBuffer = HeapAlloc(heap, RECORD_GPX_MAP_STRIP_BYTES);
    zero = 0;
    MIi_CpuClear16(zero, gRecordGpx->mZeroBuffer, RECORD_GPX_MAP_STRIP_BYTES);
    ResetRecordGpx();
}

void ReleaseRecordGpx(void) {
    u32 displayBits;

    ClearKartIconPointer();
    ClearCupMarkPointer();
    gRecordGpx = NULL;
    displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    displayBits &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    displayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    displayBits &= ~0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
}

void AdvanceRecordGpxBgSlideIn(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset =
        InterpolateS16(1, -RECORD_GPX_BG0_SLIDE_DISTANCE, 0, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordGpxCellsSlideInAndSetup();
    }
}

void AdvanceRecordGpxCellsSlideIn(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 cellIndex;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    AdvanceRecordGpxOffsetTimers();
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, RECORD_GPX_SLIDE_DISTANCE, 0, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = offsetX;
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordGpxSelect();
    }
}

void AdvanceRecordGpxSelect(void) {
    s32 touchedRect = -1;
    s32 touchBeganRect = -1;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL touchActive, recentlyLost, touchBegan, lostBeforeBegan, confirmTouchBegan, lostBeforeConfirm;

    AdvanceRecordGpxOffsetTimers();
    touchActive = TRUE;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mHasPair == 0) {
        touchActive = FALSE;
    }
    if (touchActive != FALSE) {
        touchedRect = RectTableFindContaining(gRecordGpx->mRecordGpxSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    touchBegan = FALSE;
    lostBeforeBegan = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        lostBeforeBegan = TRUE;
    }
    if (lostBeforeBegan == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchBeganRect = RectTableFindContaining(gRecordGpx->mRecordGpxSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if (touchedRect != 0) {
        gRecordGpx->mLeftRepeat = FALSE;
    }
    if (touchedRect != 1) {
        gRecordGpx->mRightRepeat = FALSE;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        confirmTouchBegan = FALSE;
        lostBeforeConfirm = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            lostBeforeConfirm = TRUE;
        }
        if (lostBeforeConfirm == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            confirmTouchBegan = TRUE;
        }
        if (confirmTouchBegan == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    RequestRecordGpxCellsSlideOut();
    gRecordGpx->mNextScreen = RECORD_SCREEN_TOP_MENU;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    if ((touchedRect == 0 && gRecordGpx->mLeftRepeat != FALSE) ||
        (touchBeganRect == 0 && gRecordGpx->mLeftRepeat == FALSE) ||
        (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_LEFT) != 0) {
        gRecordGpx->mIndexMoveDirection = RECORD_INDEX_MOVE_PREVIOUS;
        gRecordGpx->mOffsetTimers[0] = RECORD_GPX_OFFSET_TIMER_FRAMES;
        gRecordGpx->mLeftRepeat = TRUE;
        RequestRecordGpxPageSlideOut();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if ((touchedRect == 1 && gRecordGpx->mRightRepeat != FALSE) ||
        (touchBeganRect == 1 && gRecordGpx->mRightRepeat == FALSE) ||
        (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordGpx->mIndexMoveDirection = RECORD_INDEX_MOVE_NEXT;
        gRecordGpx->mOffsetTimers[1] = RECORD_GPX_OFFSET_TIMER_FRAMES;
        gRecordGpx->mRightRepeat = TRUE;
        RequestRecordGpxPageSlideOut();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    }
}

void AdvanceRecordGpxPageSlideOut(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 cellIndex;
    s32 mainLayoutCount;
    s32 subLayoutCount;
    s16 targetOffsetX = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            targetOffsetX = -RECORD_GPX_SLIDE_DISTANCE;
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            targetOffsetX = RECORD_GPX_SLIDE_DISTANCE;
            break;
    }
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordGpxPageSlideInAndMoveIndex();
    }
}

void AdvanceRecordGpxPageSlideIn(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 cellIndex;
    s32 mainLayoutCount;
    s32 subLayoutCount;
    s16 startOffsetX = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            startOffsetX = RECORD_GPX_SLIDE_DISTANCE;
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            startOffsetX = -RECORD_GPX_SLIDE_DISTANCE;
            break;
    }
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordGpxSelect();
    }
}

void AdvanceRecordGpxCellsSlideOut(void) {
    s16 offsetX;
    s32 rowIndex;
    s32 cellIndex;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, 0, RECORD_GPX_SLIDE_DISTANCE, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = offsetX;
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordGpxBgSlideOut();
    }
}

void AdvanceRecordGpxBgSlideOut(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset =
        InterpolateS16(1, 0, -RECORD_GPX_BG0_SLIDE_DISTANCE, gRecordGpx->mStateFrames, RECORD_GPX_SLIDE_FRAMES);
    if (gRecordGpx->mStateFrames >= RECORD_GPX_SLIDE_FRAMES) {
        RequestRecordScreen(gRecordGpx->mNextScreen);
    }
}

void AdvanceRecordGpx(void) {
    RecordGpx *recordGpx;

    gRecordGpx->mState = gRecordGpx->mNextState;
    switch (gRecordGpx->mState) {
        case RECORD_GPX_STATE_BG_SLIDE_IN:
            AdvanceRecordGpxBgSlideIn();
            break;
        case RECORD_GPX_STATE_CELLS_SLIDE_IN:
            AdvanceRecordGpxCellsSlideIn();
            break;
        case RECORD_GPX_STATE_SELECT:
            AdvanceRecordGpxSelect();
            break;
        case RECORD_GPX_STATE_PAGE_SLIDE_OUT:
            AdvanceRecordGpxPageSlideOut();
            break;
        case RECORD_GPX_STATE_PAGE_SLIDE_IN:
            AdvanceRecordGpxPageSlideIn();
            break;
        case RECORD_GPX_STATE_CELLS_SLIDE_OUT:
            AdvanceRecordGpxCellsSlideOut();
            break;
        case RECORD_GPX_STATE_BG_SLIDE_OUT:
            AdvanceRecordGpxBgSlideOut();
            break;
    }
    recordGpx = gRecordGpx;
    DrawLayoutTable(recordGpx->mRecordGpxMBncl, recordGpx->mRecordGpxMNcer, recordGpx->mRecordGpxMBnll,
                    GetRecordMainOam(), recordGpx->mRecordGpxMTable);
    recordGpx = gRecordGpx;
    DrawLayoutTable(recordGpx->mRecordGpxSBncl, recordGpx->mRecordGpxSNcer, recordGpx->mRecordGpxSBnll,
                    GetRecordSubOam(), recordGpx->mRecordGpxSTable);
}

void WriteRecordGpxBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordGpx->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = ((-gRecordGpx->mBg3OffsetX) & 0x1ff) | ((-gRecordGpx->mBg3OffsetY << 16) & 0x1ff0000);
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordGpxRegisters(void) {
    u32 mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    u32 subDisplayBits;

    mainDisplayBits |= 0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    subDisplayBits |= 0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
}

void RegisterRecordGpxCallbacks(void) {
    RecordScreenCallbacks local = gRecordGpxCallbacks;

    SetRecordScreenCallbacks(&local);
}
