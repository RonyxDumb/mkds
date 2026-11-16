#include "01/Menu/mission_run_mission_select.h"

#include "arena_cache_init.h"
#include "Main/Graphics/layout_rect_table.h"
#include "types.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/mission_run_boss_icon.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/select_return.h"
#include "sound_player_control.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Race/mission_table_value.h"
#include "sound_archive_load_result.h"
#include "vram_bank_display_setup.h"
#include "registers.h"
#include "01/Menu/select_engine.h"
#include "01/MapObjects/periodic_effect.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
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
    NNSG2dCellDataBank *missionRunMSselMCells = NULL;
    Nclr *missionRunMSselMOPalette = NULL;
    Ncgr *missionRunMSselSChars = NULL;
    NNSG2dCellDataBank *missionRunMSselSCells = NULL;
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
    gMissionRunMSsel->mVramTransferBuffer = HeapAlloc(gMissionRunMSsel->mHeap, SECOND_SCREEN_MAP_BYTES);
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
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gMissionRunMSsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(8, 0x1000, gMissionRunMSsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(8, 0x1800, gMissionRunMSsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(9, 0, missionRunMSselMScreenMap->mData, missionRunMSselMScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(9, 0x800, gMissionRunMSsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, missionRunMSselMChars->mData, missionRunMSselMChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, missionRunMSselMOPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, missionRunMSselSChars->mData, missionRunMSselSChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gMissionRunMSsel->mMissionRunMSselSOPalette->mData,
                                       gMissionRunMSsel->mMissionRunMSselSOPalette->mDataSize);
}

void SetMissionRunMSselAllRecorded(void) {
    s32 recordValue;
    s32 missionIndex;

    gMissionRunMSsel->mAllRecorded = 1;
    for (missionIndex = 0; missionIndex < 8; missionIndex++) {
        gMissionRunMSsel->mAllRecorded &=
            GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (missionIndex + 1), &recordValue);
    }
}

void FormatMissionRunMissionNumber(s16 missionIndex, u16 *text) {
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
    s32 recordValue;
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
        if (missionIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
            if (gMissionRunMSsel->mAllRecorded != 0) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible =
                    1;
                QueueMissionRunBossIcon(GetMissionTableRow() - 1, 1, gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl, 0x2d, 8, 1);
            } else {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][4]].mVisible =
                    1;
                QueueMissionRunBossIcon(GetMissionTableRow() - 1, 0, gMissionRunMSsel->mMissionRunMSselSNcer,
                                        gMissionRunMSsel->mMissionRunMSselSBncl, 0x2d, 8, 1);
            }
        } else {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][1]].mVisible = 1;
        }
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 1;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][2]].mVisible = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][3]].mVisible = 0;
        if (GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (missionIndex + 1), &recordValue)) {
            if (recordValue <= 4) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][5]].mVisible =
                    1;
                gMissionRunMSsel
                    ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[missionIndex][0]]
                    .mVisible = 1;
                PrintLabelLayoutTextNoFixedAdvance(
                    1, gMissionRunMSselLabelSTableIndices[missionIndex][0], gMissionRunMSsel->mMissionRunMSselSBnll,
                    gMissionRunMSselGradeStrings[recordValue], gMissionRunMSsel->mMissionRunMSselSBncl,
                    gMissionRunMSsel->mMissionRunMSselSTable);
            } else if (recordValue <= 7) {
                gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][recordValue + 1]]
                    .mVisible = 1;
            }
            if (missionIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
                gMissionRunMSsel->mBossRecorded = TRUE;
            }
        }
        LoadMissionRunMSselSoundData(0, GetMissionTableRow());
        if (missionIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
            SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][2], 2,
                                gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl);
            SetCellPaletteIndex(gMissionRunMSselIndexSTableIndices[missionIndex][1], 5,
                                gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl);
            if (gMissionRunMSsel->mAllRecorded != 0) {
                if (GetPreviousMenuScreenNumber() == SCREEN_MISSION_RUN_LVSEL) {
                    gMissionRunMSsel->mIndex = MISSION_RUN_MSSEL_BOSS_INDEX;
                }
                if (gMissionRunMSsel->mBossRecorded == FALSE) {
                    gMissionRunMSsel->mIndex = MISSION_RUN_MSSEL_BOSS_INDEX;
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
        FormatMissionRunMissionNumber(missionIndex, text);
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
            if (gMissionRunMSsel->mPaletteBlendFrame >= MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES) {
                gMissionRunMSsel->mPaletteBlendFrame = 0;
            }
            if (gMissionRunMSsel->mIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
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
                    red = fromRed + blendFrame * (toRed - fromRed) * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
                    green = fromGreen + blendFrame * (toGreen - fromGreen) * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
                    blue = fromBlue + blendFrame * (toBlue - fromBlue) * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
                } else {
                    secondHalfFrame = blendFrame - 50;
                    channelDifference = fromRed - toRed;
                    red = toRed + channelDifference * secondHalfFrame * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
                    channelDifference = fromGreen - toGreen;
                    green = toGreen + channelDifference * secondHalfFrame * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
                    channelDifference = fromBlue - toBlue;
                    blue = toBlue + channelDifference * secondHalfFrame * 2 / MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES;
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
        } else if (missionIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
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
    s32 recordValue;
    s32 hasRecord;
    gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[GetMissionTableRow() - 1]].mVisible = 0;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mVisible = 0;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mVisible = 0;
    }
    if (gMissionRunMSsel->mIndex == MISSION_RUN_MSSEL_BOSS_INDEX) {
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
    hasRecord = GetMissionRecordValue((u8) GetMissionTableRow(), (u8) (gMissionRunMSsel->mIndex + 1), &recordValue);
    gMissionRunMSsel->mMissionRunMSselMTable[18].mVisible = 0;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mVisible = 0;
    }
    if (hasRecord != 0 && recordValue <= 7) {
        if (recordValue <= 4) {
            gMissionRunMSsel->mMissionRunMSselMTable[18].mVisible = 1;
        }
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[recordValue - 2]].mVisible = 1;
    }
    missionRunMSsel = gMissionRunMSsel;
    PrintLabelLayoutTextNoFixedAdvance(
        0, 0, gMissionRunMSsel->mMissionRunMSselMBnll,
        GetBmgEntry(missionRunMSsel->mMissionMessages,
                    missionRunMSsel
                        ->mMissionFileRows[GetMissionTableValue(gMissionRunMSsel->mMissionTableMtbl,
                                                                GetMissionTableRow(), missionRunMSsel->mIndex + 1) -
                                           1]
                        .mMessageIndex),
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
        if (gMissionRunMSsel->mIndexChangeTimer == MENU_INDEX_CHANGE_FRAMES) {
            gMissionRunMSsel->mShownIndex = gMissionRunMSsel->mIndex;
            RefreshMissionRunMSselMCells();
        } else {
            mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
            offsetY = LookupIndexChangeOffset(MENU_INDEX_CHANGE_FRAMES - gMissionRunMSsel->mIndexChangeTimer, 1);
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
        gMissionRunMSsel->mIndexChangeTimer = MENU_INDEX_CHANGE_FRAMES;
    }
}

void ResetMissionRunMSselOffsets(void) {
    s32 slotIndex;
    s32 cellSlot;
    u16 mainLayoutCellCount;
    u16 subLayoutCellCount;

    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_WAIT_FADE;
    gMissionRunMSsel->mStateFrames = 0;
    gMissionRunMSsel->mBg0OffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunMSsel->mBg0OffsetY = 0;
    gMissionRunMSsel->mBg1Offset = -192;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    for (slotIndex = 0; slotIndex < 7; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselRowMTableIndices[slotIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselValueMTableIndices[slotIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[mainLayoutCellCount].mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    for (slotIndex = 0; slotIndex < 9; slotIndex++) {
        gMissionRunMSsel->mMissionRunMSselMTable[gMissionRunMSselIndexMTableIndices[slotIndex]].mOffsetX =
            LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        for (cellSlot = 0; cellSlot < 9; cellSlot++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[slotIndex][cellSlot]].mOffsetX =
                LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        }
        for (cellSlot = 0; cellSlot < 2; cellSlot++) {
            gMissionRunMSsel
                ->mMissionRunMSselSTable[subLayoutCellCount + gMissionRunMSselLabelSTableIndices[slotIndex][cellSlot]]
                .mOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselSlideIn.
void RequestMissionRunMSselSlideIn(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_SLIDE_IN;
    gMissionRunMSsel->mStateFrames = 0;
}

void RequestMissionRunMSselWaitSelectReturn(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_WAIT_SELECT_RETURN;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectReturnSlideIn();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselInput.
void RequestMissionRunMSselInput(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_INPUT;
    gMissionRunMSsel->mStateFrames = 0;
}

s32 RequestMissionRunMSselPressMission(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_PRESS_MISSION;
    gMissionRunMSsel->mStateFrames = 0;
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestMissionRunMSselChoisesOpen(void) {
    s32 missionIndex;
    void *firstText;

    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_CHOISES_OPEN;
    gMissionRunMSsel->mStateFrames = 0;
    firstText = GetBmgEntry(gMissionRunMSsel->mCommonMessages, 4);
    StartSelectChoises(firstText, GetBmgEntry(gMissionRunMSsel->mCommonMessages, 2), 0);
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 0;
    }
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselChoisesInput.
void RequestMissionRunMSselChoisesInput(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_CHOISES_INPUT;
    gMissionRunMSsel->mStateFrames = 0;
}

void RequestMissionRunMSselChoisesClose(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_CHOISES_CLOSE;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectChoisesHidden();
}

void RequestMissionRunMSselSlideOut(void) {
    gMissionRunMSsel->mNextState = MISSION_RUN_MSSEL_STATE_SLIDE_OUT;
    gMissionRunMSsel->mStateFrames = 0;
    RequestSelectReturnSlideOut();
    switch (gMissionRunMSsel->mResult) {
        case MISSION_RUN_MSSEL_RESULT_MISSION_CHOSEN:
            StopMissionRunMSselSeqsWithSteps(4, 10, GetMissionTableRow());
            break;
        case MISSION_RUN_MSSEL_RESULT_BACK:
            StopMissionRunMSselSeqsWithSteps(0, 10, GetMissionTableRow());
            break;
    }
}

void InitMissionRunMSsel(void *parentHeap, void *mainOamList, void *subOamList) {
    s32 missionIndex;
    void *heap;
    s32 remainingSize;
    u16 firstLabelIndex;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0xd204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMissionRunMSsel = HeapAlloc(heap, sizeof(MissionRunMSsel));
    gMissionRunMSsel->mHeap = heap;
    gMissionRunMSsel->mState = MISSION_RUN_MSSEL_STATE_WAIT_FADE;
    gMissionRunMSsel->mIndex = GetMissionTableColumn() - 1;
    gMissionRunMSsel->mExitOffsetX = 0;
    gMissionRunMSsel->mIndexChangeTimer = 0;
    gMissionRunMSsel->mBossRecorded = FALSE;
    gMissionRunMSsel->mMainOamList = mainOamList;
    gMissionRunMSsel->mSubOamList = subOamList;
    gMissionRunMSsel->mResult = MISSION_RUN_MSSEL_RESULT_NONE;
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
    remainingSize = GX_GetSizeOfSubOBJ();
    for (missionIndex = 0; missionIndex < 9; missionIndex++) {
        remainingSize -= InitLabelCanvas(gMissionRunMSsel->mHeap, gMissionRunMSselLabelSTableIndices[missionIndex][0],
                               gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSselLabelWidths[missionIndex][0],
                               gMissionRunMSselLabelHeights[missionIndex][0],
                               gMissionRunMSselIndexSTableIndices[missionIndex][5],
                               gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                               gMissionRunMSsel->mMissionRunMSselSTable, remainingSize);
        firstLabelIndex = gMissionRunMSselLabelSTableIndices[missionIndex][0];
        remainingSize -= InitLabelCanvas(gMissionRunMSsel->mHeap, gMissionRunMSselLabelSTableIndices[missionIndex][1],
                               gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSselLabelWidths[missionIndex][1],
                               gMissionRunMSselLabelHeights[missionIndex][1],
                               firstLabelIndex + gMissionRunMSsel->mMissionRunMSselSBncl->mCount,
                               gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                               gMissionRunMSsel->mMissionRunMSselSTable, remainingSize);
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
        case MISSION_RUN_MSSEL_RESULT_MISSION_CHOSEN:
            StopMissionRunMSselSeqsAtOnce(4, GetMissionTableRow());
            break;
        case MISSION_RUN_MSSEL_RESULT_BACK:
            StopMissionRunMSselSeqsAtOnce(0, GetMissionTableRow());
            break;
    }
    ClearMissionRunBossIconPointer();
    HeapDestroy(gMissionRunMSsel->mHeap);
    gMissionRunMSsel = NULL;
}

void AdvanceMissionRunMSselWaitFade(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    if (AreBrightnessFadesClear() != 0) {
        RequestMissionRunMSselSlideIn();
    }
}

void AdvanceMissionRunMSselSlideIn(void) {
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
    offsetX = InterpolateS16(1, LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH, 0,
                             gMissionRunMSsel->mStateFrames, MISSION_RUN_MSSEL_SLIDE_FRAMES);
    bg1Offset = InterpolateS16(1, -192, 0, gMissionRunMSsel->mStateFrames, MISSION_RUN_MSSEL_SLIDE_FRAMES);
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
    if (gMissionRunMSsel->mStateFrames >= MISSION_RUN_MSSEL_SLIDE_FRAMES) {
        RequestMissionRunMSselWaitSelectReturn();
    }
}

void AdvanceMissionRunMSselWaitSelectReturn(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    if (IsSelectReturnShownNoRequest()) {
        RequestMissionRunMSselInput();
    }
}

void AdvanceMissionRunMSselInput(void) {
    u32 touchedRectIndex = -1;
    InputSlotIndex slot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    BOOL touchBegan;
    BOOL recentlyLost;
    u16 hasPair;
    s16 current;
    s16 delta;
    s16 target;

    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    touchBegan = FALSE;
    recentlyLost = FALSE;
    hasPair = gInputSlots[slot].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slot].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slot].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan) {
        touchedRectIndex = RectTableFindContaining(gMissionRunMSsel->mMissionRunMSselSBnbl, gInputSlots[slot].mPair.mPairX,
                                         gInputSlots[slot].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slot].mPressedBits & PAD_KEY_B) == 0) {
        touchBegan = FALSE;
        recentlyLost = FALSE;
        hasPair = gInputSlots[slot].mPair.mHasPair;
        if (hasPair == 0 && gInputSlots[slot].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLost = TRUE;
        }
        if (recentlyLost == FALSE && gInputSlots[slot].mPair.mPrevHasPair == 0 && hasPair != 0) {
            touchBegan = TRUE;
        }
        if (!touchBegan || IsSelectReturnShownNoRequestAndInRect(gInputSlots[slot].mPair.mPairX,
                                                             gInputSlots[slot].mPair.mPairY) == FALSE) {
            goto skip;
        }
    }
    if (IsMissionRunMSselIndexChangeRunning() != FALSE) {
        return;
    }
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
    gMissionRunMSsel->mExitOffsetX = LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
    gMissionRunMSsel->mResult = MISSION_RUN_MSSEL_RESULT_BACK;
    RequestMissionRunMSselSlideOut();
    RequestSelectReturnPressWithSound(0);
    return;
skip:
    if (touchedRectIndex <= 8) {
        target = gMissionRunMSselRectIndices[touchedRectIndex];
        if (target == MISSION_RUN_MSSEL_BOSS_INDEX && gMissionRunMSsel->mAllRecorded == 0) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
            return;
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        RequestMissionRunMSselPressMission();
        return;
    }
    if ((u16) (gInputSlots[slot].mPressedBits & PAD_KEY_A) != 0) {
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        RequestMissionRunMSselPressMission();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_UP)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselUpSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == MISSION_RUN_MSSEL_BOSS_INDEX && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselUpSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_DOWN)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselDownSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == MISSION_RUN_MSSEL_BOSS_INDEX && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselDownSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_LEFT)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselLeftSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == MISSION_RUN_MSSEL_BOSS_INDEX && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselLeftSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_RIGHT)) {
        current = gMissionRunMSsel->mIndex;
        delta = gMissionRunMSselRightSteps[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == MISSION_RUN_MSSEL_BOSS_INDEX && gMissionRunMSsel->mAllRecorded == 0) {
            target = target + gMissionRunMSselRightSteps[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mIndexCellTimers[gMissionRunMSsel->mIndex] = MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

void AdvanceMissionRunMSselPressMission(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    if (gMissionRunMSsel->mStateFrames >= MISSION_RUN_MSSEL_HOLD_FRAMES) {
        if (IsMissionRunMSselIndexChangeRunning() == FALSE) {
            RequestMissionRunMSselChoisesOpen();
        }
    }
}

void AdvanceMissionRunMSselChoisesOpen(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (IsSelectChoisesChooseNoRequest()) {
        RequestMissionRunMSselChoisesInput();
    }
}

void AdvanceMissionRunMSselChoisesInput(void) {
    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (GetSelectChoisesDone()) {
        RequestMissionRunMSselChoisesClose();
    }
}

void AdvanceMissionRunMSselChoisesClose(void) {
    s32 missionIndex;
    s32 choisesIndex;

    UpdateMissionRunMSselSounds(gMissionRunMSsel->mPaletteBlendFrame);
    AdvanceMissionRunMSselIndexChange();
    if (IsSelectChoisesHiddenNoRequest()) {
        choisesIndex = GetSelectChoisesIndex();
        switch (choisesIndex) {
            case 0:
                SetMissionFromMissionRunMSsel();
                gMissionRunMSsel->mResult = MISSION_RUN_MSSEL_RESULT_MISSION_CHOSEN;
                gMissionRunMSsel->mExitOffsetX = -LAYOUT_ENTRY_OFFSET_SCREEN_WIDTH;
                RequestMissionRunMSselSlideOut();
                break;
            case -1:
            case 1:
                RequestMissionRunMSselInput();
                break;
        }
        for (missionIndex = 0; missionIndex < 9; missionIndex++) {
            gMissionRunMSsel->mMissionRunMSselSTable[gMissionRunMSselIndexSTableIndices[missionIndex][0]].mVisible = 1;
        }
    }
}

void AdvanceMissionRunMSselSlideOut(void) {
    s32 slotIndex;
    s32 cellSlot;
    s16 offsetX;
    s16 bg1Offset;
    u16 mainLayoutCellCount;
    u16 subLayoutCellCount;

    mainLayoutCellCount = gMissionRunMSsel->mMissionRunMSselMBncl->mCount;
    subLayoutCellCount = gMissionRunMSsel->mMissionRunMSselSBncl->mCount;
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    offsetX = InterpolateS16(1, 0, gMissionRunMSsel->mExitOffsetX,
                             gMissionRunMSsel->mStateFrames, MISSION_RUN_MSSEL_SLIDE_FRAMES);
    bg1Offset = InterpolateS16(1, 0, -0xc0, gMissionRunMSsel->mStateFrames, MISSION_RUN_MSSEL_SLIDE_FRAMES);
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
    if (gMissionRunMSsel->mStateFrames == MISSION_RUN_MSSEL_VRAM_TRANSFER_FRAME) {
        NNS_GfdRegisterNewVramTransferTask(9, 0, gMissionRunMSsel->mVramTransferBuffer, SECOND_SCREEN_MAP_BYTES);
    }
}

s32 AdvanceMissionRunMSsel(void) {
    gMissionRunMSsel->mState = gMissionRunMSsel->mNextState;
    switch (gMissionRunMSsel->mState) {
        case MISSION_RUN_MSSEL_STATE_WAIT_FADE:
            AdvanceMissionRunMSselWaitFade();
            break;
        case MISSION_RUN_MSSEL_STATE_SLIDE_IN:
            AdvanceMissionRunMSselSlideIn();
            break;
        case MISSION_RUN_MSSEL_STATE_WAIT_SELECT_RETURN:
            AdvanceMissionRunMSselWaitSelectReturn();
            break;
        case MISSION_RUN_MSSEL_STATE_INPUT:
            AdvanceMissionRunMSselInput();
            break;
        case MISSION_RUN_MSSEL_STATE_PRESS_MISSION:
            AdvanceMissionRunMSselPressMission();
            break;
        case MISSION_RUN_MSSEL_STATE_CHOISES_OPEN:
            AdvanceMissionRunMSselChoisesOpen();
            break;
        case MISSION_RUN_MSSEL_STATE_CHOISES_INPUT:
            AdvanceMissionRunMSselChoisesInput();
            break;
        case MISSION_RUN_MSSEL_STATE_CHOISES_CLOSE:
            AdvanceMissionRunMSselChoisesClose();
            break;
        case MISSION_RUN_MSSEL_STATE_SLIDE_OUT:
            AdvanceMissionRunMSselSlideOut();
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
    if (gMissionRunMSsel->mState == MISSION_RUN_MSSEL_STATE_SLIDE_OUT &&
        gMissionRunMSsel->mStateFrames >= MISSION_RUN_MSSEL_SLIDE_FRAMES) {
        return gMissionRunMSsel->mResult;
    }
    return MISSION_RUN_MSSEL_RESULT_NONE;
}

void WriteMissionRunMSselBgOffsets(void) {
    reg_G2_BG0OFS = (-gMissionRunMSsel->mBg0OffsetX & 0x1ff) | ((-gMissionRunMSsel->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gMissionRunMSsel->mBg1Offset << 16) & 0x1ff0000;
}
