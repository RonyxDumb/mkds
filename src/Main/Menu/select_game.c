#include "Main/Menu/select_game.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Menu/shuffled_indices.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "vram_bank_display_setup.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "sound_player_control.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/layout_rect_table.h"
#include "sound_archive_load_result.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

SelectGame *gSelectGame = NULL;
const LabelMessageRow gSelectGameLabelMessageRows[10] = {
    {0, 0xc8, 0xe, 0, 0x12}, {1, 0xc8, 0xe, 1, 0x13}, {2, 0xf0, 0x26, 2, 0xf}, {3, 0xf0, 0x26, 3, 0x10},
    {4, 0xc8, 0xe, 4, 0x11}, {5, 0xc8, 0xe, 5, 0x12}, {6, 0xc8, 0xe, 6, 0x13}, {7, 0xf0, 0x1e, 7, 0xe},
    {8, 0xf0, 0x26, 8, 0xf}, {9, 0xf0, 0x26, 9, 0x10}};
const SelectGameRow gSelectGameMultiRows[3] = {{6, 0, 0}, {7, 1, 1}, {8, 2, 2}};
const SelectGameRow gSelectGameBattleRows[2] = {{4, 0, 0}, {5, 1, 1}};
const SelectGameFileNames gSelectGameFileNames[2] = {
    {"common/select_game_battle_s.bncl", "common/select_game_battle_s.bnbl", "common/select_game_m_single.NSCR"},
    {"common/select_game_multi_s.bncl", "common/select_game_multi_s.bnbl", "common/select_game_m_multi.NSCR"}};

void WriteSelectGameRowToRaceSetupCopy(void) {
    BOOL battleKind;

    if (gSelectGame->mMode == SELECT_GAME_MODE_NO_CONNECTION) {
        GetRaceSetupCopy()->mMode = MODE_BATTLE;
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
        GetRaceSetupCopy()->mMode = MODE_VS;
    } else {
        GetRaceSetupCopy()->mMode = MODE_BATTLE;
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
    gSelectGame->mState = SELECT_GAME_STATE_WAIT_PRESS;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void SetSelectGameRowCellsVisible(s32 visible) {
    s32 rowIndex;
    CellFileSet *subFileSet;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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
    const LabelMessageRow *canvasRow;
    const LabelMessageRow *printRow;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectGame = HeapAlloc(heap, sizeof(SelectGame));
    MemFillWordsByBlock_inline(gSelectGame, 0x6c);
    gSelectGame->mHeap = heap;
    gSelectGame->mMode = mode;
    gSelectGame->mMainOam = mainOam;
    gSelectGame->mSubOam = subOam;
    gSelectGame->mSubOffsetX = SELECT_GAME_SUB_OFFSCREEN_X;
    gSelectGame->mMainOffsetY = -0xc0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gSelectGame->mMenuMessages = FindSceneFile("menu.bmg");
    }
    switch (gSelectGame->mMode) {
        case SELECT_GAME_MODE_NO_CONNECTION:
            gSelectGame->mState = SELECT_GAME_STATE_SLIDE_IN;
            gSelectGame->mTableCount = 2;
            gSelectGame->mTable = gSelectGameBattleRows;
            break;
        case SELECT_GAME_MODE_CONNECTION:
            gSelectGame->mState = SELECT_GAME_STATE_SLIDE_IN;
            gSelectGame->mTableCount = 3;
            gSelectGame->mTable = gSelectGameMultiRows;
            RefreshParticipantTables();
            break;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, screenMapFileSet, "common/select_game_m_b.NCGR",
                                       "common/select_game_m_b.NCLR",
                                       gSelectGameFileNames[gSelectGame->mMode].mScreenMapName, 1, FindSceneFile);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        mainObjSizeLeft = GX_GetSizeOfOBJ();
        selectGame = gSelectGame;
        LocateCellFileSet(selectGame, "common/select_game_m.nce.ncgr", "common/select_game_m.nce.ncer",
                          "common/select_game_m_o.NCLR", "common/select_game_m.bncl", "common/select_game_m.bnll", NULL,
                          FindSceneFile);
        SetupCellFileSet(SCREEN_SIDE_MAIN, gSelectGame->mHeap, selectGame->mCellFileSets);
        mainCellCount = selectGame->mCellFileSets[0].mCellLayout->mCount;
        mainLabelCount = selectGame->mCellFileSets[0].mLabelLayout->mCount;
        labelIndex = 0;
        if (mainLabelCount > 0) {
            canvasRow = gSelectGameLabelMessageRows;
            printRow = canvasRow;
            do {
                mainObjSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_MAIN, gSelectGame->mHeap, selectGame->mCellFileSets,
                                                    canvasRow, mainObjSizeLeft);
                PrintLabelLayoutTextNoFixedAdvance(0, printRow->mLabelIndex, selectGame->mCellFileSets[0].mLabelLayout,
                                                   GetBmgEntry(gSelectGame->mMenuMessages, printRow->mMessageIndex),
                                                   selectGame->mCellFileSets[0].mCellLayout,
                                                   selectGame->mCellFileSets[0].mCellTable);
                canvasRow++;
                printRow++;
                labelIndex++;
            } while (labelIndex < mainLabelCount);
        }
        if (gSelectGame->mMode == SELECT_GAME_MODE_NO_CONNECTION) {
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
    LocateCellFileSet(subFileSet, "common/select_game_s.nce.ncgr", "common/select_game_s.nce.ncer",
                      "common/select_game_s_o.NCLR", gSelectGameFileNames[gSelectGame->mMode].mCellLayoutName, NULL,
                      gSelectGameFileNames[gSelectGame->mMode].mRectsName, FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gSelectGame->mHeap, subFileSet);
    SetSelectGameSubCellsVisible(0);
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        SetSelectReturnSoundId(-1);
    } else {
        SetSelectReturnSoundId(0xe);
    }
    RequestSelectReturnSlideIn();
    if (gSelectGame->mMode == SELECT_GAME_MODE_CONNECTION) {
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
    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    selectGame = gSelectGame;
    subFileSet = &selectGame->mCellFileSets[1];
    switch (selectGame->mState) {
        case SELECT_GAME_STATE_SLIDE_IN:
            SetSelectGameSubCellsVisible(1);
            SetSelectGameSelectedRowVisible(1);
            gSelectGame->mStateFrames = gSelectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < SELECT_GAME_SLIDE_STEPS) {
                gSelectGame->mSubOffsetX =
                    InterpolateS16(1, SELECT_GAME_SUB_OFFSCREEN_X, value, gSelectGame->mStateFrames,
                                   SELECT_GAME_SLIDE_STEPS);
                gSelectGame->mMainOffsetY =
                    InterpolateS16(1, -0xc0, value, gSelectGame->mStateFrames, SELECT_GAME_SLIDE_STEPS);
            } else {
                gSelectGame->mStateFrames = value;
                gSelectGame->mSubOffsetX = value;
                gSelectGame->mMainOffsetY = value;
                gSelectGame->mState = SELECT_GAME_STATE_CHOOSE_ROW;
            }
            SetSelectGameCellTableOffsets();
            break;
        case SELECT_GAME_STATE_CHOOSE_ROW:
            previousSelectedIndex = selectGame->mSelectedIndex;
            touchValue = ~value;
            touchInReturnRect = 0;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                touchValue = gInputSlots[slotIndex].mPair.mPairX;
                pairY = gInputSlots[slotIndex].mPair.mPairY;
                touchInReturnRect = IsSelectReturnShownNoRequestAndInRect(touchValue, pairY);
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
                if (gSelectGame->mMode == SELECT_GAME_MODE_NO_CONNECTION) {
                    gSelectGame->mResult = MENU_SCREEN_RESULT_BACK;
                    gSelectGame->mState = SELECT_GAME_STATE_SLIDE_OUT;
                } else {
                    firstChoiceText = " ";
                    secondChoiceText = " ";
                    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                        firstChoiceText = GetBmgEntry(gSelectGame->mMenuMessages, 0x14);
                        secondChoiceText = GetBmgEntry(gSelectGame->mMenuMessages, 0x16);
                    }
                    StartSelectChoises(firstChoiceText, secondChoiceText, 0);
                    gSelectGame->mState = SELECT_GAME_STATE_ASK_LEAVE;
                    SetSelectGameRowCellsVisible(0);
                }
                RequestSelectReturnPressWithSound(0);
            } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP) != 0) {
                if (gSelectGame->mSelectedIndex == 0) {
                    if (gSelectGame->mMode == SELECT_GAME_MODE_CONNECTION) {
                        gSelectGame->mSelectedIndex = gSelectGame->mTableCount - 1;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex - 1;
                }
            } else if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN) != 0) {
                if (gSelectGame->mSelectedIndex == gSelectGame->mTableCount - 1) {
                    if (gSelectGame->mMode == SELECT_GAME_MODE_CONNECTION) {
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
        case SELECT_GAME_STATE_ASK_LEAVE:
            if (GetSelectChoisesDone() != 0) {
                if (GetSelectChoisesIndex() == 0 || GetSelectChoisesIndex() == ~value) {
                    gSelectGame->mState = SELECT_GAME_STATE_CHOOSE_ROW;
                } else {
                    gConnectionWork->mFlags |= CONNECTION_FLAG_ENDING;
                    gSelectGame->mResult = MENU_SCREEN_RESULT_LEAVE;
                    gSelectGame->mState = SELECT_GAME_STATE_WAIT_CONNECTION_END;
                }
                SetSelectGameRowCellsVisible(1);
                RequestSelectChoisesHidden();
            }
            break;
        case SELECT_GAME_STATE_WAIT_CONNECTION_END:
            if (AdvanceConnectionEndStopOnError() == 1) {
                value = gSelectGame->mResult;
                gSelectGame->mState = SELECT_GAME_STATE_RESULT_RETURNED;
            }
            break;
        case SELECT_GAME_STATE_WAIT_PRESS:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames >= SELECT_GAME_PRESS_START_STEP) {
                gSelectGame->mStateFrames = value;
                gSelectGame->mState = SELECT_GAME_STATE_PRESS_ANIMATION;
                SetSelectGameSelectedRowVisible(1);
            }
            break;
        case SELECT_GAME_STATE_PRESS_ANIMATION:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < SELECT_GAME_PRESS_STEPS) {
                gSelectGame->mSubOffsetX = GetSelectedPressOffset(gSelectGame->mStateFrames);
            } else {
                gSelectGame->mStateFrames = value;
                gSelectGame->mState = SELECT_GAME_STATE_SLIDE_OUT;
                if (gSelectGame->mMode != SELECT_GAME_MODE_NO_CONNECTION) {
                    RequestSelectReturnSlideOut();
                }
            }
            SetSelectGameRowOffsetX();
            break;
        case SELECT_GAME_STATE_SLIDE_OUT:
            selectGame->mStateFrames = selectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < SELECT_GAME_SLIDE_STEPS) {
                gSelectGame->mSubOffsetX =
                    InterpolateS16(1, value, SELECT_GAME_SUB_OFFSCREEN_X, gSelectGame->mStateFrames,
                                   SELECT_GAME_SLIDE_STEPS);
                gSelectGame->mMainOffsetY =
                    InterpolateS16(1, value, -0xc0, gSelectGame->mStateFrames, SELECT_GAME_SLIDE_STEPS);
            } else {
                gSelectGame->mSubOffsetX = value;
                gSelectGame->mMainOffsetY = value;
                gSelectGame->mState = SELECT_GAME_STATE_DONE;
            }
            SetSelectGameCellTableOffsets();
            break;
        case SELECT_GAME_STATE_DONE:
            value = selectGame->mResult;
            break;
    }
    if (gSelectGame->mState != SELECT_GAME_STATE_DONE) {
        if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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
    if (gSelectGame->mMode == SELECT_GAME_MODE_CONNECTION) {
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
    if (gSelectGame->mState != SELECT_GAME_STATE_DONE) {
        displayBits |= 2;
        bgControlBits = 3;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | bgControlBits;
    reg_G2_BG1OFS = (-gSelectGame->mMainOffsetY << 16) & 0x1ff0000;
    if (gSelectGame->mMainOffsetY != 0) {
        reg_GX_DISPCNT =
            (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
            (REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN1IN_MASK) | 0x1f00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0xd) | 0x20;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = windowEndY & 0xff;
        windowEndY = gSelectGame->mMainOffsetY + 0xc0;
        reg_G2_WIN1H = 0xff00;
        reg_G2_WIN1V = windowEndY & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    }
}

void LoadSelectGameData(void) {
    Ncgr *chars;
    Nclr *palette;
    NNSG2dCellDataBank *cells;
    Nscr *screenMap;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        LoadNcgrData(&chars, FindSceneFile("common/select_game_m_b.NCGR"));
        LoadNcgrData2(&chars, FindSceneFile("common/select_game_m.nce.ncgr"));
        LoadNcerData(&cells, FindSceneFile("common/select_game_m.nce.ncer"));
        LoadNclrData(&palette, FindSceneFile("common/select_game_m_b.NCLR"));
        LoadNclrData(&palette, FindSceneFile("common/select_game_m_o.NCLR"));
        LoadNscrData(&screenMap, FindSceneFile("common/select_game_m_multi.NSCR"));
        LoadNscrData(&screenMap, FindSceneFile("common/select_game_m_single.NSCR"));
    }
    LoadNcgrData2(&chars, FindSceneFile("common/select_game_s.nce.ncgr"));
    LoadNcerData(&cells, FindSceneFile("common/select_game_s.nce.ncer"));
    LoadNclrData(&palette, FindSceneFile("common/select_game_s_o.NCLR"));
}

#pragma thumb off
