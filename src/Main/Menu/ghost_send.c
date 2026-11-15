#include "Main/Menu/ghost_send.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Graphics/cell_file_set.h"
#include "Main/System/interpolation_value.h"
#include "Main/Menu/scroll_list_state.h"
#include "Main/System/heap.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "sound_archive_load.h"
#include "sound_archive_load_result.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Race/ghost_list.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/led_pattern.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "vram_bank_display_setup.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/input_slots.h"
#include "Main/Net/block.h"
#include "Main/Menu/title_scene.h"
#include "Main/Graphics/minute_second_millisecond_text.h"
#include "Main/Graphics/message_index.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/select_character.h"
#include "Main/Net/scan_ghost_info.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const s16 gTimeAttackGhostSendMLabelTextRows[3][4] = {{0, 0xdc, 0x10, 0}, {1, 0x50, 0xc, 1}, {2, 0x82, 0x10, 2}};
GhostSceneCallbacks gTimeAttackGhostSendCallbacks = {InitTimeAttackGhostSend, AdvanceTimeAttackGhostSend,
                                                     ReleaseTimeAttackGhostSend, WriteTimeAttackGhostSendRegisters};
s16 gTimeAttackGhostSendSLabelTextRows[18][4] = {
    {0, 0x80, 0x10, 0},     {1, 0x80, 0x10, 1},     {2, 0x80, 0x10, 2},     {3, 0x80, 0x10, 3},
    {4, 0x80, 0x10, 4},     {5, 0x80, 0x10, 5},     {6, 0x80, 0x10, 6},     {7, 0x40, 0x10, 7},
    {8, 0x40, 0x10, 8},     {9, 0x40, 0x10, 9},     {0xa, 0x40, 0x10, 0xa}, {0xb, 0x40, 0x10, 0xb},
    {0xc, 0x40, 0x10, 0xc}, {0xd, 0x40, 0x10, 0xd}, {0xe, 0x80, 0x10, -1},  {0xf, 0x80, 0x10, -1},
    {0x10, 0x28, 0x10, -1}, {0x11, 0x28, 0x10, -1}};
TimeAttackGhostSend *gTimeAttackGhostSend;

#pragma thumb on

void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    MinuteSecondMillisecondTime recordTime;
    s16 text[10];
    CellFileSet *fileSet;
    s32 listIndex;
    s32 value;
    s32 flagValue;
    fileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    if (action == 1) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, slot, fileSet->mLabelLayout,
            GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, GetGhostCourseMessageIndex(GetListedGhostCourseId(row))),
            fileSet->mCellLayout, fileSet->mCellTable);
        GetListedGhostTime(row, &recordTime);
        WriteMinuteSecondMillisecondText(text, recordTime.mMinute, recordTime.mSecond, recordTime.mMillisecond);
        PrintLabelLayoutTextFixedDigits(1, slot + 7, fileSet->mLabelLayout, text, fileSet->mCellLayout,
                                        fileSet->mCellTable, 7);
        value = IsSlotGhostIndex(row) == 0;
        fileSet->mCellTable[slot].mVisible = value;
        flagValue = value == 0;
        fileSet->mCellTable[slot + 7].mVisible = flagValue;
    } else if (action == 0) {
        for (listIndex = 0; listIndex < 7; listIndex++) {
            value = listIndex + 7;
            if (listIndex == selectedSlot) {
                flagValue = 0xe;
            } else {
                flagValue = 0xf;
            }
            SetLabelPaletteIndex(listIndex, flagValue, fileSet->mLabelLayout, fileSet->mCellTable,
                                 fileSet->mCellLayout);
            SetLabelPaletteIndex(value, flagValue, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
        }
    } else if (action == 2) {
        if (row >= 0 && row < (s32) GetGhostCount()) {
            value = IsSlotGhostIndex(row) == 0;
            fileSet->mCellTable[slot].mVisible = value;
            flagValue = value == 0;
            fileSet->mCellTable[slot + 7].mVisible = flagValue;
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendEndConnectionText(void) {
    void *text;
    void *buttonText;
    text = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0xd);
    buttonText = GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4);
    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_TEXT_END_CONNECTION;
    SetupTxtSystemSubTextButton(text, buttonText);
}

#pragma thumb off

#pragma thumb on

void PrintGhostSendCounts(void) {
    u16 text[6];
    CellFileSet *fileSet;
    s32 count;
    fileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    PrintLabelLayoutTextNoFixedAdvance(1, 0xe, fileSet->mLabelLayout,
                                       GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x56), fileSet->mCellLayout,
                                       fileSet->mCellTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 0xf, fileSet->mLabelLayout,
                                       GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x57), fileSet->mCellLayout,
                                       fileSet->mCellTable);
    count = GetCourseGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '3';
    text[4] = '2';
    text[5] = 0;
    PrintLabelLayoutTextFixedDigits(1, 0x10, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
    count = GetSlotGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '1';
    text[4] = '0';
    text[5] = 0;
    PrintLabelLayoutTextFixedDigits(1, 0x11, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
}

void PrintSelectedGhostSendRecord(void) {
    MinuteSecondMillisecondTime recordTime;
    u16 name[10];
    u16 terminatedName[11];
    s32 characterIndex;
    s32 kartIndex;
    GetListedGhostTime(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex, &recordTime);
    GetListedGhostName(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex, name);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    kartIndex = GetListedGhostKartIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    PrintGhostRecordInfo(&gTimeAttackGhostSend->mInfoFileSets, gTimeAttackGhostSendMLabelTextRows, terminatedName,
                         characterIndex, kartIndex,
                         GetListedGhostCourseId(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex), &recordTime);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendMainText(void) {
    void *text;
    text = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0);
    SetupTxtSystemMainTextShort(text, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendSubTextWithName(s32 messageIndex, s32 withButton) {
    u16 name[11];
    u16 text[0x100];
    void *message;
    message = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, messageIndex);
    MIi_CpuCopy16(gTimeAttackGhostSend->mChildName, name, 0x14);
    name[10] = 0;
    FormatMessageWithText(name, message, text, 0x100);
    if (withButton != 0) {
        SetupTxtSystemSubTextButton(text, GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4));
    } else {
        SetupTxtSystemSubText(text);
    }
}

void StartReadSelectedGhost(void) {
    StartReadListedGhost(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    SetupTxtSystemSubText(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 9));
    SetSelectReturnSoundId(0xe);
    RequestSelectReturnSlideOut();
}

void SetGhostSendCellsOffsetY(void) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 cellIndex;
    s16 subOffsetY;
    mainFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[0];
    subFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    mainEntryCount = mainFileSet->mCellLayout->mCount + mainFileSet->mLabelLayout->mCount;
    subEntryCount = subFileSet->mCellLayout->mCount + subFileSet->mLabelLayout->mCount;
    subOffsetY = GetInterpolatedValue(&gTimeAttackGhostSend->mInterpolation);
    for (cellIndex = 0; cellIndex < mainEntryCount; cellIndex++) {
        mainFileSet->mCellTable[cellIndex].mOffsetY = -subOffsetY;
    }
    for (cellIndex = 0; cellIndex < subEntryCount; cellIndex++) {
        subFileSet->mCellTable[cellIndex].mOffsetY = subOffsetY;
    }
}

void InitTimeAttackGhostSend(void *parentHeap, void *mainOam, void *subOam) {
    s16 groupFirstEntries[4];
    s32 cellIndex;
    s32 labelIndex;
    LayoutTableEntry *cellTable;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    void *heap;
    s32 entryIndex;
    s32 objSizeLeft;
    s32 subCellCount;
    s32 assignedCount;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostSend = HeapAlloc(heap, sizeof(*gTimeAttackGhostSend));
    MemFillWordsByBlock_inline(gTimeAttackGhostSend, 0xe0);
    gTimeAttackGhostSend->mHeap = heap;
    gTimeAttackGhostSend->mOamLists[0] = mainOam;
    gTimeAttackGhostSend->mOamLists[1] = subOam;
    gTimeAttackGhostSend->mInfoFileSets.mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gTimeAttackGhostSend->mGhostMessages = FindSceneFile("ghost.bmg");
    InitBlockEntries(gTimeAttackGhostSend->mHeap, 2);
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, gTimeAttackGhostSend, "TimeAttack_ghost_send_m_b.NCGR",
                                   "TimeAttack_ghost_send_m_b.NCLR", "TimeAttack_ghost_send_m.NSCR", 0, FindSceneFile);
    mainFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[0];
    objSizeLeft = GX_GetSizeOfOBJ();
    LocateCellFileSet(mainFileSet, "TimeAttack_ghost_send_m.nce.ncgr", "TimeAttack_ghost_send_m.nce.ncer",
                      "TimeAttack_ghost_send_m_o.NCLR", "TimeAttack_ghost_send_m.bncl", "TimeAttack_ghost_send_m.bnll",
                      NULL, FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_MAIN, gTimeAttackGhostSend->mHeap, mainFileSet);
    for (entryIndex = 0; entryIndex < mainFileSet->mLabelLayout->mCount; entryIndex++) {
        objSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_MAIN, gTimeAttackGhostSend->mHeap, mainFileSet,
                                        gTimeAttackGhostSendMLabelTextRows[entryIndex], objSizeLeft);
    }
    LocateAndQueueScreenMapFileSet(SCREEN_SIDE_SUB, &gTimeAttackGhostSend->mScreenMapFileSets[1],
                                   "TimeAttack_ghost_send_s_b.NCGR", "TimeAttack_ghost_send_s_b.NCLR",
                                   "TimeAttack_ghost_send_s.NSCR", 3, FindSceneFile);
    subFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    objSizeLeft = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(subFileSet, "TimeAttack_ghost_send_s.nce.ncgr", "TimeAttack_ghost_send_s.nce.ncer",
                      "TimeAttack_ghost_send_s_o.NCLR", "TimeAttack_ghost_send_s.bncl", "TimeAttack_ghost_send_s.bnll",
                      "TimeAttack_ghost_send_s.bnbl", FindSceneFile);
    SetupCellFileSet(SCREEN_SIDE_SUB, gTimeAttackGhostSend->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->mCount;
    for (entryIndex = 0; entryIndex < subFileSet->mLabelLayout->mCount; entryIndex++) {
        if (gTimeAttackGhostSendSLabelTextRows[entryIndex][3] < 0) {
            gTimeAttackGhostSendSLabelTextRows[entryIndex][3] = subCellCount + assignedCount++;
        }
        objSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_SUB, gTimeAttackGhostSend->mHeap, subFileSet,
                                        (s16(*)[4]) gTimeAttackGhostSendSLabelTextRows + entryIndex, objSizeLeft);
    }
    PrintGhostSendCounts();
    for (entryIndex = 0; entryIndex < 0xf; entryIndex++) {
        SetCellPriority(entryIndex, 3, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
        SetLabelPriority(entryIndex, 2, subFileSet->mLabelLayout, subFileSet->mCellTable, subFileSet->mCellLayout);
    }
    for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
        cellIndex = gTimeAttackGhostSendSLabelTextRows[entryIndex][3];
        labelIndex = gTimeAttackGhostSendSLabelTextRows[entryIndex][0];
        cellTable = subFileSet->mCellTable;
        SetLayoutEntryPositionFromCell(cellIndex, &cellTable[cellIndex], subFileSet->mCellLayout);
        SetLayoutEntryPositionFromLabel(labelIndex, cellTable + subCellCount + labelIndex, subFileSet->mLabelLayout);
    }
    SetLayoutEntryPositionFromCell(0xe, &subFileSet->mCellTable[0xe], subFileSet->mCellLayout);
    if (GetGhostCount() != 0) {
        ScreenMapFileSet *screenMapFileSet = &gTimeAttackGhostSend->mScreenMapFileSets[1];
        groupFirstEntries[0] = 0;
        groupFirstEntries[1] = 7;
        groupFirstEntries[2] = subCellCount;
        groupFirstEntries[3] = subCellCount + 7;
        InitScrollList(gTimeAttackGhostSend->mHeap, 4, groupFirstEntries, 0xe, 0xf, 0x7c, subFileSet->mCellTable,
                       subFileSet->mRects, screenMapFileSet->mScreenMaps[3]->mData, 0, 1, 2, GetGhostCount(),
                       RefreshGhostListRows);
    } else {
        for (entryIndex = 0; entryIndex < subCellCount; entryIndex++) {
            subFileSet->mCellTable[entryIndex].mVisible = 0;
        }
        for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
            subFileSet->mCellTable[subCellCount + entryIndex].mVisible = 0;
        }
    }
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[2]);
    SetupInterpolation(&gTimeAttackGhostSend->mInterpolation, INTERPOLATION_STATE_AT_START, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    SendLedPatternWireless();
    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_FADE;
    FrmHeapShrinkInParent(gTimeAttackGhostSend->mHeap);
}

s32 AdvanceTimeAttackGhostSend(SceneNumbers *advanceArg) {
    u16 slotIndex;
    s32 isTouched;
    s32 returnRequested;
    s32 returnTouched;
    s32 hasPair;
    u16 keyB;
    BackupAccess *backupAccess;
    CellFileSet *fileSets;
    s32 value;
    slotIndex = GetPadInputSlot();
    returnTouched = 0;
    AdvanceInterpolation(&gTimeAttackGhostSend->mInterpolation);
    isTouched = returnTouched;
    returnRequested = isTouched;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        returnRequested = 1;
    }
    if (returnRequested == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        isTouched = 1;
    }
    if (isTouched != 0) {
        returnTouched = IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    switch (gTimeAttackGhostSend->mState) {
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_NO_GHOST_TEXT:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = MENU_ENTRY_TIME_ATTACK_TOP_MENU;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = SCENE_MENU_1;
                }
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_LEAVE;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_FADE:
            if (AreBrightnessFadesClear() == 0) {
                if (GetGhostCount() == 0) {
                    SetupTxtSystemSubTextButton(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x53),
                                                GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4));
                    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_NO_GHOST_TEXT;
                } else {
                    PrintSelectedGhostSendRecord();
                    SetupGhostSendMainText();
                    RequestSelectReturnSlideIn();
                    SetInterpolationStateIfOpposite(&gTimeAttackGhostSend->mInterpolation, INTERPOLATION_STATE_RISING);
                    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_SLIDE_IN;
                }
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_SLIDE_IN:
            if (gTimeAttackGhostSend->mInterpolation.mState == INTERPOLATION_STATE_AT_END) {
                gTimeAttackGhostSend->mUnk_0b4 = 0;
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_PICK_GHOST;
            } else {
                SetGhostSendCellsOffsetY();
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_PICK_GHOST:
            if (IsTxtSystemOpenNoCloseRequest() != 0) {
                AdvanceScrollList();
                value = GetScrollListSelectedRow();
                if (gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex != value) {
                    gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex = value;
                    PrintSelectedGhostSendRecord();
                }
                if (IsScrollListPickStarted() != 0) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 7);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
                if (IsScrollListPickFinished() != 0) {
                    StartReadSelectedGhost();
                    StartTimeAttackGhostSendSeq();
                    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_GHOST_READ;
                } else {
                    keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
                    if (keyB != 0 || returnTouched != 0) {
                        gMenuShared->mMenuEntryKind = MENU_ENTRY_TIME_ATTACK_TOP_MENU;
                        if (advanceArg != NULL) {
                            advanceArg->mNextScene = SCENE_MENU_1;
                        }
                        gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_LEAVE;
                        RequestSelectReturnPressWithSound(0);
                    }
                }
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_GHOST_READ:
            backupAccess = gBackupAccess;
            if (backupAccess->mBackupEnabled != 0) {
                value = backupAccess->mCommandRunning;
            } else {
                value = 0;
            }
            if (value == 0 && backupAccess->mErrorCode == BACKUP_ERROR_NONE) {
                if (IsSlotGhostIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex) == 0) {
                    CopyCourseGhostToSlotGhost(GetCourseGhostBuffer(), GetSlotGhostBuffer());
                }
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_SETUP_CONNECTION;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_SETUP_CONNECTION:
            value = AdvanceConnectionSetup(1, GetSlotGhostBuffer());
            switch (value) {
                case 1:
                    ResetPendingFiles();
                    AddGhostDataBlockWrapper(GetSlotGhostBuffer(), 0x1000);
                    RequestSelectReturnSlideIn();
                    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_CHILD;
                    break;
                case MP_STATE_ADVANCE_OWN_INDEX_LOST:
                    break;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_CHILD:
            keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
            if (keyB != 0 || returnTouched != 0) {
                RequestSelectReturnPressWithSound(0);
                SetSelectReturnSoundId(0xf);
                StopTimeAttackGhostSendSeq();
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_BACK_TO_LIST;
            } else if (CopySingleChildName(gTimeAttackGhostSend->mChildName) != 0) {
                RequestSelectReturnSlideOut();
                StopTimeAttackGhostSendSeq();
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 9);
                NNS_SndArcSetCurrent(&gFileSndArc);
                SetupGhostSendSubTextWithName(0xb, 0);
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_RESULT;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_RESULT:
            value = GetZeroWordResult();
            switch (value) {
                case WORD_WAIT_RESULT_RECEIVED:
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xa);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_SHOW_NAME;
                    break;
                case WORD_WAIT_RESULT_NOT_RECEIVED:
                    SetupGhostSendEndConnectionText();
                    break;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_TEXT_END_CONNECTION:
            if (IsTxtSystemOpenAfterOpening() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_LEAVE;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_LEAVE:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gMenuShared->mMenuEntryKind = MENU_ENTRY_TIME_ATTACK_TOP_MENU;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = SCENE_MENU_1;
                }
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_LEAVE;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_SHOW_NAME:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendSubTextWithName(0xc, 1);
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_WAIT_NAME_TEXT_LEAVE;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_BACK_TO_LIST:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendMainText();
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_PICK_GHOST;
            }
            break;
        case TIME_ATTACK_GHOST_SEND_STATE_WAIT_NAME_TEXT_LEAVE:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = MENU_ENTRY_TIME_ATTACK_TOP_MENU;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = SCENE_MENU_1;
                }
                gTimeAttackGhostSend->mState = TIME_ATTACK_GHOST_SEND_STATE_LEAVE;
            }
            break;
    }
    UpdateConnectionSendTimer();
    for (value = 0; value < 2; value++) {
        fileSets = gTimeAttackGhostSend->mInfoFileSets.mCellFileSets;
        DrawLayoutTable(fileSets[value].mCellLayout, fileSets[value].mCells, fileSets[value].mLabelLayout,
                        gTimeAttackGhostSend->mOamLists[value], fileSets[value].mCellTable);
    }
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostSend(void) {
    HeapDestroy(gTimeAttackGhostSend->mHeap);
    gTimeAttackGhostSend = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteTimeAttackGhostSendRegisters(void) {
    s16 interpolatedValue = GetInterpolatedValue(&gTimeAttackGhostSend->mInterpolation);
    int negatedValue;
    reg_G2_BG0OFS = ((interpolatedValue << 16) & 0x1ff0000);
    negatedValue = -interpolatedValue;
    reg_G2S_DB_BG3OFS = ((negatedValue << 16) & 0x1ff0000);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    if (interpolatedValue != 0) {
        reg_GX_DISPCNT =
            (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
            REG_GX_DISPCNT_W0_MASK;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedValue << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT &
                              ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
                             REG_GXS_DB_DISPCNT_W0_MASK;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT &
                             ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
    }
}

#pragma thumb off
