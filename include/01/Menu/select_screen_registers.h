#pragma once

#include "types.h"

void UpdateSelectKart(void);
void WriteSelectKartScreenRegisters(void);
void UpdateSelectCharacter(void);
void WriteSelectCharacterScreenRegisters(void);
void UpdateSelectEngine(void);
void WriteSelectEngineScreenRegisters(void);
void UpdateSelectCupM(void);
void WriteSelectCupMScreenRegisters(void);
void TimeAttackGXS_SetVisiblePlane(u32 bits);
void TimeAttackGX_SetVisiblePlane(u32 bits);
void UpdateSelectGhost(void);
void WriteSelectGhostScreenRegisters(void);
void WriteMainBg1CntFields(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase, u32 overflowMode);
void WriteMainBg1CntFlag(int enable);
