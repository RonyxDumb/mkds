#pragma once

#include "types.h"

void UpdateSelectKart(void);
void WriteSelectKartScreenRegisters(void);
void UpdateSelectCharacter(void);
void WriteSelectCharacterScreenRegisters(void);
void UpdateSelectEngine(void);
void func_ov001_021855f8(void);
void UpdateSelectCupM(void);
void func_ov001_02185658(void);
void TimeAttackGXS_SetVisiblePlane(u32 bits);
void TimeAttackGX_SetVisiblePlane(u32 bits);
void UpdateSelectGhost(void);
void WriteSelectGhostScreenRegisters(void);
void func_ov001_02185740(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_ov001_02185778(int enable);
