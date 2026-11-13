#include "Main/Menu/select_kart_data.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/Menu/select_kart_entry_list.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Graphics/message_index.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Graphics/cell_layout.h"
#include "code_0214d018.h"
#include "Main/Menu/data_0202bb80.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_appear.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/palette_blend.h"
#include "code_02148950.h"
#include "Main/Kart/data_02161000.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Net/wifi_session.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/System/interpolation.h"
#include "registers.h"
#include "g2.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/System/init_after_startup.h"

const u16 gKeyTargets12RowsRow0[4] = {0xffff, 4, 1, 0xffff};
const u16 gKeyTargets8RowsRow7[4] = {4, 0xffff, 0xffff, 6};
const u16 gKeyTargets8RowsRow6Else[4] = {3, 0xffff, 7, 5};
const u16 gKeyTargets8RowsRow6Previous4[4] = {4, 0xffff, 7, 5};
const u16 gKeyTargets8RowsRow5[4] = {3, 0xffff, 6, 0xffff};
const u16 gKeyTargets8RowsRow4Else[4] = {1, 6, 0xffff, 3};
const u16 gKeyTargets8RowsRow4Previous2Or7[4] = {2, 7, 0xffff, 3};
const u16 gKeyTargets8RowsRow3Else[4] = {0, 5, 4, 0xffff};
const u16 gKeyTargets8RowsRow3Previous1Or6[4] = {1, 6, 4, 0xffff};
const u16 gKeyTargets8RowsRow2[4] = {0xffff, 4, 0xffff, 1};
const u16 gKeyTargets8RowsRow1Else[4] = {0xffff, 3, 2, 0};
const u16 gKeyTargets8RowsRow1Previous4[4] = {0xffff, 4, 2, 0};
const u16 gKeyTargets8RowsRow0[4] = {0xffff, 3, 1, 0xffff};
const u16 gKeyTargets9RowsRow8[4] = {5, 0xffff, 0xffff, 7};
const u16 gKeyTargets9RowsRow7[4] = {4, 0xffff, 8, 6};
const u16 gKeyTargets9RowsRow6[4] = {3, 0xffff, 7, 0xffff};
const u16 gKeyTargets9RowsRow5[4] = {2, 8, 0xffff, 4};
const u16 gKeyTargets9RowsRow4[4] = {1, 7, 5, 3};
const u16 gKeyTargets9RowsRow3[4] = {0, 6, 4, 0xffff};
const u16 gKeyTargets9RowsRow2[4] = {0xffff, 5, 0xffff, 1};
const u16 gKeyTargets9RowsRow1[4] = {0xffff, 4, 2, 0};
const u16 gKeyTargets9RowsRow0[4] = {0xffff, 3, 1, 0xffff};
const u16 gKeyTargets10RowsRow9[4] = {6, 0xffff, 0xffff, 8};
const u16 gKeyTargets10RowsRow8Else[4] = {4, 0xffff, 9, 7};
const u16 gKeyTargets10RowsRow8Previous5[4] = {5, 0xffff, 9, 7};
const u16 gKeyTargets10RowsRow7[4] = {3, 0xffff, 8, 0xffff};
const u16 gKeyTargets10RowsRow6[4] = {2, 9, 0xffff, 5};
const u16 gKeyTargets10RowsRow5[4] = {1, 8, 6, 4};
const u16 gKeyTargets10RowsRow4[4] = {1, 8, 5, 3};
const u16 gKeyTargets10RowsRow3[4] = {0, 7, 4, 0xffff};
const u16 gKeyTargets10RowsRow2[4] = {0xffff, 6, 0xffff, 1};
const u16 gKeyTargets10RowsRow1Else[4] = {0xffff, 4, 2, 0};
const u16 gKeyTargets10RowsRow1Previous5[4] = {0xffff, 5, 2, 0};
const u16 gKeyTargets10RowsRow0[4] = {0xffff, 3, 1, 0xffff};
const u16 gKeyTargets11RowsRow10[4] = {6, 0xffff, 0xffff, 9};
const u16 gKeyTargets11RowsRow9[4] = {5, 0xffff, 0xa, 8};
const u16 gKeyTargets11RowsRow8[4] = {5, 0xffff, 9, 7};
const u16 gKeyTargets11RowsRow7[4] = {4, 0xffff, 8, 0xffff};
const u16 gKeyTargets11RowsRow6[4] = {3, 0xa, 0xffff, 5};
const u16 gKeyTargets11RowsRow5Else[4] = {1, 8, 6, 4};
const u16 gKeyTargets11RowsRow5Previous2Or9[4] = {2, 9, 6, 4};
const u16 gKeyTargets11RowsRow4[4] = {0, 7, 5, 0xffff};
const u16 gKeyTargets11RowsRow3[4] = {0xffff, 6, 0xffff, 2};
const u16 gKeyTargets11RowsRow2[4] = {0xffff, 5, 3, 1};
const u16 gKeyTargets11RowsRow1[4] = {0xffff, 5, 2, 0};
const u16 gKeyTargets11RowsRow0[4] = {0xffff, 4, 1, 0xffff};
const u16 gKeyTargets12RowsRow11[4] = {7, 0xffff, 0xffff, 0xa};
const u16 gKeyTargets12RowsRow10[4] = {6, 0xffff, 0xb, 9};
const u16 gKeyTargets12RowsRow9[4] = {5, 0xffff, 0xa, 8};
const u16 gKeyTargets12RowsRow8[4] = {4, 0xffff, 9, 0xffff};
const u16 gKeyTargets12RowsRow7[4] = {3, 0xb, 0xffff, 6};
const u16 gKeyTargets12RowsRow6[4] = {2, 0xa, 7, 5};
const u16 gKeyTargets12RowsRow5[4] = {1, 9, 6, 4};
const u16 gKeyTargets12RowsRow4[4] = {0, 8, 5, 0xffff};
const u16 gKeyTargets12RowsRow3[4] = {0xffff, 7, 0xffff, 2};
const u16 gKeyTargets12RowsRow2[4] = {0xffff, 6, 3, 1};
const u16 gKeyTargets12RowsRow1[4] = {0xffff, 5, 2, 0};
const u16 gNameLayoutEntryIndexByCharacter[12] = {0, 5, 4, 7, 2, 6, 3, 1, 9, 8, 0xa, 0xb};
const LabelCanvasEntry gSelectKartSLabelCanvasEntries[9] = {
    {0, 95, 13, 11, 5}, {1, 95, 13, 12, 4}, {2, 95, 13, 13, 3}, {3, 95, 13, 14, 2}, {4, 95, 13, 15, 1},
    {5, 95, 13, 16, 0}, {6, 50, 13, 18, 4}, {7, 170, 13, 0, 0}, {8, 170, 13, 1, 0},
};

#pragma optimize_for_size on
#pragma thumb on
s32 UpdateSelectKartTouchHold(void) {
    s32 result = -1;
    CellFileSet *cellFileSet = &gSelectKart->mSelectKartSParts;
    u16 slotIndex = GetPadInputSlot();
    s32 pairX;
    s32 pairY;
    s32 rectIndex;
    if (gSelectKart->mTouchHeld != FALSE) {
        if (SelectKartSlotHasPairOrLost(slotIndex) != 0) {
            pairX = SelectKartGetSlotPairX(slotIndex);
            pairY = SelectKartGetSlotPairY(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, cellFileSet->mRects);
            if (rectIndex != gSelectKart->mTouchRect) {
                gSelectKart->mTouchHeld = FALSE;
                gSelectKart->mTouchHeldFrames = 0;
            } else {
                gSelectKart->mTouchHeldFrames++;
                result = rectIndex;
            }
        } else {
            gSelectKart->mTouchHeld = FALSE;
            gSelectKart->mTouchHeldFrames = 0;
        }
    } else if (SelectKartIsSlotPairNew(slotIndex) != 0) {
        result = FindRectContainingPoint(SelectKartGetSlotPairX(slotIndex), SelectKartGetSlotPairY(slotIndex),
                                         cellFileSet->mRects);
        gSelectKart->mTouchHeld = TRUE;
        gSelectKart->mTouchHeldFrames = 0;
    }
    return result;
}

u32 IsSelectKartTouchRepeat(s32 rectIndex) {
    u32 result = 0;
    u32 repeatDue;
    SelectKart *selectKart = gSelectKart;
    s32 heldFrames;
    if (selectKart->mTouchRect == rectIndex) {
        heldFrames = selectKart->mTouchHeldFrames;
        result |= (heldFrames == 0);
        repeatDue = 0;
        if (heldFrames >= 0x3c) {
            if ((heldFrames - 0x3c) % 0xf == 0) {
                repeatDue = 1;
            }
        }
        result |= repeatDue;
    }
    return result;
}

void SetSelectKartGpMPartsOffsets(void) {
    SelectKart *selectKart = gSelectKart;
    CellFileSet *gpMParts;
    if (selectKart->mEntryListUsed == FALSE) {
        gpMParts = &selectKart->mSelectCharacterGpMParts;
        gpMParts->mCellTable[1].mOffsetX = GetInterpolatedValue(&selectKart->mInterpolations[0]);
        gpMParts->mCellTable[2].mOffsetX = gpMParts->mCellTable[1].mOffsetX;
        gpMParts->mCellTable[0].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[1]);
        gpMParts->mCellTable[3].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[2]);
        gpMParts->mCellTable[9].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[3]);
        gpMParts->mCellTable[8].mOffsetY = gpMParts->mCellTable[9].mOffsetY;
        gpMParts->mCellTable[7].mOffsetY = gpMParts->mCellTable[8].mOffsetY;
        gpMParts->mCellTable[6].mOffsetY = gpMParts->mCellTable[7].mOffsetY;
        gpMParts->mCellTable[5].mOffsetY = gpMParts->mCellTable[6].mOffsetY;
        gpMParts->mCellTable[4].mOffsetY = gpMParts->mCellTable[5].mOffsetY;
    }
}
#pragma thumb off

u32 GetCellLayoutCount(LayoutEntryTable *cellLayout) {
    return cellLayout->mCount;
}

u32 GetLabelLayoutCount(LayoutEntryTable *labelLayout) {
    return labelLayout->mCount;
}

#pragma optimize_for_size on
#pragma thumb on
void SetSelectKartSPartsOffsetY(void) {
    CellFileSet *parts;
    s32 cellIndex;
    s32 count;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        parts = &gSelectKart->mSelectKartSParts;
        count = GetCellLayoutCount(parts->mCellLayout) + GetLabelLayoutCount(parts->mLabelLayout);
        for (cellIndex = 0; cellIndex < count; cellIndex++) {
            parts->mCellTable[cellIndex].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
        }
    }
}

u32 IsSelectKartModeAndTimerZero(void) {
    u32 result = 0;
    if (gSelectKart->mMode != 0 && IsPlayerEntryListTimerZero() != 0) {
        result = 1;
    }
    return result;
}

void PrintSelectKartMessage(void) {
    s32 labelIndex;
    CellFileSet *parts;
    void *message;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        message = GetBmgEntry(gSelectKart->mKartSelectMessages, GetKartMessageIndex(gSelectKart->mKartIndex));
        parts = &gSelectKart->mSelectKartSParts;
        for (labelIndex = 8; labelIndex >= 7; labelIndex--) {
            PrintLabelLayoutTextNoFixedAdvance(1, gSelectKartSLabelCanvasEntries[labelIndex].mLabelIndex, parts->mLabelLayout,
                                               message, parts->mCellLayout, parts->mCellTable);
        }
    }
}
#pragma thumb off

void *GetCellLayoutEntrySwapped(s32 index, LayoutEntryTable *cellLayout) {
    return GetCellLayoutEntry(cellLayout, index);
}

#pragma thumb on

void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts) {
    LayoutAxis *startCell = GetCellLayoutEntrySwapped(elementIndex, parts->mCellLayout);
    LayoutAxis *endCell = GetCellLayoutEntrySwapped(endCellIndex, parts->mCellLayout);
    parts->mCellTable[elementIndex].mOffsetX = (100 - paramValue) * (endCell->mUnk_00_0 - startCell->mUnk_00_0) / 100;
}

#pragma thumb off

#pragma thumb on

void RefreshKartMenuParamElements(void) {
    int result;
    CellFileSet *parts;
    short *params;
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        params = ComputeKartMenuParams(gSelectKart->mKartIndex, gSelectKart->mCharacterIndex);
        parts = &gSelectKart->mSelectKartSParts;
        SetKartMenuParamElementOffset(10, 0x10, *params, parts);
        SetKartMenuParamElementOffset(9, 0xf, params[1], parts);
        SetKartMenuParamElementOffset(8, 0xe, params[2], parts);
        SetKartMenuParamElementOffset(7, 0xd, params[3], parts);
        SetKartMenuParamElementOffset(6, 0xc, params[4], parts);
        SetKartMenuParamElementOffset(5, 0xb, params[5], parts);
    }
}

#pragma thumb off

void SelectKartMI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void SelectKartMI_CpuClearFast(void *destination, u32 size) {
    SelectKartMI_CpuFillFast(destination, 0, size);
}

u16 GetOwnIndexOrZero(void) {
    int index;
    if (gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD) {
        index = gConnectionWork->mOwnIndex;
    } else {
        index = 0;
    }
    return index;
}

u32 GetParticipantEntryIndex(u32 participantIndex) {
    return (gConnectionWork->mParticipantPosByIndex[participantIndex].mEntryIndex);
}

u32 GetOwnEntryIndex(void) {
    u32 value0;
    value0 = GetOwnIndexOrZero();
    value0 = GetParticipantEntryIndex(value0);
    return value0;
}

#pragma optimize_for_size on

#pragma thumb on
void InitSelectKart(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    CellFileSet titleFileSet;
    CellFileSet nameFileSet;
    SelectKart *selectKart;
    s32 index;
    s32 listKind;
    s32 value;
    u32 entryListUsed;
    void *text;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectKart = HeapAlloc(heap, 0x118);
    SelectKartMI_CpuClearFast(gSelectKart, 0x118);
    gSelectKart->mHeap = heap;
    gSelectKart->mMode = mode;
    gSelectKart->mTouchRect = -1;
    switch (GetRaceSetupCopy()->mEntryTransition) {
        case 1:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 1, 10, 0x60, 0);
            break;
        case 0:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 0, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 0, 10, 0x60, 0);
            if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
                StartKartModelMenuBg0Increase();
                SetKartModelMenuSpinStopped(0);
            }
            break;
    }
    SetupInterpolation(&gSelectKart->mInterpolations[1], 0, 10, -0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[3], 0, 10, 0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[4], 0, 10, -0xc0, 0);
    gSelectKart->mMainOam = mainOam;
    gSelectKart->mSubOam = subOam;
    if (gSelectKart->mMode != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        entryListUsed = 1;
    } else {
        entryListUsed = 0;
    }
    gSelectKart->mEntryListUsed = entryListUsed;
    if (gSelectKart->mEntryListUsed != FALSE) {
        switch (gSelectKart->mMode) {
            case 0:
                listKind = 0;
                break;
            case 1:
                listKind = 1;
                break;
            case 2:
                listKind = 2;
                break;
        }
        SetupPlayerEntryList(listKind, PLAYER_ENTRY_LIST_KART);
    }
    switch (gSelectKart->mMode) {
        case 0:
            gSelectKart->mEntryIndex = 0;
            break;
        case 1:
            gSelectKart->mEntryIndex = GetOwnEntryIndex();
            break;
        case 2:
            gSelectKart->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        gSelectKart->mKartSelectMessages = FindFileInLoadedArchives("kart_select.bmg");
        gSelectKart->mKartAppear = CreateKartAppear(gSelectKart->mHeap);
    }
    selectKart = gSelectKart;
    selectKart->mCharacterIndex = GetRaceSetupCopy()->mEntries[selectKart->mEntryIndex].mCharacterIndex;
    selectKart = gSelectKart;
    selectKart->mKartIndex = GetRaceSetupCopy()->mEntries[selectKart->mEntryIndex].mKartIndex;
    if (gSelectKart->mCharacterIndex == -1) {
        gSelectKart->mCharacterIndex = 0;
    }
    if (gSelectKart->mKartIndex == -1) {
        gSelectKart->mKartIndex = 0;
    }
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = 0;
    gSelectKart->mKartTableIndex = FindKartTableIndex(gSelectKart->mKartIndex);
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        if (selectKart->mEntryListUsed == FALSE) {
            cellFileSet = &selectKart->mSelectCharacterGpMParts;
            LocateCellFileSet(cellFileSet, "select_character_gp_m.nce.ncgr", "select_character_gp_m.nce.ncer",
                              "select_character_gp_m_o.NCLR", "select_character_gp_m.bncl", NULL, NULL,
                              FindFileInLoadedArchives);
            SetupCellFileSet(0, gSelectKart->mHeap, cellFileSet);
            LocateCellFileSet(&titleFileSet, "select_character_gp_title_m.nce.ncgr", "select_character_gp_title_m.nce.ncer", NULL,
                              "select_character_gp_title_m.bncl", NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(1, titleFileSet.mCells, titleFileSet.mChars, titleFileSet.mCellLayout, 0, 0,
                           cellFileSet->mCells, cellFileSet->mCellLayout);
            LocateCellFileSet(&nameFileSet, "select_character_gp_name_m.nce.ncgr", "select_character_gp_name_m.nce.ncer", NULL,
                              "select_character_gp_name_m.bncl", NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(gNameLayoutEntryIndexByCharacter[gSelectKart->mCharacterIndex], nameFileSet.mCells, nameFileSet.mChars,
                           nameFileSet.mCellLayout, 0, 2, cellFileSet->mCells, cellFileSet->mCellLayout);
            QueueCellChars(gNameLayoutEntryIndexByCharacter[gSelectKart->mCharacterIndex], nameFileSet.mCells, nameFileSet.mChars,
                           nameFileSet.mCellLayout, 0, 1, cellFileSet->mCells, cellFileSet->mCellLayout);
        }
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        LocateAndQueueScreenMapFileSet(1, &gSelectKart->mSelectKartSBParts, "select_kart_s_b.NCGR",
                                       "select_kart_s_b.NCLR", "select_kart_s.NSCR", 3, FindFileInLoadedArchives);
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        value = GX_GetSizeOfSubOBJ();
        cellFileSet = &gSelectKart->mSelectKartSParts;
        LocateCellFileSet(cellFileSet, "select_kart_s.nce.ncgr", "select_kart_s.nce.ncer", "select_kart_s_o.NCLR",
                          "select_kart_s.bncl", "select_kart_s.bnll", "select_kart_s.bnbl", FindFileInLoadedArchives);
        SetupCellFileSet(1, gSelectKart->mHeap, cellFileSet);
        for (index = 0; index < 9; index++) {
            value -= SetupLabelCanvas(1, gSelectKart->mHeap, cellFileSet, &gSelectKartSLabelCanvasEntries[index], value);
        }
        for (index = 0; index < 6; index++) {
            text = GetBmgEntry(gSelectKart->mKartSelectMessages, gSelectKartSLabelCanvasEntries[index].mMessageIndex);
            value = gSelectKartSLabelCanvasEntries[index].mLabelIndex;
            PrintLabelLayoutTextNoFixedAdvance(1, value, cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                               cellFileSet->mCellTable);
            SetLabelPriority(value, 1, cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        }
        text = GetBmgEntry(FindFileInLoadedArchives("common.bmg"), gSelectKartSLabelCanvasEntries[6].mMessageIndex);
        index = gSelectKartSLabelCanvasEntries[6].mLabelIndex;
        PrintLabelLayoutTextNoFixedAdvance(1, index, cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                           cellFileSet->mCellTable);
        SetLabelPaletteIndex(index, 1, cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        InitPaletteBlend(gSelectKart->mHeap, cellFileSet->mPalette, 1);
        cellFileSet->mCellTable[2].mVisible = 0;
        cellFileSet->mCellTable[3].mVisible = cellFileSet->mCellTable[2].mVisible;
    } else {
        InitSelectRaceRuleWait(gSelectKart->mHeap, gSelectKart->mSubOam);
        SlideInSelectRaceRuleWait();
    }
    RefreshKartMenuParamElements();
    SetSelectKartPositionDigits();
    PrintSelectKartMessage();
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        RequestSelectReturnState1();
    }
    if (SelectKartGetConnectionKind() == 2) {
        SetSelectReturnDisplayBitOn();
    }
    if (gSelectKart->mMode == 0) {
        ClearNonParticipantKartIndices();
    }
    FrmHeapShrinkInParent(heap);
}
#pragma thumb off

u32 GetConnectionState(void) {
    return (gConnectionWork->mState);
}

void SetDataSharingSendByteInState8(u8 sendByte) {
    if (GetConnectionState() == 8) {
        gConnectionWork->mDataSharingSendByte = sendByte;
    }
}

u32 SelectKartGetPairHasPair(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}

#pragma optimize_for_size on

BOOL SelectKartIsPairRecentlyLost(InputSlotPair *pair) {
    if (SelectKartGetPairHasPair(pair) == 0) {
        if (pair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

BOOL SelectKartIsPairNewUnlessLost(InputSlotPair *pair) {
    if (SelectKartIsPairRecentlyLost(pair) == 0) {
        if (SelectKartIsPairNew(pair) != 0) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsSlotPairNew(u32 slot) {
    return SelectKartIsPairNewUnlessLost(&gInputSlots[slot].mPair);
}

u32 SelectKartGetPairX(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairX;
}

u32 SelectKartGetSlotPairX(u32 slot) {
    return SelectKartGetPairX(&gInputSlots[slot].mPair);
}

u32 SelectKartGetPairY(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairY;
}

u32 SelectKartGetSlotPairY(u32 slot) {
    return SelectKartGetPairY(&gInputSlots[slot].mPair);
}

#pragma optimize_for_size on

u16 SelectKartGetInputSlotNewBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u16 SelectKartGetNewBits(u32 slotIndex, u32 mask) {
    return SelectKartGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

int AdvanceSelectKart(void) {
    SelectKart *selectKart;
    CellFileSet *selectKartParts;
    s32 oldKartIndex;
    s32 result;
    s32 padInputSlot;
    s32 isReturnTouched;
    CellFileSet *characterParts;
    u32 value;
    selectKart = gSelectKart;
    oldKartIndex = selectKart->mKartIndex;
    isReturnTouched = 0;
    result = 0;
    characterParts = &selectKart->mSelectCharacterGpMParts;
    selectKartParts = &selectKart->mSelectKartSParts;
    padInputSlot = GetPadInputSlot();
    AdvanceInterpolation(&gSelectKart->mInterpolations[0]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[1]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[2]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[3]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[4]);
    SetSelectKartGpMPartsOffsets();
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        AdvancePaletteBlend();
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        gSelectKart->mTouchRect = UpdateSelectKartTouchHold();
    } else {
        gSelectKart->mTouchRect = -1;
    }
    selectKart = gSelectKart;
    switch (selectKart->mState) {
        case 0:
            if (selectKart->mInterpolations[4].mState == 1) {
                selectKart->mStateFrames = 0;
                if (SelectKartMB_IsMultiBootChildWrapper() != 0) {
                    value = 1;
                } else {
                    value = 2;
                }
                gSelectKart->mState = value;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 1:
            SetDataSharingSendByteInState8(selectKart->mKartIndex | 0x80);
            gSelectKart->mResult = 1;
            gSelectKart->mState = 5;
            break;
        case 2:
            if (SelectKartIsSlotPairNew(padInputSlot) != 0) {
                isReturnTouched = IsSelectReturnState2NoState3Or4RequestAndInRect(SelectKartGetSlotPairX(padInputSlot),
                                                                                  SelectKartGetSlotPairY(padInputSlot));
            }
            if (SelectKartGetNewBits(padInputSlot, PAD_KEY_A) != 0 || gSelectKart->mTouchRect == 2 ||
                IsSelectKartModeAndTimerZero() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 1;
                gSelectKart->mState = 4;
                selectKartParts->mCellTable[18].mVisible = 0;
                SetLabelPaletteIndex(gSelectKartSLabelCanvasEntries[6].mLabelIndex, 0, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
                StartSeqPair(GetCharacterSeqPairNo(gSelectKart->mCharacterIndex), 1);
                SetKartModelMenuSpinStopped(1);
                StopPaletteBlend();
            } else if (SelectKartGetNewBits(padInputSlot, PAD_KEY_B) != 0 || isReturnTouched != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 2;
                StartSelectKartEntryListKindIfUsed(0);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                gSelectKart->mState = 7;
                if (gSelectKart->mMode != 0) {
                    value = 1;
                } else {
                    value = 0;
                }
                RequestSelectReturnState3WithSound(value);
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_RIGHT) != 0 || IsSelectKartTouchRepeat(1) != 0) {
                MoveSelectKartNext();
                gSelectKart->mSlidingCellIndex = 3;
                selectKartParts->mCellTable[1].mVisible = 0;
                selectKartParts->mCellTable[3].mVisible = 1;
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_LEFT) != 0 || IsSelectKartTouchRepeat(0) != 0) {
                MoveSelectKartPrev();
                gSelectKart->mSlidingCellIndex = 2;
                selectKartParts->mCellTable[0].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 1;
            }
            if (oldKartIndex != gSelectKart->mKartIndex) {
                StartCursorMoveSound();
                PrintSelectKartMessage();
                RefreshKartMenuParamElements();
                gSelectKart->mState = 3;
                gSelectKart->mStateFrames = 0;
            }
            break;
        case 3:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 6) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 2;
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = 0;
                selectKartParts->mCellTable[1].mVisible = 1;
                selectKartParts->mCellTable[0].mVisible = 1;
                selectKartParts->mCellTable[3].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 0;
            } else {
                value = LookupFrameOffset(gSelectKart->mStateFrames);
                if (gSelectKart->mSlidingCellIndex == 2) {
                    value = -value;
                }
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = value;
            }
            break;
        case 4:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            selectKart = gSelectKart;
            if (selectKart->mStateFrames >= 5) {
                switch (selectKart->mMode) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = selectKart->mKartIndex;
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = 1;
                        FillRandomKartIndices();
                        gSelectKart->mState = 6;
                        break;
                    case 1:
                        RequestSelectReturnState4();
                        SetDataSharingSendByteInState8(gSelectKart->mKartIndex | 0x80);
                        gSelectKart->mState = 5;
                        break;
                    case 2:
                        RequestSelectReturnState4();
                        SetWiFiSessionOwnKartIndex(gSelectKart->mKartIndex);
                        gSelectKart->mState = 5;
                        break;
                }
                gSelectKart->mStateFrames = 0;
                selectKartParts->mCellTable[18].mVisible = 1;
                SetLabelPaletteIndex(gSelectKartSLabelCanvasEntries[6].mLabelIndex, 1, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
            }
            break;
        case 5:
            if (selectKart->mMode == 1 && IsEveryPlayerKartStored() != 0 ||
                gSelectKart->mMode == 2 && IsWiFiSessionStep7Reached() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 6;
            }
            break;
        case 6:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 0x3c) {
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[0], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[2], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                if (gSelectKart->mMode == 2) {
                    WriteWiFiSessionToRaceSetupCopy();
                    StartSelectKartEntryListKindIfUsed(3);
                } else {
                    StartSelectKartEntryListKindIfUsed(2);
                }
                if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
                    StartKartModelMenuBg0Decrease();
                } else {
                    SlideOutSelectRaceRuleWait();
                }
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 7;
            }
            break;
        case 7:
            if (selectKart->mInterpolations[4].mState == 3) {
                GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = selectKart->mResult == 1;
                gSelectKart->mState = 8;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 8:
            result = selectKart->mResult;
            break;
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        RequestKartModelMenuCharacter(gSelectKart->mCharacterIndex);
        RequestKartModelMenuKart(gSelectKart->mKartIndex);
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
        DrawKartModelMenu();
    }
    selectKart = gSelectKart;
    if (selectKart->mEntryListUsed != FALSE) {
        AdvancePlayerEntryList();
    } else {
        DrawLayoutTable(characterParts->mCellLayout, characterParts->mCells, NULL, selectKart->mMainOam,
                        characterParts->mCellTable);
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        if (selectKart->mState != 8) {
            DrawLayoutTable(selectKartParts->mCellLayout, selectKartParts->mCells, selectKartParts->mLabelLayout,
                            selectKart->mSubOam, selectKartParts->mCellTable);
        }
    } else {
        AdvanceSelectRaceRuleWait();
    }
    switch (result) {
        case 1:
            GetRaceSetupCopy()->mEntryTransition = 0;
            break;
        case 2:
            GetRaceSetupCopy()->mEntryTransition = 2;
            break;
    }
    return result;
}
#pragma thumb off

u32 SelectKartGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

u16 *SelectKartMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 SelectKartMB_IsMultiBootChild(void) {
    if (*SelectKartMB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 SelectKartMB_IsMultiBootChildWrapper(void) {
    return SelectKartMB_IsMultiBootChild();
}

#pragma thumb on

void ReleaseSelectKart(void) {
    int result;
    if ((gSelectKart->mResult == 1) && (result = SelectKartGetConnectionKind(), result == 2)) {
        ClearSelectReturnDisplayBitOn();
    }
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        ClearPaletteBlendPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectKart->mHeap);
    *&gSelectKart = NULL;
}

#pragma thumb off

u32 SelectKartGX_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GX_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GX_DISPCNT = value;
    return value;
}

u32 SelectKartGXS_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetBG3Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg3CntBits(u32 bits) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | bits;
}

void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

u32 WriteSubWinEnableBits(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0xe000) | (bits << 13);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void SelectKartG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}

void SelectKartG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteSelectKartRegisters(void) {
    u32 displayBits = 0x16;
    s32 interpolatedValue = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
    if (gSelectKart->mState != 8) {
        displayBits |= 8;
    }
    SelectKartGX_SetVisiblePlane(0x19);
    SelectKartGXS_SetVisiblePlane(displayBits);
    SelectKartG2S_SetBG3Offset(0, -interpolatedValue);
    WriteSubBg3CntBits(2);
    WriteSubBlendAlpha(0, 0x3f, 6, 10);
    if (interpolatedValue != 0 && gSelectKart->mState != 8) {
        WriteSubWinEnableBits(1);
        SelectKartG2S_SetWnd0InsidePlane(0x1f, 1);
        SelectKartG2S_SetWndOutsidePlane(7, 1);
        SelectKartG2S_SetWnd0Position(0, 0, 0xff, interpolatedValue + 0xc0);
    } else {
        WriteSubWinEnableBits(0);
    }
    if (gSelectKart->mEntryListUsed != FALSE) {
        WritePlayerEntryListRegisters();
    }
}
#pragma thumb off

#pragma thumb on

void LoadSelectKartData(void) {
    void *fileData;
    Ncgr *chars;
    Nclr *palette;
    NNSG2dCellDataBank *cells;
    Nscr *screenMap[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMap[0] = NULL;
    fileData = FindFileInLoadedArchives("select_kart_s_b.NCGR");
    LoadNcgrData(&chars, fileData);
    fileData = FindFileInLoadedArchives("select_kart_s.nce.ncgr");
    LoadNcgrData2(&chars, fileData);
    fileData = FindFileInLoadedArchives("select_kart_s.nce.ncer");
    LoadNcerData(&cells, fileData);
    fileData = FindFileInLoadedArchives("select_kart_s_o.NCLR");
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives("select_kart_s_b.NCLR");
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives("select_kart_s.NSCR");
    LoadNscrData(screenMap, fileData);
}

#pragma thumb off
