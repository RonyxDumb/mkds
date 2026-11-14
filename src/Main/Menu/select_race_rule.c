#include "Main/Menu/select_race_rule.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record.h"
#include "Main/Graphics/oam.h"
#include "Main/System/thread_function_queue_run.h"
#include "registers.h"
#include "Main/Menu/select_cup_m.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/palette_blend.h"
#include "Main/Menu/data_0215c000.h"
#include "Main/Menu/data_0216d000.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "player.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "gfd_VramTransferManager.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/wait.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Race/ghost_record_set.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0212df7c.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Menu/select_cup_course_index.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/select_race_rule_load.h"
#include "Main/Menu/select_cup_course.h"

#pragma thumb on

void AdvanceSelectRaceRuleState6(void) {
    if (GetSelectChoisesDone() != 0) {
        RequestSelectRaceRuleState7();
        switch (GetSelectChoisesIndex()) {
            case 0:
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 7);
                break;
            case -1:
            case 1:
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x10);
                break;
        }
    }
}

void AdvanceSelectRaceRuleState7(void) {
    if (IsSelectChoisesState0NoState1Request() != 0) {
        switch (GetSelectChoisesIndex()) {
            case 0:
                RequestSelectRaceRuleState8();
                gSelectRaceRule->mResult = 1;
                StartPlayerEntryListKind(3);
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectRaceRuleState3();
                break;
        }
    }
}

void AdvanceSelectRaceRuleState8(void) {
    SelectRaceRule *selectRaceRule;
    s32 rowIndex;
    s16 returnOffsetY;
    s16 rowsOffsetY;
    s32 cellIndex;
    s32 value;
    gSelectRaceRule->mStateFrames++;
    selectRaceRule = gSelectRaceRule;
    value = InterpolateS16(1, 0, -192, selectRaceRule->mStateFrames, SELECT_RACE_RULE_SLIDE_STEPS);
    rowsOffsetY = selectRaceRule->mOffsetY + value;
    returnOffsetY = -LookupSelectReturnState4Bg2Offset(selectRaceRule->mStateFrames);
    gSelectRaceRule->mBg3Offset = rowsOffsetY;
    value = gSelectRaceRule->mBncl->mCount;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][cellIndex]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][cellIndex]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][cellIndex]].mOffsetY = rowsOffsetY;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gSelectRaceRule->mTable[value + gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[cellIndex]].mOffsetY =
                rowsOffsetY;
        }
    }
    gSelectRaceRule->mTable[value + 10].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[value + 12].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[34].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[37].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[35].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[38].mOffsetY = rowsOffsetY;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[rowIndex][cellIndex]].mOffsetY = rowsOffsetY;
        }
    }
    if (gStartupWork->mConnectionKind != 2) {
        gSelectRaceRule->mTable[40].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[41].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[value + 13].mOffsetY = returnOffsetY;
        value += 8;
        gSelectRaceRule->mTable[value].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[30].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[31].mOffsetY = rowsOffsetY;
    } else {
        gSelectRaceRule->mTable[42].mOffsetY = returnOffsetY;
        value += 14;
        gSelectRaceRule->mTable[value].mOffsetY = returnOffsetY;
    }
}

void DrawSelectRaceRuleOffsetLabel(s32 labelIndex) {
    s32 tableIndex;
    tableIndex = gSelectRaceRule->mBncl->mCount + labelIndex;
    gSelectRaceRule->mTable[tableIndex].mOffsetY++;
    SetLabelPaletteIndex(labelIndex, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
    DrawLayoutTableEntry(tableIndex, gSelectRaceRule->mBncl, gSelectRaceRule->mNcer, gSelectRaceRule->mBnll,
                         gSelectRaceRule->mOamList, gSelectRaceRule->mTable);
    gSelectRaceRule->mTable[tableIndex].mOffsetY--;
    SetLabelPaletteIndex(labelIndex, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
}

void DrawSelectRaceRuleRowOffsetLabels(s32 row) {
    if (row == SELECT_RACE_RULE_ROW_RULE_KIND) {
        if (gStartupWork->mConnectionKind != 2) {
            DrawSelectRaceRuleOffsetLabel(gSelectRaceRuleRowEntries[row].mEntryIndices[1]);
        }
        DrawSelectRaceRuleOffsetLabel(10);
    } else if (row == SELECT_RACE_RULE_ROW_TEAMS) {
        DrawSelectRaceRuleOffsetLabel(gSelectRaceRuleRowEntries[row].mEntryIndices[1]);
        DrawSelectRaceRuleOffsetLabel(12);
    } else {
        DrawSelectRaceRuleOffsetLabel(gSelectRaceRuleRowEntries[row].mEntryIndices[1]);
    }
}

s32 AdvanceSelectRaceRule(void) {
    SelectRaceRule *selectRaceRule;
    s32 rowIndex;
    gSelectRaceRule->mState = gSelectRaceRule->mNextState;
    gSelectRaceRule->mPrevRow = gSelectRaceRule->mRow;
    gSelectRaceRule->mPrevOnButton = gSelectRaceRule->mOnButton;
    switch (gSelectRaceRule->mState) {
        case SELECT_RACE_RULE_STATE_WAIT_FADE:
            AdvanceSelectRaceRuleState0();
            break;
        case SELECT_RACE_RULE_STATE_SLIDE_IN:
            AdvanceSelectRaceRuleState1();
            break;
        case SELECT_RACE_RULE_STATE_WAIT_RETURN:
            AdvanceSelectRaceRuleState2();
            break;
        case SELECT_RACE_RULE_STATE_CHOOSE:
            AdvanceSelectRaceRuleState3();
            break;
        case SELECT_RACE_RULE_STATE_WAIT_PRESS:
            AdvanceSelectRaceRuleState4();
            break;
        case SELECT_RACE_RULE_STATE_WAIT_CONFIRM_OPEN:
            AdvanceSelectRaceRuleState5();
            break;
        case SELECT_RACE_RULE_STATE_WAIT_CONFIRM_CHOICES:
            AdvanceSelectRaceRuleState6();
            break;
        case SELECT_RACE_RULE_STATE_WAIT_CONFIRM_ANSWER:
            AdvanceSelectRaceRuleState7();
            break;
        case SELECT_RACE_RULE_STATE_SLIDE_OUT:
            AdvanceSelectRaceRuleState8();
            break;
    }
    if (gStartupWork->mConnectionKind == 2) {
        AdvanceWait();
    }
    switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS]) {
        case 0:
            SetPlayerEntryListUseTeams(0);
            break;
        case 1:
        case 2:
            SetPlayerEntryListUseTeams(1);
            break;
    }
    AdvancePlayerEntryList();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        AdvancePaletteBlend();
    }
    AdvanceSelectRaceRuleHighlight();
    AdvanceSelectRaceRuleValueObjects();
    PrintSelectRaceRuleRow4Message();
    selectRaceRule = gSelectRaceRule;
    DrawLayoutTable(selectRaceRule->mBncl, selectRaceRule->mNcer, selectRaceRule->mBnll, selectRaceRule->mOamList,
                    selectRaceRule->mTable);
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        DrawSelectRaceRuleRowOffsetLabels(rowIndex);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mState == SELECT_RACE_RULE_STATE_SLIDE_OUT) {
        if (selectRaceRule->mResult == 1 && (selectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE ||
                                             selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_COURSE_LIST] == 1)) {
            if (selectRaceRule->mStateFrames >= SELECT_RACE_RULE_SLIDE_STEPS &&
                IsSelectReturnState0NoState1Request() != 0) {
                return gSelectRaceRule->mResult;
            }
        } else if (selectRaceRule->mStateFrames >= SELECT_RACE_RULE_SLIDE_STEPS) {
            return selectRaceRule->mResult;
        }
    }
    return 0;
}

void WriteSelectRaceRuleRegisters(void) {
    reg_G2S_DB_BG3OFS = (-gSelectRaceRule->mBg3Offset << 16) & 0x1ff0000;
    WritePlayerEntryListRegisters();
}

void LoadSelectCupCourseData(void) {
    Ncgr *cellChars = NULL;
    NNSG2dCellDataBank *cells = NULL;
    Nclr *cellPalette = NULL;
    Ncgr *bgChars = NULL;
    Nscr *screenMap = NULL;
    Nclr *bgPalette = NULL;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        LoadNcgrData(&bgChars, FindSceneFile(gSelectCupCourseTaMBNcgrName));
        LoadNclrData(&bgPalette, FindSceneFile(gSelectCupCourseTaMBNclrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectCupCourseTaMNscrName));
        LoadNcgrData(&bgChars, FindSceneFile(gSelectCupCourseVsMBNcgrName));
        LoadNclrData(&bgPalette, FindSceneFile(gSelectCupCourseVsMBNclrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectCupCourseVsMNscrName));
        LoadNcgrData2(&cellChars, FindSceneFile(gSelectCupCourseMNcgrName));
        LoadNcerData(&cells, FindSceneFile(gSelectCupCourseMNcerName2));
        LoadNclrData(&cellPalette, FindSceneFile(gSelectCupCourseMONclrName));
    }
}

void LocateAndQueueSelectCupCourse(void) {
    Ncgr *courseCellChars = NULL;
    Nclr *courseCellPalette = NULL;
    Ncgr *cupCellChars = NULL;
    Nclr *cupCellPalette = NULL;
    Ncgr *modeChars = NULL;
    Nscr *modeScreenMap = NULL;
    Nclr *modePalette = NULL;
    Ncgr *fixedChars = NULL;
    Nscr *fixedScreenMap = NULL;
    Nclr *fixedPalette = NULL;
    u16 *courseCellPaletteData;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(gSelectCupCourseCupMBnblName);
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        LocateNcgr(&modeChars, FindSceneFile(gSelectCupCourseTaMBNcgrName));
        LocateNclr(&modePalette, FindSceneFile(gSelectCupCourseTaMBNclrName));
        LocateNscr(&modeScreenMap, FindSceneFile(gSelectCupCourseTaMNscrName));
    } else {
        LocateNcgr(&modeChars, FindSceneFile(gSelectCupCourseVsMBNcgrName));
        LocateNclr(&modePalette, FindSceneFile(gSelectCupCourseVsMBNclrName));
        LocateNscr(&modeScreenMap, FindSceneFile(gSelectCupCourseVsMNscrName));
    }
    LocateNcgr(&fixedChars, FindSceneFile(gSelectCupMBNcgrName));
    LocateNclr(&fixedPalette, FindSceneFile(gSelectCupMBNclrName));
    LocateNscr(&fixedScreenMap, FindSceneFile(gSelectCupMNscrName));
    gSelectCupCourse->mSecondScreenMapBuffer = HeapAlloc(gSelectCupCourse->mHeap, 0x800);
    if (gSelectCupCourse->mMode == 0) {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(gSelectCupCourseTaMBnclName2);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(gSelectCupCourseTaMBnllName2);
    } else {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(gSelectCupCourseVsMBnclName);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(gSelectCupCourseVsMBnllName);
    }
    LocateNcgr2(&courseCellChars, FindSceneFile(gSelectCupCourseMNcgrName));
    LocateNcer(&gSelectCupCourse->mSelectCupCourseMNcer, FindSceneFile(gSelectCupCourseMNcerName2));
    LocateNclr(&courseCellPalette, FindSceneFile(gSelectCupCourseMONclrName));
    gSelectCupCourse->mSelectCupMBncl = FindSceneFile(gSelectCupMBnclName);
    gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(gSelectCupCourseCupMBnblName);
    gSelectCupCourse->mSelectCupMBnll = FindSceneFile(gSelectCupMBnllName);
    LocateNcgr2(&cupCellChars, FindSceneFile(gSelectCupMNcgrName));
    LocateNcer(&gSelectCupCourse->mSelectCupMNcer, FindSceneFile(gSelectCupMNcerName));
    LocateNclr(&cupCellPalette, FindSceneFile(gSelectCupMONclrName));
    courseCellPaletteData = courseCellPalette->mData;
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_TILES, 0, modeChars->mData, modeChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG_PALETTE, 0, modePalette->mData, 0x140);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0, modeScreenMap->mData,
                                       modeScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0x800, gSelectCupCourse->mSecondScreenMapBuffer,
                                       0x800);
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_TILES, 0, fixedChars->mData, fixedChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0, fixedPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, 0, fixedScreenMap->mData,
                                           fixedScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, 0x800,
                                           gSelectCupCourse->mSecondScreenMapBuffer, 0x800);
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, 0, courseCellChars->mData,
                                       courseCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0, courseCellPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1c0, courseCellPaletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, cupCellChars->mData,
                                       cupCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, cupCellPalette->mData,
                                       cupCellPalette->mDataSize);
}

void SetupSelectCupCourseObjects(void) {
    s32 cellIndex;
    u32 courseEntryCount;
    u32 cupEntryCount;
    SelectCupCourse *selectCupCourse;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        courseEntryCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mCount;
        cupEntryCount = gSelectCupCourse->mSelectCupMBncl->mCount;
        for (cellIndex = 0; cellIndex < 8; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseRecordCells[cellIndex]].mVisible = 0;
        }
        for (cellIndex = 0; cellIndex < 4; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseTrophyCells[cellIndex]].mVisible = 0;
        }
        for (cellIndex = 0; cellIndex < 4; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[cellIndex]].mVisible = 0;
            gSelectCupCourse->mSelectCupMTable[cupEntryCount + gSelectCupCourseLabelIndices[cellIndex]].mVisible = 1;
        }
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 1;
        gSelectCupCourse->mSelectCupMTable[0x14].mVisible = 0;
        gSelectCupCourse->mSelectCupMTable[0x13].mVisible = 1;
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(gCupRowsByCupIndex[GetCupIndex()], selectCupCourse->mSelectCupCourseMNcer,
                            selectCupCourse->mSelectCupCourseTaOrVsMBncl, 0, 0);
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(gCupRowsByCupIndex[GetCupIndex()], selectCupCourse->mSelectCupMNcer,
                            selectCupCourse->mSelectCupMBncl, 0x13, 1);
        selectCupCourse = gSelectCupCourse;
        cellIndex = GetCupIndex();
        QueueCupMark(gCupRowsByCupIndex[cellIndex], selectCupCourse->mSelectCupCourseMNcer,
                     selectCupCourse->mSelectCupCourseTaOrVsMBncl, 5,
                     GetCellPaletteIndex(5, selectCupCourse->mSelectCupCourseMNcer,
                                         selectCupCourse->mSelectCupCourseTaOrVsMBncl),
                     0);
        for (cellIndex = 0; cellIndex < 4; cellIndex++) {
            selectCupCourse = gSelectCupCourse;
            PrintLabelLayoutTextNoFixedAdvance(
                1, gSelectCupCourseLabelIndices[cellIndex], gSelectCupCourse->mSelectCupMBnll,
                GetBmgEntry(gSelectCupCourse->mCommonMessages,
                            gCupCourseNameMessageIndices[gCupRowsByCupIndex[GetCupIndex()]][cellIndex]),
                selectCupCourse->mSelectCupMBncl, selectCupCourse->mSelectCupMTable);
        }
        selectCupCourse = gSelectCupCourse;
        PrintLabelLayoutTextNoFixedAdvance(
            0, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, GetBmgEntry(selectCupCourse->mCommonMessages, 0x73),
            selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        PrintLabelLayoutTextNoFixedAdvance(
            0, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, GetBmgEntry(selectCupCourse->mCommonMessages, 0x74),
            selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        SetLabelOamModeXlu(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        SetLabelOamModeXlu(1, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        SetLabelOamModeXlu(2, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        SetLabelOamModeXlu(4, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        selectCupCourse = gSelectCupCourse;
        switch (selectCupCourse->mMode) {
            case 1:
            case 2:
            case 3:
                selectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 0;
                break;
        }
    }
}

void AdvanceSelectCupCourseHighlight(void) {
    s32 labelIndex;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        for (labelIndex = 0; labelIndex < 4; labelIndex++) {
            if (gSelectCupCourse->mIndex == labelIndex && gSelectCupCourse->mHighlightShown != FALSE) {
                gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[labelIndex]].mVisible = 1;
                SetLabelPaletteIndex(gSelectCupCourseLabelIndices[labelIndex], 0xe, gSelectCupCourse->mSelectCupMBnll,
                                     gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            } else {
                gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[labelIndex]].mVisible = 0;
                SetLabelPaletteIndex(gSelectCupCourseLabelIndices[labelIndex], 0xf, gSelectCupCourse->mSelectCupMBnll,
                                     gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            }
        }
    }
}

void RefreshSelectCupCourseForIndex(void) {
    SelectCupCourse *selectCupCourse;
    u32 recordTime;
    u8 timeText[0x24];
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        selectCupCourse = gSelectCupCourse;
        PrintLabelLayoutTextNoFixedAdvance(
            0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
            GetBmgEntry(gSelectCupCourse->mCommonMessages,
                        gCupCourseNameMessageIndices[gCupRowsByCupIndex[GetCupIndex()]][selectCupCourse->mIndex]),
            selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        PrintLabelLayoutTextNoFixedAdvance(
            0, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
            GetBmgEntry(gSelectCupCourse->mCommonMessages,
                        gCupCourseNameMessageIndices[gCupRowsByCupIndex[GetCupIndex()]][selectCupCourse->mIndex]),
            selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        if (IsTimeRecordFilled(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex], 0)) {
            GetTimeRecordTime(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex], 0,
                              &recordTime);
            FormatTimeFullWidth(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            PrintLabelLayoutTextFixedDigits(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                                            selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                                            selectCupCourse->mSelectCupCourseTaOrVsMTable, 9);
        } else {
            selectCupCourse = gSelectCupCourse;
            PrintLabelLayoutTextFixedDigits(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, L"--\xff1a--\xff1a---",
                                            selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                                            selectCupCourse->mSelectCupCourseTaOrVsMTable, 9);
        }
        if (IsTimeRecordFilled(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex], 5)) {
            GetTimeRecordTime(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex], 5,
                              &recordTime);
            FormatTimeFullWidth(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            PrintLabelLayoutTextFixedDigits(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                                            selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                                            selectCupCourse->mSelectCupCourseTaOrVsMTable, 9);
        } else {
            selectCupCourse = gSelectCupCourse;
            PrintLabelLayoutTextFixedDigits(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, L"--:--:---",
                                            selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                                            selectCupCourse->mSelectCupCourseTaOrVsMTable, 9);
        }
        TrySetCupPictureIndexAndQueueLoads(
            gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex]);
        gSelectCupCourse->mCupPicturePending = TRUE;
    }
}

void SetCourseIdFromSelectCupCourse(void) {
    SetCourseId(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex]);
}

void SetupGhostRecordSetForCupCourse(void) {
    SetupGhostRecordSetForCourse(gCupRowCourseIds[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex]);
    SetRaceSetupCopyGhostRecordIndex(0);
}

#pragma thumb off
