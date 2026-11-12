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
