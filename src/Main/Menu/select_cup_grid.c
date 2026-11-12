#include "Main/Menu/select_cup_grid.h"

#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02117814.h"
#include "Main/Unknown/code_021177a4.h"
#include "Main/Unknown/code_02117be0.h"
#include "Main/Unknown/code_02117d98.h"
#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0215c000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "gfd_VramTransferManager.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/unk_02175000.h"
#include "registers.h"
#include "Main/Unknown/code_02118054.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Unknown/code_02118114.h"
#include "Main/Graphics/time_format.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Save/buddy_record.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Menu/trophy_icon.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on

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
    u16 *cellIndices;
    SelectCupGrid *grid;

    if (gBootInfo->mBootType != 2) {
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

    if (gBootInfo->mBootType != 2) {
        visible = FALSE;
        for (cupIndex = 0; cupIndex < 8; cupIndex++) {
            u16 *cellIndices = gSelectCupGridCupCellIndices[cupIndex];
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
            if (gSelectCupGrid->mMode == 3) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = visible;
            }
        }
    }
}

void RequestSelectCupGridCupPicture(void) {
    if (gBootInfo->mBootType != 2) {
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
    u16 *cellIndexCursor;
    s32 cellIndex;
    SelectCupGrid *grid;
    u32 engineOrMirrorSlot;

    value = 0;
    if (gBootInfo->mBootType == 2) {
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
    if (gSelectCupGrid->mMode == 0) {
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
        } else if (gBootInfo->mBootType != 2) {
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

    if (gBootInfo->mBootType != 2) {
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

    gSelectCupGrid->mNextState = 0;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType != 2) {
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
    gSelectCupGrid->mNextState = 1;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState2(void) {
    gSelectCupGrid->mNextState = 2;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectReturnState1();
}

void RequestSelectCupGridState3(void) {
    gSelectCupGrid->mNextState = 3;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState4(void) {
    gSelectCupGrid->mNextState = 4;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType != 2) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
    }
}

void RequestSelectCupGridState5(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = 5;
    gSelectCupGrid->mStateFrames = 0;
    firstChoiceText = GetBmgEntry(gSelectCupGrid->mCommonMessages, 4);
    StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState6(void) {
    gSelectCupGrid->mNextState = 6;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState7(void) {
    gSelectCupGrid->mNextState = 7;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState8(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = 8;
    gSelectCupGrid->mStateFrames = 0;
    if (gBootInfo->mBootType == 2) {
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
    gSelectCupGrid->mNextState = 9;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 5);
    SetSelectChoisesSoundId(1, 0xf);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState10(void) {
    gSelectCupGrid->mNextState = 0xa;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState11(void) {
    gSelectCupGrid->mNextState = 0xb;
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
    gSelectCupGrid->mState = 0;
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
    if (gBootInfo->mBootType != 2) {
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
    if ((gSelectCupGrid->mMode == 0 && gSelectCupGrid->mResult == 1) || gSelectCupGrid->mResult == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (gBootInfo->mBootType != 2) {
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
    if (gBootInfo->mBootType != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        offsetX = InterpolateS16(1, 0xe0, 0, gSelectCupGrid->mStateFrames, 0xa);
        offsetY = InterpolateS16(1, -192, 0, gSelectCupGrid->mStateFrames, 0xa);
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
    if (gSelectCupGrid->mStateFrames >= 0xa) {
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
    InputSlot *hasPairSlot;
    InputSlot *inputSlot;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    pressedFlag = 0;
    releasedFlag = 0;
    hasPairSlot = &gInputHasPairs[inputIndex];
    pressedBits = gInputHasPairs[inputIndex].mPressedBits;
    if (pressedBits == 0 && gInputNoPairCounts[inputIndex].mPressedBits < 5) {
        releasedFlag = 1;
    }
    if (releasedFlag == 0 && gInputPrevHasPairs[inputIndex].mPressedBits == 0 && pressedBits != 0) {
        pressedFlag = 1;
    }
    if (pressedFlag != 0) {
        touchedRectIndex =
            RectTableFindContaining(gSelectCupGrid->mSelectCupSBnbl, gInputPairXs[inputIndex].mPressedBits,
                                    gInputPairYs[inputIndex].mPressedBits);
    }
    inputSlot = &gInputSlots[inputIndex];
    if ((u16) (gInputSlots[inputIndex].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    }
    pressedFlag = 0;
    releasedFlag = 0;
    pressedBits = hasPairSlot->mPressedBits;
    if (pressedBits == 0 && gInputNoPairCounts[inputIndex].mPressedBits < 5) {
        releasedFlag = 1;
    }
    if (releasedFlag == 0 && gInputPrevHasPairs[inputIndex].mPressedBits == 0 && pressedBits != 0) {
        pressedFlag = 1;
    }
    if (pressedFlag == 0) {
        goto L2;
    }
    if (IsSelectReturnState2NoState3Or4RequestAndInRect(gInputPairXs[inputIndex].mPressedBits,
                                                        gInputPairYs[inputIndex].mPressedBits) == FALSE) {
        goto L2;
    }
L1:
    if (IsSelectCupGridIndexChangeRunning() != 0) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    switch (gSelectCupGrid->mMode) {
        case 0:
        case 1:
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            return;
        case 2:
        case 3:
        case 4:
            if (gMenuShared->mMenuEntryKind == 2 || gMenuShared->mMenuEntryKind == 3) {
                RequestSelectCupGridState8();
                if (gBootInfo->mBootType == 2) {
                    SetSelectReturnSoundId(-1);
                }
                RequestSelectReturnState3WithSound(0);
                return;
            }
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            if (gSelectCupGrid->mMode != 2) {
                RequestSelectReturnState3WithSound(1);
                if (gBootInfo->mBootType == 2) {
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
            if (gBootInfo->mBootType != 2) {
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
                if (gBootInfo->mBootType != 2) {
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
                if (gBootInfo->mBootType != 2) {
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
                if (gBootInfo->mBootType != 2) {
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
                if (gBootInfo->mBootType != 2) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
                }
            }
        }
    }
}

void AdvanceSelectCupGridState4(void) {
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    if (gSelectCupGrid->mStateFrames == 5) {
        gSelectCupGrid->mHighlightShown = TRUE;
    }
    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (gSelectCupGrid->mStateFrames >= 10 && IsSelectCupGridIndexChangeRunning() == 0) {
        if (gSelectCupGrid->mMode == 0) {
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
        if (gBootInfo->mBootType == 2) {
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
                if (gBootInfo->mBootType == 2) {
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
    if (gBootInfo->mBootType != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mCount;
        offsetX = InterpolateS16(1, 0, 0xe0, gSelectCupGrid->mStateFrames, 0xa);
        offsetY = InterpolateS16(1, 0, -192, gSelectCupGrid->mStateFrames, 0xa);
        if (gSelectCupGrid->mResult == 2 || gSelectCupGrid->mResult == 3 || gSelectCupGrid->mMode == 0) {
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
        case 0:
            AdvanceSelectCupGridState0();
            break;
        case 1:
            AdvanceSelectCupGridState1();
            break;
        case 2:
            AdvanceSelectCupGridState2();
            break;
        case 3:
            AdvanceSelectCupGridState3();
            break;
        case 4:
            AdvanceSelectCupGridState4();
            break;
        case 5:
            AdvanceSelectCupGridState5();
            break;
        case 6:
            AdvanceSelectCupGridState6();
            break;
        case 7:
            AdvanceSelectCupGridState7();
            break;
        case 8:
            AdvanceSelectCupGridState8();
            break;
        case 9:
            AdvanceSelectCupGridState9();
            break;
        case 10:
            AdvanceSelectCupGridState10();
            break;
        case 11:
            AdvanceSelectCupGridState11();
            break;
    }
    UpdateSelectCupGridCupCells();
    UpdateSelectCupGridCourseCells();
    if (gBootInfo->mBootType != 2) {
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
    if (gSelectCupGrid->mState == 0xb && gSelectCupGrid->mStateFrames >= 0xa) {
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
