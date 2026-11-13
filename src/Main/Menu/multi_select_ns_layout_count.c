#include "Main/Menu/multi_select_ns_layout_count.h"
#include "Main/System/heap.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/palette_blend.h"
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
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/select_return.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/data_02175628.h"
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
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Net/multiboot_parent.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Save/emblem_block.h"
#include "code_02148950.h"
#include "Main/Menu/data_02163000.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_0214d018.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/select_character.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

const s16 gMultiSelectKeyStartLabelData[22] = {0xd,  0xa, -1,  -1, 6,  0x82, 0xd,  0xc, -1,   -1, 7,
                                               0x82, 0xd, 0xe, -1, -1, 8,    0x78, 0xd, 0x11, 6,  0};
struct WLMenuCallbacks gMemberKeyStartCallbacks = {InitMultiSelectMemberKeyStart, AdvanceMultiSelectMemberKeyStart,
                                                   ReleaseMultiSelectMember, WriteMultiSelectMemberRegisters};
struct WLMenuCallbacks gMemberNoKeyStartCallbacks = {InitMultiSelectMemberNoKeyStart,
                                                     AdvanceMultiSelectMemberNoKeyStart, ReleaseMultiSelectMember,
                                                     WriteMultiSelectMemberRegisters};
struct MultiSelectMember *gMultiSelectMember;

void SetupMultiSelectMemberSubTextButton(void) {
    void *bannerMessage;
    void *commonMessage;

    bannerMessage = GetBmgEntry(gMultiSelectMember->mBannerMessages, 0xb);
    commonMessage = GetBmgEntry(gMultiSelectMember->mCommonMessages, 4);
    gMultiSelectMember->mSetupState = 8;
    gMultiSelectMember->mState = 5;
    SetupTxtSystemSubTextButton(bannerMessage, commonMessage);
    RequestSelectReturnState4();
}

s32 CountMultiSelectChildren(void) {
    s32 participantIndex;
    s32 childCount;

    childCount = 0;
    for (participantIndex = 1; participantIndex < 8; participantIndex++) {
        if (TryGetPlayerName(participantIndex, NULL) != 0) {
            childCount++;
        }
    }
    return childCount;
}

void PrintMultiSelectMemberNames(void) {
    CellFileSet *subFileSet;
    const LabelMessageRow *labelMessageRow;
    u16 nameBuffer[12];
    s32 participantIndex;

    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    for (participantIndex = 1, labelMessageRow = &gMultiSelectMemberSubLabelRows.mRows[1]; participantIndex < 8;
         labelMessageRow++, participantIndex++) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (TryGetPlayerName(participantIndex, &nameBuffer[1]) != 0) {
            nameBuffer[11] = 0;
            PrintLabelLayoutTextNoFixedAdvance(1, labelMessageRow->mLabelIndex, subFileSet->mLabelLayout,
                                               &nameBuffer[1], subFileSet->mCellLayout, subFileSet->mCellTable);
            if (gMultiSelectMember->mRows[participantIndex].mState != 2) {
                gMultiSelectMember->mRows[participantIndex].mState = 1;
            }
        } else {
            ClearAndQueueLabelLayoutText(1, labelMessageRow->mLabelIndex, subFileSet->mLabelLayout,
                                         subFileSet->mCellLayout, subFileSet->mCellTable);
            gMultiSelectMember->mRows[participantIndex].mState = 0;
        }
    }
}

void PrintMultiSelectConnectionNames(void) {
    CellFileSet *subFileSet;
    const LabelMessageRow *labelMessageRow;
    u16 nameBuffer[12];
    s32 childCount;
    s32 participantIndex;

    childCount = 0;
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    for (participantIndex = 1, labelMessageRow = &gMultiSelectMemberSubLabelRows.mRows[1]; participantIndex < 8;
         labelMessageRow++, participantIndex++) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (GetPlayerRecord(participantIndex) != NULL) {
            MIi_CpuCopy16(GetPlayerRecord(participantIndex), &nameBuffer[1], 0x14);
            if (nameBuffer[1] != 0) {
                PrintLabelLayoutTextNoFixedAdvance(1, labelMessageRow->mLabelIndex, subFileSet->mLabelLayout,
                                                   &nameBuffer[1], subFileSet->mCellLayout, subFileSet->mCellTable);
                gMultiSelectMember->mRows[participantIndex].mState = 2;
                childCount++;
            } else {
                ClearAndQueueLabelLayoutText(1, labelMessageRow->mLabelIndex, subFileSet->mLabelLayout,
                                             subFileSet->mCellLayout, subFileSet->mCellTable);
                gMultiSelectMember->mRows[participantIndex].mState = 0;
            }
        }
    }
    gMultiSelectMember->mChildCount = childCount;
    gMultiSelectMember->mConnectionNamesDone = TRUE;
}

void UpdateMultiSelectMemberCells(void) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    s32 mainLabelCount;
    s32 mainCellCount;
    s32 subLabelCount;
    s32 subCellCount;
    s32 cellIndex;
    s16 interpolatedValue;
    BOOL visible;
    s32 value;
    MultiSelectMemberRow *row;

    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    mainLabelCount = mainFileSet->mLabelLayout->mCount;
    mainCellCount = mainFileSet->mCellLayout->mCount;
    subLabelCount = subFileSet->mLabelLayout->mCount;
    subCellCount = subFileSet->mCellLayout->mCount;
    AdvanceInterpolation(&gMultiSelectMember->mInterpolations[0]);
    mainFileSet->mCellTable[2].mOffsetY = GetInterpolatedValue(&gMultiSelectMember->mInterpolations[0]);
    mainFileSet->mCellTable[1].mOffsetY = mainFileSet->mCellTable[2].mOffsetY;
    mainFileSet->mCellTable[0].mOffsetY = mainFileSet->mCellTable[1].mOffsetY;
    gMultiSelectMember->mCycleFrames = gMultiSelectMember->mCycleFrames + 1;
    if (gMultiSelectMember->mCycleFrames > gMultiSelectMemberCycleSteps[gMultiSelectMember->mCycleIndex].mFrameLimit) {
        gMultiSelectMember->mCycleIndex = gMultiSelectMember->mCycleIndex + 1;
        if (gMultiSelectMember->mCycleIndex == 4) {
            gMultiSelectMember->mCycleIndex = 0;
        }
        gMultiSelectMember->mCycleFrames = 0;
    }
    if (gMultiSelectMemberCycleSteps[gMultiSelectMember->mCycleIndex].mCellIndex == 0) {
        value = 1;
    } else {
        value = 0;
    }
    mainFileSet->mCellTable[0].mVisible = value;
    if (gMultiSelectMemberCycleSteps[gMultiSelectMember->mCycleIndex].mCellIndex == 1) {
        value = 1;
    } else {
        value = 0;
    }
    mainFileSet->mCellTable[1].mVisible = value;
    if (gMultiSelectMemberCycleSteps[gMultiSelectMember->mCycleIndex].mCellIndex == 2) {
        value = 1;
    } else {
        value = 0;
    }
    mainFileSet->mCellTable[2].mVisible = value;
    AdvanceInterpolation(&gMultiSelectMember->mInterpolations[1]);
    interpolatedValue = GetInterpolatedValue(&gMultiSelectMember->mInterpolations[1]);
    mainFileSet->mCellTable[0xb].mOffsetY = interpolatedValue;
    mainFileSet->mCellTable[0xa].mOffsetY = mainFileSet->mCellTable[0xb].mOffsetY;
    mainFileSet->mCellTable[9].mOffsetY = mainFileSet->mCellTable[0xa].mOffsetY;
    mainFileSet->mCellTable[8].mOffsetY = mainFileSet->mCellTable[9].mOffsetY;
    mainFileSet->mCellTable[7].mOffsetY = mainFileSet->mCellTable[8].mOffsetY;
    mainFileSet->mCellTable[6].mOffsetY = mainFileSet->mCellTable[7].mOffsetY;
    mainFileSet->mCellTable[5].mOffsetY = mainFileSet->mCellTable[6].mOffsetY;
    mainFileSet->mCellTable[4].mOffsetY = mainFileSet->mCellTable[5].mOffsetY;
    mainFileSet->mCellTable[3].mOffsetY = mainFileSet->mCellTable[4].mOffsetY;
    for (cellIndex = 0; cellIndex < mainLabelCount; cellIndex++) {
        mainFileSet->mCellTable[cellIndex + mainCellCount].mOffsetY = interpolatedValue;
    }
    AdvanceInterpolation(&gMultiSelectMember->mInterpolations[2]);
    interpolatedValue = GetInterpolatedValue(&gMultiSelectMember->mInterpolations[2]);
    cellIndex = 0;
    value = subCellCount + subLabelCount;
    for (; cellIndex < value; cellIndex++) {
        subFileSet->mCellTable[cellIndex].mOffsetY = interpolatedValue;
    }
    if (gMultiSelectMember->mChildCount > 0) {
        SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[3], 0);
    } else {
        SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[3], 2);
    }
    AdvanceInterpolation(&gMultiSelectMember->mInterpolations[3]);
    interpolatedValue = GetInterpolatedValue(&gMultiSelectMember->mInterpolations[3]);
    subCellCount = subCellCount + 8;
    subFileSet->mCellTable[subCellCount].mOffsetY = interpolatedValue;
    subFileSet->mCellTable[0x11].mOffsetY = subFileSet->mCellTable[subCellCount].mOffsetY;
    subFileSet->mCellTable[0x10].mOffsetY = subFileSet->mCellTable[0x11].mOffsetY;
    if (gMultiSelectMember->mUnk_84 == 0) {
        for (cellIndex = 0; cellIndex < 8; cellIndex++) {
            row = &gMultiSelectMember->mRows[cellIndex];
            switch (row->mState) {
                case 0:
                    subFileSet->mCellTable[row->mSecondCellIndex].mVisible = 0;
                    subFileSet->mCellTable[row->mFirstCellIndex].mVisible =
                        subFileSet->mCellTable[row->mSecondCellIndex].mVisible;
                    row->mStateFrames = 0;
                    break;
                case 1:
                    row->mStateFrames = row->mStateFrames + 1;
                    if (row->mStateFrames > 0x14) {
                        row->mState = 2;
                    } else {
                        if (row->mStateFrames / 4 % 2 == 0) {
                            visible = TRUE;
                        } else {
                            visible = FALSE;
                        }
                        subFileSet->mCellTable[row->mFirstCellIndex].mVisible = visible;
                        if (visible == FALSE) {
                            visible = TRUE;
                        } else {
                            visible = FALSE;
                        }
                        subFileSet->mCellTable[row->mSecondCellIndex].mVisible = visible;
                    }
                    break;
                case 2:
                    subFileSet->mCellTable[row->mSecondCellIndex].mVisible = 1;
                    subFileSet->mCellTable[row->mFirstCellIndex].mVisible =
                        subFileSet->mCellTable[row->mSecondCellIndex].mVisible;
                    row->mStateFrames = 0;
                    break;
            }
        }
    }
}

void SetMultiSelectChildCountCellsVisible(void) {
    s32 countIndex;
    CellFileSet *mainFileSet;
    BOOL visible;

    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    for (countIndex = 0; countIndex < 8; countIndex++) {
        if (countIndex == gMultiSelectMember->mChildCount) {
            visible = TRUE;
        } else {
            visible = FALSE;
        }
        mainFileSet->mCellTable[gMultiSelectMemberCountCellIndices[countIndex]].mVisible = visible;
    }
}

void SetMultiSelectMemberSubCellVisible(s32 visible) {
    CellFileSet *subFileSet;
    s32 labelValue;

    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    if (visible != 0) {
        labelValue = 1;
    } else {
        labelValue = 0;
    }
    subFileSet->mCellTable[0x11].mVisible = visible;
    SetLabelPaletteIndex(8, labelValue, subFileSet->mLabelLayout, subFileSet->mCellTable, subFileSet->mCellLayout);
}

void UpdateMultiSelectMemberKeySetup(void) {
    s32 backupBusy;

    switch (gMultiSelectMember->mSetupState) {
        case 0:
            if (AdvanceSetupByMultiBoot(1, gStartupWork->mMultiSimple) == 1) {
                gMultiSelectMember->mSetupState = 1;
            }
            break;
        case 1:
            if (gMultiSelectMember->mStartPending != FALSE) {
                gMultiSelectMember->mStartPending = FALSE;
                gMultiSelectMember->mSetupState = 3;
                gMultiSelectMember->mTimer = 0x78;
                SetupTxtSystemSubTextEx(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x79), 0, 1, 1, 0, 1);
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[0], 2);
            } else if (gMultiSelectMember->mReturnPending != FALSE) {
                gMultiSelectMember->mReturnPending = FALSE;
                gMultiSelectMember->mSetupState = 7;
            } else {
                AdvanceGameInfoOnChildChange();
            }
            break;
        case 3:
            switch (AdvanceMultiBootParent()) {
                case 1:
                    gMultiSelectMember->mSetupState = 4;
                    break;
                case 2:
                    SetupMultiSelectMemberSubTextButton();
                    break;
            }
            break;
        case 4:
            switch (AdvanceMPStateMachineWithOwnIndex()) {
                case 1:
                    if (gMultiSelectMember->mTimer == 0) {
                        if ((u8) ((gConnectionWork->mParticipantMask & ~gConnectionWork->mGroupSendMask) & 0xfe) != 0) {
                            SetupTxtSystemSubText(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x81));
                            gMultiSelectMember->mTimer = 0x78;
                        } else {
                            RequestTxtSystemClose();
                        }
                        StopSeqZeroLoop();
                        StartCopyOtherEmblems(1);
                        gMultiSelectMember->mSeqZeroLoopStartPending = FALSE;
                        gMultiSelectMember->mSetupState = 6;
                    }
                    break;
                case 2:
                    SetupMultiSelectMemberSubTextButton();
                    break;
            }
            break;
        case 7:
        case 8:
            if (AdvanceConnectionEndStopOnError() == 1) {
                gMultiSelectMember->mSetupState = 11;
            }
            break;
        case 6:
            if (gBackupBuffers->mBusy == 0) {
                if (gBackupAccess->mBackupEnabled != 0) {
                    backupBusy = gBackupAccess->mCommandRunning;
                } else {
                    backupBusy = 0;
                }
            } else {
                backupBusy = 1;
            }
            if (backupBusy == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mSetupState = 11;
            }
            break;
    }
}

void UpdateMultiSelectMemberNoKeySetup(void) {
    s32 backupBusy;

    switch (gMultiSelectMember->mSetupState) {
        case 2:
            if (gMultiSelectMember->mReturnPending != FALSE) {
                gMultiSelectMember->mReturnPending = FALSE;
                gMultiSelectMember->mSetupState = 7;
                return;
            }
            switch (AdvanceConnectByMultiBoot(GetWLMenuSceneScanSlotPick()->mSlotIndex)) {
                case 1:
                    if (gStartupWork->mConnectionKind == 2) {
                        SetMultiSimple((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0 ? 1 : 0);
                    }
                    gMultiSelectMember->mSetupState = 4;
                    if (gMultiSelectMember->mUnk_84 == 0) {
                        gMultiSelectMember->mChildCount = CountMultiSelectChildren();
                        PrintMultiSelectMemberNames();
                        gMultiSelectMember->mUnk_88 = TRUE;
                    }
                    break;
                case 2:
                    SetupMultiSelectMemberSubTextButton();
                    break;
            }
            break;
        case 4:
            if (gMultiSelectMember->mReturnPending != FALSE) {
                gMultiSelectMember->mReturnPending = FALSE;
                gMultiSelectMember->mSetupState = 7;
                return;
            }
            switch (AdvanceMPStateMachineWithOwnIndex()) {
                case 1:
                    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mConnectionNamesDone == FALSE) {
                        PrintMultiSelectConnectionNames();
                        SetMultiSelectChildCountCellsVisible();
                    }
                    if (gMultiSelectMember->mTimer == 0) {
                        SetupTxtSystemSubText(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x81));
                        StopSeqZeroLoop();
                        StartCopyOtherEmblems(1);
                        gMultiSelectMember->mSeqZeroLoopStartPending = FALSE;
                        gMultiSelectMember->mTimer = 0x78;
                        gMultiSelectMember->mSetupState = 6;
                    }
                    break;
                case 2:
                    SetupMultiSelectMemberSubTextButton();
                    break;
            }
            break;
        case 7:
        case 8:
            if (AdvanceConnectionEndStopOnError() == 1) {
                gMultiSelectMember->mSetupState = 11;
            }
            break;
        case 6:
            if (gBackupBuffers->mBusy == 0) {
                if (gBackupAccess->mBackupEnabled != 0) {
                    backupBusy = gBackupAccess->mCommandRunning;
                } else {
                    backupBusy = 0;
                }
            } else {
                backupBusy = 1;
            }
            if (backupBusy == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mSetupState = 11;
            }
            break;
    }
}

void InitMultiSelectMember(void *parentHeap, void *mainOam, void *subOam) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    u32 mainObjSizeLeft;
    s32 index;
    u32 subObjSizeLeft;
    void *heap;
    volatile u32 clearValue;
    const LabelMessageRow *canvasRow;
    const LabelMessageRow *printRow;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectMember = HeapAlloc(heap, 0x154);
    clearValue = 0;
    MIi_CpuClearFast(clearValue, gMultiSelectMember, 0x154);
    gMultiSelectMember->mHeap = heap;
    gMultiSelectMember->mMainOam = mainOam;
    gMultiSelectMember->mSubOam = subOam;
    gMultiSelectMember->mBannerMessages = FindSceneFile("banner.bmg");
    gMultiSelectMember->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gMultiSelectMember->mResult = -1;
    mainObjSizeLeft = GX_GetSizeOfOBJ();
    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    LocateCellFileSet(mainFileSet, "multi_select_member_m.nce.ncgr", "multi_select_member_m.nce.ncer",
                      "multi_select_member_m_o.NCLR", "multi_select_member_m.bncl", "multi_select_member_m.bnll", NULL,
                      FindSceneFile);
    SetupCellFileSet(0, gMultiSelectMember->mHeap, mainFileSet);
    index = 0;
    canvasRow = gMultiSelectMemberMainLabelRows;
    printRow = canvasRow;
    for (; index < 2; index++) {
        mainObjSizeLeft -= SetupLabelCanvas(0, gMultiSelectMember->mHeap, mainFileSet, canvasRow, mainObjSizeLeft);
        PrintLabelLayoutTextNoFixedAdvance(0, printRow->mLabelIndex, mainFileSet->mLabelLayout,
                                           GetBmgEntry(gMultiSelectMember->mBannerMessages, printRow->mMessageIndex),
                                           mainFileSet->mCellLayout, mainFileSet->mCellTable);
        canvasRow++;
        printRow++;
    }
    SetMultiSelectChildCountCellsVisible();
    LocateAndQueueScreenMapFileSet(1, gMultiSelectMember, "multi_select_member_s_b.NCGR",
                                   "multi_select_member_s_b.NCLR", "multi_select_member_s_register.NSCR", 3,
                                   FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    LocateCellFileSet(subFileSet, "multi_select_member_register_s.nce.ncgr", "multi_select_member_register_s.nce.ncer",
                      "multi_select_member_register_s_o.NCLR", "multi_select_member_s_register.bncl",
                      "multi_select_member_s_register.bnll", "multi_select_member_s_register.bnbl", FindSceneFile);
    SetupCellFileSet(1, gMultiSelectMember->mHeap, subFileSet);
    for (index = 0; index < 9; index++) {
        subObjSizeLeft -= SetupLabelCanvas(1, gMultiSelectMember->mHeap, subFileSet,
                                           &gMultiSelectMemberSubLabelRows.mRows[index], subObjSizeLeft);
    }
    SetupInterpolation(&gMultiSelectMember->mInterpolations[3], 3, 10, 0x40, 0);
    InitPaletteBlend(gMultiSelectMember->mHeap, subFileSet->mPalette, 3);
    SetMultiSelectMemberSubCellVisible(1);
    SetupInterpolation(&gMultiSelectMember->mInterpolations[0], 0, 10, -0x40, 0);
    SetupInterpolation(&gMultiSelectMember->mInterpolations[1], 0, 10, 0x40, 0);
    SetupInterpolation(&gMultiSelectMember->mInterpolations[2], 0, 10, -0xc0, 0);
    gMultiSelectMember->mRows[0].mState = 2;
    for (index = 0; index < 8; index++) {
        gMultiSelectMember->mRows[index].mFirstCellIndex = index * 2;
        gMultiSelectMember->mRows[index].mSecondCellIndex = index * 2 + 1;
    }
    SetTxtSystemBgOffsetRequested(0x20, 0);
}

void InitMultiSelectMemberKeyStart(void *parentHeap, void *mainOam, void *subOam) {
    CellFileSet *subFileSet;
    u16 nameBuffer[11];

    InitMultiSelectMember(parentHeap, mainOam, subOam);
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    MIi_CpuCopy16(gBackupBuffers->mFirstBlock->mPlayerName, nameBuffer, 0x14);
    nameBuffer[10] = 0;
    PrintLabelLayoutTextNoFixedAdvance(1, gMultiSelectMemberSubLabelRows.mRows[0].mLabelIndex, subFileSet->mLabelLayout,
                                       nameBuffer, subFileSet->mCellLayout, subFileSet->mCellTable);
    PrintLabelLayoutTextNoFixedAdvance(
        1, gMultiSelectKeyStartLabelData[16], subFileSet->mLabelLayout,
        GetBmgEntry(gMultiSelectMember->mBannerMessages, gMultiSelectMemberSubLabelRows.mRows[8].mMessageIndex),
        subFileSet->mCellLayout, subFileSet->mCellTable);
    gStartupWork->mConnectionKind = 1;
    SetupTxtSystemMainTextEx(GetBmgEntry(gMultiSelectMember->mBannerMessages, 9), 0, 0, 1, 0, 0, 0);
    subFileSet->mCellTable[0x11].mVisible = 0;
    subFileSet->mCellTable[0x10].mVisible = subFileSet->mCellTable[0x11].mVisible;
    SetSelectReturnSoundId(-1);
    FrmHeapShrinkInParent(gMultiSelectMember->mHeap);
}

void InitMultiSelectMemberNoKeyStart(void *parentHeap, void *mainOam, void *subOam) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    u16 nameBuffer[12];
    s32 count;
    s32 mainCellCount;
    s32 subLabelCount;
    s32 subCellCount;
    s32 index;
    void *bannerMessage;

    InitMultiSelectMember(parentHeap, mainOam, subOam);
    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    gMultiSelectMember->mSetupState = 2;
    gMultiSelectMember->mUnk_84 = IsScanSlotMultiBoot(GetWLMenuSceneScanSlotPick()->mSlotIndex);
    nameBuffer[0] = 0;
    MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
    if (gMultiSelectMember->mUnk_84 == 0 &&
        TryGetScanSlotName(GetWLMenuSceneScanSlotPick()->mSlotIndex, &nameBuffer[1]) != 0) {
        nameBuffer[11] = 0;
        PrintLabelLayoutTextNoFixedAdvance(1, gMultiSelectMemberSubLabelRows.mRows[0].mLabelIndex,
                                           subFileSet->mLabelLayout, &nameBuffer[1], subFileSet->mCellLayout,
                                           subFileSet->mCellTable);
        gMultiSelectMember->mNameLabelDone = TRUE;
    }
    subFileSet->mCellTable[0x11].mVisible = 0;
    subFileSet->mCellTable[0x10].mVisible = subFileSet->mCellTable[0x11].mVisible;
    bannerMessage = GetBmgEntry(gMultiSelectMember->mBannerMessages, 10);
    if (gMultiSelectMember->mUnk_84 != 0) {
        SetupTxtSystemSubTextEx(bannerMessage, 0, 0, 1, 0, 1);
    } else {
        SetupTxtSystemMainTextEx(bannerMessage, 0, 0, 1, 0, 0, 0);
    }
    if (gMultiSelectMember->mUnk_84 != 0) {
        count = mainFileSet->mLabelLayout->mCount;
        mainCellCount = mainFileSet->mCellLayout->mCount;
        subLabelCount = subFileSet->mLabelLayout->mCount;
        subCellCount = subFileSet->mCellLayout->mCount;
        index = 0;
        mainFileSet->mCellTable[0xb].mVisible = 0;
        mainFileSet->mCellTable[0xa].mVisible = mainFileSet->mCellTable[0xb].mVisible;
        mainFileSet->mCellTable[9].mVisible = mainFileSet->mCellTable[0xa].mVisible;
        mainFileSet->mCellTable[8].mVisible = mainFileSet->mCellTable[9].mVisible;
        mainFileSet->mCellTable[7].mVisible = mainFileSet->mCellTable[8].mVisible;
        mainFileSet->mCellTable[6].mVisible = mainFileSet->mCellTable[7].mVisible;
        mainFileSet->mCellTable[5].mVisible = mainFileSet->mCellTable[6].mVisible;
        mainFileSet->mCellTable[4].mVisible = mainFileSet->mCellTable[5].mVisible;
        mainFileSet->mCellTable[3].mVisible = mainFileSet->mCellTable[4].mVisible;
        for (index = 0; index < 8; index++) {
            subFileSet->mCellTable[gMultiSelectMember->mRows[index].mSecondCellIndex].mVisible = 0;
            subFileSet->mCellTable[gMultiSelectMember->mRows[index].mFirstCellIndex].mVisible =
                subFileSet->mCellTable[gMultiSelectMember->mRows[index].mSecondCellIndex].mVisible;
        }
        for (index = 0; index < count; index++) {
            mainFileSet->mCellTable[index + mainCellCount].mVisible = 0;
        }
        index = 0;
        count = subCellCount + subLabelCount;
        for (; index < count; index++) {
            subFileSet->mCellTable[index].mVisible = 0;
        }
    }
    SetSelectReturnSoundId(-1);
    FrmHeapShrinkInParent(gMultiSelectMember->mHeap);
}

#pragma thumb off

#pragma thumb on

BOOL MultiSelectMemberIsSubSlideInDone(void) {
    if (gMultiSelectMember->mInterpolations[2].mState == 1) {
        return 1;
    }
    return 0;
}

BOOL MultiSelectMemberIsSubSlideOutDone(void) {
    if (gMultiSelectMember->mInterpolations[2].mState == 3) {
        return 1;
    }
    return 0;
}

void DrawMultiSelectMember(void) {
    int screenIndex;
    CellFileSet *cellFileSet;
    if (gMultiSelectMember->mState != 6) {
        screenIndex = 0;
        do {
            cellFileSet = &gMultiSelectMember->mCellFileSets[screenIndex];
            DrawLayoutTable(cellFileSet->mCellLayout, cellFileSet->mCells, cellFileSet->mLabelLayout,
                            (&gMultiSelectMember->mMainOam)[screenIndex], cellFileSet->mCellTable);
            screenIndex++;
        } while (screenIndex < 2);
    }
}

#pragma thumb off

#pragma thumb on

s32 AdvanceMultiSelectMemberKeyStart(SceneNumbers *sceneNumbers) {
    CellFileSet *subFileSet;
    s32 result;
    s32 previousChildCount;
    u16 slotIndex;
    s32 rectIndex;
    s32 touchInReturnRect;
    u32 pairIsNew;
    u32 pairRecentlyGone;
    u32 hasPair;
    s32 value;
    s32 pairY;

    result = -1;
    slotIndex = GetPadInputSlot();
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    previousChildCount = gMultiSelectMember->mChildCount;
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    UpdateMultiSelectMemberKeySetup();
    if (gMultiSelectMember->mState != 0 && gMultiSelectMember->mState != 3 && gMultiSelectMember->mState != 4 &&
        gMultiSelectMember->mState != 5 && gMultiSelectMember->mState != 6) {
        if (gConnectionWork == NULL) {
            value = 0;
        } else {
            value = gConnectionWork->mConnectionMode;
        }
        if (value == 1) {
            if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                value = gConnectionWork->mWaitToSendCount;
            } else {
                value = gConnectionWork->mChildren.mChildCount;
            }
        } else {
            value = 0;
        }
        gMultiSelectMember->mChildCount = value;
        if (gMultiSelectMember->mChildCount != previousChildCount) {
            PrintMultiSelectMemberNames();
            if (gMultiSelectMember->mChildCount > previousChildCount) {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
                NNS_SndArcSetCurrent(&gFileSndArc);
            } else {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 3);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
        }
    }
    SetMultiSelectChildCountCellsVisible();
    UpdateMultiSelectMemberCells();
    AdvancePaletteBlend();
    if (gMultiSelectMember->mSeqZeroLoopStartPending != FALSE) {
        gMultiSelectMember->mSeqZeroLoopStartFrames = gMultiSelectMember->mSeqZeroLoopStartFrames + 1;
        if (gMultiSelectMember->mSeqZeroLoopStartFrames > 0x96) {
            StartSeqZeroLoop();
            gMultiSelectMember->mSeqZeroLoopStartPending = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (MultiSelectMemberIsSubSlideInDone() != 0) {
                gMultiSelectMember->mState = 1;
                subFileSet->mCellTable[0x10].mVisible = 1;
                SetMultiSelectMemberSubCellVisible(1);
            }
            break;
        case 1:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = 0;
            pairRecentlyGone = 0;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyGone = 1;
            }
            if (pairRecentlyGone == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairIsNew = 1;
            }
            if (pairIsNew != 0) {
                value = gInputSlots[slotIndex].mPair.mPairX;
                pairY = gInputSlots[slotIndex].mPair.mPairY;
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(value, pairY);
                rectIndex = RectTableFindContaining(subFileSet->mRects, value, pairY);
            }
            if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 || rectIndex == 0) {
                if (gMultiSelectMember->mChildCount > 0 && gMultiSelectMember->mInterpolations[3].mState == 1) {
                    SetMultiSelectMemberSubCellVisible(0);
                    RequestSelectReturnState4();
                    StopPaletteBlend();
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 6);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gMultiSelectMember->mStartPending = TRUE;
                    gMultiSelectMember->mSeqZeroLoopStartPending = TRUE;
                    gMultiSelectMember->mState = 2;
                    break;
                }
            }
            if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectMember->mResult = 1;
                gMultiSelectMember->mState = 3;
                gMultiSelectMember->mReturnPending = TRUE;
                RequestTxtSystemClose();
                RequestSelectReturnState3WithSound(0);
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
            break;
        case 2:
            gMultiSelectMember->mState2Frames = gMultiSelectMember->mState2Frames + 1;
            if (gMultiSelectMember->mState2Frames >= 5) {
                SetMultiSelectMemberSubCellVisible(1);
                if (gMultiSelectMember->mSetupState == 11) {
                    gMenuShared->mRaceSetupRequested = 1;
                    gMenuShared->mMenuEntryKind = 4;
                    if (sceneNumbers != NULL) {
                        sceneNumbers->mNextScene = 1;
                    }
                    gMultiSelectMember->mState2Frames = 0;
                    gMultiSelectMember->mState = 7;
                }
            }
            break;
        case 5:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                RequestTxtSystemClose();
                gMultiSelectMember->mResult = 0;
                gMultiSelectMember->mState = 3;
            }
            break;
        case 3:
            if (gMultiSelectMember->mSetupState == 11) {
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[0], 2);
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (MultiSelectMemberIsSubSlideOutDone() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            result = gMultiSelectMember->mResult;
            break;
    }
    DrawMultiSelectMember();
    return result;
}

s32 AdvanceMultiSelectMemberNoKeyStart(SceneNumbers *sceneNumbers) {
    CellFileSet *subFileSet;
    s32 result;
    s32 touchInReturnRect;
    s32 previousChildCount;
    u16 slotIndex;
    u16 nameBuffer[12];
    BOOL flag;
    u32 pairIsNew;
    u32 pairRecentlyGone;
    u32 hasPair;
    s32 started;

    result = -1;
    slotIndex = GetPadInputSlot();
    touchInReturnRect = 0;
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    UpdateMultiSelectMemberNoKeySetup();
    previousChildCount = gMultiSelectMember->mChildCount;
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mConnectionNamesDone == FALSE) {
        gMultiSelectMember->mChildCount = CountMultiSelectChildren();
        if (gMultiSelectMember->mChildCount != previousChildCount) {
            PrintMultiSelectMemberNames();
            if (gMultiSelectMember->mUnk_88 == FALSE) {
                if (gMultiSelectMember->mChildCount > previousChildCount) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                } else if (gMultiSelectMember->mChildCount < previousChildCount) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 3);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
                gMultiSelectMember->mUnk_88 = FALSE;
            }
        }
        SetMultiSelectChildCountCellsVisible();
    }
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mNameLabelDone == FALSE) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (TryGetScanSlotName(GetWLMenuSceneScanSlotPick()->mSlotIndex, &nameBuffer[1]) != 0) {
            nameBuffer[11] = 0;
            PrintLabelLayoutTextNoFixedAdvance(1, gMultiSelectMemberSubLabelRows.mRows[0].mLabelIndex,
                                               subFileSet->mLabelLayout, &nameBuffer[1], subFileSet->mCellLayout,
                                               subFileSet->mCellTable);
            gMultiSelectMember->mNameLabelDone = TRUE;
        }
    }
    UpdateMultiSelectMemberCells();
    if (gMultiSelectMember->mSeqZeroLoopStartPending != FALSE) {
        gMultiSelectMember->mSeqZeroLoopStartFrames = gMultiSelectMember->mSeqZeroLoopStartFrames + 1;
        if (gMultiSelectMember->mSeqZeroLoopStartFrames > 0x96) {
            StartSeqZeroLoop();
            gMultiSelectMember->mSeqZeroLoopStartPending = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (MultiSelectMemberIsSubSlideInDone() != 0) {
                gMultiSelectMember->mState = 1;
            }
            break;
        case 1:
            pairIsNew = 0;
            pairRecentlyGone = 0;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyGone = 1;
            }
            if (pairRecentlyGone == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairIsNew = 1;
            }
            if (pairIsNew != 0) {
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(
                    gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY);
            }
            started = gMultiSelectMember->mStarted;
            if (started == 0) {
                switch (gConnectionWork->mState) {
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        flag = TRUE;
                        break;
                    default:
                        flag = FALSE;
                        break;
                }
                if (flag != FALSE) {
                    RequestSelectReturnState4();
                    SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[0], 2);
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 6);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gMultiSelectMember->mSeqZeroLoopStartPending = TRUE;
                    gMultiSelectMember->mStarted = 1;
                    break;
                }
            }
            if (gMultiSelectMember->mSetupState == 11) {
                gMenuShared->mRaceSetupRequested = 1;
                gMenuShared->mMenuEntryKind = 4;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 1;
                }
                gMultiSelectMember->mState = 7;
            } else if (started == 0) {
                if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                    gMultiSelectMember->mResult = 0;
                    gMultiSelectMember->mState = 3;
                    gMultiSelectMember->mReturnPending = TRUE;
                    RequestTxtSystemClose();
                    RequestSelectReturnState3WithSound(0);
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 3);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
            }
            break;
        case 5:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gMultiSelectMember->mResult = 0;
                gMultiSelectMember->mState = 3;
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (gMultiSelectMember->mSetupState == 11) {
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[0], 2);
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gMultiSelectMember->mInterpolations[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (MultiSelectMemberIsSubSlideOutDone() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            result = gMultiSelectMember->mResult;
            break;
    }
    DrawMultiSelectMember();
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMember(void) {
    SetTxtSystemBgOffsetRequested(0, 0);
    ClearPaletteBlendPointer();
    HeapDestroy(gMultiSelectMember->mHeap);
    *&gMultiSelectMember = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteMultiSelectMemberRegisters(void) {
    s32 displayBits;
    s32 interpolatedValue;

    displayBits = 0x17;
    interpolatedValue = GetInterpolatedValue(&gMultiSelectMember->mInterpolations[2]);
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mState != 6) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-interpolatedValue << 16) & 0x1ff0000;
    if (interpolatedValue != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off

u32 MultiSelectNSGetCellLayoutCount(const void *cellLayout) {
    return (*OFFSET_PTR(const u16, cellLayout, 6));
}

u32 MultiSelectNSGetLabelLayoutCount(const void *labelLayout) {
    return (*OFFSET_PTR(const u16, labelLayout, 6));
}
