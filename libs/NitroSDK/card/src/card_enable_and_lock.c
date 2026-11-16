#include "card_enable_and_lock.h"
#include "reset_interrupts_halt.h"
#include "thread_scheduler.h"
#include "card_rom_backup_access.h"
#include "lock_word_and_bus_ownership.h"

CARDiCommon g_Card_Context;
CARDiCommandArg g_Card_Command;
u32 g_Card_Enabled[8];

// Returns the enable flag.
u32 Card_IsEnabled(void) {
    return g_Card_Enabled[0];
}

// Ends in Os_Terminate unless card access is enabled.
void EnsureCardEnabled(void) {
    if (Card_IsEnabled() != 0) {
        return;
    }
    Os_Terminate();
}

// Sets the enable flag.
void Card_SetEnabled(u32 enable) {
    g_Card_Enabled[0] = enable;
}

// Waits while a transfer is running. Returns 1 when CARDiCommandArg.mResult is 0.
int WaitForPendingCardOperation(void) {
    CARDiCommon *common;
    u32 enabled;

    common = (CARDiCommon *) (u32) &g_Card_Context;
    enabled = Os_DisableIrq();
    while (common->mFlag & BACKUP_ACCESS_FLAG_BUSY) {
        Os_Thread_Sleep(&common->mBusyQ);
    }
    Os_RestoreIrq(enabled);
    return common->mCmd->mResult == ROM_ACCESS_SUCCEEDED;
}

// Returns 1 when no transfer is running.
int Card_IsNotBusy(void) {
    return (g_Card_Context.mFlag & BACKUP_ACCESS_FLAG_BUSY) == 0;
}

// Returns CARDiCommandArg.mResult of the last request, 0 when it succeeded.
u32 Card_GetResult(void) {
    return g_Card_Context.mCmd->mResult;
}

void Card_LockRomResource(u16 lockId) {
    Card_LockResource(lockId, 1);
    Os_TryLockCard(lockId);
}

// Calls Os_UnlockCard, then gives the ROM target back.
void Card_UnlockRomResource(u16 lockId) {
    Os_UnlockCard(lockId);
    Card_UnlockResource(lockId, 1);
}

// Takes the backup target for the lock id.
void Card_LockBackupResource(u16 lockId) {
    Card_LockResource(lockId, 2);
}

// Gives the backup target back.
void Card_UnlockBackupResource(u16 lockId) {
    Card_UnlockResource(lockId, 2);
}
