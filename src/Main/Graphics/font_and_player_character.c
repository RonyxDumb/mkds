#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/archive_slot_loaded.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

struct NNSG2dCellDataBank *g_PlayerCharacterNceNcers[2];
struct Nclr *g_PlayerCharacterPlts[2];
struct Nclr *g_PlayerShyGuyPlts[2];
struct Ncgr *g_PlayerCharacterNceNcgrs[2];
void *g_PlayerCharacterBNCLs[2];
struct NNSG2dFont g_NftrLcFontS;
struct NNSG2dFont *g_LoadedFonts[3];
struct NNSG2dFont g_NftrMarioFont;
struct NNSG2dFont g_NftrLcFontM;

#pragma thumb on
#pragma optimize_for_size on
void LoadMA2ContentIfMounted_from_thumb(void) {
    if (IsMountEntryLoaded_from_thumb(1) != 0) {
        NFTR_Load(&g_NftrLcFontS, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("LC_Font_s.NFTR"));
        NFTR_Load(&g_NftrLcFontM, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("LC_Font_m.NFTR"));
        NFTR_Load(&g_NftrMarioFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("marioFont.NFTR"));
        g_LoadedFonts[0] = &g_NftrLcFontS;
        g_LoadedFonts[1] = &g_NftrLcFontM;
        g_LoadedFonts[2] = &g_NftrMarioFont;
        Gfx_ReadPalette(g_PlayerCharacterPlts, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_M_o.NCLR"));
        Gfx_ReadPalette(g_PlayerShyGuyPlts, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_M_shyguy_o.NCLR"));
        Gfx_ReadCharGraphics(g_PlayerCharacterNceNcgrs, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_M.nce.ncgr"));
        LoadCellBankFrom(g_PlayerCharacterNceNcers, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_M.nce.ncer"));
        g_PlayerCharacterBNCLs[0] = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_M.bncl");
        Gfx_ReadPalette(&g_PlayerCharacterPlts[1], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_L_o.NCLR"));
        Gfx_ReadPalette(&g_PlayerShyGuyPlts[1], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_L_shyguy_o.NCLR"));
        Gfx_ReadCharGraphics(&g_PlayerCharacterNceNcgrs[1], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_L.nce.ncgr"));
        LoadCellBankFrom(&g_PlayerCharacterNceNcers[1], FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_L.nce.ncer"));
        g_PlayerCharacterBNCLs[1] = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("player_character_L.bncl");
    }
}

void CleanupPlayerGfxDataFontsEtc_from_thumb(void) {
    s32 fontIndex;
    s32 characterSetIndex;

    for (fontIndex = 0; fontIndex < 3; fontIndex++) {
        g_LoadedFonts[fontIndex] = NULL;
    }
    for (characterSetIndex = 0; characterSetIndex < 2; characterSetIndex++) {
        g_PlayerCharacterPlts[characterSetIndex] = NULL;
        g_PlayerShyGuyPlts[characterSetIndex] = NULL;
        g_PlayerCharacterNceNcgrs[characterSetIndex] = NULL;
        g_PlayerCharacterNceNcers[characterSetIndex] = NULL;
        g_PlayerCharacterBNCLs[characterSetIndex] = NULL;
    }
}
#pragma thumb off

#pragma thumb on
NNSG2dFont *GetLoadedFont_from_thumb(s32 index) {
    return g_LoadedFonts[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterPalette_from_thumb(int index) {
    return g_PlayerCharacterPlts[index];
}
#pragma thumb off

#pragma thumb on
Nclr *GetPlayerCharacterShyGuyPalette_from_thumb(u32 index) {
    return g_PlayerShyGuyPlts[index];
}
#pragma thumb off

#pragma thumb on
Ncgr *GetPlayerCharacterNceNcgr_from_thumb(int index) {
    return g_PlayerCharacterNceNcgrs[index];
}
#pragma thumb off

#pragma thumb on
NNSG2dCellDataBank *GetPlayerCharacterNceNcer_from_thumb(int index) {
    return g_PlayerCharacterNceNcers[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterBNCL_from_thumb(int index) {
    return g_PlayerCharacterBNCLs[index];
}
#pragma thumb off
