#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02162000.h"

#pragma thumb on

void LoadWiFiVSCourseSelectFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = arc_getSceneArcFile(aWifi_vs_course);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_0);
    g2du_unpackCharacterDataBG(&chars, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_1);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_2);
    g2du_unpackCharacterData(&chars, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_3);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_4);
    g2du_unpackCellBankData(&cells, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_5);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_6);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_7);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_8);
    g2du_unpackPaletteData(&palette, file);
    file = arc_getSceneArcFile(aWifi_vs_cour_9);
    g2du_unpackScreenData(screenMaps, file);
    file = arc_getSceneArcFile(aWifi_vs_cou_10);
    g2du_unpackScreenData(screenMaps, file);
}

#pragma thumb off
