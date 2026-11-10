#pragma once

#include "types.h"

s32 FX_MulFunc(s32 v1, s32 v2);
void FX_Init(void);
void GXx_SetMasterBrightness_(vu16 *reg, s32 brightness);
void GXS_SetGraphicsMode(u32 bgMode);
