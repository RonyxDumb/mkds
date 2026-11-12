#include "Main/Menu/multi_select_member_group.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Menu/multi_select_ns_registers.h"

#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "code_02148950.h"
#include "Main/Menu/data_02163000.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Menu/data_0217d068.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Menu/multi_select_ns_input.h"

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
    if (selectedIndex != 4) {
        memberChecksPass = FALSE;
        if (gMultiSelectMemberGroup->mUnk_58[selectedIndex].mHasText != 0 &&
            gMultiSelectMemberGroup->mUnk_58[selectedIndex].mChildCount < 7) {
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
    entryCount = *OFFSET_PTR(u16, cellFileSet->mCellLayout, 6) + *OFFSET_PTR(u16, cellFileSet->mLabelLayout, 6);
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
    MemberRowCellIndices *rowCellIndices;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    valueTable = data_021634a8;
    rowIndex = 0;
    entryOffset = 0;
    rowCellIndices = gMemberRowCellIndices;
    do {
        rowSelected = 0;
        if (gMultiSelectMemberGroup->mSelectedIndex == rowIndex && showSelected != 0) {
            rowSelected = 1;
        }
        rowFlag = *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x58);
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
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[13]].mVisible &=
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
            visibleFlag = TRUE;
        } else {
            visibleFlag = FALSE;
        }
        cellFileSet->mCellTable[rowCellIndices->mCellIndices[2]].mVisible &= visibleFlag;
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
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
        rowCellIndices = OFFSET_PTR(MemberRowCellIndices, rowCellIndices, 0x32);
        rowIndex++;
    } while (rowIndex < 4);
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
        case 0:
            if (AdvanceSetupByMultiBoot(0, 0) == 1) {
                gMultiSelectMemberGroup->mUpdateState = 1;
            }
            return;
        case 1:
            if (gMultiSelectMemberGroup->mUnk_88 != FALSE) {
                if (gMultiSelectMemberGroup->mSelectedIndex < 4) {
                    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
                        if (TryGetScanSlotName(slotIndex, &GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex]) != 0) {
                            GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex].mTerminator = 0;
                        } else {
                            MultiSelectMI_CpuClear16(&GetWLMenuSceneScanSlotPick()->mSlotTexts[slotIndex], 0x16);
                        }
                    }
                    if (TryGetScanSlotName(gMultiSelectMemberGroup->mSelectedIndex, NULL) != 0) {
                        GetWLMenuSceneScanSlotPick()->mSlotIndex = gMultiSelectMemberGroup->mSelectedIndex;
                        gMultiSelectMemberGroup->mNextCallbacksIndex = 3;
                        gMultiSelectMemberGroup->mUpdateState = 0xb;
                        return;
                    }
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mSelectedIndex].mHasText = 0;
                    return;
                }
                gMultiSelectMemberGroup->mNextCallbacksIndex = 1;
                gMultiSelectMemberGroup->mUpdateState = 5;
                return;
            }
            if (gMultiSelectMemberGroup->mState != 1) {
                return;
            }
            for (slotIndex = 0; slotIndex < 4; slotIndex++) {
                oldHasText = gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText;
                oldWord8 = gMultiSelectMemberGroup->mUnk_58[slotIndex].mChildCount;
                oldWord4 = gMultiSelectMemberGroup->mUnk_58[slotIndex].mIsMultiBoot;
                MultiSelectMI_CpuClear16(&entry, 0x16);
                gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText = TryGetScanSlotName(slotIndex, &entry);
                if (gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText != 0) {
                    entry.mTerminator = 0;
                    PrintLabelLayoutTextNoFixedAdvance(1, gMemberRowCellIndices[slotIndex].mLabelIndex,
                                                       cellFileSet->mLabelLayout, &entry, cellFileSet->mCellLayout,
                                                       cellFileSet->mCellTable);
                    gMultiSelectMemberGroup->mUnk_58[slotIndex].mChildCount = GetScanSlotChildCount(slotIndex);
                    gMultiSelectMemberGroup->mUnk_58[slotIndex].mIsMultiBoot = IsScanSlotMultiBoot(slotIndex);
                } else {
                    PrintLabelLayoutTextNoFixedAdvance(1, gMemberRowCellIndices[slotIndex].mLabelIndex,
                                                       cellFileSet->mLabelLayout,
                                                       GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 8),
                                                       cellFileSet->mCellLayout, cellFileSet->mCellTable);
                    gMultiSelectMemberGroup->mUnk_58[slotIndex].mChildCount = 0;
                    gMultiSelectMemberGroup->mUnk_58[slotIndex].mIsMultiBoot = 0;
                }
                if (oldHasText == 0 && gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText != 0) {
                    isNewEntry = TRUE;
                    for (otherSlotIndex = 0; otherSlotIndex < 4; otherSlotIndex++) {
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
                } else if (oldHasText != 0 && gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText == 0) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
                changed |= oldHasText != gMultiSelectMemberGroup->mUnk_58[slotIndex].mHasText ? 1 : 0;
                changed |= oldWord8 != gMultiSelectMemberGroup->mUnk_58[slotIndex].mChildCount ? 1 : 0;
                changed |= oldWord4 != gMultiSelectMemberGroup->mUnk_58[slotIndex].mIsMultiBoot ? 1 : 0;
            }
            if (changed != 0) {
                RefreshMultiSelectMemberGroup(1);
            }
            return;
        case 5:
        case 8:
            if (AdvanceConnectionEndStopOnError() == 1) {
                gMultiSelectMemberGroup->mUpdateState = 0xb;
            }
            return;
    }
}

void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    u32 subObjSizeLeft;
    CellFileSet *cellFileSet;
    s32 rowIndex;
    LabelMessageRow *labelMessageRow;
    void *text;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectMemberGroup = HeapAlloc(heap, 0xa8);
    MemFillWordsByBlock_inline(gMultiSelectMemberGroup, 0xa8);
    gMultiSelectMemberGroup->mHeap = heap;
    gMultiSelectMemberGroup->mUnk_40 = scene;
    gMultiSelectMemberGroup->mOamList = oamList;
    gMultiSelectMemberGroup->mBannerMessages = FindSceneFile(gBannerBmgName);
    gMultiSelectMemberGroup->mState = 0;
    gMultiSelectMemberGroup->mBg3Offset = -0xc0;
    LocateAndQueueScreenMapFileSet(1, gMultiSelectMemberGroup, gMultiSelectMemberSBNcgrName2,
                                   gMultiSelectMemberSBNclrName2, gMultiSelectMemberSGroupNscrName2, 3, FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    LocateCellFileSet(cellFileSet, gMultiSelectMemberGroupSNcgrName2, gMultiSelectMemberGroupSNcerName2,
                      gMultiSelectMemberGroupSONclrName2, gMultiSelectMemberSGroupBnclName,
                      gMultiSelectMemberSGroupBnllName, gMultiSelectMemberSGroupBnblName, FindSceneFile);
    SetupCellFileSet(1, gMultiSelectMemberGroup->mHeap, cellFileSet);
    for (rowIndex = 0, labelMessageRow = gMemberGroupLabelMessageRows; rowIndex < 5; labelMessageRow++, rowIndex++) {
        subObjSizeLeft -=
            SetupLabelCanvas(1, gMultiSelectMemberGroup->mHeap, cellFileSet, labelMessageRow, subObjSizeLeft);
        if (gMemberGroupLabelMessageRows[rowIndex].mMessageIndex < 0) {
            text = data_02163610;
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
    gStartupWork->mConnectionKind = 2;
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
        if (gMultiSelectMemberGroup->mEntriesClearFrames > 0x78) {
            for (rowIndex = 0; rowIndex < 4; rowIndex++) {
                MultiSelectMI_CpuClear16(&GetWLMenuSceneScanSlotPick()->mSlotTexts[rowIndex], 0x16);
            }
            gMultiSelectMemberGroup->mEntriesCleared = TRUE;
        }
    }
    if (gMultiSelectMemberGroup->mState != -1) {
        UpdateMemberRowsFromScanSlots();
    }
    switch (gMultiSelectMemberGroup->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                break;
            }
            if (gMultiSelectMemberGroup->mBg3OffsetFrames == 0) {
                RequestSelectReturnState1();
                SetupTxtSystemMainTextEx(GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 7), 0, 0, 1, 0, 0, 0);
            }
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, -0xc0, 0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 1;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 1:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            value = gInputSlots[slotIndex].mPair.mHasPair;
            if (value == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && value != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                pairX = gInputSlots[slotIndex].mPair.mPairX;
                pairY = gInputSlots[slotIndex].mPair.mPairY;
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, pairY);
                rectIndex = RectTableFindContaining(cellFileSet->mRects, pairX, pairY);
            }
            value = gInputSlots[slotIndex].mPressedBits;
            if ((u16) (value & PAD_KEY_A) != 0) {
                if (IsSelectedMemberRowSelectable() != 0) {
                    gMultiSelectMemberGroup->mUnk_88 = TRUE;
                    gMultiSelectMemberGroup->mState = 2;
                    gMultiSelectMemberGroup->mState2Frames = 0;
                    RefreshMultiSelectMemberGroup(0);
                    if (gMultiSelectMemberGroup->mSelectedIndex == 4) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4e);
                    } else {
                        if ((gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) == 2) {
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
                gMultiSelectMemberGroup->mState = 3;
                RequestSelectReturnState3WithSound(1);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex--;
                if (gMultiSelectMemberGroup->mSelectedIndex < 0) {
                    gMultiSelectMemberGroup->mSelectedIndex = 4;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex++;
                if (gMultiSelectMemberGroup->mSelectedIndex > 4) {
                    gMultiSelectMemberGroup->mSelectedIndex = 0;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
            } else if (rectIndex == 0xc) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4e);
                RefreshMultiSelectMemberGroup(gMultiSelectMemberGroup->mSelectedIndex != 4 ? 1 : 0);
                gMultiSelectMemberGroup->mState2Frames = 0;
                gMultiSelectMemberGroup->mState = 2;
                gMultiSelectMemberGroup->mSelectedIndex = 4;
                gMultiSelectMemberGroup->mUnk_88 = TRUE;
            } else {
                for (rowIndex = 0; rowIndex < 4; rowIndex++) {
                    if (IsRectInMemberRow(rectIndex, rowIndex) != 0) {
                        selectionChanged = gMultiSelectMemberGroup->mSelectedIndex != rowIndex ? 1 : 0;
                        if (gMultiSelectMemberGroup->mUnk_58[rowIndex].mHasText != 0 &&
                            gMultiSelectMemberGroup->mUnk_58[rowIndex].mChildCount < 7) {
                            NNS_SndArcSetCurrent(&gOnMemorySndArc);
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
                            NNS_SndArcSetCurrent(&gFileSndArc);
                            gMultiSelectMemberGroup->mSelectedIndex = rowIndex;
                            RefreshMultiSelectMemberGroup(selectionChanged);
                            gMultiSelectMemberGroup->mState2Frames = 0;
                            gMultiSelectMemberGroup->mState = 2;
                            gMultiSelectMemberGroup->mUnk_88 = TRUE;
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case 2:
            gMultiSelectMemberGroup->mState2Frames++;
            if (gMultiSelectMemberGroup->mState2Frames >= 5) {
                gMultiSelectMemberGroup->mState2Frames = 0;
                RefreshMultiSelectMemberGroup(1);
                if (gMultiSelectMemberGroup->mSelectedIndex < 4 &&
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mSelectedIndex].mHasText == 0) {
                    gMultiSelectMemberGroup->mState = 1;
                } else {
                    gMultiSelectMemberGroup->mState = 3;
                    RequestTxtSystemClose();
                }
            }
            break;
        case 3:
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, 0, -0xc0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 4;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 4:
            if (gMultiSelectMemberGroup->mUpdateState == 0xb) {
                result = gMultiSelectMemberGroup->mNextCallbacksIndex;
            }
            break;
    }
    if (gMultiSelectMemberGroup->mState != 4) {
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

    if (gMultiSelectMemberGroup->mState != 4) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-gMultiSelectMemberGroup->mBg3Offset << 16) & 0x1ff0000;
    if (gMultiSelectMemberGroup->mBg3Offset != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        windowEndY = gMultiSelectMemberGroup->mBg3Offset + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = windowEndY & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
