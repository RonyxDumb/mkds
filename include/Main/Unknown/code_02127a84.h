#pragma once

#include "types.h"

s32 LoadSelectChoises(s32 subCharOffset);
void RefreshSelectChoisesNscrCopy(void);
void RefreshSelectChoisesPaletteBits(void);
void RefreshAndQueueSelectChoises(void);
void RefreshSelectChoisesPaletteNoIndex(void);
void AdvanceSelectChoisesState0(void);
void AdvanceSelectChoisesState1(void);
