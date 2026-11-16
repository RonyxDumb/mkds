#include "card_enable_and_lock.h"
#include "reset_interrupts_halt.h"
#include "thread_scheduler.h"
#include "card_rom_backup_access.h"
#include "lock_word_and_bus_ownership.h"

CARDiCommon gAccessState;
CARDiCommandArg gRequestBlock;
u32 gAccessEnabled[8];

// Returns the enable flag.
u32 CARD_IsEnabled(void) {
    return gAccessEnabled[0];
}

// Ends in OS_Terminate unless card access is enabled.
void CARD_CheckEnabled(void) {
    if (CARD_IsEnabled() != 0) {
        return;
    }
    OS_Terminate();
}

// Sets the enable flag.
void CARD_Enable(u32 enable) {
    gAccessEnabled[0] = enable;
}

// Waits while a transfer is running. Returns 1 when CARDiCommandArg.mResult is 0.
int CARDi_WaitAsync(void) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &gAccessState;
    enabled = OS_DisableInterrupts();
    while (common->mFlag & ACCESS_FLAG_BUSY) {
        OS_SleepThread(&common->mBusyQ);
    }
    OS_RestoreInterrupts(enabled);
    return common->mCmd->mResult == ACCESS_RESULT_OK;
}

// Returns 1 when no transfer is running.
int CARDi_TryWaitAsync(void) {
    return (gAccessState.mFlag & ACCESS_FLAG_BUSY) == 0;
}

// Returns CARDiCommandArg.mResult of the last request, 0 when it succeeded.
u32 CARD_GetResultCode(void) {
    return gAccessState.mCmd->mResult;
}

void CARD_LockRom(u16 lockId) {
    CARDi_LockResource(lockId, 1);
    OS_LockCard(lockId);
}

// Calls OS_UnlockCard, then gives the ROM target back.
void CARD_UnlockRom(u16 lockId) {
    OS_UnlockCard(lockId);
    CARDi_UnlockResource(lockId, 1);
}

// Takes the backup target for the lock id.
void CARD_LockBackup(u16 lockId) {
    CARDi_LockResource(lockId, 2);
}

// Gives the backup target back.
void CARD_UnlockBackup(u16 lockId) {
    CARDi_UnlockResource(lockId, 2);
}
