#pragma once

#include "types.h"
#include "01/code_021804e0.h" // Unk02180774

void title_GXS_SetOBJVRamModeChar(u32 bits);
void title_GX_SetOBJVRamModeChar(u32 bits);
void title_dc_setSubBg3Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2);
void title_dc_setMainBg3Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2);
void title_dc_setMainBg2Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2);
void title_dc_setMainBg1Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                   u32 cntVal2, u32 cntVal13);
