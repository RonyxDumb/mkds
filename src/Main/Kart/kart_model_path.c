#include "Main/Kart/kart_model_path.h"

#include "code_02134398.h"
#include "Main/MapObjects/data_02155000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/kart_ai_battle.h"

void SetKartModelPathPrefix(int value) {
    if (value) {
        gKartModelPathPrefix = "/data/KartModelMenu/";
    } else {
        gKartModelPathPrefix = gKartModelSlashPrefix;
    }
}

char *BuildCharacterNsbmdPath(u16 characterIndex, s32 usePNames) {
    const char *ext = "nsbmd";
    const char *name;
    if (usePNames != 0) {
        name = gCharacterPNames[characterIndex].mName;
    } else {
        name = gCharacterENames[characterIndex].mName;
    }
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName,
             gCharacterSubDirNames[characterIndex]);
    snprintf(gKartModelPathBuffer, 0x100, "%s%s.%s", gKartModelPathBuffer, name, ext);
    return gKartModelPathBuffer;
}

char *BuildCharacterNsbtxPath(u16 characterIndex, s32 usePNames) {
    const char *ext = "nsbtx";
    const char *name;
    if (usePNames != 0) {
        name = gCharacterPNames[characterIndex].mName;
    } else {
        name = gCharacterENames[characterIndex].mName;
    }
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName,
             gCharacterSubDirNames[characterIndex]);
    snprintf(gKartModelPathBuffer, 0x100, "%s%s.%s", gKartModelPathBuffer, name, ext);
    return gKartModelPathBuffer;
}

char *BuildKartNsbmdPath(u16 kartIndex) {
    const char *ext = "nsbmd";
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%skart_%s.%s", gKartModelPathPrefix, gKartDirName,
             kartIndex % 3 == 0 ? "mario/" : gCharacterSubDirNames[kartIndex / 3], gKartNames[kartIndex].mName, ext);
    return gKartModelPathBuffer;
}

char *BuildKartNsbtxPath(u16 kartIndex) {
    const char *ext = "nsbtx";
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%skart_%s.%s", gKartModelPathPrefix, gKartDirName,
             kartIndex % 3 == 0 ? "mario/" : gCharacterSubDirNames[kartIndex / 3], gKartNames[kartIndex].mName, ext);
    return gKartModelPathBuffer;
}

char *BuildTireNsbmdPath(u16 unusedValue, const char *name) {
    const char *ext = "nsbmd";
    snprintf(gKartModelPathBuffer, 0x100, "%s%stire/%s.%s", gKartModelPathPrefix, gKartDirName, name, ext);
    return gKartModelPathBuffer;
}

char *BuildTireNsbtxPath(u16 unusedValue, const char *name) {
    const char *ext = "nsbtx";
    snprintf(gKartModelPathBuffer, 0x100, "%s%stire/%s.%s", gKartModelPathPrefix, gKartDirName, name, ext);
    return gKartModelPathBuffer;
}

char *BuildKartShadowNsbmdPath(u16 kartIndex) {
    snprintf(gKartModelPathBuffer, 0x100, "%s%sshadow/sh_%s.nsbmd", gKartModelPathPrefix, gKartDirName,
             gKartShadowNames[kartIndex].mName);
    return gKartModelPathBuffer;
}

const char *LookupCharacterPOrEName(s32 characterIndex, s32 usePNames) {
    if (usePNames != 0) {
        return gCharacterPNames[characterIndex].mName;
    } else {
        return gCharacterENames[characterIndex].mName;
    }
}

char *BuildCharacterDirPath(s32 characterIndex) {
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName,
             gCharacterSubDirNames[characterIndex]);
    return gKartModelPathBuffer;
}

s8 *BuildPFaceanimNsbtpPath(void) {
    snprintf((char *) &gKartModelPathBuffer, 0x100, "%s%scommon/P_faceanim.nsbtp", *(u32 *) &gKartModelPathPrefix,
             *(u32 *) &gCharacterDirName);
    return (s8 *) &gKartModelPathBuffer;
}

char *BuildEmblemNsbtxPath(u16 characterIndex) {
    snprintf(gKartModelPathBuffer, 0x100, "%semblem/%s_emblem.nsbtx", gKartModelPathPrefix,
             gCharacterEmblemNames[characterIndex].mName);
    return gKartModelPathBuffer;
}

char *BuildTeamEmblemNsbtxPath(s32 teamIndex) {
    snprintf(gKartModelPathBuffer, 0x100, "%semblem/Team%s_emblem.nsbtx", gKartModelPathPrefix,
             gTeamEmblemNames[teamIndex == 0]);
    return gKartModelPathBuffer;
}
