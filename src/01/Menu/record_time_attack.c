#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "01/Menu/record_gpx.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/record_vs.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/txt_system.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "vram_bank_display_setup.h"
#include "Main/Graphics/layout_rect_table.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "cpu_copy_clear_16.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "03/Net/essid_packet_steps.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/Graphics/oam.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u16 gRecordTAttRunningSTableIndices[2] = {0x11, 0x12};
const u16 gRecordTAttNameLabelIndices[5] = {3, 4, 5, 6, 7};
const u16 gRecordTAttButtonSequence[RECORD_TATT_BUTTON_SEQUENCE_LENGTH] = {0x40, 0x80, 0x200, 0x100, 0x800, 1};
const u16 gRecordTAttNameLabelHeights[5] = {0x10, 0x10, 0x10, 0x10, 0x10};
const s32 gRecordTAttRecordIndices[5] = {0, 1, 2, 3, 4};
const u16 gRecordTAttOffsetSTableIndices[5] = {0, 0, 1, 2, 3};
const u16 gRecordTAttTimeLabelHeights[5] = {0x10, 0x10, 0x10, 0x10, 0x10};
const u16 gRecordTAttTimeLabelIndices[5] = {1, 0, 1, 2, 3};
RecordScreenCallbacks gRecordTAttCallbacks = {InitRecordTAtt, ReleaseRecordTAtt, AdvanceRecordTAtt,
                                              WriteRecordTAttBgOffsets, WriteRecordTAttRegisters};
const u16 gRecordTAttTimerZeroSTableIndices[2] = {0xf, 0x10};
const u16 gRecordTAttTimeLabelWidths[5] = {0x46, 0x46, 0x46, 0x46, 0x46};
const u16 gRecordTAttNameLabelWidths[5] = {0x7c, 0x68, 0x68, 0x68, 0x68};
RecordTAtt *gRecordTAtt;

void AdvanceRecordTAttOffsetTimers(void) {
    s32 timerIndex;

    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(RECORD_TATT_OFFSET_TIMER_FRAMES - gRecordTAtt->mOffsetTimers[0]);
    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(RECORD_TATT_OFFSET_TIMER_FRAMES - gRecordTAtt->mOffsetTimers[1]);
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gRecordTAtt->mOffsetTimers[timerIndex] > 0) {
            gRecordTAtt->mOffsetTimers[timerIndex]--;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[timerIndex]].mVisible = 0;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[timerIndex]].mVisible = 1;
        } else {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[timerIndex]].mVisible = 1;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[timerIndex]].mVisible = 0;
        }
    }
}

BOOL AdvanceRecordTAttButtonSequence(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u16 pressedBits;

    pressedBits = gInputSlots[slotIndex].mPressedBits;
    if (pressedBits != 0) {
        if (gRecordTAttButtonSequence[0] == (gRecordTAttButtonSequence[0] | pressedBits)) {
            gRecordTAtt->mButtonSequenceIndex = 1;
            gRecordTAtt->mUnk_84 = FALSE;
        } else if (gRecordTAttButtonSequence[gRecordTAtt->mButtonSequenceIndex] ==
                   (gRecordTAttButtonSequence[gRecordTAtt->mButtonSequenceIndex] | pressedBits)) {
            gRecordTAtt->mButtonSequenceIndex++;
            gRecordTAtt->mUnk_84 = FALSE;
            if (gRecordTAtt->mButtonSequenceIndex >= RECORD_TATT_BUTTON_SEQUENCE_LENGTH) {
                gRecordTAtt->mButtonSequenceIndex = 0;
                return TRUE;
            }
        } else {
            gRecordTAtt->mButtonSequenceIndex = 0;
        }
    }
    return FALSE;
}

void InitRecordTAtt(void *heap) {
    s32 timerIndex;
    s32 recordIndex;
    s32 remainingSize;
    RecordTAtt *recordTAtt;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~REG_G2_BG1CNT_PRIORITY_MASK) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0xcc00;
    (reg_G2S_DB_BG1CNT) =
        ((reg_G2S_DB_BG1CNT) & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0x1018;
    (reg_G2S_DB_BG3CNT) =
        ((reg_G2S_DB_BG3CNT) & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x5810;
    gRecordTAtt = HeapAlloc(heap, sizeof(RecordTAtt));
    gRecordTAtt->mHeap = heap;
    gRecordTAtt->mState = RECORD_TATT_STATE_SLIDE_IN_TOP;
    gRecordTAtt->mIndex = 0;
    gRecordTAtt->mIndexMoveDirection = RECORD_INDEX_MOVE_NEXT;
    gRecordTAtt->mClearChosen = FALSE;
    gRecordTAtt->mLeftRepeat = FALSE;
    gRecordTAtt->mRightRepeat = FALSE;
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        gRecordTAtt->mOffsetTimers[timerIndex] = 0;
    }
    LocateAndQueueRecordTAtt();
    CreateKartIcon(heap);
    ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    InitLayoutTable(heap, gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMBnll,
                    &gRecordTAtt->mRecordTAttMTable);
    InitLayoutTable(heap, gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSBnll,
                    &gRecordTAtt->mRecordTAttSTable);
    gRecordTAtt->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gRecordTAtt->mGhostMessages = FindSceneFile("ghost.bmg");
    gRecordTAtt->mRecordMessages = FindSceneFile("record.bmg");
    remainingSize = 0x8000;
    remainingSize -=
        InitLabelCanvas(heap, 0, gRecordTAtt->mRecordTAttMBnll, 0xc8, 0x10, 0, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 1, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 1, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 2, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 2, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 3, gRecordTAtt->mRecordTAttMBnll, 0x7c, 0x10, 3, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 4, gRecordTAtt->mRecordTAttMBnll, 0x64, 0x10, 4, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (recordIndex = 1; recordIndex < 5; recordIndex++) {
        remainingSize -=
            InitLabelCanvas(heap, gRecordTAttTimeLabelIndices[recordIndex], gRecordTAtt->mRecordTAttSBnll,
                            gRecordTAttTimeLabelWidths[recordIndex], gRecordTAttTimeLabelHeights[recordIndex],
                            recordIndex, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                            gRecordTAtt->mRecordTAttSTable, remainingSize);
        remainingSize -=
            InitLabelCanvas(heap, gRecordTAttNameLabelIndices[recordIndex], gRecordTAtt->mRecordTAttSBnll,
                            gRecordTAttNameLabelWidths[recordIndex], gRecordTAttNameLabelHeights[recordIndex],
                            recordIndex + 5, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                            gRecordTAtt->mRecordTAttSTable, remainingSize);
    }
    InitLabelCanvas(heap, 8, gRecordTAtt->mRecordTAttSBnll, 0x98, 0x10, 0xd, gRecordTAtt->mRecordTAttSNcer,
                    gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, remainingSize);
    recordTAtt = gRecordTAtt;
    PrintLabelLayoutTextNoFixedAdvance(1, 8, gRecordTAtt->mRecordTAttSBnll, GetBmgEntry(recordTAtt->mRecordMessages, 3),
                                       recordTAtt->mRecordTAttSBncl, recordTAtt->mRecordTAttSTable);
    ResetRecordTAtt();
}

void ReleaseRecordTAtt(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    ClearKartIconPointer();
    gRecordTAtt = NULL;
    mainDisplayBits = ((reg_GX_DISPCNT) & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((mainDisplayBits & ~0x13) << 8);
    subDisplayBits = ((reg_GXS_DB_DISPCNT) & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits & ~9) << 8);
}

void AdvanceRecordTAttSlideInTop(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY =
        InterpolateS16(1, -RECORD_TATT_TOP_SLIDE_DISTANCE, 0, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttSlideInRightAndSetup();
    }
}

void AdvanceRecordTAttSlideInRight(void) {
    s32 recordIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, RECORD_TATT_SLIDE_DISTANCE, 0, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (recordIndex = 1; recordIndex < 5; recordIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[recordIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[recordIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[recordIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[recordIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttWaitInput();
    }
}

void AdvanceRecordTAttWaitInput(void) {
    s32 touchedRect = -1;
    s32 touchBeganRect = -1;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL touchFlag;
    BOOL recentlyLost;
    u16 hasPair;

    AdvanceRecordTAttOffsetTimers();
    touchFlag = TRUE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && hasPair == 0) {
        touchFlag = FALSE;
    }
    if (touchFlag != FALSE) {
        touchedRect = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    touchFlag = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchFlag = TRUE;
    }
    if (touchFlag != FALSE) {
        touchBeganRect = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if (touchedRect != 0) {
        gRecordTAtt->mLeftRepeat = FALSE;
    }
    if (touchedRect != 1) {
        gRecordTAtt->mRightRepeat = FALSE;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        touchFlag = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchFlag = TRUE;
        }
        if (touchFlag == FALSE || IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                        gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto other;
        }
    }
    RequestRecordTAttSlideOutRight();
    gRecordTAtt->mNextScreen = RECORD_SCREEN_TOP_MENU;
    RequestSelectReturnPressWithSound(0);
    goto done;
other:
    if (touchBeganRect == 2 || (u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_X) != 0) {
        RequestRecordTAttPressButton();
    } else if ((touchedRect == 0 && gRecordTAtt->mLeftRepeat != FALSE) ||
               (touchBeganRect == 0 && gRecordTAtt->mLeftRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_LEFT) != 0) {
        gRecordTAtt->mIndexMoveDirection = RECORD_INDEX_MOVE_PREVIOUS;
        gRecordTAtt->mOffsetTimers[0] = RECORD_TATT_OFFSET_TIMER_FRAMES;
        gRecordTAtt->mLeftRepeat = TRUE;
        RequestRecordTAttSlideOutSide();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    } else if ((touchedRect == 1 && gRecordTAtt->mRightRepeat != FALSE) ||
               (touchBeganRect == 1 && gRecordTAtt->mRightRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordTAtt->mIndexMoveDirection = RECORD_INDEX_MOVE_NEXT;
        gRecordTAtt->mOffsetTimers[1] = RECORD_TATT_OFFSET_TIMER_FRAMES;
        gRecordTAtt->mRightRepeat = TRUE;
        RequestRecordTAttSlideOutSide();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    }
done:
    if (AdvanceRecordTAttButtonSequence() != FALSE) {
        if (CheckRecordTAttFirstRecordFormat() != FALSE) {
            RequestRecordTAttSlideOutForTimeRecordChars();
        }
    }
}

void AdvanceRecordTAttSlideOutSide(void) {
    s32 rowIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 targetOffsetX;
    s16 offsetX;

    targetOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            targetOffsetX = -RECORD_TATT_SLIDE_DISTANCE;
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            targetOffsetX = RECORD_TATT_SLIDE_DISTANCE;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttSlideInSideAndMoveIndexAndSetup();
    }
}

void AdvanceRecordTAttSlideInSide(void) {
    s32 rowIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 startOffsetX;
    s16 offsetX;

    startOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            startOffsetX = RECORD_TATT_SLIDE_DISTANCE;
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            startOffsetX = -RECORD_TATT_SLIDE_DISTANCE;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttWaitInput();
    }
}

void AdvanceRecordTAttSlideOutRight(void) {
    s32 rowIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, RECORD_TATT_SLIDE_DISTANCE, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttSlideOutTop();
    }
}

void AdvanceRecordTAttSlideOutTop(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY =
        InterpolateS16(1, 0, -RECORD_TATT_TOP_SLIDE_DISTANCE, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordScreen(gRecordTAtt->mNextScreen);
    }
}

void AdvanceRecordTAttPressButton(void) {
    s16 offsetX;
    u16 subLayoutCount;

    gRecordTAtt->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTAtt->mStateFrames);
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_PRESS_FRAMES) {
        RequestRecordTAttSlideOutForAskClear();
    }
}

void AdvanceRecordTAttSlideOutForAskClear(void) {
    s32 rowIndex;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, RECORD_TATT_SLIDE_DISTANCE, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > RECORD_TATT_SLIDE_FRAMES) {
        if (IsSelectReturnHiddenNoSlideInRequest() != 0) {
            RequestRecordTAttWaitAskClearOpen();
        }
    }
    if (gRecordTAtt->mStateFrames == RECORD_TATT_HIDE_CELLS_FRAME) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttWaitAskClearOpen(void) {
    if (IsTxtSystemOpenNoCloseRequest() != 0) {
        RequestRecordTAttWaitClearAnswer();
    }
}

void AdvanceRecordTAttWaitClearAnswer(void) {
    if (GetTxtSystemDone() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            if (IsCourseGhostRecordMissing(gRecordTAttCourseIds[gRecordTAtt->mIndex]) == 0) {
                ClearCourseTimeRecords(gRecordTAttCourseIds[gRecordTAtt->mIndex]);
                WaitThreadFunctionsDone();
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            }
            gRecordTAtt->mClearChosen = TRUE;
        }
        RequestRecordTAttWaitAskClearClose();
    }
}

void AdvanceRecordTAttWaitAskClearClose(void) {
    s16 offsetX;
    u16 mainLayoutCount;

    gRecordTAtt->mStateFrames++;
    if (gRecordTAtt->mClearChosen != FALSE) {
        offsetX = InterpolateS16(1, 0, RECORD_TATT_SLIDE_DISTANCE, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
        gRecordTAtt->mBg1OffsetX = offsetX;
        mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    }
    if (gRecordTAtt->mStateFrames >= RECORD_TATT_SLIDE_FRAMES) {
        if (IsTxtSystemClosedNoOpenRequest() != 0) {
            RequestRecordTAttSlideInAfterAskClearAndSetup();
        }
    }
}

void AdvanceRecordTAttSlideInAfterAskClear(void) {
    s32 rowIndex;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, RECORD_TATT_SLIDE_DISTANCE, 0, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    if (gRecordTAtt->mClearChosen != FALSE) {
        u16 mainLayoutCount;

        gRecordTAtt->mBg1OffsetX = offsetX;
        mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    }
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > RECORD_TATT_SLIDE_FRAMES) {
        if (IsSelectReturnShownNoRequest() != 0) {
            RequestRecordTAttWaitInput();
        }
    }
    if (gRecordTAtt->mStateFrames == RECORD_TATT_SHOW_CELL_FRAME) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAttSlideOutForTimeText(void) {
    s32 rowIndex;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, RECORD_TATT_SLIDE_DISTANCE, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttWaitTimeRecordCharsOpen();
    }
    if (gRecordTAtt->mStateFrames == RECORD_TATT_HIDE_CELLS_FRAME) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttWaitTimeTextOpen(void) {
    int txtSystemOpenNoCloseRequest;
    txtSystemOpenNoCloseRequest = IsTxtSystemOpenNoCloseRequest();
    if (txtSystemOpenNoCloseRequest != 0) {
        RequestRecordTAttWaitTimeRecordCharsInput();
    }
}

void AdvanceRecordTAttWaitTimeTextInput(void) {
    InputSlotIndex slotIndex;
    u16 pressedOrTouchBegan;
    BOOL recentlyLost;

    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    pressedOrTouchBegan = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (pressedOrTouchBegan == 0) {
        pressedOrTouchBegan = 0;
        recentlyLost = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            pressedOrTouchBegan = 1;
        }
        if (pressedOrTouchBegan == 0 ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            return;
        }
    }
    RequestRecordTAttWaitTimeRecordCharsClose();
    RequestSelectReturnPressWithSound(0);
}

void AdvanceRecordTAttWaitTimeTextClose(void) {
    int txtSystemClosedNoOpenRequest;
    txtSystemClosedNoOpenRequest = IsTxtSystemClosedNoOpenRequest();
    if (txtSystemClosedNoOpenRequest != 0) {
        RequestRecordTAttSlideInAfterTimeRecordChars();
    }
}

void AdvanceRecordTAttSlideInAfterTimeText(void) {
    s32 rowIndex;
    s32 j;
    u16 subLayoutCount;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, RECORD_TATT_SLIDE_DISTANCE, 0, gRecordTAtt->mStateFrames, RECORD_TATT_SLIDE_FRAMES);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (rowIndex = 1; rowIndex < 5; rowIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[rowIndex]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[rowIndex]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[rowIndex][j]].mOffsetX =
                offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > RECORD_TATT_SLIDE_FRAMES) {
        RequestRecordTAttWaitInput();
    }
    if (gRecordTAtt->mStateFrames == RECORD_TATT_SHOW_CELL_FRAME) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAtt(void) {
    RecordTAtt *recordTAtt;

    gRecordTAtt->mState = gRecordTAtt->mNextState;
    switch (gRecordTAtt->mState) {
        case RECORD_TATT_STATE_SLIDE_IN_TOP:
            AdvanceRecordTAttSlideInTop();
            break;
        case RECORD_TATT_STATE_SLIDE_IN_RIGHT:
            AdvanceRecordTAttSlideInRight();
            break;
        case RECORD_TATT_STATE_WAIT_INPUT:
            AdvanceRecordTAttWaitInput();
            break;
        case RECORD_TATT_STATE_SLIDE_OUT_SIDE:
            AdvanceRecordTAttSlideOutSide();
            break;
        case RECORD_TATT_STATE_SLIDE_IN_SIDE:
            AdvanceRecordTAttSlideInSide();
            break;
        case RECORD_TATT_STATE_SLIDE_OUT_RIGHT:
            AdvanceRecordTAttSlideOutRight();
            break;
        case RECORD_TATT_STATE_SLIDE_OUT_TOP:
            AdvanceRecordTAttSlideOutTop();
            break;
        case RECORD_TATT_STATE_PRESS_BUTTON:
            AdvanceRecordTAttPressButton();
            break;
        case RECORD_TATT_STATE_SLIDE_OUT_FOR_CLEAR_PROMPT:
            AdvanceRecordTAttSlideOutForAskClear();
            break;
        case RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_OPEN:
            AdvanceRecordTAttWaitAskClearOpen();
            break;
        case RECORD_TATT_STATE_WAIT_CLEAR_ANSWER:
            AdvanceRecordTAttWaitClearAnswer();
            break;
        case RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_CLOSE:
            AdvanceRecordTAttWaitAskClearClose();
            break;
        case RECORD_TATT_STATE_SLIDE_IN_AFTER_CLEAR_PROMPT:
            AdvanceRecordTAttSlideInAfterAskClear();
            break;
        case RECORD_TATT_STATE_SLIDE_OUT_FOR_TIME_TEXT:
            AdvanceRecordTAttSlideOutForTimeText();
            break;
        case RECORD_TATT_STATE_WAIT_TIME_TEXT_OPEN:
            AdvanceRecordTAttWaitTimeTextOpen();
            break;
        case RECORD_TATT_STATE_WAIT_TIME_TEXT_INPUT:
            AdvanceRecordTAttWaitTimeTextInput();
            break;
        case RECORD_TATT_STATE_WAIT_TIME_TEXT_CLOSE:
            AdvanceRecordTAttWaitTimeTextClose();
            break;
        case RECORD_TATT_STATE_SLIDE_IN_AFTER_TIME_TEXT:
            AdvanceRecordTAttSlideInAfterTimeText();
            break;
    }
    recordTAtt = gRecordTAtt;
    DrawLayoutTable(recordTAtt->mRecordTAttMBncl, recordTAtt->mRecordTAttMNcer, recordTAtt->mRecordTAttMBnll,
                    GetRecordMainOam(), recordTAtt->mRecordTAttMTable);
    recordTAtt = gRecordTAtt;
    DrawLayoutTable(recordTAtt->mRecordTAttSBncl, recordTAtt->mRecordTAttSNcer, recordTAtt->mRecordTAttSBnll,
                    GetRecordSubOam(), recordTAtt->mRecordTAttSTable);
}

void WriteRecordTAttBgOffsets(void) {
    RecordTAtt *recordTAtt;

    reg_G2_BG0OFS = (-gRecordTAtt->mBg0Offset << 16) & 0x1ff0000;
    recordTAtt = gRecordTAtt;
    reg_G2_BG1OFS = (-recordTAtt->mBg1OffsetX & 0x1ff) | ((-recordTAtt->mBg1OffsetY << 16) & 0x1ff0000);
    reg_G2S_DB_BG3OFS = -gRecordTAtt->mBg3OffsetX & 0x1ff;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordTAttRegisters(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    mainDisplayBits |= 0x13;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    subDisplayBits |= 9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
}

void RegisterRecordTAttCallbacks(void) {
    RecordScreenCallbacks callbacks = gRecordTAttCallbacks;

    SetRecordScreenCallbacks(&callbacks);
}
