#pragma once

#include "types.h"

char *BuildTeamEmblemNsbtxPath(s32 teamIndex);
char *BuildEmblemNsbtxPath(u16 characterIndex);
s8 *BuildPFaceanimNsbtpPath(void);
char *BuildCharacterDirPath(s32 characterIndex);
const char *LookupCharacterPOrEName(s32 characterIndex, s32 usePNames);
char *BuildKartShadowNsbmdPath(u16 kartIndex);
char *BuildTireNsbtxPath(u16 unusedValue, const char *name);
char *BuildTireNsbmdPath(u16 unusedValue, const char *name);
char *BuildKartNsbtxPath(u16 kartIndex);
char *BuildKartNsbmdPath(u16 kartIndex);
char *BuildCharacterNsbtxPath(u16 characterIndex, s32 usePNames);
char *BuildCharacterNsbmdPath(u16 characterIndex, s32 usePNames);
void SetKartModelPathPrefix(int value);
