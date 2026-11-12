#pragma once

#include "types.h"

void CARD_UnlockBackup(u16 lockId);
void CARD_LockBackup(u16 lockId);
void CARD_UnlockRom(u16 lockId);
void CARD_LockRom(u16 lockId);

u32 CARD_GetResultCode(void);
int CARDi_TryWaitAsync(void);
int CARDi_WaitAsync(void);
void CARD_Enable(u32 enable);

// Returns when the enable flag is not 0, otherwise calls OS_Terminate.
void CARD_CheckEnabled(void);

// Returns the enable flag.
u32 CARD_IsEnabled(void);

typedef struct CARDiCommon CARDiCommon;

// The enable flag: CARD_Enable stores it, CARD_IsEnabled returns it.
extern u8 gAccessEnabled[];
// The 0x620-byte card state.
extern CARDiCommon gAccessState;
