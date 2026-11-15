#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
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
#include "03/Net/essid_packet_steps.h"
#include "01/unk_021a8000.h"
#include "Main/Graphics/oam.h"
#include "01/code_02198000.h"
#include "01/unk_021a9000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/record_scene.h"

// Defined const in record_time_attack.c; declared non-const here.
extern s32 gRecordTAttRecordIndices[];

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
    gRecordTAtt->mPlayerCharacterChars = GetPlayerCharacterNcgr(0);
    gRecordTAtt->mPlayerCharacterCells = GetPlayerCharacterNcer(0);
    gRecordTAtt->mPlayerCharacterPalette = GetPlayerCharacterNclr(0);
    gRecordTAtt->mPlayerCharacterCellLayout = GetPlayerCharacterBncl(0);
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
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
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
        QueueCellChars(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterChars,
                       gRecordTAtt->mPlayerCharacterCellLayout, 0, index, gRecordTAtt->mRecordTAttMNcer,
                       gRecordTAtt->mRecordTAttMBncl);
        palette = (u8 *) gRecordTAtt->mPlayerCharacterPalette->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0xe, gRecordTAttPaletteSlots[0][0] << 5,
            palette +
                (GetCellPaletteIndex(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterCellLayout)
                 << 5),
            0x20);
        result = GetTimeRecordKartIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        slot = gRecordTAttCharacterKartCellIndices[0][1];
        gRecordTAtt->mRecordTAttMTable[slot].mVisible = 1;
        QueueKartIcon(result, gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl, slot,
                      gRecordTAttPaletteSlots[1][0], 0);
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
        QueueCellChars(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterChars,
                       gRecordTAtt->mPlayerCharacterCellLayout, 1, index, gRecordTAtt->mRecordTAttSNcer,
                       gRecordTAtt->mRecordTAttSBncl);
        palette = (u8 *) gRecordTAtt->mPlayerCharacterPalette->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0x1e, gRecordTAttPaletteSlots[0][row] << 5,
            palette +
                (GetCellPaletteIndex(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterCellLayout)
                 << 5),
            0x20);
        result = GetTimeRecordKartIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], recordIndex);
        slot = gRecordTAttCharacterKartCellIndices[row][1];
        gRecordTAtt->mRecordTAttSTable[slot].mVisible = 1;
        QueueKartIcon(result, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl, slot,
                      gRecordTAttPaletteSlots[1][row], 1);
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
        gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[row][1]].mVisible = 0;
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
    s32 recordIndex;
    s32 result;
    u16 tile;
    u8 *palette;
    u16 mainLayoutCount;

    recordTAtt = gRecordTAtt;
    PrintLabelLayoutTextNoFixedAdvance(
        0, 0, gRecordTAtt->mRecordTAttMBnll,
        GetBmgEntry(recordTAtt->mCommonMessages, gRecordTAttCommonMessageIndices[recordTAtt->mIndex]),
        recordTAtt->mRecordTAttMBncl, recordTAtt->mRecordTAttMTable);
    for (recordIndex = 0; recordIndex < 5; recordIndex++) {
        if (IsTimeRecordFilled(gRecordTAttCourseIds[gRecordTAtt->mIndex], gRecordTAttRecordIndices[recordIndex])) {
            SetupRecordTAttRowValues(recordIndex);
        } else {
            SetupRecordTAttRowDashes(recordIndex);
        }
    }
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    if (IsTimeRecordFilled(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5)) {
        result = GetTimeRecordCharacterIndex(gRecordTAttCourseIds[gRecordTAtt->mIndex], 5);
        gRecordTAtt->mRecordTAttMTable[5].mVisible = 1;
        tile = gRecordTAttCharacterCells[result];
        QueueCellChars(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterChars,
                       gRecordTAtt->mPlayerCharacterCellLayout, 0, 5, gRecordTAtt->mRecordTAttMNcer,
                       gRecordTAtt->mRecordTAttMBncl);
        palette = (u8 *) gRecordTAtt->mPlayerCharacterPalette->mData;
        NNS_GfdRegisterNewVramTransferTask(
            0xe, 0x80,
            palette +
                (GetCellPaletteIndex(tile, gRecordTAtt->mPlayerCharacterCells, gRecordTAtt->mPlayerCharacterCellLayout)
                 << 5),
            0x20);
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
    s32 recordIndex;
    s32 cellIndex;
    u16 mainLayoutCount;
    u16 subLayoutCount;

    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_IN_TOP;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mBg0Offset = -192;
    gRecordTAtt->mBg1OffsetX = -256;
    gRecordTAtt->mBg1OffsetY = -192;
    gRecordTAtt->mBg3OffsetX = -256;
    mainLayoutCount = gRecordTAtt->mRecordTAttMBncl->mCount;
    subLayoutCount = gRecordTAtt->mRecordTAttSBncl->mCount;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetY = -192;
    gRecordTAtt->mRecordTAttMTable[0].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[1].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[2].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[3].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[4].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[5].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[6].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 1].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 2].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 3].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttMTable[mainLayoutCount + 4].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[15].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[16].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[12].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[13].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[14].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gRecordTAtt->mRecordTAttSTable[subLayoutCount + 8].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    for (recordIndex = 1; recordIndex < 5; recordIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttOffsetSTableIndices[recordIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttTimeLabelIndices[recordIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        gRecordTAtt->mRecordTAttSTable[subLayoutCount + gRecordTAttNameLabelIndices[recordIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        for (cellIndex = 0; cellIndex < 2; cellIndex++) {
            gRecordTAtt->mRecordTAttSTable[gRecordTAttCharacterKartCellIndices[recordIndex][cellIndex]].mOffsetX =
                LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        }
    }
    for (cellIndex = 0; cellIndex < 2; cellIndex++) {
        gRecordTAtt->mRecordTAttSTable[gRecordTAttRunningSTableIndices[cellIndex]].mVisible = 0;
    }
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
}

void RequestRecordTAttState1AndSetup(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_IN_RIGHT;
    gRecordTAtt->mStateFrames = 0;
    SetupRecordTAtt();
}

void RequestRecordTAttState2(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_INPUT;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mClearChosen = FALSE;
}

// Requests state 3.
void RequestRecordTAttState3(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_OUT_SIDE;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState4AndMoveIndex(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_IN_SIDE;
    gRecordTAtt->mStateFrames = 0;
    switch (gRecordTAtt->mIndexMoveDirection) {
        case RECORD_INDEX_MOVE_NEXT:
            IncrementRecordTAttIndex();
            break;
        case RECORD_INDEX_MOVE_PREVIOUS:
            DecrementRecordTAttIndex();
            break;
    }
    SetupRecordTAtt();
}

// Requests state 5.
void RequestRecordTAttState5(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_OUT_RIGHT;
    gRecordTAtt->mStateFrames = 0;
}

// Requests state 6.
void RequestRecordTAttState6(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_OUT_TOP;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState7(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_PRESS_BUTTON;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 1;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
}

void RequestRecordTAttState8(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_OUT_FOR_CLEAR_PROMPT;
    gRecordTAtt->mStateFrames = 0;
    RequestSelectReturnSlideOut();
}

void RequestRecordTAttState9(void) {
    u16 buf[0x102];
    RecordTAtt *recordTAtt;
    void *text;
    void *secondButtonText;

    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_OPEN;
    gRecordTAtt->mStateFrames = 0;
    buf[0] = 0;
    MIi_CpuClear16(buf[0], &buf[1], 0x200);
    recordTAtt = gRecordTAtt;
    text = GetBmgEntry(recordTAtt->mGhostMessages, gRecordTAttGhostMessageIndices[recordTAtt->mIndex]);
    FormatMessageWithText(text, GetBmgEntry(recordTAtt->mRecordMessages, 10), &buf[1], 0x200);
    text = GetBmgEntry(gRecordTAtt->mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gRecordTAtt->mCommonMessages, 1);
    SetupTxtSystemSubTextTwoButtonsEx(&buf[1], text, secondButtonText, 1, 0, 1, 1, 1);
}

void RequestRecordTAttState10(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_CLEAR_ANSWER;
    gRecordTAtt->mStateFrames = 0;
    SetTxtSystemSoundId(0, 11);
}

void RequestRecordTAttState11(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_CLOSE;
    gRecordTAtt->mStateFrames = 0;
    RequestTxtSystemClose();
    SetTxtSystemSoundId(0, 5);
}

void RequestRecordTAttState12(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_IN_AFTER_CLEAR_PROMPT;
    gRecordTAtt->mStateFrames = 0;
    RequestSelectReturnSlideIn();
    SetupRecordTAtt();
    gRecordTAtt->mRecordTAttSTable[13].mVisible = 0;
}

void RequestRecordTAttState13(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_OUT_FOR_TIME_TEXT;
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
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_TIME_TEXT_OPEN;
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
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_TIME_TEXT_INPUT;
    gRecordTAtt->mStateFrames = 0;
}

void RequestRecordTAttState16(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_WAIT_TIME_TEXT_CLOSE;
    gRecordTAtt->mStateFrames = 0;
    RequestTxtSystemClose();
}

// Requests state 17.
void RequestRecordTAttState17(void) {
    gRecordTAtt->mNextState = RECORD_TATT_STATE_SLIDE_IN_AFTER_TIME_TEXT;
    gRecordTAtt->mStateFrames = 0;
}

const u16 gRecordTAttPaletteSlots[2][5] = {{3, 3, 4, 5, 6}, {5, 7, 8, 9, 10}};
const u16 gRecordTAttCharacterKartCellIndices[5][2] = {{3, 4}, {4, 8}, {5, 9}, {6, 10}, {7, 11}};
const u16 gRecordTAttCharacterCells[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const s32 gRecordTAttCommonMessageIndices[32] = {
    0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c,
    0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c,
};
const s32 gRecordTAttCourseIds[32] = {
    0x14, 0x16, 0x1f, 0x12, 0x1b, 0x1c, 0x21, 0x18, 0x1e, 0x11, 0x19, 0x13, 0x22, 0x1a, 0x20, 0x1d,
    0x0a, 0x0b, 0x0d, 0x0e, 0x23, 0x10, 0x0c, 0x09, 0x0f, 0x24, 0x25, 0x26, 0x27, 0x17, 0x28, 0x01,
};
const s32 gRecordTAttGhostMessageIndices[32] = {
    0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42,
    0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52,
};
