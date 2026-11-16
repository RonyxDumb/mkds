#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void m2d_load(void) {
    if (m2d_arc_isArchiveLoaded(1) != 0) {
        m2d_initFont(&gLCFontS, arc_get2dArcFile("LC_Font_s.NFTR"));
        m2d_initFont(&gLCFontM, arc_get2dArcFile("LC_Font_m.NFTR"));
        m2d_initFont(&gMarioFont, arc_get2dArcFile("marioFont.NFTR"));
        FontArray[0] = &gLCFontS;
        FontArray[1] = &gLCFontM;
        FontArray[2] = &gMarioFont;
        g2du_unpackPaletteData(gPlayerCharacterNclr, arc_get2dArcFile("player_character_M_o.NCLR"));
        g2du_unpackPaletteData(gPlayerCharacterShyguyNclr, arc_get2dArcFile("player_character_M_shyguy_o.NCLR"));
        g2du_unpackCharacterData(gPlayerCharacterNcgr, arc_get2dArcFile("player_character_M.nce.ncgr"));
        g2du_unpackCellBankData(gPlayerCharacterNcer, arc_get2dArcFile("player_character_M.nce.ncer"));
        gPlayerCharacterBncl[0] = arc_get2dArcFile("player_character_M.bncl");
        g2du_unpackPaletteData(&gPlayerCharacterLNclr, arc_get2dArcFile("player_character_L_o.NCLR"));
        g2du_unpackPaletteData(&gPlayerCharacterLShyguyNclr, arc_get2dArcFile("player_character_L_shyguy_o.NCLR"));
        g2du_unpackCharacterData(&gPlayerCharacterLNcgr, arc_get2dArcFile("player_character_L.nce.ncgr"));
        g2du_unpackCellBankData(&gPlayerCharacterLNcer, arc_get2dArcFile("player_character_L.nce.ncer"));
        gPlayerCharacterBncl[1] = arc_get2dArcFile("player_character_L.bncl");
    }
}

void m2d_unload(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        FontArray[i] = NULL;
    }
    for (j = 0; j < 2; j++) {
        gPlayerCharacterNclr[j] = NULL;
        gPlayerCharacterShyguyNclr[j] = NULL;
        gPlayerCharacterNcgr[j] = NULL;
        gPlayerCharacterNcer[j] = NULL;
        gPlayerCharacterBncl[j] = NULL;
    }
}
#pragma thumb off
