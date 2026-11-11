#include "01/code_0219c784.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037000.h"
#include "01/unk_021a9000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_0201ea58.h"
#include "code_0214a390.h"
#include "registers.h"

const u8 gSelectBattleStageNegatedYCells[] = {0};
const u8 gSelectBattleStageSecondXCells[] = {0, 1};
const u8 gSelectBattleStageMNscrCopyDestination[] = {9, 7};
const u8 gSelectBattleStageOffsetYCells[] = {1, 2, 3};
const u8 gSelectBattleStageXCells[] = {4, 5, 6};
const u8 gSelectBattleStageBnblRectIndices[6] = {0, 1, 2, 3, 4, 5};
const s8 gSelectBattleStageOffsets[] = {0, -2, -3, -4, -3, -2};
const u8 gSelectBattleStageMNscrIndices[] = {0, 0, 1, 1, 2, 2};
const u8 gSelectBattleStageSTableIndices[6][3] = {{0, 12, 6}, {1, 13, 7},  {2, 14, 8},
                                                  {3, 15, 9}, {4, 16, 10}, {5, 17, 11}};
const SelectBattleStageNscrRect gSelectBattleStageNscrRects[] = {
    {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16},
};
SelectBattleStage *gSelectBattleStage;

void InitSelectBattleStage(void *parentHeap, s32 d, void *mainOam, void *subOam) {
    s32 i, j;
    void *heap;
    void *bmgEntry;

    heap = CreateExpHeapFromMaxFree(parentHeap);
    gSelectBattleStage = HeapAlloc(heap, 0x1088);
    gSelectBattleStage->mHeap = heap;
    gSelectBattleStage->mState = 0;
    gSelectBattleStage->mNextState = 0;
    gSelectBattleStage->mIndex = 0;
    gSelectBattleStage->mStateFrames = 0;
    gSelectBattleStage->mOffsetTimer = 0;
    gSelectBattleStage->mOffset = 0;
    gSelectBattleStage->mHighlightVisible = TRUE;
    gSelectBattleStage->mResult = -4;
    gSelectBattleStage->mMenuMessages = FindSceneFile("menu.bmg");
    gSelectBattleStage->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    LocateAndQueueSelectBattleStage();
    CopyAndQueueSelectBattleStageNscrRect();
    for (i = 0; i < 6; i++) {
        SetCellOamModeXlu(gSelectBattleStageSTableIndices[i][0], 1, gSelectBattleStage->mSelectBattleStageSNcer,
                          gSelectBattleStage->mSelectBattleStageBncls[1]);
    }
    gSelectBattleStage->mMainOamList = mainOam;
    gSelectBattleStage->mSubOamList = subOam;
    ResetOamLists(mainOam, subOam);
    for (i = 0; i < 2; i++) {
        InitLayoutTable(gSelectBattleStage->mHeap, gSelectBattleStage->mSelectBattleStageBncls[i],
                        gSelectBattleStage->mSelectBattleStageBnlls[i],
                        &gSelectBattleStage->mSelectBattleStageTables[i]);
    }
    gSelectBattleStage->mSelectBattleStageTables[0][0].mOffsetY = -0xa0;
    gSelectBattleStage->mSlideOffsetY = 0xa0;
    UpdateSelectBattleStageCellOffsets();
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX = 0xdc;
        }
    }
    {
        u8 a[2] = {0, 1};
        u8 b[2] = {5, 6};
        s32 rem = 0x8000;

        bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 6);
        if (d == 0) {
            bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 7);
        }
        for (i = 0; i < 2; i++) {
            rem -= InitLabelCanvas(gSelectBattleStage->mHeap, a[i], gSelectBattleStage->mSelectBattleStageBnlls[0],
                                   0xa8, 13, b[i], gSelectBattleStage->mSelectBattleStageMNcer,
                                   gSelectBattleStage->mSelectBattleStageBncls[0],
                                   gSelectBattleStage->mSelectBattleStageTables[0], rem);
            PrintLabelLayoutTextNoFixedAdvance(0, a[i], gSelectBattleStage->mSelectBattleStageBnlls[0], bmgEntry,
                                               gSelectBattleStage->mSelectBattleStageBncls[0],
                                               gSelectBattleStage->mSelectBattleStageTables[0]);
        }
        if (d == 1) {
            gSelectBattleStage->mSelectBattleStageTables[0][5].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[0][6].mVisible = 0;
        }
    }
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    SetSelectReturnSoundId(14);
}

void ReleaseSelectBattleStage(void) {
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x1e10;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    HeapDestroy(gSelectBattleStage->mHeap);
    gSelectBattleStage = NULL;
}

void LocateAndQueueSelectBattleStage(void) {
    volatile u16 z;
    Ncgr *ncgrMB;
    Nclr *nclrMB;
    Nclr *nclrMO;
    Nclr *nclrSO;

    LocateNcgr(&ncgrMB, FindSceneFile("mg/select_battle_stage_m_b.ncgr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[0], FindSceneFile("mg/select_battle_stage_m_00.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[1], FindSceneFile("mg/select_battle_stage_m_01.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[2], FindSceneFile("mg/select_battle_stage_m_02.nscr"));
    LocateNclr(&nclrMB, FindSceneFile("mg/select_battle_stage_m_b.nclr"));
    gSelectBattleStage->mSelectBattleStageBncls[0] = FindSceneFile("mg/select_battle_stage_m.bncl");
    gSelectBattleStage->mSelectBattleStageBnbls[0] = NULL;
    gSelectBattleStage->mSelectBattleStageBnlls[0] = FindSceneFile("mg/select_battle_stage_m.bnll");
    gSelectBattleStage->mSelectBattleStageBncls[1] = FindSceneFile("mg/select_battle_stage_s.bncl");
    gSelectBattleStage->mSelectBattleStageBnbls[1] = FindSceneFile("mg/select_battle_stage_s.bnbl");
    gSelectBattleStage->mSelectBattleStageBnlls[1] = NULL;
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageMNcgr, FindSceneFile("mg/select_battle_stage_m.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageMNcer, FindSceneFile("mg/select_battle_stage_m.nce.ncer"));
    LocateNclr(&nclrMO, FindSceneFile("mg/select_battle_stage_m_o.nclr"));
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageSNcgr, FindSceneFile("mg/select_battle_stage_s.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageSNcer, FindSceneFile("mg/select_battle_stage_s.nce.ncer"));
    LocateNclr(&nclrSO, FindSceneFile("mg/select_battle_stage_s_o.nclr"));
    z = 0;
    MIi_CpuClear16(z, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(6, 0, ncgrMB->mData, ncgrMB->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(10, 0, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(15, 0, nclrMB->mData, 0x180);
    NNS_GfdRegisterNewVramTransferTask(19, 0, gSelectBattleStage->mSelectBattleStageMNcgr->mData,
                                       gSelectBattleStage->mSelectBattleStageMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(14, 0, nclrMO->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(14, 0x1c0, nclrMO->mData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(35, 0, gSelectBattleStage->mSelectBattleStageSNcgr->mData,
                                       gSelectBattleStage->mSelectBattleStageSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(30, 0, nclrSO->mData, nclrSO->mDataSize);
}

void CopyAndQueueSelectBattleStageNscrRect(void) {
    s32 x, y;
    s32 idx = gSelectBattleStage->mIndex;
    u8 src = gSelectBattleStageMNscrIndices[idx];

    for (y = 0; y <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastRow -
                         gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow;
         y++) {
        for (x = 0; x <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastColumn -
                             gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn;
             x++) {
            (gSelectBattleStage->mSelectBattleStageMNscrCopy[gSelectBattleStageMNscrCopyDestination[1] + y] +
             gSelectBattleStageMNscrCopyDestination[0])[x] =
                *((u16 *) gSelectBattleStage->mSelectBattleStageMNscrs[src]->mData + x +
                  gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn +
                  (gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow + y) * 32);
        }
    }
    NNS_GfdRegisterNewVramTransferTask(10, 0, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x600);
}

void UpdateSelectBattleStageCellOffsets(void) {
    s32 i;
    u16 layoutCount = gSelectBattleStage->mSelectBattleStageBncls[0]->mCount;

    for (i = 0; i < 1; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageNegatedYCells[i]].mOffsetY =
            -gSelectBattleStage->mSlideOffsetY;
    }
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageOffsetYCells[i]].mOffsetY =
            gSelectBattleStage->mOffset - gSelectBattleStage->mSlideOffsetY;
    }
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageXCells[i]].mOffsetX =
            gSelectBattleStage->mSlideOffsetX;
    }
    for (i = 0; i < 2; i++) {
        (gSelectBattleStage->mSelectBattleStageTables[0] + layoutCount)[gSelectBattleStageSecondXCells[i]].mOffsetX =
            gSelectBattleStage->mSlideOffsetX;
    }
}

void AdvanceSelectBattleStageState0(void) {
    s32 i, j;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > 20) {
        gSelectBattleStage->mNextState = 1;
        gSelectBattleStage->mStateFrames = 0;
        gSelectBattleStage->mNextState = 1;
        RequestSelectReturnState1();
    } else if (gSelectBattleStage->mStateFrames > 10) {
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                    GetSelectedPressOffset(gSelectBattleStage->mStateFrames - 10);
            }
        }
    } else {
        gSelectBattleStage->mSlideOffsetY = InterpolateS16(1, 0xa0, 0, gSelectBattleStage->mStateFrames, 10);
        gSelectBattleStage->mSlideOffsetX = InterpolateS16(1, -0x100, 0, gSelectBattleStage->mStateFrames, 10);
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                    InterpolateS16(1, 0xdc, 0, gSelectBattleStage->mStateFrames, 10);
            }
        }
    }
}

void AdvanceSelectBattleStageState1(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gSelectBattleStage->mNextState = 2;
    }
}

void AdvanceSelectBattleStageState2(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    s32 touchedRect = -1;
    s32 touchedStage = -4;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost;
    s32 i;
    s32 previousIndex;
    u16 hasPair;

    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gSelectBattleStage->mSelectBattleStageBnbls[1],
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    for (i = 0; i < 6; i++) {
        if (touchedRect == gSelectBattleStageBnblRectIndices[i]) {
            touchedStage = i;
        }
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
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
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    if (gMenuShared->mMenuEntryKind == 2) {
        gSelectBattleStage->mNextState = 4;
        RequestSelectReturnState3WithSound(0);
        gSelectBattleStage->mUnk_2c = FALSE;
        return;
    }
    gSelectBattleStage->mNextState = 6;
    gSelectBattleStage->mPendingResult = -3;
    if (gStartupWork->mConnectionKind == 0) {
        RequestSelectReturnState3WithSound(0);
        gSelectBattleStage->mUnk_2c = FALSE;
        return;
    }
    RequestSelectReturnState3WithSound(1);
    gSelectBattleStage->mUnk_2c = TRUE;
    return;
next:
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 || touchedStage != -4) {
        previousIndex = gSelectBattleStage->mIndex;
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) == 0) {
            gSelectBattleStage->mIndex = touchedStage;
        }
        if (gSelectBattleStage->mIndex == previousIndex) {
            gSelectBattleStage->mHighlightVisible = FALSE;
        }
        gSelectBattleStage->mPendingResult = gSelectBattleStage->mIndex;
        gSelectBattleStage->mNextState = 3;
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectBattleStage->mIndex--;
        if (gSelectBattleStage->mIndex < 0) {
            gSelectBattleStage->mIndex = 5;
        }
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectBattleStage->mIndex++;
        if (gSelectBattleStage->mIndex >= 6) {
            gSelectBattleStage->mIndex = 0;
        }
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(0);
    }
}

void AdvanceSelectBattleStageState3(void) {
    s32 i;
    s16 offsetX;

    gSelectBattleStage->mStateFrames++;
    offsetX = GetSelectedPressOffset(gSelectBattleStage->mStateFrames);
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[gSelectBattleStage->mIndex][i]]
            .mOffsetX = offsetX;
    }
    if (gSelectBattleStage->mStateFrames >= 10) {
        gSelectBattleStage->mNextState = 5;
        gSelectBattleStage->mStateFrames = 0;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mCommonMessages, 4),
                           GetBmgEntry(gSelectBattleStage->mCommonMessages, 2), 0);
        SetSelectChoisesSoundId(0, 7);
        SetSelectChoisesSoundId(1, 0x10);
    } else if (gSelectBattleStage->mStateFrames >= 5) {
        gSelectBattleStage->mHighlightVisible = TRUE;
    }
}

void AdvanceSelectBattleStageState4(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        gSelectBattleStage->mPendingResult = -2;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x14),
                           GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x15), 0);
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xc);
        gSelectBattleStage->mNextState = 5;
    }
}

void AdvanceSelectBattleStageState5(void) {
    if (GetSelectChoisesDone() != 0) {
        if (gSelectBattleStage->mPendingResult == -2 || gSelectBattleStage->mPendingResult == -1) {
            if (GetSelectChoisesIndex() == 1) {
                gSelectBattleStage->mNextState = 6;
            } else {
                gSelectBattleStage->mNextState = 2;
            }
        } else {
            if (GetSelectChoisesIndex() == 0) {
                gSelectBattleStage->mNextState = 6;
                RequestSelectReturnState4();
                gSelectBattleStage->mUnk_2c = TRUE;
            } else {
                gSelectBattleStage->mNextState = 2;
            }
        }
        RequestSelectChoisesState0();
    }
}

void AdvanceSelectBattleStageState6(void) {
    s32 i;
    s32 j;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > 10) {
        if ((gSelectBattleStage->mUnk_2c != FALSE && IsSelectReturnState0NoState1Request() != 0) ||
            (gSelectBattleStage->mUnk_2c == FALSE && IsSelectReturnState2NoState3Or4Request() != 0)) {
            gSelectBattleStage->mResult = gSelectBattleStage->mPendingResult;
            return;
        }
    }
    if (gSelectBattleStage->mStateFrames > 10) {
        gSelectBattleStage->mStateFrames = 10;
    }
    gSelectBattleStage->mSlideOffsetY = InterpolateS16(1, 0, 0xa0, gSelectBattleStage->mStateFrames, 10);
    gSelectBattleStage->mSlideOffsetX = InterpolateS16(1, 0, -0x100, gSelectBattleStage->mStateFrames, 10);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                InterpolateS16(1, 0, 0xdc, gSelectBattleStage->mStateFrames, 10);
        }
    }
}

void UpdateSelectBattleStageHighlight(void) {
    s32 i;
    BOOL zero = FALSE;

    for (i = 0; i < 6; i++) {
        if (i == gSelectBattleStage->mIndex && gSelectBattleStage->mHighlightVisible != FALSE) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][1]].mVisible = 1;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][2]].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][1]].mVisible = zero;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][2]].mVisible = 1;
        }
    }
}

void AdvanceSelectBattleStageOffsetTimer(void) {
    if (gSelectBattleStage->mOffsetTimer > 0) {
        gSelectBattleStage->mOffsetTimer--;
    }
    gSelectBattleStage->mOffset = gSelectBattleStageOffsets[gSelectBattleStage->mOffsetTimer];
}

s32 AdvanceSelectBattleStage(void) {
    s32 i;

    gSelectBattleStage->mState = gSelectBattleStage->mNextState;
    switch (gSelectBattleStage->mState) {
        case 0:
            AdvanceSelectBattleStageState0();
            break;
        case 1:
            AdvanceSelectBattleStageState1();
            break;
        case 2:
            AdvanceSelectBattleStageState2();
            break;
        case 3:
            AdvanceSelectBattleStageState3();
            break;
        case 4:
            AdvanceSelectBattleStageState4();
            break;
        case 5:
            AdvanceSelectBattleStageState5();
            break;
        case 6:
            AdvanceSelectBattleStageState6();
            break;
    }
    AdvanceSelectBattleStageOffsetTimer();
    UpdateSelectBattleStageHighlight();
    UpdateSelectBattleStageCellOffsets();
    CopyAndQueueSelectBattleStageNscrRect();
    for (i = 0; i < 2; i++) {
        DrawLayoutTable(gSelectBattleStage->mSelectBattleStageBncls[i],
                        (&gSelectBattleStage->mSelectBattleStageMNcer)[i],
                        gSelectBattleStage->mSelectBattleStageBnlls[i], (&gSelectBattleStage->mMainOamList)[i],
                        gSelectBattleStage->mSelectBattleStageTables[i]);
    }
    return gSelectBattleStage->mResult;
}

void WriteSelectBattleStageRegisters(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1c00;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 1;
    reg_G2_BLDCNT = 0;
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG2OFS = ((gSelectBattleStage->mSlideOffsetY - gSelectBattleStage->mOffset) << 16) & 0x1ff0000;
}
