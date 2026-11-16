#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/archive_slot_loaded.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

struct NNSG2dCellDataBank *gPlayerCharacterNcer[2];
struct Nclr *gPlayerCharacterNclr[2];
struct Nclr *gPlayerCharacterShyguyNclr[2];
struct Ncgr *gPlayerCharacterNcgr[2];
void *gPlayerCharacterBncl[2];
struct NNSG2dFont gLCFontS;
struct NNSG2dFont *gFontTable[3];
struct NNSG2dFont gMarioFont;
struct NNSG2dFont gLCFontM;

#pragma thumb on
#pragma optimize_for_size on
void LoadFontAndPlayerCharacterData(void) {
    if (IsArchiveSlotLoaded(ARCHIVE_SLOT_MAIN_2D) != 0) {
        InitFontIfLoaded(&gLCFontS, FindFileInLoadedArchives("LC_Font_s.NFTR"));
        InitFontIfLoaded(&gLCFontM, FindFileInLoadedArchives("LC_Font_m.NFTR"));
        InitFontIfLoaded(&gMarioFont, FindFileInLoadedArchives("marioFont.NFTR"));
        gFontTable[0] = &gLCFontS;
        gFontTable[1] = &gLCFontM;
        gFontTable[2] = &gMarioFont;
        LoadNclrData(gPlayerCharacterNclr, FindFileInLoadedArchives("player_character_M_o.NCLR"));
        LoadNclrData(gPlayerCharacterShyguyNclr, FindFileInLoadedArchives("player_character_M_shyguy_o.NCLR"));
        LoadNcgrData2(gPlayerCharacterNcgr, FindFileInLoadedArchives("player_character_M.nce.ncgr"));
        LoadNcerData(gPlayerCharacterNcer, FindFileInLoadedArchives("player_character_M.nce.ncer"));
        gPlayerCharacterBncl[0] = FindFileInLoadedArchives("player_character_M.bncl");
        LoadNclrData(&gPlayerCharacterNclr[1], FindFileInLoadedArchives("player_character_L_o.NCLR"));
        LoadNclrData(&gPlayerCharacterShyguyNclr[1], FindFileInLoadedArchives("player_character_L_shyguy_o.NCLR"));
        LoadNcgrData2(&gPlayerCharacterNcgr[1], FindFileInLoadedArchives("player_character_L.nce.ncgr"));
        LoadNcerData(&gPlayerCharacterNcer[1], FindFileInLoadedArchives("player_character_L.nce.ncer"));
        gPlayerCharacterBncl[1] = FindFileInLoadedArchives("player_character_L.bncl");
    }
}

void ClearFontAndPlayerCharacterTables(void) {
    s32 fontIndex;
    s32 characterSetIndex;

    for (fontIndex = 0; fontIndex < 3; fontIndex++) {
        gFontTable[fontIndex] = NULL;
    }
    for (characterSetIndex = 0; characterSetIndex < 2; characterSetIndex++) {
        gPlayerCharacterNclr[characterSetIndex] = NULL;
        gPlayerCharacterShyguyNclr[characterSetIndex] = NULL;
        gPlayerCharacterNcgr[characterSetIndex] = NULL;
        gPlayerCharacterNcer[characterSetIndex] = NULL;
        gPlayerCharacterBncl[characterSetIndex] = NULL;
    }
}

NNSG2dFont *GetFontByIndex(s32 index) {
    return gFontTable[index];
}

void *GetPlayerCharacterNclr(int index) {
    return gPlayerCharacterNclr[index];
}

Nclr *GetPlayerCharacterShyguyNclr(u32 index) {
    return gPlayerCharacterShyguyNclr[index];
}

Ncgr *GetPlayerCharacterNcgr(int index) {
    return gPlayerCharacterNcgr[index];
}

NNSG2dCellDataBank *GetPlayerCharacterNcer(int index) {
    return gPlayerCharacterNcer[index];
}

void *GetPlayerCharacterBncl(int index) {
    return gPlayerCharacterBncl[index];
}
#pragma thumb off
