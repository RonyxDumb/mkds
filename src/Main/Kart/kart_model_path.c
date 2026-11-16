#include "Main/Kart/kart_model_path.h"

#include "print_memory_multibyte_write.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/kart_ai_battle.h"

char gCharacterEmblemNameHH[] = "HH";
char gCharacterEmblemNameKP[] = "KP";
char gCharacterEmblemNameYS[] = "YS";
char gCharacterEmblemNameLG[] = "LG";
char gCharacterEmblemNameKO[] = "KO";
char gCharacterEmblemNameMR[] = "MR";
char gCharacterEmblemNameWL[] = "WL";
char gCharacterEmblemNameRB[] = "RB";
char gCharacterEmblemNamePC[] = "PC";
char gCharacterEmblemNameKA[] = "KA";
char gCharacterEmblemNameDK[] = "DK";
char gCharacterEmblemNameDS[] = "DS";
char gCharacterEmblemNameWR[] = "WR";
char g_str_Red[] = "Red";
char gKartShadowNameWLC32[] = "WL_c";
char gKartNameMRA33[] = "MR_a";
char gCharacterNamePMR[] = "P_MR";
char gKartShadowNameDKC5[] = "DK_c";
char gKartNameKOB7[] = "KO_b";
char gCharacterNameEMR[] = "E_MR";
char gKartNameKPB10[] = "KP_b";
char gCharacterNamePDK[] = "P_DK";
char gCharacterNameEDK[] = "E_DK";
char gKartNameMRA6[] = "MR_a";
char gCharacterNamePKO[] = "P_KO";
char gKartNameMRA24[] = "MR_a";
char gCharacterNameEKO[] = "E_KO";
char gCharacterNamePKP[] = "P_KP";
char gCharacterNameEKP[] = "E_KP";
char gKartNameKOC8[] = "KO_c";
char gCharacterNamePPC[] = "P_PC";
char gCharacterNameEPC[] = "E_PC";
char gKartShadowNameMRA6[] = "MR_a";
char gCharacterNamePWR[] = "P_WR";
char gKartNamePCC14[] = "PC_c";
char gKartShadowNameKOB7[] = "KO_b";
char gCharacterNamePYS[] = "P_YS";
char gCharacterNameEYS[] = "E_YS";
char gKartNameWLC32[] = "WL_c";
char gCharacterNamePLG[] = "P_LG";
char gCharacterNameELG[] = "E_LG";
char gKartNameWRB16[] = "WR_b";
char gKartNameDSB28[] = "DS_b";
char gCharacterNameEKA[] = "E_KA";
char gKartNameMRA36[] = "MR_a";
char gCharacterNamePDS[] = "P_DS";
char gKartNameWRC17[] = "WR_c";
char gKartShadowNameWLB31[] = "WL_b";
char gCharacterNamePWL[] = "P_WL";
char gKartNameMRA18[] = "MR_a";
char gKartNameDSC29[] = "DS_c";
char gCharacterNamePRB[] = "P_RB";
char gCharacterNameERB[] = "E_RB";
char gKartShadowNameLGB22[] = "LG_b";
char gKartNameYSB19[] = "YS_b";
char gCharacterNameEHH[] = "E_HH";
char gKartNameDKC5[] = "DK_c";
char gKartNameMRA0[] = "MR_a";
char gKartNameMRA30[] = "MR_a";
char gKartShadowNameMRA0[] = "MR_a";
char gKartNameMRB1[] = "MR_b";
char gKartShadowNameMRB1[] = "MR_b";
char gKartNameMRA21[] = "MR_a";
char gKartShadowNameMRC2[] = "MR_c";
char gKartNameMRA3[] = "MR_a";
char gKartShadowNameMRA3[] = "MR_a";
char gKartNameDKB4[] = "DK_b";
char gKartNameWLB31[] = "WL_b";
char gKartShadowNameRBC35[] = "RB_c";
char gKartShadowNameDKB4[] = "DK_b";
char gKartNameYSC20[] = "YS_c";
char gKartNameLGC23[] = "LG_c";
char gCharacterNameEWL[] = "E_WL";
char gCharacterNamePKA[] = "P_KA";
char g_str_Blue[] = "Blue";
char gKartShadowNameKOC8[] = "KO_c";
char gKartShadowNameMRA36[] = "MR_a";
char gKartShadowNameMRA9[] = "MR_a";
char gKartNameKAB25[] = "KA_b";
char gKartShadowNameKPB10[] = "KP_b";
char gKartNameKPC11[] = "KP_c";
char gKartShadowNameKPC11[] = "KP_c";
char gKartNameMRA12[] = "MR_a";
char gKartShadowNameMRA12[] = "MR_a";
char gKartNamePCB13[] = "PC_b";
char gKartShadowNamePCB13[] = "PC_b";
char gKartNameMRA27[] = "MR_a";
char gKartShadowNamePCC14[] = "PC_c";
char gKartNameMRA15[] = "MR_a";
char gKartShadowNameMRA15[] = "MR_a";
char gKartNameRBB34[] = "RB_b";
char gKartShadowNameWRB16[] = "WR_b";
char gKartShadowNameDSB28[] = "DS_b";
char gKartShadowNameWRC17[] = "WR_c";
char gKartShadowNameRBB34[] = "RB_b";
char gKartShadowNameMRA18[] = "MR_a";
char gKartShadowNameDSC29[] = "DS_c";
char gKartShadowNameYSB19[] = "YS_b";
char gKartNameRBC35[] = "RB_c";
char gKartShadowNameYSC20[] = "YS_c";
char gKartShadowNameMRA30[] = "MR_a";
char gKartShadowNameMRA21[] = "MR_a";
char gKartNameLGB22[] = "LG_b";
char gKartNameMRC2[] = "MR_c";
char gCharacterNamePHH[] = "P_HH";
char gCharacterNameEDS[] = "E_DS";
char gCharacterNameEWR[] = "E_WR";
char gKartShadowNameMRA24[] = "MR_a";
char gKartNameMRA9[] = "MR_a";
char gKartShadowNameKAB25[] = "KA_b";
char gKartNameKAC26[] = "KA_c";
char gKartShadowNameKAC26[] = "KA_c";
char gKartShadowNameMRA33[] = "MR_a";
char gKartShadowNameMRA27[] = "MR_a";
char gKartShadowNameLGC23[] = "LG_c";
char gCharacterSubDirRobo[] = "robo/";
char g_str_kart[] = "kart/";
char gCharacterSubDirHeyho[] = "heyho/";
char gCharacterSubDirMario[] = "mario/";
char gCharacterSubDirKoopa[] = "koopa/";
char gCharacterSubDirPeach[] = "peach/";
char gCharacterSubDirWario[] = "wario/";
char gCharacterSubDirYoshi[] = "yoshi/";
char gCharacterSubDirLuigi[] = "luigi/";
char gCharacterSubDirKaron[] = "karon/";
char gCharacterSubDirDaisy[] = "daisy/";
const char *g_TeamNameTable[2] = {g_str_Red, g_str_Blue};
char gCharacterSubDirWaluigi[] = "waluigi/";
char gCharacterSubDirKinopio[] = "kinopio/";
char g_dir_character[] = "character/";

const CharacterNames gCharacterNames[13] = {
    {gCharacterNamePMR, gCharacterNameEMR, gCharacterEmblemNameMR},
    {gCharacterNamePDK, gCharacterNameEDK, gCharacterEmblemNameDK},
    {gCharacterNamePKO, gCharacterNameEKO, gCharacterEmblemNameKO},
    {gCharacterNamePKP, gCharacterNameEKP, gCharacterEmblemNameKP},
    {gCharacterNamePPC, gCharacterNameEPC, gCharacterEmblemNamePC},
    {gCharacterNamePWR, gCharacterNameEWR, gCharacterEmblemNameWR},
    {gCharacterNamePYS, gCharacterNameEYS, gCharacterEmblemNameYS},
    {gCharacterNamePLG, gCharacterNameELG, gCharacterEmblemNameLG},
    {gCharacterNamePKA, gCharacterNameEKA, gCharacterEmblemNameKA},
    {gCharacterNamePDS, gCharacterNameEDS, gCharacterEmblemNameDS},
    {gCharacterNamePWL, gCharacterNameEWL, gCharacterEmblemNameWL},
    {gCharacterNamePRB, gCharacterNameERB, gCharacterEmblemNameRB},
    {gCharacterNamePHH, gCharacterNameEHH, gCharacterEmblemNameHH},
};
const KartNames g_str_MR_a[37] = {
    {gKartNameMRA0, gKartShadowNameMRA0},
    {gKartNameMRB1, gKartShadowNameMRB1},
    {gKartNameMRC2, gKartShadowNameMRC2},
    {gKartNameMRA3, gKartShadowNameMRA3},
    {gKartNameDKB4, gKartShadowNameDKB4},
    {gKartNameDKC5, gKartShadowNameDKC5},
    {gKartNameMRA6, gKartShadowNameMRA6},
    {gKartNameKOB7, gKartShadowNameKOB7},
    {gKartNameKOC8, gKartShadowNameKOC8},
    {gKartNameMRA9, gKartShadowNameMRA9},
    {gKartNameKPB10, gKartShadowNameKPB10},
    {gKartNameKPC11, gKartShadowNameKPC11},
    {gKartNameMRA12, gKartShadowNameMRA12},
    {gKartNamePCB13, gKartShadowNamePCB13},
    {gKartNamePCC14, gKartShadowNamePCC14},
    {gKartNameMRA15, gKartShadowNameMRA15},
    {gKartNameWRB16, gKartShadowNameWRB16},
    {gKartNameWRC17, gKartShadowNameWRC17},
    {gKartNameMRA18, gKartShadowNameMRA18},
    {gKartNameYSB19, gKartShadowNameYSB19},
    {gKartNameYSC20, gKartShadowNameYSC20},
    {gKartNameMRA21, gKartShadowNameMRA21},
    {gKartNameLGB22, gKartShadowNameLGB22},
    {gKartNameLGC23, gKartShadowNameLGC23},
    {gKartNameMRA24, gKartShadowNameMRA24},
    {gKartNameKAB25, gKartShadowNameKAB25},
    {gKartNameKAC26, gKartShadowNameKAC26},
    {gKartNameMRA27, gKartShadowNameMRA27},
    {gKartNameDSB28, gKartShadowNameDSB28},
    {gKartNameDSC29, gKartShadowNameDSC29},
    {gKartNameMRA30, gKartShadowNameMRA30},
    {gKartNameWLB31, gKartShadowNameWLB31},
    {gKartNameWLC32, gKartShadowNameWLC32},
    {gKartNameMRA33, gKartShadowNameMRA33},
    {gKartNameRBB34, gKartShadowNameRBB34},
    {gKartNameRBC35, gKartShadowNameRBC35},
    {gKartNameMRA36, gKartShadowNameMRA36},
};
char gCharacterSubDirDonkey[] = "donkey/";
const char *g_str_characters[13] = {gCharacterSubDirMario, gCharacterSubDirDonkey,  gCharacterSubDirKinopio,
                                         gCharacterSubDirKoopa, gCharacterSubDirPeach,   gCharacterSubDirWario,
                                         gCharacterSubDirYoshi, gCharacterSubDirLuigi,   gCharacterSubDirKaron,
                                         gCharacterSubDirDaisy, gCharacterSubDirWaluigi, gCharacterSubDirRobo,
                                         gCharacterSubDirHeyho};
const char *gKartDirName = g_str_kart;
const char *gCharacterDirName = g_dir_character;

void SetCurrentlyInKartModelMenu(int value) {
    if (value) {
        g_KartModelMenuPathPrefix = "/data/KartModelMenu/";
    } else {
        g_KartModelMenuPathPrefix = g_str_Slash;
    }
}

char *FormatCharacterEmblemNsbmdPath(u16 characterIndex, s32 usePNames) {
    const char *ext = "nsbmd";
    const char *name;
    if (usePNames != 0) {
        name = gCharacterNames[characterIndex].mPName;
    } else {
        name = gCharacterNames[characterIndex].mEName;
    }
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s%s", g_KartModelMenuPathPrefix, gCharacterDirName,
             g_str_characters[characterIndex]);
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s.%s", g_FormatStringBuffer, name, ext);
    return g_FormatStringBuffer;
}

char *FormatCharacterEmblemNsbtxPath(u16 characterIndex, s32 usePNames) {
    const char *ext = "nsbtx";
    const char *name;
    if (usePNames != 0) {
        name = gCharacterNames[characterIndex].mPName;
    } else {
        name = gCharacterNames[characterIndex].mEName;
    }
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s%s", g_KartModelMenuPathPrefix, gCharacterDirName,
             g_str_characters[characterIndex]);
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s.%s", g_FormatStringBuffer, name, ext);
    return g_FormatStringBuffer;
}

char *FormatCharacterKartNsbmdPath(u16 kartIndex) {
    const char *ext = "nsbmd";
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s%skart_%s.%s", g_KartModelMenuPathPrefix, gKartDirName,
             kartIndex % 3 == 0 ? "mario/" : g_str_characters[kartIndex / 3], g_str_MR_a[kartIndex].mName, ext);
    return g_FormatStringBuffer;
}

char *FormatCharacterKartNsbtxPath(u16 kartIndex) {
    const char *ext = "nsbtx";
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s%skart_%s.%s", g_KartModelMenuPathPrefix, gKartDirName,
             kartIndex % 3 == 0 ? "mario/" : g_str_characters[kartIndex / 3], g_str_MR_a[kartIndex].mName, ext);
    return g_FormatStringBuffer;
}

char *FormatKartTireNsbmdPath(u16 unusedValue, const char *name) {
    const char *ext = "nsbmd";
    _snprintf(g_FormatStringBuffer, 0x100, "%s%stire/%s.%s", g_KartModelMenuPathPrefix, gKartDirName, name, ext);
    return g_FormatStringBuffer;
}

char *FormatKartTireNsbtxPath(u16 unusedValue, const char *name) {
    const char *ext = "nsbtx";
    _snprintf(g_FormatStringBuffer, 0x100, "%s%stire/%s.%s", g_KartModelMenuPathPrefix, gKartDirName, name, ext);
    return g_FormatStringBuffer;
}

char *FormatKartShadowNsbmdPath(u16 kartIndex) {
    _snprintf(g_FormatStringBuffer, 0x100, "%s%sshadow/sh_%s.nsbmd", g_KartModelMenuPathPrefix, gKartDirName,
             g_str_MR_a[kartIndex].mShadowName);
    return g_FormatStringBuffer;
}

const char *FormatCharacterEmblemName(s32 characterIndex, s32 usePNames) {
    if (usePNames != 0) {
        return gCharacterNames[characterIndex].mPName;
    } else {
        return gCharacterNames[characterIndex].mEName;
    }
}

char *FormatCharacterPath(s32 characterIndex) {
    _snprintf(g_FormatStringBuffer, 0x100, "%s%s%s", g_KartModelMenuPathPrefix, gCharacterDirName,
             g_str_characters[characterIndex]);
    return g_FormatStringBuffer;
}

s8 *FormatCharacterFaceAnimationNsbtpPath(void) {
    _snprintf(g_FormatStringBuffer, 0x100, "%s%scommon/P_faceanim.nsbtp", g_KartModelMenuPathPrefix, gCharacterDirName);
    return (s8 *) g_FormatStringBuffer;
}

char *FormatEmblemNsbtx(u16 characterIndex) {
    _snprintf(g_FormatStringBuffer, 0x100, "%semblem/%s_emblem.nsbtx", g_KartModelMenuPathPrefix,
             gCharacterNames[characterIndex].mEmblemName);
    return g_FormatStringBuffer;
}

char *FormatTeamEmblemNsbtx(s32 teamIndex) {
    _snprintf(g_FormatStringBuffer, 0x100, "%semblem/Team%s_emblem.nsbtx", g_KartModelMenuPathPrefix,
             g_TeamNameTable[teamIndex == 0]);
    return g_FormatStringBuffer;
}

const char *g_KartModelMenuPathPrefix;
char g_FormatStringBuffer[256];
