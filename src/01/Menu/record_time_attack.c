#include "01/Menu/record_time_attack.h"

#include "01/Menu/record_gpx.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/record_vs.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/txt_system.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "01/unk_021a6000.h"
#include "code_02148950.h"
#include "Main/Graphics/layout_rect_table.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0214cfe4.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "03/Net/essid_wcm.h"
#include "01/unk_021a8000.h"
#include "Main/Graphics/oam.h"
#include "01/code_02198000.h"
#include "01/unk_021a9000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/data_0217d068.h"

RecordTAtt *gRecordTAtt;

void LocateAndQueueRecordTAtt(void) {
    Nclr *recordTAttMONclr = NULL;
    Ncgr *recordTAttMBNcgr = NULL;
    Nclr *recordTAttMBNclr = NULL;
    Nscr *recordTAttMNscr = NULL;
    Nscr *recordTAttMScoreNscr = NULL;
    Nclr *recordTAttSONclr = NULL;
    Ncgr *recordTAttSBNcgr = NULL;
    Nclr *recordTAttSBNclr = NULL;
    Nscr *recordTAttSNscr = NULL;
    u16 *paletteData;

    LocateNcgr2(&gRecordTAtt->mRecordTAttMNcgr, FindSceneFile(gRecordTAttMNcgrName));
    LocateNcer(&gRecordTAtt->mRecordTAttMNcer, FindSceneFile(gRecordTAttMNcerName));
    LocateNclr(&recordTAttMONclr, FindSceneFile(gRecordTAttMONclrName));
    gRecordTAtt->mRecordTAttMBncl = FindSceneFile(gRecordTAttMBnclName);
    gRecordTAtt->mRecordTAttMBnll = FindSceneFile(gRecordTAttMBnllName);
    LocateNcgr2(&gRecordTAtt->mRecordTAttSNcgr, FindSceneFile(gRecordTAttSNcgrName));
    LocateNcer(&gRecordTAtt->mRecordTAttSNcer, FindSceneFile(gRecordTAttSNcerName));
    LocateNclr(&recordTAttSONclr, FindSceneFile(gRecordTAttSONclrName));
    gRecordTAtt->mRecordTAttSBncl = FindSceneFile(gRecordTAttSBnclName);
    gRecordTAtt->mRecordTAttSBnbl = FindSceneFile(gRecordTAttSBnblName);
    gRecordTAtt->mRecordTAttSBnll = FindSceneFile(gRecordTAttSBnllName);
    gRecordTAtt->mUnk_28 = GetPlayerCharacterNcgr(0);
    gRecordTAtt->mUnk_2c = GetPlayerCharacterNcer(0);
    gRecordTAtt->mUnk_30 = GetPlayerCharacterNclr(0);
    gRecordTAtt->mUnk_34 = GetPlayerCharacterBncl(0);
    LocateNcgr(&recordTAttMBNcgr, FindSceneFile(gRecordTAttMBNcgrName));
    LocateNscr(&recordTAttMNscr, FindSceneFile(gRecordTAttMNscrName));
    LocateNscr(&recordTAttMScoreNscr, FindSceneFile(gRecordTAttMScoreNscrName));
    LocateNclr(&recordTAttMBNclr, FindSceneFile(gRecordTAttMBNclrName));
    LocateNcgr(&recordTAttSBNcgr, FindSceneFile(gRecordTAttSBNcgrName));
    LocateNclr(&recordTAttSBNclr, FindSceneFile(gRecordTAttSBNclrName));
    LocateNscr(&recordTAttSNscr, FindSceneFile(gRecordTAttSNscrName));
    paletteData = recordTAttMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, gRecordTAtt->mRecordTAttMNcgr->mData,
                                       gRecordTAtt->mRecordTAttMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, recordTAttMONclr->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, (u8 *) paletteData + 0x1c0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gRecordTAtt->mRecordTAttSNcgr->mData,
                                       gRecordTAtt->mRecordTAttSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, recordTAttSONclr->mData, recordTAttSONclr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(4, 0, recordTAttMBNcgr->mData, recordTAttMBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0, recordTAttMNscr->mData, recordTAttMNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(9, 0, recordTAttMScoreNscr->mData, recordTAttMScoreNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, recordTAttMBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, recordTAttSBNcgr->mData, recordTAttSBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, recordTAttSBNclr->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, recordTAttSNscr->mData, recordTAttSNscr->mDataSize);
}

void SetupRecordTAttRowValues(u16 row) {
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 recordIndex;
    s32 result;
    u16 tile;
    u16 index;
    u16 slot;
    u16 labelIndex;
    u8 *palette;

    if (row == 0) {
        u16 cnt;

        recordIndex = gRecordTAttRecordIndices[0];
        result = GetTimeRecordCharacterIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        index = gRecordTAttCharacterKartCellIndices[0][0];
        gRecordTAtt->mRecordTAttMTable[index].mVisible = 1;
        tile = gRecordTAttCharacterCells[result];
        QueueCellChars(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 0, index,
                       gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl);
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0xe, gRecordTAttCharacterPaletteSlots[0] << 5,
            palette + (GetCellPaletteIndex(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5), 0x20);
        result = GetTimeRecordKartIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        slot = gRecordTAttCharacterKartCellIndices[0][1];
        gRecordTAtt->mRecordTAttMTable[slot].mVisible = 1;
        QueueKartIcon(result, gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl, slot,
                      gRecordTAttCharacterPaletteSlots[5], 0);
        cnt = gRecordTAtt->mRecordTAttMBncl->mCount;
        GetTimeRecordTime(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex, &time);
        FormatTimeAscii(&time, str);
        labelIndex = gRecordTAttTimeLabelIndices[0];
        gRecordTAtt->mRecordTAttMTable[cnt + labelIndex].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(0, labelIndex, gRecordTAtt->mRecordTAttMBnll, str,
                                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, 7);
        GetTimeRecordName(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex, name);
        MI_CpuFill8(str, 0, 0x20);
        MIi_CpuCopy16(name, str, 0x14);
        labelIndex = gRecordTAttNameLabelIndices[0];
        gRecordTAtt->mRecordTAttMTable[cnt + labelIndex].mVisible = 1;
        PrintLabelLayoutTextNoFixedAdvance(0, labelIndex, gRecordTAtt->mRecordTAttMBnll, str,
                                           gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable);
    } else {
        u16 cnt;

        recordIndex = gRecordTAttRecordIndices[row];
        result = GetTimeRecordCharacterIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        index = gRecordTAttCharacterKartCellIndices[row][0];
        gRecordTAtt->mRecordTAttSTable[index].mVisible = 1;
        tile = gRecordTAttCharacterCells[result];
        QueueCellChars(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 1, index,
                       gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl);
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0x1e, gRecordTAttCharacterPaletteSlots[row] << 5,
            palette + (GetCellPaletteIndex(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5), 0x20);
        result = GetTimeRecordKartIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        slot = gRecordTAttKartIconCellIndices[row][0];
        gRecordTAtt->mRecordTAttSTable[slot].mVisible = 1;
        QueueKartIcon(result, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl, slot,
                      gRecordTAttKartPaletteSlots[row], 1);
        cnt = gRecordTAtt->mRecordTAttSBncl->mCount;
        GetTimeRecordTime(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex, &time);
        FormatTimeAscii(&time, str);
        labelIndex = gRecordTAttTimeLabelIndices[row];
        gRecordTAtt->mRecordTAttSTable[cnt + labelIndex].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(1, labelIndex, gRecordTAtt->mRecordTAttSBnll, str,
                                        gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, 7);
        GetTimeRecordName(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex, name);
        MI_CpuFill8(str, 0, 0x20);
        MIi_CpuCopy16(name, str, 0x14);
        labelIndex = gRecordTAttNameLabelIndices[row];
        gRecordTAtt->mRecordTAttSTable[cnt + labelIndex].mVisible = 1;
        PrintLabelLayoutTextNoFixedAdvance(1, labelIndex, gRecordTAtt->mRecordTAttSBnll, str,
                                           gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable);
    }
}

void SetupRecordTAttRowDashes(u16 row) {
    u16 layoutCount;

    if (row == 0) {
        gRecordTAtt->mRecordTAttMTable[gRecordTAttCharacterKartCellIndices[0][0]].mVisible = 0;
        gRecordTAtt->mRecordTAttMTable[gRecordTAttCharacterKartCellIndices[0][1]].mVisible = 0;
        layoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[layoutCount + gRecordTAttTimeLabelIndices[0]].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(0, gRecordTAttTimeLabelIndices[0], gRecordTAtt->mRecordTAttMBnll, L"--:--:---",
                                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, 7);
        gRecordTAtt->mRecordTAttMTable[layoutCount + gRecordTAttNameLabelIndices[0]].mVisible = 0;
    } else {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[row][0]].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[gRecordTAttKartIconCellIndices[row][0]].mVisible = 0;
        layoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
        gRecordTAtt->mRecordTAttSTable[layoutCount + gRecordTAttTimeLabelIndices[row]].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(1, gRecordTAttTimeLabelIndices[row], gRecordTAtt->mRecordTAttSBnll,
                                        L"--:--:---", gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, 7);
        gRecordTAtt->mRecordTAttSTable[layoutCount + gRecordTAttNameLabelIndices[row]].mVisible = 0;
    }
}

void SetupRecordTAtt(void) {
    RecordTAtt *recordTAtt;
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 i;
    s32 result;
    u16 tile;
    u8 *palette;
    u16 mainLayoutCount;

    recordTAtt = gRecordTAtt;
    PrintLabelLayoutTextNoFixedAdvance(
        0, 0, gRecordTAtt->mRecordTAttMBnll,
        GetBmgEntry(recordTAtt->mCommonMessages, gRecordTAttCommonMessageIndices[recordTAtt->mIndex]),
        recordTAtt->mRecordTAttMBncl, recordTAtt->mRecordTAttMTable);
    for (i = 0; i < 5; i++) {
        if (IsTimeRecordFilled(gRecordTAttCourseIds[gRecordTAtt->mIndex], gRecordTAttRecordIndices[i])) {
            SetupRecordTAttRowValues(i);
        } else {
            SetupRecordTAttRowDashes(i);
        }
    }
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    if (IsTimeRecordFilled(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5)) {
        result = GetTimeRecordCharacterIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5);
        gRecordTAtt->mRecordTAttMTable[5].mVisible = 1;
        tile = gRecordTAttCharacterCells[result];
        QueueCellChars(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 0, 5,
                       gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl);
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0xe, 0x80, palette + (GetCellPaletteIndex(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5), 0x20);
        result = GetTimeRecordKartIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5);
        gRecordTAtt->mRecordTAttMTable[6].mVisible = 1;
        QueueKartIcon(result, gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl, 6, 6, 0);
        GetTimeRecordTime(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5, &time);
        FormatTimeAscii(&time, str);
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(0, 2, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                                        gRecordTAtt->mRecordTAttMTable, 7);
        GetTimeRecordName(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5, name);
        MI_CpuFill8(str, 0, 0x20);
        MIi_CpuCopy16(name, str, 0x14);
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mVisible = 1;
        PrintLabelLayoutTextNoFixedAdvance(0, 4, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                                           gRecordTAtt->mRecordTAttMTable);
    } else {
        gRecordTAtt->mRecordTAttMTable[5].mVisible = 0;
        gRecordTAtt->mRecordTAttMTable[6].mVisible = 0;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mVisible = 1;
        PrintLabelLayoutTextFixedDigits(0, 2, gRecordTAtt->mRecordTAttMBnll, L"--:--:---",
                                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, 7);
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mVisible = 0;
    }
}

void IncrementRecordTAttIndex(void) {
    gRecordTAtt->mIndex++;
    if (gRecordTAtt->mIndex >= 0x20) {
        gRecordTAtt->mIndex = 0;
    }
    if (IsCourseCupMessageFlagSet(gRecordTAttCourseIds[gRecordTAtt->mIndex]) == 0) {
        IncrementRecordTAttIndex();
    }
}

void DecrementRecordTAttIndex(void) {
    gRecordTAtt->mIndex--;
    if (gRecordTAtt->mIndex < 0) {
        gRecordTAtt->mIndex = 0x1f;
    }
    if (IsCourseCupMessageFlagSet(gRecordTAttCourseIds[gRecordTAtt->mIndex]) == 0) {
        DecrementRecordTAttIndex();
    }
}

BOOL CheckRecordTAttFirstRecordFormat(void) {
    u8 buf[0x14];

    if (IsTimeRecordFilled(gRecordTAttCourseIds[gRecordTAtt->mIndex], gRecordTAttRecordIndices[0]) != FALSE) {
        if (FormatFirstCourseTimeRecord(gRecordTAttCourseIds[gRecordTAtt->mIndex], buf) != 0) {
            return TRUE;
        }
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        return FALSE;
    }
    return FALSE;
}

void ResetRecordTAtt(void) {
    s32 i;
    s32 j;
    u16 mainLayoutCount;
    u16 subLayoutCount;

    gRecordTAtt->mNextState = 0;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mBg0Offset = -192;
    gRecordTAtt->mBg1OffsetX = -256;
    gRecordTAtt->mBg1OffsetY = -192;
    gRecordTAtt->mBg3OffsetX = -256;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = -192;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = 0x100;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = 0x100;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = 0x100;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = 0x100;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = 0x100;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = 0x100;
        }
    }
    for (j = 0; j < 2; j++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[j]].mVisible = 0;
    }
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
}

void RequestRecordTAttState1AndSetup(void) {
    gRecordTAtt->mNextState = 1;
    gRecordTAtt->mStateFrames = 0;
    SetupRecordTAtt();
}

void RequestRecordTAttState2(void) {
    gRecordTAtt->mNextState = 2;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mClearChosen = FALSE;
}

// Requests state 3.
void RequestRecordTAttState3(void) {
    gRecordTAtt->mNextState = 3;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState4AndMoveIndex(void) {
    gRecordTAtt->mNextState = 4;
    gRecordTAtt->mStateFrames = 0;
    switch (gRecordTAtt->mIndexMoveDirection) {
        case 0:
            IncrementRecordTAttIndex();
            break;
        case 1:
            DecrementRecordTAttIndex();
            break;
    }
    SetupRecordTAtt();
}

// Requests state 5.
void RequestRecordTAttState5(void) {
    gRecordTAtt->mNextState = 5;
    gRecordTAtt->mStateFrames = 0;
}

// Requests state 6.
void RequestRecordTAttState6(void) {
    gRecordTAtt->mNextState = 6;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState7(void) {
    gRecordTAtt->mNextState = 7;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 1;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
}

void RequestRecordTAttState8(void) {
    gRecordTAtt->mNextState = 8;
    gRecordTAtt->mStateFrames = 0;
    RequestSelectReturnState4();
}

void RequestRecordTAttState9(void) {
    u16 buf[0x102];
    RecordTAtt *recordTAtt;
    void *a;
    void *secondButtonText;

    gRecordTAtt->mNextState = 9;
    gRecordTAtt->mStateFrames = 0;
    buf[0] = 0;
    MIi_CpuClear16(buf[0], &buf[1], 0x200);
    recordTAtt = gRecordTAtt;
    a = GetBmgEntry(recordTAtt->mGhostMessages, gRecordTAttGhostMessageIndices[recordTAtt->mIndex]);
    FormatMessageWithText(a, GetBmgEntry(recordTAtt->mRecordMessages, 10), &buf[1], 0x200);
    a = GetBmgEntry(gRecordTAtt->mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gRecordTAtt->mCommonMessages, 1);
    SetupTxtSystemSubTextTwoButtonsEx(&buf[1], a, secondButtonText, 1, 0, 1, 1, 1);
}

void RequestRecordTAttState10(void) {
    gRecordTAtt->mNextState = 10;
    gRecordTAtt->mStateFrames = 0;
    SetTxtSystemSoundId(0, 11);
}

void RequestRecordTAttState11(void) {
    gRecordTAtt->mNextState = 11;
    gRecordTAtt->mStateFrames = 0;
    RequestTxtSystemClose();
    SetTxtSystemSoundId(0, 5);
}

void RequestRecordTAttState12(void) {
    gRecordTAtt->mNextState = 12;
    gRecordTAtt->mStateFrames = 0;
    RequestSelectReturnState1();
    SetupRecordTAtt();
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
}

void RequestRecordTAttState13(void) {
    gRecordTAtt->mNextState = 13;
    gRecordTAtt->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 6);
}

void RequestRecordTAttState14(void) {
    s32 sourceIndex;
    s32 destIndex;
    s32 groupPosition;
    u8 buf[0x10];
    u16 str[0x100];

    sourceIndex = 0;
    destIndex = 0;
    groupPosition = 0;
    gRecordTAtt->mNextState = 14;
    gRecordTAtt->mStateFrames = sourceIndex;
    FormatFirstCourseTimeRecord(gRecordTAttCourseIds[gRecordTAtt->mIndex], buf);
    while (destIndex < 19) {
        groupPosition++;
        if (groupPosition > 4) {
            groupPosition = 0;
            str[destIndex] = ' ';
            destIndex++;
        } else {
            str[destIndex] = buf[sourceIndex];
            destIndex++;
            sourceIndex++;
        }
    }
    str[destIndex] = 0;
    SetupTxtSystemSubTextEx(str, 0, 1, 0, 0, 0);
}

// Requests state 15.
void RequestRecordTAttState15(void) {
    gRecordTAtt->mNextState = 15;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState16(void) {
    gRecordTAtt->mNextState = 0x10;
    gRecordTAtt->mStateFrames = 0;
    RequestTxtSystemClose();
}

// Requests state 17.
void RequestRecordTAttState17(void) {
    gRecordTAtt->mNextState = 0x11;
    gRecordTAtt->mStateFrames = 0;
}

void AdvanceRecordTAttOffsetTimers(void) {
    s32 i;

    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordTAtt->mOffsetTimers[0]);
    gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordTAtt->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordTAtt->mOffsetTimers[i] > 0) {
            gRecordTAtt->mOffsetTimers[i]--;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[i]].mVisible = 0;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[i]].mVisible = 1;
        } else {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttTimerZeroSTableIndices[i]].mVisible = 1;
            gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[i]].mVisible = 0;
        }
    }
}

BOOL AdvanceRecordTAttButtonSequence(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u16 pressedBits;

    pressedBits = gInputSlots[slotIndex].mPressedBits;
    if (pressedBits != 0) {
        if (gRecordTAttButtonSequence[0] == (gRecordTAttButtonSequence[0] | pressedBits)) {
            gRecordTAtt->mButtonSequenceIndex = 1;
            gRecordTAtt->mUnk_84 = FALSE;
        } else if (gRecordTAttButtonSequence[gRecordTAtt->mButtonSequenceIndex] ==
                   (gRecordTAttButtonSequence[gRecordTAtt->mButtonSequenceIndex] | pressedBits)) {
            gRecordTAtt->mButtonSequenceIndex++;
            gRecordTAtt->mUnk_84 = FALSE;
            if (gRecordTAtt->mButtonSequenceIndex >= 6) {
                gRecordTAtt->mButtonSequenceIndex = 0;
                return TRUE;
            }
        } else {
            gRecordTAtt->mButtonSequenceIndex = 0;
        }
    }
    return FALSE;
}

void InitRecordTAtt(void *heap) {
    s32 i;
    s32 k;
    s32 remainingSize;
    RecordTAtt *recordTAtt;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~3) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~3) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~3) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & 0x43) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & 0x43) | 0xcc00;
    (reg_G2S_DB_BG1CNT) = ((reg_G2S_DB_BG1CNT) & 0x43) | 0x1018;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x5810;
    gRecordTAtt = HeapAlloc(heap, 0x94);
    gRecordTAtt->mHeap = heap;
    gRecordTAtt->mState = 0;
    gRecordTAtt->mIndex = 0;
    gRecordTAtt->mIndexMoveDirection = 0;
    gRecordTAtt->mClearChosen = FALSE;
    gRecordTAtt->mLeftRepeat = FALSE;
    gRecordTAtt->mRightRepeat = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordTAtt->mOffsetTimers[i] = 0;
    }
    LocateAndQueueRecordTAtt();
    CreateKartIcon(heap);
    ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    InitLayoutTable(heap, gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMBnll,
                    &gRecordTAtt->mRecordTAttMTable);
    InitLayoutTable(heap, gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSBnll,
                    &gRecordTAtt->mRecordTAttSTable);
    gRecordTAtt->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gRecordTAtt->mGhostMessages = FindSceneFile("ghost.bmg");
    gRecordTAtt->mRecordMessages = FindSceneFile("record.bmg");
    remainingSize = 0x8000;
    remainingSize -=
        InitLabelCanvas(heap, 0, gRecordTAtt->mRecordTAttMBnll, 0xc8, 0x10, 0, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 1, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 1, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 2, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 2, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 3, gRecordTAtt->mRecordTAttMBnll, 0x7c, 0x10, 3, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize -=
        InitLabelCanvas(heap, 4, gRecordTAtt->mRecordTAttMBnll, 0x64, 0x10, 4, gRecordTAtt->mRecordTAttMNcer,
                        gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, remainingSize);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (k = 1; k < 5; k++) {
        remainingSize -= InitLabelCanvas(heap, gRecordTAttTimeLabelIndices[k], gRecordTAtt->mRecordTAttSBnll,
                                         gRecordTAttTimeLabelWidths[k], gRecordTAttTimeLabelHeights[k], k,
                                         gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                                         gRecordTAtt->mRecordTAttSTable, remainingSize);
        remainingSize -= InitLabelCanvas(heap, gRecordTAttNameLabelIndices[k], gRecordTAtt->mRecordTAttSBnll,
                                         gRecordTAttNameLabelWidths[k], gRecordTAttNameLabelHeights[k], k + 5,
                                         gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                                         gRecordTAtt->mRecordTAttSTable, remainingSize);
    }
    InitLabelCanvas(heap, 8, gRecordTAtt->mRecordTAttSBnll, 0x98, 0x10, 0xd, gRecordTAtt->mRecordTAttSNcer,
                    gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, remainingSize);
    recordTAtt = gRecordTAtt;
    PrintLabelLayoutTextNoFixedAdvance(1, 8, gRecordTAtt->mRecordTAttSBnll, GetBmgEntry(recordTAtt->mRecordMessages, 3),
                                       recordTAtt->mRecordTAttSBncl, recordTAtt->mRecordTAttSTable);
    ResetRecordTAtt();
}

void ReleaseRecordTAtt(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    ClearKartIconPointer();
    gRecordTAtt = NULL;
    mainDisplayBits = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~0x1f00) | ((mainDisplayBits & ~0x13) << 8);
    subDisplayBits = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~0x1f00) | ((subDisplayBits & ~9) << 8);
}

void AdvanceRecordTAttState0(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState1AndSetup();
    }
}

void AdvanceRecordTAttState1(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState2();
    }
}

void AdvanceRecordTAttState2(void) {
    s32 touchedRect = -1;
    s32 touchBeganRect = -1;
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    BOOL x;
    BOOL recentlyLost;
    u16 hasPair;

    AdvanceRecordTAttOffsetTimers();
    x = TRUE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && hasPair == 0) {
        x = FALSE;
    }
    if (x != FALSE) {
        touchedRect = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                              gInputSlots[slotIndex].mPair.mPairY);
    }
    x = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        x = TRUE;
    }
    if (x != FALSE) {
        touchBeganRect = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if (touchedRect != 0) {
        gRecordTAtt->mLeftRepeat = FALSE;
    }
    if (touchedRect != 1) {
        gRecordTAtt->mRightRepeat = FALSE;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        x = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slotIndex].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
            x = TRUE;
        }
        if (x == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(
                              gInputSlots[slotIndex].mPair.mPairX, gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto other;
        }
    }
    RequestRecordTAttState5();
    gRecordTAtt->mNextScreen = 0;
    RequestSelectReturnState3WithSound(0);
    goto done;
other:
    if (touchBeganRect == 2 || (u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_X) != 0) {
        RequestRecordTAttState7();
    } else if ((touchedRect == 0 && gRecordTAtt->mLeftRepeat != FALSE) ||
               (touchBeganRect == 0 && gRecordTAtt->mLeftRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_LEFT) != 0) {
        gRecordTAtt->mIndexMoveDirection = 1;
        gRecordTAtt->mOffsetTimers[0] = 6;
        gRecordTAtt->mLeftRepeat = TRUE;
        RequestRecordTAttState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    } else if ((touchedRect == 1 && gRecordTAtt->mRightRepeat != FALSE) ||
               (touchBeganRect == 1 && gRecordTAtt->mRightRepeat == FALSE) ||
               (u16) (gInputSlots[slotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordTAtt->mIndexMoveDirection = 0;
        gRecordTAtt->mOffsetTimers[1] = 6;
        gRecordTAtt->mRightRepeat = TRUE;
        RequestRecordTAttState3();
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 2);
    }
done:
    if (AdvanceRecordTAttButtonSequence() != FALSE) {
        if (CheckRecordTAttFirstRecordFormat() != FALSE) {
            RequestRecordTAttState13();
        }
    }
}

void AdvanceRecordTAttState3(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 targetOffsetX;
    s16 offsetX;

    targetOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case 0:
            targetOffsetX = -0x100;
            break;
        case 1:
            targetOffsetX = 0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState4AndMoveIndex();
    }
}

void AdvanceRecordTAttState4(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 startOffsetX;
    s16 offsetX;

    startOffsetX = 0;
    AdvanceRecordTAttOffsetTimers();
    switch (gRecordTAtt->mIndexMoveDirection) {
        case 0:
            startOffsetX = 0x100;
            break;
        case 1:
            startOffsetX = -0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState2();
    }
}

void AdvanceRecordTAttState5(void) {
    s32 i;
    u16 mainLayoutCount;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = offsetX;
    gRecordTAtt->mBg3OffsetX = offsetX;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState6();
    }
}

void AdvanceRecordTAttState6(void) {
    s16 offsetY;

    gRecordTAtt->mStateFrames++;
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = offsetY;
    gRecordTAtt->mBg1OffsetY = offsetY;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = offsetY;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordScreen(gRecordTAtt->mNextScreen);
    }
}

void AdvanceRecordTAttState7(void) {
    s16 offsetX;
    u16 subLayoutCount;

    gRecordTAtt->mStateFrames++;
    offsetX = GetSelectedPressOffset(gRecordTAtt->mStateFrames);
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState8();
    }
}

void AdvanceRecordTAttState8(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            RequestRecordTAttState9();
        }
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttState9(void) {
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        RequestRecordTAttState10();
    }
}

void AdvanceRecordTAttState10(void) {
    if (GetTxtSystemDone() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            if (IsCourseGhostRecordMissing(gRecordTAttCourseIds[gRecordTAtt->mIndex]) == 0) {
                ClearCourseTimeRecords(gRecordTAttCourseIds[gRecordTAtt->mIndex]);
                WaitThreadFunctionsDone();
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            }
            gRecordTAtt->mClearChosen = TRUE;
        }
        RequestRecordTAttState11();
    }
}

void AdvanceRecordTAttState11(void) {
    s16 offsetX;
    u16 mainLayoutCount;

    gRecordTAtt->mStateFrames++;
    if (gRecordTAtt->mClearChosen != FALSE) {
        offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
        gRecordTAtt->mBg1OffsetX = offsetX;
        mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = offsetX;
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        if (IsTxtSystemState0NoOpenRequest() != 0) {
            RequestRecordTAttState12();
        }
    }
}

void AdvanceRecordTAttState12(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    if (gRecordTAtt->mClearChosen != FALSE) {
        u16 w;

        gRecordTAtt->mBg1OffsetX = offsetX;
        w = gRecordTAtt->mRecordTAttMBncl->mCount;
        gRecordTAtt->mRecordTAttMTable[0].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[4].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[5].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[6].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 1].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 2].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 3].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttMTable[w + 4].mOffsetX = offsetX;
    }
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            RequestRecordTAttState2();
        }
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAttState13(void) {
    s32 i;
    u16 subLayoutCount;
    s32 j;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        RequestRecordTAttState14();
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 0;
        gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
    }
}

void AdvanceRecordTAttState14(void) {
    int txtSystemNoCloseRequest;
    txtSystemNoCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (txtSystemNoCloseRequest != 0) {
        RequestRecordTAttState15();
    }
}

void AdvanceRecordTAttState15(void) {
    InputSlotIndex slotIndex;
    u16 f;
    BOOL recentlyLost;

    slotIndex = UNK_02175628_INDEX_8;
    f = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
    if (f == 0) {
        f = 0;
        recentlyLost = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            f = 1;
        }
        if (f == 0 || IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                      gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            return;
        }
    }
    RequestRecordTAttState16();
    RequestSelectReturnState3WithSound(0);
}

void AdvanceRecordTAttState16(void) {
    int txtSystemNoOpenRequest;
    txtSystemNoOpenRequest = IsTxtSystemState0NoOpenRequest();
    if (txtSystemNoOpenRequest != 0) {
        RequestRecordTAttState17();
    }
}

void AdvanceRecordTAttState17(void) {
    s32 i;
    s32 j;
    u16 subLayoutCount;
    s16 offsetX;

    gRecordTAtt->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = offsetX;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = offsetX;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = offsetX;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[i]].mOffsetX = offsetX;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[i]].mOffsetX = offsetX;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[i][j]].mOffsetX = offsetX;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        RequestRecordTAttState2();
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mVisible = 1;
    }
}

void AdvanceRecordTAtt(void) {
    RecordTAtt *recordTAtt;

    gRecordTAtt->mState = gRecordTAtt->mNextState;
    switch (gRecordTAtt->mState) {
        case 0:
            AdvanceRecordTAttState0();
            break;
        case 1:
            AdvanceRecordTAttState1();
            break;
        case 2:
            AdvanceRecordTAttState2();
            break;
        case 3:
            AdvanceRecordTAttState3();
            break;
        case 4:
            AdvanceRecordTAttState4();
            break;
        case 5:
            AdvanceRecordTAttState5();
            break;
        case 6:
            AdvanceRecordTAttState6();
            break;
        case 7:
            AdvanceRecordTAttState7();
            break;
        case 8:
            AdvanceRecordTAttState8();
            break;
        case 9:
            AdvanceRecordTAttState9();
            break;
        case 10:
            AdvanceRecordTAttState10();
            break;
        case 11:
            AdvanceRecordTAttState11();
            break;
        case 12:
            AdvanceRecordTAttState12();
            break;
        case 13:
            AdvanceRecordTAttState13();
            break;
        case 14:
            AdvanceRecordTAttState14();
            break;
        case 15:
            AdvanceRecordTAttState15();
            break;
        case 16:
            AdvanceRecordTAttState16();
            break;
        case 17:
            AdvanceRecordTAttState17();
            break;
    }
    recordTAtt = gRecordTAtt;
    DrawLayoutTable(recordTAtt->mRecordTAttMBncl, recordTAtt->mRecordTAttMNcer, recordTAtt->mRecordTAttMBnll,
                    GetRecordMainOam(), recordTAtt->mRecordTAttMTable);
    recordTAtt = gRecordTAtt;
    DrawLayoutTable(recordTAtt->mRecordTAttSBncl, recordTAtt->mRecordTAttSNcer, recordTAtt->mRecordTAttSBnll,
                    GetRecordSubOam(), recordTAtt->mRecordTAttSTable);
}

void WriteRecordTAttBgOffsets(void) {
    RecordTAtt *recordTAtt;

    reg_G2_BG0OFS = (-gRecordTAtt->mBg0Offset << 16) & 0x1ff0000;
    recordTAtt = gRecordTAtt;
    reg_G2_BG1OFS = (-recordTAtt->mBg1OffsetX & 0x1ff) | ((-recordTAtt->mBg1OffsetY << 16) & 0x1ff0000);
    reg_G2S_DB_BG3OFS = -gRecordTAtt->mBg3OffsetX & 0x1ff;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordTAttRegisters(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    mainDisplayBits |= 0x13;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (mainDisplayBits << 8);
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    subDisplayBits |= 9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
}

void RegisterRecordTAttCallbacks(void) {
    RecordScreenCallbacks a = gRecordTAttCallbacks;

    SetRecordScreenCallbacks(&a);
}
