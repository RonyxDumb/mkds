#include "Main/Menu/multi_select_member_group.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Menu/multi_select_ns_registers.h"

#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "vram_bank_display_setup.h"
#include "Main/Menu/label_palette_indices.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load_result.h"
#include "wide_string_functions.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/multi_select_ns_input.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u16 gMemberRowRectIndices[4][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0xa, 0xb}};
const LabelMessageRow gMemberGroupLabelMessageRows[5] = {{0, 0x82, 0xd, 4, -1},
                                                         {1, 0x82, 0xd, 5, -1},
                                                         {2, 0x82, 0xd, 6, -1},
                                                         {3, 0x82, 0xd, 7, -1},
                                                         {4, 0xaf, 0xd, 0x59, 2}};
const MemberRowCellIndices gMemberRowCellIndices[4] = {
    {{4, 0x5a, 0x5e, 0x14, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
      0, 8,    0xc,  0x10, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f},
     0},
    {{5, 0x5b, 0x5f, 0x15, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
      1, 9,    0xd,  0x11, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f},
     1},
    {{6, 0x5c, 0x60, 0x16, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
      2, 0xa,  0xe,  0x12, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
     2},
    {{7, 0x5d, 0x61, 0x17, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
      3, 0xb,  0xf,  0x13, 0x48, 0x49, 0x4a, 0x4d, 0x4b, 0x4c, 0x4e, 0x4f},
     3}};
LabelPaletteIndices gMemberLabelPaletteIndices = {{0, 1}};
struct WLMenuCallbacks gMultiSelectMemberGroupCallbacks = {InitMultiSelectMemberGroup, AdvanceMultiSelectMemberGroup,
                                                           ReleaseMultiSelectMemberGroup,
                                                           WriteMultiSelectMemberGroupRegisters};
struct MultiSelectMemberGroup *gMultiSelectMemberGroup;

#pragma thumb on

s32 IsRectInMemberRow(s32 rectIndex, s32 memberRow) {
    s32 columnIndex;
    BOOL found;

    found = FALSE;
    for (columnIndex = 0; columnIndex < 3; columnIndex++) {
        if (rectIndex == gMemberRowRectIndices[memberRow][columnIndex]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 IsSelectedMemberRowSelectable(void) {
    BOOL result;
    s32 selectedIndex;
    BOOL memberChecksPass;

    result = TRUE;
    selectedIndex = gMultiSelectMemberGroup->mSelectedIndex;
    if (selectedIndex != MULTI_SELECT_MEMBER_GROUP_NS_ROW) {
        memberChecksPass = FALSE;
        if (gMultiSelectMemberGroup->mMemberRows[selectedIndex].mHasText != 0 &&
            gMultiSelectMemberGroup->mMemberRows[selectedIndex].mChildCount < 7) {
            memberChecksPass = TRUE;
        }
        if (memberChecksPass == FALSE) {
            result = FALSE;
        }
    }
    return result;
}

void SetMemberGroupCellTableOffsetY(void) {
    s32 cellIndex;
    s32 entryCount;
    CellFileSet *cellFileSet;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    entryCount = cellFileSet->mCellLayout->mCount + cellFileSet->mLabelLayout->mCount;
    for (cellIndex = 0; cellIndex < entryCount; cellIndex++) {
        cellFileSet->mCellTable[cellIndex].mOffsetY = gMultiSelectMemberGroup->mBg3Offset;
    }
}

void RefreshMultiSelectMemberGroup(s32 showSelected) {
    CellFileSet *cellFileSet;
    LabelPaletteIndices valueTable;
    s32 rowIndex;
    s32 cellIndex;
    s32 entryOffset;
    s32 rowSelected;
    s32 rowNotSelected;
    s32 rowFlag;
    BOOL visibleFlag;
    BOOL isMatch;
    const MemberRowCellIndices *rowCellIndices;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    valueTable = gMemberLabelPaletteIndices;
    rowIndex = 0;
    entryOffset = 0;
    rowCellIndices = gMemberRowCellIndices;
    do {
        rowSelected = 0;
        if (gMultiSelectMemberGroup->mSelectedIndex == rowIndex && showSelected != 0) {
            rowSelected = 1;
        }
        rowFlag = OFFSET_PTR(ScanSlotMemberRow, gMultiSelectMemberGroup->mMemberRows, entryOffset)->mHasText;
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = 0;
        }
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[0x18 / 2]].mVisible = rowNotSelected;
        for (cellIndex = 1; cellIndex < 12; cellIndex++) {
            cellFileSet->mCellTable[rowCellIndices->mCellIndices[cellIndex]].mVisible = rowSelected & rowFlag;
            cellFileSet->mCellTable[(rowCellIndices->mCellIndices + 12)[cellIndex]].mVisible = rowNotSelected & rowFlag;
        }
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[1]].mVisible &=
            OFFSET_PTR(ScanSlotMemberRow, gMultiSelectMemberGroup->mMemberRows, entryOffset)->mIsMultiBoot;
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[13]].mVisible &=
            OFFSET_PTR(ScanSlotMemberRow, gMultiSelectMemberGroup->mMemberRows, entryOffset)->mIsMultiBoot;
        if (OFFSET_PTR(ScanSlotMemberRow, gMultiSelectMemberGroup->mMemberRows, entryOffset)->mIsMultiBoot == 0) {
            visibleFlag = TRUE;
        } else {
            visibleFlag = FALSE;
        }
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[2]].mVisible &= visibleFlag;
        if (OFFSET_PTR(ScanSlotMemberRow, gMultiSelectMemberGroup->mMemberRows, entryOffset)->mIsMultiBoot == 0) {
            visibleFlag = TRUE;
        } else {
            visibleFlag = FALSE;
        }
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[14]].mVisible &= visibleFlag;
        for (cellIndex = 0; cellIndex < 8; cellIndex++) {
            if (cellIndex == *(s32 *) (entryOffset + (s32) gMultiSelectMemberGroup + 0x60)) {
                isMatch = TRUE;
            } else {
                isMatch = FALSE;
            }
            cellFileSet->mCellTable[(rowCellIndices->mCellIndices + 4)[cellIndex]].mVisible &= isMatch;
            cellFileSet->mCellTable[(rowCellIndices->mCellIndices + 16)[cellIndex]].mVisible &= isMatch;
        }
        SetLabelPaletteIndex(rowCellIndices->mLabelIndex, valueTable.mPaletteIndices[rowSelected],
                             cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        entryOffset += 0xc;
        rowCellIndices++;
        rowIndex++;
    } while (rowIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT);
    if (gMultiSelectMemberGroup->mSelectedIndex == rowIndex && showSelected != 0) {
        rowSelected = 1;
    } else {
        rowSelected = 0;
    }
    cellFileSet->mCellTable[89].mVisible = rowSelected;
    if (rowSelected == 0) {
        rowNotSelected = 1;
    } else {
        rowNotSelected = 0;
    }
    cellFileSet->mCellTable[88].mVisible = rowNotSelected;
    SetLabelPaletteIndex(4, valueTable.mPaletteIndices[rowSelected], cellFileSet->mLabelLayout, cellFileSet->mCellTable,
                         cellFileSet->mCellLayout);
}

#pragma thumb off

#pragma thumb on

// Fills with 0 using a volatile halfword.
static inline void MultiSelectMI_CpuClear16(void *destination, s32 byteCount) {
    volatile u16 zero = 0;
    MIi_CpuClear16(zero, destination, byteCount);
}

void UpdateMemberRowsFromScanSlots(void) {
    s32 changed;
    CellFileSet *cellFileSet;
    s32 oldHasText;
    s32 oldWord8;
    s32 oldWord4;
    BOOL isNewEntry;
    s32 slotIndex;
    s32 otherSlotIndex;
    ScanSlotText entry;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    changed = 0;
    switch (gMultiSelectMemberGroup->mUpdateState) {
        case MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_SETUP:
            if (AdvanceSetupByMultiBoot(0, 0) == 1) {
                gMultiSelectMemberGroup->mUpdateState = MULTI_SELECT_MEMBER_GROUP_UPDATE_POLL_SLOTS;
            }
            return;
        case MULTI_SELECT_MEMBER_GROUP_UPDATE_POLL_SLOTS:
            if (gMultiSelectMemberGroup->mRowPressed != FALSE) {
                if (gMultiSelectMemberGroup->mSelectedIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT) {
                    for (slotIndex = 0; slotIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT; slotIndex++) {
                        if (TryGetScanSlotName(slotIndex, &GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex]) != 0) {
                            GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex].mTerminator = 0;
                        } else {
                            MultiSelectMI_CpuClear16(&GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex], 0x16);
                        }
                    }
                    if (TryGetScanSlotName(gMultiSelectMemberGroup->mSelectedIndex, NULL) != 0) {
                        GetWLMenuSceneScanSlotPick()->mSlotIndex = gMultiSelectMemberGroup->mSelectedIndex;
                        gMultiSelectMemberGroup->mNextCallbacksIndex = WL_MENU_CALLBACKS_MEMBER_NO_KEY_START;
                        gMultiSelectMemberGroup->mUpdateState = MULTI_SELECT_MEMBER_GROUP_UPDATE_DONE;
                        return;
                    }
                    gMultiSelectMemberGroup->mMemberRows[gMultiSelectMemberGroup->mSelectedIndex].mHasText = 0;
                    return;
                }
                gMultiSelectMemberGroup->mNextCallbacksIndex = WL_MENU_CALLBACKS_MULTI_SELECT_NS;
                gMultiSelectMemberGroup->mUpdateState = MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_CONNECTION_END_ON_LEAVE;
                return;
            }
            if (gMultiSelectMemberGroup->mState != MULTI_SELECT_MEMBER_GROUP_STATE_CHOOSE) {
                return;
            }
            for (slotIndex = 0; slotIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT; slotIndex++) {
                oldHasText = gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText;
                oldWord8 = gMultiSelectMemberGroup->mMemberRows[slotIndex].mChildCount;
                oldWord4 = gMultiSelectMemberGroup->mMemberRows[slotIndex].mIsMultiBoot;
                MultiSelectMI_CpuClear16(&entry, 0x16);
                gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText = TryGetScanSlotName(slotIndex, &entry);
                if (gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText != 0) {
                    entry.mTerminator = 0;
                    PrintLabelLayoutTextNoFixedAdvance(1, gMemberRowCellIndices[slotIndex].mLabelIndex,
                                                       cellFileSet->mLabelLayout, &entry, cellFileSet->mCellLayout,
                                                       cellFileSet->mCellTable);
                    gMultiSelectMemberGroup->mMemberRows[slotIndex].mChildCount = GetScanSlotChildCount(slotIndex);
                    gMultiSelectMemberGroup->mMemberRows[slotIndex].mIsMultiBoot = IsScanSlotMultiBoot(slotIndex);
                } else {
                    PrintLabelLayoutTextNoFixedAdvance(1, gMemberRowCellIndices[slotIndex].mLabelIndex,
                                                       cellFileSet->mLabelLayout,
                                                       GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 8),
                                                       cellFileSet->mCellLayout, cellFileSet->mCellTable);
                    gMultiSelectMemberGroup->mMemberRows[slotIndex].mChildCount = 0;
                    gMultiSelectMemberGroup->mMemberRows[slotIndex].mIsMultiBoot = 0;
                }
                if (oldHasText == 0 && gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText != 0) {
                    isNewEntry = TRUE;
                    for (otherSlotIndex = 0; otherSlotIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT; otherSlotIndex++) {
                        if (wcsncmp(entry.mText, GetWLMenuSceneScanSlotPick()->mSlotTexts[otherSlotIndex].mText, 0xb) ==
                            0) {
                            isNewEntry = FALSE;
                        }
                    }
                    if (isNewEntry != FALSE) {
                        NNS_SndArcSetCurrent(&gOnMemorySndArc);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
                        NNS_SndArcSetCurrent(&gFileSndArc);
                    }
                } else if (oldHasText != 0 && gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText == 0) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
                changed |= oldHasText != gMultiSelectMemberGroup->mMemberRows[slotIndex].mHasText ? 1 : 0;
                changed |= oldWord8 != gMultiSelectMemberGroup->mMemberRows[slotIndex].mChildCount ? 1 : 0;
                changed |= oldWord4 != gMultiSelectMemberGroup->mMemberRows[slotIndex].mIsMultiBoot ? 1 : 0;
            }
            if (changed != 0) {
                RefreshMultiSelectMemberGroup(1);
            }
            return;
        case MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_CONNECTION_END_ON_LEAVE:
        case MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_CONNECTION_END_ALT:
            if (AdvanceConnectionEndStopOnError() == 1) {
                gMultiSelectMemberGroup->mUpdateState = MULTI_SELECT_MEMBER_GROUP_UPDATE_DONE;
            }
            return;
    }
}

void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    u32 subObjSizeLeft;
    CellFileSet *cellFileSet;
    s32 rowIndex;
    const LabelMessageRow *labelMessageRow;
    void *text;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectMemberGroup = HeapAlloc(heap, sizeof(*gMultiSelectMemberGroup));
    MemFillWordsByBlock_inline(gMultiSelectMemberGroup, 0xa8);
    gMultiSelectMemberGroup->mHeap = heap;
    gMultiSelectMemberGroup->mScene = scene;
    gMultiSelectMemberGroup->mOamList = oamList;
    gMultiSelectMemberGroup->mBannerMessages = FindSceneFile("banner.bmg");
    gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_IN;
    gMultiSelectMemberGroup->mBg3Offset = -0xc0;
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_SUB, gMultiSelectMemberGroup, "multi_select_member_s_b.NCGR",
                                   "multi_select_member_s_b.NCLR", "multi_select_member_s_group.NSCR", 3,
                                   FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    LocateCellFileSet(cellFileSet, "multi_select_member_group_s.nce.ncgr", "multi_select_member_group_s.nce.ncer",
                      "multi_select_member_group_s_o.NCLR", "multi_select_member_s_group.bncl",
                      "multi_select_member_s_group.bnll", "multi_select_member_s_group.bnbl", FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gMultiSelectMemberGroup->mHeap, cellFileSet);
    for (rowIndex = 0, labelMessageRow = gMemberGroupLabelMessageRows; rowIndex < 5; labelMessageRow++, rowIndex++) {
        subObjSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_SUB, gMultiSelectMemberGroup->mHeap, cellFileSet,
                                           labelMessageRow, subObjSizeLeft);
        if (gMemberGroupLabelMessageRows[rowIndex].mMessageIndex < 0) {
            text = "";
        } else {
            text = GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages,
                               gMemberGroupLabelMessageRows[rowIndex].mMessageIndex);
        }
        PrintLabelLayoutTextNoFixedAdvance(1, gMemberGroupLabelMessageRows[rowIndex].mLabelIndex,
                                           cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                           cellFileSet->mCellTable);
    }
    RefreshMultiSelectMemberGroup(1);
    SetSelectReturnSoundId(0xf);
    gStartupWork->mConnectionKind = CONNECTION_KIND_WL_MENU;
    FrmHeapShrinkInParent(gMultiSelectMemberGroup->mHeap);
}

s32 AdvanceMultiSelectMemberGroup(SceneNumbers *sceneNumbers) {
    CellFileSet *cellFileSet;
    s32 result;
    u16 slotIndex;
    s32 rowIndex;
    s32 touchInReturnRect;
    s32 rectIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 value;
    s32 pairX;
    s32 pairY;
    s32 selectionChanged;

    result = -1;
    slotIndex = GetPadInputSlot();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    if (gMultiSelectMemberGroup->mEntriesCleared == FALSE) {
        gMultiSelectMemberGroup->mEntriesClearFrames++;
        if (gMultiSelectMemberGroup->mEntriesClearFrames > MULTI_SELECT_MEMBER_GROUP_CLEAR_FRAMES) {
            for (rowIndex = 0; rowIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT; rowIndex++) {
                MultiSelectMI_CpuClear16(&GetWLMenuSceneScanSlotPick()->mSlotTexts[rowIndex], 0x16);
            }
            gMultiSelectMemberGroup->mEntriesCleared = TRUE;
        }
    }
    if (gMultiSelectMemberGroup->mState != MULTI_SELECT_MEMBER_GROUP_STATE_NONE) {
        UpdateMemberRowsFromScanSlots();
    }
    switch (gMultiSelectMemberGroup->mState) {
        case MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_IN:
            if (AreBrightnessFadesClear() == 0) {
                break;
            }
            if (gMultiSelectMemberGroup->mBg3OffsetFrames == 0) {
                RequestSelectReturnSlideIn();
                SetupTxtSystemMainTextEx(GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 7), 0, 0, 1, 0, 0, 0);
            }
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < MULTI_SELECT_MEMBER_GROUP_SLIDE_FRAMES) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, -0xc0, 0, gMultiSelectMemberGroup->mBg3OffsetFrames,
                                   MULTI_SELECT_MEMBER_GROUP_SLIDE_FRAMES);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_CHOOSE;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case MULTI_SELECT_MEMBER_GROUP_STATE_CHOOSE:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            value = gInputSlots[slotIndex].mPair.mHasPair;
            if (value == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && value != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                pairX = gInputSlots[slotIndex].mPair.mPairX;
                pairY = gInputSlots[slotIndex].mPair.mPairY;
                touchInReturnRect = IsSelectReturnShownNoRequestAndInRect(pairX, pairY);
                rectIndex = RectTableFindContaining(cellFileSet->mRects, pairX, pairY);
            }
            value = gInputSlots[slotIndex].mPressedBits;
            if ((u16) (value & PAD_KEY_A) != 0) {
                if (IsSelectedMemberRowSelectable() != 0) {
                    gMultiSelectMemberGroup->mRowPressed = TRUE;
                    gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_PRESS_WAIT;
                    gMultiSelectMemberGroup->mPressWaitFrames = 0;
                    RefreshMultiSelectMemberGroup(0);
                    if (gMultiSelectMemberGroup->mSelectedIndex == MULTI_SELECT_MEMBER_GROUP_NS_ROW) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4e);
                    } else {
                        if ((gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) ==
                            CONNECTION_MODE_CHILD) {
                            gConnectionWork->mOperationFlags |= CONNECTION_OPERATION_SCANNING;
                        }
                        NNS_SndArcSetCurrent(&gOnMemorySndArc);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
                        NNS_SndArcSetCurrent(&gFileSndArc);
                    }
                } else {
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4f);
                }
            } else if ((u16) (value & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_OUT;
                RequestSelectReturnPressWithSound(1);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DIRECTION_UP) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex--;
                if (gMultiSelectMemberGroup->mSelectedIndex < 0) {
                    gMultiSelectMemberGroup->mSelectedIndex = MULTI_SELECT_MEMBER_GROUP_NS_ROW;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DIRECTION_DOWN) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex++;
                if (gMultiSelectMemberGroup->mSelectedIndex > MULTI_SELECT_MEMBER_GROUP_NS_ROW) {
                    gMultiSelectMemberGroup->mSelectedIndex = 0;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            } else if (rectIndex == 0xc) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4e);
                RefreshMultiSelectMemberGroup(
                    gMultiSelectMemberGroup->mSelectedIndex != MULTI_SELECT_MEMBER_GROUP_NS_ROW ? 1 : 0);
                gMultiSelectMemberGroup->mPressWaitFrames = 0;
                gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_PRESS_WAIT;
                gMultiSelectMemberGroup->mSelectedIndex = MULTI_SELECT_MEMBER_GROUP_NS_ROW;
                gMultiSelectMemberGroup->mRowPressed = TRUE;
            } else {
                for (rowIndex = 0; rowIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT; rowIndex++) {
                    if (IsRectInMemberRow(rectIndex, rowIndex) != 0) {
                        selectionChanged = gMultiSelectMemberGroup->mSelectedIndex != rowIndex ? 1 : 0;
                        if (gMultiSelectMemberGroup->mMemberRows[rowIndex].mHasText != 0 &&
                            gMultiSelectMemberGroup->mMemberRows[rowIndex].mChildCount < 7) {
                            NNS_SndArcSetCurrent(&gOnMemorySndArc);
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
                            NNS_SndArcSetCurrent(&gFileSndArc);
                            gMultiSelectMemberGroup->mSelectedIndex = rowIndex;
                            RefreshMultiSelectMemberGroup(selectionChanged);
                            gMultiSelectMemberGroup->mPressWaitFrames = 0;
                            gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_PRESS_WAIT;
                            gMultiSelectMemberGroup->mRowPressed = TRUE;
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case MULTI_SELECT_MEMBER_GROUP_STATE_PRESS_WAIT:
            gMultiSelectMemberGroup->mPressWaitFrames++;
            if (gMultiSelectMemberGroup->mPressWaitFrames >= MULTI_SELECT_MEMBER_GROUP_PRESS_FRAMES) {
                gMultiSelectMemberGroup->mPressWaitFrames = 0;
                RefreshMultiSelectMemberGroup(1);
                if (gMultiSelectMemberGroup->mSelectedIndex < MULTI_SELECT_MEMBER_GROUP_ROW_COUNT &&
                    gMultiSelectMemberGroup->mMemberRows[gMultiSelectMemberGroup->mSelectedIndex].mHasText == 0) {
                    gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_CHOOSE;
                } else {
                    gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_OUT;
                    RequestTxtSystemClose();
                }
            }
            break;
        case MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_OUT:
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < MULTI_SELECT_MEMBER_GROUP_SLIDE_FRAMES) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, 0, -0xc0, gMultiSelectMemberGroup->mBg3OffsetFrames,
                                   MULTI_SELECT_MEMBER_GROUP_SLIDE_FRAMES);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = MULTI_SELECT_MEMBER_GROUP_STATE_DONE;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case MULTI_SELECT_MEMBER_GROUP_STATE_DONE:
            if (gMultiSelectMemberGroup->mUpdateState == MULTI_SELECT_MEMBER_GROUP_UPDATE_DONE) {
                result = gMultiSelectMemberGroup->mNextCallbacksIndex;
            }
            break;
    }
    if (gMultiSelectMemberGroup->mState != MULTI_SELECT_MEMBER_GROUP_STATE_DONE) {
        DrawLayoutTable(cellFileSet->mCellLayout, cellFileSet->mCells, cellFileSet->mLabelLayout,
                        gMultiSelectMemberGroup->mOamList, cellFileSet->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMemberGroup(void) {
    HeapDestroy(gMultiSelectMemberGroup->mHeap);
    *&gMultiSelectMemberGroup = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteMultiSelectMemberGroupRegisters(void) {
    u32 displayBits = 0x16;
    s32 windowEndY;

    if (gMultiSelectMemberGroup->mState != MULTI_SELECT_MEMBER_GROUP_STATE_DONE) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-gMultiSelectMemberGroup->mBg3Offset << 16) & 0x1ff0000;
    if (gMultiSelectMemberGroup->mBg3Offset != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT &
                              ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
                             REG_GXS_DB_DISPCNT_W0_MASK;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | 7) | 0x20;
        windowEndY = gMultiSelectMemberGroup->mBg3Offset + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = windowEndY & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT &
                             ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
    }
}

#pragma thumb off
