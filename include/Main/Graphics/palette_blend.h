#pragma once

#include "types.h"

void StartStaffRollText(void);
void InitStaffRollText(void *heap);
void StartPaletteBlend(void);
void StopPaletteBlend(void);
void ResetPaletteBlendCycle(void);
void AdvancePaletteBlend(void);
void BlendPaletteColors(s32 weight);
void ClearPaletteBlendPointer(void);
