#pragma once

#include "types.h"
#include "code_021458c4.h"

void CARD_UnlockBackup(u16 lockId);
void CARD_LockBackup(u16 lockId);
void CARD_UnlockRom(u16 lockId);
void CARD_LockRom(u16 lockId);

// Values CARD_GetResultCode returns.
typedef enum CardStatus {
    CARD_STATUS_OK = 0,
    CARD_STATUS_FAILED,
    CARD_STATUS_BAD_ARGUMENT,
    CARD_STATUS_NOT_SUPPORTED,
    CARD_STATUS_TIMED_OUT,
    CARD_STATUS_ERROR,
    CARD_STATUS_NO_REPLY,
    CARD_STATUS_CANCELED
} CardStatus;

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
extern u32 gAccessEnabled[];

// The 0x620-byte card state.
extern CARDiCommon gAccessState;
// The command block that CARDiCommon.mCmd points to.
extern CARDiCommandArg gRequestBlock;
