#include "01/Menu/record_gpx.h"
#include "Main/Menu/record_scene.h"

#include "Main/System/heap.h"
#include "Main/Save/backup_reset.h"
#include "Main/Menu/record_vs.h"
#include "Main/Graphics/layout_rect_table.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/cup_mark.h"
#include "code_02148950.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "01/Menu/code_02194a30.h"

const u16 gRecordGpxCharacterPaletteSlots[4] = {3, 4, 5, 6};
const u16 gRecordGpxKartPaletteSlots[4] = {7, 8, 9, 0xa};
const s32 gRecordGpxRecordIndices[4] = {0, 1, 2, 3};
const u16 gRecordGpxCupTrophyCells[8] = {4, 5, 6, 7, 0, 1, 2, 3};
const s32 gRecordGpxCupFlagIndices[8] = {0x10, 0x10, 3, 7, 0x10, 0x10, 0xb, 0xf};
const u16 gRecordGpxGradeCellIndices[4][3] = {
    {0x18, 0x19, 0x1a}, {0x1b, 0x1c, 0x1d}, {0x1e, 0x1f, 0x20}, {0x21, 0x22, 0x23}};
const u16 gRecordGpxTotalPointsCellIndices[4][3] = {{8, 9, 0xa}, {0xb, 0xc, 0xd}, {0xe, 0xf, 0x10}, {0x11, 0x12, 0x13}};
const u16 gRecordGpxCharacterCells[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc};
const s32 gRecordGpxCupMessageIndices[8] = {0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c};
const s32 gRecordGpxCupIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const s32 gRecordGpxCupAnyOfFlagIndices[8][3] = {{0x1b, 0x1b, 0x1b}, {0x1b, 0x1b, 0x1b}, {0, 1, 2},   {4, 5, 6},
                                                 {0x1b, 0x1b, 0x1b}, {0x1b, 0x1b, 0x1b}, {8, 9, 0xa}, {0xc, 0xd, 0xe}};

void LocateAndQueueRecordGpx(void) {
    Nclr *recordGpxMONclr = NULL;
    Ncgr *recordGpxMBNcgr = NULL;
    Nclr *recordGpxMBNclr = NULL;
    Nscr *recordGpxMNscr = NULL;
    Nclr *recordGpxSONclr = NULL;
    Ncgr *recordGpxSBNcgr = NULL;
    Nclr *recordGpxSBNclr = NULL;
    u16 *paletteData;

    LocateNcgr2(&gRecordGpx->mRecordGpxMNcgr, FindSceneFile(gRecordGpxMNcgrName));
    LocateNcer(&gRecordGpx->mRecordGpxMNcer, FindSceneFile(gRecordGpxMNcerName));
    LocateNclr(&recordGpxMONclr, FindSceneFile(gRecordGpxMONclrName));
    gRecordGpx->mRecordGpxMBncl = FindSceneFile(gRecordGpxMBnclName);
    gRecordGpx->mRecordGpxMBnll = FindSceneFile(gRecordGpxMBnllName);
    LocateNcgr2(&gRecordGpx->mRecordGpxSNcgr, FindSceneFile(gRecordGpxSNcgrName));
    LocateNcer(&gRecordGpx->mRecordGpxSNcer, FindSceneFile(gRecordGpxSNcerName));
    LocateNclr(&recordGpxSONclr, FindSceneFile(gRecordGpxSONclrName));
    gRecordGpx->mRecordGpxSBncl = FindSceneFile(gRecordGpxSBnclName);
    gRecordGpx->mRecordGpxSBnbl = FindSceneFile(gRecordGpxSBnblName);
    gRecordGpx->mRecordGpxSBnll = FindSceneFile(gRecordGpxSBnllName);
    LocateNcgr2(&gRecordGpx->mRecordTrophyONcgr, FindSceneFile(gRecordTrophyONcgrName));
    LocateNcer(&gRecordGpx->mRecordTrophyONcer, FindSceneFile(gRecordTrophyONcerName));
    LocateNclr(&gRecordGpx->mRecordTrophySONclr, FindSceneFile(gRecordTrophySONclrName));
    gRecordGpx->mRecordTrophySOBncl = FindSceneFile(gRecordTrophySOBnclName);
    gRecordGpx->mPlayerCharacterMNcgr = GetPlayerCharacterNcgr(0);
    gRecordGpx->mPlayerCharacterMNcer = GetPlayerCharacterNcer(0);
    gRecordGpx->mPlayerCharacterMONclr = GetPlayerCharacterNclr(0);
    gRecordGpx->mPlayerCharacterMBncl = GetPlayerCharacterBncl(0);
    LocateNcgr(&recordGpxMBNcgr, FindSceneFile(gRecordGpxMBNcgrName));
    LocateNclr(&recordGpxMBNclr, FindSceneFile(gRecordGpxMBNclrName));
    LocateNscr(&recordGpxMNscr, FindSceneFile(gRecordGpxMNscrName));
    LocateNcgr(&recordGpxSBNcgr, FindSceneFile(gRecordGpxSBNcgrName));
    LocateNclr(&recordGpxSBNclr, FindSceneFile(gRecordGpxSBNclrName));
    LocateNscr(&gRecordGpx->mRecordGpxSNscr, FindSceneFile(gRecordGpxSNscrName));
    paletteData = recordGpxMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, gRecordGpx->mRecordGpxMNcgr->mData,
                                       gRecordGpx->mRecordGpxMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, recordGpxMONclr->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gRecordGpx->mRecordGpxSNcgr->mData,
                                       gRecordGpx->mRecordGpxSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, recordGpxSONclr->mData, recordGpxSONclr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(4, 0, recordGpxMBNcgr->mData, recordGpxMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, recordGpxMBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(8, 0, recordGpxMNscr->mData, recordGpxMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, recordGpxSBNcgr->mData, recordGpxSBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, recordGpxSBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gRecordGpx->mRecordGpxSNscr->mData,
                                       gRecordGpx->mRecordGpxSNscr->mDataSize);
    paletteData = gRecordGpx->mRecordTrophySONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxTrophyPaletteIndices[0] << 5,
                                       (u8 *) paletteData + (gRecordGpxTrophyNclrPaletteIndices[0] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxTrophyPaletteIndices[1] << 5,
                                       (u8 *) paletteData + (gRecordGpxTrophyNclrPaletteIndices[1] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxTrophyPaletteIndices[2] << 5,
                                       (u8 *) paletteData + (gRecordGpxTrophyNclrPaletteIndices[2] << 5), 0x20);
}

void SetupRecordGpxValues(s32 row) {
    s32 cellIndex;
    s32 recordValue;
    u32 grandPrixRecordTotalPoints;
    s32 subLayoutCount;
    s32 grandPrixRecordGrade;
    u32 recordTime;
    u16 buf[16];
    u16 *paletteData;

    recordValue = GetGrandPrixRecordCupRank(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[row]].mVisible = 1;
    QueueCellChars(gRecordGpxCupTrophyCells[gRecordGpx->mIndex], (gRecordGpx->mRecordTrophyONcer),
                   (gRecordGpx->mRecordTrophyONcgr), (gRecordGpx->mRecordTrophySOBncl), 1,
                   gRecordGpxTrophyCellIndices[row], (gRecordGpx->mRecordGpxSNcer), (gRecordGpx->mRecordGpxSBncl));
    SetCellPaletteIndex(gRecordGpxTrophyCellIndices[row], (u8) gRecordGpxTrophyPaletteIndices[recordValue],
                        gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl);
    recordValue =
        GetGrandPrixRecordCharacterIndex(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][0]].mVisible = 1;
    QueueCellChars(gRecordGpxCharacterCells[recordValue], (gRecordGpx->mPlayerCharacterMNcer),
                   (gRecordGpx->mPlayerCharacterMNcgr), (gRecordGpx->mPlayerCharacterMBncl), 1,
                   gRecordGpxCharacterKartCellIndices[row][0], (gRecordGpx->mRecordGpxSNcer),
                   (gRecordGpx->mRecordGpxSBncl));
    paletteData = gRecordGpx->mPlayerCharacterMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxCharacterPaletteSlots[row] << 5,
                                       (u8 *) paletteData + (GetCellPaletteIndex(gRecordGpxCharacterCells[recordValue],
                                                                                 (gRecordGpx->mPlayerCharacterMNcer),
                                                                                 (gRecordGpx->mPlayerCharacterMBncl))
                                                             << 5),
                                       0x20);
    recordValue = GetGrandPrixRecordKartIndex(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][1]].mVisible = 1;
    QueueKartIcon(recordValue, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                  gRecordGpxCharacterKartCellIndices[row][1], gRecordGpxKartPaletteSlots[row], 1);
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    GetGrandPrixRecordTime(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row], &recordTime);
    FormatTimeAscii(&recordTime, buf);
    gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[row]].mVisible = 1;
    PrintLabelLayoutTextFixedDigits(1, gRecordGpxTimeLabelIndices[row], gRecordGpx->mRecordGpxSBnll, buf,
                                    gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    grandPrixRecordTotalPoints =
        (u16) GetGrandPrixRecordTotalPoints(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    FormatAsciiNumber(grandPrixRecordTotalPoints, buf);
    gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[row]].mVisible = 1;
    PrintLabelLayoutTextFixedAdvance(1, gRecordGpxTotalPointsLabelIndices[row], gRecordGpx->mRecordGpxSBnll, buf,
                                     gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][cellIndex]].mVisible = 0;
    }
    switch (grandPrixRecordTotalPoints) {
        case 0:
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][0]].mVisible = 1;
            break;
        case 1:
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][1]].mVisible = 1;
            break;
        default:
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][2]].mVisible = 1;
            break;
    }
    gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[row]].mVisible = 0;
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[row][cellIndex]].mVisible = 0;
    }
    grandPrixRecordGrade =
        GetGrandPrixRecordGrade(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    if (grandPrixRecordGrade < 5) {
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[row]].mVisible = 1;
        PrintLabelLayoutTextNoFixedAdvance(1, gRecordGpxGradeLabelIndices[row], gRecordGpx->mRecordGpxSBnll,
                                           gRecordGpxGradeStrings[grandPrixRecordGrade], gRecordGpx->mRecordGpxSBncl,
                                           gRecordGpx->mRecordGpxSTable);
    } else {
        gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[row][grandPrixRecordGrade - 5]].mVisible = 1;
    }
}

void SetupRecordGpxDashes(s32 row) {
    s32 cellIndex;

    gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[row]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][0]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][1]].mVisible = 0;
    PrintLabelLayoutTextFixedDigits(1, gRecordGpxTimeLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"--:--:---",
                                    gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    PrintLabelLayoutTextFixedAdvance(1, gRecordGpxTotalPointsLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"--",
                                     gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][cellIndex]].mVisible = 0;
    }
    if (row != 3 || IsRecordGpxCupBackupFlagSet(gRecordGpx->mIndex) != 0) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][0]].mVisible = 1;
    }
    for (cellIndex = 0; cellIndex < 3; cellIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[row][cellIndex]].mVisible = 0;
    }
    PrintLabelLayoutTextNoFixedAdvance(1, gRecordGpxGradeLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"-",
                                       gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable);
}

// Stores both offsets and steps both timers; while timer i is above 0 its Running row is switched
// on and its TimerZero row off, and the other way round once it reaches 0.
void AdvanceRecordGpxOffsetTimers(void) {
    s32 timerIndex;

    gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordGpx->mOffsetTimers[0]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordGpx->mOffsetTimers[1]);
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gRecordGpx->mOffsetTimers[timerIndex] > 0) {
            gRecordGpx->mOffsetTimers[timerIndex]--;
            gRecordGpx->mRecordGpxSTable[gRecordGpxTimerZeroSTableIndices[timerIndex]].mVisible = 0;
            gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[timerIndex]].mVisible = 1;
        } else {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTimerZeroSTableIndices[timerIndex]].mVisible = 1;
            gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[timerIndex]].mVisible = 0;
        }
    }
}

void SetupRecordGpx(void) {
    s32 cellIndex;
    s32 subLayoutCount;
    RecordGpx *recordGpx;
    void *bmgEntry;
    u8 cellPaletteIndex;

    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    if (IsRecordGpxCupBackupFlagSet(gRecordGpx->mIndex) != 0) {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, OFFSET_PTR(u8, gRecordGpx->mRecordGpxSNscr, 0xc) + 0x3c6,
                                           0x134);
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[3]].mVisible = 1;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[3][cellIndex]].mVisible = 1;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[3]].mVisible = 1;
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, gRecordGpx->mZeroBuffer + 0x3c6, 0x134);
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[3]].mVisible = 0;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[3][cellIndex]].mVisible = 0;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[3]].mVisible = 0;
    }
    recordGpx = gRecordGpx;
    cellPaletteIndex = GetCellPaletteIndex(1, (recordGpx->mRecordGpxMNcer), (recordGpx->mRecordGpxMBncl));
    QueueCupMark(recordGpx->mIndex, recordGpx->mRecordGpxMNcer, recordGpx->mRecordGpxMBncl, 1, cellPaletteIndex, 0);
    recordGpx = gRecordGpx;
    bmgEntry = GetBmgEntry(recordGpx->mCommonMessages, gRecordGpxCupMessageIndices[recordGpx->mIndex]);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordGpx->mRecordGpxMBnll, bmgEntry, recordGpx->mRecordGpxMBncl,
                                       recordGpx->mRecordGpxMTable);
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        if (IsGrandPrixRecordFilled(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[cellIndex]) !=
            0) {
            SetupRecordGpxValues(cellIndex);
        } else {
            SetupRecordGpxDashes(cellIndex);
        }
    }
}

void IncrementRecordGpxIndex(void) {
    s32 index;

    gRecordGpx->mIndex++;
    index = gRecordGpx->mIndex;
    if (index >= 8) {
        index = 0;
        gRecordGpx->mIndex = index;
    }
    if (IsRecordGpxCupSelectable(index) == 0) {
        IncrementRecordGpxIndex();
    }
}

void DecrementRecordGpxIndex(void) {
    s32 index;

    gRecordGpx->mIndex--;
    index = gRecordGpx->mIndex;
    if (index < 0) {
        index = 7;
        gRecordGpx->mIndex = index;
    }
    if (IsRecordGpxCupSelectable(index) == 0) {
        DecrementRecordGpxIndex();
    }
}

u32 IsRecordGpxCupBackupFlagSet(s32 cupIndex) {
    return IsBackupFlagSet(gRecordGpxCupFlagIndices[cupIndex]);
}

u32 IsRecordGpxCupSelectable(u32 cupIndex) {
    u32 result;
    s32 flagIndex;

    result = 0;
    switch (cupIndex) {
        case 0:
        case 1:
        case 4:
        case 5:
            return 1;
        case 2:
        case 3:
        case 6:
        case 7:
            for (flagIndex = 0; flagIndex < 3; flagIndex++) {
                result |= IsBackupFlagSet(gRecordGpxCupAnyOfFlagIndices[cupIndex][flagIndex]);
            }
            result |= IsRecordGpxCupBackupFlagSet(cupIndex);
            break;
    }
    return result;
}

void ResetRecordGpx(void) {
    s32 rowIndex;
    s32 cellIndex;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    gRecordGpx->mNextState = 0;
    gRecordGpx->mStateFrames = 0;
    gRecordGpx->mBg0Offset = ~0xbf;
    gRecordGpx->mBg3OffsetX = ~0xff;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordGpx->mRecordGpxSTable[44].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordGpx->mRecordGpxSTable[45].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    for (rowIndex = 0; rowIndex < 4; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[rowIndex]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[gRecordGpxLowSTableIndices[rowIndex]].mOffsetY = gRecordGpx->mBg3OffsetY;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetX =
                LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[rowIndex][cellIndex]].mOffsetY =
                gRecordGpx->mBg3OffsetY;
        }
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[gRecordGpxHighSTableIndices[rowIndex]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[rowIndex]].mOffsetY =
            gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[rowIndex]].mOffsetY =
            gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[rowIndex]].mOffsetY =
            gRecordGpx->mBg3OffsetY;
        for (cellIndex = 0; cellIndex < 3; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetX =
                LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[rowIndex][cellIndex]].mOffsetY =
                gRecordGpx->mBg3OffsetY;
        }
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetX =
                LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[rowIndex][cellIndex]].mOffsetY =
                gRecordGpx->mBg3OffsetY;
        }
    }
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[rowIndex]].mVisible = 0;
    }
}
