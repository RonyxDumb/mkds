#include "Main/Menu/multi_select_files.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/data_02163000.h"


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
    file = FindSceneFile("multi_select_member_s_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("multi_select_member_m.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("multi_select_member_group_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("multi_select_member_register_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("multi_select_NS_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("multi_select_member_m.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("multi_select_member_group_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("multi_select_member_register_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("multi_select_NS_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("multi_select_member_m_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("multi_select_member_s_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("multi_select_member_group_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("multi_select_member_register_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("multi_select_NS_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("multi_select_member_s_register.NSCR");
    LoadNscrData(screenMaps, file);
    file = FindSceneFile("multi_select_member_s_group.NSCR");
    LoadNscrData(screenMaps, file);
}

#pragma thumb off
