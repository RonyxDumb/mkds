#pragma once

#include "types.h"

struct KartModelsEntry;

void StructAD00Sub_SomeFn_3(struct KartModelsEntry *kartModelsEntry);
s32 AdvanceKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, s32 blendAmount);
void StartKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor);
