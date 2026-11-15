#pragma once

#include "types.h"
#include "03/Menu/wifi_menu_shared.h"

void DeleteOamRange(OamRange *range);
OamRange *CreateOamRange(u32 screen, s32 entryCount, s32 fromFront);
void ReleaseOamRanges(void);
void InitOamRanges(void);
OamRange *CreateOamRangeFromNceImage(u32 screen, u32 imageIndex, s32 fromFront);
