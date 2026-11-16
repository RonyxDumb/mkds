#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/unk_02162000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

// Unpacks the Chars, Cells, Palette and ScreenMap files of the ghost scene in place; nothing is kept.
void ghost_loadFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_b_ncgr_0);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_b_ncgr_0);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_b_ncgr_0);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_b_ncgr_0);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_nce_ncgr_1);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_nce_ncgr_1);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_nce_ncgr_0);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_nce_ncgr_0);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_nce_ncer_1);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_nce_ncer_1);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_nce_ncer_0);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_nce_ncer_0);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_b_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_o_nclr_1);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_b_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_o_nclr_1);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_b_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_b_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_o_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_o_nclr_0);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_m_nscr_0);
    g2du_unpackScreenData(screenMaps, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_get_s_nscr_0);
    g2du_unpackScreenData(screenMaps, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_m_nscr_0);
    g2du_unpackScreenData(screenMaps, file);
    file = arc_getSceneArcFile(aTimeattack_ghost_send_s_nscr_0);
    g2du_unpackScreenData(screenMaps, file);
    kic_unpackDataForGhost();
}

#pragma thumb off
