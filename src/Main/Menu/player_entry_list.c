#include "Main/Menu/player_entry_list.h"
#include "Main/Menu/data_0202bb80.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Race/race_setup.h"
#include "Main/Graphics/timer_cell_index.h"
#include "Main/Menu/own_entry_position_copy_cell.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/player_record.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/packed_index.h"
#include "Main/Net/wifi_session_karts.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "code_02148950.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/MapObjects/data_0217a000.h"
#include "player.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "gfd_VramTransferManager.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0202056c.h"
#include "registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/message_index.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/select_character.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"

const u16 gTitleCellIndices[4] = {0, 1, 2, 0};
const u16 gNormalTimerDigitCellIndices[10] = {0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38};
const u16 gDownloadTimerDigitCellIndices[10] = {0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37};
const u16 gDownloadCharacterCellIndices[14] = {0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
                                               0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0};
const u16 gNormalCharacterCellIndices[14] = {0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
                                             0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0};
const EntryCellIndices gNormalEntryCellIndices[8] = {{0, 9, 0x11},   {1, 0xa, 0x12}, {2, 0xb, 0x13}, {3, 0xc, 0x14},
                                                     {4, 0xd, 0x15}, {5, 0xe, 0x16}, {6, 0xf, 0x17}, {7, 0x10, 0x18}};
const EntryCellIndices gDownloadEntryCellIndices[8] = {{0, 9, 0x11},   {1, 0xa, 0x12}, {2, 0xb, 0x13}, {3, 0xc, 0x14},
                                                       {4, 0xd, 0x15}, {5, 0xe, 0x16}, {6, 0xf, 0x17}, {7, 0x10, 0x18}};
const EntryLabelTextRow gDownloadEntryLabelTextRows[8] = {
    {0, 0x30, 0xb, 9},   {1, 0x30, 0xb, 0xa}, {2, 0x30, 0xb, 0xb},
    {3, 0x30, 0xb, 0xc}, {4, 0x30, 0xb, 0xd}, {5, 0x30, 0xb, 0xe},
    {6, 0x30, 0xb, 0xf}, {7, 0x30, 0xb, 0x10}};
const EntryLabelTextRow gNormalEntryLabelTextRows[8] = {
    {0, 0x30, 0xb, 9},   {1, 0x30, 0xb, 0xa}, {2, 0x30, 0xb, 0xb},
    {3, 0x30, 0xb, 0xc}, {4, 0x30, 0xb, 0xd}, {5, 0x30, 0xb, 0xe},
    {6, 0x30, 0xb, 0xf}, {7, 0x30, 0xb, 0x10}};
const s16 gEntrySlotOffsetsX[4] = {-96, 0, 0xa0, 0x100};
const EntryLabelTextRow *gEntryLabelTextRows;
const u16 *gCharacterCellIndices;
PlayerEntryList *gPlayerEntryList;
const u16 *gTimerDigitCellIndices;
const EntryCellIndices *gEntryCellIndices;

#pragma thumb on

void SetEntrySlot(s32 entryIndex, s32 slot) {
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mMoveFrames = PLAYER_ENTRY_LIST_MOVE_FRAMES;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mToSlot = slot;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot =
        gPlayerEntryList->mEntries[entryIndex].mSlotMove.mToSlot;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mFromSlot =
        gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot;
}

// Sets the target slot; asking for the slot it came from turns the running move around.
void SetEntryTargetSlot(s32 entryIndex, s32 slot) {
    EntrySlotMove *entry;
    entry = &gPlayerEntryList->mEntries[entryIndex].mSlotMove;
    entry->mTargetSlot = slot;
    if (entry->mTargetSlot == entry->mFromSlot) {
        entry->mFromSlot = entry->mToSlot;
        entry->mToSlot = entry->mTargetSlot;
        entry->mMoveFrames = PLAYER_ENTRY_LIST_MOVE_FRAMES - entry->mMoveFrames;
    }
}

void ResetEntrySlots(void) {
    s32 slotIndex;
    slotIndex = 0;
    do {
        SetEntrySlot(slotIndex, 0);
        SetEntryTargetSlot(slotIndex, PLAYER_ENTRY_SLOT_FIRST_INNER);
        slotIndex++;
    } while (slotIndex < 8);
}

#pragma thumb off

#pragma thumb on

// Moves each entry toward its target slot one slot at a time, each move taking 10 frames.
void AdvanceEntrySlots(void) {
    s32 entryIndex;
    EntrySlotMove *move;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        move = &gPlayerEntryList->mEntries[entryIndex].mSlotMove;
        if (move->mMoveFrames < PLAYER_ENTRY_LIST_MOVE_FRAMES) {
            move->mMoveFrames++;
        } else if (move->mTargetSlot != move->mToSlot) {
            move->mMoveFrames = 0;
            move->mFromSlot = move->mToSlot;
            if (move->mTargetSlot > move->mToSlot) {
                move->mToSlot++;
            } else {
                move->mToSlot--;
            }
        }
    }
}

void SetEntryTargetInnerSlot(s32 entryIndex) {
    switch (gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot) {
        case PLAYER_ENTRY_SLOT_FIRST_OUTER:
            SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_FIRST_INNER);
            break;
        case PLAYER_ENTRY_SLOT_SECOND_OUTER:
            SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_SECOND_INNER);
            break;
    }
}

void SetEntryTargetOuterSlot(s32 entryIndex) {
    switch (gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot) {
        case PLAYER_ENTRY_SLOT_FIRST_INNER:
            SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_FIRST_OUTER);
            break;
        case PLAYER_ENTRY_SLOT_SECOND_INNER:
            SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_SECOND_OUTER);
            break;
    }
}

#pragma thumb off

static inline s32 GetMenuSharedShuffledIndex(s32 index) {
    return gMenuShared->mShuffledIndices[index];
}

#pragma thumb on

void AdvancePlayerEntryListOffsets(void) {
    PlayerEntryList *entryList = gPlayerEntryList;
    CellFileSet *fileSet = &entryList->mParts;
    s32 entryIndex;
    s32 cellCount = fileSet->mCellLayout->mCount;
    s32 onesCell;
    s32 value;
    s16 offsetX;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        AdvanceInterpolation(&gPlayerEntryList->mInterpolations[0]);
        fileSet->mCellTable[25].mOffsetY = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[0]);
        AdvanceInterpolation(&gPlayerEntryList->mInterpolations[3]);
        fileSet->mCellTable[64].mOffsetY = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[3]);
        fileSet->mCellTable[63].mOffsetY = fileSet->mCellTable[64].mOffsetY;
        fileSet->mCellTable[62].mOffsetY = fileSet->mCellTable[63].mOffsetY;
        fileSet->mCellTable[61].mOffsetY = fileSet->mCellTable[62].mOffsetY;
        fileSet->mCellTable[60].mOffsetY = fileSet->mCellTable[61].mOffsetY;
        fileSet->mCellTable[59].mOffsetY = fileSet->mCellTable[60].mOffsetY;
    }
    AdvanceInterpolation(&gPlayerEntryList->mInterpolations[1]);
    offsetX = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[1]);
    onesCell = GetTimerOnesCellIndex();
    fileSet->mCellTable[onesCell].mOffsetX = offsetX;
    fileSet->mCellTable[GetTimerTensCellIndex()].mOffsetX = fileSet->mCellTable[onesCell].mOffsetX;
    AdvanceInterpolation(&gPlayerEntryList->mInterpolations[2]);
    AdvanceEntrySlots();
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        offsetX = InterpolateS16(1, gEntrySlotOffsetsX[gPlayerEntryList->mEntries[entryIndex].mSlotMove.mFromSlot],
                                 gEntrySlotOffsetsX[gPlayerEntryList->mEntries[entryIndex].mSlotMove.mToSlot],
                                 gPlayerEntryList->mEntries[entryIndex].mSlotMove.mMoveFrames, 10);
        fileSet->mCellTable[cellCount + gEntryLabelTextRows[entryIndex].mLabelIndex].mOffsetX = offsetX;
        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mOffsetX =
            fileSet->mCellTable[cellCount + gEntryLabelTextRows[entryIndex].mLabelIndex].mOffsetX;
        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mOffsetX =
            fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mOffsetX;
        fileSet->mCellTable[gEntryCellIndices[entryIndex].mEntryCellIndex].mOffsetX =
            fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mOffsetX;
        if (entryIndex == gPlayerEntryList->mEntryIndex) {
            fileSet->mCellTable[GetOwnEntryPositionCopyCellIndex()].mOffsetX = offsetX;
        }
    }
}

static inline void PlayerEntryListMI_CpuCopy16(const void *source, void *destination, s32 byteCount) {
    MIi_CpuCopy16(source, destination, byteCount);
}

void SetExtraEntryNames(void) {
    void *text = GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), 0x72);
    u16 digitBuffer[3];
    u16 *digitText = &digitBuffer[1];
    s32 entryIndex;
    digitText[0] = 0;
    digitText[1] = 0;
    for (entryIndex = gPlayerEntryList->mPlayerCount; entryIndex < 8; entryIndex++) {
        digitBuffer[0] = 0;
        MIi_CpuClear16(digitBuffer[0], gPlayerEntryList->mEntries[entryIndex].mName, 0x16);
        MIi_CpuCopy16(text, gPlayerEntryList->mEntries[entryIndex].mName, 0x14);
        digitBuffer[1] = entryIndex + 0x31 - gPlayerEntryList->mPlayerCount;
        wcsncat(gPlayerEntryList->mEntries[entryIndex].mName, digitText, 1);
    }
}

void PrintEntryName(s32 entryIndex, u16 *name) {
    PlayerEntryList *entryList = gPlayerEntryList;
    u16 text[12];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x16);
    name[10] = 0;
    CopyTextWithinWidth(name, &text[1]);
    PrintLabelLayoutTextNoFixedAdvance(0, gEntryLabelTextRows[entryIndex].mLabelIndex, entryList->mParts.mLabelLayout,
                                       &text[1], entryList->mParts.mCellLayout, entryList->mParts.mCellTable);
}

void InitPlayerEntryList(void *parentHeap, void *mainOam) {
    void *heap = CreateFrmHeapFromMaxFree(parentHeap);
    s32 objSizeLeft;
    CellFileSet *fileSet;
    s32 entryIndex;
    gPlayerEntryList = HeapAlloc(heap, sizeof(*gPlayerEntryList));
    MemFillWordsByBlock_inline(gPlayerEntryList, 0x258);
    gPlayerEntryList->mHeap = heap;
    gPlayerEntryList->mMainOam = mainOam;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gEntryCellIndices = gDownloadEntryCellIndices;
        gEntryLabelTextRows = gDownloadEntryLabelTextRows;
        gCharacterCellIndices = gDownloadCharacterCellIndices;
        gTimerDigitCellIndices = gDownloadTimerDigitCellIndices;
    } else {
        gEntryCellIndices = gNormalEntryCellIndices;
        gEntryLabelTextRows = gNormalEntryLabelTextRows;
        gCharacterCellIndices = gNormalCharacterCellIndices;
        gTimerDigitCellIndices = gNormalTimerDigitCellIndices;
    }
    objSizeLeft = GX_GetSizeOfOBJ();
    fileSet = &gPlayerEntryList->mParts;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        LocateCellFileSet(fileSet, "mb/select_menu_etc_download_m.nce.ncgr", "mb/select_menu_etc_download_m.nce.ncer",
                          "mb/select_menu_etc_download_m_o.NCLR", "mb/select_menu_etc_download_m.bncl",
                          "mb/select_menu_etc_download_m.bnll", NULL, FindSceneFile);
    } else {
        LocateCellFileSet(fileSet, "select_menu_etc_m.nce.ncgr", "select_menu_etc_m.nce.ncer",
                          "select_menu_etc_m_o.NCLR", "select_menu_etc_m.bncl", "select_menu_etc_m.bnll", NULL,
                          FindFileInLoadedArchives);
    }
    InitLayoutTable(gPlayerEntryList->mHeap, fileSet->mCellLayout, fileSet->mLabelLayout, &fileSet->mCellTable);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        objSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_MAIN, gPlayerEntryList->mHeap, fileSet,
                                        &gEntryLabelTextRows[entryIndex], objSizeLeft);
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = 0;
        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible =
            fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible;
    }
    ResetEntrySlots();
    SetupInterpolation(&gPlayerEntryList->mInterpolations[0], 0, 10, -0x40, 0);
    SetupInterpolation(&gPlayerEntryList->mInterpolations[2], 3, 10, 0x60, 0);
    SetupInterpolation(&gPlayerEntryList->mInterpolations[3], 3, 10, 0x40, 0);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        LocateCellFileSet(&gPlayerEntryList->mTitleParts, "select_menu_etc_title_m.nce.ncgr",
                          "select_menu_etc_title_m.nce.ncer", NULL, "select_menu_etc_title_m.bncl", NULL, NULL,
                          FindFileInLoadedArchives);
    }
    gPlayerEntryList->mSetupRequested = TRUE;
    FrmHeapShrinkInParent(gPlayerEntryList->mHeap);
}

void SetupPlayerEntryList(s32 mode, s32 screenKind) {
    PlayerEntryList *entryList = gPlayerEntryList;
    CellFileSet *fileSet = &entryList->mParts;
    CellFileSet *titleFileSet = &entryList->mTitleParts;
    s32 count;
    s32 index;
    s32 secondIndex;
    BOOL stateActive;
    s32 onesCell;
    vu16 clearValue;
    vu16 secondClearValue;
    u8 screenMapFileSet[0x24];
    entryList->mMode = mode;
    gPlayerEntryList->mScreenKind = screenKind;
    if (gPlayerEntryList->mSetupRequested != FALSE) {
        gPlayerEntryList->mTimer = PLAYER_ENTRY_LIST_TIMER_FRAMES;
        SetupInterpolation(&gPlayerEntryList->mInterpolations[1], 0, 10, 0x40, 0);
        switch (gPlayerEntryList->mMode) {
            case PLAYER_ENTRY_LIST_MODE_NO_CONNECTION:
                gPlayerEntryList->mPlayerCount = 1;
                gPlayerEntryList->mEntryIndex = 0;
                gPlayerEntryList->mShowAllEntries = 1;
                MIi_CpuCopy16(gBackupBuffers->mFirstBlock->mPlayerName,
                              gPlayerEntryList->mEntries[gPlayerEntryList->mEntryIndex].mName, 0x14);
                SetExtraEntryNames();
                break;
            case PLAYER_ENTRY_LIST_MODE_CONNECTION:
                stateActive = TRUE;
                if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
                    gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
                    stateActive = FALSE;
                }
                if (stateActive != FALSE) {
                    index = CountSetBits(gConnectionWork->mParticipantMask);
                } else {
                    index = 0;
                }
                gPlayerEntryList->mPlayerCount = (u8) index;
                if (gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD) {
                    index = gConnectionWork->mOwnIndex;
                } else {
                    index = 0;
                }
                gPlayerEntryList->mEntryIndex = GetParticipantPosByIndex(index)->mEntryIndex;
                for (secondIndex = 0; secondIndex < (count = gPlayerEntryList->mPlayerCount); secondIndex++) {
                    GetRaceSetupCopy()->mEntries[secondIndex].mPlayerKind = PLAYER_KIND_HUMAN;
                    clearValue = 0;
                    MIi_CpuClear16(clearValue, gPlayerEntryList->mEntries[secondIndex].mName, 0x16);
                    PlayerEntryListMI_CpuCopy16(
                        GetParticipantIndexByPos(secondIndex) == 0xffff
                            ? (void *) 0
                            : &gConnectionWork->mPlayerRecords[GetParticipantIndexByPos(secondIndex)],
                        gPlayerEntryList->mEntries[secondIndex].mName, 0x14);
                }
                for (; count < 8; count++) {
                    SetEntryTargetSlot(count, PLAYER_ENTRY_SLOT_FIRST_OUTER);
                }
                SetExtraEntryNames();
                for (index = 0; index < 8; index++) {
                    gPlayerEntryList->mKartShown[index] = 0;
                    gPlayerEntryList->mCharacterShown[index] = gPlayerEntryList->mKartShown[index];
                }
                break;
            case PLAYER_ENTRY_LIST_MODE_WIFI_SESSION:
                gPlayerEntryList->mPlayerCount = GetSessionKartCount();
                gPlayerEntryList->mEntryIndex = GetRaceSetupCopyEntryIndex();
                for (index = 0; index < (count = gPlayerEntryList->mPlayerCount); index++) {
                    secondClearValue = 0;
                    MIi_CpuClear16(secondClearValue, gPlayerEntryList->mEntries[index].mName, 0x16);
                    if (GetIndexOfPackedIndex(index) >= 0) {
                        PlayerEntryListMI_CpuCopy16(GetPlayerRecordName((u8) GetIndexOfPackedIndex(index)),
                                                    gPlayerEntryList->mEntries[index].mName, 0x14);
                    }
                }
                for (; count < 8; count++) {
                    SetEntryTargetSlot(count, PLAYER_ENTRY_SLOT_FIRST_OUTER);
                }
                for (index = 0; index < 4; index++) {
                    gPlayerEntryList->mEmptySlotSoundPlayed[index] = 0;
                }
                for (index = 0; index < 8; index++) {
                    gPlayerEntryList->mKartShown[index] = 0;
                    gPlayerEntryList->mCharacterShown[index] = gPlayerEntryList->mKartShown[index];
                }
                break;
        }
    }
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        for (index = 0; index < 8; index++) {
            fileSet->mCellTable[gEntryCellIndices[index].mKartCellIndex].mVisible = 0;
        }
        if (gPlayerEntryList->mMode == PLAYER_ENTRY_LIST_MODE_CONNECTION) {
            for (index = gPlayerEntryList->mPlayerCount; index < 8; index++) {
                secondIndex = GetRaceSetupCopy()->mEntries[index].mCharacterIndex;
                CopyCellLayoutEntryCellIndex(gEntryCellIndices[index].mCharacterCellIndex,
                                             gCharacterCellIndices[secondIndex], fileSet->mCellLayout);
                fileSet->mCellTable[gEntryCellIndices[index].mCharacterCellIndex].mVisible = 1;
            }
        }
        reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0xd08;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0xc00;
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, screenMapFileSet, "mb/select_menu_etc_download_m_b.NCGR",
                                           "mb/select_menu_etc_download_m_b.NCLR",
                                           "mb/select_menu_etc_download_m_bg_00.NSCR", 0, FindSceneFile);
            LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, screenMapFileSet, "mb/select_menu_etc_download_m_b.NCGR",
                                           "mb/select_menu_etc_download_m_b.NCLR",
                                           "mb/select_menu_etc_download_m_bg_01.NSCR", 1, FindSceneFile);
        } else {
            LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, screenMapFileSet, "select_menu_etc_m_b.NCGR",
                                           "select_menu_etc_m_b.NCLR", "select_menu_etc_m_bg_00.NSCR", 0,
                                           FindFileInLoadedArchives);
            LocateAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, screenMapFileSet, "select_menu_etc_m_b.NCGR",
                                           "select_menu_etc_m_b.NCLR", "select_menu_etc_m_bg_01.NSCR", 1,
                                           FindFileInLoadedArchives);
        }
    } else if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_KART) {
        SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[3], INTERPOLATION_STATE_RISING);
    }
    if (gPlayerEntryList->mMoveInnerPending != FALSE) {
        for (index = 0; index < 8; index++) {
            if (index < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                SetEntryTargetInnerSlot(index);
            }
        }
        gPlayerEntryList->mMoveInnerPending = FALSE;
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, 0, gPlayerEntryList->mParts.mChars->mData,
                                       gPlayerEntryList->mParts.mChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0, fileSet->mPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1c0,
                                       fileSet->mPalette->mBytes + 0x1c0, 0x40);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        QueueCellChars(gTitleCellIndices[gPlayerEntryList->mScreenKind], titleFileSet->mCells, titleFileSet->mChars,
                       titleFileSet->mCellLayout, 0, 0x19, fileSet->mCells, fileSet->mCellLayout);
        SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], INTERPOLATION_STATE_RISING);
    }
    CopyCellLayoutEntryPosition(GetOwnEntryPositionCopyCellIndex(),
                                gEntryCellIndices[gPlayerEntryList->mEntryIndex].mEntryCellIndex, fileSet->mCellLayout);
    for (index = 0; index < 8; index++) {
        PrintEntryName(index, gPlayerEntryList->mEntries[index].mName);
    }
    SetupInterpolation(&gPlayerEntryList->mInterpolations[2], 3, 10, 0x60, 0);
    gPlayerEntryList->mUseTeams = 0;
    count = 0;
    if (gPlayerEntryList->mScreenKind != PLAYER_ENTRY_LIST_RACE_RULE &&
        gPlayerEntryList->mMode != PLAYER_ENTRY_LIST_MODE_NO_CONNECTION) {
        count = 1;
    }
    gPlayerEntryList->mTimerEnabled = count;
    onesCell = GetTimerOnesCellIndex();
    fileSet->mCellTable[onesCell].mVisible = gPlayerEntryList->mTimerEnabled;
    fileSet->mCellTable[GetTimerTensCellIndex()].mVisible = fileSet->mCellTable[onesCell].mVisible;
    gPlayerEntryList->mSetupRequested = FALSE;
}

void AdvancePlayerEntryList(void) {
    CellFileSet *fileSet = &gPlayerEntryList->mParts;
    PlayerEntryList *entryList;
    s32 entryIndex;
    s32 frames;
    s32 framesAhead;
    s32 counter;
    s32 value;
    s32 kartIndex;
    s32 wiFiSessionKartIndex;
    BOOL hasKart;
    if (AreBrightnessFadesClear() == 0) {
        return;
    }
    if (gPlayerEntryList->mTimerEnabled != 0) {
        if (gPlayerEntryList->mTimer != 0) {
            gPlayerEntryList->mTimer--;
            frames = gPlayerEntryList->mTimer;
            framesAhead = frames + 0x3c;
            counter = framesAhead / 0x3c;
            if (frames == 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x51);
            } else if (framesAhead % 0x3c == 0 && counter <= 4) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x50);
            }
        } else {
            counter = 0;
        }
        value = GetTimerTensCellIndex();
        fileSet->mCellTable[value].mVisible = counter >= 10 ? 1 : 0;
        value = GetTimerTensCellIndex();
        CopyCellLayoutEntryCellIndex(value, gTimerDigitCellIndices[counter / 10 % 10], fileSet->mCellLayout);
        value = GetTimerOnesCellIndex();
        CopyCellLayoutEntryCellIndex(value, gTimerDigitCellIndices[counter % 10], fileSet->mCellLayout);
    }
    entryList = gPlayerEntryList;
    if (entryList->mScreenKind != PLAYER_ENTRY_LIST_RACE_RULE) {
        switch (entryList->mMode) {
            case PLAYER_ENTRY_LIST_MODE_NO_CONNECTION: {
                s32 entryCharacter;
                s32 kartStored;

                for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                    entryCharacter = GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex;
                    if (entryCharacter == -1) {
                        value = 0;
                    } else {
                        value = 1;
                    }
                    kartStored = GetRaceSetupCopy()->mEntries[entryIndex].mKartStored;
                    if (value != 0) {
                        CopyCellLayoutEntryCellIndex(gEntryCellIndices[entryIndex].mCharacterCellIndex,
                                                     gCharacterCellIndices[entryCharacter], fileSet->mCellLayout);
                    }
                    fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible = value;
                    fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = kartStored;
                }
            } break;
            case PLAYER_ENTRY_LIST_MODE_CONNECTION: {
                s32 sharedCharacter;

                for (entryIndex = 0; entryIndex < gPlayerEntryList->mPlayerCount; entryIndex++) {
                    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED &&
                        (gConnectionWork->mParticipantMask & (1 << GetParticipantIndexByPos(entryIndex))) != 0) {
                        counter =
                            gConnectionWork->mSharingReceiveRecords[GetParticipantIndexByPos(entryIndex)].mSendByte;
                    } else {
                        counter = 0;
                    }
                    if (counter == 0xff) {
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = 0;
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible =
                            fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible;
                        GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex = -1;
                        GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex = -1;
                        GetRaceSetupCopy()->mEntries[entryIndex].mKartStored = 0;
                        gPlayerEntryList->mKartShown[entryIndex] = 0;
                        gPlayerEntryList->mCharacterShown[entryIndex] = gPlayerEntryList->mKartShown[entryIndex];
                    } else if ((counter & 0x40) != 0) {
                        sharedCharacter = counter & 0x3f;
                        if (sharedCharacter == 0xc) {
                            CopyCellLayoutEntryCellIndex(gEntryCellIndices[entryIndex].mCharacterCellIndex,
                                                         gCharacterCellIndices[sharedCharacter] +
                                                             GetMenuSharedShuffledIndex(entryIndex),
                                                         fileSet->mCellLayout);
                        } else {
                            CopyCellLayoutEntryCellIndex(gEntryCellIndices[entryIndex].mCharacterCellIndex,
                                                         gCharacterCellIndices[sharedCharacter], fileSet->mCellLayout);
                        }
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible = 1;
                        GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex = sharedCharacter;
                        if (gPlayerEntryList->mEntryIndex != entryIndex &&
                            gPlayerEntryList->mCharacterShown[entryIndex] == 0) {
                            AddCharacterSeqQueueEntry(sharedCharacter, 0);
                            gPlayerEntryList->mCharacterShown[entryIndex] = 1;
                        }
                        if ((counter & 0x80) != 0) {
                            kartIndex = GetCharacterKartIndexByMode(sharedCharacter);
                            fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = 1;
                            GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex = kartIndex;
                            GetRaceSetupCopy()->mEntries[entryIndex].mKartStored = 1;
                        }
                    } else if ((counter & 0x80) != 0) {
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = 1;
                        GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex = counter & 0x3f;
                        GetRaceSetupCopy()->mEntries[entryIndex].mKartStored = 1;
                        if (gPlayerEntryList->mEntryIndex != entryIndex &&
                            gPlayerEntryList->mKartShown[entryIndex] == 0) {
                            AddCharacterSeqQueueEntry(GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex, 1);
                            gPlayerEntryList->mKartShown[entryIndex] = 1;
                        }
                    }
                }
            } break;
            case PLAYER_ENTRY_LIST_MODE_WIFI_SESSION: {
                s32 wifiCharacter;

                for (entryIndex = 0; entryIndex < gPlayerEntryList->mPlayerCount; entryIndex++) {
                    if (GetKartMaskBitOfPackedIndex(entryIndex) == 0) {
                        CopyCellLayoutEntryCellIndex(gEntryCellIndices[entryIndex].mCharacterCellIndex, 0x2e,
                                                     fileSet->mCellLayout);
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible = 1;
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = 0;
                        if (gPlayerEntryList->mEmptySlotSoundPlayed[entryIndex] == 0) {
                            gPlayerEntryList->mEmptySlotSoundPlayed[entryIndex] = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x52);
                        }
                    } else {
                        wifiCharacter = GetWiFiSessionCharacterIndex(GetIndexOfPackedIndex(entryIndex));
                        wiFiSessionKartIndex = GetWiFiSessionKartIndex(GetIndexOfPackedIndex(entryIndex));
                        if (wifiCharacter == -1) {
                            value = 0;
                        } else {
                            value = 1;
                        }
                        if (wiFiSessionKartIndex == -1) {
                            hasKart = FALSE;
                        } else {
                            hasKart = TRUE;
                        }
                        if (value != 0) {
                            CopyCellLayoutEntryCellIndex(gEntryCellIndices[entryIndex].mCharacterCellIndex,
                                                         gCharacterCellIndices[wifiCharacter], fileSet->mCellLayout);
                        }
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mCharacterCellIndex].mVisible = value;
                        fileSet->mCellTable[gEntryCellIndices[entryIndex].mKartCellIndex].mVisible = hasKart;
                        if (gPlayerEntryList->mEntryIndex != entryIndex) {
                            if (gPlayerEntryList->mCharacterShown[entryIndex] == 0 && value != 0) {
                                AddCharacterSeqQueueEntry(wifiCharacter, 0);
                                if (hasKart != FALSE) {
                                    gPlayerEntryList->mKartShown[entryIndex] = 1;
                                }
                            } else if (gPlayerEntryList->mKartShown[entryIndex] == 0 && hasKart != FALSE) {
                                AddCharacterSeqQueueEntry(wifiCharacter, 1);
                            }
                            gPlayerEntryList->mCharacterShown[entryIndex] = value;
                            gPlayerEntryList->mKartShown[entryIndex] = hasKart;
                        }
                    }
                }
            } break;
        }
    }
    AdvancePlayerEntryListOffsets();
    DrawLayoutTable(fileSet->mCellLayout, fileSet->mCells, fileSet->mLabelLayout, gPlayerEntryList->mMainOam,
                    fileSet->mCellTable);
}

#pragma thumb off

#pragma thumb on

void ReleasePlayerEntryList(void) {
    HeapDestroy(gPlayerEntryList->mHeap);
    *&gPlayerEntryList = NULL;
}

#pragma thumb off

#pragma thumb on

void WritePlayerEntryListRegisters(void) {
    u32 displayBits = 0x19;
    BOOL bg0As;
    s16 interpolatedValue;

    interpolatedValue = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[2]);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        bg0As = FALSE;
        displayBits |= 2;
        reg_G2_BG0OFS = interpolatedValue & 0x1ff;
        reg_G2_BG1OFS = -interpolatedValue & 0x1ff;
        reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 3;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    } else {
        bg0As = TRUE;
    }
    if (gPlayerEntryList->mMode == PLAYER_ENTRY_LIST_MODE_WIFI_SESSION) {
        displayBits |= 2;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, bg0As);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        reg_GX_DISPCNT =
            (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
            (REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN0IN_MASK) | 0x1d) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN1IN_MASK) | 0x1e00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0x1c) | 0x20;
        reg_G2_WIN0H = 0x80;
        reg_G2_WIN0V = 0xc0;
        reg_G2_WIN1H = 0x8000;
        reg_G2_WIN1V = 0xc0;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    }
}

void LoadPlayerEntryListFiles(void) {
    Ncgr *chars;
    Nclr *palette;
    NNSG2dCellDataBank *cells;
    Nscr *screenMap;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        LoadNcgrData(&chars, FindSceneFile("mb/select_menu_etc_download_m_b.NCGR"));
        LoadNcgrData2(&chars, FindSceneFile("mb/select_menu_etc_download_m.nce.ncgr"));
        LoadNcerData(&cells, FindSceneFile("mb/select_menu_etc_download_m.nce.ncer"));
        LoadNclrData(&palette, FindSceneFile("mb/select_menu_etc_download_m_o.NCLR"));
        LoadNclrData(&palette, FindSceneFile("mb/select_menu_etc_download_m_b.NCLR"));
        LoadNscrData(&screenMap, FindSceneFile("mb/select_menu_etc_download_m_bg_00.NSCR"));
        LoadNscrData(&screenMap, FindSceneFile("mb/select_menu_etc_download_m_bg_01.NSCR"));
    } else {
        LoadNcgrData(&chars, FindFileInLoadedArchives("select_menu_etc_m_b.NCGR"));
        LoadNcgrData2(&chars, FindFileInLoadedArchives("select_menu_etc_m.nce.ncgr"));
        LoadNcgrData2(&chars, FindFileInLoadedArchives("select_menu_etc_title_m.nce.ncgr"));
        LoadNcerData(&cells, FindFileInLoadedArchives("select_menu_etc_m.nce.ncer"));
        LoadNcerData(&cells, FindFileInLoadedArchives("select_menu_etc_title_m.nce.ncer"));
        LoadNclrData(&palette, FindFileInLoadedArchives("select_menu_etc_m_o.NCLR"));
        LoadNclrData(&palette, FindFileInLoadedArchives("select_menu_etc_m_b.NCLR"));
        LoadNscrData(&screenMap, FindFileInLoadedArchives("select_menu_etc_m_bg_00.NSCR"));
        LoadNscrData(&screenMap, FindFileInLoadedArchives("select_menu_etc_m_bg_01.NSCR"));
    }
}

#pragma thumb off

#pragma thumb on

u32 IsPlayerEntryListTimerZero(void) {
    if (gPlayerEntryList->mTimer == 0) {
        return 1;
    }
    return 0;
}

u32 IsEveryPlayerKartStored(void) {
    u32 allKartsStored;
    int index;
    int offset;
    RaceSetupCopy *setupCopy;
    allKartsStored = 1;
    index = 0;
    if (0 < gPlayerEntryList->mPlayerCount) {
        offset = 0;
        do {
            setupCopy = GetRaceSetupCopy();
            allKartsStored = allKartsStored & setupCopy->mEntries[index].mKartStored;
            offset = offset + 0x18;
            index = index + 1;
        } while (index < gPlayerEntryList->mPlayerCount);
    }
    return allKartsStored;
}

#pragma thumb off

#pragma thumb on

void StartPlayerEntryListKind(s32 kind) {
    s32 entryIndex;

    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], INTERPOLATION_STATE_FALLING);
    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[3], INTERPOLATION_STATE_FALLING);
    SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], INTERPOLATION_STATE_FALLING);
    switch (kind) {
        case 0:
        case 1:
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_FIRST_INNER);
                }
            }
            break;
        case 2:
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[1], INTERPOLATION_STATE_FALLING);
            break;
        case 3:
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                SetEntryTargetOuterSlot(entryIndex);
            }
            gPlayerEntryList->mMoveInnerPending = TRUE;
            break;
    }
}

void SetPlayerEntryListUseTeams(s32 useTeams) {
    s32 entryIndex;
    s32 slot;

    if (gPlayerEntryList->mUseTeams != useTeams) {
        if (useTeams != 0) {
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 0) {
                        slot = 1;
                    } else if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 1) {
                        slot = 2;
                    }
                    SetEntryTargetSlot(entryIndex, slot);
                }
            }
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], INTERPOLATION_STATE_RISING);
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], INTERPOLATION_STATE_FALLING);
        } else {
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (entryIndex < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mShowAllEntries != 0) {
                    SetEntryTargetSlot(entryIndex, PLAYER_ENTRY_SLOT_FIRST_INNER);
                }
            }
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[2], INTERPOLATION_STATE_FALLING);
            SetInterpolationStateIfOpposite(&gPlayerEntryList->mInterpolations[0], INTERPOLATION_STATE_RISING);
        }
    }
    gPlayerEntryList->mUseTeams = useTeams;
}

#pragma thumb off

#pragma thumb on

void SetEntryTeamIndex(int entryIndex, int teamIndex) {
    u32 slot;
    if ((gPlayerEntryList->mUseTeams != 0) && (teamIndex != gPlayerEntryList->mEntries[entryIndex].mTeamIndex)) {
        if (teamIndex == 1) {
            slot = 2;
        } else {
            slot = 1;
        }
        SetEntryTargetSlot(entryIndex, slot);
    }
    gPlayerEntryList->mEntries[entryIndex].mTeamIndex = teamIndex;
}

#pragma thumb off

#pragma thumb on

void SetPlayerEntryListShowAllEntries(s32 showAll) {
    s32 entryIndex;
    s32 slot;
    if (gPlayerEntryList->mShowAllEntries != showAll) {
        if (showAll != 0) {
            for (entryIndex = gPlayerEntryList->mPlayerCount; entryIndex < 8; entryIndex++) {
                if (gPlayerEntryList->mUseTeams != 0) {
                    if (gPlayerEntryList->mEntries[entryIndex].mTeamIndex == 1) {
                        slot = 3;
                    } else {
                        slot = 0;
                    }
                } else {
                    slot = 0;
                }
                SetEntrySlot(entryIndex, slot);
                SetEntryTargetInnerSlot(entryIndex);
            }
        } else {
            for (entryIndex = gPlayerEntryList->mPlayerCount; entryIndex < 8; entryIndex++) {
                SetEntryTargetOuterSlot(entryIndex);
            }
        }
    }
    gPlayerEntryList->mShowAllEntries = showAll;
}

#pragma thumb off

#pragma thumb on
void RequestPlayerEntryListSetup(void) {
    gPlayerEntryList->mSetupRequested = TRUE;
}
#pragma thumb off
