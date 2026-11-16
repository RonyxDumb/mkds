#pragma once

#include "types.h"

void AdvanceSelectReturnState1(void);
void AdvanceSelectReturnState0(void);
void SetSelectReturnPaletteBits(s32 paletteKind);
s32 gmenu_loadSelectReturn(s32 subCharOffset);
void gmenu_setupHWForSelectReturn(void);
