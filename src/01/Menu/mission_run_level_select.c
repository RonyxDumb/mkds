#include "01/Menu/mission_run_level_select.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_02148950.h"
#include "01/unk_021a9000.h"
#include "01/unk_021ca000.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"

const s16 gMissionRunLVselRightIndexOffsets[7] = {1, 1, 0, 1, 1, 0, 0};
const s16 gMissionRunLVselLeftIndexOffsets[7] = {0, -1, -1, 0, -1, -1, 0};
const s16 gMissionRunLVselDownIndexOffsets[7] = {3, 3, 3, 0, 2, 0, 0};
const s16 gMissionRunLVselUpIndexOffsets[7] = {0, 0, 0, -3, -3, -3, -2};
const u16 gMissionRunLVselGradeLabelIndices[7] = {0, 1, 2, 3, 4, 5, 6};
const u16 gMissionRunLVselGradeLabelHeights[7] = {0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe};
const u16 gMissionRunLVselGradeLabelWidths[7] = {0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe};
const u16 gMissionRunLVselLevelCellIndices[7][11] = {{0, 7, 0xe, 0x15, 0x1c, 0x23, 0x2a, 0x31, 0x38, 0x39, 0x3a}, {1, 8, 0xf, 0x16, 0x1d, 0x24, 0x2b, 0x32, 0x3b, 0x3c, 0x3d}, {2, 9, 0x10, 0x17, 0x1e, 0x25, 0x2c, 0x33, 0x3e, 0x3f, 0x40}, {3, 0xa, 0x11, 0x18, 0x1f, 0x26, 0x2d, 0x34, 0x41, 0x42, 0x43}, {4, 0xb, 0x12, 0x19, 0x20, 0x27, 0x2e, 0x35, 0x44, 0x45, 0x46}, {5, 0xc, 0x13, 0x1a, 0x21, 0x28, 0x2f, 0x36, 0x47, 0x48, 0x49}, {6, 0xd, 0x14, 0x1b, 0x22, 0x29, 0x30, 0x37, 0x4a, 0x4b, 0x4c}};
const s16 gMissionRunLVselTouchLevelIndices[7] = {0, 1, 2, 3, 4, 5, 6};
MissionRunLVsel *gMissionRunLVsel;

void LoadMissionRunLVselData(void) {
    Ncgr *missionRunLVselSNcgr = NULL;
    Unk02021dc8 *missionRunLVselSNcer = NULL;
    Nclr *missionRunLVselSONclr = NULL;
    Ncgr *missionRunLVselMBNcgr = NULL;
    Nscr *missionRunLVselMNscr = NULL;
    Nclr *missionRunLVselMBNclr = NULL;

    LoadNcgrData(&missionRunLVselMBNcgr, FindSceneFile(gMissionRunLVselMBNcgrName));
    LoadNscrData(&missionRunLVselMNscr, FindSceneFile(gMissionRunLVselMNscrName));
    LoadNclrData(&missionRunLVselMBNclr, FindSceneFile(gMissionRunLVselMBNclrName));
    LoadNcgrData2(&missionRunLVselSNcgr, FindSceneFile(gMissionRunLVselSNcgrName));
    LoadNcerData(&missionRunLVselSNcer, FindSceneFile(gMissionRunLVselSNcerName));
    LoadNclrData(&missionRunLVselSONclr, FindSceneFile(gMissionRunLVselSONclrName));
}

void LocateAndQueueMissionRunLVsel(void) {
    Ncgr *missionRunLVselSNcgr = NULL;
    Nclr *missionRunLVselSONclr = NULL;
    Ncgr *missionRunLVselMBNcgr = NULL;
    Nscr *missionRunLVselMNscr = NULL;
    Nclr *missionRunLVselMBNclr = NULL;

    LocateNcgr(&missionRunLVselMBNcgr, FindSceneFile(gMissionRunLVselMBNcgrName));
    LocateNscr(&missionRunLVselMNscr, FindSceneFile(gMissionRunLVselMNscrName));
    LocateNclr(&missionRunLVselMBNclr, FindSceneFile(gMissionRunLVselMBNclrName));
    if (gMissionRunLVsel->mReachedLevel >= 6) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Bncl = FindSceneFile(gMissionRunLVselS7BnclName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl = FindSceneFile(gMissionRunLVselS7BnblName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnll = FindSceneFile(gMissionRunLVselS7BnllName);
    } else {
        gMissionRunLVsel->mMissionRunLVselS7Or6Bncl = FindSceneFile(gMissionRunLVselS6BnclName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl = FindSceneFile(gMissionRunLVselS6BnblName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnll = FindSceneFile(gMissionRunLVselS6BnllName);
    }
    LocateNcgr2(&missionRunLVselSNcgr, FindSceneFile(gMissionRunLVselSNcgrName));
    LocateNcer(&gMissionRunLVsel->mMissionRunLVselSNcer, FindSceneFile(gMissionRunLVselSNcerName));
    LocateNclr(&missionRunLVselSONclr, FindSceneFile(gMissionRunLVselSONclrName));
    gMissionRunLVsel->mUnk_14 = HeapAlloc(gMissionRunLVsel->mHeap, 0x800);
    NNS_GfdRegisterNewVramTransferTask(4, 0, missionRunLVselMBNcgr->mData, missionRunLVselMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, missionRunLVselMNscr->mData, missionRunLVselMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gMissionRunLVsel->mUnk_14, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, missionRunLVselMBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, missionRunLVselSNcgr->mData, missionRunLVselSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, missionRunLVselSONclr->mData, missionRunLVselSONclr->mDataSize);
}

s32 GetMissionRunLVselMinRecordValue(s16 levelIndex) {
    s32 i;
    s32 result;
    s32 recordValue;
    u8 levelNumber;

    result = 8;
    i = 0;
    levelNumber = levelIndex + 1;

    for (; i < 9; i++) {
        if (GetMissionRecordValue(levelNumber, (u8) (i + 1), &recordValue)) {
            if (recordValue < result) {
                result = recordValue;
            }
        } else {
            result = 9;
        }
    }
    return result;
}

u32 IsMissionRunLVselLevelReached(int levelIndex) {
    if (gMissionRunLVsel->mReachedLevel >= levelIndex) {
        return 1;
    }
    return 0;
}

void RefreshMissionRunLVselLevelCells(void) {
    s32 i;
    u16 layoutCount;
    s32 minRecordValue;
    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][0]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][4]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][5]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][6]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][7]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][8]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][9]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][10]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[i]].mVisible = 0;
        if (IsMissionRunLVselLevelReached((s16) i)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][1]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][5]].mVisible = 1;
            minRecordValue = GetMissionRunLVselMinRecordValue(i);
            if (minRecordValue <= 4) {
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][7]].mVisible = 1;
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[i]]
                    .mVisible = 1;
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gMissionRunLVselGradeLabelIndices[i], gMissionRunLVsel->mMissionRunLVselS7Or6Bnll,
                    gMissionRunLVselGradeStrings[minRecordValue], gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Table);
            } else if (minRecordValue <= 7) {
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][minRecordValue + 3]]
                    .mVisible = 1;
            }
        } else if (i != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][4]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][6]].mVisible = 1;
        }
        SetCellOamModeXlu(gMissionRunLVselLevelCellIndices[i][0], 1, gMissionRunLVsel->mMissionRunLVselSNcer,
                          gMissionRunLVsel->mMissionRunLVselS7Or6Bncl);
    }
}

void UpdateMissionRunLVselHighlight(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][4]].mVisible = 0;
        if (gMissionRunLVsel->mHighlightTimers[i] > 0) {
            gMissionRunLVsel->mHighlightTimers[i] = gMissionRunLVsel->mHighlightTimers[i] - 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][3]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][3]].mOffsetY =
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][2]].mOffsetY + 1;
        } else if (gMissionRunLVsel->mIndex == i) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][2]].mVisible = 1;
        } else if (IsMissionRunLVselLevelReached((s16) i)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][1]].mVisible = 1;
        } else if (i != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][4]].mVisible = 1;
        }
    }
}

void RefreshMissionRunLVselReachedLevel(void) {
    BOOL all = TRUE;
    s32 i = 0;
    s32 ok;
    s32 j;
    s32 recordValue;
    u8 levelNumber;
    gMissionRunLVsel->mReachedLevel = 0;
    for (i = 0; i < 7; i++) {
        ok = 1;
        j = 0;
        levelNumber = i + 1;
        for (; j < 9; j++) {
            ok &= GetMissionRecordValue(levelNumber, (u8) (j + 1), &recordValue);
            if (!ok || recordValue < 5) {
                all = FALSE;
            }
        }
        if (ok) {
            if (i == 5) {
                if (all) {
                    gMissionRunLVsel->mReachedLevel = i + 1;
                }
            } else {
                gMissionRunLVsel->mReachedLevel = i + 1;
            }
        }
    }
}

void SetMissionTableToSelectedLevel(void) {
    SetMissionTableRow((gMissionRunLVsel->mIndex + 1) * 0x1000000 >> 0x18);
    SetMissionTableColumn(1);
}

BOOL IsMissionRunLVselLastRecordMissing(void) {
    s32 i;
    s32 ok = 1;
    s32 result;
    s32 recordValue;

    for (i = 0; i < 8; i++) {
        ok &= GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), (u8) (i + 1), &recordValue);
    }
    result = GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), 9, &recordValue);
    if (ok != 0 && result == 0) {
        return TRUE;
    }
    return FALSE;
}

void ResetMissionRunLVsel(void) {
    s32 i;
    s32 j;
    s32 layoutCount;

    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    i = 0;
    gMissionRunLVsel->mNextState = 0;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mBg0Offset = -192;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][j]].mOffsetX = 0x100;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[i]].mOffsetX =
            0x100;
    }
}

void RequestMissionRunLVselState1(void) {
    gMissionRunLVsel->mNextState = 1;
    gMissionRunLVsel->mStateFrames = 0;
    if (GetPreviousMenuScreenNumber() == SCREEN_MISSION_RUN_MSSEL) {
        gMissionRunLVsel->mSlideOffsetX = -256;
    } else {
        gMissionRunLVsel->mSlideOffsetX = 0x100;
    }
}

void RequestMissionRunLVselState2(void) {
    gMissionRunLVsel->mNextState = 2;
    gMissionRunLVsel->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceMissionRunLVsel call copies it to
// mState and runs AdvanceMissionRunLVselState3.
void RequestMissionRunLVselState3(void) {
    gMissionRunLVsel->mNextState = 3;
    gMissionRunLVsel->mStateFrames = 0;
}

void RequestMissionRunLVselState4(void) {
    gMissionRunLVsel->mNextState = 4;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mSlideOffsetX = 0x100;
    SetMissionTableToSelectedLevel();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestMissionRunLVselState5(void) {
    gMissionRunLVsel->mNextState = 5;
    gMissionRunLVsel->mStateFrames = 0;
    switch (gMissionRunLVsel->mResult) {
        case 1:
            if (IsMissionRunLVselLastRecordMissing() != FALSE) {
                StopMissionRunLVselSeqsWithSteps(3, 10);
            } else {
                StopMissionRunLVselSeqsWithSteps(0, 10);
            }
            break;
        case 2:
            StopMissionRunLVselSeqsWithSteps(4, 10);
            break;
    }
}

void InitMissionRunLVsel(void *parentHeap, void *mainOam, void *subOam) {
    s32 i;
    s32 remainingSize;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    {
        void *heap = CreateFrmHeapFromMaxFree(parentHeap);

        gMissionRunLVsel = HeapAlloc(heap, 0x5c);
        gMissionRunLVsel->mHeap = heap;
    }
    gMissionRunLVsel->mState = 0;
    gMissionRunLVsel->mMainOam = mainOam;
    gMissionRunLVsel->mSubOam = subOam;
    gMissionRunLVsel->mResult = 0;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mHighlightTimers[i] = 0;
    }
    if (gMenuShared->mLVselIndex6Requested != 0) {
        gMissionRunLVsel->mIndex = 6;
        gMenuShared->mLVselIndex6Requested = 0;
        StartMissionRunLVselSeq(2);
    } else {
        gMissionRunLVsel->mIndex = GetMissionTableRow() - 1;
        if (GetPreviousMenuScreenNumber() == 0x1f) {
            StartMissionRunLVselSeq(1);
        } else {
            StartMissionRunLVselSeq(0);
        }
    }
    RefreshMissionRunLVselReachedLevel();
    LocateAndQueueMissionRunLVsel();
    ResetOamLists(gMissionRunLVsel->mMainOam, gMissionRunLVsel->mSubOam);
    InitLayoutTable(gMissionRunLVsel->mHeap, gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, &gMissionRunLVsel->mMissionRunLVselS7Or6Table);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 7; i++) {
        remainingSize -= InitLabelCanvas(
            gMissionRunLVsel->mHeap, gMissionRunLVselGradeLabelIndices[i], gMissionRunLVsel->mMissionRunLVselS7Or6Bnll,
            gMissionRunLVselGradeLabelWidths[i], gMissionRunLVselGradeLabelHeights[i],
            gMissionRunLVselLevelCellIndices[i][7], gMissionRunLVsel->mMissionRunLVselSNcer,
            gMissionRunLVsel->mMissionRunLVselS7Or6Bncl, gMissionRunLVsel->mMissionRunLVselS7Or6Table, remainingSize);
    }
    RefreshMissionRunLVselLevelCells();
    ResetMissionRunLVsel();
    FrmHeapShrinkInParent(gMissionRunLVsel->mHeap);
}

void ReleaseMissionRunLVsel(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    switch (gMissionRunLVsel->mResult) {
        case 1:
            if (IsMissionRunLVselLastRecordMissing() != FALSE) {
                StopMissionRunLVselSeqsWithSteps(3, 10);
            } else {
                StopMissionRunLVselSeqsWithSteps(0, 10);
            }
            break;
        case 2:
            StartSceneSeqAfterMissionRunLVsel(4);
            break;
    }
    HeapDestroy(gMissionRunLVsel->mHeap);
    gMissionRunLVsel = NULL;
}

void AdvanceMissionRunLVselState0(void) {
    int fadesClear;
    StartSceneSeqIfIdle();
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestMissionRunLVselState1();
    }
}

void AdvanceMissionRunLVselState1(void) {
    s32 i;
    s32 j;
    s32 layoutCount;
    s16 offsetX;

    StartSceneSeqIfIdle();
    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, gMissionRunLVsel->mSlideOffsetX, 0, gMissionRunLVsel->mStateFrames, 10);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, -192, 0, gMissionRunLVsel->mStateFrames, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][j]].mOffsetX = offsetX;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[i]].mOffsetX =
            offsetX;
    }
    if (gMissionRunLVsel->mStateFrames >= 10) {
        RequestMissionRunLVselState2();
    }
}

void AdvanceMissionRunLVselState2(void) {
    int returnState2NoRequest;
    StartSceneSeqIfIdle();
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        RequestMissionRunLVselState3();
    }
}

void AdvanceMissionRunLVselState3(void) {
    u32 touchedRect = -1;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL touchBegan;
    BOOL recentlyLost;
    s16 targetIndex;

    StartSceneSeqIfIdle();
    touchBegan = FALSE;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl,
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        BOOL touchBeganAgain = FALSE;
        BOOL recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    RequestMissionRunLVselState5();
    gMissionRunLVsel->mSlideOffsetX = 0x100;
    gMissionRunLVsel->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (touchedRect <= 6) {
        targetIndex = gMissionRunLVselTouchLevelIndices[touchedRect];
        if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
            gMissionRunLVsel->mIndex = targetIndex;
            gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
            RequestMissionRunLVselState4();
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
        return;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
        gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
        RequestMissionRunLVselState4();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (gMissionRunLVselUpIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselUpIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (gMissionRunLVselDownIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselDownIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (gMissionRunLVselLeftIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselLeftIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (gMissionRunLVselRightIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselRightIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    }
}

void AdvanceMissionRunLVselState4(void) {
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    StartSceneSeqIfIdle();
    if (gMissionRunLVsel->mStateFrames >= 5) {
        RequestMissionRunLVselState5();
        gMissionRunLVsel->mSlideOffsetX = -256;
        gMissionRunLVsel->mResult = 1;
    }
}

void AdvanceMissionRunLVselState5(void) {
    s32 i;
    s32 j;
    s32 layoutCount;
    s16 offsetX;

    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0, gMissionRunLVsel->mSlideOffsetX, gMissionRunLVsel->mStateFrames, 10);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, 0, -192, gMissionRunLVsel->mStateFrames, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[i][j]].mOffsetX = offsetX;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[i]].mOffsetX =
            offsetX;
    }
}

s32 AdvanceMissionRunLVsel(void) {
    gMissionRunLVsel->mState = gMissionRunLVsel->mNextState;
    switch (gMissionRunLVsel->mState) {
        case 0:
            AdvanceMissionRunLVselState0();
            break;
        case 1:
            AdvanceMissionRunLVselState1();
            break;
        case 2:
            AdvanceMissionRunLVselState2();
            break;
        case 3:
            AdvanceMissionRunLVselState3();
            break;
        case 4:
            AdvanceMissionRunLVselState4();
            break;
        case 5:
            AdvanceMissionRunLVselState5();
            break;
    }
    UpdateMissionRunLVselHighlight();
    DrawLayoutTable(gMissionRunLVsel->mMissionRunLVselS7Or6Bncl, gMissionRunLVsel->mMissionRunLVselSNcer,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, gMissionRunLVsel->mSubOam,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Table);
    if (gMissionRunLVsel->mState == 5 && gMissionRunLVsel->mStateFrames >= 10) {
        return gMissionRunLVsel->mResult;
    }
    return 0;
}

void WriteMissionRunLVselBg0Offset(void) {
    reg_G2_BG0OFS = (-gMissionRunLVsel->mBg0Offset << 16) & 0x1ff0000;
}
