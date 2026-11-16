#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

void LoadMultiSelectFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = arc_getSceneArcFile(aMulti_select_m);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aMulti_select_0);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aMulti_select_1);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aMulti_select_2);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aMulti_select_n);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aMulti_select_3);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aMulti_select_4);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aMulti_select_5);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aMulti_select_6);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aMulti_select_7);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aMulti_select_8);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aMulti_select_9);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aMulti_selec_10);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aMulti_selec_11);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aMulti_selec_12);
    g2du_unpackScreenData(screenMaps, file);
    file = arc_getSceneArcFile(aMulti_selec_13);
    g2du_unpackScreenData(screenMaps, file);
}

#pragma thumb off
