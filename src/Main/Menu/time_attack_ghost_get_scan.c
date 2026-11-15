#include "Main/Menu/time_attack_ghost_get_scan.h"
#include "Main/Race/results_battle_registers.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Race/ghost_list.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/Menu/scroll_list_state.h"
#include "Main/System/heap.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/led_pattern.h"
#include "Main/Save/ghost_record.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Menu/select_return.h"
#include "code_02148950.h"
#include "Main/Race/data_02164000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217c000.h"
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
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0214cfe4.h"
#include "Main/Graphics/message_index.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_0214d018.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/select_character.h"
#include "Main/Graphics/minute_second_millisecond_text.h"
#include "registers.h"
#include "Main/Net/pending_files.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/scan_selected_entry.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Menu/time_attack_ghost_get_names_b.h"
#include "Main/Menu/time_attack_ghost_get_names_a.h"
#include "Main/Menu/time_attack_ghost_get_names_d.h"
#include "Main/Menu/time_attack_ghost_get_names_e.h"
#include "Main/Menu/time_attack_ghost_get_names_c.h"
#include "Main/Menu/time_attack_ghost_get_names_f.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"
#include "Main/Menu/time_attack_ghost_get_slot_data.h"
#include "Main/Menu/time_attack_ghost_get_names_g.h"

#pragma thumb on

s16 gTimeAttackGhostGetScanSSelLabelTextRows[8][4] = {{0, 0x64, 0xd, 0},  {1, 0x64, 0xd, 1},  {2, 0x64, 0xd, 2},
                                                      {3, 0x64, 0xd, 3},  {4, 0x86, 0xd, -1}, {5, 0x86, 0xd, -1},
                                                      {6, 0x86, 0xd, -1}, {7, 0x86, 0xd, -1}};
const s16 gTimeAttackGhostGetScanMLabelTextRows[3][4] = {{0, 0xdc, 0x10, 0}, {1, 0x50, 0xc, 1}, {2, 0x82, 0x10, 2}};
const s16 gTimeAttackGhostGetSlotMLabelTextRows[3][4] = {{0, 0xdc, 0x10, 0}, {1, 0x50, 0xc, 1}, {2, 0x82, 0x10, 2}};
GhostSceneCallbacks gTimeAttackGhostGetScanCallbacks = {InitTimeAttackGhostGetScan, AdvanceTimeAttackGhostGetScan,
                                                        ReleaseTimeAttackGhostGetScan, WriteGhostGetScanRegisters};
TimeAttackGhostGetSlot *gTimeAttackGhostGetSlot;
TimeAttackGhostGetScan *gTimeAttackGhostGetScan;
struct WLMenuMessage *gWLMenuMessage;

void RefreshSlotGhostListRows(s32 action, s32 slot, s32 listIndex, s32 selectedSlot) {
    CellFileSet *subCellFileSet;
    s32 rowIndex;
    s32 paletteIndex;
    s32 timeLabelIndex;
    MinuteSecondMillisecondTime time;
    s16 timeText[12];

    subCellFileSet = &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[1];
    if (action == 1) {
        listIndex += GetCourseGhostCount();
        PrintLabelLayoutTextNoFixedAdvance(1, slot, subCellFileSet->mLabelLayout,
                                           GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages,
                                                       GetGhostCourseMessageIndex(GetListedGhostCourseId(listIndex))),
                                           subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
        GetListedGhostTime(listIndex, &time);
        WriteMinuteSecondMillisecondText(timeText, time.mMinute, time.mSecond, time.mMillisecond);
        PrintLabelLayoutTextFixedDigits(1, slot + 7, subCellFileSet->mLabelLayout, timeText,
                                        subCellFileSet->mCellLayout, subCellFileSet->mCellTable, 7);
    } else if (action == 0) {
        for (rowIndex = 0; rowIndex < 7; rowIndex++) {
            timeLabelIndex = rowIndex + 7;
            if (rowIndex == selectedSlot) {
                paletteIndex = 14;
            } else {
                paletteIndex = 15;
            }
            SetLabelPaletteIndex(rowIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
            SetLabelPaletteIndex(timeLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupGhostMainTextEx(void) {
    void *message;
    message = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 3);
    SetTxtSystemBgOffsetRequested(0xfffffff4, 0);
    SetupTxtSystemMainTextEx(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

static inline s32 GhostGetSlotIsBackupCommandRunning(void) {
    BackupAccess *backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        return backupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 GhostGetSlotIsBackupBusy(void) {
    if (gBackupBuffers->mBusy == 0) {
        return GhostGetSlotIsBackupCommandRunning();
    }
    return 1;
}

void SetupGhostNameSubTextTwoButtons(void) {
    void *formatText;
    void *firstButtonText;
    void *secondButtonText;
    u8 ghostName[0x14];
    u16 nameText[11];
    u16 formattedText[0x100];

    formatText = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 0x12);
    firstButtonText = GetBmgEntry(gTimeAttackGhostGetSlot->mInfoFileSets.mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gTimeAttackGhostGetSlot->mInfoFileSets.mCommonMessages, 1);
    GetListedGhostName(gTimeAttackGhostGetSlot->mInfoFileSets.mSelectedIndex + GetCourseGhostCount(), ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    FormatMessageWithText(nameText, formatText, formattedText, 0x100);
    SetTxtSystemSoundId(0, -1);
    SetupTxtSystemSubTextTwoButtonsEx(formattedText, firstButtonText, secondButtonText, 1, 0, 1, 1, 0);
}

void UpdateSlotSlideOffsets(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 entryIndex;
    s16 offset;

    mainCellFileSet = &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[0];
    subCellFileSet = &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mCount + mainCellFileSet->mLabelLayout->mCount;
    subEntryCount = subCellFileSet->mCellLayout->mCount + subCellFileSet->mLabelLayout->mCount;
    offset = GetInterpolatedValue(&gTimeAttackGhostGetSlot->mInterpolation);
    for (entryIndex = 0; entryIndex < mainEntryCount; entryIndex++) {
        mainCellFileSet->mCellTable[entryIndex].mOffsetY = -offset;
    }
    for (entryIndex = 0; entryIndex < subEntryCount; entryIndex++) {
        subCellFileSet->mCellTable[entryIndex].mOffsetY = offset;
    }
}

void PrintSelectedGhostRecord(void) {
    s32 listIndex;
    u32 characterIndex;
    u32 kartIndex;
    u32 courseId;
    MinuteSecondMillisecondTime time;
    u8 ghostName[0x14];
    u16 nameText[11];

    listIndex = GetCourseGhostCount() + gTimeAttackGhostGetSlot->mInfoFileSets.mSelectedIndex;
    GetListedGhostTime(listIndex, &time);
    GetListedGhostName(listIndex, ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(listIndex);
    kartIndex = GetListedGhostKartIndex(listIndex);
    courseId = GetListedGhostCourseId(listIndex);
    PrintGhostRecordInfo(&gTimeAttackGhostGetSlot->mInfoFileSets, gTimeAttackGhostGetSlotMLabelTextRows, nameText,
                         characterIndex, kartIndex, courseId, &time);
}

void InitTimeAttackGhostGetSlot(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    s32 entryIndex;
    u32 remainingObjSize;
    s32 textRowIndex;
    s32 assignedCount;
    s32 cellCount;
    s32 cellIndex;
    s32 labelIndex;
    s32 secondLabelIndex;
    s16 *row;
    LayoutTableEntry *cellTable;
    u16 groupFirstEntries[3];

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostGetSlot = HeapAlloc(heap, sizeof(*gTimeAttackGhostGetSlot));
    MemFillWordsByBlock_inline(gTimeAttackGhostGetSlot, 0xa8);
    gTimeAttackGhostGetSlot->mHeap = heap;
    gTimeAttackGhostGetSlot->mOamLists[0] = mainOam;
    gTimeAttackGhostGetSlot->mOamLists[1] = subOam;
    gTimeAttackGhostGetSlot->mInfoFileSets.mCommonMessages = FindFileInLoadedArchives(gTimeAttackGhostGetCommonBmgName);
    gTimeAttackGhostGetSlot->mGhostMessages = FindSceneFile(gTimeAttackGhostGetGhostBmgName);
    cellFileSet = &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    LocateCellFileSet(cellFileSet, gTimeAttackGhostGetMNceNcgrName, gTimeAttackGhostGetMNceNcerName,
                      gTimeAttackGhostGetMONclrName, gTimeAttackGhostGetMBnclName, gTimeAttackGhostGetMBnllName, NULL,
                      FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_MAIN, gTimeAttackGhostGetSlot->mHeap, cellFileSet);
    for (entryIndex = 0; entryIndex < cellFileSet->mLabelLayout->mCount; entryIndex++) {
        remainingObjSize -= SetupLabelCanvas(SCREEN_SIDE_MAIN, gTimeAttackGhostGetSlot->mHeap, cellFileSet,
                                             gTimeAttackGhostGetSlotMLabelTextRows[entryIndex], remainingObjSize);
    }
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_SUB, gTimeAttackGhostGetSlot, gTimeAttackGhostGetSBNcgrName,
                                   gTimeAttackGhostGetSBNclrName, gTimeAttackGhostGetSNscrName, 3, FindSceneFile);
    cellFileSet = &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(cellFileSet, gTimeAttackGhostGetSNceNcgrName, gTimeAttackGhostGetSNceNcerName,
                      gTimeAttackGhostGetSONclrName, gTimeAttackGhostGetSBnclName, gTimeAttackGhostGetSBnllName,
                      gTimeAttackGhostGetSBnblName, FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gTimeAttackGhostGetSlot->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mCount;
    textRowIndex = 0;
    if (textRowIndex < cellFileSet->mLabelLayout->mCount) {
        row = gTimeAttackGhostGetSlotSLabelTextRows[0];
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= SetupLabelCanvas(SCREEN_SIDE_SUB, gTimeAttackGhostGetSlot->mHeap, cellFileSet,
                                                 gTimeAttackGhostGetSlotSLabelTextRows[textRowIndex], remainingObjSize);
            row += 4;
            textRowIndex++;
        } while (textRowIndex < cellFileSet->mLabelLayout->mCount);
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        SetCellPriority(entryIndex, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    for (textRowIndex = 0, row = gTimeAttackGhostGetSlotSLabelTextRows[0]; textRowIndex < 7; textRowIndex++) {
        cellIndex = row[3];
        labelIndex = row[0];
        secondLabelIndex = gTimeAttackGhostGetSlotSLabelTextRows[textRowIndex + 7][0];
        cellTable = cellFileSet->mCellTable;
        SetLayoutEntryPositionFromCell(cellIndex, &cellTable[cellIndex], cellFileSet->mCellLayout);
        SetLayoutEntryPositionFromLabel(labelIndex, &cellTable[labelIndex] + cellCount, cellFileSet->mLabelLayout);
        SetLayoutEntryPositionFromLabel(secondLabelIndex, &cellTable[secondLabelIndex] + cellCount,
                                        cellFileSet->mLabelLayout);
        row += 4;
    }
    SetLayoutEntryPositionFromCell(7, &cellFileSet->mCellTable[7], cellFileSet->mCellLayout);
    groupFirstEntries[0] = 0;
    groupFirstEntries[1] = cellCount;
    groupFirstEntries[2] = cellCount + 7;
    InitScrollList(gTimeAttackGhostGetSlot->mHeap, 3, groupFirstEntries, 7, 8, 0x7c, cellFileSet->mCellTable,
                   cellFileSet->mRects, gTimeAttackGhostGetSlot->mScreenMapFileSet.mScreenMaps[3]->mData, 0, 1, 2, 10,
                   RefreshSlotGhostListRows);
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets[2]);
    PrintSelectedGhostRecord();
    SetupInterpolation(&gTimeAttackGhostGetSlot->mInterpolation, 0, 10, -0xc0, 0);
    RequestSelectReturnSlideIn();
    SetSelectReturnSoundId(0xf);
    SetupGhostMainTextEx();
    FrmHeapShrinkInParent(gTimeAttackGhostGetSlot->mHeap);
}

s32 AdvanceTimeAttackGhostGetSlot(u16 *sceneNumbers) {
    TimeAttackGhostGetSlot *object;
    enum { RESULT_NONE = -1 } result;
    s32 touchInReturnRect;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    s32 index;
    u16 slotIndex;
    u16 hasPair;
    void *message;
    CellFileSet *cellFileSets;
    void *buttonText;

    result = RESULT_NONE;
    slotIndex = GetPadInputSlot();
    touchInReturnRect = 0;
    AdvanceInterpolation(&gTimeAttackGhostGetSlot->mInterpolation);
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
        touchInReturnRect = IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                  gInputSlots[slotIndex].mPair.mPairY);
    }
    object = gTimeAttackGhostGetSlot;
    switch (object->mState) {
        case TIME_ATTACK_GHOST_GET_SLOT_STATE_SLIDE_IN:
            if (object->mInterpolation.mState == 1) {
                object->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_CHOOSE_SLOT;
            } else {
                UpdateSlotSlideOffsets();
            }
            break;
        case TIME_ATTACK_GHOST_GET_SLOT_STATE_CHOOSE_SLOT:
            if (IsTxtSystemClosedNoOpenRequest() != 0) {
                SetupGhostMainTextEx();
            }
            AdvanceScrollList();
            index = GetScrollListSelectedRow();
            if (gTimeAttackGhostGetSlot->mInfoFileSets.mSelectedIndex != index) {
                gTimeAttackGhostGetSlot->mInfoFileSets.mSelectedIndex = index;
                PrintSelectedGhostRecord();
            }
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
            }
            if (IsScrollListPickFinished() != 0) {
                SetupGhostNameSubTextTwoButtons();
                RequestSelectReturnSlideOut();
                gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_SAVE_ANSWER;
            } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 0x54);
                buttonText = GetBmgEntry(gTimeAttackGhostGetSlot->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                RequestSelectReturnPressWithSound(1);
                gTimeAttackGhostGetSlot->mUnk_a0 = FALSE;
                gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_MESSAGE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_SAVE_ANSWER:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    GetSlotGhostBuffer()->mHead.mFilled = 1;
                    WriteSlotGhostRecord((u8) gTimeAttackGhostGetSlot->mInfoFileSets.mSelectedIndex,
                                         GetSlotGhostBuffer());
                    gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_BACKUP;
                } else {
                    RequestSelectReturnSlideIn();
                    gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_CHOOSE_SLOT;
                }
                RequestTxtSystemClose();
            }
            break;
        case TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_BACKUP:
            if (GhostGetSlotIsBackupBusy() != 0) {
                message = GetBmgEntry(object->mGhostMessages, 0x10);
                buttonText = GetBmgEntry(gTimeAttackGhostGetSlot->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetSlot->mUnk_a0 = FALSE;
                gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_MESSAGE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_MESSAGE_DONE:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers[2] = 1;
                }
                gTimeAttackGhostGetSlot->mState = TIME_ATTACK_GHOST_GET_SLOT_STATE_DONE;
            }
            break;
    }
    for (index = 0; index < 2; index++) {
        cellFileSets = gTimeAttackGhostGetSlot->mInfoFileSets.mCellFileSets;
        DrawLayoutTable(cellFileSets[index].mCellLayout, cellFileSets[index].mCells, cellFileSets[index].mLabelLayout,
                        gTimeAttackGhostGetSlot->mOamLists[index], cellFileSets[index].mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostGetSlot(void) {
    HeapDestroy(gTimeAttackGhostGetSlot->mHeap);
    gTimeAttackGhostGetSlot = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteGhostGetSlotRegisters(void) {
    s32 offset;
    s32 negatedOffset;

    offset = GetInterpolatedValue(&gTimeAttackGhostGetSlot->mInterpolation);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    if (offset != 0) {
        reg_GX_DISPCNT =
            (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
            REG_GX_DISPCNT_W0_MASK;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT &
                              ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
                             REG_GXS_DB_DISPCNT_W0_MASK;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT &
                             ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
    }
}

void StartTimeAttackGhostGetScanWaitErrorMessage(void) {
    void *message;
    void *buttonText;

    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x11);
    buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 4);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextButton(message, buttonText);
    gTimeAttackGhostGetScan->mStateFrames = 0;
    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_ERROR_MESSAGE;
}

#pragma thumb off

#pragma thumb on

void SetupGhostMainTextShort(void) {
    void *message;
    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 1);
    SetupTxtSystemMainTextShort(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

// Selects the previous filled entry whose counter has run up to its end; a nonzero argument wraps from the first entry
// to the last.
void MoveSelectedGhostUp(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    TimeAttackGhostGetScan *object;

    found = FALSE;
    object = gTimeAttackGhostGetScan;
    startIndex = object->mInfoFileSets.mSelectedIndex;
    index = startIndex - 1;
    if (index < 0) {
        if (wrap == 0) {
            return;
        }
        index = 3;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mInfoFileSets.mSelectedIndex = index;
                break;
            }
            index--;
            if (index < 0) {
                if (wrap == 0) {
                    return;
                }
                index = 3;
            }
        } while (index != object->mInfoFileSets.mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

// Selects the next filled entry whose counter has run up to its end; a nonzero argument wraps from the last entry to
// the first.
void MoveSelectedGhostDown(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    TimeAttackGhostGetScan *object;

    found = FALSE;
    object = gTimeAttackGhostGetScan;
    startIndex = object->mInfoFileSets.mSelectedIndex;
    index = startIndex + 1;
    if (index >= 4) {
        if (wrap == 0) {
            return;
        }
        index = 0;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mInfoFileSets.mSelectedIndex = index;
                break;
            }
            index++;
            if (index >= 4) {
                if (wrap == 0) {
                    return;
                }
                index = 0;
            }
        } while (index != object->mInfoFileSets.mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

void SetScanSelectedEntryHighlight(s32 cursorVisible) {
    CellFileSet *subCellFileSet;
    s32 selectedIndex;
    s32 courseLabelIndex;
    s32 paletteIndex;

    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    selectedIndex = gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex;
    courseLabelIndex = selectedIndex + 4;
    if (cursorVisible != 0) {
        paletteIndex = 0xe;
    } else {
        paletteIndex = 0xf;
    }
    subCellFileSet->mCellTable[4].mVisible = cursorVisible;
    SetLabelPaletteIndex(courseLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                         subCellFileSet->mCellLayout);
    SetLabelPaletteIndex(selectedIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                         subCellFileSet->mCellLayout);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSubTextTwoButtons(void) {
    void *message;
    void *firstButtonText;
    void *secondButtonText;
    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 8);
    firstButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 1);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextTwoButtonsEx(message, firstButtonText, secondButtonText, 0, 0, 1, 1, 0);
}

#pragma thumb off

#pragma thumb on

void UpdateScanSelectedIndex(void) {
    TimeAttackGhostGetScan *object;
    CellFileSet *subCellFileSet;
    s32 entryIndex;

    object = gTimeAttackGhostGetScan;
    subCellFileSet = &object->mInfoFileSets.mCellFileSets[1];
    if (object->mInfoFileSets.mSelectedIndex < 0) {
        for (entryIndex = 0; entryIndex < 4; entryIndex++) {
            if (object->mGhostInfoEntries[entryIndex].mFilled != FALSE) {
                object->mInfoFileSets.mSelectedIndex = entryIndex;
                subCellFileSet->mCellTable[4].mVisible = 1;
                CopyCellLayoutEntryPosition(4, gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][3],
                                            subCellFileSet->mCellLayout);
                return;
            }
        }
    } else {
        if (object->mFilledCount == 0) {
            subCellFileSet->mCellTable[4].mVisible = 0;
            gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex = -1;
            return;
        }
        if (object->mGhostInfoEntries[object->mInfoFileSets.mSelectedIndex].mFilled == FALSE) {
            for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                if (object->mGhostInfoEntries[entryIndex].mFilled != FALSE) {
                    object->mInfoFileSets.mSelectedIndex = entryIndex;
                    return;
                }
            }
        }
    }
}

void UpdateScanEntryOffsetX(void) {
    CellFileSet *subCellFileSet;
    s32 cellCount;
    s32 entryIndex;
    s16 interpolatedValue;
    s16 offsetX;

    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    cellCount = subCellFileSet->mCellLayout->mCount;
    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
        AdvanceInterpolation(&gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation);
        interpolatedValue =
            GetInterpolatedValue(&gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation);
        subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex + 4][0]].mOffsetX =
            interpolatedValue;
        offsetX = subCellFileSet
                      ->mCellTable[cellCount +
                                   ((const s16(*)[4]) gTimeAttackGhostGetScanSSelLabelTextRows)[entryIndex + 4][0]]
                      .mOffsetX;
        subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][0]].mOffsetX =
            offsetX;
        offsetX =
            subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][0]].mOffsetX;
        subCellFileSet->mCellTable[gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][3]].mOffsetX = offsetX;
        if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex == entryIndex) {
            subCellFileSet->mCellTable[4].mOffsetX = interpolatedValue;
        }
    }
}

void UpdateScanSlideOffsets(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 entryIndex;
    s16 offset;

    mainCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[0];
    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mCount + mainCellFileSet->mLabelLayout->mCount;
    subEntryCount = subCellFileSet->mCellLayout->mCount + subCellFileSet->mLabelLayout->mCount;
    offset = GetInterpolatedValue(&gTimeAttackGhostGetScan->mInterpolation);
    for (entryIndex = 0; entryIndex < mainEntryCount; entryIndex++) {
        mainCellFileSet->mCellTable[entryIndex].mOffsetY = -offset;
    }
    for (entryIndex = 0; entryIndex < subEntryCount; entryIndex++) {
        subCellFileSet->mCellTable[entryIndex].mOffsetY = offset;
    }
}

void RefreshScanSelectedGhostInfo(void) {
    GhostInfoEntry *selectedEntry;
    s32 cellIndex;
    CellFileSet *mainCellFileSet;
    s32 entryCount;
    BOOL hasSelection;

    mainCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[0];
    selectedEntry = &gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex];
    entryCount = mainCellFileSet->mCellLayout->mCount + mainCellFileSet->mLabelLayout->mCount;
    for (cellIndex = 0; cellIndex < entryCount; cellIndex++) {
        if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex >= 0) {
            hasSelection = TRUE;
        } else {
            hasSelection = FALSE;
        }
        mainCellFileSet->mCellTable[cellIndex].mVisible = hasSelection;
    }
    if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex >= 0) {
        PrintGhostRecordInfo(&gTimeAttackGhostGetScan->mInfoFileSets, gTimeAttackGhostGetScanMLabelTextRows,
                             selectedEntry, selectedEntry->mInfo.mCharacterIndex, selectedEntry->mInfo.mKartIndex,
                             selectedEntry->mInfo.mCourseId, &selectedEntry->mInfo.mTime);
    }
}

void RefreshScanEntryPalettes(void) {
    s32 entryIndex;
    CellFileSet *subCellFileSet;
    s32 paletteIndex;
    s32 courseLabelIndex;

    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
        courseLabelIndex = entryIndex + 4;
        if (entryIndex == gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex) {
            paletteIndex = 14;
        } else {
            paletteIndex = 15;
        }
        SetLabelPaletteIndex(courseLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        SetLabelPaletteIndex(entryIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
    }
    if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex >= 0) {
        CopyCellLayoutEntryPosition(
            4, gTimeAttackGhostGetScanSSelLabelTextRows[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex][3],
            subCellFileSet->mCellLayout);
    }
}

BOOL AreGhostRecordInfosDifferent(GhostRecordInfo *storedInfo, GhostRecordInfo *newInfo) {
    s32 charIndex;
    s32 nameDiffers;
    BOOL halfwordDiffers;

    nameDiffers = 0;
    for (charIndex = 0; charIndex < 11; charIndex++) {
        if (storedInfo->mName[charIndex] != newInfo->mName[charIndex]) {
            halfwordDiffers = TRUE;
        } else {
            halfwordDiffers = FALSE;
        }
        nameDiffers |= halfwordDiffers;
    }
    if (nameDiffers != 0 || storedInfo->mKartIndex != newInfo->mKartIndex ||
        storedInfo->mCharacterIndex != newInfo->mCharacterIndex || storedInfo->mCourseId != newInfo->mCourseId ||
        storedInfo->mTime.mMinute != newInfo->mTime.mMinute || storedInfo->mTime.mSecond != newInfo->mTime.mSecond ||
        storedInfo->mTime.mMillisecond != newInfo->mTime.mMillisecond) {
        return TRUE;
    }
    return FALSE;
}

void InitTimeAttackGhostGetScan(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    u32 remainingObjSize;
    s32 index;
    s32 value;
    s32 assignedCount;
    s32 cellCount;
    s16 *row;
    BOOL screen;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostGetScan = HeapAlloc(heap, sizeof(*gTimeAttackGhostGetScan));
    MemFillWordsByBlock_inline(gTimeAttackGhostGetScan, 0x1a8);
    gTimeAttackGhostGetScan->mHeap = heap;
    gTimeAttackGhostGetScan->mOamLists[0] = mainOam;
    gTimeAttackGhostGetScan->mOamLists[1] = subOam;
    gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gTimeAttackGhostGetScan->mGhostMessages = FindSceneFile("ghost.bmg");
    InitBlockEntries(gTimeAttackGhostGetScan->mHeap, 2);
    gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex = -1;
    for (index = 0; index < 4; index++) {
        SetupInterpolation(&gTimeAttackGhostGetScan->mGhostInfoEntries[index].mInterpolation, 3, 10, 0x100, 0);
    }
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, gTimeAttackGhostGetScan, "TimeAttack_ghost_get_m_b.NCGR",
                                   "TimeAttack_ghost_get_m_b.NCLR", "TimeAttack_ghost_get_m.NSCR", 0, FindSceneFile);
    cellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    LocateCellFileSet(cellFileSet, "TimeAttack_ghost_get_m.nce.ncgr", "TimeAttack_ghost_get_m.nce.ncer",
                      "TimeAttack_ghost_get_m_o.NCLR", "TimeAttack_ghost_get_m.bncl", "TimeAttack_ghost_get_m.bnll",
                      NULL, FindSceneFile);
    screen = FALSE;
    SetupCellFileSet(SCREEN_SIDE_MAIN, gTimeAttackGhostGetScan->mHeap, cellFileSet);
    index = 0;
    if (index < cellFileSet->mLabelLayout->mCount) {
        row = (s16 *) gTimeAttackGhostGetScanMLabelTextRows;
        do {
            remainingObjSize -=
                SetupLabelCanvas(screen, gTimeAttackGhostGetScan->mHeap, cellFileSet, row, remainingObjSize);
            row += 4;
            index++;
        } while (index < cellFileSet->mLabelLayout->mCount);
    }
    value = cellFileSet->mCellLayout->mCount + cellFileSet->mLabelLayout->mCount;
    for (index = 0; index < value; index++) {
        cellFileSet->mCellTable[index].mVisible = 0;
    }
    cellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(cellFileSet, "TimeAttack_ghost_get_s.nce.ncgr", "TimeAttack_ghost_get_s.nce.ncer",
                      "TimeAttack_ghost_get_s_o.NCLR", "TimeAttack_ghost_get_s_sel.bncl",
                      "TimeAttack_ghost_get_s_sel.bnll", "TimeAttack_ghost_get_s_sel.bnbl", FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gTimeAttackGhostGetScan->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mCount;
    index = 0;
    if (index < cellFileSet->mLabelLayout->mCount) {
        row = gTimeAttackGhostGetScanSSelLabelTextRows[0];
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= SetupLabelCanvas(SCREEN_SIDE_SUB, gTimeAttackGhostGetScan->mHeap, cellFileSet,
                                                 gTimeAttackGhostGetScanSSelLabelTextRows[index], remainingObjSize);
            row += 4;
            index++;
        } while (index < cellFileSet->mLabelLayout->mCount);
    }
    for (value = 0; value < cellCount; value++) {
        SetCellPriority(value, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    cellFileSet->mCellTable[4].mVisible = 0;
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[2]);
    SetupInterpolation(&gTimeAttackGhostGetScan->mInterpolation, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    FrmHeapShrinkInParent(gTimeAttackGhostGetScan->mHeap);
}

#pragma thumb off

#pragma thumb on

static inline s32 GhostGetScanIsBackupCommandRunning(void) {
    BackupAccess *backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        return backupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 GhostGetScanIsBackupBusy(void) {
    if (gBackupBuffers->mBusy == 0) {
        return GhostGetScanIsBackupCommandRunning();
    }
    return 1;
}

s32 AdvanceTimeAttackGhostGetScan(SceneNumbers *sceneNumbers) {
    CellFileSet *subCellFileSet;
    CellFileSet *cellFileSet;
    s32 previousSelectedIndex;
    u16 slotIndex;
    s32 result;
    s32 touchInReturnRect;
    s32 rectIndex;
    s32 entryIndex;
    s32 courseLabelIndex;
    s32 courseMessageIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 hasPair;
    s32 pairX;
    s32 pairY;
    void *message;
    void *buttonText;
    void *secondButtonText;
    u8 idBytes[3];
    GhostRecordInfo ghostRecordInfo;
    u16 formattedText[0x100];

    previousSelectedIndex = gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex;
    slotIndex = GetPadInputSlot();
    touchInReturnRect = 0;
    result = -1;
    rectIndex = -1;
    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    AdvanceInterpolation(&gTimeAttackGhostGetScan->mInterpolation);
    switch (gTimeAttackGhostGetScan->mState) {
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_FADE:
            if (AreBrightnessFadesClear() == 0) {
                RequestSelectReturnSlideIn();
                SetupGhostMainTextShort();
                SetInterpolationStateIfOpposite(&gTimeAttackGhostGetScan->mInterpolation, INTERPOLATION_STATE_RISING);
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_IN;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_IN:
            if (gTimeAttackGhostGetScan->mInterpolation.mState == 1) {
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_SCAN_LIST;
            } else {
                UpdateScanSlideOffsets();
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_SCAN_LIST:
            switch (AdvanceConnectionSetup(0, NULL)) {
                case 1:
                    SetupTxtSystemSubText(GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0xf));
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 9);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_REQUEST_BLOCK_COUNT;
                    break;
                case 0:
                    if (gTimeAttackGhostGetScan->mGhostPicked != FALSE) {
                        break;
                    }
                    if (IsTxtSystemClosedNoOpenRequest() != 0) {
                        SetupGhostMainTextShort();
                    }
                    gTimeAttackGhostGetScan->mFilledCount = 0;
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        courseLabelIndex = entryIndex + 4;
                        if (TryGetScanGhostInfo(entryIndex, &ghostRecordInfo, &idBytes[0], &idBytes[1], &idBytes[2],
                                                &ghostRecordInfo.mTime.mMinute, &ghostRecordInfo.mTime.mSecond,
                                                &ghostRecordInfo.mTime.mMillisecond)) {
                            ghostRecordInfo.mKartIndex = idBytes[0];
                            ghostRecordInfo.mCharacterIndex = idBytes[1];
                            ghostRecordInfo.mCourseId = idBytes[2];
                            gTimeAttackGhostGetScan->mFilledCount++;
                            if (gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled == FALSE ||
                                AreGhostRecordInfosDifferent(
                                    &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInfo, &ghostRecordInfo) !=
                                    FALSE) {
                                courseMessageIndex = GetGhostCourseMessageIndex(ghostRecordInfo.mCourseId);
                                ghostRecordInfo.mName[10] = 0;
                                PrintLabelLayoutTextNoFixedAdvance(
                                    1, gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][0],
                                    subCellFileSet->mLabelLayout, &ghostRecordInfo, subCellFileSet->mCellLayout,
                                    subCellFileSet->mCellTable);
                                PrintLabelLayoutTextNoFixedAdvance(
                                    1, gTimeAttackGhostGetScanSSelLabelTextRows[courseLabelIndex][0],
                                    subCellFileSet->mLabelLayout,
                                    GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, courseMessageIndex),
                                    subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
                                MIi_CpuCopyFast(&ghostRecordInfo,
                                                &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInfo, 0x28);
                                gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled = TRUE;
                                SetInterpolationStateIfOpposite(
                                    &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation,
                                    INTERPOLATION_STATE_RISING);
                                if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex == entryIndex) {
                                    RefreshScanSelectedGhostInfo();
                                }
                                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 7);
                                NNS_SndArcSetCurrent(&gFileSndArc);
                            }
                        } else {
                            SetInterpolationStateIfOpposite(
                                &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation,
                                INTERPOLATION_STATE_FALLING);
                            gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled = FALSE;
                        }
                    }
                    UpdateScanSelectedIndex();
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
                        pairX = gInputSlots[slotIndex].mPair.mPairX;
                        pairY = gInputSlots[slotIndex].mPair.mPairY;
                        touchInReturnRect = IsSelectReturnShownNoRequestAndInRect(pairX, pairY);
                        rectIndex = RectTableFindContaining(subCellFileSet->mRects, pairX, pairY);
                    }
                    if (rectIndex >= 0 && gTimeAttackGhostGetScan->mGhostInfoEntries[rectIndex].mFilled != FALSE) {
                        SetupGhostSubTextTwoButtons();
                        SetScanSelectedEntryHighlight(
                            gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex != rectIndex ? 1 : 0);
                        gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex = rectIndex;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        RequestSelectReturnSlideOut();
                        gTimeAttackGhostGetScan->mGhostPicked = TRUE;
                        gTimeAttackGhostGetScan->mStateFrames = 0;
                        gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK;
                    } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 &&
                               gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex >= 0) {
                        SetupGhostSubTextTwoButtons();
                        SetScanSelectedEntryHighlight(0);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        RequestSelectReturnSlideOut();
                        gTimeAttackGhostGetScan->mGhostPicked = TRUE;
                        gTimeAttackGhostGetScan->mStateFrames = 0;
                        gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK;
                    } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                        gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_LEAVE;
                        RequestSelectReturnPressWithSound(0);
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP)) {
                        if (gTimeAttackGhostGetScan->mFilledCount == 2) {
                            MoveSelectedGhostUp(0);
                        } else if (gTimeAttackGhostGetScan->mFilledCount > 2) {
                            MoveSelectedGhostUp(1);
                        }
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN)) {
                        if (gTimeAttackGhostGetScan->mFilledCount == 2) {
                            MoveSelectedGhostDown(0);
                        } else if (gTimeAttackGhostGetScan->mFilledCount > 2) {
                            MoveSelectedGhostDown(1);
                        }
                    }
                    break;
                case 2:
                    break;
            }
            if (previousSelectedIndex != gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex) {
                RefreshScanSelectedGhostInfo();
                RefreshScanEntryPalettes();
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK:
            gTimeAttackGhostGetScan->mStateFrames++;
            if (gTimeAttackGhostGetScan->mStateFrames > TIME_ATTACK_GHOST_GET_SCAN_PICK_STEPS) {
                SetScanSelectedEntryHighlight(1);
                gTimeAttackGhostGetScan->mStateFrames = 0;
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK_ANSWER;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK_ANSWER:
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    SetSelectedScanEntry(gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex);
                } else {
                    RequestSelectReturnSlideIn();
                    gTimeAttackGhostGetScan->mGhostPicked = FALSE;
                }
                RequestTxtSystemClose();
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_SCAN_LIST;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_REQUEST_BLOCK_COUNT:
            switch (AdvanceBlockCountRequest()) {
                case 1:
                    ResetPendingFiles();
                    SetBlockEntryBuffer(0, GetSlotGhostBuffer());
                    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_RECEIVE_BLOCKS;
                    break;
                case 2:
                    StartTimeAttackGhostGetScanWaitErrorMessage();
                    break;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_RECEIVE_BLOCKS:
            switch (AdvanceBlockReceive()) {
                case 1:
                    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_AFTER_RECEIVE;
                    break;
                case 2:
                    StartTimeAttackGhostGetScanWaitErrorMessage();
                    break;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_AFTER_RECEIVE:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_CHECK_SLOT;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_LEAVE:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gMenuShared->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 1;
                }
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_CHECK_SLOT:
            if (DoesAnySlotGhostMatchCourse(
                    gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                        .mInfo.mCourseId) != 0) {
                courseMessageIndex = GetGhostCourseMessageIndex(
                    gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                        .mInfo.mCourseId);
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x55);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 0);
                secondButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 1);
                FormatMessageWithText(GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, courseMessageIndex), message,
                                      formattedText, 0x100);
                SetTxtSystemSoundId(0, -1);
                SetupTxtSystemSubTextTwoButtonsEx(formattedText, buttonText, secondButtonText, 1, 0, 1, 1, 0);
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_REPLACE_ANSWER;
            } else if (GetSlotGhostCount() == 10) {
                RequestTxtSystemClose();
                gTimeAttackGhostGetScan->mNextCallbacksIndex = 2;
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_OUT;
                SetInterpolationStateIfOpposite(&gTimeAttackGhostGetScan->mInterpolation, INTERPOLATION_STATE_FALLING);
            } else {
                gTimeAttackGhostGetScan->mGhostSlot = FindUnfilledGhostSlot();
                GetSlotGhostBuffer()->mHead.mFilled = 1;
                WriteSlotGhostRecord(gTimeAttackGhostGetScan->mGhostSlot, GetSlotGhostBuffer());
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_BACKUP;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_REPLACE_ANSWER:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
            if (GetTxtSystemDone() != 0) {
                RequestTxtSystemClose();
                if (GetTxtSystemSelectedIndex() == 0) {
                    gTimeAttackGhostGetScan->mGhostSlot = FindSlotGhostForCourse(
                        gTimeAttackGhostGetScan
                            ->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                            .mInfo.mCourseId);
                    GetSlotGhostBuffer()->mHead.mFilled = 1;
                    WriteSlotGhostRecord(gTimeAttackGhostGetScan->mGhostSlot, GetSlotGhostBuffer());
                    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_BACKUP;
                } else {
                    gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_CLOSED;
                }
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_CLOSED:
            if (IsTxtSystemClosedNoOpenRequest() != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x54);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_BACKUP:
            if (GhostGetScanIsBackupBusy() != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x10);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_ERROR_MESSAGE:
            if (IsTxtSystemOpenAfterOpening() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gTimeAttackGhostGetScan->mStateFrames = 0;
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_LEAVE;
                RequestTxtSystemClose();
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_DONE:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 1;
                }
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_DONE;
            }
            break;
        case TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_OUT:
            if (gTimeAttackGhostGetScan->mInterpolation.mState == 3) {
                result = gTimeAttackGhostGetScan->mNextCallbacksIndex;
                gTimeAttackGhostGetScan->mState = TIME_ATTACK_GHOST_GET_SCAN_STATE_DONE;
            } else {
                UpdateScanSlideOffsets();
            }
            break;
    }
    UpdateScanEntryOffsetX();
    UpdateConnectionSendTimer();
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        cellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[entryIndex];
        DrawLayoutTable(cellFileSet->mCellLayout, cellFileSet->mCells, cellFileSet->mLabelLayout,
                        gTimeAttackGhostGetScan->mOamLists[entryIndex], cellFileSet->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostGetScan(void) {
    HeapDestroy((void *) ((u32) gTimeAttackGhostGetScan->mHeap));
    *&gTimeAttackGhostGetScan = NULL;
}

#pragma thumb off
