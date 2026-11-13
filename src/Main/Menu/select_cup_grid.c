#include "Main/Menu/select_cup_grid.h"

#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Menu/trophy_icon.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_0215c000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "gfd_VramTransferManager.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "registers.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/time_format.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Save/buddy_record.h"
#include "Main/System/thread_function_queue_run.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

char *gSelectCupGridSBnblName = "common/select_cup_s.bnbl";
const u16 gSelectCupGridCourseLabelWidths[4] = {0xa3, 0xa3, 0xa3, 0xa3};
const u32 gSelectCupGridEngineFlagIndices[8][3] = {{0x1b, 0x1b, 0x1b}, {0x1b, 0x1b, 0x1b}, {0, 1, 2},
                                                   {4, 5, 6},          {0x1b, 0x1b, 0x1b}, {0x1b, 0x1b, 0x1b},
                                                   {8, 9, 0xa},        {0xc, 0xd, 0xe}};
const u32 gSelectCupGridMirrorFlagIndices[8] = {0x10, 0x10, 3, 7, 0x10, 0x10, 0xb, 0xf};
char *gSelectCupGridSNcgrName = "common/select_cup_s.nce.ncgr";
const s32 gSelectCupGridRecordEngineClasses[4] = {0, 1, 2, 3};
const u16 gSelectCupGridCourseLabelIndices[4] = {3, 2, 1, 0};
const s16 gSelectCupGridRightOffsets[8] = {1, 1, 1, 0, 1, 1, 1, 0};
char *gSelectCupGridMBNclrName = "common/select_cup_m_b.nclr";
const u16 gSelectCupGridCourseLabelCells[4] = {0x12, 0x11, 0x10, 0xf};
const u32 gSelectCupGridRectCupIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gSelectCupGridMONclrName = "common/select_cup_m_o.nclr";
const u16 gSelectCupGridRecordCells[8] = {7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe};
char *gSelectCupGridMBnllName = "common/select_cup_m.bnll";
char *gSelectCupGridMNcgrName = "common/select_cup_m.nce.ncgr";
char *gSelectCupGridSONclrName = "common/select_cup_s_o.nclr";
char *gSelectCupGridSBnclName = "common/select_cup_s.bncl";
const u32 gSelectCupGridFirstCourseIds[8] = {0x14, 0x1b, 0x1e, 0x22, 0xa, 0x23, 0xf, 0x27};
char *gSelectCupGridMNscrName = "common/select_cup_m.nscr";
char *gSelectCupGridSNcerName = "common/select_cup_s.nce.ncer";
const u32 gSelectCupGridEngineSlots[3] = {0, 1, 2};
const u16 gSelectCupGridTrophyCells[4] = {3, 4, 5, 6};
const u32 gSelectCupGridIndicesByCup[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const s16 gSelectCupGridUpOffsets[8] = {0, 0, 0, 0, -4, -4, -4, -4};
const u32 gSelectCupGridCupIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gSelectCupGridMNcerName = "common/select_cup_m.nce.ncer";
char *gSelectCupGridMBNcgrName = "common/select_cup_m_b.ncgr";
const u16 gSelectCupGridCupCellIndices[8][6] = {
    {0xb, 0x14, 0x1c, 0xc, 0x2c, 0x25}, {4, 0x15, 0x1d, 0xd, 0x2d, 0x28},   {5, 0x16, 0x1e, 0xe, 0x2e, 0x2b},
    {6, 0x17, 0x1f, 0xf, 0x2f, 0x27},   {7, 0x18, 0x20, 0x10, 0x30, 0x2a},  {8, 0x19, 0x21, 0x11, 0x31, 0x29},
    {9, 0x1a, 0x22, 0x12, 0x32, 0x26},  {0xa, 0x1b, 0x23, 0x13, 0x33, 0x24}};
char *gSelectCupGridMBnclName = "common/select_cup_m.bncl";
const u32 gSelectCupGridRecordCellSlots[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const u32 gSelectCupGridCourseIds[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13},
                                           {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe},     {0x23, 0x10, 0xc, 9},
                                           {0xf, 0x24, 0x25, 0x26},  {0x27, 0x17, 0x28, 1}};
const u16 gSelectCupGridCupMessageIndices[8][4] = {
    {0x2d, 0x2e, 0x2f, 0x30}, {0x31, 0x32, 0x33, 0x34}, {0x35, 0x36, 0x37, 0x38}, {0x39, 0x3a, 0x3b, 0x3c},
    {0x3d, 0x3e, 0x3f, 0x40}, {0x41, 0x42, 0x43, 0x44}, {0x45, 0x46, 0x47, 0x48}, {0x49, 0x4a, 0x4b, 0x4c}};
const u16 gSelectCupGridCourseLabelHeights[4] = {0xd, 0xd, 0xd, 0xd};
const s16 gSelectCupGridDownOffsets[8] = {4, 4, 4, 4, 0, 0, 0, 0};
const s16 gSelectCupGridLeftOffsets[8] = {0, -1, -1, -1, 0, -1, -1, -1};
SelectCupGrid *gSelectCupGrid;

void RefreshSelectCupGridCupsEnabled(void) {
    int cupIndex;
    u32 enabled;
    cupIndex = 0;
    do {
        enabled = GetSelectCupGridCupEnabled(cupIndex);
        gSelectCupGrid->mCupsEnabled[cupIndex] = enabled;
        cupIndex = cupIndex + 1;
    } while (cupIndex < 8);
}

#pragma thumb off

#pragma thumb on
void InitSelectCupGridCells(void) {
    s32 cupCellIndex;
    s32 index;
    u16 mainCellCount;
    const u16 *cellIndices;
    SelectCupGrid *grid;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        for (index = 0; index < 4; index++) {
            gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mVisible = 0;
            gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mVisible = 1;
        }
        for (index = 0; index < 8; index++) {
            for (cupCellIndex = 0, cellIndices = gSelectCupGridCupCellIndices[index]; cupCellIndex < 6;
                 cupCellIndex++) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[cupCellIndex]].mVisible = 0;
            }
        }
        gSelectCupGrid->mSelectCupMTable[0x14].mVisible = 1;
        gSelectCupGrid->mSelectCupMTable[0x13].mVisible = 1;
        gSelectCupGrid->mSelectCupSTable[2].mVisible = 1;
        gSelectCupGrid->mSelectCupSTable[3].mVisible = 1;
        for (index = 0; index < 8; index++) {
            gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][0]].mVisible = 1;
        }
        for (index = 0; index < 8; index++) {
            grid = gSelectCupGrid;
            QueueCupMark(index, grid->mSelectCupSNcer, grid->mSelectCupSBncl, gSelectCupGridCupCellIndices[index][4],
                         GetCellPaletteIndex(gSelectCupGridCupCellIndices[index][4], grid->mSelectCupSNcer,
                                             grid->mSelectCupSBncl),
                         1);
        }
    }
}

void UpdateSelectCupGridCupCells(void) {
    s32 cupIndex;
    BOOL visible;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        visible = FALSE;
        for (cupIndex = 0; cupIndex < 8; cupIndex++) {
            const u16 *cellIndices = gSelectCupGridCupCellIndices[cupIndex];
            gSelectCupGrid->mSelectCupSTable[cellIndices[1]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[2]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[3]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[4]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = 0;
            if (gSelectCupGrid->mCupsEnabled[cupIndex] == 0) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[3]].mVisible = 1;
                gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = 1;
            } else {
                if (gSelectCupGrid->mIndex == cupIndex && gSelectCupGrid->mHighlightShown != FALSE) {
                    gSelectCupGrid->mSelectCupSTable[cellIndices[2]].mVisible = 1;
                } else {
                    gSelectCupGrid->mSelectCupSTable[cellIndices[1]].mVisible = 1;
                }
                gSelectCupGrid->mSelectCupSTable[cellIndices[4]].mVisible = 1;
            }
            if (gSelectCupGrid->mMode == SELECT_CUP_GRID_MODE_MULTI_SIMPLE) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = visible;
            }
        }
    }
}

void RequestSelectCupGridCupPicture(void) {
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        TrySetCupPictureIndexAndQueueLoads(
            gSelectCupGridCourseIds[gSelectCupGrid->mIndex][gSelectCupGrid->mShownCourseIndex]);
        gSelectCupGrid->mCupPicturePending = TRUE;
    }
}

void SetupSelectCupGridIndex(void) {
    u32 value;
    s32 recordSlot;
    s32 grade;
    s32 courseIndex;
    const u16 *cellIndexCursor;
    s32 cellIndex;
    SelectCupGrid *grid;
    u32 engineOrMirrorSlot;

    value = 0;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    QueueSelectCupNameM(gSelectCupGrid->mIndex, gSelectCupGrid->mSelectCupMNcer, gSelectCupGrid->mSelectCupMBncl, 0x13,
                        value);
    cellIndex = 0;
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        grid = gSelectCupGrid;
        PrintLabelLayoutTextNoFixedAdvance(
            cellIndex, gSelectCupGridCourseLabelIndices[courseIndex], gSelectCupGrid->mSelectCupMBnll,
            GetBmgEntry(grid->mCommonMessages, gSelectCupGridCupMessageIndices[grid->mIndex][courseIndex]),
            grid->mSelectCupMBncl, grid->mSelectCupMTable);
    }
    for (cellIndex = 0, cellIndexCursor = gSelectCupGridRecordCells; cellIndex < 8; cellIndexCursor++, cellIndex++) {
        gSelectCupGrid->mSelectCupMTable[*cellIndexCursor].mVisible = 0;
    }
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[courseIndex]].mVisible = 0;
    }
    if (gSelectCupGrid->mMode == SELECT_CUP_GRID_MODE_SHOW_RECORDS) {
        if (GetMirrorMode() != 0) {
            engineOrMirrorSlot = 3;
        } else {
            engineOrMirrorSlot = gSelectCupGridEngineSlots[GetEngineIndex()];
        }
        recordSlot = gSelectCupGridRecordEngineClasses[engineOrMirrorSlot];
        if (IsGrandPrixRecordFilled(gSelectCupGridCupIndices[gSelectCupGrid->mIndex], recordSlot) != 0) {
            grade = GetGrandPrixRecordGrade(gSelectCupGridCupIndices[gSelectCupGrid->mIndex], recordSlot);
            gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[gSelectCupGridRecordCellSlots[grade]]].mVisible =
                1;
            switch (grade) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    value = gSelectCupGridTrophyCells[0];
                    break;
                case 5:
                    value = gSelectCupGridTrophyCells[1];
                    break;
                case 6:
                    value = gSelectCupGridTrophyCells[2];
                    break;
                case 7:
                    value = gSelectCupGridTrophyCells[3];
                    break;
            }
            gSelectCupGrid->mSelectCupMTable[value].mVisible = 1;
            grade = GetGrandPrixRecordCupRank(gSelectCupGridCupIndices[gSelectCupGrid->mIndex], recordSlot);
            grid = gSelectCupGrid;
            QueueTrophyIcon(gSelectCupGridCupIndices[grid->mIndex], grade, grid->mSelectCupMNcer, grid->mSelectCupMBncl,
                            value, 4, 0);
        }
    }
    RequestSelectCupGridCupPicture();
}

// Stores the cup at mIndex and the first course of that cup in the race setup record.
void SetCupFromSelectCupGrid(void) {
    SetCupIndex(gSelectCupGridCupIndices[gSelectCupGrid->mIndex]);
    SetCourseId(gSelectCupGridFirstCourseIds[gSelectCupGrid->mIndex]);
}
#pragma thumb off

#pragma thumb on

u32 IsSelectCupGridIndexChangeRunning(void) {
    if (gSelectCupGrid->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridIndexChange(void) {
    u16 mainCellCount;
    s16 offsetY;
    int index;

    if (IsSelectCupGridIndexChangeRunning() != 0) {
        if (gSelectCupGrid->mIndexChangeTimer == 7) {
            gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
            SetupSelectCupGridIndex();
        } else if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
            offsetY = LookupIndexChangeOffset(7 - gSelectCupGrid->mIndexChangeTimer, 1);
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (index = 0; index < 8; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mOffsetY =
                    offsetY;
            }
        }
        gSelectCupGrid->mIndexChangeTimer = gSelectCupGrid->mIndexChangeTimer - 1;
    } else if (gSelectCupGrid->mIndex != gSelectCupGrid->mShownIndex) {
        gSelectCupGrid->mIndexChangeTimer = 7;
    }
}

void UpdateSelectCupGridCourseCells(void) {
    int courseIndex;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        for (courseIndex = 0; courseIndex < 4; courseIndex++) {
            if (gSelectCupGrid->mShownCourseIndex == courseIndex) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[courseIndex]].mVisible = 1;
                SetLabelPaletteIndex(gSelectCupGridCourseLabelIndices[courseIndex], 0xe,
                                     gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mSelectCupMTable,
                                     gSelectCupGrid->mSelectCupMBncl);
            } else {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[courseIndex]].mVisible = 0;
                SetLabelPaletteIndex(gSelectCupGridCourseLabelIndices[courseIndex], 0xf,
                                     gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mSelectCupMTable,
                                     gSelectCupGrid->mSelectCupMBncl);
            }
        }
    }
}

void AdvanceSelectCupGridShownCourse(void) {
    gSelectCupGrid->mShownCourseFrames = gSelectCupGrid->mShownCourseFrames + 1;
    if (gSelectCupGrid->mShownCourseFrames >= 0x4b) {
        gSelectCupGrid->mShownCourseIndex = gSelectCupGrid->mShownCourseIndex + 1;
        if (gSelectCupGrid->mShownCourseIndex >= 4) {
            gSelectCupGrid->mShownCourseIndex = 0;
        }
        gSelectCupGrid->mShownCourseFrames = 0;
        RequestSelectCupGridCupPicture();
    }
}

void ResetSelectCupGridShownCourse(void) {
    gSelectCupGrid->mShownCourseIndex = 0;
    gSelectCupGrid->mShownCourseFrames = 0;
}

void RequestSelectCupGridState0(void) {
    u16 mainCellCount;
    s32 offsetY;
    s32 offsetX;
    int index;
    int cellIndex;

    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_FADE;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        if (GetPreviousMenuScreenNumber() == 0x18 || GetPreviousMenuScreenNumber() == 0xc) {
            offsetY = 0;
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (index = 0; index < 8; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mOffsetY =
                    offsetY;
            }
        } else {
            offsetY = -192;
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (index = 0; index < 8; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mOffsetY =
                    offsetY;
            }
        }
        offsetY = -192;
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        offsetX = -224;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = 0xe0;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = 0xe0;
        for (index = 0; index < 4; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = offsetX;
            }
        }
        for (index = 4; index < 8; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = 0xe0;
            }
        }
    }
}

void RequestSelectCupGridState1(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_SLIDE_IN;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState2(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_RETURN;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectReturnState1();
}

void RequestSelectCupGridState3(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_CHOOSE;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState4(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_CHOSEN;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
    }
}

void RequestSelectCupGridState5(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_CONFIRM_OPEN;
    gSelectCupGrid->mStateFrames = 0;
    firstChoiceText = GetBmgEntry(gSelectCupGrid->mCommonMessages, 4);
    StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState6(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_CONFIRM_CHOICES;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState7(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_CONFIRM_ANSWER;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState8(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_EXIT_OPEN;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        firstChoiceText = GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5d);
        StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5f), 0);
    } else {
        firstChoiceText = GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x14);
        StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x15), 0);
    }
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState9(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_EXIT_CHOICES;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 5);
    SetSelectChoisesSoundId(1, 0xf);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState10(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_WAIT_EXIT_ANSWER;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState11(void) {
    gSelectCupGrid->mNextState = SELECT_CUP_GRID_STATE_SLIDE_OUT;
    gSelectCupGrid->mStateFrames = 0;
}

void InitSelectCupGrid(void *heap, void *mainOam, void *subOam, s32 mode) {
    s32 remainingSize;
    int index;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    heap = CreateFrmHeapFromMaxFree(heap);
    gSelectCupGrid = HeapAlloc(heap, 0x8c);
    gSelectCupGrid->mHeap = heap;
    gSelectCupGrid->mState = SELECT_CUP_GRID_STATE_WAIT_FADE;
    gSelectCupGrid->mIndex = gSelectCupGridIndicesByCup[GetCupIndex()];
    gSelectCupGrid->mHighlightShown = TRUE;
    gSelectCupGrid->mIndexChangeTimer = 0;
    gSelectCupGrid->mMode = mode;
    gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
    gSelectCupGrid->mCupPicturePending = FALSE;
    gSelectCupGrid->mMainOam = mainOam;
    gSelectCupGrid->mSubOam = subOam;
    gSelectCupGrid->mResult = 0;
    ResetSelectCupGridShownCourse();
    RefreshSelectCupGridCupsEnabled();
    LocateAndQueueSelectCupGrid();
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        ResetOamLists(gSelectCupGrid->mMainOam, gSelectCupGrid->mSubOam);
    }
    gSelectCupGrid->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gSelectCupGrid->mMenuMessages = FindSceneFile("menu.bmg");
        InitLayoutTable(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMBnll,
                        &gSelectCupGrid->mSelectCupMTable);
        InitLayoutTable(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupSBncl, NULL,
                        &gSelectCupGrid->mSelectCupSTable);
        remainingSize = 0x8000;
        for (index = 0; index < 4; index++) {
            remainingSize -= InitLabelCanvas(
                gSelectCupGrid->mHeap, gSelectCupGridCourseLabelIndices[index], gSelectCupGrid->mSelectCupMBnll,
                gSelectCupGridCourseLabelWidths[index], gSelectCupGridCourseLabelHeights[index],
                gSelectCupGridCourseLabelCells[index], gSelectCupGrid->mSelectCupMNcer, gSelectCupGrid->mSelectCupMBncl,
                gSelectCupGrid->mSelectCupMTable, remainingSize);
        }
        CreateSelectCupNameM(gSelectCupGrid->mHeap);
        CreateCommonCupMark(gSelectCupGrid->mHeap);
        CreateTrophyIcon(gSelectCupGrid->mHeap);
    } else {
        InitSelectRaceRuleWait(gSelectCupGrid->mHeap, gSelectCupGrid->mSubOam);
        if (GetPreviousMenuScreenNumber() != 0xc) {
            SlideInSelectRaceRuleWait();
        } else {
            PlaceSelectRaceRuleWait();
        }
    }
    InitSelectCupGridCells();
    SetupSelectCupGridIndex();
    RequestSelectCupGridState0();
    FrmHeapShrinkInParent(gSelectCupGrid->mHeap);
    if (gStartupWork->mConnectionKind == 2) {
        ClearSelectReturnDisplayBitOn();
    }
}

void ReleaseSelectCupGrid(void) {
    if ((gSelectCupGrid->mMode == SELECT_CUP_GRID_MODE_SHOW_RECORDS && gSelectCupGrid->mResult == 1) ||
        gSelectCupGrid->mResult == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        ClearSelectCupNameMPointer();
        ClearCupMarkPointer();
        ClearTrophyIconPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectCupGrid->mHeap);
    gSelectCupGrid = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectCupGridState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState1(void) {
    u16 mainCellCount;
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    int index;
    int cellIndex;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        offsetX = InterpolateS16(1, 0xe0, 0, gSelectCupGrid->mStateFrames, SELECT_CUP_GRID_SLIDE_STEPS);
        offsetY = InterpolateS16(1, -192, 0, gSelectCupGrid->mStateFrames, SELECT_CUP_GRID_SLIDE_STEPS);
        if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (index = 0; index < 8; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mOffsetY =
                    offsetY;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = offsetX;
        for (index = 0; index < 4; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = -offsetX;
            }
        }
        for (index = 4; index < 8; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = offsetX;
            }
        }
    }
    if (gSelectCupGrid->mStateFrames >= SELECT_CUP_GRID_SLIDE_STEPS) {
        RequestSelectCupGridState2();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState2(void) {
    int isReturnState2NoState3Or4Request;
    isReturnState2NoState3Or4Request = IsSelectReturnState2NoState3Or4Request();
    if (isReturnState2NoState3Or4Request != 0) {
        RequestSelectCupGridState3();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState3(void) {
    InputSlotIndex inputIndex;
    s32 touchedRectIndex;
    s32 neighborIndex;
    s32 touchedCupIndex;
    int pressedFlag;
    int releasedFlag;
    u16 pressedBits;
    InputSlotAtHasPair *hasPairSlot;
    InputSlot *inputSlot;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    pressedFlag = 0;
    releasedFlag = 0;
    hasPairSlot = &gInputHasPairs[inputIndex];
    pressedBits = gInputHasPairs[inputIndex].mHasPair;
    if (pressedBits == 0 && gInputNoPairCounts[inputIndex].mNoPairCount < 5) {
        releasedFlag = 1;
    }
    if (releasedFlag == 0 && gInputPrevHasPairs[inputIndex].mPrevHasPair == 0 && pressedBits != 0) {
        pressedFlag = 1;
    }
    if (pressedFlag != 0) {
        touchedRectIndex = RectTableFindContaining(gSelectCupGrid->mSelectCupSBnbl, gInputPairXs[inputIndex].mPairX,
                                                   gInputPairYs[inputIndex].mPairY);
    }
    inputSlot = &gInputSlots[inputIndex];
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    }
    pressedFlag = 0;
    releasedFlag = 0;
    pressedBits = hasPairSlot->mHasPair;
    if (pressedBits == 0 && gInputNoPairCounts[inputIndex].mNoPairCount < 5) {
        releasedFlag = 1;
    }
    if (releasedFlag == 0 && gInputPrevHasPairs[inputIndex].mPrevHasPair == 0 && pressedBits != 0) {
        pressedFlag = 1;
    }
    if (pressedFlag == 0) {
        goto L2;
    }
    if (IsSelectReturnState2NoState3Or4RequestAndInRect(gInputPairXs[inputIndex].mPairX,
                                                        gInputPairYs[inputIndex].mPairY) == FALSE) {
        goto L2;
    }
L1:
    if (IsSelectCupGridIndexChangeRunning() != 0) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    switch (gSelectCupGrid->mMode) {
        case SELECT_CUP_GRID_MODE_SHOW_RECORDS:
        case SELECT_CUP_GRID_MODE_NO_RECORDS:
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            return;
        case SELECT_CUP_GRID_MODE_NO_CONNECTION:
        case SELECT_CUP_GRID_MODE_MULTI_SIMPLE:
        case SELECT_CUP_GRID_MODE_MULTI_OTHER:
            if (gMenuShared->mMenuEntryKind == 2 || gMenuShared->mMenuEntryKind == 3) {
                RequestSelectCupGridState8();
                if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                    SetSelectReturnSoundId(-1);
                }
                RequestSelectReturnState3WithSound(0);
                return;
            }
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            if (gSelectCupGrid->mMode != SELECT_CUP_GRID_MODE_NO_CONNECTION) {
                RequestSelectReturnState3WithSound(1);
                if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                    SlideOutSelectRaceRuleWait();
                }
            } else {
                RequestSelectReturnState3WithSound(0);
            }
            return;
    }
    return;
L2:
    if ((u32) touchedRectIndex <= 7) {
        touchedCupIndex = gSelectCupGridRectCupIndices[touchedRectIndex];
        if (gSelectCupGrid->mCupsEnabled[touchedCupIndex] == 0) {
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
            }
            return;
        }
        if (gSelectCupGrid->mIndex == touchedCupIndex) {
            gSelectCupGrid->mHighlightShown = FALSE;
        }
        gSelectCupGrid->mIndex = touchedCupIndex;
        RequestSelectCupGridState4();
        return;
    }
    if ((u16) (inputSlot->mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectCupGridState4();
        gSelectCupGrid->mHighlightShown = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        releasedFlag = gSelectCupGrid->mIndex;
        pressedFlag = gSelectCupGridUpOffsets[releasedFlag];
        if (pressedFlag != 0) {
            neighborIndex = releasedFlag + pressedFlag;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        releasedFlag = gSelectCupGrid->mIndex;
        pressedFlag = gSelectCupGridDownOffsets[releasedFlag];
        if (pressedFlag != 0) {
            neighborIndex = releasedFlag + pressedFlag;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        releasedFlag = gSelectCupGrid->mIndex;
        pressedFlag = gSelectCupGridLeftOffsets[releasedFlag];
        if (pressedFlag != 0) {
            neighborIndex = releasedFlag + pressedFlag;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        releasedFlag = gSelectCupGrid->mIndex;
        pressedFlag = gSelectCupGridRightOffsets[releasedFlag];
        if (pressedFlag != 0) {
            neighborIndex = releasedFlag + pressedFlag;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
                }
            }
        }
    }
}

void AdvanceSelectCupGridState4(void) {
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    if (gSelectCupGrid->mStateFrames == SELECT_CUP_GRID_HIGHLIGHT_STEP) {
        gSelectCupGrid->mHighlightShown = TRUE;
    }
    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (gSelectCupGrid->mStateFrames >= SELECT_CUP_GRID_SLIDE_STEPS && IsSelectCupGridIndexChangeRunning() == 0) {
        if (gSelectCupGrid->mMode == SELECT_CUP_GRID_MODE_SHOW_RECORDS) {
            RequestSelectCupGridState5();
            return;
        }
        SetCupFromSelectCupGrid();
        gSelectCupGrid->mResult = 1;
        RequestSelectCupGridState11();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState5(void) {
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState6();
    }
}

void AdvanceSelectCupGridState6(void) {
    int isDone;
    AdvanceSelectCupGridShownCourse();
    isDone = GetSelectChoisesDone();
    if (isDone != 0) {
        RequestSelectCupGridState7();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState7(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
            case 0:
                SetCupFromSelectCupGrid();
                gSelectCupGrid->mResult = 1;
                RequestSelectCupGridState11();
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectCupGridState3();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState8(void) {
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState9();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState9(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupGridState10();
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            choiceIndex = GetSelectChoisesIndex();
            switch (choiceIndex) {
                case -1:
                case 0:
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xf);
                    break;
            }
        }
    }
}

void AdvanceSelectCupGridState10(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
            case -1:
            case 0:
                RequestSelectCupGridState3();
                break;
            case 1:
                gSelectCupGrid->mResult = 3;
                RequestSelectCupGridState11();
                if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                    SlideOutSelectRaceRuleWait();
                }
                break;
        }
    }
}

void AdvanceSelectCupGridState11(void) {
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    u16 mainCellCount;
    int index;
    int cellIndex;
    int labelIndex;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        offsetX = InterpolateS16(1, 0, 0xe0, gSelectCupGrid->mStateFrames, SELECT_CUP_GRID_SLIDE_STEPS);
        offsetY = InterpolateS16(1, 0, -192, gSelectCupGrid->mStateFrames, SELECT_CUP_GRID_SLIDE_STEPS);
        if (gSelectCupGrid->mResult == 2 || gSelectCupGrid->mResult == 3 ||
            gSelectCupGrid->mMode == SELECT_CUP_GRID_MODE_SHOW_RECORDS) {
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (index = 0; index < 8; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridRecordCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridTrophyCells[index]].mOffsetY = offsetY;
            }
            for (index = 0; index < 4; index++) {
                gSelectCupGrid->mSelectCupMTable[gSelectCupGridCourseLabelCells[index]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + gSelectCupGridCourseLabelIndices[index]].mOffsetY =
                    offsetY;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = offsetX;
        for (index = 0; index < 4; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = -offsetX;
            }
        }
        for (index = 4; index < 8; index++) {
            for (cellIndex = 0; cellIndex < 6; cellIndex++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[index][cellIndex]].mOffsetX = offsetX;
            }
        }
    }
}

s32 AdvanceSelectCupGrid(void) {
    int rowIndex;
    int screenMapIndex;
    u16 *screenMap;

    gSelectCupGrid->mState = gSelectCupGrid->mNextState;
    switch (gSelectCupGrid->mState) {
        case SELECT_CUP_GRID_STATE_WAIT_FADE:
            AdvanceSelectCupGridState0();
            break;
        case SELECT_CUP_GRID_STATE_SLIDE_IN:
            AdvanceSelectCupGridState1();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_RETURN:
            AdvanceSelectCupGridState2();
            break;
        case SELECT_CUP_GRID_STATE_CHOOSE:
            AdvanceSelectCupGridState3();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_CHOSEN:
            AdvanceSelectCupGridState4();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_CONFIRM_OPEN:
            AdvanceSelectCupGridState5();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_CONFIRM_CHOICES:
            AdvanceSelectCupGridState6();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_CONFIRM_ANSWER:
            AdvanceSelectCupGridState7();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_EXIT_OPEN:
            AdvanceSelectCupGridState8();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_EXIT_CHOICES:
            AdvanceSelectCupGridState9();
            break;
        case SELECT_CUP_GRID_STATE_WAIT_EXIT_ANSWER:
            AdvanceSelectCupGridState10();
            break;
        case SELECT_CUP_GRID_STATE_SLIDE_OUT:
            AdvanceSelectCupGridState11();
            break;
    }
    UpdateSelectCupGridCupCells();
    UpdateSelectCupGridCourseCells();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (gSelectCupGrid->mCupPicturePending != FALSE && IsCupPictureReady() != FALSE) {
            screenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(0xf, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (rowIndex = 0; rowIndex < 11; rowIndex++) {
                screenMapIndex = (rowIndex + 8) * 0x20 + 0x16;
                NNS_GfdRegisterNewVramTransferTask(8, screenMapIndex * 2, screenMap + screenMapIndex, 0x14);
            }
            gSelectCupGrid->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMNcer,
                        gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mMainOam, gSelectCupGrid->mSelectCupMTable);
        DrawLayoutTable(gSelectCupGrid->mSelectCupSBncl, gSelectCupGrid->mSelectCupSNcer, NULL, gSelectCupGrid->mSubOam,
                        gSelectCupGrid->mSelectCupSTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupGrid->mState == SELECT_CUP_GRID_STATE_SLIDE_OUT &&
        gSelectCupGrid->mStateFrames >= SELECT_CUP_GRID_SLIDE_STEPS) {
        return gSelectCupGrid->mResult;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void WriteSelectCupGridRegisters(void) {
    u32 scratchValue;
    u32 registerValue;
    u32 controlValue;
    scratchValue = gSelectCupGrid->mBg0Offset;
    scratchValue = 0u - (scratchValue);
    registerValue = (scratchValue << 16);
    scratchValue = 0x1ff0000u;
    registerValue = (registerValue) & (scratchValue);
    scratchValue = 0x4000010u;
    *(u32 *) ((scratchValue) + 0u) = registerValue;
    registerValue = 0x4000000u;
    controlValue = *(const u32 *) ((registerValue) + 0u);
    scratchValue = 0xffff1fffu;
    controlValue = (controlValue) & (scratchValue);
    *(u32 *) ((registerValue) + 0u) = controlValue;
}
#pragma thumb off
