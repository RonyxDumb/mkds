#pragma once

#include "types.h"

typedef u32 (*CARDPulledOutCallback)(void);

void Card_SendToFifo(u32 data, s32 wait);
void Card_TerminateForPulledOut(void);

u32 Card_IsPulledOut(void);
void Card_SetUserCardPulledOutCallback(CARDPulledOutCallback callback);
void Card_CardPulledOutHandler(u32 tag, u32 data);
void Card_InitializePulledOutCallback(void);

// Set to 1 by Card_CardPulledOutHandler; Card_IsPulledOut returns it.
extern u32 g_Card_IsPulledOut;

// The hook set by Card_SetUserCardPulledOutCallback, cleared by Card_InitializePulledOutCallback and called by
// Card_CardPulledOutHandler.
extern CARDPulledOutCallback g_Card_UserCardPulledOutCallback;
