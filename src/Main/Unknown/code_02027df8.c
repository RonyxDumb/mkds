#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02161000.h"

#pragma thumb on

void func_02027df8(void) {
    void *fileData;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMap[0] = NULL;
    fileData = arc_get2dArcFile(aSelect_kart_s_b_ncgr);
    g2du_unpackCharacterDataBG(&chars, fileData);
    fileData = arc_get2dArcFile(aSelect_kart_s_nce_ncgr);
    g2du_unpackCharacterData(&chars, fileData);
    fileData = arc_get2dArcFile(aSelect_kart_s_nce_ncer);
    g2du_unpackCellBankData(&cells, fileData);
    fileData = arc_get2dArcFile(aSelect_kart_s_o_nclr);
    g2du_unpackPaletteData(&palette, fileData);
    fileData = arc_get2dArcFile(aSelect_kart_s_b_nclr);
    g2du_unpackPaletteData(&palette, fileData);
    fileData = arc_get2dArcFile(aSelect_kart_s_nscr);
    g2du_unpackScreenData(screenMap, fileData);
}

#pragma thumb off
