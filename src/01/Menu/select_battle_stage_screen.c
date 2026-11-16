#include "01/Menu/select_battle_stage_screen.h"
#include "01/Menu/select_battle_stage_data.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/System/heap.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/layout_rect_table.h"
#include "display_blend_affine_setup.h"
#include "registers.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

void LoadSelectBattleStageData(void) {
    void *sceneFile;
    LoadedPartPointer loaded;
    sceneFile = FindSceneFile("mg/select_battle_stage_m_b.ncgr");
    LoadNcgrData(&loaded.mNcgr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m_00.nscr");
    LoadNscrData(&loaded.mNscr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m_01.nscr");
    LoadNscrData(&loaded.mNscr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m_02.nscr");
    LoadNscrData(&loaded.mNscr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m_b.nclr");
    LoadNclrData(&loaded.mNclr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m.nce.ncgr");
    LoadNcgrData2(&loaded.mNcgr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m.nce.ncer");
    LoadNcerData(&loaded.mNcer, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_m_o.nclr");
    LoadNclrData(&loaded.mNclr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_s.nce.ncgr");
    LoadNcgrData2(&loaded.mNcgr, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_s.nce.ncer");
    LoadNcerData(&loaded.mNcer, sceneFile);
    sceneFile = FindSceneFile("mg/select_battle_stage_s_o.nclr");
    LoadNclrData(&loaded.mNclr, sceneFile);
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
    gSelectBattleStage = HeapAlloc(heap, sizeof(SelectBattleStage));
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
        SetCellOamModeXlu(gSelectBattleStageSTableIndices[index][0], 1, gSelectBattleStage->mSelectBattleStageSCells,
                          gSelectBattleStage->mSelectBattleStageCellLayouts[1]);
    }
    gSelectBattleStage->mMainOamList = mainOam;
    gSelectBattleStage->mSubOamList = subOam;
    ResetOamLists(mainOam, subOam);
    for (index = 0; index < 2; index++) {
        InitLayoutTable(gSelectBattleStage->mHeap, gSelectBattleStage->mSelectBattleStageCellLayouts[index],
                        gSelectBattleStage->mSelectBattleStageLabelLayouts[index],
                        &gSelectBattleStage->mSelectBattleStageTables[index]);
    }
    gSelectBattleStage->mSelectBattleStageTables[0][0].mOffsetY = -SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y;
    gSelectBattleStage->mSlideOffsetY = SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y;
    UpdateSelectBattleStageCellOffsets();
    for (index = 0; index < 6; index++) {
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[index][cellIndex]]
                .mOffsetX = SELECT_BATTLE_STAGE_CELL_SLIDE_DISTANCE;
        }
    }
    {
        u8 labelIndices[2] = {0, 1};
        u8 layoutEntryIndices[2] = {5, 6};
        s32 remainingSize = 0x8000;

        bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 6);
        if (variant == 0) {
            bmgEntry = GetBmgEntry(gSelectBattleStage->mMenuMessages, 7);
        }
        for (index = 0; index < 2; index++) {
            remainingSize -= InitLabelCanvas(
                gSelectBattleStage->mHeap, labelIndices[index], gSelectBattleStage->mSelectBattleStageLabelLayouts[0], 0xa8,
                13, layoutEntryIndices[index], gSelectBattleStage->mSelectBattleStageMCells,
                gSelectBattleStage->mSelectBattleStageCellLayouts[0], gSelectBattleStage->mSelectBattleStageTables[0], remainingSize);
            PrintLabelLayoutTextNoFixedAdvance(0, labelIndices[index], gSelectBattleStage->mSelectBattleStageLabelLayouts[0],
                                               bmgEntry, gSelectBattleStage->mSelectBattleStageCellLayouts[0],
                                               gSelectBattleStage->mSelectBattleStageTables[0]);
        }
        if (variant == 1) {
            gSelectBattleStage->mSelectBattleStageTables[0][5].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[0][6].mVisible = 0;
        }
    }
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x9e10;
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
}

void ReleaseSelectBattleStage(void) {
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x1e10;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
    HeapDestroy(gSelectBattleStage->mHeap);
    gSelectBattleStage = NULL;
}

void LocateAndQueueSelectBattleStage(void) {
    volatile u16 clearValue;
    Ncgr *selectBattleStageMBChars;
    Nclr *selectBattleStageMBPalette;
    Nclr *selectBattleStageMOPalette;
    Nclr *selectBattleStageSOPalette;

    LocateNcgr(&selectBattleStageMBChars, FindSceneFile("mg/select_battle_stage_m_b.ncgr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMScreenMaps[0], FindSceneFile("mg/select_battle_stage_m_00.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMScreenMaps[1], FindSceneFile("mg/select_battle_stage_m_01.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMScreenMaps[2], FindSceneFile("mg/select_battle_stage_m_02.nscr"));
    LocateNclr(&selectBattleStageMBPalette, FindSceneFile("mg/select_battle_stage_m_b.nclr"));
    gSelectBattleStage->mSelectBattleStageCellLayouts[0] = FindSceneFile("mg/select_battle_stage_m.bncl");
    gSelectBattleStage->mSelectBattleStageRects[0] = NULL;
    gSelectBattleStage->mSelectBattleStageLabelLayouts[0] = FindSceneFile("mg/select_battle_stage_m.bnll");
    gSelectBattleStage->mSelectBattleStageCellLayouts[1] = FindSceneFile("mg/select_battle_stage_s.bncl");
    gSelectBattleStage->mSelectBattleStageRects[1] = FindSceneFile("mg/select_battle_stage_s.bnbl");
    gSelectBattleStage->mSelectBattleStageLabelLayouts[1] = NULL;
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageMChars, FindSceneFile("mg/select_battle_stage_m.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageMCells, FindSceneFile("mg/select_battle_stage_m.nce.ncer"));
    LocateNclr(&selectBattleStageMOPalette, FindSceneFile("mg/select_battle_stage_m_o.nclr"));
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageSChars, FindSceneFile("mg/select_battle_stage_s.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageSCells, FindSceneFile("mg/select_battle_stage_s.nce.ncer"));
    LocateNclr(&selectBattleStageSOPalette, FindSceneFile("mg/select_battle_stage_s_o.nclr"));
    clearValue = 0;
    MIi_CpuClear16(clearValue, gSelectBattleStage->mSelectBattleStageMScreenMapCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(6, 0, selectBattleStageMBChars->mData, selectBattleStageMBChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(10, 0, gSelectBattleStage->mSelectBattleStageMScreenMapCopy, 0x1000);
    NNS_GfdRegisterNewVramTransferTask(15, 0, selectBattleStageMBPalette->mData, 0x180);
    NNS_GfdRegisterNewVramTransferTask(19, 0, gSelectBattleStage->mSelectBattleStageMChars->mData,
                                       gSelectBattleStage->mSelectBattleStageMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(14, 0, selectBattleStageMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(14, 0x1c0, selectBattleStageMOPalette->mData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(35, 0, gSelectBattleStage->mSelectBattleStageSChars->mData,
                                       gSelectBattleStage->mSelectBattleStageSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(30, 0, selectBattleStageSOPalette->mData, selectBattleStageSOPalette->mDataSize);
}

void CopyAndQueueSelectBattleStageNscrRect(void) {
    s32 column, row;
    s32 stageIndex = gSelectBattleStage->mIndex;
    u8 screenMapIndex = gSelectBattleStageMNscrIndices[stageIndex];

    for (row = 0; row <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastRow -
                             gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow;
         row++) {
        for (column = 0; column <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastColumn -
                                       gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn;
             column++) {
            (gSelectBattleStage->mSelectBattleStageMScreenMapCopy[gSelectBattleStageMNscrCopyDestination[1] + row] +
             gSelectBattleStageMNscrCopyDestination[0])[column] =
                *((u16 *) gSelectBattleStage->mSelectBattleStageMScreenMaps[screenMapIndex]->mData + column +
                  gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn +
                  (gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow + row) * 32);
        }
    }
    NNS_GfdRegisterNewVramTransferTask(10, 0, gSelectBattleStage->mSelectBattleStageMScreenMapCopy, 0x600);
}

void UpdateSelectBattleStageCellOffsets(void) {
    s32 index;
    u16 layoutCount = gSelectBattleStage->mSelectBattleStageCellLayouts[0]->mCount;

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

void AdvanceSelectBattleStageSlideIn(void) {
    s32 stageIndex, cellIndex;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > SELECT_BATTLE_STAGE_SLIDE_FRAMES + SELECT_BATTLE_STAGE_SETTLE_FRAMES) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN;
        gSelectBattleStage->mStateFrames = 0;
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN;
        RequestSelectReturnSlideIn();
    } else if (gSelectBattleStage->mStateFrames > SELECT_BATTLE_STAGE_SLIDE_FRAMES) {
        for (stageIndex = 0; stageIndex < SELECT_BATTLE_STAGE_COUNT; stageIndex++) {
            for (cellIndex = 0; cellIndex < 3; cellIndex++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                    .mOffsetX =
                    GetSelectedPressOffset(gSelectBattleStage->mStateFrames - SELECT_BATTLE_STAGE_SLIDE_FRAMES);
            }
        }
    } else {
        gSelectBattleStage->mSlideOffsetY =
            InterpolateS16(1, SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y, 0, gSelectBattleStage->mStateFrames,
                           SELECT_BATTLE_STAGE_SLIDE_FRAMES);
        gSelectBattleStage->mSlideOffsetX =
            InterpolateS16(1, -SELECT_BATTLE_STAGE_SLIDE_DISTANCE_X, 0, gSelectBattleStage->mStateFrames,
                           SELECT_BATTLE_STAGE_SLIDE_FRAMES);
        for (stageIndex = 0; stageIndex < SELECT_BATTLE_STAGE_COUNT; stageIndex++) {
            for (cellIndex = 0; cellIndex < 3; cellIndex++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                    .mOffsetX = InterpolateS16(1, SELECT_BATTLE_STAGE_CELL_SLIDE_DISTANCE, 0,
                                               gSelectBattleStage->mStateFrames, SELECT_BATTLE_STAGE_SLIDE_FRAMES);
            }
        }
    }
}

void AdvanceSelectBattleStageWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_INPUT;
    }
}

void AdvanceSelectBattleStageInput(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    s32 touchedRectIndex = -1;
    s32 touchedStageIndex = -4;
    BOOL touchBegan = FALSE;
    BOOL recentlyLost;
    s32 stageIndex;
    s32 previousIndex;
    u16 hasPair;

    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRectIndex = RectTableFindContaining(gSelectBattleStage->mSelectBattleStageRects[1],
                                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
    }
    for (stageIndex = 0; stageIndex < SELECT_BATTLE_STAGE_COUNT; stageIndex++) {
        if (touchedRectIndex == gSelectBattleStageBnblRectIndices[stageIndex]) {
            touchedStageIndex = stageIndex;
        }
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
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
            goto next;
        }
    }
    if (gMenuShared->mMenuEntryKind == 2) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN_THEN_CHOISES;
        RequestSelectReturnPressWithSound(0);
        gSelectBattleStage->mWaitForReturnHidden = FALSE;
        return;
    }
    gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_SLIDE_OUT;
    gSelectBattleStage->mPendingResult = -3;
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
        RequestSelectReturnPressWithSound(0);
        gSelectBattleStage->mWaitForReturnHidden = FALSE;
        return;
    }
    RequestSelectReturnPressWithSound(1);
    gSelectBattleStage->mWaitForReturnHidden = TRUE;
    return;
next:
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 || touchedStageIndex != -4) {
        previousIndex = gSelectBattleStage->mIndex;
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) == 0) {
            gSelectBattleStage->mIndex = touchedStageIndex;
        }
        if (gSelectBattleStage->mIndex == previousIndex) {
            gSelectBattleStage->mHighlightVisible = FALSE;
        }
        gSelectBattleStage->mPendingResult = gSelectBattleStage->mIndex;
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_PRESS_STAGE;
        gSelectBattleStage->mOffsetTimer = SELECT_BATTLE_STAGE_OFFSET_TIMER_FRAMES;
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectBattleStage->mIndex--;
        if (gSelectBattleStage->mIndex < 0) {
            gSelectBattleStage->mIndex = SELECT_BATTLE_STAGE_COUNT - 1;
        }
        gSelectBattleStage->mOffsetTimer = SELECT_BATTLE_STAGE_OFFSET_TIMER_FRAMES;
        StartSoundOncePerFrame(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectBattleStage->mIndex++;
        if (gSelectBattleStage->mIndex >= SELECT_BATTLE_STAGE_COUNT) {
            gSelectBattleStage->mIndex = 0;
        }
        gSelectBattleStage->mOffsetTimer = SELECT_BATTLE_STAGE_OFFSET_TIMER_FRAMES;
        StartSoundOncePerFrame(0);
    }
}

void AdvanceSelectBattleStagePressStage(void) {
    s32 cellIndex;
    s16 offsetX;

    gSelectBattleStage->mStateFrames++;
    offsetX = GetSelectedPressOffset(gSelectBattleStage->mStateFrames);
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gSelectBattleStage
            ->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[gSelectBattleStage->mIndex][cellIndex]]
            .mOffsetX = offsetX;
    }
    if (gSelectBattleStage->mStateFrames >= SELECT_BATTLE_STAGE_SETTLE_FRAMES) {
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_CHOISES;
        gSelectBattleStage->mStateFrames = 0;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mCommonMessages, 4),
                           GetBmgEntry(gSelectBattleStage->mCommonMessages, 2), 0);
        SetSelectChoisesSoundId(0, 7);
        SetSelectChoisesSoundId(1, 0x10);
    } else if (gSelectBattleStage->mStateFrames >= SELECT_BATTLE_STAGE_HIGHLIGHT_FRAME) {
        gSelectBattleStage->mHighlightVisible = TRUE;
    }
}

void AdvanceSelectBattleStageWaitSelectReturnThenChoises(void) {
    if (IsSelectReturnShownNoRequest() != 0) {
        gSelectBattleStage->mPendingResult = -2;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x14),
                           GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x15), 0);
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xc);
        gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_CHOISES;
    }
}

void AdvanceSelectBattleStageChoises(void) {
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
                RequestSelectReturnSlideOut();
                gSelectBattleStage->mWaitForReturnHidden = TRUE;
            } else {
                gSelectBattleStage->mNextState = SELECT_BATTLE_STAGE_STATE_INPUT;
            }
        }
        RequestSelectChoisesHidden();
    }
}

void AdvanceSelectBattleStageSlideOut(void) {
    s32 stageIndex;
    s32 cellIndex;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > SELECT_BATTLE_STAGE_SLIDE_FRAMES) {
        if ((gSelectBattleStage->mWaitForReturnHidden != FALSE && IsSelectReturnHiddenNoSlideInRequest() != 0) ||
            (gSelectBattleStage->mWaitForReturnHidden == FALSE && IsSelectReturnShownNoRequest() != 0)) {
            gSelectBattleStage->mResult = gSelectBattleStage->mPendingResult;
            return;
        }
    }
    if (gSelectBattleStage->mStateFrames > SELECT_BATTLE_STAGE_SLIDE_FRAMES) {
        gSelectBattleStage->mStateFrames = SELECT_BATTLE_STAGE_SLIDE_FRAMES;
    }
    gSelectBattleStage->mSlideOffsetY = InterpolateS16(
        1, 0, SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y, gSelectBattleStage->mStateFrames, SELECT_BATTLE_STAGE_SLIDE_FRAMES);
    gSelectBattleStage->mSlideOffsetX =
        InterpolateS16(1, 0, -SELECT_BATTLE_STAGE_SLIDE_DISTANCE_X, gSelectBattleStage->mStateFrames,
                       SELECT_BATTLE_STAGE_SLIDE_FRAMES);
    for (stageIndex = 0; stageIndex < SELECT_BATTLE_STAGE_COUNT; stageIndex++) {
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[stageIndex][cellIndex]]
                .mOffsetX = InterpolateS16(1, 0, SELECT_BATTLE_STAGE_CELL_SLIDE_DISTANCE,
                                           gSelectBattleStage->mStateFrames, SELECT_BATTLE_STAGE_SLIDE_FRAMES);
        }
    }
}

void UpdateSelectBattleStageHighlight(void) {
    s32 stageIndex;
    BOOL zero = FALSE;

    for (stageIndex = 0; stageIndex < SELECT_BATTLE_STAGE_COUNT; stageIndex++) {
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
            AdvanceSelectBattleStageSlideIn();
            break;
        case SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN:
            AdvanceSelectBattleStageWaitSelectReturn();
            break;
        case SELECT_BATTLE_STAGE_STATE_INPUT:
            AdvanceSelectBattleStageInput();
            break;
        case SELECT_BATTLE_STAGE_STATE_PRESS_STAGE:
            AdvanceSelectBattleStagePressStage();
            break;
        case SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN_THEN_CHOISES:
            AdvanceSelectBattleStageWaitSelectReturnThenChoises();
            break;
        case SELECT_BATTLE_STAGE_STATE_CHOISES:
            AdvanceSelectBattleStageChoises();
            break;
        case SELECT_BATTLE_STAGE_STATE_SLIDE_OUT:
            AdvanceSelectBattleStageSlideOut();
            break;
    }
    AdvanceSelectBattleStageOffsetTimer();
    UpdateSelectBattleStageHighlight();
    UpdateSelectBattleStageCellOffsets();
    CopyAndQueueSelectBattleStageNscrRect();
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        DrawLayoutTable(gSelectBattleStage->mSelectBattleStageCellLayouts[screenIndex],
                        (&gSelectBattleStage->mSelectBattleStageMCells)[screenIndex],
                        gSelectBattleStage->mSelectBattleStageLabelLayouts[screenIndex],
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
