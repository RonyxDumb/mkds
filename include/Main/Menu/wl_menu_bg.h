#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // DisplaySettings

void WLMenuSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void WLMenuSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                            u32 cntVal8, u32 cntVal2, u32 cntVal13);
void WLMenuMI_CpuClearFast(void *dest, u32 size);
void WLMenuMI_CpuFillFast(void *dest, u32 fillValue, u32 size);
