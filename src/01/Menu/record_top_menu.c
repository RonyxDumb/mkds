#include "01/Menu/record_top_menu.h"

#include "01/unk_021a6000.h"
#include "Main/System/heap.h"
#include "Main/Menu/record_vs.h"
#include "Main/Menu/record_list.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/data_02175628.h"
#include "01/Menu/record_time_attack.h"
#include "Main/Menu/select_return.h"
#include "01/code_0219c000.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/oam.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/code_0219a000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/MapObjects/data_0217a000.h"
#include "player.h"
#include "code_0212df7c.h"
#include "01/Menu/select_ghost.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Sound/sound_system.h"

const u16 gRecordTopMenuGradeSTableIndices[3] = {2, 3, 4};
const u16 gRecordTopMenuRowCellIndices[3] = {9, 0xa, 0xb};
const u16 gRecordTopMenuLabelWidths[3][3] = {{0x70, 0x70, 0x70}, {0x20, 0x20, 0x20}, {0x20, 0x20, 0x20}};
const s32 gRecordTopMenuTouchRowIndices[3] = {0, 1, 2};
const u16 gRecordTopMenuLabelHeights[3][3] = {{0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}};
const s32 gRecordTopMenuRowRecordScreens[3] = {1, 2, 3};
const u16 gRecordTopMenuRecordMessageIndices[3] = {6, 7, 8};
const u16 gRecordTopMenuOffsetSTableIndices[3] = {3, 4, 5};
const u16 gRecordTopMenuRowSTableIndices[3] = {6, 7, 8};
const u16 gRecordTopMenuXluCellIndices[3] = {0, 1, 2};
const u16 gRecordTopMenuLabelIndices[3][3] = {{1, 2, 3}, {4, 6, 8}, {5, 7, 9}};
RecordTopMenu *gRecordTopMenu;

void LocateAndQueueRecordTopMenu(void) {
    Ncgr *recordTopMenuMNcgr;
    Nclr *recordTopMenuMONclr;
    Ncgr *recordTopMenuSNcgr;
    Nclr *recordTopMenuSONclr;
    Ncgr *recordTopMenuMBNcgr;
    Nclr *recordTopMenuMBNclr;
    Nscr *recordTopMenuMNscr;
    u16 *paletteData;

    recordTopMenuMNcgr = NULL;
    recordTopMenuMONclr = NULL;
    recordTopMenuSNcgr = NULL;
    recordTopMenuSONclr = NULL;
    recordTopMenuMBNcgr = NULL;
    recordTopMenuMBNclr = NULL;
    recordTopMenuMNscr = NULL;
    LocateNcgr(&recordTopMenuMBNcgr, FindSceneFile(gRecordTopMenuMBNcgrName));
    LocateNclr(&recordTopMenuMBNclr, FindSceneFile(gRecordTopMenuMBNclrName));
    LocateNscr(&recordTopMenuMNscr, FindSceneFile(gRecordTopMenuMNscrName));
    gRecordTopMenu->mSecondScreenMapBuffer = HeapAlloc(gRecordTopMenu->mHeap, 0x800);
    gRecordTopMenu->mRecordTopMenuMBncl = FindSceneFile(gRecordTopMenuMBnclName);
    gRecordTopMenu->mRecordTopMenuMBnll = FindSceneFile(gRecordTopMenuMBnllName);
    LocateNcgr2(&recordTopMenuMNcgr, FindSceneFile(gRecordTopMenuMNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuMNcer, FindSceneFile(gRecordTopMenuMNcerName));
    LocateNclr(&recordTopMenuMONclr, FindSceneFile(gRecordTopMenuMONclrName));
    gRecordTopMenu->mRecordTopMenuSBncl = FindSceneFile(gRecordTopMenuSBnclName);
    gRecordTopMenu->mRecordTopMenuSBnbl = FindSceneFile(gRecordTopMenuSBnblName);
    LocateNcgr2(&recordTopMenuSNcgr, FindSceneFile(gRecordTopMenuSNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuSNcer, FindSceneFile(gRecordTopMenuSNcerName));
    LocateNclr(&recordTopMenuSONclr, FindSceneFile(gRecordTopMenuSONclrName));
    paletteData = recordTopMenuMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(4, 0, recordTopMenuMBNcgr->mData, recordTopMenuMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(15, 0, recordTopMenuMBNclr->mData, 0x60);
    NNS_GfdRegisterNewVramTransferTask(8, 0, recordTopMenuMNscr->mData, recordTopMenuMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gRecordTopMenu->mSecondScreenMapBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, recordTopMenuMNcgr->mData, recordTopMenuMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(14, 0, recordTopMenuMONclr->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(14, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, recordTopMenuSNcgr->mData, recordTopMenuSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, recordTopMenuSONclr->mData, recordTopMenuSONclr->mDataSize);
}

void SetRecordTopMenuRowOn(s32 row) {
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[row]].mVisible = 1;
    SetCellPaletteIndex(gRecordTopMenuRowCellIndices[row], 14, gRecordTopMenu->mRecordTopMenuSNcer,
                        gRecordTopMenu->mRecordTopMenuSBncl);
}

void SetRecordTopMenuRowOff(s32 row) {
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[row]].mVisible = 0;
    SetCellPaletteIndex(gRecordTopMenuRowCellIndices[row], 15, gRecordTopMenu->mRecordTopMenuSNcer,
                        gRecordTopMenu->mRecordTopMenuSBncl);
}

void ResetRecordTopMenu(void) {
    s32 i;
    s32 j;
    const u16 *labelRow;
    s32 mainLayoutCount;

    gRecordTopMenu->mNextState = 0;
    gRecordTopMenu->mStateFrames = 0;
    gRecordTopMenu->mBg0Offset = ~0xbf;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = ~0xbf;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mOffsetY = ~0xbf;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, labelRow = gRecordTopMenuLabelIndices[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = ~0xbf;
            labelRow++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = 0xe0;
        SetRecordTopMenuRowOff(i);
    }
}

// Requests state 1 for the next update.
void RequestRecordTopMenuState1(void) {
    gRecordTopMenu->mNextState = 1;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 2 for the next update.
void RequestRecordTopMenuState2(void) {
    gRecordTopMenu->mNextState = 2;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuState3(void) {
    gRecordTopMenu->mNextState = 3;
    gRecordTopMenu->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4 for the next update.
void RequestRecordTopMenuState4(void) {
    gRecordTopMenu->mNextState = 4;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuState5(void) {
    gRecordTopMenu->mNextState = 5;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

// Requests state 6 for the next update.
void RequestRecordTopMenuState6(void) {
    gRecordTopMenu->mNextState = 6;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 7 for the next update.
void RequestRecordTopMenuState7(void) {
    gRecordTopMenu->mNextState = 7;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuState8(void) {
    gRecordTopMenu->mNextState = 8;
    gRecordTopMenu->mStateFrames = 0;
    SetupTxtSystemSubText(GetBmgEntry(gRecordTopMenu->mUnk_20, 0x76));
}

void RequestRecordTopMenuState9(void) {
    gRecordTopMenu->mNextState = 9;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
}

void RequestRecordTopMenuState10(void) {
    gRecordTopMenu->mNextState = 10;
    gRecordTopMenu->mStateFrames = 0;
    RequestTxtSystemClose();
}

// Requests state 11 for the next update.
void RequestRecordTopMenuState11(void) {
    gRecordTopMenu->mNextState = 11;
    gRecordTopMenu->mStateFrames = 0;
}

void IncrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex++;
    if (gRecordTopMenu->mIndex >= 3) {
        gRecordTopMenu->mIndex = 0;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void DecrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex--;
    if (gRecordTopMenu->mIndex < 0) {
        gRecordTopMenu->mIndex = 2;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
}

void RefreshRecordTopMenuGradeCells(void) {
    s32 best = 7;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (IsGrandPrixRecordFilled(i, j)) {
                s32 v = GetGrandPrixRecordGrade(i, j);
                if (best > v) {
                    best = v;
                }
            } else {
                best = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mVisible = 0;
    }
    if (best > 4) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[best - 5]].mVisible = 1;
    }
}

void InitRecordTopMenu(void *heap) {
    u32 scores[3][3] = {0};
    u16 buf[16];
    s32 remainingSize;
    u16 labelEntryIndex;
    u16 mainLayoutCount;
    s32 i;
    s32 j;
    BackupFirstBlock **firstBlock;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x8800;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    gRecordTopMenu = HeapAlloc(heap, 0x48);
    gRecordTopMenu->mHeap = heap;
    gRecordTopMenu->mState = 0;
    switch (GetRecordPrevScreen()) {
        case 1:
        case 5:
            gRecordTopMenu->mIndex = 0;
            break;
        case 2:
            gRecordTopMenu->mIndex = 1;
            break;
        case 3:
            if (GetRecordCount()) {
                gRecordTopMenu->mIndex = 2;
            } else {
                gRecordTopMenu->mIndex = 0;
            }
            break;
    }
    LocateAndQueueRecordTopMenu();
    for (i = 0; i < 3; i++) {
        SetCellOamModeXlu(gRecordTopMenuXluCellIndices[i], 1, gRecordTopMenu->mRecordTopMenuSNcer,
                          gRecordTopMenu->mRecordTopMenuSBncl);
    }
    ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMBnll,
                    &gRecordTopMenu->mRecordTopMenuMTable);
    InitLayoutTable(heap, gRecordTopMenu->mRecordTopMenuSBncl, NULL, &gRecordTopMenu->mRecordTopMenuSTable);
    gRecordTopMenu->mUnk_20 = FindFileInLoadedArchives("common.bmg");
    gRecordTopMenu->mRecordMessages = FindSceneFile("record.bmg");
    remainingSize = 0x8000;
    remainingSize -=
        InitLabelCanvas(heap, 0, gRecordTopMenu->mRecordTopMenuMBnll, 0xaa, 0xe, 0, gRecordTopMenu->mRecordTopMenuMNcer,
                        gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordTopMenu->mRecordTopMenuMBnll,
                                       GetBmgEntry(gRecordTopMenu->mRecordMessages, 9),
                                       gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    labelEntryIndex = 1;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            remainingSize -=
                InitLabelCanvas(heap, gRecordTopMenuLabelIndices[i][j], gRecordTopMenu->mRecordTopMenuMBnll,
                                gRecordTopMenuLabelWidths[i][j], gRecordTopMenuLabelHeights[i][j], labelEntryIndex,
                                gRecordTopMenu->mRecordTopMenuMNcer, gRecordTopMenu->mRecordTopMenuMBncl,
                                gRecordTopMenu->mRecordTopMenuMTable, remainingSize);
            labelEntryIndex = mainLayoutCount + gRecordTopMenuLabelIndices[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        PrintLabelLayoutTextNoFixedAdvance(
            0, gRecordTopMenuLabelIndices[0][i], gRecordTopMenu->mRecordTopMenuMBnll,
            GetBmgEntry(gRecordTopMenu->mRecordMessages, gRecordTopMenuRecordMessageIndices[i]),
            gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    }
    firstBlock = &gBackupBuffers->mFirstBlock;
    scores[1][0] = (*firstBlock)->mTotals[0];
    scores[2][0] = (*firstBlock)->mTotals[1];
    scores[1][1] = (*firstBlock)->mTotals[2];
    scores[2][1] = (*firstBlock)->mTotals[3];
    scores[1][2] = (*firstBlock)->mTotals[4];
    scores[2][2] = (*firstBlock)->mTotals[5];
    for (i = 1; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (scores[i][j] > 9999) {
                scores[i][j] = 9999;
            }
            FormatAsciiNumber(scores[i][j], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordTopMenuLabelIndices[i][j], gRecordTopMenu->mRecordTopMenuMBnll,
                                             buf, gRecordTopMenu->mRecordTopMenuMBncl,
                                             gRecordTopMenu->mRecordTopMenuMTable, 6);
        }
    }
    RefreshRecordTopMenuGradeCells();
    ResetRecordTopMenu();
    SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
}

void ReleaseRecordTopMenu(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    gRecordTopMenu = NULL;
    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    mainDisplayBits &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    subDisplayBits &= ~0x1;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
}

void AdvanceRecordTopMenuState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestRecordTopMenuState1();
    }
}

void AdvanceRecordTopMenuState1(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s16 offsetY;
    const u16 *p;
    s32 mainLayoutCount;

    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mOffsetY = offsetY;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = gRecordTopMenuLabelIndices[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *p].mOffsetY = offsetY;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState2();
    }
}

void AdvanceRecordTopMenuState2(void) {
    s16 offsetX;
    s32 i;

    gRecordTopMenu->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTopMenu->mStateFrames);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState3();
    }
}

void AdvanceRecordTopMenuState3(void) {
    int returnState2NoRequest;
    returnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (returnState2NoRequest != 0) {
        RequestRecordTopMenuState4();
    }
}

void AdvanceRecordTopMenuState4(void) {
    InputSlotIndex slotIndex;
    u16 keyBPressed;
    BOOL touchBegan;
    s32 touchedRect;
    BOOL recentlyLost;
    BOOL touchBeganAgain;
    BOOL recentlyLostAgain;
    s32 rowIndex;

    touchBegan = FALSE;
    touchedRect = -1;
    slotIndex = UNK_02175628_INDEX_8;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchedRect = RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
        touchBeganAgain = FALSE;
        recentlyLostAgain = FALSE;
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
            goto skip;
        }
    }
    SetSelectReturnSoundId(15);
    RequestRecordTopMenuState6();
    gRecordTopMenu->mRecordScreen = 5;
    RequestSelectReturnState3WithSound(1);
    return;
skip:
    if ((u32) touchedRect <= 2) {
        rowIndex = gRecordTopMenuTouchRowIndices[touchedRect];
        if (gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[rowIndex]].mVisible != 0) {
            if (gRecordTopMenu->mIndex == rowIndex) {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = rowIndex;
            } else {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = rowIndex;
                SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
            }
            RequestRecordTopMenuState5();
        }
    } else {
        keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_A;
        if (keyBPressed != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            RequestRecordTopMenuState5();
        } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            DecrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            IncrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        }
    }
}

void AdvanceRecordTopMenuState5(void) {
    s16 offsetX;

    gRecordTopMenu->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTopMenu->mStateFrames);
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[gRecordTopMenu->mIndex]].mOffsetX = offsetX;
    if (gRecordTopMenu->mStateFrames == 5) {
        SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        if (gRecordTopMenu->mIndex == 2 && GetRecordCount() == 0) {
            RequestRecordTopMenuState7();
            return;
        }
        gRecordTopMenu->mRecordScreen = gRecordTopMenuRowRecordScreens[gRecordTopMenu->mIndex];
        RequestRecordTopMenuState6();
    }
}

void AdvanceRecordTopMenuState6(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s16 offsetY;
    const u16 *labelRow;
    s32 mainLayoutCount;

    if (GetRecordNextScene() == -1 && gRecordTopMenu->mRecordScreen == 5) {
        SetRecordNextScene(0);
    }
    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = offsetY;
    mainLayoutCount = gRecordTopMenu->mRecordTopMenuMBncl->mCount;
    gRecordTopMenu->mRecordTopMenuMTable[0].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[1].mOffsetY = offsetY;
    gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount].mOffsetY = offsetY;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[gRecordTopMenuGradeSTableIndices[i]].mOffsetY = offsetY;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, labelRow = gRecordTopMenuLabelIndices[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[mainLayoutCount + *labelRow].mOffsetY = offsetY;
            labelRow++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10 && GetRecordNextScene() == -1) {
        RequestRecordScreen(gRecordTopMenu->mRecordScreen);
    }
}

void AdvanceRecordTopMenuState7(void) {
    s16 offsetX;
    s32 i;

    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState8();
    }
}

void AdvanceRecordTopMenuState8(void) {
    int txtSystemNoCloseRequest;
    txtSystemNoCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (txtSystemNoCloseRequest != 0) {
        RequestRecordTopMenuState9();
    }
}

void AdvanceRecordTopMenuState9(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u16 keyBPressed;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;

    RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                            gInputSlots[slotIndex].mPair.mPairY);
    keyBPressed = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (keyBPressed == 0) {
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
            return;
        }
    }
    RequestRecordTopMenuState10();
    RequestSelectReturnState3WithSound(0);
}

void AdvanceRecordTopMenuState10(void) {
    int txtSystemNoOpenRequest;
    txtSystemNoOpenRequest = IsTxtSystemState0NoOpenRequest();
    if (txtSystemNoOpenRequest != 0) {
        RequestRecordTopMenuState11();
    }
}

void AdvanceRecordTopMenuState11(void) {
    s32 i;
    s16 offsetX;
    gRecordTopMenu->mStateFrames++;
    offsetX = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuXluCellIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowSTableIndices[i]].mOffsetX = offsetX;
        gRecordTopMenu->mRecordTopMenuSTable[gRecordTopMenuRowCellIndices[i]].mOffsetX = offsetX;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState3();
    }
}

void AdvanceRecordTopMenu(void) {
    RecordTopMenu *recordTopMenu;
    gRecordTopMenu->mState = gRecordTopMenu->mNextState;
    switch (gRecordTopMenu->mState) {
        case 0:
            AdvanceRecordTopMenuState0();
            break;
        case 1:
            AdvanceRecordTopMenuState1();
            break;
        case 2:
            AdvanceRecordTopMenuState2();
            break;
        case 3:
            AdvanceRecordTopMenuState3();
            break;
        case 4:
            AdvanceRecordTopMenuState4();
            break;
        case 5:
            AdvanceRecordTopMenuState5();
            break;
        case 6:
            AdvanceRecordTopMenuState6();
            break;
        case 7:
            AdvanceRecordTopMenuState7();
            break;
        case 8:
            AdvanceRecordTopMenuState8();
            break;
        case 9:
            AdvanceRecordTopMenuState9();
            break;
        case 10:
            AdvanceRecordTopMenuState10();
            break;
        case 11:
            AdvanceRecordTopMenuState11();
            break;
    }
    recordTopMenu = gRecordTopMenu;
    DrawLayoutTable(recordTopMenu->mRecordTopMenuMBncl, recordTopMenu->mRecordTopMenuMNcer,
                    recordTopMenu->mRecordTopMenuMBnll, GetRecordMainOam(), recordTopMenu->mRecordTopMenuMTable);
    recordTopMenu = gRecordTopMenu;
    DrawLayoutTable(recordTopMenu->mRecordTopMenuSBncl, recordTopMenu->mRecordTopMenuSNcer, NULL, GetRecordSubOam(),
                    recordTopMenu->mRecordTopMenuSTable);
}

void WriteRecordTopMenuBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordTopMenu->mBg0Offset << 16) & 0x1ff0000;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordTopMenuRegisters(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;
    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((mainDisplayBits | 0x11) << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 0x1) << 8);
}

void RegisterRecordTopMenuCallbacks(void) {
    RecordScreenCallbacks tbl = {InitRecordTopMenu, ReleaseRecordTopMenu, AdvanceRecordTopMenu,
                                 WriteRecordTopMenuBgOffsets, WriteRecordTopMenuRegisters};
    SetRecordScreenCallbacks(&tbl);
}
