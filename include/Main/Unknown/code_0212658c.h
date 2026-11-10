#pragma once

#include "types.h"

void SetupTxtSystemMainTextEx(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                              s32 mainAnim, s32 subAnim);
void SetupTxtSystemMainTextShort(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex,
                                 u32 closeToIndex, u32 mainAnim, u32 subAnim);
