#include "01/code_02193c5c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_0201ea58.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02117218.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0205f000.h"
#include "registers.h"

RecordGpx *gRecordGpx;

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
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, (u8 *) paletteData + 0x1c0, 0x40);
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
                                       (u8 *) paletteData + (data_ov001_021a660c[0] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxTrophyPaletteIndices[1] << 5,
                                       (u8 *) paletteData + (data_ov001_021a660c[1] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, gRecordGpxTrophyPaletteIndices[2] << 5,
                                       (u8 *) paletteData + (data_ov001_021a660c[2] << 5), 0x20);
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
    recordValue = GetGrandPrixRecordCharacterIndex(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][0]].mVisible = 1;
    QueueCellChars(gRecordGpxCharacterCells[recordValue], (gRecordGpx->mPlayerCharacterMNcer),
                   (gRecordGpx->mPlayerCharacterMNcgr), (gRecordGpx->mPlayerCharacterMBncl), 1,
                   gRecordGpxCharacterKartCellIndices[row][0], (gRecordGpx->mRecordGpxSNcer),
                   (gRecordGpx->mRecordGpxSBncl));
    paletteData = gRecordGpx->mPlayerCharacterMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(
        0x1e, gRecordGpxCharacterPaletteSlots[row] << 5,
        (u8 *) paletteData + (GetCellPaletteIndex(gRecordGpxCharacterCells[recordValue], (gRecordGpx->mPlayerCharacterMNcer),
                                                  (gRecordGpx->mPlayerCharacterMBncl))
                              << 5),
        0x20);
    recordValue = GetGrandPrixRecordKartIndex(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[row]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][1]].mVisible = 1;
    QueueKartIcon(recordValue, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                  gRecordGpxCharacterKartCellIndices[row][1], data_ov001_021a668c[row], 1);
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
    s32 i;

    gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[row]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][0]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[row][1]].mVisible = 0;
    PrintLabelLayoutTextFixedDigits(1, gRecordGpxTimeLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"--:--:---",
                                    gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    PrintLabelLayoutTextFixedAdvance(1, gRecordGpxTotalPointsLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"--",
                                     gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, 7);
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][i]].mVisible = 0;
    }
    if (row != 3 || IsRecordGpxCupBackupFlagSet(gRecordGpx->mIndex) != 0) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[row][0]].mVisible = 1;
    }
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[row][i]].mVisible = 0;
    }
    PrintLabelLayoutTextNoFixedAdvance(1, gRecordGpxGradeLabelIndices[row], gRecordGpx->mRecordGpxSBnll, L"-",
                                       gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable);
}

// Stores both offsets and steps both timers; while timer i is above 0 its Running row is switched
// on and its TimerZero row off, and the other way round once it reaches 0.
void AdvanceRecordGpxOffsetTimers(void) {
    s32 i;

    gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordGpx->mOffsetTimers[0]);
    gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordGpx->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordGpx->mOffsetTimers[i] > 0) {
            gRecordGpx->mOffsetTimers[i]--;
            gRecordGpx->mRecordGpxSTable[gRecordGpxTimerZeroSTableIndices[i]].mVisible = 0;
            gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[i]].mVisible = 1;
        } else {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTimerZeroSTableIndices[i]].mVisible = 1;
            gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[i]].mVisible = 0;
        }
    }
}

void SetupRecordGpx(void) {
    s32 i;
    s32 subLayoutCount;
    RecordGpx *recordGpx;
    void *bmgEntry;
    u8 cellPaletteIndex;

    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    if (IsRecordGpxCupBackupFlagSet(gRecordGpx->mIndex) != 0) {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, OFFSET_PTR(u8, gRecordGpx->mRecordGpxSNscr, 0xc) + 0x3c6,
                                           0x134);
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[3]].mVisible = 1;
        for (i = 0; i < 3; i++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[3][i]].mVisible = 1;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[3]].mVisible = 1;
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, (u8 *) gRecordGpx->mZeroBuffer + 0x3c6, 0x134);
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[3]].mVisible = 0;
        for (i = 0; i < 3; i++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[3][i]].mVisible = 0;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[3]].mVisible = 0;
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
    for (i = 0; i < 4; i++) {
        if (IsGrandPrixRecordFilled(gRecordGpxCupIndices[gRecordGpx->mIndex], gRecordGpxRecordIndices[i]) != 0) {
            SetupRecordGpxValues(i);
        } else {
            SetupRecordGpxDashes(i);
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
    s32 i;

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
            for (i = 0; i < 3; i++) {
                result |= IsBackupFlagSet(gRecordGpxCupAnyOfFlagIndices[cupIndex][i]);
            }
            result |= IsRecordGpxCupBackupFlagSet(cupIndex);
            break;
    }
    return result;
}

void ResetRecordGpx(void) {
    s32 i;
    s32 j;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    gRecordGpx->mNextState = 0;
    gRecordGpx->mStateFrames = 0;
    gRecordGpx->mBg0Offset = ~0xbf;
    gRecordGpx->mBg3OffsetX = ~0xff;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxSTable[44].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxSTable[45].mOffsetX = 0x100;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetY =
            gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetY =
            gRecordGpx->mBg3OffsetY;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
    }
    for (i = 0; i < 2; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxRunningSTableIndices[i]].mVisible = 0;
    }
}

void RequestRecordGpxState1AndSetup(void) {
    gRecordGpx->mNextState = 1;
    gRecordGpx->mStateFrames = 0;
    SetupRecordGpx();
}

// Requests state 2: stores mNextState = 2 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState2.
void RequestRecordGpxState2(void) {
    gRecordGpx->mNextState = 2;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState3.
void RequestRecordGpxState3(void) {
    gRecordGpx->mNextState = 3;
    gRecordGpx->mStateFrames = 0;
}

void RequestRecordGpxState4AndMoveIndex(void) {
    gRecordGpx->mNextState = 4;
    gRecordGpx->mStateFrames = 0;
    switch (gRecordGpx->mUnk_7c) {
        case 0:
            IncrementRecordGpxIndex();
            break;
        case 1:
            DecrementRecordGpxIndex();
            break;
    }
    SetupRecordGpx();
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState5.
void RequestRecordGpxState5(void) {
    gRecordGpx->mNextState = 5;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState6.
void RequestRecordGpxState6(void) {
    gRecordGpx->mNextState = 6;
    gRecordGpx->mStateFrames = 0;
}

void InitRecordGpx(void *heap) {
    u32 anyFlagSet = 0;
    s32 i;
    s32 remainingSize;
    void *recordMainOam;
    vu16 zero;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x8800;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x5810;
    gRecordGpx = HeapAlloc(heap, 0x94);
    gRecordGpx->mHeap = heap;
    gRecordGpx->mState = 0;
    gRecordGpx->mIndex = 0;
    gRecordGpx->mUnk_7c = 0;
    gRecordGpx->mUnk_88 = FALSE;
    gRecordGpx->mUnk_8c = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordGpx->mOffsetTimers[i] = 0;
    }
    LocateAndQueueRecordGpx();
    CreateKartIcon(heap);
    CreateCupMark(heap);
    recordMainOam = GetRecordMainOam();
    ResetOamLists(recordMainOam, GetRecordSubOam());
    InitLayoutTable(heap, gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMBnll, &gRecordGpx->mRecordGpxMTable);
    InitLayoutTable(heap, gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSBnll, &gRecordGpx->mRecordGpxSTable);
    gRecordGpx->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitLabelCanvas(heap, 0, gRecordGpx->mRecordGpxMBnll, 200, 16, 0, gRecordGpx->mRecordGpxMNcer,
                    gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMTable, 0x8000);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 4; i++) {
        remainingSize -=
            InitLabelCanvas(heap, gRecordGpxTimeLabelIndices[i], gRecordGpx->mRecordGpxSBnll,
                            gRecordGpxTimeLabelWidths[i], gRecordGpxTimeLabelHeights[i], i, gRecordGpx->mRecordGpxSNcer,
                            gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable, remainingSize);
        remainingSize -= InitLabelCanvas(heap, gRecordGpxTotalPointsLabelIndices[i], gRecordGpx->mRecordGpxSBnll,
                                         gRecordGpxTotalPointsLabelWidths[i], gRecordGpxTotalPointsLabelHeights[i],
                                         i + 4, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                                         gRecordGpx->mRecordGpxSTable, remainingSize);
        remainingSize -= InitLabelCanvas(heap, gRecordGpxGradeLabelIndices[i], gRecordGpx->mRecordGpxSBnll,
                                         gRecordGpxGradeLabelWidths[i], gRecordGpxGradeLabelHeights[i], i + 12,
                                         gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                                         gRecordGpx->mRecordGpxSTable, remainingSize);
    }
    gRecordGpx->mBg3OffsetY = 0;
    for (i = 0; i < 8; i++) {
        anyFlagSet |= IsRecordGpxCupBackupFlagSet(i);
    }
    if (anyFlagSet == 0) {
        gRecordGpx->mBg3OffsetY = 16;
    }
    gRecordGpx->mZeroBuffer = HeapAlloc(heap, 0x134);
    zero = 0;
    MIi_CpuClear16(zero, gRecordGpx->mZeroBuffer, 0x134);
    ResetRecordGpx();
}

void ReleaseRecordGpx(void) {
    u32 displayBits;

    ClearKartIconPointer();
    ClearCupMarkPointer();
    gRecordGpx = NULL;
    displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    displayBits &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    displayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    displayBits &= ~0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
}

void AdvanceRecordGpxState0(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset = InterpolateS16(1, -192, 0, gRecordGpx->mStateFrames, 10);
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState1AndSetup();
    }
}

void AdvanceRecordGpxState1(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    AdvanceRecordGpxOffsetTimers();
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = offsetX;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetX = offsetX;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState2();
    }
}

void AdvanceRecordGpxState2(void) {
    s32 touchedRect = -1;
    s32 touchBeganRect = -1;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL touchActive, recentlyLost, touchBegan, lostBeforeBegan, confirmTouchBegan, lostBeforeConfirm;

    AdvanceRecordGpxOffsetTimers();
    touchActive = TRUE;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mHasPair == 0) {
        touchActive = FALSE;
    }
    if (touchActive != FALSE) {
        touchedRect = RectTableFindContaining(gRecordGpx->mRecordGpxSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    touchBegan = FALSE;
    lostBeforeBegan = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        lostBeforeBegan = TRUE;
    }
    if (lostBeforeBegan == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchBeganRect = RectTableFindContaining(gRecordGpx->mRecordGpxSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if (touchedRect != 0) {
        gRecordGpx->mUnk_88 = FALSE;
    }
    if (touchedRect != 1) {
        gRecordGpx->mUnk_8c = FALSE;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        confirmTouchBegan = FALSE;
        lostBeforeConfirm = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            lostBeforeConfirm = TRUE;
        }
        if (lostBeforeConfirm == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            confirmTouchBegan = TRUE;
        }
        if (confirmTouchBegan == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    RequestRecordGpxState5();
    gRecordGpx->mUnk_90 = 0;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if ((touchedRect == 0 && gRecordGpx->mUnk_88 != FALSE) || (touchBeganRect == 0 && gRecordGpx->mUnk_88 == FALSE) ||
        (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_LEFT) != 0) {
        gRecordGpx->mUnk_7c = 1;
        gRecordGpx->mOffsetTimers[0] = 6;
        gRecordGpx->mUnk_88 = TRUE;
        RequestRecordGpxState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
        return;
    }
    if ((touchedRect == 1 && gRecordGpx->mUnk_8c != FALSE) || (touchBeganRect == 1 && gRecordGpx->mUnk_8c == FALSE) ||
        (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordGpx->mUnk_7c = 0;
        gRecordGpx->mOffsetTimers[1] = 6;
        gRecordGpx->mUnk_8c = TRUE;
        RequestRecordGpxState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    }
}

void AdvanceRecordGpxState3(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s32 mainLayoutCount;
    s32 subLayoutCount;
    s16 targetOffsetX = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->mUnk_7c) {
        case 0:
            targetOffsetX = -256;
            break;
        case 1:
            targetOffsetX = 0x100;
            break;
    }
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetX = offsetX;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState4AndMoveIndex();
    }
}

void AdvanceRecordGpxState4(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s32 mainLayoutCount;
    s32 subLayoutCount;
    s16 startOffsetX = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->mUnk_7c) {
        case 0:
            startOffsetX = 0x100;
            break;
        case 1:
            startOffsetX = -256;
            break;
    }
    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetX = offsetX;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState2();
    }
}

void AdvanceRecordGpxState5(void) {
    s16 offsetX;
    s32 i;
    s32 j;
    s32 mainLayoutCount;
    s32 subLayoutCount;

    gRecordGpx->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordGpx->mRecordGpxMBncl->mCount;
    subLayoutCount = gRecordGpx->mRecordGpxSBncl->mCount;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = offsetX;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = offsetX;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[gRecordGpxTrophyCellIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxTotalPointsCellIndices[i][j]].mOffsetX = offsetX;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxTotalPointsLabelIndices[i]].mOffsetX = offsetX;
        gRecordGpx->mRecordGpxSTable[subLayoutCount + gRecordGpxGradeLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxGradeCellIndices[i][j]].mOffsetX = offsetX;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[gRecordGpxCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState6();
    }
}

void AdvanceRecordGpxState6(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset = InterpolateS16(1, 0, -192, gRecordGpx->mStateFrames, 10);
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordScreen(gRecordGpx->mUnk_90);
    }
}

void AdvanceRecordGpx(void) {
    RecordGpx *recordGpx;

    gRecordGpx->mState = gRecordGpx->mNextState;
    switch (gRecordGpx->mState) {
        case 0:
            AdvanceRecordGpxState0();
            break;
        case 1:
            AdvanceRecordGpxState1();
            break;
        case 2:
            AdvanceRecordGpxState2();
            break;
        case 3:
            AdvanceRecordGpxState3();
            break;
        case 4:
            AdvanceRecordGpxState4();
            break;
        case 5:
            AdvanceRecordGpxState5();
            break;
        case 6:
            AdvanceRecordGpxState6();
            break;
    }
    recordGpx = gRecordGpx;
    DrawLayoutTable(recordGpx->mRecordGpxMBncl, recordGpx->mRecordGpxMNcer, recordGpx->mRecordGpxMBnll,
                    GetRecordMainOam(), recordGpx->mRecordGpxMTable);
    recordGpx = gRecordGpx;
    DrawLayoutTable(recordGpx->mRecordGpxSBncl, recordGpx->mRecordGpxSNcer, recordGpx->mRecordGpxSBnll,
                    GetRecordSubOam(), recordGpx->mRecordGpxSTable);
}

void WriteRecordGpxBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordGpx->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = ((-gRecordGpx->mBg3OffsetX) & 0x1ff) | ((-gRecordGpx->mBg3OffsetY << 16) & 0x1ff0000);
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordGpxRegisters(void) {
    u32 mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    u32 subDisplayBits;

    mainDisplayBits |= 0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    subDisplayBits |= 0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
}

void RegisterRecordGpxCallbacks(void) {
    RecordScreenCallbacks local = gRecordGpxCallbacks;

    SetRecordScreenCallbacks(&local);
}
