#include "Main/Kart/KartResourcePaths.h"

#include "code_02134398.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void cklcr_setLoadFromFolder(int value) {
    if (value) {
        ckldr_sLoadBasePath = aDataKartmode_1;
    } else {
        ckldr_sLoadBasePath = gKartModelSlashPrefix;
    }
}

char *cklcr_getCharacterNsbmdPath(u16 a, s32 b) {
    const char *ext = "nsbmd";
    const char *name;
    if (b != 0) {
        name = cklcr_sCharDefs[a].mUnk_00;
    } else {
        name = gCharacterENames[a].mUnk_00;
    }
    snprintf(ckldr_sPathResult, 0x100, "%s%s%s", ckldr_sLoadBasePath, cklcr_sCharacterFolder, sCharFolderNames[a]);
    snprintf(ckldr_sPathResult, 0x100, "%s%s.%s", ckldr_sPathResult, name, ext);
    return ckldr_sPathResult;
}

char *cklcr_getCharacterNsbtxPath(u16 a, s32 b) {
    const char *ext = "nsbtx";
    const char *name;
    if (b != 0) {
        name = cklcr_sCharDefs[a].mUnk_00;
    } else {
        name = gCharacterENames[a].mUnk_00;
    }
    snprintf(ckldr_sPathResult, 0x100, "%s%s%s", ckldr_sLoadBasePath, cklcr_sCharacterFolder, sCharFolderNames[a]);
    snprintf(ckldr_sPathResult, 0x100, "%s%s.%s", ckldr_sPathResult, name, ext);
    return ckldr_sPathResult;
}

char *cklcr_getKartNsbmdPath(u16 a) {
    const char *ext = "nsbmd";
    snprintf(ckldr_sPathResult, 0x100, "%s%s%skart_%s.%s", ckldr_sLoadBasePath, cklcr_sKartFolder,
             a % 3 == 0 ? "mario/" : sCharFolderNames[a / 3], cklcr_sKartDefs[a].mUnk_00, ext);
    return ckldr_sPathResult;
}

char *cklcr_getKartNsbtxPath(u16 a) {
    const char *ext = "nsbtx";
    snprintf(ckldr_sPathResult, 0x100, "%s%s%skart_%s.%s", ckldr_sLoadBasePath, cklcr_sKartFolder,
             a % 3 == 0 ? "mario/" : sCharFolderNames[a / 3], cklcr_sKartDefs[a].mUnk_00, ext);
    return ckldr_sPathResult;
}

char *cklcr_getTireNsbmdPath(u16 a, const char *name) {
    const char *ext = "nsbmd";
    snprintf(ckldr_sPathResult, 0x100, "%s%stire/%s.%s", ckldr_sLoadBasePath, cklcr_sKartFolder, name, ext);
    return ckldr_sPathResult;
}

char *cklcr_getTireNsbtxPath(u16 a, const char *name) {
    const char *ext = "nsbtx";
    snprintf(ckldr_sPathResult, 0x100, "%s%stire/%s.%s", ckldr_sLoadBasePath, cklcr_sKartFolder, name, ext);
    return ckldr_sPathResult;
}

char *cklcr_getKartShadowPath(u16 a) {
    snprintf(ckldr_sPathResult, 0x100, "%s%sshadow/sh_%s.nsbmd", ckldr_sLoadBasePath, cklcr_sKartFolder,
             gKartShadowNames[a].mUnk_00);
    return ckldr_sPathResult;
}

const char *cklcr_getCharacterModelName(s32 a, s32 b) {
    if (b != 0) {
        return cklcr_sCharDefs[a].mUnk_00;
    } else {
        return gCharacterENames[a].mUnk_00;
    }
}

char *cklcr_getCharacterFolderPath(s32 a) {
    snprintf(ckldr_sPathResult, 0x100, "%s%s%s", ckldr_sLoadBasePath, cklcr_sCharacterFolder, sCharFolderNames[a]);
    return ckldr_sPathResult;
}

s8 *cklcr_getFaceAnimPath(void) {
    snprintf((char *) &ckldr_sPathResult, 0x100, aSScommonP_face, *(u32 *) &ckldr_sLoadBasePath,
             *(u32 *) &cklcr_sCharacterFolder);
    return (s8 *) &ckldr_sPathResult;
}

char *cklcr_getCharacterEmblemPath(u16 a) {
    snprintf(ckldr_sPathResult, 0x100, aSemblemS_emble, ckldr_sLoadBasePath, gCharacterEmblemNames[a].mUnk_00);
    return ckldr_sPathResult;
}

char *cklcr_getTeamEmblemPath(s32 a) {
    snprintf(ckldr_sPathResult, 0x100, aSemblemTeamS_e, ckldr_sLoadBasePath, sTeamNames[a == 0]);
    return ckldr_sPathResult;
}
