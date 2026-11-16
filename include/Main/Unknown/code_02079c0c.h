#pragma once

#include "types.h"

struct KartModelsEntry;

void chkrt_applyKartCrsMat(struct KartModelsEntry *kartModelsEntry);
s32 chkrt_progressColorInterpolation(struct KartModelsEntry *kartModelsEntry, s32 blendAmount);
void chkrt_setTargetColors(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor);
