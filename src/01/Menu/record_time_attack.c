#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "01/Menu/record_gpx.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/record_vs.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/txt_system.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "01/unk_021a6000.h"
#include "code_02148950.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0214cfe4.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "03/Net/essid_packet_steps.h"
#include "01/unk_021a8000.h"
#include "Main/Graphics/oam.h"
#include "01/code_02198000.h"
#include "01/unk_021a9000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/sound_system.h"

void AdvanceRecordTAtt(void);
void InitRecordTAtt(void *heap);
void ReleaseRecordTAtt(void);
void WriteRecordTAttBgOffsets(void);
void WriteRecordTAttRegisters(void);
const u16 gRecordTAttRunningSTableIndices[2] = {0x11, 0x12};
const u16 gRecordTAttNameLabelIndices[5] = {3, 4, 5, 6, 7};
const u16 gRecordTAttButtonSequence[6] = {0x40, 0x80, 0x200, 0x100, 0x800, 1};
const u16 gRecordTAttNameLabelHeights[5] = {0x10, 0x10, 0x10, 0x10, 0x10};
const s32 gRecordTAttRecordIndices[5] = {0, 1, 2, 3, 4};
const u16 gRecordTAttOffsetSTableIndices[5] = {0, 0, 1, 2, 3};
const u16 gRecordTAttTimeLabelHeights[5] = {0x10, 0x10, 0x10, 0x10, 0x10};
const u16 gRecordTAttTimeLabelIndices[5] = {1, 0, 1, 2, 3};
RecordScreenCallbacks gRecordTAttCallbacks = {InitRecordTAtt, ReleaseRecordTAtt, AdvanceRecordTAtt, WriteRecordTAttBgOffsets, WriteRecordTAttRegisters};
const u16 gRecordTAttTimerZeroSTableIndices[2] = {0xf, 0x10};
const u16 gRecordTAttTimeLabelWidths[5] = {0x46, 0x46, 0x46, 0x46, 0x46};
const u16 gRecordTAttNameLabelWidths[5] = {0x7c, 0x68, 0x68, 0x68, 0x68};
RecordTAtt *gRecordTAtt;

void AdvanceRecordTAttOffsetTimers(void) {
    s32 i;

    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordTAtt->mOffsetTimers[0]);
    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordTAtt->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordTAtt->mOffsetTimers[i] > 0) {
            gRecordTAtt->mOffsetTimers[i]--;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[i]].mVisible = 0;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[i]].mVisible = 1;
        } else {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[i]].mVisible = 1;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[i]].mVisible = 0;
        }
    }
}

BOOL AdvanceRecordTAttButtonSequence(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
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
            if (gRecordTAtt->mButtonSequenceIndex >= 6) {
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
    s32 i;
    s32 k;
    s32 remainingSize;
    RecordTAtt *recordTAtt;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~3) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~3) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~3) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & 0x43) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & 0x43) | 0xcc00;
    (reg_G2S_DB_BG1CNT) = ((reg_G2S_DB_BG1CNT) & 0x43) | 0x1018;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x5810;
    gRecordTAtt = HeapAlloc(heap, 0x94);
    gRecordTAtt->mHeap = heap;
    gRecordTAtt->mState = 0;
    gRecordTAtt->mIndex = 0;
    gRecordTAtt->mIndexMoveDirection = 0;
    gRecordTAtt->mClearChosen = FALSE;
    gRecordTAtt->mLeftRepeat = FALSE;
    gRecordTAtt->mRightRepeat = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordTAtt->mOffsetTimers[i] = 0;
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
    for (k = 1; k < 5; k++) {
        remainingSize -= InitLabelCanvas(heap, gRecordTAttTimeLabelIndices[k], gRecordTAtt->mRecordTAttSBnll,
                                         gRecordTAttTimeLabelWidths[k], gRecordTAttTimeLabelHeights[k], k,
                                         gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                                         gRecordTAtt->mRecordTAttSTable, remainingSize);
        remainingSize -= InitLabelCanvas(heap, gRecordTAttNameLabelIndices[k], gRecordTAtt->mRecordTAttSBnll,
                                         gRecordTAttNameLabelWidths[k], gRecordTAttNameLabelHeights[k], k + 5,
                                         gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
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
    mainDisplayBits = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~0x1f00) | ((mainDisplayBits & ~0x13) << 8);
    subDisplayBits = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~0x1f00) | ((subDisplayBits & ~9) << 8);
}

void AdvanceRecordTAttState0(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState1AndSetup();
    }
}

void AdvanceRecordTAttState1(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
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
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState2();
    }
}

void AdvanceRecordTAttState2(void) {
    s32 touchedRect = -1;
    s32 touchBeganRect = -1;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL x;
    BOOL recentlyLost;
    u16 hasPair;

    AdvanceRecordTAttOffsetTimers();
    x = TRUE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && hasPair == 0) {
        x = FALSE;
    }
    if (x != FALSE) {
        touchedRect = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    x = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        x = TRUE;
    }
    if (x != FALSE) {
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
        x = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            x = TRUE;
        }
        if (x == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(
                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto other;
        }
    }
    RequestRecordTAttState5();
    gRecordTAtt->mNextScreen = 0;
    RequestSelectReturnState3WithSound(0);
    goto done;
other:
    if (touchBeganRect == 2 || (u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_X) != 0) {
        RequestRecordTAttState7();
    } else if ((touchedRect == 0 && gRecordTAtt->mLeftRepeat != FALSE) ||
               (touchBeganRect == 0 && gRecordTAtt->mLeftRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_LEFT) != 0) {
        gRecordTAtt->mIndexMoveDirection = 1;
        gRecordTAtt->mOffsetTimers[0] = 6;
        gRecordTAtt->mLeftRepeat = TRUE;
        RequestRecordTAttState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    } else if ((touchedRect == 1 && gRecordTAtt->mRightRepeat != FALSE) ||
               (touchBeganRect == 1 && gRecordTAtt->mRightRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordTAtt->mIndexMoveDirection = 0;
        gRecordTAtt->mOffsetTimers[1] = 6;
        gRecordTAtt->mRightRepeat = TRUE;
        RequestRecordTAttState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    }
done:
    if (AdvanceRecordTAttButtonSequence() != FALSE) {
        if (CheckRecordTAttFirstRecordFormat() != FALSE) {
            RequestRecordTAttState13();
        }
    }
}

void AdvanceRecordTAttState3(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 targetOffsetX;
    s16 offsetX;

    targetOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case 0:
            targetOffsetX = -0x100;
            break;
        case 1:
            targetOffsetX = 0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordTAtt->mStateFrames, 10);
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
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState4AndMoveIndex();
    }
}

void AdvanceRecordTAttState4(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 startOffsetX;
    s16 offsetX;

    startOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case 0:
            startOffsetX = 0x100;
            break;
        case 1:
            startOffsetX = -0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordTAtt->mStateFrames, 10);
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
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState2();
    }
}

void AdvanceRecordTAttState5(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
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
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState6();
    }
}

void AdvanceRecordTAttState6(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordScreen(gRecordTAtt->mNextScreen);
    }
}

void AdvanceRecordTAttState7(void) {
    s16 offsetX;
    u16 subLayoutCount;

    gRecordTAtt->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTAtt->mStateFrames);
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState8();
    }
}

void AdvanceRecordTAttState8(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            RequestRecordTAttState9();
        }
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttState9(void) {
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        RequestRecordTAttState10();
    }
}

void AdvanceRecordTAttState10(void) {
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
        RequestRecordTAttState11();
    }
}

void AdvanceRecordTAttState11(void) {
    s16 offsetX;
    u16 mainLayoutCount;

    gRecordTAtt->mStateFrames++;
    if (gRecordTAtt->mClearChosen != FALSE) {
        offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
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
    if (gRecordTAtt->mStateFrames >= 10) {
        if (IsTxtSystemState0NoOpenRequest() != 0) {
            RequestRecordTAttState12();
        }
    }
}

void AdvanceRecordTAttState12(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    if (gRecordTAtt->mClearChosen != FALSE) {
        u16 w;

        gRecordTAtt->mBg1OffsetX = offsetX;
        w = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 4].mOffsetX = offsetX;
    }
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            RequestRecordTAttState2();
        }
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAttState13(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        RequestRecordTAttState14();
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttState14(void) {
    int txtSystemNoCloseRequest;
    txtSystemNoCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (txtSystemNoCloseRequest != 0) {
        RequestRecordTAttState15();
    }
}

void AdvanceRecordTAttState15(void) {
    InputSlotIndex slotIndex;
    u16 f;
    BOOL recentlyLost;

    slotIndex = UNK_02175628_INDEX_8;
    f = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (f == 0) {
        f = 0;
        recentlyLost = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            f = 1;
        }
        if (f == 0 || IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                      gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            return;
        }
    }
    RequestRecordTAttState16();
    RequestSelectReturnState3WithSound(0);
}

void AdvanceRecordTAttState16(void) {
    int txtSystemNoOpenRequest;
    txtSystemNoOpenRequest = IsTxtSystemState0NoOpenRequest();
    if (txtSystemNoOpenRequest != 0) {
        RequestRecordTAttState17();
    }
}

void AdvanceRecordTAttState17(void) {
    s32 i;
    s32 j;
    u16 subLayoutCount;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        RequestRecordTAttState2();
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAtt(void) {
    RecordTAtt *recordTAtt;

    gRecordTAtt->mState = gRecordTAtt->mNextState;
    switch (gRecordTAtt->mState) {
        case 0:
            AdvanceRecordTAttState0();
            break;
        case 1:
            AdvanceRecordTAttState1();
            break;
        case 2:
            AdvanceRecordTAttState2();
            break;
        case 3:
            AdvanceRecordTAttState3();
            break;
        case 4:
            AdvanceRecordTAttState4();
            break;
        case 5:
            AdvanceRecordTAttState5();
            break;
        case 6:
            AdvanceRecordTAttState6();
            break;
        case 7:
            AdvanceRecordTAttState7();
            break;
        case 8:
            AdvanceRecordTAttState8();
            break;
        case 9:
            AdvanceRecordTAttState9();
            break;
        case 10:
            AdvanceRecordTAttState10();
            break;
        case 11:
            AdvanceRecordTAttState11();
            break;
        case 12:
            AdvanceRecordTAttState12();
            break;
        case 13:
            AdvanceRecordTAttState13();
            break;
        case 14:
            AdvanceRecordTAttState14();
            break;
        case 15:
            AdvanceRecordTAttState15();
            break;
        case 16:
            AdvanceRecordTAttState16();
            break;
        case 17:
            AdvanceRecordTAttState17();
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

    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    mainDisplayBits |= 0x13;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    subDisplayBits |= 9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
}

void RegisterRecordTAttCallbacks(void) {
    RecordScreenCallbacks a = gRecordTAttCallbacks;

    SetRecordScreenCallbacks(&a);
}
