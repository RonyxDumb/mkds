#pragma once

#include "types.h"

void CARDi_SendtoPxi(u32 data, s32 wait);
void CARD_TerminateForPulledOut(void);

u32 CARD_IsPulledOut(void);
void CARD_SetPulledOutCallback(void *callback);
void CARDi_PulledOutCallback(u32 tag, u32 data);
void CARD_InitPulledOutCallback(void);
