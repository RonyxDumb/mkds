#include "01/Menu/mission_run_level_select.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "code_02148950.h"
#include "01/unk_021a9000.h"
#include "01/unk_021ca000.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const u16 gMissionRunLVselGradeLabelWidths[7] = {0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe};
const u16 gMissionRunLVselGradeLabelIndices[7] = {0, 1, 2, 3, 4, 5, 6};
const u16 gMissionRunLVselGradeLabelHeights[7] = {0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe};
const s16 gMissionRunLVselTouchLevelIndices[7] = {0, 1, 2, 3, 4, 5, 6};
const s16 gMissionRunLVselUpIndexOffsets[7] = {0, 0, 0, -3, -3, -3, -2};
const s16 gMissionRunLVselDownIndexOffsets[7] = {3, 3, 3, 0, 2, 0, 0};
const s16 gMissionRunLVselLeftIndexOffsets[7] = {0, -1, -1, 0, -1, -1, 0};
const u16 gMissionRunLVselLevelCellIndices[7][11] = {{0, 7, 0xe, 0x15, 0x1c, 0x23, 0x2a, 0x31, 0x38, 0x39, 0x3a},
                                                     {1, 8, 0xf, 0x16, 0x1d, 0x24, 0x2b, 0x32, 0x3b, 0x3c, 0x3d},
                                                     {2, 9, 0x10, 0x17, 0x1e, 0x25, 0x2c, 0x33, 0x3e, 0x3f, 0x40},
                                                     {3, 0xa, 0x11, 0x18, 0x1f, 0x26, 0x2d, 0x34, 0x41, 0x42, 0x43},
                                                     {4, 0xb, 0x12, 0x19, 0x20, 0x27, 0x2e, 0x35, 0x44, 0x45, 0x46},
                                                     {5, 0xc, 0x13, 0x1a, 0x21, 0x28, 0x2f, 0x36, 0x47, 0x48, 0x49},
                                                     {6, 0xd, 0x14, 0x1b, 0x22, 0x29, 0x30, 0x37, 0x4a, 0x4b, 0x4c}};
const s16 gMissionRunLVselRightIndexOffsets[7] = {1, 1, 0, 1, 1, 0, 0};
u16 gMissionRunLVselGradeTextB[2] = {0x42, 0};
const char *gMissionRunLVselMBNclrName = gMissionRunLVselMBNclrFileName;
const char *gMissionRunLVselS7BnblName = gMissionRunLVselS7BnblFileName;
u16 gMissionRunLVselGradeTextD[2] = {0x44, 0};
const char *gMissionRunLVselS7BnllName = gMissionRunLVselS7BnllFileName;
u16 gMissionRunLVselGradeTextC[2] = {0x43, 0};
const char *gMissionRunLVselMNscrName = gMissionRunLVselMNscrFileName;
const char *gMissionRunLVselSONclrName = gMissionRunLVselSONclrFileName;
u16 gMissionRunLVselGradeTextE[2] = {0x45, 0};
u16 gMissionRunLVselGradeTextA[2] = {0x41, 0};
const char *gMissionRunLVselS6BnblName = gMissionRunLVselS6BnblFileName;
const char *gMissionRunLVselS6BnllName = gMissionRunLVselS6BnllFileName;
const char *gMissionRunLVselS6BnclName = gMissionRunLVselS6BnclFileName;
const char *gMissionRunLVselMBNcgrName = gMissionRunLVselMBNcgrFileName;
const char *gMissionRunLVselSNcerName = gMissionRunLVselSNcerFileName;
const char *gMissionRunLVselS7BnclName = gMissionRunLVselS7BnclFileName;
const char *gMissionRunLVselSNcgrName = gMissionRunLVselSNcgrFileName;
u16 *gMissionRunLVselGradeStrings[5] = {gMissionRunLVselGradeTextE, gMissionRunLVselGradeTextD,
                                        gMissionRunLVselGradeTextC, gMissionRunLVselGradeTextB,
                                        gMissionRunLVselGradeTextA};
char gMissionRunLVselMNscrFileName[28] = "mr/Mission_run_LVsel_m.nscr";
char gMissionRunLVselS6BnclFileName[30] = "mr/Mission_run_LVsel_s_6.bncl";
char gMissionRunLVselS6BnllFileName[30] = "mr/Mission_run_LVsel_s_6.bnll";
char gMissionRunLVselS7BnclFileName[30] = "mr/Mission_run_LVsel_s_7.bncl";
char gMissionRunLVselS7BnblFileName[30] = "mr/Mission_run_LVsel_s_7.bnbl";
char gMissionRunLVselMBNclrFileName[30] = "mr/Mission_run_LVsel_m_b.nclr";
char gMissionRunLVselSONclrFileName[30] = "mr/Mission_run_LVsel_s_o.nclr";
char gMissionRunLVselS6BnblFileName[30] = "mr/Mission_run_LVsel_s_6.bnbl";
char gMissionRunLVselMBNcgrFileName[30] = "mr/Mission_run_LVsel_m_b.ncgr";
char gMissionRunLVselS7BnllFileName[30] = "mr/Mission_run_LVsel_s_7.bnll";
char gMissionRunLVselSNcgrFileName[32] = "mr/Mission_run_LVsel_s.nce.ncgr";
char gMissionRunLVselSNcerFileName[32] = "mr/Mission_run_LVsel_s.nce.ncer";
MissionRunLVsel *gMissionRunLVsel;

void LoadMissionRunLVselData(void) {
    Ncgr *missionRunLVselSNcgr = NULL;
    NNSG2dCellDataBank *missionRunLVselSNcer = NULL;
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
    if (gMissionRunLVsel->mReachedLevel >= MISSION_RUN_LVSEL_LAST_LEVEL_INDEX) {
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
    gMissionRunLVsel->mVramTransferBuffer = HeapAlloc(gMissionRunLVsel->mHeap, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(4, 0, missionRunLVselMBNcgr->mData, missionRunLVselMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, missionRunLVselMNscr->mData, missionRunLVselMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gMissionRunLVsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, missionRunLVselMBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, missionRunLVselSNcgr->mData, missionRunLVselSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, missionRunLVselSONclr->mData, missionRunLVselSONclr->mDataSize);
}

s32 GetMissionRunLVselMinRecordValue(s16 levelIndex) {
    s32 columnIndex;
    s32 result;
    s32 recordValue;
    u8 levelNumber;

    result = 8;
    columnIndex = 0;
    levelNumber = levelIndex + 1;

    for (; columnIndex < 9; columnIndex++) {
        if (GetMissionRecordValue(levelNumber, (u8) (columnIndex + 1), &recordValue)) {
            if (recordValue < result) {
                result = recordValue;
            }
        } else {
            result = 9;
        }
    }
    return result;
}

u32 IsMissionRunLVselLevelReached(s16 levelIndex) {
    if (gMissionRunLVsel->mReachedLevel >= levelIndex) {
        return 1;
    }
    return 0;
}

void RefreshMissionRunLVselLevelCells(void) {
    s32 levelIndex;
    u16 layoutCount;
    s32 minRecordValue;
    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][0]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][4]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][5]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][6]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][7]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][8]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][9]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][10]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[levelIndex]]
            .mVisible = 0;
        if (IsMissionRunLVselLevelReached(levelIndex)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][1]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][5]].mVisible = 1;
            minRecordValue = GetMissionRunLVselMinRecordValue(levelIndex);
            if (minRecordValue <= 4) {
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][7]].mVisible =
                    1;
                gMissionRunLVsel
                    ->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[levelIndex]]
                    .mVisible = 1;
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gMissionRunLVselGradeLabelIndices[levelIndex], gMissionRunLVsel->mMissionRunLVselS7Or6Bnll,
                    gMissionRunLVselGradeStrings[minRecordValue], gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Table);
            } else if (minRecordValue <= 7) {
                gMissionRunLVsel
                    ->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][minRecordValue + 3]]
                    .mVisible = 1;
            }
        } else if (levelIndex != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][4]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][6]].mVisible = 1;
        }
        SetCellOamModeXlu(gMissionRunLVselLevelCellIndices[levelIndex][0], 1, gMissionRunLVsel->mMissionRunLVselSNcer,
                          gMissionRunLVsel->mMissionRunLVselS7Or6Bncl);
    }
}

void UpdateMissionRunLVselHighlight(void) {
    s32 levelIndex;
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][4]].mVisible = 0;
        if (gMissionRunLVsel->mHighlightTimers[levelIndex] > 0) {
            gMissionRunLVsel->mHighlightTimers[levelIndex] = gMissionRunLVsel->mHighlightTimers[levelIndex] - 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][3]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][3]].mOffsetY =
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][2]].mOffsetY +
                1;
        } else if (gMissionRunLVsel->mIndex == levelIndex) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][2]].mVisible = 1;
        } else if (IsMissionRunLVselLevelReached(levelIndex)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][1]].mVisible = 1;
        } else if (levelIndex != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][4]].mVisible = 1;
        }
    }
}

void RefreshMissionRunLVselReachedLevel(void) {
    BOOL all = TRUE;
    s32 levelIndex = 0;
    s32 ok;
    s32 columnIndex;
    s32 recordValue;
    u8 levelNumber;
    gMissionRunLVsel->mReachedLevel = 0;
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        ok = 1;
        columnIndex = 0;
        levelNumber = levelIndex + 1;
        for (; columnIndex < 9; columnIndex++) {
            ok &= GetMissionRecordValue(levelNumber, (u8) (columnIndex + 1), &recordValue);
            if (!ok || recordValue < 5) {
                all = FALSE;
            }
        }
        if (ok) {
            if (levelIndex == 5) {
                if (all) {
                    gMissionRunLVsel->mReachedLevel = levelIndex + 1;
                }
            } else {
                gMissionRunLVsel->mReachedLevel = levelIndex + 1;
            }
        }
    }
}

void SetMissionTableToSelectedLevel(void) {
    SetMissionTableRow((gMissionRunLVsel->mIndex + 1) * 0x1000000 >> 0x18);
    SetMissionTableColumn(1);
}

BOOL IsMissionRunLVselLastRecordMissing(void) {
    s32 columnIndex;
    s32 ok = 1;
    s32 result;
    s32 recordValue;

    for (columnIndex = 0; columnIndex < 8; columnIndex++) {
        ok &= GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), (u8) (columnIndex + 1), &recordValue);
    }
    result = GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), 9, &recordValue);
    if (ok != 0 && result == 0) {
        return TRUE;
    }
    return FALSE;
}

void ResetMissionRunLVsel(void) {
    s32 levelIndex;
    s32 cellIndex;
    s32 layoutCount;

    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    levelIndex = 0;
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_WAIT_FADE;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mBg0Offset = -192;
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        for (cellIndex = 0; cellIndex < 11; cellIndex++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][cellIndex]]
                .mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[levelIndex]]
            .mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    }
}

void RequestMissionRunLVselSlideIn(void) {
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_SLIDE_IN;
    gMissionRunLVsel->mStateFrames = 0;
    if (GetPreviousMenuScreenNumber() == SCREEN_MISSION_RUN_MSSEL) {
        gMissionRunLVsel->mSlideOffsetX = -LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    } else {
        gMissionRunLVsel->mSlideOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    }
}

void RequestMissionRunLVselWaitSelectReturn(void) {
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_WAIT_SELECT_RETURN;
    gMissionRunLVsel->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

// Requests the select state: stores mNextState and zeroes mStateFrames; the next AdvanceMissionRunLVsel call copies
// it to mState and runs AdvanceMissionRunLVselSelect.
void RequestMissionRunLVselSelect(void) {
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_SELECT;
    gMissionRunLVsel->mStateFrames = 0;
}

void RequestMissionRunLVselHoldChosen(void) {
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_HOLD_CHOSEN;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mSlideOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    SetMissionTableToSelectedLevel();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestMissionRunLVselSlideOut(void) {
    gMissionRunLVsel->mNextState = MISSION_RUN_LVSEL_STATE_SLIDE_OUT;
    gMissionRunLVsel->mStateFrames = 0;
    switch (gMissionRunLVsel->mResult) {
        case MISSION_RUN_LVSEL_RESULT_LEVEL_CHOSEN:
            if (IsMissionRunLVselLastRecordMissing() != FALSE) {
                StopMissionRunLVselSeqsWithSteps(3, 10);
            } else {
                StopMissionRunLVselSeqsWithSteps(0, 10);
            }
            break;
        case MISSION_RUN_LVSEL_RESULT_BACK:
            StopMissionRunLVselSeqsWithSteps(4, 10);
            break;
    }
}

void InitMissionRunLVsel(void *parentHeap, void *mainOam, void *subOam) {
    s32 levelIndex;
    s32 remainingSize;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x9004;
    {
        void *heap = CreateFrmHeapFromMaxFree(parentHeap);

        gMissionRunLVsel = HeapAlloc(heap, sizeof(MissionRunLVsel));
        gMissionRunLVsel->mHeap = heap;
    }
    gMissionRunLVsel->mState = MISSION_RUN_LVSEL_STATE_WAIT_FADE;
    gMissionRunLVsel->mMainOam = mainOam;
    gMissionRunLVsel->mSubOam = subOam;
    gMissionRunLVsel->mResult = MISSION_RUN_LVSEL_RESULT_NONE;
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        gMissionRunLVsel->mHighlightTimers[levelIndex] = 0;
    }
    if (gMenuShared->mLVselIndex6Requested != 0) {
        gMissionRunLVsel->mIndex = MISSION_RUN_LVSEL_LAST_LEVEL_INDEX;
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
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        remainingSize -= InitLabelCanvas(
            gMissionRunLVsel->mHeap, gMissionRunLVselGradeLabelIndices[levelIndex],
            gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, gMissionRunLVselGradeLabelWidths[levelIndex],
            gMissionRunLVselGradeLabelHeights[levelIndex], gMissionRunLVselLevelCellIndices[levelIndex][7],
            gMissionRunLVsel->mMissionRunLVselSNcer, gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
            gMissionRunLVsel->mMissionRunLVselS7Or6Table, remainingSize);
    }
    RefreshMissionRunLVselLevelCells();
    ResetMissionRunLVsel();
    FrmHeapShrinkInParent(gMissionRunLVsel->mHeap);
}

void ReleaseMissionRunLVsel(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
    switch (gMissionRunLVsel->mResult) {
        case MISSION_RUN_LVSEL_RESULT_LEVEL_CHOSEN:
            if (IsMissionRunLVselLastRecordMissing() != FALSE) {
                StopMissionRunLVselSeqsWithSteps(3, 10);
            } else {
                StopMissionRunLVselSeqsWithSteps(0, 10);
            }
            break;
        case MISSION_RUN_LVSEL_RESULT_BACK:
            StartSceneSeqAfterMissionRunLVsel(4);
            break;
    }
    HeapDestroy(gMissionRunLVsel->mHeap);
    gMissionRunLVsel = NULL;
}

void AdvanceMissionRunLVselWaitFade(void) {
    int fadesClear;
    StartSceneSeqIfIdle();
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestMissionRunLVselSlideIn();
    }
}

void AdvanceMissionRunLVselSlideIn(void) {
    s32 levelIndex;
    s32 cellIndex;
    s32 layoutCount;
    s16 offsetX;

    StartSceneSeqIfIdle();
    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, gMissionRunLVsel->mSlideOffsetX, 0, gMissionRunLVsel->mStateFrames,
                             MISSION_RUN_LVSEL_SLIDE_FRAMES);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, -MISSION_RUN_LVSEL_BG0_SLIDE_DISTANCE, 0,
                                                  gMissionRunLVsel->mStateFrames, MISSION_RUN_LVSEL_SLIDE_FRAMES);
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        for (cellIndex = 0; cellIndex < 11; cellIndex++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][cellIndex]]
                .mOffsetX = offsetX;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[levelIndex]]
            .mOffsetX = offsetX;
    }
    if (gMissionRunLVsel->mStateFrames >= MISSION_RUN_LVSEL_SLIDE_FRAMES) {
        RequestMissionRunLVselWaitSelectReturn();
    }
}

void AdvanceMissionRunLVselWaitSelectReturn(void) {
    int returnShownNoRequest;
    StartSceneSeqIfIdle();
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        RequestMissionRunLVselSelect();
    }
}

void AdvanceMissionRunLVselSelect(void) {
    u32 touchedRect = -1;
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL touchBegan;
    BOOL recentlyLost;
    s16 targetIndex;

    StartSceneSeqIfIdle();
    touchBegan = FALSE;
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
        touchedRect = RectTableFindContaining(gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl,
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        BOOL touchBeganAgain = FALSE;
        BOOL recentlyLostAgain = FALSE;
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
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    RequestMissionRunLVselSlideOut();
    gMissionRunLVsel->mSlideOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunLVsel->mResult = MISSION_RUN_LVSEL_RESULT_BACK;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    if (touchedRect <= 6) {
        targetIndex = gMissionRunLVselTouchLevelIndices[touchedRect];
        if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
            gMissionRunLVsel->mIndex = targetIndex;
            gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
            RequestMissionRunLVselHoldChosen();
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
        return;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
        gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
        RequestMissionRunLVselHoldChosen();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (gMissionRunLVselUpIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselUpIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (gMissionRunLVselDownIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselDownIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (gMissionRunLVselLeftIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselLeftIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (gMissionRunLVselRightIndexOffsets[gMissionRunLVsel->mIndex] != 0) {
            targetIndex = gMissionRunLVsel->mIndex + gMissionRunLVselRightIndexOffsets[gMissionRunLVsel->mIndex];
            if (IsMissionRunLVselLevelReached(targetIndex) != 0) {
                gMissionRunLVsel->mIndex = targetIndex;
                gMissionRunLVsel->mHighlightTimers[gMissionRunLVsel->mIndex] = MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
        }
    }
}

void AdvanceMissionRunLVselHoldChosen(void) {
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    StartSceneSeqIfIdle();
    if (gMissionRunLVsel->mStateFrames >= MISSION_RUN_LVSEL_HOLD_FRAMES) {
        RequestMissionRunLVselSlideOut();
        gMissionRunLVsel->mSlideOffsetX = -LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gMissionRunLVsel->mResult = MISSION_RUN_LVSEL_RESULT_LEVEL_CHOSEN;
    }
}

void AdvanceMissionRunLVselSlideOut(void) {
    s32 levelIndex;
    s32 cellIndex;
    s32 layoutCount;
    s16 offsetX;

    layoutCount = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mCount;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0, gMissionRunLVsel->mSlideOffsetX, gMissionRunLVsel->mStateFrames,
                             MISSION_RUN_LVSEL_SLIDE_FRAMES);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, 0, -MISSION_RUN_LVSEL_BG0_SLIDE_DISTANCE,
                                                  gMissionRunLVsel->mStateFrames, MISSION_RUN_LVSEL_SLIDE_FRAMES);
    for (levelIndex = 0; levelIndex < 7; levelIndex++) {
        for (cellIndex = 0; cellIndex < 11; cellIndex++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[gMissionRunLVselLevelCellIndices[levelIndex][cellIndex]]
                .mOffsetX = offsetX;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[layoutCount + gMissionRunLVselGradeLabelIndices[levelIndex]]
            .mOffsetX = offsetX;
    }
}

s32 AdvanceMissionRunLVsel(void) {
    gMissionRunLVsel->mState = gMissionRunLVsel->mNextState;
    switch (gMissionRunLVsel->mState) {
        case MISSION_RUN_LVSEL_STATE_WAIT_FADE:
            AdvanceMissionRunLVselWaitFade();
            break;
        case MISSION_RUN_LVSEL_STATE_SLIDE_IN:
            AdvanceMissionRunLVselSlideIn();
            break;
        case MISSION_RUN_LVSEL_STATE_WAIT_SELECT_RETURN:
            AdvanceMissionRunLVselWaitSelectReturn();
            break;
        case MISSION_RUN_LVSEL_STATE_SELECT:
            AdvanceMissionRunLVselSelect();
            break;
        case MISSION_RUN_LVSEL_STATE_HOLD_CHOSEN:
            AdvanceMissionRunLVselHoldChosen();
            break;
        case MISSION_RUN_LVSEL_STATE_SLIDE_OUT:
            AdvanceMissionRunLVselSlideOut();
            break;
    }
    UpdateMissionRunLVselHighlight();
    DrawLayoutTable(gMissionRunLVsel->mMissionRunLVselS7Or6Bncl, gMissionRunLVsel->mMissionRunLVselSNcer,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, gMissionRunLVsel->mSubOam,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Table);
    if (gMissionRunLVsel->mState == MISSION_RUN_LVSEL_STATE_SLIDE_OUT &&
        gMissionRunLVsel->mStateFrames >= MISSION_RUN_LVSEL_SLIDE_FRAMES) {
        return gMissionRunLVsel->mResult;
    }
    return 0;
}

void WriteMissionRunLVselBg0Offset(void) {
    reg_G2_BG0OFS = (-gMissionRunLVsel->mBg0Offset << 16) & 0x1ff0000;
}
