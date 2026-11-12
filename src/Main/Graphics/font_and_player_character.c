#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/archive_slot_loaded.h"
#include "Main/MapObjects/data_0217b000.h"

struct Unk02021dc8 *gPlayerCharacterNcer[2];
struct Nclr *gPlayerCharacterNclr[2];
struct Nclr *gPlayerCharacterShyguyNclr[2];
struct Ncgr *gPlayerCharacterNcgr[2];
void *gPlayerCharacterBncl[2];
struct Unk02022aa8 gLCFontS;
struct Unk02022aa8 *gFontTable[3];
struct Unk02022aa8 gMarioFont;
struct Unk02022aa8 gLCFontM;

#pragma thumb on
#pragma optimize_for_size on
void LoadFontAndPlayerCharacterData(void) {
    if (IsArchiveSlotLoaded(1) != 0) {
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
#pragma thumb off

#pragma thumb on
Unk02022aa8 *GetFontByIndex(s32 index) {
    return gFontTable[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterNclr(int index) {
    return gPlayerCharacterNclr[index];
}
#pragma thumb off

#pragma thumb on
Nclr *GetPlayerCharacterShyguyNclr(u32 index) {
    return gPlayerCharacterShyguyNclr[index];
}
#pragma thumb off

#pragma thumb on
Ncgr *GetPlayerCharacterNcgr(int index) {
    return gPlayerCharacterNcgr[index];
}
#pragma thumb off

#pragma thumb on
Unk02021dc8 *GetPlayerCharacterNcer(int index) {
    return gPlayerCharacterNcer[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterBncl(int index) {
    return gPlayerCharacterBncl[index];
}
#pragma thumb off
