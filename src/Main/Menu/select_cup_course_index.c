#include "Main/Menu/select_cup_course_index.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/oam.h"

#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_0215c000.h"
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
#include "Main/Menu/select_race_rule.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Race/ghost_record_set.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Graphics/time_format.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "code_0212df7c.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/select_cup_course.h"

char *gSelectCupMNcgrName = "common/select_cup_m.nce.ncgr";
char *gSelectCupCourseMONclrName = "common/select_cup_course_m_o.nclr";
char *gSelectCupMBnllName = "common/select_cup_m.bnll";
char *gSelectCupCourseTaMBNcgrName = "common/select_cup_course_ta_m_b.ncgr";
const u16 gSelectCupCourseLabelCells[4] = {0x12, 0x11, 0x10, 0xf};
const s16 gCupCourseIndicesByCourse[56] = {-1, 3, -1, -1, -1, -1, -1, -1, -1, 3, 0, 1, 2, 2, 3, 0, 1, 1, 3, 3, 0, -1, 1, 1, 0, 2, 1, 0, 1, 3, 0, 2, 2, 2, 0, 0, 1, 2, 3, 0, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0};
char *gSelectCupMNcerName = "common/select_cup_m.nce.ncer";
const s16 gSelectCupCourseRectCourseIndices[4] = {3, 2, 1, 0};
char *gSelectCupCourseTaMBnllName2 = "common/select_cup_course_ta_m.bnll";
char *gSelectCupCourseVsMNscrName = "common/select_cup_course_vs_m.nscr";
char *gSelectCupCourseVsMBnclName = "common/select_cup_course_vs_m.bncl";
char *gSelectCupMBnclName = "common/select_cup_m.bncl";
char *gSelectCupCourseVsMBNclrName = "common/select_cup_course_vs_m_b.nclr";
char *gSelectCupCourseCupMBnblName = "common/select_cup_m.bnbl";
const u16 gSelectCupCourseRecordCells[8] = {7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe};
char *gSelectCupMBNcgrName = "common/select_cup_m_b.ncgr";
const u16 gCupCourseNameMessageIndices[8][4] = {{0x2d, 0x2e, 0x2f, 0x30}, {0x31, 0x32, 0x33, 0x34}, {0x35, 0x36, 0x37, 0x38}, {0x39, 0x3a, 0x3b, 0x3c}, {0x3d, 0x3e, 0x3f, 0x40}, {0x41, 0x42, 0x43, 0x44}, {0x45, 0x46, 0x47, 0x48}, {0x49, 0x4a, 0x4b, 0x4c}};
char *gSelectCupCourseMNcgrName = "common/select_cup_course_m.nce.ncgr";
const u16 gSelectCupCourseTrophyCells[4] = {3, 4, 5, 6};
char *gSelectCupCourseTaMBNclrName = "common/select_cup_course_ta_m_b.nclr";
char *gSelectCupCourseTaMNscrName = "common/select_cup_course_ta_m.nscr";
const u16 gSelectCupCourseLabelIndices[4] = {3, 2, 1, 0};
char *gSelectCupCourseVsMBnllName = "common/select_cup_course_vs_m.bnll";
char *gSelectCupMONclrName = "common/select_cup_m_o.nclr";
const u32 gCupRowsByCupIndex[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const u16 gSelectCupCourseLabelHeights[4] = {0xd, 0xd, 0xd, 0xd};
char *gSelectCupMNscrName = "common/select_cup_m.nscr";
const u16 gSelectCupCourseLabelWidths[4] = {0xa3, 0xa3, 0xa3, 0xa3};
char *gSelectCupCourseMNcerName2 = "common/select_cup_course_m.nce.ncer";
const u16 gCupCourseGhostMessageIndices[8][4] = {{0x33, 0x34, 0x35, 0x36}, {0x37, 0x38, 0x39, 0x3a}, {0x3b, 0x3c, 0x3d, 0x3e}, {0x3f, 0x40, 0x41, 0x42}, {0x43, 0x44, 0x45, 0x46}, {0x47, 0x48, 0x49, 0x4a}, {0x4b, 0x4c, 0x4d, 0x4e}, {0x4f, 0x50, 0x51, 0x52}};
char *gSelectCupMBNclrName = "common/select_cup_m_b.nclr";
char *gSelectCupCourseTaMBnclName2 = "common/select_cup_course_ta_m.bncl";
const u32 gCupRowCourseIds[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13}, {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe}, {0x23, 0x10, 0xc, 9}, {0xf, 0x24, 0x25, 0x26}, {0x27, 0x17, 0x28, 1}};
char *gSelectCupCourseVsMBNcgrName = "common/select_cup_course_vs_m_b.ncgr";

#pragma thumb on

u32 IsSelectCupCourseIndexChangeRunning(void) {
    if (gSelectCupCourse->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectCupCourseIndexChange(void) {
    s32 taOrVsCellCount;
    s16 offsetY;

    if (IsSelectCupCourseIndexChangeRunning() != 0) {
        if (gSelectCupCourse->mIndexChangeTimer == 7) {
            gSelectCupCourse->mShownIndex = gSelectCupCourse->mIndex;
            RefreshSelectCupCourseForIndex();
        } else if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            taOrVsCellCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mCount;
            offsetY = LookupIndexChangeOffset(7 - gSelectCupCourse->mIndexChangeTimer, 1);
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 1].mOffsetY = offsetY;
        }
        gSelectCupCourse->mIndexChangeTimer--;
    } else if (gSelectCupCourse->mIndex != gSelectCupCourse->mShownIndex) {
        gSelectCupCourse->mIndexChangeTimer = 7;
    }
}

void RequestSelectCupCourseState0(void) {
    s16 subOffsetY;
    s32 taOrVsCellCount;
    s32 cellIndex;
    s32 selectCupMCellCount;

    gSelectCupCourse->mNextState = 0;
    gSelectCupCourse->mStateFrames = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (GetPreviousMenuScreenNumber() != SCREEN_SELECT_GHOST) {
            taOrVsCellCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mCount;
            gSelectCupCourse->mBg0Offset = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 1].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 2].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 3].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 4].mOffsetY = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 5].mOffsetY = -0xc0;
        }
        if (GetPreviousMenuScreenNumber() != SCREEN_SELECT_GHOST) {
            subOffsetY = -0x20;
        } else {
            subOffsetY = -0xe0;
        }
        selectCupMCellCount = gSelectCupCourse->mSelectCupMBncl->mCount;
        gSelectCupCourse->mBg3Offset = subOffsetY;
        gSelectCupCourse->mSelectCupMTable[0x14].mOffsetY = subOffsetY;
        gSelectCupCourse->mSelectCupMTable[0x13].mOffsetY = subOffsetY;
        gSelectCupCourse->mSelectCupMTable[2].mOffsetY = subOffsetY;
        gSelectCupCourse->mSelectCupMTable[1].mOffsetY = subOffsetY;
        gSelectCupCourse->mSelectCupMTable[0].mOffsetY = subOffsetY;
        for (cellIndex = 0; cellIndex < 8; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseRecordCells[cellIndex]].mOffsetY = subOffsetY;
        }
        for (cellIndex = 0; cellIndex < 4; cellIndex++) {
            gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[cellIndex]].mOffsetY = subOffsetY;
            gSelectCupCourse->mSelectCupMTable[selectCupMCellCount + gSelectCupCourseLabelIndices[cellIndex]].mOffsetY =
                subOffsetY;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectCupCourse call copies it to
// mState and runs AdvanceSelectCupCourseState1.
void RequestSelectCupCourseState1(void) {
    gSelectCupCourse->mNextState = 1;
    gSelectCupCourse->mStateFrames = 0;
}

void RequestSelectCupCourseState2(void) {
    gSelectCupCourse->mNextState = 2;
    gSelectCupCourse->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectCupCourse call copies it to
// mState and runs AdvanceSelectCupCourseState3.
void RequestSelectCupCourseState3(void) {
    gSelectCupCourse->mNextState = 3;
    gSelectCupCourse->mStateFrames = 0;
}

void RequestSelectCupCourseState4(void) {
    gSelectCupCourse->mNextState = 4;
    gSelectCupCourse->mStateFrames = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
    }
}

void RequestSelectCupCourseState5(void) {
    u16 messageText[0x100];
    SelectCupCourse *selectCupCourse;

    gSelectCupCourse->mNextState = 5;
    gSelectCupCourse->mStateFrames = 0;
    selectCupCourse = gSelectCupCourse;
    switch (selectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            StartSelectChoises(GetBmgEntry(selectCupCourse->mCommonMessages, 4),
                               GetBmgEntry(selectCupCourse->mCommonMessages, 2), 0);
            break;
        case 2:
            StartSelectChoises(GetBmgEntry(selectCupCourse->mCommonMessages, 4),
                               GetBmgEntry(selectCupCourse->mCommonMessages, 2), 0);
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                FormatMessageWithText(
                    GetBmgEntry(gSelectCupCourse->mGhostMessages,
                                gCupCourseGhostMessageIndices[gCupRowsByCupIndex[GetCupIndex()]][gSelectCupCourse->mIndex]),
                    GetBmgEntry(gSelectCupCourse->mCommonMessages, 0x8b), messageText, 0x200);
                SetTxtSystemOpenSoundId(0x23);
                SetupTxtSystemMainText(messageText);
            }
            break;
    }
}
#pragma thumb off

#pragma thumb on

void RequestSelectCupCourseState6(void) {
    gSelectCupCourse->mNextState = 6;
    gSelectCupCourse->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on
void RequestSelectCupCourseState7(void) {
    gSelectCupCourse->mNextState = 7;
    gSelectCupCourse->mStateFrames = 0;
    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            RequestSelectChoisesState0();
            break;
        case 2:
            RequestSelectChoisesState0();
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                RequestTxtSystemClose();
            }
            break;
    }
}

void RequestSelectCupCourseState8(void) {
    gSelectCupCourse->mNextState = 8;
    gSelectCupCourse->mStateFrames = 0;
    if (gSelectCupCourse->mMode == 0) {
        if (gSelectCupCourse->mResult == 1) {
            if (HasNoSelectableGhost() != FALSE) {
                RequestSelectReturnState4();
            }
        }
    } else {
        RequestSelectReturnState4();
    }
}

void InitSelectCupCourse(void *parentHeap, void *mainOam, void *subOam, s32 mode) {
    void *heap;
    s32 remainingSize;
    s32 labelIndex;
    u32 remainingSubSize;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x9004;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectCupCourse = HeapAlloc(heap, 0x70);
    gSelectCupCourse->mHeap = heap;
    gSelectCupCourse->mState = 0;
    gSelectCupCourse->mIndex = gCupCourseIndicesByCourse[GetCourseId()];
    gSelectCupCourse->mHighlightShown = TRUE;
    gSelectCupCourse->mIndexChangeTimer = 0;
    gSelectCupCourse->mMode = mode;
    gSelectCupCourse->mShownIndex = gSelectCupCourse->mIndex;
    gSelectCupCourse->mCupPicturePending = FALSE;
    gSelectCupCourse->mMainOam = mainOam;
    gSelectCupCourse->mSubOam = subOam;
    gSelectCupCourse->mResult = 0;
    LocateAndQueueSelectCupCourse();
    gSelectCupCourse->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitLayoutTable(gSelectCupCourse->mHeap, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, &gSelectCupCourse->mSelectCupCourseTaOrVsMTable);
        InitLayoutTable(gSelectCupCourse->mHeap, gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMBnll,
                        &gSelectCupCourse->mSelectCupMTable);
        remainingSize = 0x8000;
        remainingSize -=
            InitLabelCanvas(gSelectCupCourse->mHeap, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 0,
                            gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                            gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        remainingSize -=
            InitLabelCanvas(gSelectCupCourse->mHeap, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 1,
                            gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                            gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        remainingSize -=
            InitLabelCanvas(gSelectCupCourse->mHeap, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 2,
                            gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                            gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        remainingSize -=
            InitLabelCanvas(gSelectCupCourse->mHeap, 3, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 3,
                            gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                            gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        remainingSize -=
            InitLabelCanvas(gSelectCupCourse->mHeap, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 4,
                            gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                            gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        InitLabelCanvas(gSelectCupCourse->mHeap, 5, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 5,
                        gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMTable, remainingSize);
        remainingSubSize = GX_GetSizeOfSubOBJ();
        for (labelIndex = 0; labelIndex < 4; labelIndex++) {
            remainingSubSize -= InitLabelCanvas(
                gSelectCupCourse->mHeap, gSelectCupCourseLabelIndices[labelIndex], gSelectCupCourse->mSelectCupMBnll,
                gSelectCupCourseLabelWidths[labelIndex], gSelectCupCourseLabelHeights[labelIndex],
                gSelectCupCourseLabelCells[labelIndex], gSelectCupCourse->mSelectCupMNcer,
                gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMTable, remainingSubSize);
        }
        CreateSelectCupNameM(gSelectCupCourse->mHeap);
        CreateCommonCupMark(gSelectCupCourse->mHeap);
    } else {
        gSelectCupCourse->mGhostMessages = FindSceneFile("ghost.bmg");
        InitSelectRaceRuleWait(gSelectCupCourse->mHeap, gSelectCupCourse->mSubOam);
        PlaceSelectRaceRuleWait();
    }
    SetupSelectCupCourseObjects();
    RefreshSelectCupCourseForIndex();
    RequestSelectCupCourseState0();
    FrmHeapShrinkInParent(gSelectCupCourse->mHeap);
}

void ReleaseSelectCupCourse(void) {
    if (gSelectCupCourse->mResult == 1) {
        if (gSelectCupCourse->mMode == 0) {
            if (HasNoSelectableGhost() != FALSE) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
            }
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
        }
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        ClearSelectCupNameMPointer();
        ClearCupMarkPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectCupCourse->mHeap);
    gSelectCupCourse = NULL;
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupCourseState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectCupCourseState1();
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectCupCourseState1(void) {
    s16 offsetY;
    s32 taOrVsCellCount;
    s32 cellIndex;

    gSelectCupCourse->mStateFrames++;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InterpolateS16(1, 0x100, 0, gSelectCupCourse->mStateFrames, 10);
        offsetY = InterpolateS16(1, -0xc0, 0, gSelectCupCourse->mStateFrames, 10);
        if (GetPreviousMenuScreenNumber() != SCREEN_SELECT_GHOST) {
            taOrVsCellCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mCount;
            gSelectCupCourse->mBg0Offset = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 1].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 2].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 3].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 4].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[taOrVsCellCount + 5].mOffsetY = offsetY;
        }
        if (GetPreviousMenuScreenNumber() == SCREEN_SELECT_GHOST) {
            taOrVsCellCount = gSelectCupCourse->mSelectCupMBncl->mCount;
            gSelectCupCourse->mBg3Offset = offsetY - 0x20;
            gSelectCupCourse->mSelectCupMTable[0x14].mOffsetY = offsetY - 0x20;
            gSelectCupCourse->mSelectCupMTable[0x13].mOffsetY = offsetY - 0x20;
            gSelectCupCourse->mSelectCupMTable[2].mOffsetY = offsetY - 0x20;
            gSelectCupCourse->mSelectCupMTable[1].mOffsetY = offsetY - 0x20;
            gSelectCupCourse->mSelectCupMTable[0].mOffsetY = offsetY - 0x20;
            for (cellIndex = 0; cellIndex < 8; cellIndex++) {
                gSelectCupCourse->mSelectCupMTable[gSelectCupCourseRecordCells[cellIndex]].mOffsetY = offsetY - 0x20;
            }
            offsetY -= 0x20;
            for (cellIndex = 0; cellIndex < 4; cellIndex++) {
                gSelectCupCourse->mSelectCupMTable[gSelectCupCourseLabelCells[cellIndex]].mOffsetY = offsetY;
                gSelectCupCourse->mSelectCupMTable[taOrVsCellCount + gSelectCupCourseLabelIndices[cellIndex]].mOffsetY =
                    offsetY;
            }
        }
    }
    if (gSelectCupCourse->mStateFrames >= 10) {
        RequestSelectCupCourseState2();
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupCourseState2(void) {
    int returnRequested;
    returnRequested = IsSelectReturnState2NoState3Or4Request();
    if (returnRequested != 0) {
        RequestSelectCupCourseState3();
    }
}

#pragma thumb off
