#include "01/Menu/select_engine.h"

#include "types.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "01/Menu/mission_run_boss_icon.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_return.h"
#include "Main/System/input_slots.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "Main/Graphics/layout_rect_table.h"
#include "registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race_setup.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const char *gSelectEngineMBNclrName = "gp/select_engine_m_b.nclr";
const u16 gSelectEngineAOrBSTableIndices[4][3] = {{3, 7, 0xb}, {2, 6, 0xa}, {1, 5, 9}, {0, 4, 8}};
const s16 gSelectEngineRightStepsFlagSet[4] = {1, 0, 1, 0};
const char *gSelectEngineBSBnclName = "gp/select_engine_B_s.bncl";
const char *gSelectEngineBSBnblName = "gp/select_engine_B_s.bnbl";
const char *gSelectEngineMNscrName = "gp/select_engine_m.nscr";
const u32 gSelectEngineEngineIndices[4] = {ENGINE_CLASS_SLOW, ENGINE_CLASS_MEDIUM, ENGINE_CLASS_FAST,
                                           ENGINE_CLASS_MEDIUM};
const u32 gSelectEngineIndicesByEngineIndex[3] = {0, 1, 2};
const char *gSelectEngineSNcgrName = "gp/select_engine_s.nce.ncgr";
const char *gSelectEngineMBNcgrName = "gp/select_engine_m_b.ncgr";
const char *gSelectEngineMBnclName = "gp/select_engine_m.bncl";
const u16 gSelectEngineMTableIndices[4] = {7, 8, 9, 0xa};
const s16 gSelectEngineDownStepsFlagSet[4] = {2, 2, 0, 0};
const s16 gSelectEngineUpStepsFlagClear[4] = {2, -1, -1, 0};
const s16 gSelectEngineDownStepsFlagClear[4] = {1, 1, -2, 0};
const u16 gSelectEngineFixedMTableIndices[6] = {0, 1, 2, 3, 4, 5};
const s32 gSelectEngineRectIndices[4] = {3, 2, 1, 0};
const s16 gSelectEngineLeftStepsFlagClear[4] = {0, 0, 0, 0};
const s16 gSelectEngineRightStepsFlagClear[4] = {0, 0, 0, 0};
const char *gSelectEngineMNcerName = "gp/select_engine_m.nce.ncer";
const char *gSelectEngineSNcerName = "gp/select_engine_s.nce.ncer";
const s16 gSelectEngineUpStepsFlagSet[4] = {0, 0, -2, -2};
const s16 gSelectEngineLeftStepsFlagSet[4] = {0, -1, 0, -1};
const char *gSelectEngineMNcgrName = "gp/select_engine_m.nce.ncgr";
const char *gSelectEngineMONclrName = "gp/select_engine_m_o.nclr";
const char *gSelectEngineSONclrName = "gp/select_engine_s_o.nclr";
const char *gSelectEngineASBnblName = "gp/select_engine_A_s.bnbl";
const char *gSelectEngineASBnclName = "gp/select_engine_A_s.bncl";
SelectEngine *gSelectEngine;

void LoadSelectEngineData(void) {
    Ncgr *selectEngineMChars = NULL;
    NNSG2dCellDataBank *selectEngineMCells = NULL;
    Nclr *selectEngineMOPalette = NULL;
    Ncgr *selectEngineSChars = NULL;
    NNSG2dCellDataBank *selectEngineSCells = NULL;
    Nclr *selectEngineSOPalette = NULL;
    Ncgr *selectEngineMBChars = NULL;
    Nscr *selectEngineMScreenMap = NULL;
    Nclr *selectEngineMBPalette = NULL;

    LoadNcgrData(&selectEngineMBChars, FindSceneFile(gSelectEngineMBNcgrName));
    LoadNclrData(&selectEngineMBPalette, FindSceneFile(gSelectEngineMBNclrName));
    LoadNscrData(&selectEngineMScreenMap, FindSceneFile(gSelectEngineMNscrName));
    LoadNcgrData2(&selectEngineMChars, FindSceneFile(gSelectEngineMNcgrName));
    LoadNcerData(&selectEngineMCells, FindSceneFile(gSelectEngineMNcerName));
    LoadNclrData(&selectEngineMOPalette, FindSceneFile(gSelectEngineMONclrName));
    LoadNcgrData2(&selectEngineSChars, FindSceneFile(gSelectEngineSNcgrName));
    LoadNcerData(&selectEngineSCells, FindSceneFile(gSelectEngineSNcerName));
    LoadNclrData(&selectEngineSOPalette, FindSceneFile(gSelectEngineSONclrName));
}

void LocateAndQueueSelectEngine(void) {
    Ncgr *selectEngineMChars = NULL;
    Nclr *selectEngineMOPalette = NULL;
    Ncgr *selectEngineSChars = NULL;
    Nclr *selectEngineSOPalette = NULL;
    Ncgr *selectEngineMBChars = NULL;
    Nscr *selectEngineMScreenMap = NULL;
    Nclr *selectEngineMBPalette = NULL;
    u16 *paletteData;

    LocateNcgr(&selectEngineMBChars, FindSceneFile(gSelectEngineMBNcgrName));
    LocateNclr(&selectEngineMBPalette, FindSceneFile(gSelectEngineMBNclrName));
    LocateNscr(&selectEngineMScreenMap, FindSceneFile(gSelectEngineMNscrName));
    gSelectEngine->mVramTransferBuffer = HeapAlloc(gSelectEngine->mHeap, SECOND_SCREEN_MAP_BYTES);
    gSelectEngine->mSelectEngineMBncl = FindSceneFile(gSelectEngineMBnclName);
    LocateNcgr2(&selectEngineMChars, FindSceneFile(gSelectEngineMNcgrName));
    LocateNcer(&gSelectEngine->mSelectEngineMNcer, FindSceneFile(gSelectEngineMNcerName));
    LocateNclr(&selectEngineMOPalette, FindSceneFile(gSelectEngineMONclrName));
    LocateNcgr2(&selectEngineSChars, FindSceneFile(gSelectEngineSNcgrName));
    LocateNcer(&gSelectEngine->mSelectEngineSNcer, FindSceneFile(gSelectEngineSNcerName));
    LocateNclr(&selectEngineSOPalette, FindSceneFile(gSelectEngineSONclrName));
    if (IsBackupFlagSet(0x10) != 0) {
        gSelectEngine->mSelectEngineAOrBSBncl = FindSceneFile(gSelectEngineBSBnclName);
        gSelectEngine->mSelectEngineAOrBSBnbl = FindSceneFile(gSelectEngineBSBnblName);
    } else {
        gSelectEngine->mSelectEngineAOrBSBncl = FindSceneFile(gSelectEngineASBnclName);
        gSelectEngine->mSelectEngineAOrBSBnbl = FindSceneFile(gSelectEngineASBnblName);
    }
    paletteData = selectEngineMOPalette->mData;
    NNS_GfdRegisterNewVramTransferTask(4, 0, selectEngineMBChars->mData, selectEngineMBChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, selectEngineMBPalette->mData, 0x100);
    NNS_GfdRegisterNewVramTransferTask(8, 0, selectEngineMScreenMap->mData, selectEngineMScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gSelectEngine->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, selectEngineMChars->mData, selectEngineMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, selectEngineMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, selectEngineSChars->mData, selectEngineSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, selectEngineSOPalette->mData, selectEngineSOPalette->mDataSize);
}

void InitSelectEngineCells(void) {
    s32 slotIndex;
    s32 cellSlot;

    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mVisible = 0;
        for (cellSlot = 0; cellSlot < 3; cellSlot++) {
            gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]].mVisible = 0;
        }
    }
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mVisible = 1;
    }
    gSelectEngine->mSelectEngineMTable[6].mVisible = 1;
    gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[gSelectEngine->mIndex]].mVisible = 1;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][0]].mVisible = 1;
        SetCellOamModeXlu(gSelectEngineAOrBSTableIndices[slotIndex][0], 1, gSelectEngine->mSelectEngineSNcer,
                          gSelectEngine->mSelectEngineAOrBSBncl);
    }
    SetCellOamModeXlu(2, 1, gSelectEngine->mSelectEngineMNcer, gSelectEngine->mSelectEngineMBncl);
}

void UpdateSelectEngineIndexCells(void) {
    s32 slotIndex;

    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][1]].mVisible = 0;
        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][2]].mVisible = 0;
        if (gSelectEngine->mIndex == slotIndex && gSelectEngine->mAlternateCellShown != FALSE) {
            gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][2]].mVisible = 1;
        } else {
            gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][1]].mVisible = 1;
        }
    }
    if (IsBackupFlagSet(0x10) == 0) {
        for (slotIndex = 0; slotIndex < 3; slotIndex++) {
            gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[3][slotIndex]].mVisible = 0;
        }
    }
}

void RefreshSelectEngineMCells(void) {
    s32 slotIndex;

    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mVisible = 0;
    }
    gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[gSelectEngine->mIndex]].mVisible = 1;
}

void SetEngineFromSelectEngine(void) {
    if (gSelectEngine->mIndex == SELECT_ENGINE_ENTRY_MIRROR) {
        SetEngineIndex(gSelectEngineEngineIndices[2]);
        SetMirrorMode();
    } else {
        SetEngineIndex(gSelectEngineEngineIndices[gSelectEngine->mIndex]);
        ClearMirrorMode();
    }
    SetCupIndex(0);
}

u32 IsSelectEngineIndexChangeRunning(void) {
    if (gSelectEngine->mIndexChangeFramesRemaining != 0) {
        return 1;
    }
    return 0;
}

void AdvanceSelectEngineIndexChange(void) {
    s32 slotIndex;
    s16 offsetY;

    if (IsSelectEngineIndexChangeRunning() != 0) {
        if (gSelectEngine->mIndexChangeFramesRemaining == SELECT_ENGINE_INDEX_CHANGE_FRAMES) {
            gSelectEngine->mLastChangeIndex = gSelectEngine->mIndex;
            RefreshSelectEngineMCells();
        } else {
            offsetY = LookupIndexChangeOffset(
                SELECT_ENGINE_INDEX_CHANGE_FRAMES - gSelectEngine->mIndexChangeFramesRemaining, 0);
            for (slotIndex = 0; slotIndex < 6; slotIndex++) {
                gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = offsetY;
            }
            for (slotIndex = 0; slotIndex < 4; slotIndex++) {
                gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = offsetY;
            }
        }
        gSelectEngine->mIndexChangeFramesRemaining -= 1;
    } else if (gSelectEngine->mIndex != gSelectEngine->mLastChangeIndex) {
        gSelectEngine->mIndexChangeFramesRemaining = SELECT_ENGINE_INDEX_CHANGE_FRAMES;
    }
}

void ResetSelectEngineOffsets(void) {
    s32 slotIndex;
    s32 cellSlot;

    gSelectEngine->mNextState = SELECT_ENGINE_STATE_WAIT_FADE;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mBg0Offset = SELECT_ENGINE_SLIDE_DISTANCE_Y;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY =
            SELECT_ENGINE_SLIDE_DISTANCE_Y;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = -SELECT_ENGINE_SLIDE_DISTANCE_Y;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY =
            SELECT_ENGINE_SLIDE_DISTANCE_Y;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (slotIndex) {
                case SELECT_ENGINE_ENTRY_SLOW:
                case SELECT_ENGINE_ENTRY_FAST:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -SELECT_ENGINE_SLIDE_IN_DISTANCE_X;
                    }
                    break;
                case SELECT_ENGINE_ENTRY_MEDIUM:
                case SELECT_ENGINE_ENTRY_MIRROR:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = SELECT_ENGINE_SLIDE_IN_DISTANCE_X;
                    }
                    break;
            }
        } else {
            for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]].mOffsetX =
                    SELECT_ENGINE_SLIDE_IN_DISTANCE_X;
            }
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineSlideIn.
void RequestSelectEngineSlideIn(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_SLIDE_IN;
    gSelectEngine->mStateFrames = 0;
}

// Requests state 2: stores mNextState = 2 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEnginePressOffsetAfterSlideIn.
void RequestSelectEngineSlideInPressOffset(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_SETTLE;
    gSelectEngine->mStateFrames = 0;
}

void RequestSelectEngineWaitSelectReturn(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_WAIT_SELECT_RETURN;
    gSelectEngine->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

// Requests state 4: stores mNextState = 4 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineInput.
void RequestSelectEngineInput(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_INPUT;
    gSelectEngine->mStateFrames = 0;
}

void RequestSelectEnginePress(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_PRESS;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mResult = MENU_SCREEN_RESULT_NEXT;
    SetEngineFromSelectEngine();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineSlideOut.
void RequestSelectEngineSlideOut(void) {
    gSelectEngine->mNextState = SELECT_ENGINE_STATE_SLIDE_OUT;
    gSelectEngine->mStateFrames = 0;
}

void InitSelectEngine(void *parentHeap, void *mainOamList, void *subOamList) {
    void *heap;
    SelectEngine *selectEngine;
    vu16 *bg0Control = &reg_G2_BG0CNT;
    vu16 *bg1Control = &reg_G2_BG1CNT;

    *bg0Control = (*bg0Control & ~3) | 1;
    *bg1Control = (*bg1Control & ~3) | 1;
    *bg0Control = (*bg0Control & 0x43) | 0x9004;
    *bg1Control = (*bg1Control & 0x43) | 0x9204;
    reg_G2_BG0OFS = 0xc00000;
    reg_G2_BG1OFS = 0xc00000;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    selectEngine = HeapAlloc(heap, sizeof(SelectEngine));
    gSelectEngine = selectEngine;
    selectEngine->mHeap = heap;
    gSelectEngine->mState = SELECT_ENGINE_STATE_WAIT_FADE;
    gSelectEngine->mIndexChangeFramesRemaining = 0;
    gSelectEngine->mAlternateCellShown = TRUE;
    gSelectEngine->mMainOamList = mainOamList;
    gSelectEngine->mSubOamList = subOamList;
    gSelectEngine->mResult = SELECT_ENGINE_RESULT_NONE;
    if (GetMirrorMode() != 0) {
        gSelectEngine->mIndex = SELECT_ENGINE_ENTRY_MIRROR;
    } else {
        gSelectEngine->mIndex = gSelectEngineIndicesByEngineIndex[GetEngineIndex()];
    }
    gSelectEngine->mLastChangeIndex = gSelectEngine->mIndex;
    LocateAndQueueSelectEngine();
    ResetOamLists(gSelectEngine->mMainOamList, gSelectEngine->mSubOamList);
    InitLayoutTable(gSelectEngine->mHeap, gSelectEngine->mSelectEngineMBncl, NULL, &gSelectEngine->mSelectEngineMTable);
    InitLayoutTable(gSelectEngine->mHeap, gSelectEngine->mSelectEngineAOrBSBncl, NULL,
                    &gSelectEngine->mSelectEngineAOrBSTable);
    InitSelectEngineCells();
    RefreshSelectEngineMCells();
    ResetSelectEngineOffsets();
    FrmHeapShrinkInParent(gSelectEngine->mHeap);
}

void ReleaseSelectEngine(void) {
    HeapDestroy(gSelectEngine->mHeap);
    gSelectEngine = NULL;
}

void AdvanceSelectEngineWaitFade(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectEngineSlideIn();
    }
}

void AdvanceSelectEngineSlideIn(void) {
    s16 slideX;
    s16 slideY;
    s32 cellSlot;
    s32 slotIndex;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    slideX = InterpolateS16(1, SELECT_ENGINE_SLIDE_IN_DISTANCE_X, 0, gSelectEngine->mStateFrames,
                            SELECT_ENGINE_SLIDE_FRAMES);
    slideY =
        InterpolateS16(1, -SELECT_ENGINE_SLIDE_DISTANCE_Y, 0, gSelectEngine->mStateFrames, SELECT_ENGINE_SLIDE_FRAMES);
    gSelectEngine->mBg0Offset = -slideY;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = -slideY;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = slideY;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = -slideY;
        if (IsBackupFlagSet(0x10)) {
            switch (slotIndex) {
                case SELECT_ENGINE_ENTRY_SLOW:
                case SELECT_ENGINE_ENTRY_FAST:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -slideX;
                    }
                    break;
                case SELECT_ENGINE_ENTRY_MEDIUM:
                case SELECT_ENGINE_ENTRY_MIRROR:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = slideX;
                    }
                    break;
            }
        } else {
            for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]].mOffsetX =
                    slideX;
            }
        }
    }
    if (gSelectEngine->mStateFrames >= SELECT_ENGINE_SLIDE_FRAMES) {
        RequestSelectEngineSlideInPressOffset();
    }
}

void AdvanceSelectEnginePressOffsetAfterSlideIn(void) {
    s16 selectedPressOffset;
    s32 slotIndex;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    selectedPressOffset = GetSelectedPressOffset(gSelectEngine->mStateFrames);
    gSelectEngine->mBg0Offset = selectedPressOffset;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = selectedPressOffset;
    }
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = selectedPressOffset;
    }
    if (gSelectEngine->mStateFrames >= SELECT_ENGINE_PRESS_FRAMES) {
        RequestSelectEngineWaitSelectReturn();
    }
}

void AdvanceSelectEngineWaitSelectReturn(void) {
    int returnShownNoRequest;
    returnShownNoRequest = IsSelectReturnShownNoRequest();
    if (returnShownNoRequest != 0) {
        RequestSelectEngineInput();
    }
}

void AdvanceSelectEngineInput(void) {
    u32 touchedRectIndex = -1;
    InputSlotIndex inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL pairStarted;
    s32 recentlyNoPair;
    BOOL pairStartedAgain;
    s32 recentlyNoPairAgain;
    u32 hasPair;
    u32 hasPairAgain;
    s32 currentIndex;
    s32 value;
    SelectEngine *selectEngine;

    AdvanceSelectEngineIndexChange();
    recentlyNoPair = pairStarted = FALSE;
    hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_RECENTLY_LOST_FRAMES) {
        recentlyNoPair = 1;
    }
    if (recentlyNoPair == 0 && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        pairStarted = TRUE;
    }
    if (pairStarted != FALSE) {
        touchedRectIndex =
            RectTableFindContaining(gSelectEngine->mSelectEngineAOrBSBnbl, gInputSlots[inputSlotIndex].mPair.mPairX,
                                    gInputSlots[inputSlotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_B) == 0) {
        recentlyNoPairAgain = pairStartedAgain = FALSE;
        hasPairAgain = gInputSlots[inputSlotIndex].mPair.mHasPair;
        if (hasPairAgain == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_RECENTLY_LOST_FRAMES) {
            recentlyNoPairAgain = 1;
        }
        if (recentlyNoPairAgain == 0 && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPairAgain != 0) {
            pairStartedAgain = TRUE;
        }
        if (pairStartedAgain == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[inputSlotIndex].mPair.mPairX,
                                                  gInputSlots[inputSlotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    if (IsSelectEngineIndexChangeRunning() != 0) {
        return;
    }
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
    RequestSelectEngineSlideOut();
    gSelectEngine->mResult = MENU_SCREEN_RESULT_BACK;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    if (touchedRectIndex <= 3) {
        value = gSelectEngineRectIndices[touchedRectIndex];
        if (gSelectEngine->mIndex == value) {
            gSelectEngine->mAlternateCellShown = FALSE;
        }
        gSelectEngine->mIndex = value;
        RequestSelectEnginePress();
        return;
    }
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
        gSelectEngine->mAlternateCellShown = FALSE;
        RequestSelectEnginePress();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineUpStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineUpStepsFlagClear[currentIndex];
        }
        if (value != 0) {
            selectEngine->mIndex = currentIndex + value;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineDownStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineDownStepsFlagClear[currentIndex];
        }
        if (value != 0) {
            selectEngine->mIndex = currentIndex + value;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_LEFT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineLeftStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineLeftStepsFlagClear[currentIndex];
        }
        if (value != 0) {
            selectEngine->mIndex = currentIndex + value;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_RIGHT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineRightStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            value = gSelectEngineRightStepsFlagClear[currentIndex];
        }
        if (value != 0) {
            selectEngine->mIndex = currentIndex + value;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceSelectEnginePress(void) {
    AdvanceSelectEngineIndexChange();
    if (gSelectEngine->mStateFrames == SELECT_ENGINE_ALTERNATE_CELL_SHOWN_FRAME) {
        gSelectEngine->mAlternateCellShown = TRUE;
    }
    gSelectEngine->mStateFrames++;
    if (gSelectEngine->mStateFrames >= SELECT_ENGINE_PRESS_FRAMES) {
        if (IsSelectEngineIndexChangeRunning() == 0) {
            RequestSelectEngineSlideOut();
        }
    }
}

void AdvanceSelectEngineSlideOut(void) {
    s16 slideX;
    s16 slideY;
    s32 slotIndex;
    s32 cellSlot;

    gSelectEngine->mStateFrames++;
    slideX = InterpolateS16(1, 0, SELECT_ENGINE_SLIDE_OUT_DISTANCE_X, gSelectEngine->mStateFrames,
                            SELECT_ENGINE_SLIDE_FRAMES);
    slideY =
        InterpolateS16(1, 0, -SELECT_ENGINE_SLIDE_DISTANCE_Y, gSelectEngine->mStateFrames, SELECT_ENGINE_SLIDE_FRAMES);
    gSelectEngine->mBg0Offset = -slideY;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = -slideY;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = slideY;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = -slideY;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (slotIndex) {
                case SELECT_ENGINE_ENTRY_SLOW:
                case SELECT_ENGINE_ENTRY_FAST:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -slideX;
                    }
                    break;
                case SELECT_ENGINE_ENTRY_MEDIUM:
                case SELECT_ENGINE_ENTRY_MIRROR:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = slideX;
                    }
                    break;
            }
        } else {
            for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]].mOffsetX =
                    slideX;
            }
        }
    }
}

int AdvanceSelectEngine(void) {
    gSelectEngine->mState = gSelectEngine->mNextState;
    switch (gSelectEngine->mState) {
        case SELECT_ENGINE_STATE_WAIT_FADE:
            AdvanceSelectEngineWaitFade();
            break;
        case SELECT_ENGINE_STATE_SLIDE_IN:
            AdvanceSelectEngineSlideIn();
            break;
        case SELECT_ENGINE_STATE_SETTLE:
            AdvanceSelectEnginePressOffsetAfterSlideIn();
            break;
        case SELECT_ENGINE_STATE_WAIT_SELECT_RETURN:
            AdvanceSelectEngineWaitSelectReturn();
            break;
        case SELECT_ENGINE_STATE_INPUT:
            AdvanceSelectEngineInput();
            break;
        case SELECT_ENGINE_STATE_PRESS:
            AdvanceSelectEnginePress();
            break;
        case SELECT_ENGINE_STATE_SLIDE_OUT:
            AdvanceSelectEngineSlideOut();
            break;
    }
    UpdateSelectEngineIndexCells();
    DrawLayoutTable(gSelectEngine->mSelectEngineMBncl, gSelectEngine->mSelectEngineMNcer, NULL,
                    gSelectEngine->mMainOamList, gSelectEngine->mSelectEngineMTable);
    DrawLayoutTable(gSelectEngine->mSelectEngineAOrBSBncl, gSelectEngine->mSelectEngineSNcer, NULL,
                    gSelectEngine->mSubOamList, gSelectEngine->mSelectEngineAOrBSTable);
    if (gSelectEngine->mState == SELECT_ENGINE_STATE_SLIDE_OUT &&
        gSelectEngine->mStateFrames >= SELECT_ENGINE_SLIDE_FRAMES) {
        return gSelectEngine->mResult;
    }
    return SELECT_ENGINE_RESULT_NONE;
}

void WriteSelectEngineBg0Offset(void) {
    reg_G2_BG0OFS = (-gSelectEngine->mBg0Offset << 16) & 0x01ff0000;
}
