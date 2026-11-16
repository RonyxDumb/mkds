#include "Main/Menu/wifi_vs_course_select_files.h"
#include "Main/Menu/wifi_vs_course_select.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/System/heap.h"
#include "vram_bank_display_setup.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Graphics/message_index.h"
#include "Main/System/interpolation.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/scroll_list_state.h"
#include "Main/Menu/player_entry_layout_rows.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/oam.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/packed_index.h"
#include "Main/Graphics/layout_table_entry.h"
#include "sound_player_control.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "tick_counter.h"
#include "Main/Graphics/cell_layout.h"
#include "Main/Graphics/layout_rect_table.h"
#include "sound_archive_load_result.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_character.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"

const u16 gCourseRowCellIndices[4] = {0, 1, 2, 3};
const u16 gCourseTimerDigitCellIndices[10] = {5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe};
const LabelTextRow gWiFiVSCourseSelectMLabelTextRows[4] = {
    {0, 0xb0, 0x10, 0}, {1, 0xb0, 0x10, 1}, {2, 0xb0, 0x10, 2}, {3, 0xb0, 0x10, 3}};
const LabelTextRow gWiFiVSCourseSelectSLabelTextRows[7] = {{0, 0xa4, 0x10, 0}, {1, 0xa4, 0x10, 1}, {2, 0xa4, 0x10, 2},
                                                           {3, 0xa4, 0x10, 3}, {4, 0xa4, 0x10, 4}, {5, 0xa4, 0x10, 5},
                                                           {6, 0xa4, 0x10, 6}};
const s32 gCourseIdTable[20] = {0x14, 0x16, 0x1f, 0x12, 0x1b, 0x1c, 0x1e, 0x19, 0x22, 0x1d,
                                0xa,  0xb,  0xd,  0xe,  0x10, 9,    0x24, 0x27, 0x28, 1};
struct WiFiVSCourseSelect *gWiFiVSCourseSelect;

#pragma thumb on

// Sets the digit cells for the place of the kart among the karts that appear for the character and for how many appear.
void WriteKartPositionAndCount(s32 position, s32 kartCount) {
    CellFileSet *fileSet;
    s32 tens;
    s32 ones;

    tens = kartCount / 10 % 10;
    ones = kartCount % 10;
    fileSet = &gPlayerEntryList->mParts;
    fileSet->mCellTable[0x3c].mVisible = position >= 10 ? 1 : 0;
    CopyCellLayoutEntryCellIndex(0x3c, position / 10 % 10 + 0x41, fileSet->mCellLayout);
    CopyCellLayoutEntryCellIndex(0x3d, position % 10 + 0x41, fileSet->mCellLayout);
    if (kartCount >= 10) {
        tens += 0x4b;
        CopyCellLayoutEntryCellIndex(0x3f, tens, fileSet->mCellLayout);
        CopyCellLayoutEntryCellIndex(0x40, ones + 0x4b, fileSet->mCellLayout);
    } else {
        fileSet->mCellTable[0x40].mVisible = 0;
        CopyCellLayoutEntryCellIndex(0x3f, ones + 0x4b, fileSet->mCellLayout);
    }
}

// List callback: action 1 prints the label of a row, action 0 sets the highlight value of the seven slots.
void RefreshCourseListRows(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    CellFileSet *fileSet;
    void *text;
    s32 slotIndex;
    s32 paletteIndex;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    if (action == 1) {
        if (row == 0) {
            text = GetBmgEntry(gWiFiVSCourseSelect->mWiFiMessages, 0x1a);
        } else {
            text = GetBmgEntry(gWiFiVSCourseSelect->mWiFiMessages, GetWiFiCourseMessageIndex(gCourseIdTable[row - 1]));
        }
        PrintLabelLayoutTextNoFixedAdvance(1, slot, fileSet->mLabelLayout, text, fileSet->mCellLayout,
                                           fileSet->mCellTable);
    } else if (action == 0) {
        for (slotIndex = 0; slotIndex < 7; slotIndex++) {
            if (slotIndex == selectedSlot) {
                paletteIndex = 0xe;
            } else {
                paletteIndex = 0xf;
            }
            SetLabelPaletteIndex(slotIndex, paletteIndex, fileSet->mLabelLayout, fileSet->mCellTable,
                                 fileSet->mCellLayout);
        }
    }
}

void SetWiFiVSCourseSelectRowsOffsetY(void) {
    CellFileSet *fileSet;
    s32 cellCount;
    s32 rowIndex;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mCount;
    for (rowIndex = 0; rowIndex < gWiFiVSCourseSelect->mPlayerCount; rowIndex++) {
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex].mOffsetY =
            InterpolateS16(1, 0,
                           0x60 - (((s16 *) GetCellLayoutEntry(
                                       fileSet->mCellLayout, gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex))[1]
                                       << 20 >>
                                   20),
                           (*(struct WiFiVSCourseSelect **) &gWiFiVSCourseSelect)->mStateFrames,
                           WIFI_VS_COURSE_SELECT_FADE_OUT_ROWS_FRAMES);
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex].mOffsetY =
            InterpolateS16(
                1, 0,
                0x60 - (((s16 *) GetLabelLayoutEntry(fileSet->mLabelLayout,
                                                     gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex))[1]
                            << 20 >>
                        20),
                (*(struct WiFiVSCourseSelect **) &gWiFiVSCourseSelect)->mStateFrames,
                WIFI_VS_COURSE_SELECT_FADE_OUT_ROWS_FRAMES);
    }
}

void ShowWiFiSessionCourse(void) {
    CellFileSet *fileSet;
    u16 cellCount;
    s32 rowIndex;
    s32 courseId;
    u16 *text;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mCount;
    courseId = GetWiFiSessionCourseId();
    text = GetBmgEntry(gWiFiVSCourseSelect->mCommonMessages, GetCourseMessageIndex(courseId));
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex].mVisible = 0;
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex].mVisible =
            fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex].mVisible;
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex].mOffsetX = 0;
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex].mOffsetX =
            fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[rowIndex].mCellIndex].mOffsetX;
        SetInterpolationStateIfOpposite(&gWiFiVSCourseSelect->mRowInterpolations[rowIndex], INTERPOLATION_STATE_AT_END);
    }
    fileSet->mCellTable[4].mVisible = 1;
    fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex + cellCount].mVisible =
        fileSet->mCellTable[4].mVisible;
    fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex + cellCount].mOffsetY += 2;
    PrintLabelLayoutTextNoFixedAdvance(0, gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex, fileSet->mLabelLayout, text,
                                       fileSet->mCellLayout, fileSet->mCellTable);
    gWiFiVSCourseSelect->mCourseId = courseId;
    gWiFiVSCourseSelect->mCourseMessageIndex = GetCourseMessageIndex(courseId);
    gWiFiVSCourseSelect->mCourseNameStart[0] = text[0];
    gWiFiVSCourseSelect->mCourseNameStart[1] = text[1];
    gWiFiVSCourseSelect->mCourseNameStart[2] = text[2];
    gWiFiVSCourseSelect->mCourseNameStart[3] = text[3];
}

void AdvanceSubCellsOffsetY(void) {
    CellFileSet *fileSet;
    s32 entryCount;
    s32 cellIndex;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    entryCount = fileSet->mCellLayout->mCount + fileSet->mLabelLayout->mCount;
    AdvanceInterpolation(&gWiFiVSCourseSelect->mInterpolations[0]);
    gWiFiVSCourseSelect->mSubOffsetY = GetInterpolatedValue(&gWiFiVSCourseSelect->mInterpolations[0]);
    for (cellIndex = 0; cellIndex < entryCount; cellIndex++) {
        fileSet->mCellTable[cellIndex].mOffsetY = gWiFiVSCourseSelect->mSubOffsetY;
    }
}

void AdvancePickedCourseRows(void) {
    s32 rowIndex;
    CellFileSet *fileSet;
    s32 cellCount;
    s32 pickedCourseId;
    void *text;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mCount;
    for (rowIndex = 0; rowIndex < gWiFiVSCourseSelect->mPlayerCount; rowIndex++) {
        AdvanceInterpolation(&gWiFiVSCourseSelect->mRowInterpolations[rowIndex]);
        if (GetIndexOfPackedIndex(rowIndex) >= 0) {
            pickedCourseId = GetWiFiSessionPickedCourseId(GetIndexOfPackedIndex(rowIndex));
        } else {
            pickedCourseId = 0;
        }
        switch (gWiFiVSCourseSelect->mState) {
            case WIFI_VS_COURSE_SELECT_STATE_WAIT_SLIDE_IN:
            case WIFI_VS_COURSE_SELECT_STATE_PICK_COURSE:
            case WIFI_VS_COURSE_SELECT_STATE_WAIT_OTHER_PICKS:
                if (pickedCourseId != 0 && pickedCourseId != gWiFiVSCourseSelect->mShownCourseIds[rowIndex]) {
                    text = GetBmgEntry(gWiFiVSCourseSelect->mCommonMessages, GetCourseMessageIndex(pickedCourseId));
                    PrintLabelLayoutTextNoFixedAdvance(0, gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex,
                                                       fileSet->mLabelLayout, text, fileSet->mCellLayout,
                                                       fileSet->mCellTable);
                    gWiFiVSCourseSelect->mShownCourseIds[rowIndex] = pickedCourseId;
                    SetInterpolationStateIfOpposite(&gWiFiVSCourseSelect->mRowInterpolations[rowIndex],
                                                    INTERPOLATION_STATE_RISING);
                    if (gWiFiVSCourseSelect->mEntryIndex != rowIndex) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x208);
                    }
                }
                break;
        }
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex].mOffsetX =
            GetInterpolatedValue(&gWiFiVSCourseSelect->mRowInterpolations[rowIndex]);
        fileSet->mCellTable[gCourseRowCellIndices[rowIndex]].mOffsetX =
            fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[rowIndex].mLabelIndex].mOffsetX;
    }
}

void AdvanceWiFiVSCourseSelectTimer(void) {
    s32 seconds;
    CellFileSet *fileSet;
    LayoutEntryTable *cellLayout;
    void *cells;

    seconds = 0;
    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    AdvanceInterpolation(&gWiFiVSCourseSelect->mInterpolations[2]);
    fileSet->mCellTable[16].mOffsetX = GetInterpolatedValue(&gWiFiVSCourseSelect->mInterpolations[2]);
    fileSet->mCellTable[15].mOffsetX = fileSet->mCellTable[16].mOffsetX;
    switch (gWiFiVSCourseSelect->mState) {
        case WIFI_VS_COURSE_SELECT_STATE_WAIT_SLIDE_IN:
        case WIFI_VS_COURSE_SELECT_STATE_PICK_COURSE:
        case WIFI_VS_COURSE_SELECT_STATE_WAIT_OTHER_PICKS:
            if (gWiFiVSCourseSelect->mTimer != 0) {
                gWiFiVSCourseSelect->mTimer--;
                seconds = (gWiFiVSCourseSelect->mTimer + 0x3c) / 0x3c;
                fileSet->mCellTable[15].mVisible = seconds >= 10 ? 1 : 0;
                if (gWiFiVSCourseSelect->mTimer == 0) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x51);
                } else if ((gWiFiVSCourseSelect->mTimer + 0x3c) % 0x3c == 0 && seconds <= 4) {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x50);
                }
            }
            cellLayout = fileSet->mCellLayout;
            cells = fileSet->mCells;
            QueueCellChars(gCourseTimerDigitCellIndices[seconds / 10 % 10], cells, fileSet->mChars, cellLayout, 0, 0xf,
                           cells, cellLayout);
            cellLayout = fileSet->mCellLayout;
            cells = fileSet->mCells;
            QueueCellChars(gCourseTimerDigitCellIndices[seconds % 10], cells, fileSet->mChars, cellLayout, 0, 0x10,
                           cells, cellLayout);
            break;
    }
}

// Picks a course index at random that none of the stored course ids of the earlier races has.
s32 PickRandomCourseIndexNotRaced(void) {
    WiFiVSCourseSelect *courseSelect;
    RandomState64 *random;
    MenuShared *menuShared;
    s32 entryIndex;
    s32 courseIndex;
    BOOL notRaced;
    u32 courseId;
    u32 *cursor;

    courseSelect = gWiFiVSCourseSelect;
    random = &courseSelect->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    courseIndex = (u16) (random->mValue >> 32 >> 20) % 20;
    menuShared = gMenuShared;
    do {
        notRaced = TRUE;
        courseIndex = (courseIndex + 1) % 20;
        entryIndex = 0;
        cursor = (u32 *) menuShared;
        courseId = gCourseIdTable[courseIndex];
        for (; entryIndex < 4; entryIndex++) {
            if (cursor[0x17] == courseId) {
                notRaced = FALSE;
                break;
            }
            cursor++;
        }
    } while (notRaced == FALSE);
    return courseIndex;
}

void InitWiFiVSCourseSelect(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    RandomState64 *random;
    u32 tick;
    u32 seed;
    u32 objSizeLeft;
    s32 index;
    s32 value;
    s32 subCellCount;
    s32 subIndex;
    s32 labelIndex;
    LayoutTableEntry *cellTable;
    u16 values[2];

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gWiFiVSCourseSelect = HeapAlloc(heap, sizeof(*gWiFiVSCourseSelect));
    MemFillWordsByBlock_inline(gWiFiVSCourseSelect, 0x158);
    gWiFiVSCourseSelect->mHeap = heap;
    gWiFiVSCourseSelect->mOamLists[0] = mainOam;
    gWiFiVSCourseSelect->mOamLists[1] = subOam;
    gWiFiVSCourseSelect->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gWiFiVSCourseSelect->mWiFiMessages = FindSceneFile("wifi.bmg");
    tick = OS_GetTick();
    seed = (tick << 16) + (u32) OS_GetTick();
    random = &gWiFiVSCourseSelect->mRandom;
    random->mValue = seed;
    random->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    random->mIncrement = RANDOM_STATE64_INCREMENT;
    gWiFiVSCourseSelect->mPlayerCount = GetSessionKartCount();
    gWiFiVSCourseSelect->mEntryIndex = GetRaceSetupCopyEntryIndex();
    gWiFiVSCourseSelect->mTimer = WIFI_VS_COURSE_SELECT_TIMER_FRAMES;
    gWiFiVSCourseSelect->mSubOffsetY = -0xc0;
    for (index = 0; index < 4; index++) {
        gWiFiVSCourseSelect->mShownCourseIds[index] = 0;
        SetupInterpolation(&gWiFiVSCourseSelect->mRowInterpolations[index], 3, 10, 0xfc, 0);
    }
    SetupInterpolation(&gWiFiVSCourseSelect->mInterpolations[1], 0, 10, -0x40, 0);
    SetupInterpolation(&gWiFiVSCourseSelect->mInterpolations[0], 0, 10, -0xc0, 0);
    SetupInterpolation(&gWiFiVSCourseSelect->mInterpolations[2], 0, 10, 0x40, 0);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0xc00;
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, gWiFiVSCourseSelect, "WiFi_VS_course_select_m_b.NCGR",
                                   "WiFi_VS_course_select_m_b.NCLR", "WiFi_VS_course_select_m.NSCR", 0, FindSceneFile);
    mainFileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    objSizeLeft = GX_GetSizeOfOBJ();
    LocateCellFileSet(mainFileSet, "WiFi_VS_course_select_m.nce.ncgr", "WiFi_VS_course_select_m.nce.ncer",
                      "WiFi_VS_course_select_m_o.NCLR", "WiFi_VS_course_select_m.bncl", "WiFi_VS_course_select_m.bnll",
                      NULL, FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_MAIN, gWiFiVSCourseSelect->mHeap, mainFileSet);
    value = mainFileSet->mCellLayout->mCount;
    for (index = 0; index < value; index++) {
        SetCellPriority(index, 1, mainFileSet->mCells, mainFileSet->mCellLayout);
    }
    for (index = 0; index < mainFileSet->mLabelLayout->mCount; index++) {
        objSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_MAIN, gWiFiVSCourseSelect->mHeap, mainFileSet,
                                        &gWiFiVSCourseSelectMLabelTextRows[index], objSizeLeft);
    }
    for (index = gWiFiVSCourseSelect->mPlayerCount; index < 4; index++) {
        mainFileSet->mCellTable[gCourseRowCellIndices[index]].mVisible = 0;
        mainFileSet->mCellTable[value + gWiFiVSCourseSelectMLabelTextRows[index].mLabelIndex].mVisible = 0;
    }
    for (index = 0; index < value; index++) {
        SetCellPriority(index, 2, mainFileSet->mCells, mainFileSet->mCellLayout);
    }
    mainFileSet->mCellTable[4].mOffsetY =
        0x60 - (((s16 *) GetCellLayoutEntry(mainFileSet->mCellLayout, 4))[1] << 20 >> 20);
    mainFileSet->mCellTable[4].mVisible = 0;
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_SUB, &gWiFiVSCourseSelect->mWiFiVSCourseSelectMBAndSBParts[1],
                                   "WIFI_VS_COURSE_SELECT_S_B.NCGR", "WIFI_VS_COURSE_SELECT_S_B.NCLR",
                                   "WIFI_VS_COURSE_SELECT_S.NSCR", 3, FindSceneFile);
    subFileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    objSizeLeft = GX_GetSizeOfSubOBJ();
    LocateCellFileSet(subFileSet, "WiFi_VS_course_select_s.nce.ncgr", "WiFi_VS_course_select_s.nce.ncer",
                      "WiFi_VS_course_select_s_o.NCLR", "WiFi_VS_course_select_s.bncl", "WiFi_VS_course_select_s.bnll",
                      "WiFi_VS_course_select_s.bnbl", FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gWiFiVSCourseSelect->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->mCount;
    for (subIndex = 0; subIndex < subCellCount; subIndex++) {
        SetCellPriority(subIndex, 1, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (subIndex = 0; subIndex < subFileSet->mLabelLayout->mCount; subIndex++) {
        objSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_SUB, gWiFiVSCourseSelect->mHeap, subFileSet,
                                        &gWiFiVSCourseSelectSLabelTextRows[subIndex], objSizeLeft);
    }
    for (subIndex = 0; subIndex < subCellCount; subIndex++) {
        SetCellPriority(subIndex, 2, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (index = 0; index < 7; index++) {
        value = gWiFiVSCourseSelectSLabelTextRows[index].mCellIndex;
        labelIndex = gWiFiVSCourseSelectSLabelTextRows[index].mLabelIndex;
        cellTable = subFileSet->mCellTable;
        SetLayoutEntryPositionFromCell(value, cellTable + value, subFileSet->mCellLayout);
        SetLayoutEntryPositionFromLabel(labelIndex, cellTable + labelIndex + subCellCount, subFileSet->mLabelLayout);
    }
    SetLayoutEntryPositionFromCell(7, subFileSet->mCellTable + 7, subFileSet->mCellLayout);
    values[0] = 0;
    values[1] = subCellCount;
    InitScrollList(gWiFiVSCourseSelect->mHeap, 2, values, 7, 8, 0x7c, subFileSet->mCellTable, subFileSet->mRects,
                   gWiFiVSCourseSelect->mWiFiVSCourseSelectMBAndSBParts[1].mScreenMaps[3]->mData, 5, 6, 0, 0x15,
                   RefreshCourseListRows);
    FrmHeapShrinkInParent(gWiFiVSCourseSelect->mHeap);
}

s32 AdvanceWiFiVSCourseSelect(void) {
    WiFiVSCourseSelect *courseSelect;
    CellFileSet *fileSets;
    s32 result = 0;
    s32 fileSetIndex;
    s32 value;

    AdvanceScrollList();
    AdvancePickedCourseRows();
    switch (gWiFiVSCourseSelect->mState) {
        case WIFI_VS_COURSE_SELECT_STATE_WAIT_SLIDE_IN:
            if (AreBrightnessFadesClear() == 0) {
                break;
            }
            if (gWiFiVSCourseSelect->mInterpolations[0].mState == INTERPOLATION_STATE_AT_END) {
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_PICK_COURSE;
            }
            AdvanceSubCellsOffsetY();
            break;
        case WIFI_VS_COURSE_SELECT_STATE_PICK_COURSE:
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x208);
            }
            if (IsScrollListPickFinished() == 0 && gWiFiVSCourseSelect->mTimer != 0) {
                break;
            }
            value = GetScrollListSelectedRow();
            if (value == 0) {
                value = PickRandomCourseIndexNotRaced();
            } else {
                value--;
            }
            SetWiFiSessionOwnPickedCourseId(gCourseIdTable[value]);
            gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_WAIT_OTHER_PICKS;
            gWiFiVSCourseSelect->mSelectResult = 1;
            SetScrollListEnabled(0);
            break;
        case WIFI_VS_COURSE_SELECT_STATE_WAIT_OTHER_PICKS:
            if (IsWiFiSessionStep10Reached() != 0) {
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_HOLD_PICKS;
                SetInterpolationStateIfOpposite(&gWiFiVSCourseSelect->mInterpolations[2], INTERPOLATION_STATE_FALLING);
            }
            break;
        case WIFI_VS_COURSE_SELECT_STATE_HOLD_PICKS:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > WIFI_VS_COURSE_SELECT_HOLD_FRAMES) {
                StartFadeToFadedPositiveOneScreen(WIFI_VS_COURSE_SELECT_FADE_OUT_ROWS_FRAMES, 1);
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_FADE_OUT_ROWS;
                gWiFiVSCourseSelect->mStateFrames = 0;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x209);
            }
            break;
        case WIFI_VS_COURSE_SELECT_STATE_FADE_OUT_ROWS:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames <= WIFI_VS_COURSE_SELECT_FADE_OUT_ROWS_FRAMES) {
                SetWiFiVSCourseSelectRowsOffsetY();
            } else {
                StartFadeToClearOneScreen(10, 1);
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_HOLD_COURSE;
                gWiFiVSCourseSelect->mStateFrames = 0;
                ShowWiFiSessionCourse();
            }
            break;
        case WIFI_VS_COURSE_SELECT_STATE_HOLD_COURSE:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > WIFI_VS_COURSE_SELECT_HOLD_FRAMES) {
                StartFadeToFadedNegative(10);
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_FADE_IN;
                gWiFiVSCourseSelect->mStateFrames = 0;
            }
            break;
        case WIFI_VS_COURSE_SELECT_STATE_FADE_IN:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > WIFI_VS_COURSE_SELECT_FADE_TO_FADED_FRAMES) {
                gWiFiVSCourseSelect->mState = WIFI_VS_COURSE_SELECT_STATE_DONE;
                gWiFiVSCourseSelect->mStateFrames = 0;
            }
            break;
        case WIFI_VS_COURSE_SELECT_STATE_DONE:
            result = gWiFiVSCourseSelect->mSelectResult;
            break;
    }
    AdvanceWiFiVSCourseSelectTimer();
    AdvanceInterpolation(&gWiFiVSCourseSelect->mInterpolations[1]);
    for (fileSetIndex = 0; fileSetIndex < 2; fileSetIndex++) {
        courseSelect = gWiFiVSCourseSelect;
        fileSets = &courseSelect->mWiFiVSCourseSelectMParts;
        DrawLayoutTable(fileSets[fileSetIndex].mCellLayout, fileSets[fileSetIndex].mCells,
                        fileSets[fileSetIndex].mLabelLayout, courseSelect->mOamLists[fileSetIndex],
                        fileSets[fileSetIndex].mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseWiFiVSCourseSelect(void) {
    HeapDestroy(gWiFiVSCourseSelect->mHeap);
    *&gWiFiVSCourseSelect = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteWiFiVSCourseSelectRegisters(void) {
    s32 window0V;

    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1a00;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 2;
    reg_G2_BG0OFS = (-GetInterpolatedValue(&gWiFiVSCourseSelect->mInterpolations[1]) << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gWiFiVSCourseSelect->mSubOffsetY << 16) & 0x1ff0000;
    if (gWiFiVSCourseSelect->mSubOffsetY != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT &
                              ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
                             REG_GXS_DB_DISPCNT_W0_MASK;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | 7) | 0x20;
        window0V = gWiFiVSCourseSelect->mSubOffsetY + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = window0V & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT &
                             ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
    }
}

#pragma thumb off

#pragma thumb on

void LoadWiFiVSCourseSelectFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    NNSG2dCellDataBank *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindSceneFile("WiFi_VS_course_select_m_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("WiFi_VS_course_select_s_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("WiFi_VS_course_select_m.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("WiFi_VS_course_select_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("WiFi_VS_course_select_m.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("WiFi_VS_course_select_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("WiFi_VS_course_select_m_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("WiFi_VS_course_select_m_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("WiFi_VS_course_select_s_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("WiFi_VS_course_select_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("WiFi_VS_course_select_m.NSCR");
    LoadNscrData(screenMaps, file);
    file = FindSceneFile("WiFi_VS_course_select_s.NSCR");
    LoadNscrData(screenMaps, file);
}

#pragma thumb off
