#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void StartStaffRollText(void);
void InitStaffRollText(void *heap);
void StartPaletteBlend(void);
void StopPaletteBlend(void);
void ResetPaletteBlendCycle(void);
void AdvancePaletteBlend(void);
void BlendPaletteColors(s32 weight);
void ClearPaletteBlendPointer(void);

void AdvanceStaffRollTextState1(void);
void AdvanceStaffRollText(void);
void SetStaffRollScrollAndDrainQueue(void);

void ClearStaffRollTextPointer(void);

typedef struct Nclr Nclr;

void InitPaletteBlend(void *heap, Nclr *nclr, u32 paletteIndex);

extern struct PaletteBlend *gPaletteBlend;
extern struct StaffRollText *gStaffRollText;
