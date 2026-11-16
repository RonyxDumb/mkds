#pragma once

#include "types.h"
#include "card_rom_backup_access.h"

void Card_UnlockBackupResource(u16 lockId);
void Card_LockBackupResource(u16 lockId);
void Card_UnlockRomResource(u16 lockId);
void Card_LockRomResource(u16 lockId);

// Values Card_GetResult returns.
typedef enum CardStatus {
    BACKUP_RESULT_OK = 0,
    BACKUP_RESULT_FAILED,
    BACKUP_RESULT_BAD_ARGUMENT,
    BACKUP_RESULT_NOT_SUPPORTED,
    BACKUP_RESULT_TIMED_OUT,
    BACKUP_RESULT_ERROR,
    BACKUP_RESULT_NO_REPLY,
    BACKUP_RESULT_CANCELED
} CardStatus;

u32 Card_GetResult(void);
int Card_IsNotBusy(void);
int WaitForPendingCardOperation(void);
void Card_SetEnabled(u32 enable);

// Returns when the enable flag is not 0, otherwise calls Os_Terminate.
void EnsureCardEnabled(void);

// Returns the enable flag.
u32 Card_IsEnabled(void);

typedef struct CARDiCommon CARDiCommon;

// The enable flag: Card_SetEnabled stores it, Card_IsEnabled returns it.
extern u32 g_Card_Enabled[];

// The 0x620-byte card state.
extern CARDiCommon g_Card_Context;
// The command block that CARDiCommon.mCmd points to.
extern CARDiCommandArg g_Card_Command;
