#include "Main/Menu/ghost_send.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Graphics/cell_file_set.h"
#include "Main/System/interpolation_value.h"
#include "Main/Menu/scroll_list_state.h"
#include "Main/System/heap.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
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
#include "code_02148950.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/data_02162c74.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Net/block.h"
#include "Main/Menu/title_scene.h"
#include "Main/Graphics/minute_second_millisecond_text.h"
#include "Main/Graphics/message_index.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
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
GhostSceneCallbacks gTimeAttackGhostSendCallbacks = {InitTimeAttackGhostSend, AdvanceTimeAttackGhostSend, ReleaseTimeAttackGhostSend, WriteTimeAttackGhostSendRegisters};
s16 gTimeAttackGhostSendSLabelTextRows[18][4] = {{0, 0x80, 0x10, 0}, {1, 0x80, 0x10, 1}, {2, 0x80, 0x10, 2}, {3, 0x80, 0x10, 3}, {4, 0x80, 0x10, 4}, {5, 0x80, 0x10, 5}, {6, 0x80, 0x10, 6}, {7, 0x40, 0x10, 7}, {8, 0x40, 0x10, 8}, {9, 0x40, 0x10, 9}, {0xa, 0x40, 0x10, 0xa}, {0xb, 0x40, 0x10, 0xb}, {0xc, 0x40, 0x10, 0xc}, {0xd, 0x40, 0x10, 0xd}, {0xe, 0x80, 0x10, -1}, {0xf, 0x80, 0x10, -1}, {0x10, 0x28, 0x10, -1}, {0x11, 0x28, 0x10, -1}};
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

void SetupGhostSendState8Text(void) {
    void *text;
    void *buttonText;
    text = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0xd);
    buttonText = GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4);
    gTimeAttackGhostSend->mState = 8;
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
    RequestSelectReturnState4();
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
    gTimeAttackGhostSend = HeapAlloc(heap, 0xe0);
    MemFillWordsByBlock_inline(gTimeAttackGhostSend, 0xe0);
    gTimeAttackGhostSend->mHeap = heap;
    gTimeAttackGhostSend->mOamLists[0] = mainOam;
    gTimeAttackGhostSend->mOamLists[1] = subOam;
    gTimeAttackGhostSend->mInfoFileSets.mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gTimeAttackGhostSend->mGhostMessages = FindSceneFile("ghost.bmg");
    InitBlockEntries(gTimeAttackGhostSend->mHeap, 2);
    LocateAndQueueScreenMapFileSet(0, gTimeAttackGhostSend, "TimeAttack_ghost_send_m_b.NCGR",
                                   "TimeAttack_ghost_send_m_b.NCLR", "TimeAttack_ghost_send_m.NSCR", 0, FindSceneFile);
    mainFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[0];
    objSizeLeft = GX_GetSizeOfOBJ();
    LocateCellFileSet(mainFileSet, "TimeAttack_ghost_send_m.nce.ncgr", "TimeAttack_ghost_send_m.nce.ncer",
                      "TimeAttack_ghost_send_m_o.NCLR", "TimeAttack_ghost_send_m.bncl", "TimeAttack_ghost_send_m.bnll",
                      NULL, FindSceneFile);
    SetupCellFileSet(0, gTimeAttackGhostSend->mHeap, mainFileSet);
    for (entryIndex = 0; entryIndex < mainFileSet->mLabelLayout->mCount; entryIndex++) {
        objSizeLeft -= SetupLabelCanvas(0, gTimeAttackGhostSend->mHeap, mainFileSet,
                                        gTimeAttackGhostSendMLabelTextRows[entryIndex], objSizeLeft);
    }
    LocateAndQueueScreenMapFileSet(1, &gTimeAttackGhostSend->mScreenMapFileSets[1], "TimeAttack_ghost_send_s_b.NCGR",
                                   "TimeAttack_ghost_send_s_b.NCLR", "TimeAttack_ghost_send_s.NSCR", 3, FindSceneFile);
    subFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    objSizeLeft = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(subFileSet, "TimeAttack_ghost_send_s.nce.ncgr", "TimeAttack_ghost_send_s.nce.ncer",
                      "TimeAttack_ghost_send_s_o.NCLR", "TimeAttack_ghost_send_s.bncl", "TimeAttack_ghost_send_s.bnll",
                      "TimeAttack_ghost_send_s.bnbl", FindSceneFile);
    SetupCellFileSet(1, gTimeAttackGhostSend->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->mCount;
    for (entryIndex = 0; entryIndex < subFileSet->mLabelLayout->mCount; entryIndex++) {
        if (gTimeAttackGhostSendSLabelTextRows[entryIndex][3] < 0) {
            gTimeAttackGhostSendSLabelTextRows[entryIndex][3] = subCellCount + assignedCount++;
        }
        objSizeLeft -= SetupLabelCanvas(1, gTimeAttackGhostSend->mHeap, subFileSet,
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
    SetupInterpolation(&gTimeAttackGhostSend->mInterpolation, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    SendLedPatternWireless();
    gTimeAttackGhostSend->mState = 1;
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
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        returnRequested = 1;
    }
    if (returnRequested == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        isTouched = 1;
    }
    if (isTouched != 0) {
        returnTouched = IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                        gInputSlots[slotIndex].mPair.mPairY);
    }
    switch (gTimeAttackGhostSend->mState) {
        case 0:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 1:
            if (AreBrightnessFadesClear() == 0) {
                if (GetGhostCount() == 0) {
                    SetupTxtSystemSubTextButton(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x53),
                                                GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4));
                    gTimeAttackGhostSend->mState = 0;
                } else {
                    PrintSelectedGhostSendRecord();
                    SetupGhostSendMainText();
                    RequestSelectReturnState1();
                    SetInterpolationStateIfOpposite(&gTimeAttackGhostSend->mInterpolation, 0);
                    gTimeAttackGhostSend->mState = 2;
                }
            }
            break;
        case 2:
            if (gTimeAttackGhostSend->mInterpolation.mState == 1) {
                gTimeAttackGhostSend->mUnk_0b4 = 0;
                gTimeAttackGhostSend->mState = 3;
            } else {
                SetGhostSendCellsOffsetY();
            }
            break;
        case 3:
            if (IsTxtSystemState2NoCloseRequest() != 0) {
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
                    gTimeAttackGhostSend->mState = 4;
                } else {
                    keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
                    if (keyB != 0 || returnTouched != 0) {
                        gMenuShared->mMenuEntryKind = 5;
                        if (advanceArg != NULL) {
                            advanceArg->mNextScene = 1;
                        }
                        gTimeAttackGhostSend->mState = 0xe;
                        RequestSelectReturnState3WithSound(0);
                    }
                }
            }
            break;
        case 4:
            backupAccess = gBackupAccess;
            if (backupAccess->mBackupEnabled != 0) {
                value = backupAccess->mCommandRunning;
            } else {
                value = 0;
            }
            if (value == 0 && backupAccess->mErrorCode == 0) {
                if (IsSlotGhostIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex) == 0) {
                    CopyCourseGhostToSlotGhost(GetCourseGhostBuffer(), GetSlotGhostBuffer());
                }
                gTimeAttackGhostSend->mState = 5;
            }
            break;
        case 5:
            value = AdvanceConnectionSetup(1, GetSlotGhostBuffer());
            switch (value) {
                case 1:
                    ResetPendingFiles();
                    AddGhostDataBlockWrapper(GetSlotGhostBuffer(), 0x1000);
                    RequestSelectReturnState1();
                    gTimeAttackGhostSend->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
            if (keyB != 0 || returnTouched != 0) {
                RequestSelectReturnState3WithSound(0);
                SetSelectReturnSoundId(0xf);
                StopTimeAttackGhostSendSeq();
                gTimeAttackGhostSend->mState = 0xb;
            } else if (CopySingleChildName(gTimeAttackGhostSend->mChildName) != 0) {
                RequestSelectReturnState4();
                StopTimeAttackGhostSendSeq();
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 9);
                NNS_SndArcSetCurrent(&gFileSndArc);
                SetupGhostSendSubTextWithName(0xb, 0);
                gTimeAttackGhostSend->mState = 7;
            }
            break;
        case 7:
            value = GetZeroWordResult();
            switch (value) {
                case 1:
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xa);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gTimeAttackGhostSend->mState = 0xa;
                    break;
                case 2:
                    SetupGhostSendState8Text();
                    break;
            }
            break;
        case 8:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gTimeAttackGhostSend->mState = 9;
            }
            break;
        case 9:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 10:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendSubTextWithName(0xc, 1);
                gTimeAttackGhostSend->mState = 0xd;
            }
            break;
        case 11:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendMainText();
                gTimeAttackGhostSend->mState = 3;
            }
            break;
        case 13:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mNextScene = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
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
    *(int *) &gTimeAttackGhostSend = 0;
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
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedValue << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
