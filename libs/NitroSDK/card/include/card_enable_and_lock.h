#pragma once

#include "types.h"
#include "card_rom_backup_access.h"

void CARD_UnlockBackup(u16 lockId);
void CARD_LockBackup(u16 lockId);
void CARD_UnlockRom(u16 lockId);
void CARD_LockRom(u16 lockId);

// Values CARD_GetResultCode returns.
typedef enum CARDResult {
    BACKUP_RESULT_OK = 0,
    BACKUP_RESULT_FAILED,
    BACKUP_RESULT_BAD_ARGUMENT,
    BACKUP_RESULT_NOT_SUPPORTED,
    BACKUP_RESULT_TIMED_OUT,
    BACKUP_RESULT_ERROR,
    BACKUP_RESULT_NO_REPLY,
    BACKUP_RESULT_CANCELED
} CARDResult;

u32 CARD_GetResultCode(void);
int CARDi_TryWaitAsync(void);
int CARDi_WaitAsync(void);
void CARD_Enable(u32 enable);

// Returns when the enable flag is not 0, otherwise calls OS_Terminate.
void CARD_CheckEnabled(void);

// Returns the enable flag.
u32 CARD_IsEnabled(void);

typedef struct CARDiCommon CARDiCommon;

// Word 0 is the enable flag: CARD_Enable stores it, CARD_IsEnabled returns it. The other seven words are not used.
extern u32 gAccessEnabled[];

// The 0x620-byte card state.
extern CARDiCommon gAccessState;
// The command block that CARDiCommon.mCmd points to.
extern CARDiCommandArg gRequestBlock;
