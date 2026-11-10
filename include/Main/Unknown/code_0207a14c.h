#pragma once

#include "types.h"
#include "code_02012b30.h" // NNSG3dResMdl

extern s32 gMinKartDistanceSquaredPresent;
extern s32 gMinKartDistanceSquared;

void SetKartModelMaterialColors(NNSG3dResMdl *mdl, u32 colorSet);
BOOL IsEntryKartNormalOrNotMissionRun(void);
BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared);
