#include "Main/Race/results_battle_registers.h"
#include "Main/Menu/wl_menu_kind.h"
#include "Main/System/interpolation_value.h"
#include "Main/Race/cup_records.h"
#include "Main/System/low_byte.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/System/backup_net_camera_work.h"
#include "registers.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/layout_table_entry.h"
#include "vram_bank_display_setup.h"
#include "vram_transfer_queue.h"
#include "cpu_copy_clear_16.h"
#include "Main/Scene/run_scene_connection.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Race/race.h"
#include "Main/Race/results_battle_frame_limit.h"
#include "Main/Net/wifi_session.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Graphics/scene_text.h"
#include "Main/MapObjects/trophy.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/menu.h"
#include "Main/Net/packed_index.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Race/race_scene_callbacks.h"
#include "01/Scene/test_scene.h"
#include "Main/Graphics/cell_layout.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/time_attack_ghost_get_scan.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Scene/display_settings_descs.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u16 gResultsBattleSubLabelCanvasEntries[16][4] = {
    {0, 0x30, 0x10, 0},     {1, 0x30, 0x10, 1},     {2, 0x30, 0x10, 2},     {3, 0x30, 0x10, 3},
    {4, 0x30, 0x10, 4},     {5, 0x30, 0x10, 5},     {6, 0x30, 0x10, 6},     {7, 0x30, 0x10, 7},
    {8, 0x18, 0xb, 0x30},   {9, 0x18, 0xb, 0x31},   {0xa, 0x18, 0xb, 0x32}, {0xb, 0x18, 0xb, 0x33},
    {0xc, 0x18, 0xb, 0x34}, {0xd, 0x18, 0xb, 0x35}, {0xe, 0x18, 0xb, 0x36}, {0xf, 0x18, 0xb, 0x37}};
const u8 gResultsBattleRankZeroLabelTextRows[64] = {0, 0, 0xb0, 0, 0x10, 0, 0, 0, 1, 0, 0x96, 0, 0x10, 0, 1, 0,
                                                    2, 0, 0x96, 0, 0x10, 0, 2, 0, 3, 0, 0x96, 0, 0x10, 0, 3, 0,
                                                    4, 0, 0x96, 0, 0x10, 0, 4, 0, 5, 0, 0x96, 0, 0x10, 0, 5, 0,
                                                    6, 0, 0x96, 0, 0x10, 0, 6, 0, 7, 0, 0x96, 0, 0x10, 0, 7, 0};
const u16 gResultsBattleKartFirstCellIndices[8] = {0, 4, 0xa, 0x12, 0x1c, 0x28, 0x36, 0};
const u16 gResultsBattleTeamFirstCellIndices[8] = {0, 2, 6, 0xc, 0x14, 0x1e, 0x2a, 0};
const u8 gResultsBattleOwnEntryLabelTextRows[8] = {0, 0, 0x8c, 0, 0x10, 0, 0, 0};
char gResultsBattleVictoryBNcgrName[] = "results_battle_victory_m_b.NCGR";
char gResultsBattleVictoryBNclrName[] = "results_battle_victory_m_b.NCLR";
char gResultsBattleVictoryUpperNscrName[] = "results_battle_victory_m_upper.NSCR";
char gResultsBattleVictoryLowerNscrName[] = "results_battle_victory_m_lower.NSCR";
char gResultsBattleVictoryNcgrName[] = "results_battle_victory_m.nce.ncgr";
char gResultsBattleVictoryNcerName[] = "results_battle_victory_m.nce.ncer";
char gResultsBattleVictoryONclrName[] = "results_battle_victory_m_o.NCLR";
char gResultsBattleVictoryBnclName[] = "Results_battle_victory_m.bncl";
char gResultsBattleVictoryBnllName[] = "Results_battle_victory_m.bnll";
char gResultsBattleVsRedNcerName[] = "results_battle_VS_m.nce.ncer";
char gResultsBattleDrawONclrName[] = "results_battle_draw_m_o.NCLR";
char gResultsBattleLoseUpperNscrName[] = "results_battle_lose_m_upper.NSCR";
char gResultsBattleLoseLowerNscrName[] = "results_battle_lose_m_lower.NSCR";
char gResultsBattleLoseNcgrName[] = "results_battle_lose_m.nce.ncgr";
char gResultsBattleLoseNcerName[] = "results_battle_lose_m.nce.ncer";
char gResultsBattleLoseONclrName[] = "results_battle_lose_m_o.NCLR";
char gResultsBattleLoseBnclName[] = "Results_battle_lose_m.bncl";
char gResultsBattleVsRedBNclrName[] = "results_battle_VS_m_b.NCLR";
char gResultsBattleLoseBNclrName[] = "results_battle_lose_m_b.NCLR";
char gResultsBattleDrawBNclrName[] = "results_battle_draw_m_b.NCLR";
char gResultsBattleDrawUpperNscrName[] = "results_battle_draw_m_upper.NSCR";
char gResultsBattleDrawLowerNscrName[] = "results_battle_draw_m_lower.NSCR";
char gResultsBattleDrawNcgrName[] = "results_battle_draw_m.nce.ncgr";
char gResultsBattleDrawNcerName[] = "results_battle_draw_m.nce.ncer";
char gResultsBattleDrawBNcgrName[] = "results_battle_draw_m_b.NCGR";
char gResultsBattleDrawBnclName[] = "Results_battle_draw_m.bncl";
char gResultsBattleVsBlueBNclrName[] = "results_battle_VS_m_b.NCLR";
char gResultsBattleVsBlueBNcgrName[] = "results_battle_VS_m_b.NCGR";
char gResultsBattleVsBlueUpperNscrName[] = "results_battle_VS_m_upper_blue.NSCR";
char gResultsBattleVsBlueLowerNscrName[] = "results_battle_VS_m_lower_blue.NSCR";
char gResultsBattleVsBlueNcgrName[] = "results_battle_VS_m.nce.ncgr";
char gResultsBattleVsBlueNcerName[] = "results_battle_VS_m.nce.ncer";
char gResultsBattleVsRedONclrName[] = "results_battle_VS_m_o.NCLR";
char gResultsBattleVsRedBnclName[] = "Results_battle_VS_m.bncl";
char gResultsBattleLoseBnllName[] = "Results_battle_lose_m.bnll";
char gResultsBattleVsRedBNcgrName[] = "results_battle_VS_m_b.NCGR";
char gResultsBattleVsRedUpperNscrName[] = "results_battle_VS_m_upper_red.NSCR";
char gResultsBattleVsRedLowerNscrName[] = "results_battle_VS_m_lower_red.NSCR";
char gResultsBattleVsRedNcgrName[] = "results_battle_VS_m.nce.ncgr";
char gResultsBattleLoseBNcgrName[] = "results_battle_lose_m_b.NCGR";
char gResultsBattleVsBlueONclrName[] = "results_battle_VS_m_o.NCLR";
char gResultsBattleVsBlueBnclName[] = "Results_battle_VS_m.bncl";
const ResultsBattleVictoryFileNames gResultsBattleVictoryFileNames[5] = {
    {gResultsBattleVictoryBNcgrName, gResultsBattleVictoryBNclrName, gResultsBattleVictoryUpperNscrName,
     gResultsBattleVictoryLowerNscrName, gResultsBattleVictoryNcgrName, gResultsBattleVictoryNcerName,
     gResultsBattleVictoryONclrName, gResultsBattleVictoryBnclName, gResultsBattleVictoryBnllName},
    {gResultsBattleLoseBNcgrName, gResultsBattleLoseBNclrName, gResultsBattleLoseUpperNscrName,
     gResultsBattleLoseLowerNscrName, gResultsBattleLoseNcgrName, gResultsBattleLoseNcerName,
     gResultsBattleLoseONclrName, gResultsBattleLoseBnclName, gResultsBattleLoseBnllName},
    {gResultsBattleDrawBNcgrName, gResultsBattleDrawBNclrName, gResultsBattleDrawUpperNscrName,
     gResultsBattleDrawLowerNscrName, gResultsBattleDrawNcgrName, gResultsBattleDrawNcerName,
     gResultsBattleDrawONclrName, gResultsBattleDrawBnclName, NULL},
    {gResultsBattleVsBlueBNcgrName, gResultsBattleVsBlueBNclrName, gResultsBattleVsBlueUpperNscrName,
     gResultsBattleVsBlueLowerNscrName, gResultsBattleVsBlueNcgrName, gResultsBattleVsBlueNcerName,
     gResultsBattleVsBlueONclrName, gResultsBattleVsBlueBnclName, NULL},
    {gResultsBattleVsRedBNcgrName, gResultsBattleVsRedBNclrName, gResultsBattleVsRedUpperNscrName,
     gResultsBattleVsRedLowerNscrName, gResultsBattleVsRedNcgrName, gResultsBattleVsRedNcerName,
     gResultsBattleVsRedONclrName, gResultsBattleVsRedBnclName, NULL}};
ResultsBattle *g_GlobalV;

// Reads the table of g_GlobalLU, a row chosen by one call and a column by another.
static inline KartCourseResult *ResultsBattleGetKartCourseResult(u32 entryIndex) {
    return &g_GlobalLU->mKartResults[GetSomeLUMaxIndex()][Int32ToInt8(entryIndex)];
}

#pragma thumb on

void WriteGhostGetScanRegisters(void) {
    s16 offset;
    u32 subWinOutBits;
    u32 subWinInBits;
    s32 negatedOffset;
    s32 mainWinInBits;

    offset = GetInterpolatedValue(&gTimeAttackGhostGetScan->mInterpolation);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    switch (offset) {
        default:
            reg_GX_DISPCNT =
                (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
                REG_GX_DISPCNT_W0_MASK;
            mainWinInBits = (reg_G2_WININ & ~REG_G2_WININ_WIN0IN_MASK) | 0x1f;
            reg_G2_WININ = mainWinInBits | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK |
                                                         REG_GXS_DB_DISPCNT_W0_MASK)) |
                                 REG_GXS_DB_DISPCNT_W0_MASK;
            subWinInBits = (reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | 0x1f;
            reg_G2S_DB_WININ = subWinInBits | 0x20;
            subWinOutBits = (reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | 7;
            reg_G2S_DB_WINOUT = subWinOutBits | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT =
                reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK |
                                                        REG_GXS_DB_DISPCNT_W0_MASK);
            break;
    }
}

void AssignResultsBattleTeamOrder(void) {
    ResultsBattle *resultsBattle;
    s32 nextOrderIndex;
    s32 team1Count;
    s32 entryIndex;

    nextOrderIndex = 0;
    team1Count = 0;
    for (entryIndex = 0; entryIndex < g_GlobalV->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 0) {
            g_GlobalV->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
    for (entryIndex = 0; entryIndex < g_GlobalV->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            team1Count++;
        }
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (entryIndex = 0; entryIndex < g_GlobalV->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            g_GlobalV->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
}

void AssignResultsBattleTeamOrderByScore(void) {
    ResultsBattle *resultsBattle;
    s32 scores[8];
    s32 team0Entries[8];
    s32 team1Entries[8];
    s32 team0BestIndex;
    s32 nextOrderIndex;
    s32 memberIndex;
    s32 team0Count;
    s32 kartIndex;
    s32 team1Count;
    s32 team1Step;
    s32 team0BestScore;
    s32 team0Step;
    s32 team1BestScore;
    s32 team1BestIndex;

    nextOrderIndex = 0;
    team0Count = 0;
    team1Count = 0;
    for (kartIndex = 0; kartIndex < (resultsBattle = g_GlobalV)->mKartCount; kartIndex++) {
        scores[kartIndex] = resultsBattle->mEntries[kartIndex].mScore;
    }
    for (kartIndex = 0; kartIndex < (resultsBattle = *(ResultsBattle **) &g_GlobalV)->mKartCount; kartIndex++) {
        if (GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 0) {
            team0Entries[team0Count] = kartIndex;
            team0Count = team0Count + 1;
        } else {
            team1Entries[team1Count] = kartIndex;
            team1Count = team1Count + 1;
        }
    }
    for (team0Step = 0; team0Step < team0Count; team0Step++) {
        team0BestScore = -1;
        team0BestIndex = -1;
        for (memberIndex = 0; memberIndex < team0Count; memberIndex++) {
            if (team0BestScore < scores[team0Entries[memberIndex]]) {
                team0BestScore = scores[team0Entries[memberIndex]];
                team0BestIndex = memberIndex;
            }
        }
        g_GlobalV->mEntries[team0Entries[team0BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team0Entries[team0BestIndex]] = -2;
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (team1Step = 0; team1Step < team1Count; team1Step++) {
        team1BestScore = -1;
        team1BestIndex = -1;
        for (memberIndex = 0; memberIndex < team1Count; memberIndex++) {
            if (team1BestScore < scores[team1Entries[memberIndex]]) {
                team1BestScore = scores[team1Entries[memberIndex]];
                team1BestIndex = memberIndex;
            }
        }
        g_GlobalV->mEntries[team1Entries[team1BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team1Entries[team1BestIndex]] = -2;
    }
}

void FillResultsBattleEntries(void) {
    u16 rankKartIndex;
    u16 kartIndex;
    s32 higherCount;

    for (kartIndex = 0; kartIndex < g_GlobalV->mKartCount; kartIndex++) {
        if (g_GlobalV->mMode == CONNECTION_KIND_WIFI_MENU || g_GlobalCO->mRuleKind == RULE_KIND_RACE_COUNT) {
            g_GlobalV->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(Int32ToInt8(kartIndex))->mTotalPoints;
        } else {
            g_GlobalV->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(Int32ToInt8(kartIndex))->mWinCount;
        }
    }
    for (rankKartIndex = 0; rankKartIndex < g_GlobalV->mKartCount; rankKartIndex++) {
        higherCount = 0;
        for (kartIndex = 0; kartIndex < g_GlobalV->mKartCount; kartIndex++) {
            if (rankKartIndex != kartIndex &&
                g_GlobalV->mEntries[rankKartIndex].mScore < g_GlobalV->mEntries[kartIndex].mScore) {
                higherCount++;
            }
        }
        g_GlobalV->mEntries[rankKartIndex].mRank = higherCount;
    }
    if (g_GlobalCO->mUseTeams != 0) {
        if (g_GlobalCO->mMode == MODE_BATTLE && g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT) {
            AssignResultsBattleTeamOrder();
        } else {
            AssignResultsBattleTeamOrderByScore();
        }
    } else if (g_GlobalCO->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < g_GlobalV->mKartCount; kartIndex++) {
            g_GlobalV->mEntries[kartIndex].mOrderIndex = g_GlobalB488->mOrderIndices[kartIndex];
        }
    } else {
        for (kartIndex = 0; kartIndex < g_GlobalV->mKartCount; kartIndex++) {
            g_GlobalV->mEntries[kartIndex].mOrderIndex = GetSomeRacerPosition(kartIndex) - 1;
        }
    }
}

s32 AreResultsBattleRanksAllZero(void) {
    s32 allRanksZero;
    s32 kartIndex;

    allRanksZero = 1;
    kartIndex = 0;
    for (; kartIndex < g_GlobalV->mKartCount; kartIndex++) {
        allRanksZero &= g_GlobalV->mEntries[kartIndex].mRank == 0 ? 1 : 0;
    }
    return allRanksZero;
}

s32 IsResultsBattleTimerRunOut(void) {
    BOOL result;

    result = FALSE;
    if (g_GlobalV->mUseTimer != FALSE && g_GlobalV->mTimer == 0) {
        result = TRUE;
    }
    return result;
}

s32 IsResultsBattleTimerBelowChoiceStart(void) {
    BOOL result;

    result = FALSE;
    if (g_GlobalV->mUseTimer != FALSE && g_GlobalV->mTimer < RESULTS_BATTLE_TIMER_CHOICE_FRAMES) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void StartResultsBattleChoices(void) {
    void *firstText;
    void *secondText;
    firstText = Bmg_GetRawStringPointer_from_thumb(g_GlobalV->mCommonMessages, 0x5d);
    secondText = Bmg_GetRawStringPointer_from_thumb(g_GlobalV->mCommonMessages, 0x5f);
    StartSelectChoises(firstText, secondText, 0);
}

#pragma thumb off

static inline void ResultsBattleEntryMI_CpuClear16(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    Mem_CpuFill16(fillValue, buffer, byteCount);
}

#pragma thumb on

void SetResultsBattleEntryCellsVisible(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    BOOL isTeamIndex1;
    BOOL cellVisible;
    BOOL isOwnEntry;
    BOOL isOwnNotTeam1;

    subCellFileSet = &g_GlobalV->mCellFileSets[1];
    if (g_GlobalV->mOwnEntryIndex == entryIndex) {
        isOwnEntry = TRUE;
    } else {
        isOwnEntry = FALSE;
    }
    orderIndex = g_GlobalV->mEntries[entryIndex].mOrderIndex;
    if (g_GlobalCO->mUseTeams != 0) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            isTeamIndex1 = TRUE;
        } else {
            isTeamIndex1 = FALSE;
        }
        isOwnNotTeam1 = FALSE;
        if (isTeamIndex1 == FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        if (cellVisible != FALSE && isOwnEntry != FALSE) {
            isOwnNotTeam1 = TRUE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = isOwnNotTeam1;
        if (cellVisible != FALSE && isOwnEntry == FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = cellVisible;
        if (isTeamIndex1 != FALSE && isOwnEntry != FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = cellVisible;
        if (isTeamIndex1 != FALSE && isOwnEntry == FALSE) {
            isOwnEntry = TRUE;
        } else {
            isOwnEntry = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = isOwnEntry;
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex].mVisible = subCellFileSet->mCellTable[orderIndex + 8].mVisible;
    } else {
        subCellFileSet->mCellTable[orderIndex].mVisible = isOwnEntry;
        if (isOwnEntry == FALSE) {
            isOwnEntry = TRUE;
        } else {
            isOwnEntry = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = isOwnEntry;
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = subCellFileSet->mCellTable[orderIndex + 0x28].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = subCellFileSet->mCellTable[orderIndex + 0x20].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = subCellFileSet->mCellTable[orderIndex + 0x18].mVisible;
    }
}

void PrintResultsBattleScoreAndShowRank(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    s32 score;
    s32 length;
    u16 scoreText[4];

    subCellFileSet = &g_GlobalV->mCellFileSets[1];
    orderIndex = g_GlobalV->mEntries[entryIndex].mOrderIndex;
    score = g_GlobalV->mEntries[entryIndex].mScore;
    if (g_GlobalCO->mMode == MODE_BATTLE && g_GlobalCO->mUseTeams != 0 &&
        g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT) {
        subCellFileSet->mCellTable[orderIndex + 0x38].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x48].mVisible = 0;
        return;
    }
    length = 0;
    ResultsBattleEntryMI_CpuClear16(scoreText, 8);
    if (score >= 100) {
        scoreText[length++] = 0x30 + (score / 100) % 10;
    }
    if (score >= 10) {
        scoreText[length++] = 0x30 + (score / 10) % 10;
    }
    scoreText[length++] = 0x30 + score % 10;
    scoreText[length] = 0;
    PrintLabelLayoutTextFixedDigits(1, orderIndex + 8, subCellFileSet->mLabelLayout, scoreText,
                                    subCellFileSet->mCellLayout, subCellFileSet->mCellTable, 6);
    orderIndex += 0x38;
    subCellFileSet->mCellTable[orderIndex].mVisible = 1;
    CopyCellLayoutEntryCellIndex(orderIndex, g_GlobalV->mEntries[entryIndex].mRank + 0x40,
                                 subCellFileSet->mCellLayout);
}

void QueueResultsBattleCharacterIcon(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 iconSetSelector) {
    CellFileSet *iconCellFileSet;
    CellFileSet *cellFileSet;
    s32 characterIndex;
    Nclr *palette;
    u8 *paletteBlock;
    u8 cellPaletteIndex;
    u32 shuffledIndex;

    cellFileSet = &g_GlobalV->mCellFileSets[cellFileSetIndex];
    if (iconSetSelector == 1) {
        iconCellFileSet = &g_GlobalV->mCellFileSets[2];
    } else {
        iconCellFileSet = &g_GlobalV->mCellFileSets[3];
    }
    characterIndex = GetCurrentEntry(entryIndex)->mCharacterIndex;
    QueueCellCharsAndFirstPalette(characterIndex, iconCellFileSet->mCells, iconCellFileSet->mChars,
                                  iconCellFileSet->mPalette, iconCellFileSet->mCellLayout, cellFileSetIndex, cellIndex,
                                  cellFileSet->mCells, cellFileSet->mCellLayout);
    if (characterIndex == 0xc) {
        if (iconSetSelector == 1) {
            palette = g_GlobalV->mCellFileSet2ShyguyPalette;
        } else {
            palette = g_GlobalV->mCellFileSet3ShyguyPalette;
        }
        cellPaletteIndex = GetCellPaletteIndex(cellIndex, cellFileSet->mCells, cellFileSet->mCellLayout);
        shuffledIndex = g_GlobalB488->mShuffledIndices[entryIndex];
        paletteBlock = shuffledIndex * 0x20 + palette->mBytes;
        if (cellFileSetIndex == 0) {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, cellPaletteIndex << 5, paletteBlock,
                                               0x20);
        } else {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, cellPaletteIndex << 5, paletteBlock,
                                               0x20);
        }
    }
}

void SetupResultsBattleOwnEntry(void *heap) {
    s32 index;
    u32 remainingObjSize;
    CellFileSet *mainCellFileSet;
    u8 *labelEntry;
    u16 entryName[11];

    remainingObjSize = GX_GetSizeOfOBJ();
    mainCellFileSet = &g_GlobalV->mCellFileSets[0];
    g_GlobalV->mTimerDigitCellBase = 1;
    g_GlobalV->mTimerTensCell = 0xb;
    index = 0;
    if ((s32) mainCellFileSet->mLabelLayout->mCount > 0) {
        labelEntry = (u8 *) gResultsBattleOwnEntryLabelTextRows;
        do {
            remainingObjSize -= SetupLabelCanvas(SCREEN_SIDE_MAIN, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            index++;
        } while (index < mainCellFileSet->mLabelLayout->mCount);
    }
    ResultsBattleEntryMI_CpuClear16(entryName, 0x16);
    FormatRacerNameString_from_thumb((u16) g_GlobalV->mOwnEntryIndex, entryName, 1);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                                       mainCellFileSet->mCellTable);
    QueueResultsBattleCharacterIcon(0, g_GlobalV->mOwnEntryIndex, 0, 1);
}

void SetupResultsBattleRankZeroNames(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 rowIndex;
    s32 labelIndex;
    s32 entryIndex;
    s32 cellCount;
    u32 remainingObjSize;
    u8 *labelEntry;
    u16 entryName[11];
    s32 labelCount;
    LayoutTableEntry *cell;

    mainCellFileSet = &g_GlobalV->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    rowIndex = 0;
    cellCount = mainCellFileSet->mCellLayout->mCount;
    g_GlobalV->mTimerDigitCellBase = 8;
    g_GlobalV->mTimerTensCell = 0x12;
    labelIndex = 0;
    labelCount = mainCellFileSet->mLabelLayout->mCount;
    if (labelCount > 0) {
        labelEntry = (u8 *) gResultsBattleRankZeroLabelTextRows;
        do {
            remainingObjSize -= SetupLabelCanvas(rowIndex, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            labelIndex++;
        } while (labelIndex < mainCellFileSet->mLabelLayout->mCount);
    }
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainCellFileSet->mLabelLayout,
                                       Bmg_GetRawStringPointer_from_thumb(g_GlobalV->mCommonMessages, 0x7a), mainCellFileSet->mCellLayout,
                                       mainCellFileSet->mCellTable);
    for (entryIndex = 0; entryIndex < g_GlobalV->mKartCount; entryIndex++) {
        if (g_GlobalV->mEntries[entryIndex].mRank == 0) {
            ResultsBattleEntryMI_CpuClear16(entryName, 0x16);
            FormatRacerNameString_from_thumb((u16) entryIndex, entryName, 1);
            rowIndex++;
            PrintLabelLayoutTextNoFixedAdvance(0, rowIndex, mainCellFileSet->mLabelLayout, entryName,
                                               mainCellFileSet->mCellLayout, mainCellFileSet->mCellTable);
        }
    }
    while (rowIndex < 7) {
        rowIndex = rowIndex + 1;
        mainCellFileSet->mCellTable[rowIndex].mVisible = 0;
        rowIndex = (u32) rowIndex;
        cell = &mainCellFileSet->mCellTable[rowIndex + cellCount];
        cell->mVisible = 0;
    }
}

void SetupResultsBattleKartIcons(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 count;
    s32 iconCellBase;
    BOOL iconSetSelector;
    s32 index;

    mainCellFileSet = &g_GlobalV->mCellFileSets[0];
    count = g_GlobalV->mIconKartCount;
    iconCellBase = count + gResultsBattleKartFirstCellIndices[count - 2];
    if (count > 4) {
        iconSetSelector = FALSE;
    } else {
        iconSetSelector = TRUE;
    }
    g_GlobalV->mTimerDigitCellBase = 0x46;
    g_GlobalV->mTimerTensCell = 0x50;
    for (index = 0; index < 0x46; index++) {
        mainCellFileSet->mCellTable[index].mVisible = 0;
    }
    for (index = gResultsBattleKartFirstCellIndices[g_GlobalV->mIconKartCount - 2];
         index <
         gResultsBattleKartFirstCellIndices[g_GlobalV->mIconKartCount - 2] + g_GlobalV->mIconKartCount * 2;
         index++) {
        mainCellFileSet->mCellTable[index].mVisible = 1;
    }
    for (index = 0; index < g_GlobalV->mIconKartCount; index++) {
        QueueResultsBattleCharacterIcon(0, index, iconCellBase + index, iconSetSelector);
    }
}

void SetupResultsBattleTeamIcons(void *heap) {
    ResultsBattle *results;
    CellFileSet *mainCellFileSet;
    s32 teamIndex;
    s32 count;
    s32 iconCellBase;
    s32 sourceCellIndex;
    s32 placedCount;
    s32 hiddenCellIndex;
    BOOL iconSetSelector;
    s32 shownCellIndex;
    s32 iconCellIndex;
    s32 entryIndex;

    results = g_GlobalV;
    mainCellFileSet = &results->mCellFileSets[0];
    switch (results->mFileSetKind) {
        case RESULTS_BATTLE_FILES_VS_BLUE:
            teamIndex = 0;
            break;
        default:
            teamIndex = 1;
            break;
    }
    placedCount = 0;
    count = results->mIconKartCount;
    iconCellBase = count + gResultsBattleTeamFirstCellIndices[count - 1];
    if (count <= 5) {
        iconSetSelector = TRUE;
        sourceCellIndex = 0x38;
    } else {
        iconSetSelector = FALSE;
        sourceCellIndex = 0x39;
    }
    results->mTimerDigitCellBase = 0x3a;
    g_GlobalV->mTimerTensCell = 0x44;
    for (hiddenCellIndex = 0; hiddenCellIndex < 0x38; hiddenCellIndex++) {
        mainCellFileSet->mCellTable[hiddenCellIndex].mVisible = 0;
    }
    shownCellIndex = gResultsBattleTeamFirstCellIndices[g_GlobalV->mIconKartCount - 1];
    shownCellIndex = (u32) shownCellIndex;
    if (shownCellIndex <
        gResultsBattleTeamFirstCellIndices[g_GlobalV->mIconKartCount - 1] + g_GlobalV->mIconKartCount * 2) {
        do {
            mainCellFileSet->mCellTable[shownCellIndex].mVisible = 1;
            shownCellIndex++;
        } while (shownCellIndex < gResultsBattleTeamFirstCellIndices[g_GlobalV->mIconKartCount - 1] +
                                      g_GlobalV->mIconKartCount * 2);
    }
    if (g_GlobalV->mFileSetKind == RESULTS_BATTLE_FILES_VS_BLUE) {
        for (iconCellIndex = gResultsBattleTeamFirstCellIndices[g_GlobalV->mIconKartCount - 1];
             iconCellIndex <
             g_GlobalV->mIconKartCount + gResultsBattleTeamFirstCellIndices[g_GlobalV->mIconKartCount - 1];
             iconCellIndex++) {
            CopyCellLayoutEntryCellIndex(iconCellIndex, sourceCellIndex, mainCellFileSet->mCellLayout);
        }
    }
    for (entryIndex = 0; entryIndex < g_GlobalV->mKartCount; entryIndex++) {
        if (teamIndex == GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex) {
            QueueResultsBattleCharacterIcon(0, entryIndex, iconCellBase + placedCount, iconSetSelector);
            placedCount++;
        }
    }
    mainCellFileSet->mCellTable[0x39].mVisible = 0;
    mainCellFileSet->mCellTable[0x38].mVisible = mainCellFileSet->mCellTable[0x39].mVisible;
}

#pragma thumb off

#pragma thumb on

// Fills with 0 using a volatile halfword.
static inline void ResultsBattleMI_CpuClear16(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    Mem_CpuFill16(fillValue, buffer, byteCount);
}

static inline CourseTeamResult *ResultsBattleGetCourseTeamResult(s32 teamIndex) {
    return &g_GlobalLU->mTeamResults[GetSomeLUMaxIndex()].mTeams[teamIndex];
}

static inline CourseTeamResults *GetCourseTeamResults(void) {
    return &g_GlobalLU->mTeamResults[GetSomeLUMaxIndex()];
}

void InstanceStructV_from_thumb(void *heap, void *mainOam, void *subOam) {
    DisplaySettings *displaySettings;
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    ResultsBattle *results;
    ScreenMapFileSet *screenMapFileSet;
    LayoutEntryTable *cellLayout;
    u32 remainingObjSize;
    s32 firstTeamScore;
    s32 value;
    s32 orderIndex;
    u16 itemIndex;
    u16 entryIndex;
    u16 entryName[11];
    SceneTextInitParams sceneTextInitParams;
    s32 orderUsed[8];

    g_GlobalV = Mem_AllocateHeap(heap, sizeof(*g_GlobalV));
    MemFillWordsByBlock_inline(g_GlobalV, 0x154);
    g_GlobalV->mOamLists[0] = mainOam;
    g_GlobalV->mOamLists[1] = subOam;
    g_GlobalV->mMode = g_GlobalP->mConnectionKind;
    if (g_GlobalV->mMode == CONNECTION_KIND_WIFI_MENU) {
        SetupWiFiSession(WIFI_SESSION_SETUP_CONTINUE_CHOICES);
    }
    Init3dEngine();
    displaySettings = CreateDisplayConfig(heap, gResultsDisplaySettingsDesc);
    DisplayEngineConfig_SetBg0Config(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0xd, 2, 0);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 0xc, 0, 0);
    DisplayEngineConfig_SetBg2Config2(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x1e, 6);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0x1d, 6);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    SetGlobalDisplayConfig(displaySettings);
    sceneTextInitParams.mUseTxtSystem = 0;
    sceneTextInitParams.mTxtSystemFont = NULL;
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 0;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = 1;
    sceneTextInitParams.mSelectChoisesFont = GetLoadedFont_from_thumb(2);
    sceneTextInitParams.mUseSelectReturn = 0;
    sceneTextInitParams.mUseBackScreen = 0;
    sceneTextInitParams.mBackScreenKind = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &sceneTextInitParams);
    InitFrmVramManagers();
    g_GlobalV->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    switch (g_GlobalV->mMode) {
        case CONNECTION_KIND_NONE:
            g_GlobalV->mOwnEntryIndex = 0;
            g_GlobalV->mKartCount = g_GlobalCO->mKartCount;
            g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_FRAMES;
            break;
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            SetSelectChoisesSoundId(1, 0xf);
            g_GlobalV->mOwnEntryIndex =
                GetParticipantPosByIndex(
                    g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD ? g_GlobalZE->mOwnIndex : 0)
                    ->mEntryIndex;
            g_GlobalV->mKartCount = g_GlobalCO->mKartCount;
            g_GlobalV->mState = RESULTS_BATTLE_STATE_START_SYNC;
            break;
        case CONNECTION_KIND_WIFI_MENU:
            g_GlobalV->mOwnEntryIndex = GetPackedIndex(DWC_GetMyAID());
            g_GlobalV->mKartCount = g_GlobalB->mKartCount;
            g_GlobalV->mUseTimer = TRUE;
            g_GlobalV->mTimer = RESULTS_BATTLE_TIMER_START_FRAMES;
            g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_FRAMES;
            break;
    }
    FillResultsBattleEntries();
    if (g_GlobalCO->mUseTeams != 0) {
        firstTeamScore = 0;
        value = 0;
        switch (g_GlobalCO->mRuleKind) {
            case RULE_KIND_WIN_COUNT:
                firstTeamScore = ResultsBattleGetCourseTeamResult(0)->mWinCount;
                value = ResultsBattleGetCourseTeamResult(1)->mWinCount;
                break;
            case RULE_KIND_RACE_COUNT:
                firstTeamScore = GetCourseTeamResults()->mTeams[0].mTotalPoints;
                value = GetCourseTeamResults()->mTeams[1].mTotalPoints;
                break;
        }
        if (firstTeamScore == value) {
            g_GlobalV->mIconKartCount = g_GlobalV->mKartCount;
            g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_DRAW;
        } else if (firstTeamScore > value) {
            g_GlobalV->mIconKartCount = g_GlobalCO->mTeamKartCounts[0];
            g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_VS_BLUE;
        } else if (value > firstTeamScore) {
            g_GlobalV->mIconKartCount = g_GlobalCO->mTeamKartCounts[1];
            g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_VS_RED;
        }
    } else if (AreResultsBattleRanksAllZero() != 0) {
        g_GlobalV->mIconKartCount = g_GlobalV->mKartCount;
        g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_DRAW;
    } else if (g_GlobalV->mEntries[g_GlobalV->mOwnEntryIndex].mRank == 0) {
        g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_VICTORY;
    } else {
        g_GlobalV->mFileSetKind = RESULTS_BATTLE_FILES_LOSE;
    }
    LoadPlayerGfxData_from_thumb(1, &g_GlobalV->mCellFileSets[2]);
    LoadPlayerGfxData_from_thumb(0, &g_GlobalV->mCellFileSets[3]);
    g_GlobalV->mCellFileSet2ShyguyPalette = GetPlayerCharacterShyGuyPalette_from_thumb(1);
    g_GlobalV->mCellFileSet3ShyguyPalette = GetPlayerCharacterShyGuyPalette_from_thumb(0);
    screenMapFileSet = &g_GlobalV->mScreenMapFileSets[0];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mBNcgrName,
                         gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mBNclrName,
                         gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mLowerNscrName, 3, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    MaybeReadScreenBlock_0(&screenMapFileSet->mScreenMaps[2],
                 FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mUpperNscrName));
    CopyBgData_Bg3_Top(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    CopyPaletteTop(screenMapFileSet->mPalette->mData, 0, 0x140);
    TEQSub_Fn10Impl_Fn12Impl(screenMapFileSet->mScreenMaps[2]->mData, 0, screenMapFileSet->mScreenMaps[2]->mDataSize);
    TEQSub_Fn11Impl_Fn13Impl(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    mainCellFileSet = &g_GlobalV->mCellFileSets[0];
    PlayerGfxData_Create_from_thumb(mainCellFileSet, gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mNcgrName,
                    gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mNcerName,
                    gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mONclrName,
                    gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mBnclName,
                    gResultsBattleVictoryFileNames[g_GlobalV->mFileSetKind].mBnllName, NULL, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    SetupCellFileSet(SCREEN_SIDE_MAIN, heap, mainCellFileSet);
    switch (g_GlobalV->mFileSetKind) {
        case RESULTS_BATTLE_FILES_VICTORY:
            SetupResultsBattleOwnEntry(heap);
            break;
        case RESULTS_BATTLE_FILES_LOSE:
            SetupResultsBattleRankZeroNames(heap);
            break;
        case RESULTS_BATTLE_FILES_DRAW:
            SetupResultsBattleKartIcons(heap);
            break;
        case RESULTS_BATTLE_FILES_VS_BLUE:
        case RESULTS_BATTLE_FILES_VS_RED:
            SetupResultsBattleTeamIcons(heap);
            break;
    }
    cellLayout = mainCellFileSet->mCellLayout;
    for (itemIndex = 0; itemIndex < cellLayout->mCount; itemIndex++) {
        GetCellLayoutEntry(mainCellFileSet->mCellLayout, itemIndex);
    }
    screenMapFileSet = &g_GlobalV->mScreenMapFileSets[1];
    LoadScreenMapFileSet(screenMapFileSet, "results_battle_s_b.NCGR", "results_battle_s_b.NCLR",
                         "results_battle_s_bg.NSCR", 3, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    CopyBgData_Bg3_Bottom(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    CopyPaletteBottom(screenMapFileSet->mPalette->mData, 0, 0x140);
    TEQSub_Fn27Impl_Fn29Impl(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    remainingObjSize = GX_GetSizeOfSubOBJ();
    results = g_GlobalV;
    subCellFileSet = &results->mCellFileSets[1];
    PlayerGfxData_Create_from_thumb(subCellFileSet, "results_battle_s.nce.ncgr", "results_battle_s.nce.ncer", "results_battle_s_o.NCLR",
                    "results_battle_s.bncl", "results_battle_s.bnll", NULL, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    InitLayoutTable(heap, subCellFileSet->mCellLayout, subCellFileSet->mLabelLayout, &subCellFileSet->mCellTable);
    TEQSub_Fn35Impl(results->mCellFileSets[1].mChars->mData, 0, results->mCellFileSets[1].mChars->mDataSize);
    TEQSub_Fn30Impl(subCellFileSet->mPalette->mData, 0, subCellFileSet->mPalette->mDataSize);
    for (itemIndex = 0; itemIndex < subCellFileSet->mLabelLayout->mCount; itemIndex++) {
        remainingObjSize -= SetupLabelCanvas(SCREEN_SIDE_SUB, heap, subCellFileSet,
                                             gResultsBattleSubLabelCanvasEntries[itemIndex], remainingObjSize);
    }
    for (itemIndex = 0; itemIndex < subCellFileSet->mCellLayout->mCount; itemIndex++) {
        SetCellPriority(itemIndex, 2, subCellFileSet->mCells, subCellFileSet->mCellLayout);
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        orderUsed[itemIndex] = 0;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        orderIndex = g_GlobalV->mEntries[entryIndex].mOrderIndex;
        value = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind;
        if ((value == PLAYER_KIND_HUMAN || value == PLAYER_KIND_CPU || value == PLAYER_KIND_PEER) &&
            (g_GlobalV->mMode != CONNECTION_KIND_WIFI_MENU || g_GlobalV->mEntries[entryIndex].mScore != 0)) {
            QueueResultsBattleCharacterIcon(1, entryIndex, orderIndex + 0x30, 1);
            ResultsBattleMI_CpuClear16(entryName, 0x16);
            FormatRacerNameString_from_thumb(entryIndex, entryName, 0);
            PrintLabelLayoutTextNoFixedAdvance(1, orderIndex, subCellFileSet->mLabelLayout, entryName,
                                               subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
            PrintResultsBattleScoreAndShowRank(entryIndex);
            SetResultsBattleEntryCellsVisible(entryIndex);
            orderUsed[orderIndex] = 1;
        }
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        if (orderUsed[itemIndex] == 0) {
            subCellFileSet->mCellTable[itemIndex + 0x48].mVisible = 0;
            subCellFileSet->mCellTable[itemIndex + 0x30].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x48].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x38].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x30].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x28].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x38].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x20].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x28].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x18].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x20].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x10].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x18].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x08].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x10].mVisible;
            subCellFileSet->mCellTable[itemIndex].mVisible = subCellFileSet->mCellTable[itemIndex + 0x08].mVisible;
        }
    }
    switch (g_GlobalV->mFileSetKind) {
        case RESULTS_BATTLE_FILES_VS_BLUE:
            if (GetCurrentEntry(g_GlobalV->mOwnEntryIndex)->mPlayer.mTeamIndex == 0) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case RESULTS_BATTLE_FILES_VS_RED:
            if (GetCurrentEntry(g_GlobalV->mOwnEntryIndex)->mPlayer.mTeamIndex == 1) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case RESULTS_BATTLE_FILES_VICTORY:
            value = 0;
            break;
        default:
            value = 7;
            break;
    }
    LoadCupTrophyModel(8, value);
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsBattle(SceneNumbers *sceneNumbers) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    InputSlotIndex inputSlotIndex;
    s32 shownTimer;
    s32 cellCount;
    void *tensCellLayout;
    void *tensCells;
    void *unitsCellLayout;
    void *unitsCells;
    s32 drawIndex;
    s32 frameLimit;

    subCellFileSet = &g_GlobalV->mCellFileSets[1];
    mainCellFileSet = &g_GlobalV->mCellFileSets[0];
    if (g_GlobalV->mUseTimer != FALSE) {
        if (g_GlobalV->mTimer != 0) {
            g_GlobalV->mTimer = g_GlobalV->mTimer - 1;
            shownTimer = (g_GlobalV->mTimer + RESULTS_BATTLE_TIMER_STEP_FRAMES) / RESULTS_BATTLE_TIMER_STEP_FRAMES;
            mainCellFileSet->mCellTable[g_GlobalV->mTimerTensCell].mVisible = shownTimer >= 10 ? 1 : 0;
            if (g_GlobalV->mTimer == 0) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x51);
            } else if ((g_GlobalV->mTimer + RESULTS_BATTLE_TIMER_STEP_FRAMES) % RESULTS_BATTLE_TIMER_STEP_FRAMES ==
                           0 &&
                       shownTimer <= 4) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x50);
            }
        } else {
            shownTimer = 0;
        }
        tensCellLayout = mainCellFileSet->mCellLayout;
        tensCells = mainCellFileSet->mCells;
        QueueCellChars(g_GlobalV->mTimerDigitCellBase + (shownTimer / 10) % 10, tensCells, mainCellFileSet->mChars,
                       tensCellLayout, 0, g_GlobalV->mTimerTensCell, tensCells, tensCellLayout);
        unitsCellLayout = mainCellFileSet->mCellLayout;
        unitsCells = mainCellFileSet->mCells;
        QueueCellChars(g_GlobalV->mTimerDigitCellBase + shownTimer % 10, unitsCells, mainCellFileSet->mChars,
                       unitsCellLayout, 0, g_GlobalV->mTimerTensCell + 1, unitsCells, unitsCellLayout);
    } else {
        mainCellFileSet->mCellTable[g_GlobalV->mTimerTensCell + 1].mVisible = 0;
        mainCellFileSet->mCellTable[g_GlobalV->mTimerTensCell].mVisible =
            mainCellFileSet->mCellTable[g_GlobalV->mTimerTensCell + 1].mVisible;
    }
    switch (g_GlobalV->mState) {
        case RESULTS_BATTLE_STATE_START_SYNC:
            g_GlobalV->mSyncAndWaitFrames = g_GlobalV->mSyncAndWaitFrames + 1;
            if (StartDataSharingSync() == 1) {
                g_GlobalV->mState = RESULTS_BATTLE_STATE_FINISH_SYNC;
            }
            break;
        case RESULTS_BATTLE_STATE_FINISH_SYNC:
            g_GlobalV->mSyncAndWaitFrames = g_GlobalV->mSyncAndWaitFrames + 1;
            if (FinishDataSharingSync() == 1) {
                g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_FRAMES;
            }
            break;
        case RESULTS_BATTLE_STATE_WAIT_FRAMES:
            frameLimit = GetResultsBattleFrameLimit();
            g_GlobalV->mSyncAndWaitFrames = g_GlobalV->mSyncAndWaitFrames + 1;
            if (g_GlobalV->mSyncAndWaitFrames > frameLimit) {
                g_GlobalV->mSyncAndWaitFrames = 0;
                g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_CONFIRM;
            }
            break;
        case RESULTS_BATTLE_STATE_WAIT_CONFIRM:
            switch (g_GlobalV->mMode) {
                case CONNECTION_KIND_NONE:
                    if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mPressedBits & PAD_KEY_A) != 0) {
                        PlaySseqFromSarc(&gSharedSeqHandle, 0, 5);
                        if (sceneNumbers != NULL) {
                            sceneNumbers->mNextScene = SCENE_MENU_1;
                        }
                        g_GlobalV->mState = RESULTS_BATTLE_STATE_DONE;
                    }
                    break;
                case CONNECTION_KIND_MEMBER_SELECT:
                case CONNECTION_KIND_WL_MENU:
                    inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
                    if ((u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
                        StartResultsBattleChoices();
                        g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_CHOICE;
                        PlaySseqFromSarc(&gSharedSeqHandle, 0, 5);
                    }
                    break;
                case CONNECTION_KIND_WIFI_MENU:
                    if (IsResultsBattleTimerRunOut() != 0) {
                        SetWiFiSessionOwnContinueChoice(1);
                        g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_WIFI_CONTINUE;
                    } else if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mPressedBits & PAD_KEY_A) != 0 ||
                               IsResultsBattleTimerBelowChoiceStart() != 0) {
                        StartResultsBattleChoices();
                        PlaySseqFromSarc(&gSharedSeqHandle, 0, 5);
                        g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_CHOICE;
                    }
                    break;
            }
            break;
        case RESULTS_BATTLE_STATE_WAIT_CHOICE:
            switch (g_GlobalV->mMode) {
                case CONNECTION_KIND_MEMBER_SELECT:
                case CONNECTION_KIND_WL_MENU:
                    if (GetSelectChoisesDone() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                if (g_GlobalP->mMultiSimple != 0) {
                                    g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_MENU;
                                    g_GlobalB488->mMenuEntryKind = MENU_ENTRY_SELECT_GAME;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = SCENE_WL_MENU;
                                    }
                                } else {
                                    g_GlobalB488->mMenuEntryKind = MENU_ENTRY_SELECT_GAME;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = SCENE_MENU_1;
                                    }
                                }
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_DONE;
                                break;
                            case 1:
                                g_GlobalZE->mFlags = g_GlobalZE->mFlags | CONNECTION_FLAG_ENDING;
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_END_CONNECTION;
                                break;
                            case -1:
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_CONFIRM;
                                break;
                        }
                        RequestSelectChoisesHidden();
                    }
                    break;
                case CONNECTION_KIND_WIFI_MENU:
                    if (GetSelectChoisesDone() != 0 || IsResultsBattleTimerRunOut() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_WIFI_CONTINUE;
                                SetWiFiSessionOwnContinueChoice(1);
                                break;
                            case 1:
                                SetWiFiSessionOwnContinueChoice(0);
                                g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_VS_SETTING;
                                if (sceneNumbers != NULL) {
                                    sceneNumbers->mNextScene = SCENE_WIFI_MENU;
                                }
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_DONE;
                                break;
                            case -1:
                                g_GlobalV->mState = RESULTS_BATTLE_STATE_WAIT_CONFIRM;
                                break;
                        }
                        RequestSelectChoisesHidden();
                    }
                    break;
            }
            break;
        case RESULTS_BATTLE_STATE_WAIT_WIFI_CONTINUE:
            if (GetWiFiSessionContinueResult() != 0) {
                switch (GetWiFiSessionContinueResult()) {
                    case WIFI_CONTINUE_RESULT_KARTS_LEFT:
                        g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_SELECT_CHARACTER;
                        break;
                    case WIFI_CONTINUE_RESULT_ENDED:
                        g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_VS_SETTING;
                        break;
                }
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = SCENE_WIFI_MENU;
                }
                g_GlobalV->mState = RESULTS_BATTLE_STATE_DONE;
            }
            break;
        case RESULTS_BATTLE_STATE_END_CONNECTION:
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                g_GlobalV->mState = RESULTS_BATTLE_STATE_DONE;
            }
            break;
    }
    AdvanceTrophy();
    DrawTrophy();
    for (drawIndex = 0; drawIndex < 2; drawIndex++) {
        DrawLayoutTable(g_GlobalV->mCellFileSets[drawIndex].mCellLayout,
                        g_GlobalV->mCellFileSets[drawIndex].mCells,
                        g_GlobalV->mCellFileSets[drawIndex].mLabelLayout, g_GlobalV->mOamLists[drawIndex],
                        g_GlobalV->mCellFileSets[drawIndex].mCellTable);
    }
    cellCount = subCellFileSet->mCellLayout->mCount;
    for (drawIndex = 0; drawIndex < 8; drawIndex++) {
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY + 1;
        SetLabelPaletteIndex(drawIndex, 0xe, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        DrawLayoutTableEntry(drawIndex + cellCount, subCellFileSet->mCellLayout, subCellFileSet->mCells,
                             subCellFileSet->mLabelLayout, g_GlobalV->mOamLists[1], subCellFileSet->mCellTable);
        SetLabelPaletteIndex(drawIndex, 0xf, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY - 1;
    }
    NavigationContext_OnSceneUpdate_from_thumb();
}

void ReleaseResultsBattle(void) {
    g_GlobalB488->mRaceSetupRequested = 1;
    DisposeNavigationContext_from_thumb();
}

#pragma thumb off

#pragma thumb on
void j_NavigationContext_OnSceneVblank_0_from_thumb(void) {
    u32 unused;
    NavigationContext_OnSceneVblank_from_thumb();
}
#pragma thumb off
