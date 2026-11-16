#pragma once

#include "types.h"

typedef u32 (*CARDPulledOutCallback)(void);

void CARDi_SendtoPxi(u32 data, s32 wait);
void CARD_TerminateForPulledOut(void);

u32 CARD_IsPulledOut(void);
void CARD_SetPulledOutCallback(CARDPulledOutCallback callback);
void CARDi_PulledOutCallback(u32 tag, u32 data);
void CARD_InitPulledOutCallback(void);

// Set to 1 by CARDi_PulledOutCallback on the pulled-out command and never cleared; CARD_IsPulledOut returns it.
extern u32 gRemovalSeen;

// The callback set by CARD_SetPulledOutCallback and cleared by CARD_InitPulledOutCallback; CARDi_PulledOutCallback
// calls it when set and ends the program when it is not set or returns non-zero.
extern CARDPulledOutCallback gRemovalCallback;
