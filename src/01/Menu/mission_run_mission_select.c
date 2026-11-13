#include "01/Menu/mission_run_mission_select.h"

#include "code_0200eddc.h"
#include "Main/Graphics/layout_rect_table.h"
#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/Menu/mission_run_boss_icon.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/select_return.h"
#include "player.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "01/code_021a0000.h"
#include "01/unk_021a9000.h"
#include "Main/Race/mission_table_value.h"
#include "code_0212df7c.h"
#include "code_02148950.h"
#include "registers.h"
#include "01/code_021a1000.h"
#include "01/Menu/select_engine.h"
#include "01/MapObjects/periodic_effect.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u16 gMissionRunMSselValueMTableIndices[6] = {0x15, 0x14, 0x13, 0x16, 0x17, 0x18};
const s16 gMissionRunMSselRectIndices[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const u16 gMissionRunMSselLabelSTableIndices[9][2] = {{0, 9},   {1, 0xa}, {2, 0xb},  {3, 0xc}, {4, 0xd},
                                                      {5, 0xe}, {6, 0xf}, {7, 0x10}, {8, 0x11}};
const s16 gMissionRunMSselDownSteps[9] = {3, 7, 2, 2, 3, 0, 0, 0, -2};
const u16 gMissionRunMSselLabelWidths[9][2] = {{0xe, 0x28}, {0xe, 0x28}, {0xe, 0x28}, {0xe, 0x28}, {0xe, 0x28},
                                               {0xe, 0x28}, {0xe, 0x28}, {0xe, 0x28}, {0xe, 0x28}};
const s16 gMissionRunMSselLeftSteps[9] = {0, -1, -1, 0, 4, 0, -1, -1, -5};
const u16 gMissionRunMSselIndexMTableIndices[9] = {0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0xa};
const s16 gMissionRunMSselUpSteps[9] = {0, 0, 0, -3, -2, -2, 2, -3, -7};
const u16 gMissionRunMSselIndexSTableIndices[9][9] = {
    {0, 9, 0x12, 0x1b, 0x2c, 0x2e, 0x37, 0x38, 0x39},   {1, 0xa, 0x13, 0x1c, 0x25, 0x2f, 0x3a, 0x3b, 0x3c},
    {2, 0xb, 0x14, 0x1d, 0x26, 0x30, 0x3d, 0x3e, 0x3f}, {3, 0xc, 0x15, 0x1e, 0x27, 0x31, 0x40, 0x41, 0x42},
    {4, 0xd, 0x16, 0x1f, 0x28, 0x32, 0x43, 0x44, 0x45}, {5, 0xe, 0x17, 0x20, 0x29, 0x33, 0x46, 0x47, 0x48},
    {6, 0xf, 0x18, 0x21, 0x2a, 0x34, 0x49, 0x4a, 0x4b}, {7, 0x10, 0x19, 0x22, 0x2b, 0x35, 0x4c, 0x4d, 0x4e},
    {8, 0x11, 0x1a, 0x23, 0x24, 0x36, 0x4f, 0x50, 0x51}};
const u16 gMissionRunMSselRowMTableIndices[7] = {2, 3, 4, 5, 6, 7, 8};
const u16 gMissionRunMSselLabelHeights[9][2] = {{0xe, 0xe}, {0xe, 0xe}, {0xe, 0xe}, {0xe, 0xe}, {0xe, 0xe},
                                                {0xe, 0xe}, {0xe, 0xe}, {0xe, 0xe}, {0xe, 0xe}};
const s16 gMissionRunMSselRightSteps[9] = {1, 1, 0, 5, 0, 1, 1, 0, -4};
const char *gMissionRunMSselMNscrName = gMissionRunMSselMNscrFileName;
u16 gMissionRunMSselGradeTextC[2] = {0x43, 0};
const char *gMissionRunMSselSBnblName = gMissionRunMSselSBnblFileName;
const char *gMissionRunMSselMBNclrName = gMissionRunMSselMBNclrFileName;
const char *gMissionRunMSselMWNscrName = gMissionRunMSselMWNscrFileName;
u16 gMissionRunMSselGradeTextB[2] = {0x42, 0};
u16 gMissionRunMSselGradeTextE[2] = {0x45, 0};
const char *gMissionRunMSselMBNcgrName = gMissionRunMSselMBNcgrFileName;
const char *gMissionRunMSselMNcgrName = gMissionRunMSselMNcgrFileName;
const char *gMissionRunMSselMBnclName = gMissionRunMSselMBnclFileName;
const char *gMissionRunMSselMONclrName = gMissionRunMSselMONclrFileName;
const char *gMissionRunMSselSNcerName = gMissionRunMSselSNcerFileName;
const char *gMissionRunMSselSONclrName = gMissionRunMSselSONclrFileName;
u16 gMissionRunMSselGradeTextD[2] = {0x44, 0};
const char *gMissionRunMSselMBnllName = gMissionRunMSselMBnllFileName;
const char *gMissionRunMSselSBnllName = gMissionRunMSselSBnllFileName;
const char *gMissionRunMSselSNcgrName = gMissionRunMSselSNcgrFileName;
const char *gMissionRunMSselMNcerName = gMissionRunMSselMNcerFileName;
const char *gMissionRunMSselSBnclName = gMissionRunMSselSBnclFileName;
u16 gMissionRunMSselGradeTextA[2] = {0x41, 0};
u16 *gMissionRunMSselGradeStrings[5] = {gMissionRunMSselGradeTextE, gMissionRunMSselGradeTextD,
                                        gMissionRunMSselGradeTextC, gMissionRunMSselGradeTextB,
                                        gMissionRunMSselGradeTextA};
char gMissionRunMSselMBnllFileName[28] = "mr/Mission_run_MSsel_m.bnll";
char gMissionRunMSselSBnclFileName[28] = "mr/Mission_run_MSsel_s.bncl";
char gMissionRunMSselSBnblFileName[28] = "mr/Mission_run_MSsel_s.bnbl";
char gMissionRunMSselMNscrFileName[28] = "mr/Mission_run_MSsel_m.nscr";
char gMissionRunMSselSBnllFileName[28] = "mr/Mission_run_MSsel_s.bnll";
char gMissionRunMSselMBnclFileName[28] = "mr/Mission_run_MSsel_m.bncl";
char gMissionRunMSselMWNscrFileName[30] = "mr/Mission_run_MSsel_m_w.nscr";
char gMissionRunMSselMBNclrFileName[30] = "mr/Mission_run_MSsel_m_b.nclr";
char gMissionRunMSselMONclrFileName[30] = "mr/Mission_run_MSsel_m_o.nclr";
char gMissionRunMSselSONclrFileName[30] = "mr/Mission_run_MSsel_s_o.nclr";
char gMissionRunMSselMBNcgrFileName[30] = "mr/Mission_run_MSsel_m_b.ncgr";
char gMissionRunMSselMNcgrFileName[32] = "mr/Mission_run_MSsel_m.nce.ncgr";
char gMissionRunMSselMNcerFileName[32] = "mr/Mission_run_MSsel_m.nce.ncer";
char gMissionRunMSselSNcgrFileName[32] = "mr/Mission_run_MSsel_s.nce.ncgr";
char gMissionRunMSselSNcerFileName[32] = "mr/Mission_run_MSsel_s.nce.ncer";
MissionRunMSsel *gMissionRunMSsel;

void LoadMissionRunMSselAndBossIconData(void) {
    Ncgr *missionRunMSselMChars = NULL;
    Unk02021dc8 *missionRunMSselMCells = NULL;
    Nclr *missionRunMSselMOPalette = NULL;
    Ncgr *missionRunMSselSChars = NULL;
    Unk02021dc8 *missionRunMSselSCells = NULL;
    Nclr *missionRunMSselSOPalette = NULL;
    Ncgr *missionRunMSselMBChars = NULL;
    Nscr *missionRunMSselMWScreenMap = NULL;
    Nscr *missionRunMSselMScreenMap = NULL;
    Nclr *missionRunMSselMBPalette = NULL;

    LoadNcgrData(&missionRunMSselMBChars, FindSceneFile(gMissionRunMSselMBNcgrName));
    LoadNclrData(&missionRunMSselMBPalette, FindSceneFile(gMissionRunMSselMBNclrName));
    LoadNscrData(&missionRunMSselMWScreenMap, FindSceneFile(gMissionRunMSselMWNscrName));
    LoadNscrData(&missionRunMSselMScreenMap, FindSceneFile(gMissionRunMSselMNscrName));
    LoadNcgrData2(&missionRunMSselMChars, FindSceneFile(gMissionRunMSselMNcgrName));
    LoadNcerData(&missionRunMSselMCells, FindSceneFile(gMissionRunMSselMNcerName));
    LoadNclrData(&missionRunMSselMOPalette, FindSceneFile(gMissionRunMSselMONclrName));
    LoadNcgrData2(&missionRunMSselSChars, FindSceneFile(gMissionRunMSselSNcgrName));
    LoadNcerData(&missionRunMSselSCells, FindSceneFile(gMissionRunMSselSNcerName));
    LoadNclrData(&missionRunMSselSOPalette, FindSceneFile(gMissionRunMSselSONclrName));
    LoadMissionRunBossIconData();
}

void LocateAndQueueMissionRunMSsel(void) {
    Ncgr *missionRunMSselMChars = NULL;
    Nclr *missionRunMSselMOPalette = NULL;
    Ncgr *missionRunMSselSChars = NULL;
    Ncgr *missionRunMSselMBChars = NULL;
    Nscr *missionRunMSselMWScreenMap = NULL;
    Nscr *missionRunMSselMScreenMap = NULL;
    Nclr *missionRunMSselMBPalette = NULL;
    u16 *paletteData;

    LocateNcgr(&missionRunMSselMBChars, FindSceneFile(gMissionRunMSselMBNcgrName));
    LocateNclr(&missionRunMSselMBPalette, FindSceneFile(gMissionRunMSselMBNclrName));
    LocateNscr(&missionRunMSselMWScreenMap, FindSceneFile(gMissionRunMSselMWNscrName));
    LocateNscr(&missionRunMSselMScreenMap, FindSceneFile(gMissionRunMSselMNscrName));
    gMissionRunMSsel->mVramTransferBuffer = HeapAlloc(gMissionRunMSsel->mHeap, 0x800);
    gMissionRunMSsel->mMissionRunMSselMBncl = FindSceneFile(gMissionRunMSselMBnclName);
    gMissionRunMSsel->mMissionRunMSselMBnll = FindSceneFile(gMissionRunMSselMBnllName);
    LocateNcgr2(&missionRunMSselMChars, FindSceneFile(gMissionRunMSselMNcgrName));
    LocateNcer(&gMissionRunMSsel->mMissionRunMSselMNcer, FindSceneFile(gMissionRunMSselMNcerName));
    LocateNclr(&missionRunMSselMOPalette, FindSceneFile(gMissionRunMSselMONclrName));
    gMissionRunMSsel->mMissionRunMSselSBncl = FindSceneFile(gMissionRunMSselSBnclName);
    gMissionRunMSsel->mMissionRunMSselSBnbl = FindSceneFile(gMissionRunMSselSBnblName);
    gMissionRunMSsel->mMissionRunMSselSBnll = FindSceneFile(gMissionRunMSselSBnllName);
    LocateNcgr2(&missionRunMSselSChars, FindSceneFile(gMissionRunMSselSNcgrName));
    LocateNcer(&gMissionRunMSsel->mMissionRunMSselSNcer, FindSceneFile(gMissionRunMSselSNcerName));
    LocateNclr(&gMissionRunMSsel->mMissionRunMSselSOPalette, FindSceneFile(gMissionRunMSselSONclrName));
    paletteData = missionRunMSselMOPalette->mData;
    NNS_GfdRegisterNewVramTransferTask(4, 0, missionRunMSselMBChars->mData, missionRunMSselMBChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, missionRunMSselMBPalette->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(8, 0, missionRunMSselMWScreenMap->mData, missionRunMSselMWScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gMissionRunMSsel->mVramTransferBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(8, 0x1000, gMissionRunMSsel->mVramTransferBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(8, 0x1800, gMissionRunMSsel->mVramTransferBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(9, 0, missionRunMSselMScreenMap->mData, missionRunMSselMScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(9, 0x800, gMissionRunMSsel->mVramTransferBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, missionRunMSselMChars->mData, missionRunMSselMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, missionRunMSselMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, missionRunMSselSChars->mData, missionRunMSselSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gMissionRunMSsel->mMissionRunMSselSOPalette->mData,
                                       gMissionRunMSsel->mMissionRunMSselSOPalette->mDataSize);
}

void SetMissionRunMSselAllRecorded(void) {
    s32 out;
    s32 missionIndex;

    gMissionRunMSsel->mAllRecorded = 1;
    for (missionIndex = 0; missionIndex < 8; missionIndex++) {
        gMissionRunMSsel->mAllRecorded &=
            GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (missionIndex + 1), &out);
    }
}

void FormatMissionRunMissionNumber(s32 missionIndex, u16 *text) {
    FormatAsciiNumber(GetMissionTableRow(), text);
    text[1] = 0x2d;
    FormatAsciiNumber(missionIndex + 1, text + 2);
    text[3] = 0;
}

void InitMissionRunMSselCells(void) {
    u16 subLayoutCellCount;
    s32 missionIndex;
    u16 mainLayoutCellCount;
    s32 slotIndex;
    s32 out;
    u16 text[18];
    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[missionIndex]].mVisible = 0;
        for (slotIndex = 0; slotIndex < 9; slotIndex++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][slotIndex]]
                .mVisible = 0;
        }
        for (slotIndex = 0; slotIndex < 2; slotIndex++) {
            gMissionRunMSsel
                ->mMissionRunMSselSTable[subLayoutCellCount +
                                         gMissionRunMSselLabelSTableIndices[missionIndex][slotIndex]]
                .mVisible = 0;
        }
    }
    for (slotIndex = 0; slotIndex < 7; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mVisible = 0;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mVisible = 1;
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        if (missionIndex == 8) {
            if (gMissionRunMSsel->mAllRecorded != 0) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible =
                    1;
                QueueMissionRunBossIcon((s16) (GetMissionTableRow() - 1), 1, gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl, 0x2d, 8, 1);
            } else {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][4]].mVisible =
                    1;
                QueueMissionRunBossIcon((s16) (GetMissionTableRow() - 1), 0, gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl, 0x2d, 8, 1);
            }
        } else {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible = 1;
        }
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 1;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][2]].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][3]].mVisible = 0;
        if (GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (missionIndex + 1), &out)) {
            if (out <= 4) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][5]].mVisible =
                    1;
                gMissionRunMSsel
                    ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[missionIndex][0]]
                    .mVisible = 1;
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gMissionRunMSselLabelSTableIndices[missionIndex][0], gMissionRunMSsel->mMissionRunMSselSBnll,
                    gMissionRunMSselGradeStrings[out], gMissionRunMSsel->mMissionRunMSselSBncl,
                    gMissionRunMSsel->mMissionRunMSselSTable);
            } else if (out <= 7) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][out + 1]]
                    .mVisible = 1;
            }
            if (missionIndex == 8) {
                gMissionRunMSsel->mBossRecorded = TRUE;
            }
        }
        LoadMissionRunMSselSoundData(0, GetMissionTableRow());
        if (missionIndex == 8) {
            SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][2], 2,
                                gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl);
            SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][1], 5,
                                gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl);
            if (gMissionRunMSsel->mAllRecorded != 0) {
                if (GetPreviousMenuScreenNumber() == SCREEN_MISSION_RUN_LVSEL) {
                    gMissionRunMSsel->mIndex = 8;
                }
                if (gMissionRunMSsel->mBossRecorded == FALSE) {
                    gMissionRunMSsel->mIndex = 8;
                    SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][2], 0xb,
                                        gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl);
                    SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][1], 0xe,
                                        gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl);
                    LoadMissionRunMSselSoundData(3, GetMissionTableRow());
                }
            }
        }
        gMissionRunMSsel
            ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[missionIndex][1]]
            .mVisible = 1;
        FormatMissionRunMissionNumber((s16) missionIndex, text);
        PrintLabelLayoutTextNoFixedAdvance(
            1, gMissionRunMSselLabelSTableIndices[missionIndex][1], gMissionRunMSsel->mMissionRunMSselSBnll, text,
            gMissionRunMSsel->mMissionRunMSselSBncl, gMissionRunMSsel->mMissionRunMSselSTable);
        SetCellOamModeXlu(gMissionRunMSselIndexSTableIndices[missionIndex][0], 1,
                          gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl);
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mVisible = 1;
}

void AdvanceMissionRunMSselPaletteBlend(void) {
    s32 colorIndex;
    s32 fromRed;
    s32 fromGreen;
    s32 fromBlue;
    s32 toRed;
    s32 toGreen;
    s32 toBlue;
    s32 fromPaletteRow;
    s32 toPaletteRow;
    s32 blendPaletteRow;
    volatile u16 zero;
    u16 *palette;
    s32 fromColor;
    s32 toColor;
    s32 blendFrame;
    s32 secondHalfFrame;
    s32 channelDifference;
    s32 red;
    s32 green;
    s32 blue;

    if (gMissionRunMSsel->mAllRecorded != 0) {
        if (gMissionRunMSsel->mBossRecorded == FALSE) {
            gMissionRunMSsel->mPaletteBlendFrame = gMissionRunMSsel->mPaletteBlendFrame + 1;
            if (gMissionRunMSsel->mPaletteBlendFrame >= 100) {
                gMissionRunMSsel->mPaletteBlendFrame = 0;
            }
            if (gMissionRunMSsel->mIndex == 8) {
                fromPaletteRow = 9;
                toPaletteRow = 10;
                blendPaletteRow = 11;
            } else {
                fromPaletteRow = 12;
                toPaletteRow = 13;
                blendPaletteRow = 14;
            }
            zero = 0;
            MIi_CpuClear16(zero, gMissionRunMSsel->mBlendedPalette, 0x20);
            palette = gMissionRunMSsel->mMissionRunMSselSOPalette->mData;
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                fromColor = (palette + fromPaletteRow * 16)[colorIndex];
                toColor = (palette + toPaletteRow * 16)[colorIndex];
                fromRed = fromColor & 0x1f;
                fromGreen = (fromColor & 0x3e0) >> 5;
                fromBlue = (fromColor & 0x7c00) >> 10;
                toRed = toColor & 0x1f;
                toGreen = (toColor & 0x3e0) >> 5;
                toBlue = (toColor & 0x7c00) >> 10;
                blendFrame = gMissionRunMSsel->mPaletteBlendFrame;
                if (blendFrame < 50) {
                    red = fromRed + blendFrame * (toRed - fromRed) * 2 / 100;
                    green = fromGreen + blendFrame * (toGreen - fromGreen) * 2 / 100;
                    blue = fromBlue + blendFrame * (toBlue - fromBlue) * 2 / 100;
                } else {
                    secondHalfFrame = blendFrame - 50;
                    channelDifference = fromRed - toRed;
                    red = toRed + channelDifference * secondHalfFrame * 2 / 100;
                    channelDifference = fromGreen - toGreen;
                    green = toGreen + channelDifference * secondHalfFrame * 2 / 100;
                    channelDifference = fromBlue - toBlue;
                    blue = toBlue + channelDifference * secondHalfFrame * 2 / 100;
                }
                gMissionRunMSsel->mBlendedPalette[colorIndex] = red | ((blue << 10) | (green << 5));
            }
            DC_FlushRange(gMissionRunMSsel->mBlendedPalette, 0x20);
            NNS_GfdRegisterNewVramTransferTask(0x1e, blendPaletteRow << 5, gMissionRunMSsel->mBlendedPalette, 0x20);
        }
    }
}

void UpdateMissionRunMSselIndexCells(void) {
    s32 missionIndex;
    s32 remainingFrames;
    s16 offsetY;
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][2]].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][3]].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][4]].mVisible = 0;
        remainingFrames = gMissionRunMSsel->mIndexCellTimers[missionIndex];
        if (remainingFrames > 0) {
            gMissionRunMSsel->mIndexCellTimers[missionIndex] = remainingFrames - 1;
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][3]].mVisible = 1;
            offsetY =
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][2]].mOffsetY +
                1;
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][3]].mOffsetY =
                offsetY;
        } else if (gMissionRunMSsel->mIndex == missionIndex) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][2]].mVisible = 1;
        } else if (missionIndex == 8) {
            if (gMissionRunMSsel->mAllRecorded) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible =
                    1;
            } else {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][4]].mVisible =
                    1;
            }
        } else {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible = 1;
        }
    }
}

void RefreshMissionRunMSselMCells(void) {
    MissionRunMSsel *missionRunMSsel;
    s32 slotIndex;
    s32 out;
    s32 hasRecord;
    gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[GetMissionTableRow() - 1]].mVisible = 0;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mVisible = 0;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mVisible = 0;
    }
    if (gMissionRunMSsel->mIndex == 8) {
        gMissionRunMSsel->mMissionRunMSselMTable[0].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselMTable[1].mVisible = 1;
    } else {
        gMissionRunMSsel->mMissionRunMSselMTable[0].mVisible = 1;
        gMissionRunMSsel->mMissionRunMSselMTable[1].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[GetMissionTableRow() - 1]].mVisible =
            1;
        gMissionRunMSsel->mMissionRunMSselMTable[9].mVisible = 1;
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[gMissionRunMSsel->mIndex]]
            .mVisible = 1;
    }
    hasRecord = GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (gMissionRunMSsel->mIndex + 1), &out);
    gMissionRunMSsel->mMissionRunMSselMTable[18].mVisible = 0;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mVisible = 0;
    }
    if (hasRecord != 0 && out <= 7) {
        if (out <= 4) {
            gMissionRunMSsel->mMissionRunMSselMTable[18].mVisible = 1;
        }
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[out - 2]].mVisible = 1;
    }
    missionRunMSsel = gMissionRunMSsel;
    PrintLabelLayoutTextNoFixedAdvance(
        0, 0, gMissionRunMSsel->mMissionRunMSselMBnll,
        GetBmgEntry(missionRunMSsel->mMissionMessages,
                    missionRunMSsel
                        ->mMissionFileRows[GetMissionTableValue(gMissionRunMSsel->mMissionTableMtbl,
                                                                GetMissionTableRow(), missionRunMSsel->mIndex + 1) -
                                           1]
                        .mUnk_0c),
        missionRunMSsel->mMissionRunMSselMBncl, missionRunMSsel->mMissionRunMSselMTable);
}

void SetMissionFromMissionRunMSsel(void) {
    u32 missionTableRow;
    u32 missionTableColumn;

    SetMissionTableColumn((s8) (gMissionRunMSsel->mIndex + 1));
    missionTableRow = GetMissionTableRow();
    missionTableColumn = GetMissionTableColumn();
    SetMissionFileRowIndex(
        (u16) (GetMissionTableValue(gMissionRunMSsel->mMissionTableMtbl, missionTableRow, missionTableColumn) - 1));
}

BOOL IsMissionRunMSselIndexChangeRunning(void) {
    if (gMissionRunMSsel->mIndexChangeTimer != 0) {
        return TRUE;
    }
    return FALSE;
}

void AdvanceMissionRunMSselIndexChange(void) {
    u16 mainLayoutCellCount;
    s16 offsetY;
    s32 slotIndex;

    if (IsMissionRunMSselIndexChangeRunning() != FALSE) {
        if (gMissionRunMSsel->mIndexChangeTimer == 7) {
            gMissionRunMSsel->mShownIndex = gMissionRunMSsel->mIndex;
            RefreshMissionRunMSselMCells();
        } else {
            mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
            offsetY = LookupIndexChangeOffset(7 - gMissionRunMSsel->mIndexChangeTimer, 1);
            gMissionRunMSsel->mBg0OffsetY = offsetY;
            gMissionRunMSsel->mMissionRunMSselMTable[0].mOffsetY = offsetY;
            gMissionRunMSsel->mMissionRunMSselMTable[1].mOffsetY = offsetY;
            gMissionRunMSsel->mMissionRunMSselMTable[9].mOffsetY = offsetY;
            gMissionRunMSsel->mMissionRunMSselMTable[18].mOffsetY = offsetY;
            for (slotIndex = 0; slotIndex < 7; slotIndex++) {
                gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mOffsetY =
                    offsetY;
            }
            for (slotIndex = 0; slotIndex < 6; slotIndex++) {
                gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mOffsetY =
                    offsetY;
            }
            gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mOffsetY = offsetY;
            for (slotIndex = 0; slotIndex < 9; slotIndex++) {
                gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mOffsetY =
                    offsetY;
            }
        }
        gMissionRunMSsel->mIndexChangeTimer = gMissionRunMSsel->mIndexChangeTimer - 1;
    } else if (gMissionRunMSsel->mIndex != gMissionRunMSsel->mShownIndex) {
        gMissionRunMSsel->mIndexChangeTimer = 7;
    }
}

void ResetMissionRunMSselOffsets(void) {
    s32 slotIndex;
    s32 cellSlot;
    u16 mainLayoutCellCount;
    u16 subLayoutCellCount;

    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    gMissionRunMSsel->mNextState = 0;
    gMissionRunMSsel->mStateFrames = 0;
    gMissionRunMSsel->mBg0OffsetX = 0x100;
    gMissionRunMSsel->mBg0OffsetY = 0;
    gMissionRunMSsel->mBg1Offset = -192;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mOffsetX = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mOffsetX = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mOffsetX = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mOffsetX = 0x100;
    for (slotIndex = 0; slotIndex < 7; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mOffsetX = 0x100;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mOffsetX = 0x100;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mOffsetX = 0x100;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mOffsetX = 0x100;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mOffsetX = 0x100;
        for (cellSlot = 0; cellSlot < 9; cellSlot++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[slotIndex][cellSlot]].mOffsetX =
                0x100;
        }
        for (cellSlot = 0; cellSlot < 2; cellSlot++) {
            gMissionRunMSsel
                ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[slotIndex][cellSlot]]
                .mOffsetX = 0x100;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState1.
void RequestMissionRunMSselState1(void) {
    gMissionRunMSsel->mNextState = 1;
    gMissionRunMSsel->mStateFrames = 0;
}

void RequestMissionRunMSselState2(void) {
    gMissionRunMSsel->mNextState = 2;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState3.
void RequestMissionRunMSselState3(void) {
    gMissionRunMSsel->mNextState = 3;
    gMissionRunMSsel->mStateFrames = 0;
}

s32 RequestMissionRunMSselState4(void) {
    gMissionRunMSsel->mNextState = 4;
    gMissionRunMSsel->mStateFrames = 0;
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestMissionRunMSselState5(void) {
    s32 missionIndex;
    void *firstText;

    gMissionRunMSsel->mNextState = 5;
    gMissionRunMSsel->mStateFrames = 0;
    firstText = GetBmgEntry(gMissionRunMSsel->mCommonMessages, 4);
    StartSelectChoises(firstText, GetBmgEntry(gMissionRunMSsel->mCommonMessages, 2), 0);
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 0;
    }
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState6.
void RequestMissionRunMSselState6(void) {
    gMissionRunMSsel->mNextState = 6;
    gMissionRunMSsel->mStateFrames = 0;
}

void RequestMissionRunMSselState7(void) {
    gMissionRunMSsel->mNextState = 7;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestMissionRunMSselState8(void) {
    gMissionRunMSsel->mNextState = 8;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectReturnState4();
    switch (gMissionRunMSsel->mResult) {
        case 1:
            StopMissionRunMSselSeqsWithSteps(4, 10, GetMissionTableRow());
            break;
        case 2:
            StopMissionRunMSselSeqsWithSteps(0, 10, GetMissionTableRow());
            break;
    }
}

void InitMissionRunMSsel(void *parentHeap, void *mainOamList, void *subOamList) {
    s32 missionIndex;
    void *heap;
    s32 rem;
    u16 base;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMissionRunMSsel = HeapAlloc(heap, 0xc0);
    gMissionRunMSsel->mHeap = heap;
    gMissionRunMSsel->mState = 0;
    gMissionRunMSsel->mIndex = GetMissionTableColumn() - 1;
    gMissionRunMSsel->mExitOffsetX = 0;
    gMissionRunMSsel->mIndexChangeTimer = 0;
    gMissionRunMSsel->mBossRecorded = FALSE;
    gMissionRunMSsel->mMainOamList = mainOamList;
    gMissionRunMSsel->mSubOamList = subOamList;
    gMissionRunMSsel->mResult = 0;
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        gMissionRunMSsel->mIndexCellTimers[missionIndex] = 0;
    }
    SetMissionRunMSselAllRecorded();
    LocateAndQueueMissionRunMSsel();
    ResetOamLists(gMissionRunMSsel->mMainOamList, gMissionRunMSsel->mSubOamList);
    InitLayoutTable(gMissionRunMSsel->mHeap, gMissionRunMSsel->mMissionRunMSselMBncl,
                    gMissionRunMSsel->mMissionRunMSselMBnll, &gMissionRunMSsel->mMissionRunMSselMTable);
    InitLayoutTable(gMissionRunMSsel->mHeap, gMissionRunMSsel->mMissionRunMSselSBncl,
                    gMissionRunMSsel->mMissionRunMSselSBnll, &gMissionRunMSsel->mMissionRunMSselSTable);
    gMissionRunMSsel->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gMissionRunMSsel->mMissionMessages = FindSceneFile("mission.bmg");
    gMissionRunMSsel->mMissionTableMtbl = FindFileInLoadedArchives("missionTable.mtbl");
    gMissionRunMSsel->mMissionFileRows = (MissionFileRow *) ((u8 *) FindSceneFile("mission.mr") + 8);
    InitLabelCanvas(gMissionRunMSsel->mHeap, 0, gMissionRunMSsel->mMissionRunMSselMBnll, 0xd2, 0x46, 0,
                    gMissionRunMSsel->mMissionRunMSselMNcer, gMissionRunMSsel->mMissionRunMSselMBncl,
                    gMissionRunMSsel->mMissionRunMSselMTable, 0x8000);
    rem = GX_GetSizeOfSubOBJ();
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        rem -= InitLabelCanvas(gMissionRunMSsel->mHeap, gMissionRunMSselLabelSTableIndices[missionIndex][0],
                               gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSselLabelWidths[missionIndex][0],
                               gMissionRunMSselLabelHeights[missionIndex][0],
                               gMissionRunMSselIndexSTableIndices[missionIndex][5],
                               gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                               gMissionRunMSsel->mMissionRunMSselSTable, rem);
        base = gMissionRunMSselLabelSTableIndices[missionIndex][0];
        rem -= InitLabelCanvas(gMissionRunMSsel->mHeap, gMissionRunMSselLabelSTableIndices[missionIndex][1],
                               gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSselLabelWidths[missionIndex][1],
                               gMissionRunMSselLabelHeights[missionIndex][1],
                               base + gMissionRunMSsel->mMissionRunMSselSBncl->mCount,
                               gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                               gMissionRunMSsel->mMissionRunMSselSTable, rem);
    }
    CreateMissionRunBossIcon(gMissionRunMSsel->mHeap);
    InitMissionRunMSselCells();
    gMissionRunMSsel->mShownIndex = gMissionRunMSsel->mIndex;
    RefreshMissionRunMSselMCells();
    ResetMissionRunMSselOffsets();
    FrmHeapShrinkInParent(gMissionRunMSsel->mHeap);
}

void ReleaseMissionRunMSsel(void) {
    switch (gMissionRunMSsel->mResult) {
        case 1:
            StopMissionRunMSselSeqsAtOnce(4, GetMissionTableRow());
            break;
        case 2:
            StopMissionRunMSselSeqsAtOnce(0, GetMissionTableRow());
            break;
    }
    ClearMissionRunBossIconPointer();
    HeapDestroy(gMissionRunMSsel->mHeap);
    gMissionRunMSsel = NULL;
}

void AdvanceMissionRunMSselState0(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    if (AreBrightnessFadesClear() != 0) {
        RequestMissionRunMSselState1();
    }
}

void AdvanceMissionRunMSselState1(void) {
    s32 slotIndex;
    s32 cellSlot;
    u16 mainLayoutCellCount;
    s16 offsetX;
    u16 subLayoutCellCount;
    s16 bg1Offset;

    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0x100, 0, gMissionRunMSsel->mStateFrames, 10);
    bg1Offset = InterpolateS16(1, -192, 0, gMissionRunMSsel->mStateFrames, 10);
    gMissionRunMSsel->mBg0OffsetX = offsetX;
    gMissionRunMSsel->mBg1Offset = bg1Offset;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mOffsetX = offsetX;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mOffsetX = offsetX;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mOffsetX = offsetX;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mOffsetX = offsetX;
    for (slotIndex = 0; slotIndex < 7; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mOffsetX = offsetX;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mOffsetX = offsetX;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mOffsetX = offsetX;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mOffsetX = offsetX;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mOffsetX = offsetX;
        for (cellSlot = 0; cellSlot < 9; cellSlot++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[slotIndex][cellSlot]].mOffsetX =
                offsetX;
        }
        for (cellSlot = 0; cellSlot < 2; cellSlot++) {
            gMissionRunMSsel
                ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[slotIndex][cellSlot]]
                .mOffsetX = offsetX;
        }
    }
    if (gMissionRunMSsel->mStateFrames >= 10) {
        RequestMissionRunMSselState2();
    }
}

void AdvanceMissionRunMSselState2(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    if (IsSelectReturnState2NoState3Or4Request()) {
        RequestMissionRunMSselState3();
    }
}

void AdvanceMissionRunMSselState3(void) {
    u32 result = -1;
    InputSlotIndex slot = UNK_02175628_INDEX_8;
    BOOL flag_b;
    BOOL flag_a;
    u16 value;
    s16 current;
    s16 delta;
    s16 target;

    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    flag_b = FALSE;
    flag_a = FALSE;
    value = gInputSlots[slot].mPair.mHasPair;
    if (value == 0 && gInputSlots[slot].mPair.mNoPairCount < 5) {
        flag_a = TRUE;
    }
    if (flag_a == FALSE && gInputSlots[slot].mPair.mPrevHasPair == 0 && value != 0) {
        flag_b = TRUE;
    }
    if (flag_b) {
        result = RectTableFindContaining(gMissionRunMSsel->mMissionRunMSselSBnbl, gInputSlots[slot].mPair.mPairX,
                                         gInputSlots[slot].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slot].mPressedBits & PAD_KEY_B) == 0) {
        flag_b = FALSE;
        flag_a = FALSE;
        value = gInputSlots[slot].mPair.mHasPair;
        if (value == 0 && gInputSlots[slot].mPair.mNoPairCount < 5) {
            flag_a = TRUE;
        }
        if (flag_a == FALSE && gInputSlots[slot].mPair.mPrevHasPair == 0 && value != 0) {
            flag_b = TRUE;
        }
        if (!flag_b || IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slot].mPair.mPairX,
                                                                       gInputSlots[slot].mPair.mPairY) == FALSE) {
            goto skip;
        }
    }
    if (IsMissionRunMSselIndexChangeRunning() != FALSE) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    gMissionRunMSsel->mExitOffsetX = 0x100;
    gMissionRunMSsel->mResult = 2;
    RequestMissionRunMSselState8();
    RequestSelectReturnState3WithSound(0);
    return;
skip:
    if (result <= 8) {
        target = gMissionRunMSselRectIndices[result];
        if (target == 8 && gMissionRunMSsel->mAllRecorded == 0) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
            return;
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        RequestMissionRunMSselState4();
        return;
    }
    if ((u16) (gInputSlots[slot].mPressedBits & PAD_KEY_A) != 0) {
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        RequestMissionRunMSselState4();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselUpSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselUpSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselDownSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselDownSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_LEFT)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselLeftSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselLeftSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselRightSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselRightSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = 5;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

void AdvanceMissionRunMSselState4(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    if (gMissionRunMSsel->mStateFrames >= 5) {
        if (IsMissionRunMSselIndexChangeRunning() == FALSE) {
            RequestMissionRunMSselState5();
        }
    }
}

void AdvanceMissionRunMSselState5(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (IsSelectChoisesState1NoState0Request()) {
        RequestMissionRunMSselState6();
    }
}

void AdvanceMissionRunMSselState6(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (GetSelectChoisesDone()) {
        RequestMissionRunMSselState7();
    }
}

void AdvanceMissionRunMSselState7(void) {
    s32 missionIndex;
    s32 choisesIndex;

    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (IsSelectChoisesState0NoState1Request()) {
        choisesIndex = GetSelectChoisesIndex();
        switch (choisesIndex) {
            case 0:
                SetMissionFromMissionRunMSsel();
                gMissionRunMSsel->mResult = 1;
                gMissionRunMSsel->mExitOffsetX = -0x100;
                RequestMissionRunMSselState8();
                break;
            case -1:
            case 1:
                RequestMissionRunMSselState3();
                break;
        }
        for (missionIndex = 0; missionIndex < 9; missionIndex++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 1;
        }
    }
}

void AdvanceMissionRunMSselState8(void) {
    s32 slotIndex;
    s32 cellSlot;
    s16 first;
    s16 second;
    u16 mainLayoutCellCount;
    u16 subLayoutCellCount;

    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    first = InterpolateS16(1, 0, gMissionRunMSsel->mExitOffsetX, gMissionRunMSsel->mStateFrames, 10);
    second = InterpolateS16(1, 0, -0xc0, gMissionRunMSsel->mStateFrames, 10);
    gMissionRunMSsel->mBg0OffsetX = first;
    gMissionRunMSsel->mBg1Offset = second;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mOffsetX = first;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mOffsetX = first;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mOffsetX = first;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mOffsetX = first;
    for (slotIndex = 0; slotIndex < 7; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mOffsetX = first;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mOffsetX = first;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mOffsetX = first;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mOffsetX = first;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mOffsetX = first;
        for (cellSlot = 0; cellSlot < 9; cellSlot++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[slotIndex][cellSlot]].mOffsetX =
                first;
        }
        for (cellSlot = 0; cellSlot < 2; cellSlot++) {
            gMissionRunMSsel
                ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[slotIndex][cellSlot]]
                .mOffsetX = first;
        }
    }
    if (gMissionRunMSsel->mStateFrames == 5) {
        NNS_GfdRegisterNewVramTransferTask(9, 0, gMissionRunMSsel->mVramTransferBuffer, 0x800);
    }
}

s32 AdvanceMissionRunMSsel(void) {
    gMissionRunMSsel->mState = gMissionRunMSsel->mNextState;
    switch (gMissionRunMSsel->mState) {
        case 0:
            AdvanceMissionRunMSselState0();
            break;
        case 1:
            AdvanceMissionRunMSselState1();
            break;
        case 2:
            AdvanceMissionRunMSselState2();
            break;
        case 3:
            AdvanceMissionRunMSselState3();
            break;
        case 4:
            AdvanceMissionRunMSselState4();
            break;
        case 5:
            AdvanceMissionRunMSselState5();
            break;
        case 6:
            AdvanceMissionRunMSselState6();
            break;
        case 7:
            AdvanceMissionRunMSselState7();
            break;
        case 8:
            AdvanceMissionRunMSselState8();
            break;
    }
    UpdateMissionRunMSselIndexCells();
    AdvanceMissionRunMSselPaletteBlend();
    DrawLayoutTable(gMissionRunMSsel->mMissionRunMSselMBncl, gMissionRunMSsel->mMissionRunMSselMNcer,
                    gMissionRunMSsel->mMissionRunMSselMBnll, gMissionRunMSsel->mMainOamList,
                    gMissionRunMSsel->mMissionRunMSselMTable);
    DrawLayoutTable(gMissionRunMSsel->mMissionRunMSselSBncl, gMissionRunMSsel->mMissionRunMSselSNcer,
                    gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSsel->mSubOamList,
                    gMissionRunMSsel->mMissionRunMSselSTable);
    if (gMissionRunMSsel->mState == 8 && gMissionRunMSsel->mStateFrames >= 10) {
        return gMissionRunMSsel->mResult;
    }
    return 0;
}

void WriteMissionRunMSselBgOffsets(void) {
    reg_G2_BG0OFS = (-gMissionRunMSsel->mBg0OffsetX & 0x1ff) | ((-gMissionRunMSsel->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gMissionRunMSsel->mBg1Offset << 16) & 0x1ff0000;
}
