#include "Main/Menu/record_vs_erase.h"
#include "Main/System/heap.h"
#include "Main/Menu/record_list.h"
#include "Main/Menu/data_0215c000.h"
#include "Main/Menu/data_0216d000.h"
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
#include "Main/Graphics/time_format.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "gfd_VramTransferManager.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Kart/kart_model_menu.h"
#include "Main/Menu/record_vs.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Item/item_pool.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/oam.h"
#include "code_0212df7c.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "code_02148950.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u16 gRecordVSEraseRow0MessageIndices[4] = {6, 7, 8, 0};
const u16 gRecordVSEraseGridLabelWidths[3][3] = {{0x70, 0x70, 0x70}, {0x20, 0x20, 0x20}, {0x20, 0x20, 0x20}};
char *gRecordVSSEraseBnblName = "Record_VS_s_erase.bnbl";
char *gRecordVSSEraseBnllName = "Record_VS_s_erase.bnll";
const u16 gRecordVSEraseOffsetCellIndices[2] = {0x20, 0x21};
const u16 gRecordVSEraseRowLabelWidths[6] = {0x78, 0x78, 0x78, 0x78, 0x78, 0};
const s16 gRecordVSEraseRectInputSlots[6] = {0, 1, 2, 3, 4, 0};
char *gRecordVSSEraseNscrName = "Record_VS_s_erase.nscr";
const u16 gRecordVSEraseFriendKeyLabelIndices[12] = {2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd};
const u16 gRecordVSEraseHighlightIndices[6] = {5, 6, 7, 8, 9, 0};
char *gRecordVSSBNclrName = "Record_VS_s_b.nclr";
const u16 gRecordVSEraseFriendKeyWidths[12] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
const u16 gRecordVSEraseUnflaggedObjectIndices[6] = {0x14, 0x15, 0x16, 0x17, 0x18, 0};
const u16 gRecordVSEraseFlaggedObjectIndices[6] = {0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0};
const u16 gRecordVSEraseGridLabelHeights[3][3] = {{0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}, {0xe, 0xe, 0xe}};
char *gRecordVSSBNcgrName = "Record_VS_s_b.ncgr";
const u16 gRecordVSEraseGridLabelIndices[3][3] = {{2, 3, 4}, {5, 7, 9}, {6, 8, 0xa}};
const u16 gRecordVSEraseRowLabelHeights[6] = {0x10, 0x10, 0x10, 0x10, 0x10, 0};
const u16 gRecordVSEraseFlaggedRowIndices[6] = {0xa, 0xb, 0xc, 0xd, 0xe, 0};
char *gRecordVSSEraseBnclName = "Record_VS_s_erase.bncl";
const u16 gRecordVSEraseRowLabelIndices[6] = {0, 1, 2, 3, 4, 0};
const u16 gRecordVSEraseNoOffsetCellIndices[2] = {0x1e, 0x1f};
const u16 gRecordVSEraseUnhighlightedIndices[6] = {0, 1, 2, 3, 4, 0};
const u16 gRecordVSEraseFlaggedHighlightIndices[6] = {0xf, 0x10, 0x11, 0x12, 0x13, 0};
const u16 gRecordVSEraseFriendKeyHeights[12] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
RecordVSErase *gRecordVSErase;

#pragma thumb on

void LocateAndQueueRecordVSErase(void) {
    void *sceneFile;
    Nclr *emblemPalette;
    Ncgr *sbChars;
    Nclr *sbPalette;
    Nscr *eraseScreenMap[2];
    sbChars = NULL;
    sbPalette = NULL;
    eraseScreenMap[0] = NULL;
    sceneFile = FindSceneFile(gRecordVSMNcgrName);
    LocateNcgr2(&gRecordVSErase->mRecordVSMNcgr, sceneFile);
    sceneFile = FindSceneFile(gRecordVSMNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSMNcer, sceneFile);
    sceneFile = FindSceneFile(gRecordVSMBnclName);
    gRecordVSErase->mRecordVSMBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMBnllName);
    gRecordVSErase->mRecordVSMBnll = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMTransientBnclName);
    gRecordVSErase->mRecordVSMTransientBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMTransientBnllName);
    gRecordVSErase->mRecordVSMTransientBnll = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSNcgrName);
    LocateNcgr2(&gRecordVSErase->mRecordVSSNcgr, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSSNcer, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSEraseBnclName);
    gRecordVSErase->mRecordVSSEraseBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSEraseBnblName);
    gRecordVSErase->mRecordVSSEraseBnbl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSEraseBnllName);
    gRecordVSErase->mRecordVSSEraseBnll = sceneFile;
    sceneFile = HeapAlloc(gRecordVSErase->mHeap, (0x00000800u));
    gRecordVSErase->mSecondScreenMapBuffer = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSBNcgrName);
    LocateNcgr(&sbChars, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSEraseNscrName);
    LocateNscr(eraseScreenMap, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSBNclrName);
    LocateNclr(&sbPalette, sceneFile);
    sceneFile = FindSceneFile(gRecordVSM02NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM02Nscr, sceneFile);
    sceneFile = FindSceneFile(gRecordVSM03NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM03Nscr, sceneFile);
    emblemPalette = GetEmblemSBNclr();
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, sbChars->mData, sbChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, eraseScreenMap[0]->mData, eraseScreenMap[0]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, (0x00000800u), gRecordVSErase->mSecondScreenMapBuffer, (0x00000800u));
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, sbPalette->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x40, emblemPalette->mData, 0x20);
}

#pragma thumb off

#pragma thumb on

u16 GetRecordVSEraseFirstRecordIndex(void) {
    return gRecordVSErase->mPageIndex * 5;
}

#pragma thumb off

#pragma thumb on

BOOL IsRecordVSEraseRowFilled(int row) {
    int firstRecordIndex;
    int recordCount;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    recordCount = GetRecordCount();
    if (recordCount > firstRecordIndex + row) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void UpdateRecordVSEraseRows(void) {
    s32 rowIndex;
    s32 eraseCellCount;
    s32 firstRecordIndex;

    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mVisible = 0;
    }
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        if (IsRecordVSEraseRowFilled((s16) rowIndex)) {
            if (gRecordVSErase->mIndex == rowIndex) {
                if (IsRecordFlagged(firstRecordIndex)) {
                    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mVisible = 1;
                    SetLabelPaletteIndex(gRecordVSEraseRowLabelIndices[rowIndex], 0xe,
                                         gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                                         gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mVisible = 1;
                    SetLabelPaletteIndex(gRecordVSEraseRowLabelIndices[rowIndex], 0xe,
                                         gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                                         gRecordVSErase->mRecordVSSEraseBncl);
                }
            } else {
                if (IsRecordFlagged(firstRecordIndex)) {
                    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mVisible = 1;
                    SetLabelPaletteIndex(gRecordVSEraseRowLabelIndices[rowIndex], 0xe,
                                         gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                                         gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mVisible = 1;
                    SetLabelPaletteIndex(gRecordVSEraseRowLabelIndices[rowIndex], 0xf,
                                         gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                                         gRecordVSErase->mRecordVSSEraseBncl);
                }
            }
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mVisible =
                IsRecordFlagged(firstRecordIndex) ? 0 : 1;
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mVisible =
                IsRecordFlagged(firstRecordIndex);
            gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mVisible = 1;
        }
        firstRecordIndex++;
    }
}

void PrintRecordVSEraseShownRecord(void) {
    s32 firstRecordIndex;
    s32 index;
    s32 columnIndex;
    BOOL queueSelector;
    u16 text[0x10];
    u32 counts[3][3] = {0};
    u8 friendKeyText[0x14];
    DateBytes date;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    if (GetRecordFriendKeyText(firstRecordIndex + gRecordVSErase->mShownIndex, friendKeyText)) {
        gRecordVSErase->mTransientDrawn = 1;
        NNS_GfdRegisterNewVramTransferTask(9, 0, gRecordVSErase->mRecordVSM03Nscr->mData,
                                           gRecordVSErase->mRecordVSM03Nscr->mDataSize);
    } else {
        gRecordVSErase->mTransientDrawn = 0;
        NNS_GfdRegisterNewVramTransferTask(9, 0, gRecordVSErase->mRecordVSM02Nscr->mData,
                                           gRecordVSErase->mRecordVSM02Nscr->mDataSize);
    }
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            CopyRecordText(firstRecordIndex + gRecordVSErase->mShownIndex, text, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordVSErase->mRecordVSMBnll, text,
                                               gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
            counts[1][0] = GetRecordMatchKind0FirstCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[1][1] = GetRecordMatchKind1FirstCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[1][2] = GetRecordMatchKind2FirstCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][0] = GetRecordMatchKind0SecondCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][1] = GetRecordMatchKind1SecondCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][2] = GetRecordMatchKind2SecondCount(firstRecordIndex + gRecordVSErase->mShownIndex);
            for (index = 1; index < 3; index++) {
                for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                    if (counts[index][columnIndex] > 0x270f) {
                        counts[index][columnIndex] = 0x270f;
                    }
                }
            }
            FormatAsciiNumber(counts[1][0], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[1][0], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][1], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[1][1], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][2], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[1][2], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][0], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[2][0], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][1], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[2][1], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][2], text);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSEraseGridLabelIndices[2][2], gRecordVSErase->mRecordVSMBnll,
                                             text, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            GetRecordDate(firstRecordIndex + gRecordVSErase->mShownIndex, &date);
            FormatDate(&date, text);
            PrintLabelLayoutTextFixedDigits(0, 0xc, gRecordVSErase->mRecordVSMBnll, text,
                                            gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, 6);
            ReadRecordEmblem(firstRecordIndex + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            NNS_GfdRegisterNewVramTransferTask(
                0x13, GetCellCharIndex(3, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMBncl) << 5,
                gRecordVSErase->mEmblemConverted, 0x200);
            break;
        case 1:
            CopyRecordText(firstRecordIndex + gRecordVSErase->mShownIndex, text, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordVSErase->mRecordVSMTransientBnll, text,
                                               gRecordVSErase->mRecordVSMTransientBncl,
                                               gRecordVSErase->mRecordVSMTransientTable);
            queueSelector = FALSE;
            for (index = 0; index < 12; index++) {
                FormatAsciiNumber(friendKeyText[index] - 0x30, text);
                PrintLabelLayoutTextNoFixedAdvance(
                    queueSelector, gRecordVSEraseFriendKeyLabelIndices[index], gRecordVSErase->mRecordVSMTransientBnll,
                    text, gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
            }
            ReadRecordEmblem(firstRecordIndex + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            NNS_GfdRegisterNewVramTransferTask(
                0x13, GetCellCharIndex(1, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl) << 5,
                gRecordVSErase->mEmblemConverted, 0x200);
            break;
    }
}

void RefreshRecordVSErasePage(void) {
    s32 firstRecordIndex;
    s32 rowIndex;
    u8 nameText[0x20];

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        if (GetRecordCount() > firstRecordIndex + rowIndex) {
            CopyRecordText(firstRecordIndex + rowIndex, nameText, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(
                1, gRecordVSEraseRowLabelIndices[rowIndex], gRecordVSErase->mRecordVSSEraseBnll, nameText,
                gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
        }
    }
    if (GetRecordCount() <= firstRecordIndex + gRecordVSErase->mIndex) {
        gRecordVSErase->mIndex = GetRecordCount() % 5 - 1;
        gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    }
    PrintRecordVSEraseShownRecord();
}

#pragma thumb off

#pragma thumb on
u32 IncrementRecordVSErasePageIndex(void) {
    s32 pageIndex = gRecordVSErase->mPageIndex + 1;
    gRecordVSErase->mPageIndex = pageIndex;
    return pageIndex;
}
#pragma thumb off

#pragma thumb on
u32 DecrementRecordVSErasePageIndex(void) {
    s32 pageIndex = gRecordVSErase->mPageIndex - 1;
    gRecordVSErase->mPageIndex = pageIndex;
    return pageIndex;
}
#pragma thumb off

#pragma thumb on

void IncrementRecordVSEraseIndex(void) {
    int rowFilled;
    int nextIndex;
    nextIndex = (gRecordVSErase->mIndex + 1) * 0x10000 >> 0x10;
    rowFilled = IsRecordVSEraseRowFilled(nextIndex);
    if ((rowFilled == 0) || (5 <= nextIndex)) {
        nextIndex = 0;
    }
    if (gRecordVSErase->mIndex != nextIndex) {
        NNS_SndArcPlayerStartSeqArc((const void *) (((u32) ((u8 *) &gSharedSeqHandle))), 0, 0);
    }
    gRecordVSErase->mIndex = nextIndex;
}

void DecrementRecordVSEraseIndex(void) {
    int rowFilled;
    int recordCount;
    int recordsOnLastPage;
    int previousIndex;
    previousIndex = (gRecordVSErase->mIndex + -1) * 0x10000 >> 0x10;
    if (previousIndex < 0) {
        previousIndex = 4;
        rowFilled = IsRecordVSEraseRowFilled(4);
        if (rowFilled == 0) {
            recordCount = GetRecordCount();
            recordsOnLastPage = (recordCount) % 5;
            previousIndex = (recordsOnLastPage + -1) * 0x10000 >> 0x10;
        }
    }
    if (gRecordVSErase->mIndex != previousIndex) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
    gRecordVSErase->mIndex = previousIndex;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseOffsetTimers(void) {
    s32 firstRecordIndex;
    BOOL hiddenA;
    BOOL hiddenB;
    s32 timerIndex;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseOffsetCellIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordVSErase->mOffsetTimers[0]);
    gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseOffsetCellIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordVSErase->mOffsetTimers[1]);
    hiddenA = FALSE;
    hiddenB = FALSE;
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gRecordVSErase->mOffsetTimers[timerIndex] > 0) {
            gRecordVSErase->mOffsetTimers[timerIndex]--;
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseNoOffsetCellIndices[timerIndex]].mVisible = hiddenA;
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseOffsetCellIndices[timerIndex]].mVisible = 1;
        } else {
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseNoOffsetCellIndices[timerIndex]].mVisible = 1;
            gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseOffsetCellIndices[timerIndex]].mVisible = hiddenB;
        }
    }
    if (firstRecordIndex == 0) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseNoOffsetCellIndices[0]].mVisible = 0;
    }
    if (firstRecordIndex + 5 >= GetRecordCount()) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseNoOffsetCellIndices[1]].mVisible = 0;
    }
}

#pragma thumb off

#pragma thumb on

u32 IsRecordVSEraseIndexChangeRunning(void) {
    if (gRecordVSErase->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseIndexChange(void) {
    s32 mainCellCount;
    s32 transientCellCount;
    s16 offsetY;

    if (IsRecordVSEraseIndexChangeRunning()) {
        if (gRecordVSErase->mIndexChangeTimer == 7) {
            gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
            PrintRecordVSEraseShownRecord();
        } else {
            mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
            transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mCount;
            offsetY = LookupIndexChangeOffset(7 - gRecordVSErase->mIndexChangeTimer, 0);
            gRecordVSErase->mBg0OffsetY = offsetY;
            gRecordVSErase->mRecordVSMTable[3].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTransientTable[1].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetY = offsetY;
        }
        gRecordVSErase->mIndexChangeTimer--;
    } else {
        if (gRecordVSErase->mIndex != 5 && gRecordVSErase->mIndex != gRecordVSErase->mShownIndex) {
            gRecordVSErase->mIndexChangeTimer = 7;
        }
    }
}

void RequestRecordVSEraseState0(void) {
    s32 rowIndex;
    u16 eraseCellCount;

    rowIndex = 0;
    gRecordVSErase->mNextState = 0;
    gRecordVSErase->mStateFrames = 0;
    gRecordVSErase->mBg3Offset = ~0xbf;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = ~0xbf;
    for (; rowIndex < 5; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mOffsetX = 0x100;
    }
    PrintRecordVSEraseShownRecord();
    SetupTxtSystemSubTextButtonEx(GetBmgEntry(gRecordVSErase->mRecordMessages, 4),
                                  GetBmgEntry(gRecordVSErase->mCommonMessages, 6), 0, 1, 1, 1);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseOffsetCellIndices[rowIndex]].mVisible = 0;
    }
}

void RequestRecordVSEraseState1(void) {
    gRecordVSErase->mNextState = 1;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState2(void) {
    gRecordVSErase->mNextState = 2;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
}

void RequestRecordVSEraseState3(void) {
    gRecordVSErase->mNextState = 3;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState1();
    RefreshRecordVSErasePage();
}

void RequestRecordVSEraseState4(void) {
    gRecordVSErase->mNextState = 4;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState5(void) {
    gRecordVSErase->mNextState = 5;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState6(void) {
    gRecordVSErase->mNextState = 6;
    gRecordVSErase->mStateFrames = 0;
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            IncrementRecordVSErasePageIndex();
            break;
        case 1:
            DecrementRecordVSErasePageIndex();
            break;
    }
    RefreshRecordVSErasePage();
}

void RequestRecordVSEraseState7(void) {
    gRecordVSErase->mNextState = 7;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState4();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestRecordVSEraseState8(void) {
    u16 recordName[0x10];
    u16 messageText[0x100];
    u16 firstRecordIndex;

    gRecordVSErase->mNextState = 8;
    gRecordVSErase->mStateFrames = 0;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    CopyRecordText(firstRecordIndex + gRecordVSErase->mIndex, recordName, 0x20);
    FormatMessageWithText(recordName, GetBmgEntry(gRecordVSErase->mRecordMessages, 5), messageText, 0x200);
    SetupTxtSystemSubTextTwoButtonsEx(messageText, GetBmgEntry(gRecordVSErase->mCommonMessages, 0),
                                      GetBmgEntry(gRecordVSErase->mCommonMessages, 1), 1, 0, 1, 1, 1);
}

void RequestRecordVSEraseState9(void) {
    gRecordVSErase->mNextState = 9;
    gRecordVSErase->mStateFrames = 0;
    SetTxtSystemSoundId(0, 0xb);
}

void RequestRecordVSEraseState10(void) {
    gRecordVSErase->mNextState = 0xa;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
    SetTxtSystemSoundId(0, 5);
}

void RequestRecordVSEraseState11(void) {
    gRecordVSErase->mNextState = 0xb;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState1();
    RefreshRecordVSErasePage();
}

void RequestRecordVSEraseState12(void) {
    gRecordVSErase->mNextState = 0xc;
    gRecordVSErase->mStateFrames = 0;
}

void InitRecordVSErase(void *heap) {
    s32 remainingSize;
    const u16 *cellIndexCursor;
    s32 remainingSubSize;
    u16 mainCellCount;
    u16 cellIndex;
    s32 columnIndex;
    s32 index;
    u32 unhighlightedMode;
    u32 highlightMode;
    u32 flaggedRowMode;
    u32 flaggedHighlightMode;
    u32 rowLabelMode;

    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x9810;
    gRecordVSErase = HeapAlloc(heap, 0xa4);
    gRecordVSErase->mHeap = heap;
    gRecordVSErase->mState = 3;
    gRecordVSErase->mPageIndex = GetRecordScenePageIndex();
    gRecordVSErase->mIndex = GetRecordSceneIndex();
    gRecordVSErase->mPageDecrement = 0;
    gRecordVSErase->mIndexChangeTimer = 0;
    gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    gRecordVSErase->mTransientDrawn = 0;
    gRecordVSErase->mErased = 0;
    gRecordVSErase->mPageDecrementRepeat = FALSE;
    gRecordVSErase->mPageIncrementRepeat = FALSE;
    for (index = 0; index < 2; index++) {
        gRecordVSErase->mOffsetTimers[index] = 0;
    }
    LoadEmblemSBNclr(heap);
    LocateAndQueueRecordVSErase();
    InitLayoutTable(heap, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMBnll,
                    &gRecordVSErase->mRecordVSMTable);
    InitLayoutTable(heap, gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientBnll,
                    &gRecordVSErase->mRecordVSMTransientTable);
    InitLayoutTable(heap, gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseBnll,
                    &gRecordVSErase->mRecordVSSEraseTable);
    gRecordVSErase->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gRecordVSErase->mRecordMessages = FindSceneFile("record.bmg");
    remainingSize = 0x8000;
    remainingSize -=
        InitLabelCanvas(heap, 0, gRecordVSErase->mRecordVSMBnll, 0x8c, 0x10, 0, gRecordVSErase->mRecordVSMNcer,
                        gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 1, gRecordVSErase->mRecordVSMBnll, 0xaa, 0xe, 1, gRecordVSErase->mRecordVSMNcer,
                        gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 1, gRecordVSErase->mRecordVSMBnll,
                                       GetBmgEntry(gRecordVSErase->mRecordMessages, 0), gRecordVSErase->mRecordVSMBncl,
                                       gRecordVSErase->mRecordVSMTable);
    remainingSize -=
        InitLabelCanvas(heap, 0xb, gRecordVSErase->mRecordVSMBnll, 0x96, 0xe, 2, gRecordVSErase->mRecordVSMNcer,
                        gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 0xb, gRecordVSErase->mRecordVSMBnll,
                                       GetBmgEntry(gRecordVSErase->mRecordMessages, 1), gRecordVSErase->mRecordVSMBncl,
                                       gRecordVSErase->mRecordVSMTable);
    remainingSize -=
        InitLabelCanvas(heap, 0xc, gRecordVSErase->mRecordVSMBnll, 0x46, 0x10, 3, gRecordVSErase->mRecordVSMNcer,
                        gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    cellIndex = 4;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
    for (index = 0; index < 3; index++) {
        for (columnIndex = 0; columnIndex < 3; columnIndex++) {
            remainingSize -= InitLabelCanvas(
                heap, gRecordVSEraseGridLabelIndices[index][columnIndex], gRecordVSErase->mRecordVSMBnll,
                gRecordVSEraseGridLabelWidths[index][columnIndex], gRecordVSEraseGridLabelHeights[index][columnIndex],
                cellIndex, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMBncl,
                gRecordVSErase->mRecordVSMTable, remainingSize);
            cellIndex = mainCellCount + gRecordVSEraseGridLabelIndices[index][columnIndex];
        }
    }
    for (index = 0; index < 3; index++) {
        PrintLabelLayoutTextNoFixedAdvance(
            0, gRecordVSEraseGridLabelIndices[0][index], gRecordVSErase->mRecordVSMBnll,
            GetBmgEntry(gRecordVSErase->mRecordMessages, gRecordVSEraseRow0MessageIndices[index]),
            gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
    }
    remainingSize -= InitLabelCanvas(heap, 0, gRecordVSErase->mRecordVSMTransientBnll, 0x8c, 0x10, 0,
                                     gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl,
                                     gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    remainingSize -= InitLabelCanvas(heap, 1, gRecordVSErase->mRecordVSMTransientBnll, 0x70, 0x10, 1,
                                     gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl,
                                     gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(
        0, 1, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xb),
        gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    remainingSize -= InitLabelCanvas(heap, 0xe, gRecordVSErase->mRecordVSMTransientBnll, 0xe0, 0x38, 2,
                                     gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl,
                                     gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(
        0, 0xe, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xc),
        gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    for (index = 0; index < 12; index++) {
        remainingSize -=
            InitLabelCanvas(heap, gRecordVSEraseFriendKeyLabelIndices[index], gRecordVSErase->mRecordVSMTransientBnll,
                            gRecordVSEraseFriendKeyWidths[index], gRecordVSEraseFriendKeyHeights[index], index + 3,
                            gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl,
                            gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    }
    remainingSubSize = GX_GetSizeOfSubOBJ();
    for (index = 0, cellIndexCursor = gRecordVSEraseFlaggedHighlightIndices; index < 5; index++) {
        remainingSubSize -=
            InitLabelCanvas(heap, gRecordVSEraseRowLabelIndices[index], gRecordVSErase->mRecordVSSEraseBnll,
                            gRecordVSEraseRowLabelWidths[index], gRecordVSEraseRowLabelHeights[index], *cellIndexCursor,
                            gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl,
                            gRecordVSErase->mRecordVSSEraseTable, remainingSubSize);
        cellIndexCursor++;
    }
    InitLabelCanvas(heap, 5, gRecordVSErase->mRecordVSSEraseBnll, 0xfa, 0x10, 5, gRecordVSErase->mRecordVSSNcer,
                    gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable, remainingSubSize);
    PrintLabelLayoutTextNoFixedAdvance(1, 5, gRecordVSErase->mRecordVSSEraseBnll,
                                       GetBmgEntry(gRecordVSErase->mRecordMessages, 2),
                                       gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
    unhighlightedMode = 0;
    highlightMode = 0;
    flaggedRowMode = 0;
    flaggedHighlightMode = 0;
    rowLabelMode = 0;
    for (index = 0; index < 5; index++) {
        SetCellOamModeXlu(gRecordVSEraseUnhighlightedIndices[index], unhighlightedMode, gRecordVSErase->mRecordVSSNcer,
                          gRecordVSErase->mRecordVSSEraseBncl);
        SetCellOamModeXlu(gRecordVSEraseHighlightIndices[index], highlightMode, gRecordVSErase->mRecordVSSNcer,
                          gRecordVSErase->mRecordVSSEraseBncl);
        SetCellOamModeXlu(gRecordVSEraseFlaggedRowIndices[index], flaggedRowMode, gRecordVSErase->mRecordVSSNcer,
                          gRecordVSErase->mRecordVSSEraseBncl);
        SetCellOamModeXlu(gRecordVSEraseFlaggedHighlightIndices[index], flaggedHighlightMode,
                          gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        SetLabelOamModeXlu(gRecordVSEraseRowLabelIndices[index], rowLabelMode, gRecordVSErase->mRecordVSSEraseBnll,
                           gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
    }
    SetLabelOamModeXlu(5, 0, gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                       gRecordVSErase->mRecordVSSEraseBncl);
    gRecordVSErase->mEmblem = HeapAlloc(heap, 0x201);
    gRecordVSErase->mEmblemConverted = HeapAlloc(heap, 0x200);
    RequestRecordVSEraseState0();
}

void ReleaseRecordVSErase(void) {
    u32 planeBits;

    SetRecordScenePageIndex(gRecordVSErase->mPageIndex);
    SetRecordSceneIndex(gRecordVSErase->mIndex);
    gRecordVSErase = NULL;
    planeBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    planeBits &= ~9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (planeBits << 8);
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState0(void) {
    int isState2NoCloseRequest;
    isState2NoCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (isState2NoCloseRequest != 0) {
        RequestRecordVSEraseState1();
    }
}

void AdvanceRecordVSEraseState1(void) {
    int isDone;
    isDone = GetTxtSystemDone();
    if (isDone != 0) {
        RequestRecordVSEraseState2();
    }
}

void AdvanceRecordVSEraseState2(void) {
    int isState0NoOpenRequest;
    isState0NoOpenRequest = IsTxtSystemState0NoOpenRequest();
    if (isState0NoOpenRequest != 0) {
        RequestRecordVSEraseState3();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState3(void) {
    s16 offsetX;
    u32 offsetY;
    u16 eraseCellCount;
    s32 rowIndex;

    AdvanceRecordVSEraseOffsetTimers();
    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 0xa);
    offsetY = InterpolateS16(1, ~0xbf, 0, gRecordVSErase->mStateFrames, 0xa);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mOffsetX =
            offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState4(void) {
    s32 firstRecordIndex;
    s32 downRectIndex;
    u32 pressedRectIndex;
    InputSlotIndex inputSlotIndex;
    BOOL condition;

    downRectIndex = -1;
    pressedRectIndex = downRectIndex;
    inputSlotIndex = UNK_02175628_INDEX_8;
    AdvanceRecordVSEraseOffsetTimers();
    AdvanceRecordVSEraseIndexChange();
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    condition =
        (gInputSlots[inputSlotIndex].mPair.mHasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) ||
        gInputSlots[inputSlotIndex].mPair.mHasPair != 0;
    if (condition) {
        downRectIndex =
            RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, gInputSlots[inputSlotIndex].mPair.mPairX,
                                    gInputSlots[inputSlotIndex].mPair.mPairY);
    }
    condition =
        !(gInputSlots[inputSlotIndex].mPair.mHasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) &&
        (gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && gInputSlots[inputSlotIndex].mPair.mHasPair != 0);
    if (condition) {
        pressedRectIndex =
            RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, gInputSlots[inputSlotIndex].mPair.mPairX,
                                    gInputSlots[inputSlotIndex].mPair.mPairY);
    }
    if (downRectIndex != 5) {
        gRecordVSErase->mPageDecrementRepeat = FALSE;
    }
    if (downRectIndex != 6) {
        gRecordVSErase->mPageIncrementRepeat = FALSE;
    }
    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_B) != 0 ||
        ((condition = !(gInputSlots[inputSlotIndex].mPair.mHasPair == 0 &&
                        gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) &&
                      (gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 &&
                       gInputSlots[inputSlotIndex].mPair.mHasPair != 0)) &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[inputSlotIndex].mPair.mPairX,
                                                         gInputSlots[inputSlotIndex].mPair.mPairY) != FALSE)) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        RequestRecordVSEraseState12();
        gRecordVSErase->mNextScreen = 3;
        RequestSelectReturnState3WithSound(0);
        return;
    }
    if ((downRectIndex == 5 && gRecordVSErase->mPageDecrementRepeat != FALSE) ||
        (pressedRectIndex == 5 && gRecordVSErase->mPageDecrementRepeat == FALSE) ||
        (u16) (gInputSlots[inputSlotIndex].mBits & PAD_KEY_LEFT) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[30].mVisible == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 1;
        gRecordVSErase->mOffsetTimers[0] = 6;
        gRecordVSErase->mPageDecrementRepeat = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if ((downRectIndex == 6 && gRecordVSErase->mPageIncrementRepeat != FALSE) ||
        (pressedRectIndex == 6 && gRecordVSErase->mPageIncrementRepeat == FALSE) ||
        (u16) (gInputSlots[inputSlotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[31].mVisible == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 0;
        gRecordVSErase->mOffsetTimers[1] = 6;
        gRecordVSErase->mPageIncrementRepeat = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if (pressedRectIndex <= 4) {
        inputSlotIndex = gRecordVSEraseRectInputSlots[pressedRectIndex];
        if (inputSlotIndex == gRecordVSErase->mIndex) {
            if (IsRecordFlagged(firstRecordIndex + inputSlotIndex) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    RequestRecordVSEraseState7();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
            }
            return;
        }
        if (IsRecordVSEraseRowFilled(inputSlotIndex) != 0) {
            gRecordVSErase->mIndex = inputSlotIndex;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else {
        if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
            if (IsRecordFlagged(firstRecordIndex + gRecordVSErase->mIndex) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    RequestRecordVSEraseState7();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
            }
            return;
        }
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            DecrementRecordVSEraseIndex();
            return;
        }
        if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            IncrementRecordVSEraseIndex();
        }
    }
}

void AdvanceRecordVSEraseState5(void) {
    s16 targetOffsetX;
    u16 mainCellCount;
    s32 index;
    u16 transientCellCount;
    u16 eraseCellCount;
    s32 columnIndex;
    s16 offsetX;

    targetOffsetX = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            targetOffsetX = ~0xff;
            break;
        case 1:
            targetOffsetX = 0x100;
            break;
    }
    gRecordVSErase->mStateFrames++;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mCount;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = offsetX;
    gRecordVSErase->mBg1OffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
    for (index = 0; index < 3; index++) {
        for (columnIndex = 0; columnIndex < 3; columnIndex++) {
            gRecordVSErase->mRecordVSMTable[mainCellCount + gRecordVSEraseGridLabelIndices[index][columnIndex]]
                .mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
    for (index = 0; index < 0xc; index++) {
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + gRecordVSEraseFriendKeyLabelIndices[index]]
            .mOffsetX = offsetX;
    }
    for (index = 0; index < 5; index++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[index]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        RequestRecordVSEraseState6();
    }
}

void AdvanceRecordVSEraseState6(void) {
    s16 startOffsetX;
    u16 mainCellCount;
    s32 index;
    u16 transientCellCount;
    u16 eraseCellCount;
    s32 columnIndex;
    s16 offsetX;

    startOffsetX = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            startOffsetX = 0x100;
            break;
        case 1:
            startOffsetX = ~0xff;
            break;
    }
    gRecordVSErase->mStateFrames++;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mCount;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = offsetX;
    gRecordVSErase->mBg1OffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
    for (index = 0; index < 3; index++) {
        for (columnIndex = 0; columnIndex < 3; columnIndex++) {
            gRecordVSErase->mRecordVSMTable[mainCellCount + gRecordVSEraseGridLabelIndices[index][columnIndex]]
                .mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
    for (index = 0; index < 0xc; index++) {
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + gRecordVSEraseFriendKeyLabelIndices[index]]
            .mOffsetX = offsetX;
    }
    for (index = 0; index < 5; index++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[index]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        RequestRecordVSEraseState4();
    }
}

void AdvanceRecordVSEraseState7(void) {
    s16 offsetX;
    u32 offsetY;
    u16 eraseCellCount;
    s32 rowIndex;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 0xa);
    offsetY = InterpolateS16(1, 0, ~0xbf, gRecordVSErase->mStateFrames, 0xa);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mOffsetX =
            offsetX;
    }
    if (gRecordVSErase->mStateFrames > 0xa) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            RequestRecordVSEraseState8();
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState8(void) {
    int noCloseRequest;
    noCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (noCloseRequest != 0) {
        RequestRecordVSEraseState9();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState9(void) {
    u16 firstRecordIndex;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    if (GetTxtSystemDone()) {
        if (GetTxtSystemSelectedIndex() == 0) {
            EraseRecord(firstRecordIndex + gRecordVSErase->mIndex);
            gRecordVSErase->mErased = 1;
        } else {
            gRecordVSErase->mErased = 0;
        }
        RequestRecordVSEraseState10();
    }
}

void AdvanceRecordVSEraseState10(void) {
    s32 index;
    s32 columnIndex;
    s16 offsetX;
    u16 mainCellCount;
    u16 transientCellCount;
    u16 firstRecordIndex;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, -0x100, gRecordVSErase->mStateFrames, 10);
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mCount;
    if (GetRecordCount() != 0 && gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
        for (index = 0; index < 3; index++) {
            for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                gRecordVSErase->mRecordVSMTable[mainCellCount + gRecordVSEraseGridLabelIndices[index][columnIndex]]
                    .mOffsetX = offsetX;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
        for (index = 0; index < 12; index++) {
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount + gRecordVSEraseFriendKeyLabelIndices[index]]
                .mOffsetX = offsetX;
        }
    }
    if (IsTxtSystemState0NoOpenRequest()) {
        firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
        if (GetRecordCount() <= firstRecordIndex) {
            gRecordVSErase->mPageIndex--;
        }
        if (gRecordVSErase->mPageIndex < 0) {
            gRecordVSErase->mNextScreen = 3;
            RequestRecordScreen(gRecordVSErase->mNextScreen);
        } else {
            RequestRecordVSEraseState11();
        }
    }
}

void AdvanceRecordVSEraseState11(void) {
    s32 index;
    s32 columnIndex;
    s16 offsetX;
    s16 offsetY;
    u16 mainCellCount;
    u16 transientCellCount;
    u16 eraseCellCount;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 10);
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordVSErase->mStateFrames, 10);
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mCount;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mCount;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    if (gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
        for (index = 0; index < 3; index++) {
            for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                gRecordVSErase->mRecordVSMTable[mainCellCount + gRecordVSEraseGridLabelIndices[index][columnIndex]]
                    .mOffsetX = offsetX;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
        for (index = 0; index < 12; index++) {
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount + gRecordVSEraseFriendKeyLabelIndices[index]]
                .mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (index = 0; index < 5; index++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[index]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[index]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request()) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState12(void) {
    s32 rowIndex;
    s16 offsetX;
    s16 offsetY;
    u16 eraseCellCount;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordVSErase->mStateFrames, 10);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mCount;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnhighlightedIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedRowIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedHighlightIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseUnflaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[gRecordVSEraseFlaggedObjectIndices[rowIndex]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + gRecordVSEraseRowLabelIndices[rowIndex]].mOffsetX =
            offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 10) {
        RequestRecordScreen(gRecordVSErase->mNextScreen);
    }
}

void AdvanceRecordVSErase(void) {
    gRecordVSErase->mState = gRecordVSErase->mNextState;
    switch (gRecordVSErase->mState) {
        case 0:
            AdvanceRecordVSEraseState0();
            break;
        case 1:
            AdvanceRecordVSEraseState1();
            break;
        case 2:
            AdvanceRecordVSEraseState2();
            break;
        case 3:
            AdvanceRecordVSEraseState3();
            break;
        case 4:
            AdvanceRecordVSEraseState4();
            break;
        case 5:
            AdvanceRecordVSEraseState5();
            break;
        case 6:
            AdvanceRecordVSEraseState6();
            break;
        case 7:
            AdvanceRecordVSEraseState7();
            break;
        case 8:
            AdvanceRecordVSEraseState8();
            break;
        case 9:
            AdvanceRecordVSEraseState9();
            break;
        case 10:
            AdvanceRecordVSEraseState10();
            break;
        case 11:
            AdvanceRecordVSEraseState11();
            break;
        case 12:
            AdvanceRecordVSEraseState12();
            break;
    }
    UpdateRecordVSEraseRows();
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            DrawLayoutTable(gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMNcer,
                            gRecordVSErase->mRecordVSMBnll, GetRecordMainOam(), gRecordVSErase->mRecordVSMTable);
            break;
        case 1:
            DrawLayoutTable(gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMNcer,
                            gRecordVSErase->mRecordVSMTransientBnll, GetRecordMainOam(),
                            gRecordVSErase->mRecordVSMTransientTable);
            break;
    }
    DrawLayoutTable(gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSNcer,
                    gRecordVSErase->mRecordVSSEraseBnll, GetRecordSubOam(), gRecordVSErase->mRecordVSSEraseTable);
}

void WriteRecordVSEraseBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordVSErase->mBg0OffsetX & 0x1ff) | ((-gRecordVSErase->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVSErase->mBg1OffsetX & 0x1ff) | ((-gRecordVSErase->mBg1OffsetY << 16) & 0x1ff0000);
    reg_G2S_DB_BG3OFS = (-gRecordVSErase->mBg3Offset << 16) & 0x1ff0000;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordVSEraseRegisters(void) {
    u32 planeBits;

    planeBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((planeBits | 9) << 8);
}

void RegisterRecordVSEraseCallbacks(void) {
    RecordScreenCallbacks callbacks = {InitRecordVSErase, ReleaseRecordVSErase, AdvanceRecordVSErase,
                                       WriteRecordVSEraseBgOffsets, WriteRecordVSEraseRegisters};

    SetRecordScreenCallbacks(&callbacks);
}

#pragma thumb off
