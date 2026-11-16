#include "Main/Menu/select_race_rule_load.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/wait_load.h"
#include "Main/Menu/select_cup_name_files.h"
#include "vram_transfer_queue.h"
#include "Main/Menu/select_race_rule_state.h"

#pragma thumb on

const u16 gSelectRaceRuleStepCellsChanging[5][2] = {{0xa, 0xf}, {0xb, 0x10}, {0xc, 0x11}, {0xd, 0x12}, {0xe, 0x13}};
const u16 gSelectRaceRuleStepCellsPlain[5][2] = {{0x14, 0x19}, {0x15, 0x1a}, {0x16, 0x1b}, {0x17, 0x1c}, {0x18, 0x1d}};
const char *gSelectCupNameMBnclName = "common/select_cup_name_m.bncl";
const u32 gSelectRaceRulePreviousRectRows[5] = {0, 1, 2, 3, 4};
const u32 gSelectRaceRuleEntryInputSlots[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const SelectRaceRuleNscrRect gSelectRaceRuleSMenuNscrRects[5] = {{0, 0, 0x20, 4, 0, 1},
                                                                 {0, 3, 0x20, 4, 0, 2},
                                                                 {0, 7, 0x20, 4, 0, 1},
                                                                 {0, 0xa, 0x20, 6, 0, 2},
                                                                 {0, 0xf, 0x20, 5, 0, 1}};
const SelectRaceRuleNscrRect gSelectRaceRuleMultiSimpleNscrRects[5] = {
    {0, 0, 0, 0, 0, 0}, {0, 0, 0x20, 5, 0, 1}, {0, 0, 0, 0, 0, 0}, {0, 4, 0x20, 8, 0, 2}, {0, 0xb, 0x20, 7, 0, 1}};
const char *gSelectCupNameMNcgrName = "common/select_cup_name_m.nce.ncgr";
const char *gSelectCupNameMNcerName = "common/select_cup_name_m.nce.ncer";

void VerifyCommonSelectRaceRuleFiles_from_thumb(void) {
    void *sceneFile;
    Ncgr *cellChars;
    NNSG2dCellDataBank *cells;
    Nclr *cellPalette;
    Ncgr *bgChars;
    Nscr *screenMap;
    Nclr *bgPalette[1];
    cellChars = NULL;
    cells = NULL;
    cellPalette = NULL;
    bgChars = NULL;
    screenMap = NULL;
    bgPalette[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_b_ncgr);
    Gfx_ReadCharGraphicsV2(&bgChars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_menu_nscr);
    MaybeReadScreenBlock_0(&screenMap, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_b_nclr);
    Gfx_ReadPalette(bgPalette, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_multi_simple_s_b_ncgr);
    Gfx_ReadCharGraphicsV2(&bgChars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_multi_simple_s_nscr);
    MaybeReadScreenBlock_0(&screenMap, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_nce_ncgr);
    Gfx_ReadCharGraphics(&cellChars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_nce_ncer);
    LoadCellBankFrom(&cells, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_o_nclr);
    Gfx_ReadPalette(&cellPalette, sceneFile);
    VerifyCommonWaitFiles_from_thumb();
}

void LocateAndQueueSelectRaceRule(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Ncgr *bgChars;
    Nclr *bgPalette;
    cellChars = NULL;
    bgChars = NULL;
    bgPalette = NULL;
    if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE) {
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_multi_simple_s_b_ncgr);
        MaybeReadCharBlock_1(&bgChars, sceneFile);
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_multi_simple_s_nscr);
        MaybeReadScreenBlock(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleMultiSimpleSBnclName);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleMultiSimpleSBnblName);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleMultiSimpleSBnllName);
        gSelectRaceRule->mBnll = sceneFile;
    } else {
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_b_ncgr);
        MaybeReadCharBlock_1(&bgChars, sceneFile);
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_menu_nscr);
        MaybeReadScreenBlock(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleSBnclName);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleSBnblName);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectRaceRuleSBnllName);
        gSelectRaceRule->mBnll = sceneFile;
    }
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_b_nclr);
    Gfx_ReadPaletteRelative(&bgPalette, sceneFile);
    sceneFile = Mem_AllocateHeap(gSelectRaceRule->mHeap, (0x00000800u));
    gSelectRaceRule->mSecondScreenMapBuffer = sceneFile;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_nce_ncgr);
    Gfx_ReadCharGraphicsRelative(&cellChars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_nce_ncer);
    LocateNcer(&gSelectRaceRule->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_select_race_rule_s_o_nclr);
    Gfx_ReadPaletteRelative(&gSelectRaceRule->mNclr, sceneFile);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG0_TILES, 0, bgChars->mData, bgChars->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG3_MAP, 0, gSelectRaceRule->mNscr->mData,
                                       gSelectRaceRule->mNscr->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG3_MAP, (0x00000800u),
                                       gSelectRaceRule->mSecondScreenMapBuffer, (0x00000800u));
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0, bgPalette->mData, 0x80);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, cellChars->mData, cellChars->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, gSelectRaceRule->mNclr->mData,
                                       gSelectRaceRule->mNclr->mDataSize);
}

#pragma thumb off
