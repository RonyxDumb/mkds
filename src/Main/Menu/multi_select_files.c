#include "Main/Menu/multi_select_files.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
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
    file = FindSceneFile(gMultiSelectMemberSBNcgrName);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(gMultiSelectMemberMNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gMultiSelectMemberGroupSNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gMultiSelectMemberRegisterSNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gMultiSelectNSSNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gMultiSelectMemberMNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gMultiSelectMemberGroupSNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gMultiSelectMemberRegisterSNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gMultiSelectNSSNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gMultiSelectMemberMONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gMultiSelectMemberSBNclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gMultiSelectMemberGroupSONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gMultiSelectMemberRegisterSONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gMultiSelectNSSONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gMultiSelectMemberSRegisterNscrName);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(gMultiSelectMemberSGroupNscrName);
    LoadNscrData(screenMaps, file);
}

#pragma thumb off
