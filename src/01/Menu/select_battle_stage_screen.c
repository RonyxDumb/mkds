#include "01/Menu/select_battle_stage_screen.h"
#include "01/code_0219d50c.h"
#include "01/unk_021a8000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/followed_kart_or.h"
#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/select_return.h"
#include "01/code_0219c000.h"
#include "Main/Graphics/layout_rect_table.h"
#include "g2.h"
#include "registers.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

void LoadSelectBattleStageData(void) {
    void *v1;
    LoadedPartPointer loaded;
    v1 = FindSceneFile("mg/select_battle_stage_m_b.ncgr");
    LoadNcgrData(&loaded.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_00.nscr");
    LoadNscrData(&loaded.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_01.nscr");
    LoadNscrData(&loaded.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_02.nscr");
    LoadNscrData(&loaded.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_b.nclr");
    LoadNclrData(&loaded.mNclr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m.nce.ncgr");
    LoadNcgrData2(&loaded.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m.nce.ncer");
    LoadNcerData(&loaded.mNcer, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_o.nclr");
    LoadNclrData(&loaded.mNclr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s.nce.ncgr");
    LoadNcgrData2(&loaded.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s.nce.ncer");
    LoadNcerData(&loaded.mNcer, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s_o.nclr");
    LoadNclrData(&loaded.mNclr, v1);
}

const u8 gSelectBattleStageNegatedYCells[1] = {0};
const u8 gSelectBattleStageSecondXCells[2] = {0, 1};
const u8 gSelectBattleStageMNscrCopyDestination[2] = {9, 7};
const u8 gSelectBattleStageOffsetYCells[3] = {1, 2, 3};
const u8 gSelectBattleStageXCells[3] = {4, 5, 6};
const u8 gSelectBattleStageBnblRectIndices[6] = {0, 1, 2, 3, 4, 5};
const s8 gSelectBattleStageOffsets[6] = {0, -2, -3, -4, -3, -2};
const u8 gSelectBattleStageMNscrIndices[6] = {0, 0, 1, 1, 2, 2};
const u8 gSelectBattleStageSTableIndices[6][3] = {{0, 12, 6}, {1, 13, 7},  {2, 14, 8},
                                                  {3, 15, 9}, {4, 16, 10}, {5, 17, 11}};
const SelectBattleStageNscrRect gSelectBattleStageNscrRects[6] = {
    {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16},
};
SelectBattleStage *gSelectBattleStage;

void InitSelectBattleStage(void *parentHeap, s32 variant, void *mainOam, void *subOam) {
    s32 index, cellIndex;
    void *heap;
    void *bmgEntry;

    heap = CreateExpHeapFromMaxFree(parentHeap);
    gSelectBattleStage = HeapAlloc(heap, 0x1088);
    gSelectBattleStage->mHeap = heap;
    gSelectBattleStage->mState = SELECT_BATTLE_STAGE_STATE_SLIDE_IN;
    gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_SLIDE_IN;
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
    for (index = 0; index < 6; index++) {
        SetCellOamModeXlu(gSelectBattleStageSTableIndices[index][0], 1, gSelectBattleStage->mSelectBattleStageSNcer,
                          gSelectBattleStage->mSelectBattleStageBncls[1]);
    }
    gSelectBattleStage->mMainOamList = mainOam;
    gSelectBattleStage->mSubOamList = subOam;
    ResetOamLists(mainOam, subOam);
    for (index = 0; index < 2; index++) {
        InitLayoutTable(gSelectBattleStage->mHeap, gSelectBattleStage->mSelectBattleStageBncls[index],
                        gSelectBattleStage->mSelectBattleStageBnlls[index],
                        &gSelectBattleStage->mSelectBattleStageTables[index]);
    }
    gSelectBattleStage->mSelectBattleStageTables[0][0].mOffsetY = -0xa0;
    gSelectBattleStage->mSlideOffsetY = 0xa0;
    UpdateSelectBattleStageCellOffsets();
    for (index = 0; index < 6; index++) {
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[index][cellIndex]]
                .mOffsetX = 0xdc;
        }
    }
    {
        u8 labelIndices[2] = {0, 1};
        u8 layoutEntryIndices[2] = {5, 6};
        s32 rem = 0x8000;

        bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 6);
        if (variant == 0) {
            bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 7);
        }
        for (index = 0; index < 2; index++) {
            rem -= InitLabelCanvas(
                gSelectBattleStage->mHeap, labelIndices[index], gSelectBattleStage->mSelectBattleStageBnlls[0], 0xa8,
                13, layoutEntryIndices[index], gSelectBattleStage->mSelectBattleStageMNcer,
                gSelectBattleStage->mSelectBattleStageBncls[0], gSelectBattleStage->mSelectBattleStageTables[0], rem);
            PrintLabelLayoutTextNoFixedAdvance(0, labelIndices[index], gSelectBattleStage->mSelectBattleStageBnlls[0],
                                               bmgEntry, gSelectBattleStage->mSelectBattleStageBncls[0],
                                               gSelectBattleStage->mSelectBattleStageTables[0]);
        }
        if (variant == 1) {
            gSelectBattleStage->mSelectBattleStageTables[0][5].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[0][6].mVisible = 0;
        }
    }
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x9e10;
    SetSelectReturnSoundId(14);
}

void ReleaseSelectBattleStage(void) {
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x1e10;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
    HeapDestroy(gSelectBattleStage->mHeap);
    gSelectBattleStage = NULL;
}

void LocateAndQueueSelectBattleStage(void) {
    volatile u16 clearValue;
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
    clearValue = 0;
    MIi_CpuClear16(clearValue, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x1000);
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
    s32 column, row;
    s32 idx = gSelectBattleStage->mIndex;
    u8 src = gSelectBattleStageMNscrIndices[idx];

    for (row = 0; row <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastRow -
                             gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow;
         row++) {
        for (column = 0; column <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastColumn -
                                       gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn;
             column++) {
            (gSelectBattleStage->mSelectBattleStageMNscrCopy[gSelectBattleStageMNscrCopyDestination[1] + row] +
             gSelectBattleStageMNscrCopyDestination[0])[column] =
                *((u16 *) gSelectBattleStage->mSelectBattleStageMNscrs[src]->mData + column +
                  gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn +
                  (gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow + row) * 32);
        }
    }
    NNS_GfdRegisterNewVramTransferTask(10, 0, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x600);
}

void UpdateSelectBattleStageCellOffsets(void) {
    s32 index;
    u16 layoutCount = gSelectBattleStage->mSelectBattleStageBncls[0]->mCount;

    for (index = 0; index < 1; index++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageNegatedYCells[index]].mOffsetY =
            -gSelectBattleStage->mSlideOffsetY;
    }
    for (index = 0; index < 3; index++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageOffsetYCells[index]].mOffsetY =
            gSelectBattleStage->mOffset - gSelectBattleStage->mSlideOffsetY;
    }
    for (index = 0; index < 3; index++) {
        gSelectBattleStage->mSelectBattleStageTables[0][gSelectBattleStageXCells[index]].mOffsetX =
            gSelectBattleStage->mSlideOffsetX;
    }
    for (index = 0; index < 2; index++) {
        (gSelectBattleStage->mSelectBattleStageTables[0] + layoutCount)[gSelectBattleStageSecondXCells[index]]
            .mOffsetX = gSelectBattleStage->mSlideOffsetX;
    }
}

void AdvanceSelectBattleStageState0(void) {
    s32 stageIndex, cellIndex;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > 20) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN;
        gSelectBattleStage->mStateFrames = 0;
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN;
        RequestSelectReturnState1();
    } else if (gSelectBattleStage->mStateFrames > 10) {
        for (stageIndex = 0; stageIndex < 6; stageIndex++) {
            for (cellIndex = 0; cellIndex < 3; cellIndex++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                    .mOffsetX = GetSelectedPressOffset(gSelectBattleStage->mStateFrames - 10);
            }
        }
    } else {
        gSelectBattleStage->mSlideOffsetY = InterpolateS16(1, 0xa0, 0, gSelectBattleStage->mStateFrames, 10);
        gSelectBattleStage->mSlideOffsetX = InterpolateS16(1, -0x100, 0, gSelectBattleStage->mStateFrames, 10);
        for (stageIndex = 0; stageIndex < 6; stageIndex++) {
            for (cellIndex = 0; cellIndex < 3; cellIndex++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                    .mOffsetX = InterpolateS16(1, 0xdc, 0, gSelectBattleStage->mStateFrames, 10);
            }
        }
    }
}

void AdvanceSelectBattleStageState1(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_INPUT;
    }
}

void AdvanceSelectBattleStageState2(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    s32 touchedRect = -1;
    s32 touchedStage = -4;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost;
    s32 stageIndex;
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
    for (stageIndex = 0; stageIndex < 6; stageIndex++) {
        if (touchedRect == gSelectBattleStageBnblRectIndices[stageIndex]) {
            touchedStage = stageIndex;
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
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN_THEN_CHOISES;
        RequestSelectReturnState3WithSound(0);
        gSelectBattleStage->mUnk_2c = FALSE;
        return;
    }
    gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_SLIDE_OUT;
    gSelectBattleStage->mPendingResult = -3;
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
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
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_PRESS_STAGE;
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
    s32 cellIndex;
    s16 offsetX;

    gSelectBattleStage->mStateFrames++;
    offsetX = GetSelectedPressOffset(gSelectBattleStage->mStateFrames);
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gSelectBattleStage
            ->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[gSelectBattleStage->mIndex][cellIndex]]
            .mOffsetX = offsetX;
    }
    if (gSelectBattleStage->mStateFrames >= 10) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_CHOISES;
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
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_CHOISES;
    }
}

void AdvanceSelectBattleStageState5(void) {
    if (GetSelectChoisesDone() != 0) {
        if (gSelectBattleStage->mPendingResult == -2 || gSelectBattleStage->mPendingResult == -1) {
            if (GetSelectChoisesIndex() == 1) {
                gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_SLIDE_OUT;
            } else {
                gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_INPUT;
            }
        } else {
            if (GetSelectChoisesIndex() == 0) {
                gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_SLIDE_OUT;
                RequestSelectReturnState4();
                gSelectBattleStage->mUnk_2c = TRUE;
            } else {
                gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_INPUT;
            }
        }
        RequestSelectChoisesState0();
    }
}

void AdvanceSelectBattleStageState6(void) {
    s32 stageIndex;
    s32 cellIndex;

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
    for (stageIndex = 0; stageIndex < 6; stageIndex++) {
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                .mOffsetX = InterpolateS16(1, 0, 0xdc, gSelectBattleStage->mStateFrames, 10);
        }
    }
}

void UpdateSelectBattleStageHighlight(void) {
    s32 stageIndex;
    BOOL zero = FALSE;

    for (stageIndex = 0; stageIndex < 6; stageIndex++) {
        if (stageIndex == gSelectBattleStage->mIndex && gSelectBattleStage->mHighlightVisible != FALSE) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][1]].mVisible =
                1;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][2]].mVisible =
                0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][1]].mVisible =
                zero;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][2]].mVisible =
                1;
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
    s32 screenIndex;

    gSelectBattleStage->mState = gSelectBattleStage->mNextState;
    switch (gSelectBattleStage->mState) {
        case SELECT_BATTLE_STAGE_STATE_SLIDE_IN:
            AdvanceSelectBattleStageState0();
            break;
        case SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN:
            AdvanceSelectBattleStageState1();
            break;
        case SELECT_BATTLE_STAGE_STATE_INPUT:
            AdvanceSelectBattleStageState2();
            break;
        case SELECT_BATTLE_STAGE_STATE_PRESS_STAGE:
            AdvanceSelectBattleStageState3();
            break;
        case SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN_THEN_CHOISES:
            AdvanceSelectBattleStageState4();
            break;
        case SELECT_BATTLE_STAGE_STATE_CHOISES:
            AdvanceSelectBattleStageState5();
            break;
        case SELECT_BATTLE_STAGE_STATE_SLIDE_OUT:
            AdvanceSelectBattleStageState6();
            break;
    }
    AdvanceSelectBattleStageOffsetTimer();
    UpdateSelectBattleStageHighlight();
    UpdateSelectBattleStageCellOffsets();
    CopyAndQueueSelectBattleStageNscrRect();
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        DrawLayoutTable(gSelectBattleStage->mSelectBattleStageBncls[screenIndex],
                        (&gSelectBattleStage->mSelectBattleStageMNcer)[screenIndex],
                        gSelectBattleStage->mSelectBattleStageBnlls[screenIndex],
                        (&gSelectBattleStage->mMainOamList)[screenIndex],
                        gSelectBattleStage->mSelectBattleStageTables[screenIndex]);
    }
    return gSelectBattleStage->mResult;
}

void WriteSelectBattleStageRegisters(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1c00;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1600;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 1;
    reg_G2_BLDCNT = 0;
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG2OFS = ((gSelectBattleStage->mSlideOffsetY - gSelectBattleStage->mOffset) << 16) & 0x1ff0000;
}
