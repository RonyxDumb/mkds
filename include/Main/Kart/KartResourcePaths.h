#pragma once

#include "types.h"

char *cklcr_getTeamEmblemPath(s32 a);
char *cklcr_getCharacterEmblemPath(u16 a);
s8 *cklcr_getFaceAnimPath(void);
char *cklcr_getCharacterFolderPath(s32 a);
const char *cklcr_getCharacterModelName(s32 a, s32 b);
char *cklcr_getKartShadowPath(u16 a);
char *cklcr_getTireNsbtxPath(u16 a, const char *name);
char *cklcr_getTireNsbmdPath(u16 a, const char *name);
char *cklcr_getKartNsbtxPath(u16 a);
char *cklcr_getKartNsbmdPath(u16 a);
char *cklcr_getCharacterNsbtxPath(u16 a, s32 b);
char *cklcr_getCharacterNsbmdPath(u16 a, s32 b);
void cklcr_setLoadFromFolder(int value);
