#include "01/Menu/select_engine.h"

#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "01/Menu/mission_run_boss_icon.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_02175628.h"
#include "player.h"
#include "01/code_021a1000.h"
#include "code_0212df7c.h"
#include "Main/Graphics/layout_rect_table.h"
#include "registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/code_02185000.h"
#include "01/unk_021a7000.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race.h"
#include "Main/Race/data_020f36d8.h"
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
const u32 gSelectEngineEngineIndices[4] = {0, 1, 2, 1};
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
    Unk02021dc8 *selectEngineMCells = NULL;
    Nclr *selectEngineMOPalette = NULL;
    Ncgr *selectEngineSChars = NULL;
    Unk02021dc8 *selectEngineSCells = NULL;
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
    gSelectEngine->mUnk_1c = HeapAlloc(gSelectEngine->mHeap, 0x800);
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
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gSelectEngine->mUnk_1c, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, selectEngineMChars->mData, selectEngineMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, selectEngineMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, (u8 *) paletteData + 0x1c0, 0x40);
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
        if (gSelectEngine->mIndex == slotIndex && gSelectEngine->mUnk_38 != FALSE) {
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
    if (gSelectEngine->mIndex == 3) {
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
        if (gSelectEngine->mIndexChangeFramesRemaining == 7) {
            gSelectEngine->mLastChangeIndex = gSelectEngine->mIndex;
            RefreshSelectEngineMCells();
        } else {
            offsetY = LookupIndexChangeOffset(7 - gSelectEngine->mIndexChangeFramesRemaining, 0);
            for (slotIndex = 0; slotIndex < 6; slotIndex++) {
                gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = offsetY;
            }
            for (slotIndex = 0; slotIndex < 4; slotIndex++) {
                gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = offsetY;
            }
        }
        gSelectEngine->mIndexChangeFramesRemaining -= 1;
    } else if (gSelectEngine->mIndex != gSelectEngine->mLastChangeIndex) {
        gSelectEngine->mIndexChangeFramesRemaining = 7;
    }
}

void ResetSelectEngineOffsets(void) {
    s32 slotIndex;
    s32 cellSlot;

    gSelectEngine->mNextState = 0;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mBg0Offset = 0xc0;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = 0xc0;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = -0xc0;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = 0xc0;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (slotIndex) {
                case 0:
                case 2:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -0xe0;
                    }
                    break;
                case 1:
                case 3:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = 0xe0;
                    }
                    break;
            }
        } else {
            for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]].mOffsetX =
                    0xe0;
            }
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState1.
void RequestSelectEngineState1(void) {
    gSelectEngine->mNextState = 1;
    gSelectEngine->mStateFrames = 0;
}

// Requests state 2: stores mNextState = 2 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState2.
void RequestSelectEngineState2(void) {
    gSelectEngine->mNextState = 2;
    gSelectEngine->mStateFrames = 0;
}

void RequestSelectEngineState3(void) {
    gSelectEngine->mNextState = 3;
    gSelectEngine->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4: stores mNextState = 4 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState4.
void RequestSelectEngineState4(void) {
    gSelectEngine->mNextState = 4;
    gSelectEngine->mStateFrames = 0;
}

void RequestSelectEngineState5(void) {
    gSelectEngine->mNextState = 5;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mResult = 1;
    SetEngineFromSelectEngine();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState6.
void RequestSelectEngineState6(void) {
    gSelectEngine->mNextState = 6;
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
    selectEngine = HeapAlloc(heap, 0x50);
    gSelectEngine = selectEngine;
    selectEngine->mHeap = heap;
    gSelectEngine->mState = 0;
    gSelectEngine->mIndexChangeFramesRemaining = 0;
    gSelectEngine->mUnk_38 = TRUE;
    gSelectEngine->mMainOamList = mainOamList;
    gSelectEngine->mSubOamList = subOamList;
    gSelectEngine->mResult = 0;
    if (GetMirrorMode() != 0) {
        gSelectEngine->mIndex = 3;
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

void AdvanceSelectEngineState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectEngineState1();
    }
}

void AdvanceSelectEngineState1(void) {
    s16 slideX;
    s16 slideY;
    s32 cellSlot;
    s32 slotIndex;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    slideX = InterpolateS16(1, 0xe0, 0, gSelectEngine->mStateFrames, 10);
    slideY = InterpolateS16(1, -0xc0, 0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -slideY;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = -slideY;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = slideY;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = -slideY;
        if (IsBackupFlagSet(0x10)) {
            switch (slotIndex) {
                case 0:
                case 2:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -slideX;
                    }
                    break;
                case 1:
                case 3:
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
    if (gSelectEngine->mStateFrames >= 10) {
        RequestSelectEngineState2();
    }
}

void AdvanceSelectEngineState2(void) {
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
    if (gSelectEngine->mStateFrames >= 10) {
        RequestSelectEngineState3();
    }
}

void AdvanceSelectEngineState3(void) {
    int returnState2NoState3Or4Request;
    returnState2NoState3Or4Request = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoState3Or4Request != 0) {
        RequestSelectEngineState4();
    }
}

void AdvanceSelectEngineState4(void) {
    u32 touchedRectIndex = -1;
    InputSlotIndex inputSlotIndex = UNK_02175628_INDEX_8;
    BOOL pairStarted;
    s32 recentlyNoPair;
    BOOL pairStartedAgain;
    s32 recentlyNoPairAgain;
    u32 hasPair;
    u32 hasPairAgain;
    s32 currentIndex;
    s32 s;
    SelectEngine *selectEngine;

    AdvanceSelectEngineIndexChange();
    recentlyNoPair = pairStarted = FALSE;
    hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
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
        if (hasPairAgain == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
            recentlyNoPairAgain = 1;
        }
        if (recentlyNoPairAgain == 0 && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPairAgain != 0) {
            pairStartedAgain = TRUE;
        }
        if (pairStartedAgain == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[inputSlotIndex].mPair.mPairX,
                                                            gInputSlots[inputSlotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    if (IsSelectEngineIndexChangeRunning() != 0) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    RequestSelectEngineState6();
    gSelectEngine->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (touchedRectIndex <= 3) {
        s = gSelectEngineRectIndices[touchedRectIndex];
        if (gSelectEngine->mIndex == s) {
            gSelectEngine->mUnk_38 = FALSE;
        }
        gSelectEngine->mIndex = s;
        RequestSelectEngineState5();
        return;
    }
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
        gSelectEngine->mUnk_38 = FALSE;
        RequestSelectEngineState5();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineUpStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineUpStepsFlagClear[currentIndex];
        }
        if (s != 0) {
            selectEngine->mIndex = currentIndex + s;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineDownStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineDownStepsFlagClear[currentIndex];
        }
        if (s != 0) {
            selectEngine->mIndex = currentIndex + s;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineLeftStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineLeftStepsFlagClear[currentIndex];
        }
        if (s != 0) {
            selectEngine->mIndex = currentIndex + s;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineRightStepsFlagSet[currentIndex];
        } else {
            currentIndex = gSelectEngine->mIndex;
            selectEngine = gSelectEngine;
            s = gSelectEngineRightStepsFlagClear[currentIndex];
        }
        if (s != 0) {
            selectEngine->mIndex = currentIndex + s;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    }
}

void AdvanceSelectEngineState5(void) {
    AdvanceSelectEngineIndexChange();
    if (gSelectEngine->mStateFrames == 5) {
        gSelectEngine->mUnk_38 = TRUE;
    }
    gSelectEngine->mStateFrames++;
    if (gSelectEngine->mStateFrames >= 10) {
        if (IsSelectEngineIndexChangeRunning() == 0) {
            RequestSelectEngineState6();
        }
    }
}

void AdvanceSelectEngineState6(void) {
    s16 slideX;
    s16 slideY;
    s32 slotIndex;
    s32 cellSlot;

    gSelectEngine->mStateFrames++;
    slideX = InterpolateS16(1, 0, 0xc0, gSelectEngine->mStateFrames, 10);
    slideY = InterpolateS16(1, 0, -0xc0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -slideY;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineFixedMTableIndices[slotIndex]].mOffsetY = -slideY;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = slideY;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        gSelectEngine->mSelectEngineMTable[gSelectEngineMTableIndices[slotIndex]].mOffsetY = -slideY;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (slotIndex) {
                case 0:
                case 2:
                    for (cellSlot = 0; cellSlot < 3; cellSlot++) {
                        gSelectEngine->mSelectEngineAOrBSTable[gSelectEngineAOrBSTableIndices[slotIndex][cellSlot]]
                            .mOffsetX = -slideX;
                    }
                    break;
                case 1:
                case 3:
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
        case 0:
            AdvanceSelectEngineState0();
            break;
        case 1:
            AdvanceSelectEngineState1();
            break;
        case 2:
            AdvanceSelectEngineState2();
            break;
        case 3:
            AdvanceSelectEngineState3();
            break;
        case 4:
            AdvanceSelectEngineState4();
            break;
        case 5:
            AdvanceSelectEngineState5();
            break;
        case 6:
            AdvanceSelectEngineState6();
            break;
    }
    UpdateSelectEngineIndexCells();
    DrawLayoutTable(gSelectEngine->mSelectEngineMBncl, gSelectEngine->mSelectEngineMNcer, NULL,
                    gSelectEngine->mMainOamList, gSelectEngine->mSelectEngineMTable);
    DrawLayoutTable(gSelectEngine->mSelectEngineAOrBSBncl, gSelectEngine->mSelectEngineSNcer, NULL,
                    gSelectEngine->mSubOamList, gSelectEngine->mSelectEngineAOrBSTable);
    if (gSelectEngine->mState == 6 && gSelectEngine->mStateFrames >= 10) {
        return gSelectEngine->mResult;
    }
    return 0;
}

void WriteSelectEngineBg0Offset(void) {
    reg_G2_BG0OFS = (-gSelectEngine->mBg0Offset << 16) & 0x01ff0000;
}
