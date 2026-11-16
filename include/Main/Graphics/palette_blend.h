#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void RunWhenStaffRollCount(void);
void LoadStaffRollStuff(void *heap);
void StartPaletteBlend(void);
void StopPaletteBlend(void);
void ResetPaletteBlendCycle(void);
void AdvancePaletteBlend(void);
void BlendPaletteColors(s32 weight);
void ClearPaletteBlendPointer(void);

void FormatSomeStaffRollBmgString(void);
void AdvanceStaffRollText(void);
void SetStaffRollScrollAndDrainQueue(void);

void ResetStaffRollStuffObject(void);

typedef struct Nclr Nclr;

void InitPaletteBlend(void *heap, Nclr *nclr, u32 paletteIndex);

extern struct PaletteBlend *gPaletteBlend;
extern struct StaffRollText *g_GlobalSTF;
