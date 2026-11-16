#pragma once

#include "types.h"
#include "reset_interrupts_halt.h"

s32 CreateRaceHudSubScreenRainStarCells(void);
void UpdateVsSelectCupM(void);

void WriteVsSelectCupMRegisters(void);

void VsSelectGXS_SetVisiblePlane(int bits);
void VsSelectGX_SetVisiblePlane(int bits);

BOOL VsSelectCupMB_IsMultiBootChildWrapper(void);
BOOL VsSelectCupMB_IsMultiBootChild(void);
BootInfo *GetBootIndicatorPointer_2(void);
void UpdateVsSelectCupCourse(void);

void WriteVsSelectCupCourseRegisters(void);

void UpdateVsSelectCupGrid(void);

void VsSelectCupSetRaceSetupRequested(unsigned int requested);
void VsSelectCupSetMenuEntryKind(unsigned int entryKind);
unsigned int VsSelectCupGetConnectionKind(void);

void WriteVsSelectCupGridRegisters(void);

void UpdateVsSelectRaceRule(void);

void WriteVsSelectRaceRuleRegisters(void);

void UpdateVsSelectKart(void);

void WriteVsSelectKartRegisters(void);

void UpdateVsSelectCharacter(void);

void WriteVsSelectCharacterRegisters(void);
