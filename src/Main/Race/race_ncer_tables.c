#include "Main/Race/race_ncer_tables.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"

#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Menu/message_screen.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/data_027e0000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "Main/Race/data_020b846c.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020b85dc.h"
#include "Main/Race/data_020b85f0.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "os_thread.h"
#include "Main/Graphics/message_index.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_0200eddc.h"
#include "g2d_NOB_load.h"
#include "g2d_CharCanvas.h"
#include "code_0214cfe4.h"
#include "Main/Menu/menu_shared_clear.h"

struct RaceNcerNclrNcgrTables *gRaceNcerNclrNcgrTables;

void InitRaceNcerNclrNcgrTables(void) {
    Unk02021dc8 *raceMCells;
    Unk02021dc8 *raceGoalMCells;
    Unk02021dc8 *raceTaMCells;
    Unk02021dc8 *raceBattleMCells;
    Unk02021dc8 *raceStartBattleMCells;
    Unk02021dc8 *raceMrMCells;
    Unk02021dc8 *raceGoalMrMCells;
    Ncgr *raceIconTxtChars;
    Nclr *ownCharacterPalette;
    Unk02021dc8 *raceSCells;
    Unk02021dc8 *raceGoalSCells;
    Unk02021dc8 *raceGoalTeamSCells;
    Unk02021dc8 *raceNewRecordTaSCells;
    u8 raceGoalMOCharCanvas[0x20];
    TextCanvas raceGoalMOTextCanvas;
    u8 raceTaMOCharCanvas[0x20];
    TextCanvas raceTaMOTextCanvas;
    u8 raceStartBattleMOCharCanvas[0x20];
    TextCanvas raceStartBattleMOTextCanvas;
    u8 raceGoalSOCharCanvas[0x20];
    TextCanvas raceGoalSOTextCanvas;
    u16 goalKartName[0x14];
    u8 raceGoalSOMessageCharCanvas[0x20];
    TextCanvas raceGoalSOMessageTextCanvas;
    u8 raceGoalTeamSOCharCanvas[0x20];
    TextCanvas raceGoalTeamSOTextCanvas;
    u16 goalTeamKartName[0x14];
    u8 raceNewRecordTaSOCharCanvas[0x20];
    TextCanvas raceNewRecordTaSOTextCanvas;
    u16 recordRowName[0xe];
    u16 index;
    u16 recordRowX;
    u16 recordRowY;
    u16 goalTeamX;
    u16 goalTeamY;
    s32 colorIndex;
    void *font;
    s32 courseMessageIndex;
    s32 charSpacing;
    s32 teamColorIndex;
    u16 nameX;
    u16 nameY;
    s32 color;
    s32 colorBelow;
    void *iconCharData;

    gRaceNcerNclrNcgrTables = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x88c);
    for (index = 0; index < 0x38; index++) {
        gRaceNcerNclrNcgrTables->mRaceMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0x44; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0xf; index++) {
        gRaceNcerNclrNcgrTables->mRaceTaMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0xd; index++) {
        gRaceNcerNclrNcgrTables->mRaceBattleMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0x16; index++) {
        gRaceNcerNclrNcgrTables->mRaceMrMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 8; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalMrMNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0xc9; index++) {
        gRaceNcerNclrNcgrTables->mRaceSNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0x2c; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalSNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0x28; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalTeamSNcerEntries[index] = NULL;
    }
    for (index = 0; index < 0x21; index++) {
        gRaceNcerNclrNcgrTables->mRaceNewRecordTaSNcerEntries[index] = NULL;
    }
    for (index = 0; index < 3; index++) {
        gRaceNcerNclrNcgrTables->mRaceStartBattleMNcerEntries[index] = NULL;
    }

    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNclr, FindSceneFileWrapper("race_m_o.NCLR"));
    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNclr, FindSceneFileWrapper("race_goal_m_o.NCLR"));
    switch (gRaceSetup->mMode) {
        case MODE_TIME_ATTACK:
            gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNclr = gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNclr;
            break;
        case MODE_BATTLE:
            LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[3].mNclr,
                         FindSceneFileWrapper("race_battle_m_o.NCLR"));
            if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
                LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNclr,
                             FindSceneFileWrapper("race_start_battle_m_o.NCLR"));
            }
            break;
        case MODE_MISSION_RUN:
            LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[4].mNclr, FindSceneFileWrapper("race_mr_m_o.NCLR"));
            LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[5].mNclr,
                         FindSceneFileWrapper("race_goal_mr_m_o.NCLR"));
            break;
        case MODE_WIFI:
            break;
    }

    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr, FindSceneFileWrapper("race_m_o.NCGR"));
    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr, FindSceneFileWrapper("race_goal_m_o.NCGR"));
    switch (gRaceSetup->mMode) {
        case MODE_TIME_ATTACK:
            LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNcgr, FindSceneFileWrapper("race_ta_m_o.NCGR"));
            break;
        case MODE_BATTLE:
            LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[3].mNcgr,
                          FindSceneFileWrapper("race_battle_m_o.NCGR"));
            if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
                LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNcgr,
                              FindSceneFileWrapper("race_start_battle_m_o.NCGR"));
            }
            break;
        case MODE_MISSION_RUN:
            LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[4].mNcgr, FindSceneFileWrapper("race_mr_m_o.NCGR"));
            LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[5].mNcgr,
                          FindSceneFileWrapper("race_goal_mr_m_o.NCGR"));
            break;
        case MODE_WIFI:
            break;
    }

    raceMCells = NULL;
    LoadNcerData(&raceMCells, FindSceneFileWrapper("race_m.NCER"));
    for (index = 0; index < 0x38; index++) {
        gRaceNcerNclrNcgrTables->mRaceMNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceMCells, index);
    }
    raceGoalMCells = NULL;
    LoadNcerData(&raceGoalMCells, FindSceneFileWrapper("race_goal_m.NCER"));
    for (index = 0; index < 0x44; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalMNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceGoalMCells, index);
    }

    switch (gRaceSetup->mMode) {
        case MODE_TIME_ATTACK:
            font = GetFontByIndex(2);
            NNS_G2dCharCanvasInitForBG(raceGoalMOCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr->mData,
                                       0x20, 0x10, 4);
            raceGoalMOTextCanvas.mCharSpacing = IsLanguageJa();
            raceGoalMOTextCanvas.mCharCanvas = raceGoalMOCharCanvas;
            raceGoalMOTextCanvas.mFont = font;
            raceGoalMOTextCanvas.mLineSpacing = 0;
            NNSi_G2dTextCanvasDrawText(&raceGoalMOTextCanvas, 0x80, 0x38, 0xe, 0x412,
                                       GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), 0x81));
            DC_FlushRange(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr->mData,
                          gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr->mDataSize);
            raceTaMCells = NULL;
            LoadNcerData(&raceTaMCells, FindSceneFileWrapper("race_ta_m.NCER"));
            for (index = 0; index < 0xf; index++) {
                gRaceNcerNclrNcgrTables->mRaceTaMNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceTaMCells, index);
            }
            font = GetFontByIndex(2);
            NNS_G2dCharCanvasInitForBG(raceTaMOCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNcgr->mData,
                                       0x20, 4, 4);
            raceTaMOTextCanvas.mCharSpacing = IsLanguageJa();
            raceTaMOTextCanvas.mCharCanvas = raceTaMOCharCanvas;
            raceTaMOTextCanvas.mFont = font;
            raceTaMOTextCanvas.mLineSpacing = 0;
            NNSi_G2dTextCanvasDrawText(&raceTaMOTextCanvas, 0x80, 0x18, 0xe, 0x412,
                                       GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), 0x6d));
            DC_FlushRange(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNcgr->mData,
                          gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNcgr->mDataSize);
            CopyCharsBlock(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[2].mNcgr->mData, 0, 0, 0x20, 4,
                           gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                raceBattleMCells = NULL;
                LoadNcerData(&raceBattleMCells, FindSceneFileWrapper("race_battle_m.NCER"));
                for (index = 0; index < 0xd; index++) {
                    gRaceNcerNclrNcgrTables->mRaceBattleMNcerEntries[index] =
                        NNS_G2dGetCellDataByIdx(raceBattleMCells, index);
                }
                MIi_CpuCopy16(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[3].mNclr->mData,
                              gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNclr->mData, 0x40);
                CopyCharsBlock(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[3].mNcgr->mData, 0, 0, 0x20, 4,
                               gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            } else {
                raceStartBattleMCells = NULL;
                LoadNcerData(&raceStartBattleMCells, FindSceneFileWrapper("race_start_battle_m.NCER"));
                for (index = 0; index < 3; index++) {
                    gRaceNcerNclrNcgrTables->mRaceStartBattleMNcerEntries[index] =
                        NNS_G2dGetCellDataByIdx(raceStartBattleMCells, index);
                }
                font = GetFontByIndex(2);
                courseMessageIndex = GetCourseMessageIndex(gRaceSetup->mCourseId);
                NNS_G2dCharCanvasInitForBG(raceStartBattleMOCharCanvas,
                                           gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNcgr->mData, 0x20, 4, 4);
                charSpacing = RaceStartIsLanguageJa();
                raceStartBattleMOTextCanvas.mFont = font;
                raceStartBattleMOTextCanvas.mCharCanvas = raceStartBattleMOCharCanvas;
                raceStartBattleMOTextCanvas.mLineSpacing = 0;
                raceStartBattleMOTextCanvas.mCharSpacing = charSpacing;
                NNSi_G2dTextCanvasDrawText(&raceStartBattleMOTextCanvas, 0, 9, 0xc, 0x40a,
                                           GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"),
                                                       gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON ? 0x54 : 0x55));
                NNSi_G2dTextCanvasDrawText(&raceStartBattleMOTextCanvas, 0, 8, 0xc, 0x40a,
                                           GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"),
                                                       gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON ? 0x54 : 0x55));
                raceStartBattleMOTextCanvas.mCharSpacing = RaceStartIsLanguageJa();
                NNSi_G2dTextCanvasDrawText(
                    &raceStartBattleMOTextCanvas, 0, 0x19, 0xe, 0x40a,
                    GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), courseMessageIndex));
                NNSi_G2dTextCanvasDrawText(
                    &raceStartBattleMOTextCanvas, 0, 0x18, 0xe, 0x40a,
                    GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), courseMessageIndex));
                DC_FlushRange(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNcgr->mData,
                              gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNcgr->mDataSize);
                MIi_CpuCopy16(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNclr->mData,
                              gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNclr->mData, 0x40);
                CopyCharsBlock(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[10].mNcgr->mData, 0, 0, 0x20, 4,
                               gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            }
            break;
        case MODE_MISSION_RUN:
            raceMrMCells = NULL;
            LoadNcerData(&raceMrMCells, FindSceneFileWrapper("race_mr_m.NCER"));
            for (index = 0; index < 0x16; index++) {
                gRaceNcerNclrNcgrTables->mRaceMrMNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceMrMCells, index);
            }
            MIi_CpuCopy16(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[4].mNclr->mData,
                          gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNclr->mData, 0x40);
            CopyCharsBlock(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[4].mNcgr->mData, 0, 0, 0x20, 4,
                           gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            raceGoalMrMCells = NULL;
            LoadNcerData(&raceGoalMrMCells, FindSceneFileWrapper("race_goal_mr_m.NCER"));
            for (index = 0; index < 8; index++) {
                gRaceNcerNclrNcgrTables->mRaceGoalMrMNcerEntries[index] =
                    NNS_G2dGetCellDataByIdx(raceGoalMrMCells, index);
            }
            MIi_CpuCopy16(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[5].mNclr->mData,
                          gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNclr->mData, 0x20);
            CopyCharsBlock(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[5].mNcgr->mData, 0, 0, 0x20, 8,
                           gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr->mData, 0, 0);
            break;
        case 5:
            raceIconTxtChars = NULL;
            LoadNcgrData2(&raceIconTxtChars, FindSceneFileWrapper("race_icon_txt.NCGR"));
            iconCharData = raceIconTxtChars->mData;
            CopyCharsBlock(iconCharData, 0, 0, 8, 2, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[0].mNcgr->mData, 0x18,
                           0xe);
            CopyCharsBlock(iconCharData, 0, 0, 8, 2, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[1].mNcgr->mData, 0x18,
                           0xe);
            break;
    }

    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[6].mNclr, FindSceneFileWrapper("race_s_o.NCLR"));
    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[7].mNclr, FindSceneFileWrapper("race_goal_s_o.NCLR"));
    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[8].mNclr, FindSceneFileWrapper("race_goal_team_s_o.NCLR"));
    if (gRaceSetup->mUseTeams != 0) {
        ownCharacterPalette = NULL;
        teamColorIndex =
            gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mTeamIndex == 0 ? 0x13 : 0x23;
        LoadNclrData(&ownCharacterPalette, FindSceneFileWrapper("race_own_character_s_o.NCLR"));
        DC_FlushRange(gRaceNcerNclrNcgrTables->mNclrNcgrPairs[6].mNclr->mData, 0x200);
        for (colorIndex = 0; colorIndex < 4; colorIndex++) {
            gRaceNcerNclrNcgrTables->mNclrNcgrPairs[6].mNclr->mData[colorIndex + 0xb3] =
                ownCharacterPalette->mData[teamColorIndex + colorIndex];
        }
    }
    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[6].mNcgr, FindSceneFileWrapper("race_s_o.NCGR"));
    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[7].mNcgr, FindSceneFileWrapper("race_goal_s_o.NCGR"));
    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[8].mNcgr, FindSceneFileWrapper("race_goal_team_s_o.NCGR"));

    font = GetFontByIndex(0);
    NNS_G2dCharCanvasInitForBG(raceGoalSOCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[7].mNcgr->mData, 0x20,
                               0x10, 4);
    raceGoalSOTextCanvas.mCharCanvas = raceGoalSOCharCanvas;
    raceGoalSOTextCanvas.mFont = font;
    raceGoalSOTextCanvas.mCharSpacing = 1;
    raceGoalSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
        nameX = (index % 2) * 0x68;
        nameY = (index / 2) * 0x10 + 0x48;
        CopyKartEntryName(index, goalKartName, 1);
        NNSi_G2dTextCanvasDrawText(&raceGoalSOTextCanvas, nameX, nameY + 1,
                                   index == GetFollowedKartOrEntryIndex() ? 0xd : 0xf, 0x40a, goalKartName);
        NNSi_G2dTextCanvasDrawText(&raceGoalSOTextCanvas, nameX, nameY,
                                   index == GetFollowedKartOrEntryIndex() ? 0xc : 0xe, 0x40a, goalKartName);
    }

    font = GetFontByIndex(2);
    NNS_G2dCharCanvasInitForBG(raceGoalSOMessageCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[7].mNcgr->mData,
                               0x20, 0x10, 4);
    raceGoalSOMessageTextCanvas.mCharCanvas = raceGoalSOMessageCharCanvas;
    raceGoalSOMessageTextCanvas.mFont = font;
    raceGoalSOMessageTextCanvas.mCharSpacing = 1;
    raceGoalSOMessageTextCanvas.mLineSpacing = 0;
    NNSi_G2dTextCanvasDrawText(&raceGoalSOMessageTextCanvas, 0x20, 0x38, 0xe, 0x40a,
                               GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), 0x79));

    font = GetFontByIndex(0);
    NNS_G2dCharCanvasInitForBG(raceGoalTeamSOCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[8].mNcgr->mData, 0x20,
                               0xa, 4);
    raceGoalTeamSOTextCanvas.mCharCanvas = raceGoalTeamSOCharCanvas;
    raceGoalTeamSOTextCanvas.mFont = font;
    raceGoalTeamSOTextCanvas.mCharSpacing = 1;
    raceGoalTeamSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
        goalTeamX = (index % 4) * 0x38;
        goalTeamY = (index / 4) * 0x10 + 0x38;
        CopyKartEntryName(index, goalTeamKartName, 0);
        if (index == GetFollowedKartOrEntryIndex()) {
            if (gRaceSetup->mUseTeams != 0) {
                if (gRaceSetup->mCurrentEntries[index].mPlayer.mTeamIndex == 0) {
                    color = 0xa;
                    colorBelow = 0xb;
                } else {
                    color = 8;
                    colorBelow = 9;
                }
            } else {
                color = 0xc;
                colorBelow = 0xd;
            }
        } else {
            color = 0xe;
            colorBelow = 0xf;
        }
        NNSi_G2dTextCanvasDrawText(&raceGoalTeamSOTextCanvas, goalTeamX, goalTeamY + 1, colorBelow, 0x40a,
                                   goalTeamKartName);
        NNSi_G2dTextCanvasDrawText(&raceGoalTeamSOTextCanvas, goalTeamX, goalTeamY, color, 0x40a, goalTeamKartName);
    }

    raceSCells = NULL;
    LoadNcerData(&raceSCells, FindSceneFileWrapper("race_s.NCER"));
    for (index = 0; index < 0xc9; index++) {
        gRaceNcerNclrNcgrTables->mRaceSNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceSCells, index);
    }
    raceGoalSCells = NULL;
    LoadNcerData(&raceGoalSCells, FindSceneFileWrapper("race_goal_s.NCER"));
    for (index = 0; index < 0x2c; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalSNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceGoalSCells, index);
    }
    raceGoalTeamSCells = NULL;
    LoadNcerData(&raceGoalTeamSCells, FindSceneFileWrapper("race_goal_team_s.NCER"));
    for (index = 0; index < 0x28; index++) {
        gRaceNcerNclrNcgrTables->mRaceGoalTeamSNcerEntries[index] = NNS_G2dGetCellDataByIdx(raceGoalTeamSCells, index);
    }

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    LoadNclrData(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[9].mNclr,
                 FindSceneFileWrapper("race_new_record_ta_s_o.NCLR"));
    LoadNcgrData2(&gRaceNcerNclrNcgrTables->mNclrNcgrPairs[9].mNcgr,
                  FindSceneFileWrapper("race_new_record_ta_s_o.NCGR"));
    font = GetFontByIndex(0);
    NNS_G2dCharCanvasInitForBG(raceNewRecordTaSOCharCanvas, gRaceNcerNclrNcgrTables->mNclrNcgrPairs[9].mNcgr->mData,
                               0x20, 0x10, 4);
    raceNewRecordTaSOTextCanvas.mCharCanvas = raceNewRecordTaSOCharCanvas;
    raceNewRecordTaSOTextCanvas.mFont = font;
    raceNewRecordTaSOTextCanvas.mCharSpacing = 1;
    raceNewRecordTaSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < 7; index++) {
        recordRowY = (index / 2) * 0x10 + 0x49;
        CopyPlayerOrTimeRecordName(index, recordRowName, 1);
        recordRowX = (index % 2) * 0x68;
        NNSi_G2dTextCanvasDrawText(&raceNewRecordTaSOTextCanvas, recordRowX, recordRowY + 1, 0xf, 0x40a, recordRowName);
        NNSi_G2dTextCanvasDrawText(&raceNewRecordTaSOTextCanvas, recordRowX, recordRowY, 0xe, 0x40a, recordRowName);
    }
    raceNewRecordTaSCells = NULL;
    LoadNcerData(&raceNewRecordTaSCells, FindSceneFileWrapper("race_new_record_ta_s.NCER"));
    for (index = 0; index < 0x21; index++) {
        gRaceNcerNclrNcgrTables->mRaceNewRecordTaSNcerEntries[index] =
            NNS_G2dGetCellDataByIdx(raceNewRecordTaSCells, index);
    }
}

struct RaceNcerNclrNcgrTables **ClearRaceNcerNclrNcgrTablesPointer(void) {
    gRaceNcerNclrNcgrTables = NULL;
    return &gRaceNcerNclrNcgrTables;
}

RaceNclrNcgr *GetRaceNclrNcgr(u32 pairIndex) {
    return &gRaceNcerNclrNcgrTables->mNclrNcgrPairs[pairIndex];
}

NNSG2dCellDataWithBR *GetRaceMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceMNcerEntries[cellIndex];
}

u32 LookupRaceMNcerIndex(u32 kind) {
    u32 cellIndex;
    KartItems *kartItems;
    enum { K0 } itemInfoIndex;

    cellIndex = 0xb;
    switch (kind) {
        case 0:
            cellIndex = 0x12;
            break;
        case 1:
            cellIndex = 0x10;
            break;
        case 2:
            cellIndex = 0x17;
            break;
        case 3:
            cellIndex = 0x14;
            break;
        case 4:
            cellIndex = 0xd;
            break;
        case 5:
            kartItems = &gKartItems[GetFollowedKartOrEntryIndex()];
            itemInfoIndex = kartItems->mHeldItem.mItemInfoIndex;
            switch (gItemInfos[itemInfoIndex].mObjectKind == 3 ? (u16) kartItems->mHeldItem.mObjectCount : 0) {
                case 1:
                    cellIndex = 0xd;
                    break;
                case 2:
                    cellIndex = 0xe;
                    break;
                case 0:
                case 3:
                    cellIndex = 0xf;
                    break;
            }
            break;
        case 6:
            cellIndex = 0x16;
            break;
        case 7:
            cellIndex = 0x1b;
            break;
        case 8:
            cellIndex = 0x19;
            break;
        case 9:
            cellIndex = 0x13;
            break;
        case 10:
            cellIndex = 0x18;
            break;
        case 11:
            cellIndex = 0x11;
            break;
        case 12:
            cellIndex = 0x1a;
            break;
        case 13:
            cellIndex = 0x1e;
            break;
        case 14:
            cellIndex = 0x1c;
            break;
        case 15:
            cellIndex = 0x1d;
            break;
        case 16:
            cellIndex = 0x15;
            break;
        case 17:
            cellIndex = 0x1f;
            break;
        case 18:
        case 19:
            break;
    }
    return cellIndex;
}

NNSG2dCellDataWithBR *GetRaceGoalMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceGoalMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceTaMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceTaMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceBattleMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceBattleMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceMrMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceMrMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceGoalMrMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceGoalMrMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceSNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceGoalSNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceGoalSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceGoalTeamSNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceGoalTeamSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceNewRecordTaSNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceNewRecordTaSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetRaceStartBattleMNcerEntry(u32 cellIndex) {
    return gRaceNcerNclrNcgrTables->mRaceStartBattleMNcerEntries[cellIndex];
}

s32 LookupRaceSNcerIndex(s32 kartIndex, s32 shownItem) {
    KartItems *kartItems;
    u32 heldObjectCount;
    enum { K0 } itemInfoIndex;

    switch (shownItem) {
        case 0:
            return 0x1b;
        case 1:
            return 0x14;
        case 2:
            return 0x22;
        case 3:
            return 0x17;
        case 4:
            return 0x11;
        case 5:
            kartItems = GetKartItems(kartIndex);
            itemInfoIndex = kartItems->mHeldItem.mItemInfoIndex;
            if (gItemInfos[itemInfoIndex].mObjectKind == 3) {
                heldObjectCount = (u16) kartItems->mHeldItem.mObjectCount;
            } else {
                heldObjectCount = 0;
            }
            switch (heldObjectCount) {
                case 1:
                    return 0x11;
                case 2:
                    return 0x12;
                case 0:
                case 3:
                    return 0x13;
            }
            break;
        case 6:
            return 0x1f;
        case 7:
            return 0x20;
        case 8:
            return 0x21;
        case 9:
            return 0x1c;
        case 10:
            return 0x23;
        case 11:
            return 0x15;
        case 12:
            return 0x19;
        case 13:
            return 0x18;
        case 14:
            return 0x1d;
        case 16:
            return 0x1e;
        case 15:
            return 0x1a;
        case 17:
            return 0x16;
    }
    return kartIndex;
}

void RenderKartEntryNames(void) {
    void *font;
    void *charBuffer;
    u16 kartIndex;
    s32 textX;
    s32 textY;
    s32 color;
    s32 colorBelow;
    BOOL flag;
    u8 charCanvas[0x20];
    TextCanvas textCanvas;
    u16 kartName[22];

    font = GetFontByIndex(0);
    charBuffer = GetMessageScreenCharBuffer();
    ClearMessageScreenChars();
    NNS_G2dCharCanvasInitForBG(charCanvas, charBuffer, 0x20, 4, 4);
    textCanvas.mCharCanvas = charCanvas;
    textCanvas.mCharSpacing = 1;
    textCanvas.mFont = font;
    textCanvas.mLineSpacing = 0;
    kartIndex = 0;
    flag = FALSE;
    for (; kartIndex < 8; kartIndex++) {
        textX = (kartIndex % 4) << 6;
        textY = (((u32) kartIndex >> 2) << 4) + 8;
        CopyKartEntryName(kartIndex, kartName, flag);
        if (kartIndex == GetFollowedKartOrEntryIndex()) {
            if (gRaceSetup->mUseTeams != 0) {
                if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0) {
                    color = 10;
                    colorBelow = 11;
                } else {
                    color = 8;
                    colorBelow = 9;
                }
            } else {
                color = 12;
                colorBelow = 13;
            }
        } else {
            color = 14;
            colorBelow = 15;
        }
        NNSi_G2dTextCanvasDrawText(&textCanvas, textX, textY + 1, colorBelow, 0x40a, kartName);
        NNSi_G2dTextCanvasDrawText(&textCanvas, textX, textY, color, 0x40a, kartName);
    }
}

void GetEntryCharacterAndPalette(s32 entryIndex, s32 *outCharacterIndex, s32 *outPaletteIndex) {
    s32 shuffledIndex;

    *outCharacterIndex = gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
    switch (*outCharacterIndex) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *outPaletteIndex = 7;
            break;
        case 1:
        case 3:
        case 9:
            *outPaletteIndex = 8;
            break;
        case 4:
        case 5:
            *outPaletteIndex = 9;
            break;
        case 6:
        case 7:
            *outPaletteIndex = 10;
            break;
        case 12:
            shuffledIndex = gMenuShared->mShuffledIndices[entryIndex];
            *outCharacterIndex = shuffledIndex % 4 + 12;
            if (shuffledIndex < 4) {
                *outPaletteIndex = 5;
            } else {
                *outPaletteIndex = 6;
            }
            break;
    }
}

void GetTimeRecordCharacterAndPalette(s32 recordIndex, s32 *outCharacterIndex, s32 *outPaletteIndex) {
    TimeRecord timeRecord;

    GetCourseTimeRecord(gRaceSetup->mCourseId, recordIndex, &timeRecord);
    if (timeRecord.mFilled != 0) {
        *outCharacterIndex = timeRecord.mCharacterIndex;
    } else {
        *outCharacterIndex = 0;
        *outPaletteIndex = 0;
        return;
    }
    switch (*outCharacterIndex) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *outPaletteIndex = 7;
            break;
        case 1:
        case 3:
        case 9:
            *outPaletteIndex = 8;
            break;
        case 4:
        case 5:
            *outPaletteIndex = 9;
            break;
        case 6:
        case 7:
            *outPaletteIndex = 10;
            break;
        case 12:
            break;
    }
}

void CopyRaceTransferMapMrSO(u16 *palette, void *chars) {
    Ncgr *transferMapMrChars = NULL;
    void *transferMapMrCharData;
    Nclr *firstNclr;
    Nclr *secondNclr;
    Nclr *thirdNclr;
    Nclr *fourthNclr;
    Nclr *fifthNclr;
    Nclr *sixthNclr;
    Nclr *seventhNclr;
    s32 colorIndex;

    LoadNcgrData2(&transferMapMrChars, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCGR"));
    transferMapMrCharData = transferMapMrChars->mData;
    switch (gRaceSetup->mMissionTableValue) {
        case 0x9:
            CopyCharsBlock(transferMapMrCharData, 0x0, 0, 4, 4, chars, 0, 12);
            firstNclr = NULL;
            LoadNclrData(&firstNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = firstNclr->mData[0x0 + colorIndex];
            }
            break;
        case 0x32:
            CopyCharsBlock(transferMapMrCharData, 0x4, 0, 8, 4, chars, 0, 12);
            secondNclr = NULL;
            LoadNclrData(&secondNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = secondNclr->mData[0x10 + colorIndex];
            }
            break;
        case 0x15:
            CopyCharsBlock(transferMapMrCharData, 0xc, 0, 4, 4, chars, 0, 12);
            thirdNclr = NULL;
            LoadNclrData(&thirdNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = thirdNclr->mData[0x20 + colorIndex];
            }
            break;
        case 0x33:
            CopyCharsBlock(transferMapMrCharData, 0x10, 0, 4, 4, chars, 0, 12);
            fourthNclr = NULL;
            LoadNclrData(&fourthNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = fourthNclr->mData[0x50 + colorIndex];
            }
            break;
        case 0x11:
            CopyCharsBlock(transferMapMrCharData, 0x14, 0, 4, 4, chars, 0, 12);
            fifthNclr = NULL;
            LoadNclrData(&fifthNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = fifthNclr->mData[0x60 + colorIndex];
            }
            break;
        case 0xa:
            CopyCharsBlock(transferMapMrCharData, 0x18, 0, 4, 4, chars, 0, 12);
            sixthNclr = NULL;
            LoadNclrData(&sixthNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = sixthNclr->mData[0x70 + colorIndex];
            }
            break;
        case 0x31:
            CopyCharsBlock(transferMapMrCharData, 0x0, 4, 8, 4, chars, 0, 12);
            seventhNclr = NULL;
            LoadNclrData(&seventhNclr, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = seventhNclr->mData[0x80 + colorIndex];
            }
            break;
    }
}

void CopyRaceTransferSOAndMapSO(u16 *palette, void *chars) {
    s32 characterIndex;
    s32 paletteIndex;
    Ncgr *transferChars = NULL;
    Nclr *firstNclr;
    Nclr *secondNclr;
    Nclr *thirdNclr;
    Nclr *fourthNclr;
    Nclr *fifthNclr;
    Nclr *sixthNclr;
    Nclr *seventhNclr;
    Nclr *eighthNclr;
    Nclr *ninthNclr;
    Nclr *tenthNclr;
    Nclr *eleventhNclr;
    Nclr *twelfthNclr;
    Nclr *thirteenthNclr;
    Nclr *fourteenthNclr;
    Nclr *fifteenthNclr;
    void *transferCharData;
    u8 kartIndex;
    u8 index;
    u8 nameIndex;
    s32 colorIndex;
    NNSG2dCellOAMAttrData *oamEntry;

    LoadNcgrData2(&transferChars, FindSceneFileWrapper("race_transfer_s_o.NCGR"));
    transferCharData = transferChars->mData;
    for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
        GetEntryCharacterAndPalette(kartIndex, &characterIndex, &paletteIndex);
        CopyCharsBlock(transferCharData, characterIndex << 1, 0, 2, 2, chars, kartIndex << 1, 0);
        oamEntry = gRaceNcerNclrNcgrTables->mRaceSNcerEntries[kartIndex]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
    }
    for (index = 0; index < (s32) gRaceSetup->mKartCount; index++) {
        GetEntryCharacterAndPalette(index, &characterIndex, &paletteIndex);
        CopyCharsBlock(transferCharData, characterIndex << 1, 2, 2, 2, chars, (index << 1) + 0x10, 0);
        oamEntry = gRaceNcerNclrNcgrTables->mRaceSNcerEntries[index + 8]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        oamEntry = gRaceNcerNclrNcgrTables->mRaceGoalSNcerEntries[index]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        oamEntry = gRaceNcerNclrNcgrTables->mRaceGoalTeamSNcerEntries[index]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            oamEntry = gRaceNcerNclrNcgrTables->mRaceNewRecordTaSNcerEntries[index + 7]->mPOamAttrArray;
            oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        }
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        for (index = 0; index < 6; index++) {
            GetTimeRecordCharacterAndPalette(index, &characterIndex, &paletteIndex);
            CopyCharsBlock(transferCharData, characterIndex << 1, 2, 2, 2, chars, ((index + 2) << 1) + 0x10, 0);
            oamEntry = gRaceNcerNclrNcgrTables->mRaceNewRecordTaSNcerEntries[index + 8]->mPOamAttrArray;
            oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        }
    }
    for (nameIndex = 0; nameIndex < (s32) gRaceSetup->mKartCount; nameIndex++) {
        s32 nameTilePositions[8][2] = {{16, 8}, {16, 10}, {11, 12}, {18, 12}, {25, 12}, {11, 14}, {18, 14}, {25, 14}};

        CopyCharsBlock(GetMessageScreenCharBuffer(), (nameIndex % 4) << 3, ((u32) nameIndex >> 2) << 1, 7, 2, chars,
                       nameTilePositions[nameIndex][0], nameTilePositions[nameIndex][1]);
    }
    ClearMessageScreenChars();
    LoadNcgrData2(&transferChars, FindSceneFileWrapper("race_transfer_map_s_o.NCGR"));
    transferCharData = transferChars->mData;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        CopyCharsBlock(transferCharData, 0x14, 6, 0xc, 4, chars, 0, 8);
        CopyCharsBlock(transferCharData, 0x14, 0xa, 0xb, 4, chars, 0, 0xc);
        firstNclr = NULL;
        LoadNclrData(&firstNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
        for (colorIndex = 0; colorIndex < 16; colorIndex++) {
            palette[0x40 + colorIndex] = firstNclr->mData[0xd0 + colorIndex];
        }
    } else {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_OLD_NOKO_SFC:
            case COURSE_ID_BEACH:
            case COURSE_ID_MINI_STAGE3:
                CopyCharsBlock(transferCharData, 0x0, 0, 4, 2, chars, 0, 8);
                secondNclr = NULL;
                LoadNclrData(&secondNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = secondNclr->mData[colorIndex];
                }
                break;
            case COURSE_ID_OLD_MARIO_SFC:
            case COURSE_ID_MANSION:
            case COURSE_ID_OLD_DONUT_SFC:
                CopyCharsBlock(transferCharData, 0x4, 0, 5, 2, chars, 0, 8);
                thirdNclr = NULL;
                LoadNclrData(&thirdNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = thirdNclr->mData[0x10 + colorIndex];
                }
                break;
            case COURSE_ID_DESERT:
                CopyCharsBlock(transferCharData, 0x9, 0, 6, 2, chars, 0, 8);
                fourthNclr = NULL;
                LoadNclrData(&fourthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fourthNclr->mData[0x20 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_CHOCO_64:
                CopyCharsBlock(transferCharData, 0xf, 0, 3, 2, chars, 0, 8);
                fifthNclr = NULL;
                LoadNclrData(&fifthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fifthNclr->mData[0x30 + colorIndex];
                }
                break;
            case COURSE_ID_PINBALL:
                CopyCharsBlock(transferCharData, 0, 2, 0xc, 4, chars, 0, 8);
                CopyCharsBlock(transferCharData, 0, 6, 0xb, 4, chars, 0, 0xc);
                if (gRaceSetup->mMirrorMode != 0) {
                    CopyCharsBlockFlippedVertically(transferCharData, 0, 2, 8, 8, chars, 0, 8);
                }
                sixthNclr = NULL;
                LoadNclrData(&sixthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = sixthNclr->mData[0x40 + colorIndex];
                }
                break;
            case COURSE_ID_RIDGE:
            case COURSE_ID_OLD_KINOKO_GC:
                CopyCharsBlock(transferCharData, 0x14, 0, 8, 4, chars, 0, 8);
                seventhNclr = NULL;
                LoadNclrData(&seventhNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = seventhNclr->mData[0x50 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_FRAPPE_64:
            case COURSE_ID_SNOW:
                CopyCharsBlock(transferCharData, 0x1d, 0, 3, 2, chars, 0, 8);
                eighthNclr = NULL;
                LoadNclrData(&eighthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = eighthNclr->mData[0x60 + colorIndex];
                }
                break;
            case COURSE_ID_CLOCK:
                CopyCharsBlock(transferCharData, 0xc, 4, 8, 4, chars, 0, 8);
                ninthNclr = NULL;
                LoadNclrData(&ninthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = ninthNclr->mData[0x70 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_YOSHI_GC:
            case COURSE_ID_OLD_BABY_GC:
            case COURSE_ID_MARIO:
            case COURSE_ID_OLD_CHOCO_SFC:
                CopyCharsBlock(transferCharData, 0xc, 2, 8, 2, chars, 0, 8);
                tenthNclr = NULL;
                LoadNclrData(&tenthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = tenthNclr->mData[0x80 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_MOMO_64:
            case COURSE_ID_OLD_LUIGI_GC:
            case COURSE_ID_AIRSHIP:
            case COURSE_ID_GARDEN:
                CopyCharsBlock(transferCharData, 0x13, 4, 12, 4, chars, 0, 8);
                eleventhNclr = NULL;
                LoadNclrData(&eleventhNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = eleventhNclr->mData[0x90 + colorIndex];
                }
                break;
            case COURSE_ID_STADIUM:
                CopyCharsBlock(transferCharData, 0x8, 10, 8, 4, chars, 0, 8);
                twelfthNclr = NULL;
                LoadNclrData(&twelfthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = twelfthNclr->mData[0x80 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_KOOPA_AGB:
            case COURSE_ID_KOOPA:
                CopyCharsBlock(transferCharData, 0xc, 8, 8, 2, chars, 0, 8);
                thirteenthNclr = NULL;
                LoadNclrData(&thirteenthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = thirteenthNclr->mData[0xa0 + colorIndex];
                }
                break;
            case COURSE_ID_RAINBOW:
                CopyCharsBlock(transferCharData, 0x12, 10, 2, 2, chars, 0, 8);
                fourteenthNclr = NULL;
                LoadNclrData(&fourteenthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fourteenthNclr->mData[0xb0 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_HYUDORO_64:
                CopyCharsBlock(transferCharData, 0x0, 10, 8, 6, chars, 0, 8);
                fifteenthNclr = NULL;
                LoadNclrData(&fifteenthNclr, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fifteenthNclr->mData[0xe0 + colorIndex];
                }
                break;
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        CopyRaceTransferMapMrSO(palette, chars);
    }
}
