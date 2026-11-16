#include "Main/Race/race_ncer_tables.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"

#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Menu/message_screen.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Race/race_m_ncer_index.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_m_ncer_entry.h"
#include "Main/Race/race_nclr_ncgr.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "thread_scheduler.h"
#include "Main/Graphics/message_index.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "arena_cache_init.h"
#include "cell_data_unpack.h"
#include "char_canvas_text_draw.h"
#include "cpu_copy_clear_16.h"
#include "Main/Menu/menu_shared_clear.h"

struct RaceNcerNclrNcgrTables *g_GlobalB3C4;

void CreateGlobalB3C4(void) {
    NNSG2dCellDataBank *raceMCells;
    NNSG2dCellDataBank *raceGoalMCells;
    NNSG2dCellDataBank *raceTaMCells;
    NNSG2dCellDataBank *raceBattleMCells;
    NNSG2dCellDataBank *raceStartBattleMCells;
    NNSG2dCellDataBank *raceMrMCells;
    NNSG2dCellDataBank *raceGoalMrMCells;
    Ncgr *raceIconTxtChars;
    Nclr *ownCharacterPalette;
    NNSG2dCellDataBank *raceSCells;
    NNSG2dCellDataBank *raceGoalSCells;
    NNSG2dCellDataBank *raceGoalTeamSCells;
    NNSG2dCellDataBank *raceNewRecordTaSCells;
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

    g_GlobalB3C4 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalB3C4));
    for (index = 0; index < RACE_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_GOAL_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_TA_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceTaMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_BATTLE_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceBattleMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_MR_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceMrMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_GOAL_MR_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalMrMNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceSNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_GOAL_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalSNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_GOAL_TEAM_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalTeamSNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_NEW_RECORD_TA_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceNewRecordTaSNcerEntries[index] = NULL;
    }
    for (index = 0; index < RACE_START_BATTLE_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceStartBattleMNcerEntries[index] = NULL;
    }

    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_o.NCLR"));
    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_m_o.NCLR"));
    switch (g_GlobalCO->mMode) {
        case MODE_TIME_ATTACK:
            g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNclr =
                g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNclr;
            break;
        case MODE_BATTLE:
            Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_BATTLE_M].mNclr,
                         j_FindFileBuffer_K2D_LOC_R2D_R2L("race_battle_m_o.NCLR"));
            if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
                Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNclr,
                             j_FindFileBuffer_K2D_LOC_R2D_R2L("race_start_battle_m_o.NCLR"));
            }
            break;
        case MODE_MISSION_RUN:
            Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_MR_M].mNclr,
                         j_FindFileBuffer_K2D_LOC_R2D_R2L("race_mr_m_o.NCLR"));
            Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_MR_M].mNclr,
                         j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_mr_m_o.NCLR"));
            break;
        case MODE_WIFI:
            break;
    }

    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_o.NCGR"));
    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_m_o.NCGR"));
    switch (g_GlobalCO->mMode) {
        case MODE_TIME_ATTACK:
            Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNcgr,
                          j_FindFileBuffer_K2D_LOC_R2D_R2L("race_ta_m_o.NCGR"));
            break;
        case MODE_BATTLE:
            Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_BATTLE_M].mNcgr,
                          j_FindFileBuffer_K2D_LOC_R2D_R2L("race_battle_m_o.NCGR"));
            if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
                Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNcgr,
                              j_FindFileBuffer_K2D_LOC_R2D_R2L("race_start_battle_m_o.NCGR"));
            }
            break;
        case MODE_MISSION_RUN:
            Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_MR_M].mNcgr,
                          j_FindFileBuffer_K2D_LOC_R2D_R2L("race_mr_m_o.NCGR"));
            Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_MR_M].mNcgr,
                          j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_mr_m_o.NCGR"));
            break;
        case MODE_WIFI:
            break;
    }

    raceMCells = NULL;
    LoadCellBankFrom(&raceMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m.NCER"));
    for (index = 0; index < RACE_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceMNcerEntries[index] = CellBank_GetMetatileEntry(raceMCells, index);
    }
    raceGoalMCells = NULL;
    LoadCellBankFrom(&raceGoalMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_m.NCER"));
    for (index = 0; index < RACE_GOAL_M_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalMNcerEntries[index] = CellBank_GetMetatileEntry(raceGoalMCells, index);
    }

    switch (g_GlobalCO->mMode) {
        case MODE_TIME_ATTACK:
            font = GetLoadedFont_from_thumb(2);
            G2d_Sprite_CreateFromTiles(raceGoalMOCharCanvas,
                                       g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr->mData,
                                       0x20, 0x10, 4);
            raceGoalMOTextCanvas.mCharSpacing = ComputeSomeInterCharacterWidth();
            raceGoalMOTextCanvas.mCharCanvas = raceGoalMOCharCanvas;
            raceGoalMOTextCanvas.mFont = font;
            raceGoalMOTextCanvas.mLineSpacing = 0;
            G2d_Text_PrintString(&raceGoalMOTextCanvas, 0x80, 0x38, 0xe, 0x412,
                                       Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), 0x81));
            Arm_FlushRange(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr->mData,
                          g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr->mDataSize);
            raceTaMCells = NULL;
            LoadCellBankFrom(&raceTaMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_ta_m.NCER"));
            for (index = 0; index < RACE_TA_M_NCER_COUNT; index++) {
                g_GlobalB3C4->mRaceTaMNcerEntries[index] = CellBank_GetMetatileEntry(raceTaMCells, index);
            }
            font = GetLoadedFont_from_thumb(2);
            G2d_Sprite_CreateFromTiles(raceTaMOCharCanvas,
                                       g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNcgr->mData, 0x20,
                                       4, 4);
            raceTaMOTextCanvas.mCharSpacing = ComputeSomeInterCharacterWidth();
            raceTaMOTextCanvas.mCharCanvas = raceTaMOCharCanvas;
            raceTaMOTextCanvas.mFont = font;
            raceTaMOTextCanvas.mLineSpacing = 0;
            G2d_Text_PrintString(&raceTaMOTextCanvas, 0x80, 0x18, 0xe, 0x412,
                                       Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), 0x6d));
            Arm_FlushRange(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNcgr->mData,
                          g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNcgr->mDataSize);
            CopyCharsBlock(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_TA_M].mNcgr->mData, 0, 0, 0x20, 4,
                           g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr->mData, 0, 0);
            break;
        case MODE_BATTLE:
            if (g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                raceBattleMCells = NULL;
                LoadCellBankFrom(&raceBattleMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_battle_m.NCER"));
                for (index = 0; index < RACE_BATTLE_M_NCER_COUNT; index++) {
                    g_GlobalB3C4->mRaceBattleMNcerEntries[index] =
                        CellBank_GetMetatileEntry(raceBattleMCells, index);
                }
                CopyMemory16(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_BATTLE_M].mNclr->mData,
                              g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNclr->mData, 0x40);
                CopyCharsBlock(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_BATTLE_M].mNcgr->mData, 0, 0,
                               0x20, 4, g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr->mData, 0,
                               0);
            } else {
                raceStartBattleMCells = NULL;
                LoadCellBankFrom(&raceStartBattleMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_start_battle_m.NCER"));
                for (index = 0; index < RACE_START_BATTLE_M_NCER_COUNT; index++) {
                    g_GlobalB3C4->mRaceStartBattleMNcerEntries[index] =
                        CellBank_GetMetatileEntry(raceStartBattleMCells, index);
                }
                font = GetLoadedFont_from_thumb(2);
                courseMessageIndex = GetBmgIndexFromCircuitIndex_from_thumb(g_GlobalCO->mCourseId);
                G2d_Sprite_CreateFromTiles(
                    raceStartBattleMOCharCanvas,
                    g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNcgr->mData, 0x20, 4, 4);
                charSpacing = GetSomeInterCharacterWidth();
                raceStartBattleMOTextCanvas.mFont = font;
                raceStartBattleMOTextCanvas.mCharCanvas = raceStartBattleMOCharCanvas;
                raceStartBattleMOTextCanvas.mLineSpacing = 0;
                raceStartBattleMOTextCanvas.mCharSpacing = charSpacing;
                G2d_Text_PrintString(&raceStartBattleMOTextCanvas, 0, 9, 0xc, 0x40a,
                                           Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"),
                                                       g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON ? 0x54 : 0x55));
                G2d_Text_PrintString(&raceStartBattleMOTextCanvas, 0, 8, 0xc, 0x40a,
                                           Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"),
                                                       g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON ? 0x54 : 0x55));
                raceStartBattleMOTextCanvas.mCharSpacing = GetSomeInterCharacterWidth();
                G2d_Text_PrintString(
                    &raceStartBattleMOTextCanvas, 0, 0x19, 0xe, 0x40a,
                    Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), courseMessageIndex));
                G2d_Text_PrintString(
                    &raceStartBattleMOTextCanvas, 0, 0x18, 0xe, 0x40a,
                    Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), courseMessageIndex));
                Arm_FlushRange(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNcgr->mData,
                              g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNcgr->mDataSize);
                CopyMemory16(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNclr->mData,
                              g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNclr->mData, 0x40);
                CopyCharsBlock(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_START_BATTLE_M].mNcgr->mData, 0,
                               0, 0x20, 4, g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr->mData,
                               0, 0);
            }
            break;
        case MODE_MISSION_RUN:
            raceMrMCells = NULL;
            LoadCellBankFrom(&raceMrMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_mr_m.NCER"));
            for (index = 0; index < RACE_MR_M_NCER_COUNT; index++) {
                g_GlobalB3C4->mRaceMrMNcerEntries[index] = CellBank_GetMetatileEntry(raceMrMCells, index);
            }
            CopyMemory16(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_MR_M].mNclr->mData,
                          g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNclr->mData, 0x40);
            CopyCharsBlock(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_MR_M].mNcgr->mData, 0, 0, 0x20, 4,
                           g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr->mData, 0, 0);
            raceGoalMrMCells = NULL;
            LoadCellBankFrom(&raceGoalMrMCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_mr_m.NCER"));
            for (index = 0; index < RACE_GOAL_MR_M_NCER_COUNT; index++) {
                g_GlobalB3C4->mRaceGoalMrMNcerEntries[index] =
                    CellBank_GetMetatileEntry(raceGoalMrMCells, index);
            }
            CopyMemory16(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_MR_M].mNclr->mData,
                          g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNclr->mData, 0x20);
            CopyCharsBlock(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_MR_M].mNcgr->mData, 0, 0, 0x20,
                           8, g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr->mData, 0, 0);
            break;
        case MODE_WIFI:
            raceIconTxtChars = NULL;
            Gfx_ReadCharGraphics(&raceIconTxtChars, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_icon_txt.NCGR"));
            iconCharData = raceIconTxtChars->mData;
            CopyCharsBlock(iconCharData, 0, 0, 8, 2,
                           g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_M].mNcgr->mData, 0x18, 0xe);
            CopyCharsBlock(iconCharData, 0, 0, 8, 2,
                           g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_M].mNcgr->mData, 0x18, 0xe);
            break;
    }

    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_S].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_s_o.NCLR"));
    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_S].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_s_o.NCLR"));
    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_TEAM_S].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_team_s_o.NCLR"));
    if (g_GlobalCO->mUseTeams != 0) {
        ownCharacterPalette = NULL;
        teamColorIndex =
            g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mPlayer.mTeamIndex == 0 ? 0x13 : 0x23;
        Gfx_ReadPalette(&ownCharacterPalette, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_own_character_s_o.NCLR"));
        Arm_FlushRange(g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_S].mNclr->mData, 0x200);
        for (colorIndex = 0; colorIndex < 4; colorIndex++) {
            g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_S].mNclr->mData[colorIndex + 0xb3] =
                ownCharacterPalette->mData[teamColorIndex + colorIndex];
        }
    }
    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_RACE_S].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_s_o.NCGR"));
    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_S].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_s_o.NCGR"));
    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_TEAM_S].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_team_s_o.NCGR"));

    font = GetLoadedFont_from_thumb(0);
    G2d_Sprite_CreateFromTiles(raceGoalSOCharCanvas,
                               g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_S].mNcgr->mData, 0x20, 0x10,
                               4);
    raceGoalSOTextCanvas.mCharCanvas = raceGoalSOCharCanvas;
    raceGoalSOTextCanvas.mFont = font;
    raceGoalSOTextCanvas.mCharSpacing = 1;
    raceGoalSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < (u32) g_GlobalCO->mKartCount; index++) {
        nameX = (index % 2) * 0x68;
        nameY = (index / 2) * 0x10 + 0x48;
        FormatRacerNameString_from_thumb(index, goalKartName, 1);
        G2d_Text_PrintString(&raceGoalSOTextCanvas, nameX, nameY + 1,
                                   index == GetCurrentPlayerRacerId() ? 0xd : 0xf, 0x40a, goalKartName);
        G2d_Text_PrintString(&raceGoalSOTextCanvas, nameX, nameY,
                                   index == GetCurrentPlayerRacerId() ? 0xc : 0xe, 0x40a, goalKartName);
    }

    font = GetLoadedFont_from_thumb(2);
    G2d_Sprite_CreateFromTiles(raceGoalSOMessageCharCanvas,
                               g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_S].mNcgr->mData, 0x20, 0x10,
                               4);
    raceGoalSOMessageTextCanvas.mCharCanvas = raceGoalSOMessageCharCanvas;
    raceGoalSOMessageTextCanvas.mFont = font;
    raceGoalSOMessageTextCanvas.mCharSpacing = 1;
    raceGoalSOMessageTextCanvas.mLineSpacing = 0;
    G2d_Text_PrintString(&raceGoalSOMessageTextCanvas, 0x20, 0x38, 0xe, 0x40a,
                               Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2("common.bmg"), 0x79));

    font = GetLoadedFont_from_thumb(0);
    G2d_Sprite_CreateFromTiles(raceGoalTeamSOCharCanvas,
                               g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_GOAL_TEAM_S].mNcgr->mData, 0x20,
                               0xa, 4);
    raceGoalTeamSOTextCanvas.mCharCanvas = raceGoalTeamSOCharCanvas;
    raceGoalTeamSOTextCanvas.mFont = font;
    raceGoalTeamSOTextCanvas.mCharSpacing = 1;
    raceGoalTeamSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < (u32) g_GlobalCO->mKartCount; index++) {
        goalTeamX = (index % 4) * 0x38;
        goalTeamY = (index / 4) * 0x10 + 0x38;
        FormatRacerNameString_from_thumb(index, goalTeamKartName, 0);
        if (index == GetCurrentPlayerRacerId()) {
            if (g_GlobalCO->mUseTeams != 0) {
                if (g_GlobalCO->mCurrentEntries[index].mPlayer.mTeamIndex == 0) {
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
        G2d_Text_PrintString(&raceGoalTeamSOTextCanvas, goalTeamX, goalTeamY + 1, colorBelow, 0x40a,
                                   goalTeamKartName);
        G2d_Text_PrintString(&raceGoalTeamSOTextCanvas, goalTeamX, goalTeamY, color, 0x40a, goalTeamKartName);
    }

    raceSCells = NULL;
    LoadCellBankFrom(&raceSCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_s.NCER"));
    for (index = 0; index < RACE_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceSNcerEntries[index] = CellBank_GetMetatileEntry(raceSCells, index);
    }
    raceGoalSCells = NULL;
    LoadCellBankFrom(&raceGoalSCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_s.NCER"));
    for (index = 0; index < RACE_GOAL_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalSNcerEntries[index] = CellBank_GetMetatileEntry(raceGoalSCells, index);
    }
    raceGoalTeamSCells = NULL;
    LoadCellBankFrom(&raceGoalTeamSCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_goal_team_s.NCER"));
    for (index = 0; index < RACE_GOAL_TEAM_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceGoalTeamSNcerEntries[index] = CellBank_GetMetatileEntry(raceGoalTeamSCells, index);
    }

    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    Gfx_ReadPalette(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_NEW_RECORD_TA_S].mNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s_o.NCLR"));
    Gfx_ReadCharGraphics(&g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_NEW_RECORD_TA_S].mNcgr,
                  j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s_o.NCGR"));
    font = GetLoadedFont_from_thumb(0);
    G2d_Sprite_CreateFromTiles(raceNewRecordTaSOCharCanvas,
                               g_GlobalB3C4->mNclrNcgrPairs[RACE_NCER_PAIR_NEW_RECORD_TA_S].mNcgr->mData,
                               0x20, 0x10, 4);
    raceNewRecordTaSOTextCanvas.mCharCanvas = raceNewRecordTaSOCharCanvas;
    raceNewRecordTaSOTextCanvas.mFont = font;
    raceNewRecordTaSOTextCanvas.mCharSpacing = 1;
    raceNewRecordTaSOTextCanvas.mLineSpacing = 0;
    for (index = 0; index < 7; index++) {
        recordRowY = (index / 2) * 0x10 + 0x49;
        FormatTimeTrialRecordRacerNameString(index, recordRowName, 1);
        recordRowX = (index % 2) * 0x68;
        G2d_Text_PrintString(&raceNewRecordTaSOTextCanvas, recordRowX, recordRowY + 1, 0xf, 0x40a, recordRowName);
        G2d_Text_PrintString(&raceNewRecordTaSOTextCanvas, recordRowX, recordRowY, 0xe, 0x40a, recordRowName);
    }
    raceNewRecordTaSCells = NULL;
    LoadCellBankFrom(&raceNewRecordTaSCells, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s.NCER"));
    for (index = 0; index < RACE_NEW_RECORD_TA_S_NCER_COUNT; index++) {
        g_GlobalB3C4->mRaceNewRecordTaSNcerEntries[index] =
            CellBank_GetMetatileEntry(raceNewRecordTaSCells, index);
    }
}

struct RaceNcerNclrNcgrTables **ResetGlobalB3C4(void) {
    g_GlobalB3C4 = NULL;
    return &g_GlobalB3C4;
}

RaceNclrNcgr *GetRacePaletteBlock(u32 pairIndex) {
    return &g_GlobalB3C4->mNclrNcgrPairs[pairIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceMNcerEntries[cellIndex];
}

u32 LookupRaceMNcerIndex(u32 kind) {
    u32 cellIndex;
    KartItems *kartItems;
    enum { ITEM_INFO_INDEX_FIRST } itemInfoIndex;

    cellIndex = RACE_M_CELL_ITEM_EMPTY;
    switch (kind) {
        case ITEM_INFO_KOURA_G:
            cellIndex = RACE_M_CELL_KOURA_G;
            break;
        case ITEM_INFO_KOURA_R:
            cellIndex = RACE_M_CELL_KOURA_R;
            break;
        case ITEM_INFO_BANANA:
            cellIndex = RACE_M_CELL_BANANA;
            break;
        case ITEM_INFO_F_BOX:
            cellIndex = RACE_M_CELL_F_BOX;
            break;
        case ITEM_INFO_KINOKO:
            cellIndex = RACE_M_CELL_KINOKO_ONE;
            break;
        case ITEM_INFO_KINOKO_THREE:
            kartItems = &gKartItems[GetCurrentPlayerRacerId()];
            itemInfoIndex = kartItems->mHeldItem.mItemInfoIndex;
            switch (gItemInfos[itemInfoIndex].mObjectKind == ITEM_OBJECT_KIND_KINOKO
                        ? (u16) kartItems->mHeldItem.mObjectCount
                        : 0) {
                case 1:
                    cellIndex = RACE_M_CELL_KINOKO_ONE;
                    break;
                case 2:
                    cellIndex = RACE_M_CELL_KINOKO_TWO;
                    break;
                case 0:
                case 3:
                    cellIndex = RACE_M_CELL_KINOKO_THREE;
                    break;
            }
            break;
        case ITEM_INFO_BOMB:
            cellIndex = RACE_M_CELL_BOMB;
            break;
        case ITEM_INFO_KOURA_W:
            cellIndex = RACE_M_CELL_KOURA_W;
            break;
        case ITEM_INFO_THUNDER:
            cellIndex = RACE_M_CELL_THUNDER;
            break;
        case ITEM_INFO_KOURA_G_THREE:
            cellIndex = RACE_M_CELL_KOURA_G_THREE;
            break;
        case ITEM_INFO_BANANA_THREE:
            cellIndex = RACE_M_CELL_BANANA_THREE;
            break;
        case ITEM_INFO_KOURA_R_THREE:
            cellIndex = RACE_M_CELL_KOURA_R_THREE;
            break;
        case ITEM_INFO_STAR:
            cellIndex = RACE_M_CELL_STAR;
            break;
        case ITEM_INFO_KINOKO_P:
            cellIndex = RACE_M_CELL_KINOKO_P;
            break;
        case ITEM_INFO_KILLER:
            cellIndex = RACE_M_CELL_KILLER;
            break;
        case ITEM_INFO_GESSO:
            cellIndex = RACE_M_CELL_GESSO;
            break;
        case ITEM_INFO_TERESA:
            cellIndex = RACE_M_CELL_TERESA;
            break;
        case ITEM_INFO_BOUNCING_ITEM_BOX:
            cellIndex = RACE_M_CELL_BOUNCING_ITEM_BOX;
            break;
        case ITEM_INFO_COUNT:
        case ITEM_INFO_NONE:
            break;
    }
    return cellIndex;
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceGoalM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceGoalMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceTaM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceTaMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceBattleM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceBattleMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceMrM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceMrMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceGoalMrM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceGoalMrMNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceS(u32 cellIndex) {
    return g_GlobalB3C4->mRaceSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceGoalS(u32 cellIndex) {
    return g_GlobalB3C4->mRaceGoalSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceGoalTeamS(u32 cellIndex) {
    return g_GlobalB3C4->mRaceGoalTeamSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceNewRecordTaS(u32 cellIndex) {
    return g_GlobalB3C4->mRaceNewRecordTaSNcerEntries[cellIndex];
}

NNSG2dCellDataWithBR *GetB3C4_Cell_RaceStartBattleM(u32 cellIndex) {
    return g_GlobalB3C4->mRaceStartBattleMNcerEntries[cellIndex];
}

s32 LookupRaceSNcerIndex(s32 kartIndex, s32 shownItem) {
    KartItems *kartItems;
    u32 heldObjectCount;
    enum { ITEM_INFO_INDEX_FIRST } itemInfoIndex;

    switch (shownItem) {
        case ITEM_INFO_KOURA_G:
            return RACE_S_CELL_KOURA_G;
        case ITEM_INFO_KOURA_R:
            return RACE_S_CELL_KOURA_R;
        case ITEM_INFO_BANANA:
            return RACE_S_CELL_BANANA;
        case ITEM_INFO_F_BOX:
            return RACE_S_CELL_F_BOX;
        case ITEM_INFO_KINOKO:
            return RACE_S_CELL_KINOKO_ONE;
        case ITEM_INFO_KINOKO_THREE:
            kartItems = GetKartItems(kartIndex);
            itemInfoIndex = kartItems->mHeldItem.mItemInfoIndex;
            if (gItemInfos[itemInfoIndex].mObjectKind == ITEM_OBJECT_KIND_KINOKO) {
                heldObjectCount = (u16) kartItems->mHeldItem.mObjectCount;
            } else {
                heldObjectCount = 0;
            }
            switch (heldObjectCount) {
                case 1:
                    return RACE_S_CELL_KINOKO_ONE;
                case 2:
                    return RACE_S_CELL_KINOKO_TWO;
                case 0:
                case 3:
                    return RACE_S_CELL_KINOKO_THREE;
            }
            break;
        case ITEM_INFO_BOMB:
            return RACE_S_CELL_BOMB;
        case ITEM_INFO_KOURA_W:
            return RACE_S_CELL_KOURA_W;
        case ITEM_INFO_THUNDER:
            return RACE_S_CELL_THUNDER;
        case ITEM_INFO_KOURA_G_THREE:
            return RACE_S_CELL_KOURA_G_THREE;
        case ITEM_INFO_BANANA_THREE:
            return RACE_S_CELL_BANANA_THREE;
        case ITEM_INFO_KOURA_R_THREE:
            return RACE_S_CELL_KOURA_R_THREE;
        case ITEM_INFO_STAR:
            return RACE_S_CELL_STAR;
        case ITEM_INFO_KINOKO_P:
            return RACE_S_CELL_KINOKO_P;
        case ITEM_INFO_KILLER:
            return RACE_S_CELL_KILLER;
        case ITEM_INFO_TERESA:
            return RACE_S_CELL_TERESA;
        case ITEM_INFO_GESSO:
            return RACE_S_CELL_GESSO;
        case ITEM_INFO_BOUNCING_ITEM_BOX:
            return RACE_S_CELL_BOUNCING_ITEM_BOX;
    }
    return kartIndex;
}

void DrawRacerNames(void) {
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

    font = GetLoadedFont_from_thumb(0);
    charBuffer = GetSomeBgCanvasTileData_from_thumb();
    Clear1A44SomeTileData_from_thumb();
    G2d_Sprite_CreateFromTiles(charCanvas, charBuffer, 0x20, 4, 4);
    textCanvas.mCharCanvas = charCanvas;
    textCanvas.mCharSpacing = 1;
    textCanvas.mFont = font;
    textCanvas.mLineSpacing = 0;
    kartIndex = 0;
    flag = FALSE;
    for (; kartIndex < 8; kartIndex++) {
        textX = (kartIndex % 4) << 6;
        textY = (((u32) kartIndex >> 2) << 4) + 8;
        FormatRacerNameString_from_thumb(kartIndex, kartName, flag);
        if (kartIndex == GetCurrentPlayerRacerId()) {
            if (g_GlobalCO->mUseTeams != 0) {
                if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0) {
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
        G2d_Text_PrintString(&textCanvas, textX, textY + 1, colorBelow, 0x40a, kartName);
        G2d_Text_PrintString(&textCanvas, textX, textY, color, 0x40a, kartName);
    }
}

void GetRacerCharacterIdAndUnk(s32 entryIndex, s32 *outCharacterIndex, s32 *outPaletteIndex) {
    s32 shuffledIndex;

    *outCharacterIndex = g_GlobalCO->mCurrentEntries[entryIndex].mCharacterIndex;
    switch (*outCharacterIndex) {
        case CHARACTER_MARIO:
        case CHARACTER_KINOPIO:
        case CHARACTER_KARON:
        case CHARACTER_WALUIGI:
        case CHARACTER_ROBO:
            *outPaletteIndex = 7;
            break;
        case CHARACTER_DONKEY:
        case CHARACTER_KOOPA:
        case CHARACTER_DAISY:
            *outPaletteIndex = 8;
            break;
        case CHARACTER_PEACH:
        case CHARACTER_WARIO:
            *outPaletteIndex = 9;
            break;
        case CHARACTER_YOSHI:
        case CHARACTER_LUIGI:
            *outPaletteIndex = 10;
            break;
        case CHARACTER_HEYHO:
            shuffledIndex = g_GlobalB488->mShuffledIndices[entryIndex];
            *outCharacterIndex = shuffledIndex % 4 + 12;
            if (shuffledIndex < 4) {
                *outPaletteIndex = 5;
            } else {
                *outPaletteIndex = 6;
            }
            break;
    }
}

void GetTimeTrialRecordCharacterIdAndUnk(s32 recordIndex, s32 *outCharacterIndex, s32 *outPaletteIndex) {
    TimeRecord timeRecord;

    TimeTrialRecord_CopyFrom_from_thumb(g_GlobalCO->mCourseId, recordIndex, &timeRecord);
    if (timeRecord.mFilled != 0) {
        *outCharacterIndex = timeRecord.mCharacterIndex;
    } else {
        *outCharacterIndex = 0;
        *outPaletteIndex = 0;
        return;
    }
    switch (*outCharacterIndex) {
        case CHARACTER_MARIO:
        case CHARACTER_KINOPIO:
        case CHARACTER_KARON:
        case CHARACTER_WALUIGI:
        case CHARACTER_ROBO:
            *outPaletteIndex = 7;
            break;
        case CHARACTER_DONKEY:
        case CHARACTER_KOOPA:
        case CHARACTER_DAISY:
            *outPaletteIndex = 8;
            break;
        case CHARACTER_PEACH:
        case CHARACTER_WARIO:
            *outPaletteIndex = 9;
            break;
        case CHARACTER_YOSHI:
        case CHARACTER_LUIGI:
            *outPaletteIndex = 10;
            break;
        case CHARACTER_HEYHO:
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

    Gfx_ReadCharGraphics(&transferMapMrChars, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCGR"));
    transferMapMrCharData = transferMapMrChars->mData;
    switch (g_GlobalCO->mMissionTableValue) {
        case MISSION_NUMBER_DONKETU:
            CopyCharsBlock(transferMapMrCharData, 0x0, 0, 4, 4, chars, 0, 12);
            firstNclr = NULL;
            Gfx_ReadPalette(&firstNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = firstNclr->mData[0x0 + colorIndex];
            }
            break;
        case MISSION_NUMBER_IWANTE:
            CopyCharsBlock(transferMapMrCharData, 0x4, 0, 8, 4, chars, 0, 12);
            secondNclr = NULL;
            Gfx_ReadPalette(&secondNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = secondNclr->mData[0x10 + colorIndex];
            }
            break;
        case MISSION_NUMBER_KURIKING:
            CopyCharsBlock(transferMapMrCharData, 0xc, 0, 4, 4, chars, 0, 12);
            thirdNclr = NULL;
            Gfx_ReadPalette(&thirdNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = thirdNclr->mData[0x20 + colorIndex];
            }
            break;
        case MISSION_NUMBER_KING_TERESA:
            CopyCharsBlock(transferMapMrCharData, 0x10, 0, 4, 4, chars, 0, 12);
            fourthNclr = NULL;
            Gfx_ReadPalette(&fourthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = fourthNclr->mData[0x50 + colorIndex];
            }
            break;
        case MISSION_NUMBER_BOMB_KING:
            CopyCharsBlock(transferMapMrCharData, 0x14, 0, 4, 4, chars, 0, 12);
            fifthNclr = NULL;
            Gfx_ReadPalette(&fifthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = fifthNclr->mData[0x60 + colorIndex];
            }
            break;
        case MISSION_NUMBER_KING_ICE_DONKETU:
            CopyCharsBlock(transferMapMrCharData, 0x18, 0, 4, 4, chars, 0, 12);
            sixthNclr = NULL;
            Gfx_ReadPalette(&sixthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
            for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                palette[0x50 + colorIndex] = sixthNclr->mData[0x70 + colorIndex];
            }
            break;
        case MISSION_NUMBER_HANACHAN:
            CopyCharsBlock(transferMapMrCharData, 0x0, 4, 8, 4, chars, 0, 12);
            seventhNclr = NULL;
            Gfx_ReadPalette(&seventhNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_mr_s_o.NCLR"));
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

    Gfx_ReadCharGraphics(&transferChars, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_s_o.NCGR"));
    transferCharData = transferChars->mData;
    for (kartIndex = 0; kartIndex < (s32) g_GlobalCO->mKartCount; kartIndex++) {
        GetRacerCharacterIdAndUnk(kartIndex, &characterIndex, &paletteIndex);
        CopyCharsBlock(transferCharData, characterIndex << 1, 0, 2, 2, chars, kartIndex << 1, 0);
        oamEntry = g_GlobalB3C4->mRaceSNcerEntries[kartIndex]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
    }
    for (index = 0; index < (s32) g_GlobalCO->mKartCount; index++) {
        GetRacerCharacterIdAndUnk(index, &characterIndex, &paletteIndex);
        CopyCharsBlock(transferCharData, characterIndex << 1, 2, 2, 2, chars, (index << 1) + 0x10, 0);
        oamEntry = g_GlobalB3C4->mRaceSNcerEntries[index + 8]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        oamEntry = g_GlobalB3C4->mRaceGoalSNcerEntries[index]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        oamEntry = g_GlobalB3C4->mRaceGoalTeamSNcerEntries[index]->mPOamAttrArray;
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
            oamEntry = g_GlobalB3C4->mRaceNewRecordTaSNcerEntries[index + 7]->mPOamAttrArray;
            oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        }
    }
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        for (index = 0; index < 6; index++) {
            GetTimeTrialRecordCharacterIdAndUnk(index, &characterIndex, &paletteIndex);
            CopyCharsBlock(transferCharData, characterIndex << 1, 2, 2, 2, chars, ((index + 2) << 1) + 0x10, 0);
            oamEntry = g_GlobalB3C4->mRaceNewRecordTaSNcerEntries[index + 8]->mPOamAttrArray;
            oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfff) + (paletteIndex << 12);
        }
    }
    for (nameIndex = 0; nameIndex < (s32) g_GlobalCO->mKartCount; nameIndex++) {
        s32 nameTilePositions[8][2] = {{16, 8}, {16, 10}, {11, 12}, {18, 12}, {25, 12}, {11, 14}, {18, 14}, {25, 14}};

        CopyCharsBlock(GetSomeBgCanvasTileData_from_thumb(), (nameIndex % 4) << 3, ((u32) nameIndex >> 2) << 1, 7, 2, chars,
                       nameTilePositions[nameIndex][0], nameTilePositions[nameIndex][1]);
    }
    Clear1A44SomeTileData_from_thumb();
    Gfx_ReadCharGraphics(&transferChars, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCGR"));
    transferCharData = transferChars->mData;
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        CopyCharsBlock(transferCharData, 0x14, 6, 0xc, 4, chars, 0, 8);
        CopyCharsBlock(transferCharData, 0x14, 0xa, 0xb, 4, chars, 0, 0xc);
        firstNclr = NULL;
        Gfx_ReadPalette(&firstNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
        for (colorIndex = 0; colorIndex < 16; colorIndex++) {
            palette[0x40 + colorIndex] = firstNclr->mData[0xd0 + colorIndex];
        }
    } else {
        switch (g_GlobalCO->mCourseId) {
            case COURSE_ID_OLD_NOKO_SFC:
            case COURSE_ID_BEACH:
            case COURSE_ID_MINI_STAGE3:
                CopyCharsBlock(transferCharData, 0x0, 0, 4, 2, chars, 0, 8);
                secondNclr = NULL;
                Gfx_ReadPalette(&secondNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = secondNclr->mData[colorIndex];
                }
                break;
            case COURSE_ID_OLD_MARIO_SFC:
            case COURSE_ID_MANSION:
            case COURSE_ID_OLD_DONUT_SFC:
                CopyCharsBlock(transferCharData, 0x4, 0, 5, 2, chars, 0, 8);
                thirdNclr = NULL;
                Gfx_ReadPalette(&thirdNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = thirdNclr->mData[0x10 + colorIndex];
                }
                break;
            case COURSE_ID_DESERT:
                CopyCharsBlock(transferCharData, 0x9, 0, 6, 2, chars, 0, 8);
                fourthNclr = NULL;
                Gfx_ReadPalette(&fourthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fourthNclr->mData[0x20 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_CHOCO_64:
                CopyCharsBlock(transferCharData, 0xf, 0, 3, 2, chars, 0, 8);
                fifthNclr = NULL;
                Gfx_ReadPalette(&fifthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fifthNclr->mData[0x30 + colorIndex];
                }
                break;
            case COURSE_ID_PINBALL:
                CopyCharsBlock(transferCharData, 0, 2, 0xc, 4, chars, 0, 8);
                CopyCharsBlock(transferCharData, 0, 6, 0xb, 4, chars, 0, 0xc);
                if (g_GlobalCO->mMirrorMode != 0) {
                    CopyCharsBlockFlippedVertically(transferCharData, 0, 2, 8, 8, chars, 0, 8);
                }
                sixthNclr = NULL;
                Gfx_ReadPalette(&sixthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = sixthNclr->mData[0x40 + colorIndex];
                }
                break;
            case COURSE_ID_RIDGE:
            case COURSE_ID_OLD_KINOKO_GC:
                CopyCharsBlock(transferCharData, 0x14, 0, 8, 4, chars, 0, 8);
                seventhNclr = NULL;
                Gfx_ReadPalette(&seventhNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = seventhNclr->mData[0x50 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_FRAPPE_64:
            case COURSE_ID_SNOW:
                CopyCharsBlock(transferCharData, 0x1d, 0, 3, 2, chars, 0, 8);
                eighthNclr = NULL;
                Gfx_ReadPalette(&eighthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = eighthNclr->mData[0x60 + colorIndex];
                }
                break;
            case COURSE_ID_CLOCK:
                CopyCharsBlock(transferCharData, 0xc, 4, 8, 4, chars, 0, 8);
                ninthNclr = NULL;
                Gfx_ReadPalette(&ninthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
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
                Gfx_ReadPalette(&tenthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
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
                Gfx_ReadPalette(&eleventhNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = eleventhNclr->mData[0x90 + colorIndex];
                }
                break;
            case COURSE_ID_STADIUM:
                CopyCharsBlock(transferCharData, 0x8, 10, 8, 4, chars, 0, 8);
                twelfthNclr = NULL;
                Gfx_ReadPalette(&twelfthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = twelfthNclr->mData[0x80 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_KOOPA_AGB:
            case COURSE_ID_KOOPA:
                CopyCharsBlock(transferCharData, 0xc, 8, 8, 2, chars, 0, 8);
                thirteenthNclr = NULL;
                Gfx_ReadPalette(&thirteenthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = thirteenthNclr->mData[0xa0 + colorIndex];
                }
                break;
            case COURSE_ID_RAINBOW:
                CopyCharsBlock(transferCharData, 0x12, 10, 2, 2, chars, 0, 8);
                fourteenthNclr = NULL;
                Gfx_ReadPalette(&fourteenthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fourteenthNclr->mData[0xb0 + colorIndex];
                }
                break;
            case COURSE_ID_OLD_HYUDORO_64:
                CopyCharsBlock(transferCharData, 0x0, 10, 8, 6, chars, 0, 8);
                fifteenthNclr = NULL;
                Gfx_ReadPalette(&fifteenthNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("race_transfer_map_s_o.NCLR"));
                for (colorIndex = 0; colorIndex < 16; colorIndex++) {
                    palette[0x40 + colorIndex] = fifteenthNclr->mData[0xe0 + colorIndex];
                }
                break;
        }
    }
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        CopyRaceTransferMapMrSO(palette, chars);
    }
}
