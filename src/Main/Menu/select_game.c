#include "Main/Menu/select_game.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Menu/shuffled_indices.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Menu/select_return.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void WriteSelectGameRowToRaceSetupCopy(void) {
    BOOL battleKind;

    if (gSelectGame->mMode == 0) {
        GetRaceSetupCopy()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 0:
                battleKind = FALSE;
                break;
            default:
                battleKind = TRUE;
                break;
        }
        GetRaceSetupCopy()->mBattleKind = battleKind;
    } else if (gSelectGame->mSelectedIndex == 0) {
        GetRaceSetupCopy()->mMode = 3;
    } else {
        GetRaceSetupCopy()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 1:
                battleKind = FALSE;
                break;
            default:
                battleKind = TRUE;
                break;
        }
        GetRaceSetupCopy()->mBattleKind = battleKind;
    }
    gSelectGame->mResult = 1;
    gSelectGame->mState = 5;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void SetSelectGameRowCellsVisible(s32 visible) {
    s32 rowIndex;
    CellFileSet *subFileSet;

    if (gBootInfo->mBootType != 2) {
        subFileSet = &gSelectGame->mCellFileSets[1];
        for (rowIndex = 0; rowIndex < gSelectGame->mTableCount; rowIndex++) {
            subFileSet->mCellTable[gSelectGame->mTable[rowIndex].mCellIndex].mVisible = visible;
        }
    }
}

void SetSelectGameRowOffsetX(void) {
    s32 rowIndex;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (rowIndex = 0; rowIndex < gSelectGame->mTableCount; rowIndex++) {
        subFileSet->mCellTable[gSelectGame->mTable[rowIndex].mSelectedCellIndex].mOffsetX = gSelectGame->mSubOffsetX;
    }
}

void SetSelectGameCellTableOffsets(void) {
    CellFileSet *subFileSet;
    s32 cellIndex;
    s32 mainCellCount;
    s32 count;
    SelectGame *selectGame;

    if (gBootInfo->mBootType != 2) {
        selectGame = gSelectGame;
        mainCellCount = selectGame->mCellFileSets[0].mCellLayout->mCount;
        count = selectGame->mCellFileSets[0].mLabelLayout->mCount;
        for (cellIndex = 0; cellIndex < count; cellIndex++) {
            selectGame->mCellFileSets[0].mCellTable[cellIndex + mainCellCount].mOffsetY = gSelectGame->mMainOffsetY;
        }
    }
    subFileSet = &gSelectGame->mCellFileSets[1];
    count = subFileSet->mCellLayout->mCount;
    for (cellIndex = 0; cellIndex < count; cellIndex++) {
        subFileSet->mCellTable[cellIndex].mOffsetX = gSelectGame->mSubOffsetX;
    }
}

void SetSelectGameSelectedRowVisible(s32 showSelected) {
    BOOL visible;
    s32 rowIndex;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (rowIndex = 0; rowIndex < gSelectGame->mTableCount; rowIndex++) {
        if (rowIndex == gSelectGame->mSelectedIndex && showSelected != 0) {
            visible = TRUE;
        } else {
            visible = FALSE;
        }
        subFileSet->mCellTable[gSelectGame->mTable[rowIndex].mSelectedCellIndex].mVisible = visible;
    }
}

void SetSelectGameSubCellsVisible(s32 visible) {
    s32 cellIndex;
    CellFileSet *subFileSet;

    subFileSet = &gSelectGame->mCellFileSets[1];
    for (cellIndex = 0; cellIndex < subFileSet->mCellLayout->mCount; cellIndex++) {
        subFileSet->mCellTable[cellIndex].mVisible = visible;
    }
}

void InitSelectGame(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    SelectGame *selectGame;
    CellFileSet *subFileSet;
    u8 screenMapFileSet[0x28];
    u32 mainObjSizeLeft;
    s32 labelIndex;
    s32 mainCellCount;
    s32 mainLabelCount;
    s32 hiddenLabelIndex;
    s32 hiddenLabelStart;
    s32 hiddenLabelCount;
    LabelMessageRow *canvasRow;
    LabelMessageRow *printRow;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectGame = HeapAlloc(heap, 0x6c);
    MemFillWordsByBlock_inline(gSelectGame, 0x6c);
    gSelectGame->mHeap = heap;
    gSelectGame->mMode = mode;
    gSelectGame->mMainOam = mainOam;
    gSelectGame->mSubOam = subOam;
    gSelectGame->mSubOffsetX = 0xee;
    gSelectGame->mMainOffsetY = -0xc0;
    if (gBootInfo->mBootType != 2) {
        gSelectGame->mMenuMessages = FindSceneFile(gMenuBmgName);
    }
    switch (gSelectGame->mMode) {
        case 0:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 2;
            gSelectGame->mTable = data_02153de8;
            break;
        case 1:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 3;
            gSelectGame->mTable = data_02153df4;
            RefreshParticipantTables();
            break;
    }
    if (gBootInfo->mBootType != 2) {
        LocateAndQueueScreenMapFileSet(0, screenMapFileSet, gSelectGameMBNcgrName2, gSelectGameMBNclrName2,
                                       data_02153e10[gSelectGame->mMode].mUnk_00, 1, FindSceneFile);
    }
    if (gBootInfo->mBootType != 2) {
        mainObjSizeLeft = GX_GetSizeOfOBJ();
        selectGame = gSelectGame;
        LocateCellFileSet(selectGame, gSelectGameMNceNcgrName2, gSelectGameMNceNcerName2, gSelectGameMONclrName2,
                          gSelectGameMBnclName, gSelectGameMBnllName, NULL, FindSceneFile);
        SetupCellFileSet(0, gSelectGame->mHeap, selectGame->mCellFileSets);
        mainCellCount = selectGame->mCellFileSets[0].mCellLayout->mCount;
        mainLabelCount = selectGame->mCellFileSets[0].mLabelLayout->mCount;
        labelIndex = 0;
        if (mainLabelCount > 0) {
            canvasRow = gSelectGameLabelMessageRows;
            printRow = canvasRow;
            do {
                mainObjSizeLeft -=
                    SetupLabelCanvas(0, gSelectGame->mHeap, selectGame->mCellFileSets, canvasRow, mainObjSizeLeft);
                PrintLabelLayoutTextNoFixedAdvance(0, printRow->mLabelIndex, selectGame->mCellFileSets[0].mLabelLayout,
                                                   GetBmgEntry(gSelectGame->mMenuMessages, printRow->mMessageIndex),
                                                   selectGame->mCellFileSets[0].mCellLayout,
                                                   selectGame->mCellFileSets[0].mCellTable);
                canvasRow++;
                printRow++;
                labelIndex++;
            } while (labelIndex < mainLabelCount);
        }
        if (gSelectGame->mMode == 0) {
            hiddenLabelStart = 4;
            hiddenLabelCount = 6;
        } else {
            hiddenLabelStart = 0;
            hiddenLabelCount = 4;
        }
        for (hiddenLabelIndex = hiddenLabelStart; hiddenLabelIndex < hiddenLabelStart + hiddenLabelCount;
             hiddenLabelIndex++) {
            selectGame->mCellFileSets[0].mCellTable[hiddenLabelIndex + mainCellCount].mVisible = 0;
        }
    }
    subFileSet = &gSelectGame->mCellFileSets[1];
    LocateCellFileSet(subFileSet, gSelectGameSNceNcgrName2, gSelectGameSNceNcerName2, gSelectGameSONclrName2,
                      data_02153e08[gSelectGame->mMode].mUnk_00, NULL, data_02153e0c[gSelectGame->mMode].mUnk_00,
                      FindSceneFile);
    SetupCellFileSet(1, gSelectGame->mHeap, subFileSet);
    SetSelectGameSubCellsVisible(0);
    if (gBootInfo->mBootType == 2) {
        SetSelectReturnSoundId(-1);
    } else {
        SetSelectReturnSoundId(0xe);
    }
    RequestSelectReturnState1();
    if (gSelectGame->mMode == 1) {
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xf);
    }
    gMenuShared->mMenuEntryKind = 0;
    FrmHeapShrinkInParent(gSelectGame->mHeap);
}

s32 AdvanceSelectGame(void) {
    s32 value;
    InputSlotIndex slotIndex;
    SelectGame *selectGame;
    CellFileSet *subFileSet;
    s32 previousSelectedIndex;
    s32 touchInReturnRect;
    s32 touchValue;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    s32 pairY;
    s32 unusedValue;
    u32 hasPair;
    s32 rowIndex;
    const void *firstChoiceText;
    const void *secondChoiceText;

    value = 0;
    slotIndex = UNK_02175628_INDEX_8;
    selectGame = gSelectGame;
    subFileSet = &selectGame->mCellFileSets[1];
    switch (selectGame->mState) {
        case 3:
            SetSelectGameSubCellsVisible(1);
            SetSelectGameSelectedRowVisible(1);
            gSelectGame->mStateFrames = gSelectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = InterpolateS16(1, 0xee, value, gSelectGame->mStateFrames, 10);
                gSelectGame->mMainOffsetY = InterpolateS16(1, -0xc0, value, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mStateFrames = value;
                gSelectGame->mSubOffsetX = value;
                gSelectGame->mMainOffsetY = value;
                gSelectGame->mState = 4;
            }
            SetSelectGameCellTableOffsets();
            break;
        case 4:
            previousSelectedIndex = selectGame->mSelectedIndex;
            touchValue = ~value;
            touchInReturnRect = 0;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                touchValue = gInputSlots[slotIndex].mPair.mPairX;
                pairY = gInputSlots[slotIndex].mPair.mPairY;
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(touchValue, pairY);
                touchValue = RectTableFindContaining(subFileSet->mRects, touchValue, pairY);
            }
            if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
                SetSelectGameSelectedRowVisible(0);
                WriteSelectGameRowToRaceSetupCopy();
            } else if (touchValue >= 0) {
                for (rowIndex = 0; rowIndex < gSelectGame->mTableCount; rowIndex++) {
                    if (touchValue == gSelectGame->mTable[rowIndex].mRectEntryId) {
                        SetSelectGameSelectedRowVisible(gSelectGame->mSelectedIndex != rowIndex ? 1 : 0);
                        gSelectGame->mSelectedIndex = rowIndex;
                        WriteSelectGameRowToRaceSetupCopy();
                        break;
                    }
                }
            } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                if (gSelectGame->mMode == 0) {
                    gSelectGame->mResult = 2;
                    gSelectGame->mState = 9;
                } else {
                    firstChoiceText = data_02163aec;
                    secondChoiceText = data_02163af0;
                    if (gBootInfo->mBootType != 2) {
                        firstChoiceText = GetBmgEntry(gSelectGame->mMenuMessages, 0x14);
                        secondChoiceText = GetBmgEntry(gSelectGame->mMenuMessages, 0x16);
                    }
                    StartSelectChoises(firstChoiceText, secondChoiceText, 0);
                    gSelectGame->mState = 7;
                    SetSelectGameRowCellsVisible(0);
                }
                RequestSelectReturnState3WithSound(0);
            } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
                if (gSelectGame->mSelectedIndex == 0) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = gSelectGame->mTableCount - 1;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex - 1;
                }
            } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
                if (gSelectGame->mSelectedIndex == gSelectGame->mTableCount - 1) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = 0;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex + 1;
                }
            }
            if (touchValue < 0 && previousSelectedIndex != gSelectGame->mSelectedIndex) {
                SetSelectGameSelectedRowVisible(1);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            }
            break;
        case 7:
            if (GetSelectChoisesDone() != 0) {
                if (GetSelectChoisesIndex() == 0 || GetSelectChoisesIndex() == ~value) {
                    gSelectGame->mState = 4;
                } else {
                    gConnectionWork->mFlags |= CONNECTION_FLAG_ENDING;
                    gSelectGame->mResult = 3;
                    gSelectGame->mState = 8;
                }
                SetSelectGameRowCellsVisible(1);
                RequestSelectChoisesState0();
            }
            break;
        case 8:
            if (AdvanceConnectionEndStopOnError() == 1) {
                value = gSelectGame->mResult;
                gSelectGame->mState = 11;
            }
            break;
        case 5:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames >= 5) {
                gSelectGame->mStateFrames = value;
                gSelectGame->mState = 6;
                SetSelectGameSelectedRowVisible(1);
            }
            break;
        case 6:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = GetSelectedPressOffset(gSelectGame->mStateFrames);
            } else {
                gSelectGame->mStateFrames = value;
                gSelectGame->mState = 9;
                if (gSelectGame->mMode != 0) {
                    RequestSelectReturnState4();
                }
            }
            SetSelectGameRowOffsetX();
            break;
        case 9:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mSubOffsetX = InterpolateS16(1, value, 0xee, gSelectGame->mStateFrames, 10);
                gSelectGame->mMainOffsetY = InterpolateS16(1, value, -0xc0, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mSubOffsetX = value;
                gSelectGame->mMainOffsetY = value;
                gSelectGame->mState = 10;
            }
            SetSelectGameCellTableOffsets();
            break;
        case 10:
            value = selectGame->mResult;
            break;
    }
    if (gSelectGame->mState != 10) {
        if (gBootInfo->mBootType != 2) {
            DrawLayoutTable(selectGame->mCellFileSets[0].mCellLayout, selectGame->mCellFileSets[0].mCells,
                            selectGame->mCellFileSets[0].mLabelLayout, gSelectGame->mMainOam,
                            selectGame->mCellFileSets[0].mCellTable);
        }
        DrawLayoutTable(subFileSet->mCellLayout, subFileSet->mCells, subFileSet->mLabelLayout, gSelectGame->mSubOam,
                        subFileSet->mCellTable);
    }
    return value;
}

void ReleaseSelectGame(void) {
    if (gSelectGame->mMode == 1) {
        RequestPlayerEntryListSetup();
        if (gStartupWork->mMultiSimple != 0) {
            FillShuffledIndices();
        }
    }
    HeapDestroy(gSelectGame->mHeap);
    gSelectGame = NULL;
}

void WriteSelectGameMainRegisters(void) {
    u32 displayBits;
    u32 bgControlBits;
    s32 windowEndY;

    displayBits = 0x18;
    bgControlBits = 0;
    if (gSelectGame->mState != 10) {
        displayBits |= 2;
        bgControlBits = 3;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | bgControlBits;
    reg_G2_BG1OFS = (-gSelectGame->mMainOffsetY << 16) & 0x1ff0000;
    if (gSelectGame->mMainOffsetY != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & 0xffffc0ff) | 0x1f00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xd) | 0x20;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = windowEndY & 0xff;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN1H = 0xff00;
        reg_G2_WIN1V = windowEndY & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    }
}

void LoadSelectGameData(void) {
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap;

    if (gBootInfo->mBootType != 2) {
        LoadNcgrData(&chars, FindSceneFile(gSelectGameMBNcgrName));
        LoadNcgrData2(&chars, FindSceneFile(gSelectGameMNceNcgrName));
        LoadNcerData(&cells, FindSceneFile(gSelectGameMNceNcerName));
        LoadNclrData(&palette, FindSceneFile(gSelectGameMBNclrName));
        LoadNclrData(&palette, FindSceneFile(gSelectGameMONclrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectGameMMultiNscrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectGameMSingleNscrName));
    }
    LoadNcgrData2(&chars, FindSceneFile(gSelectGameSNceNcgrName));
    LoadNcerData(&cells, FindSceneFile(gSelectGameSNceNcerName));
    LoadNclrData(&palette, FindSceneFile(gSelectGameSONclrName));
}

#pragma thumb off
