/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts_IrqAndFiq Os_DisableIrqFiq
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts_IrqAndFiq Os_RestoreIrqFiq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_DoUnlockByWord Os_Lock_UnlockImpl
#include "OS_spinLock.h"

#include "OS_system.h"
#include "mmap.h"
#include "MI_exMemory.h"
#include "code32.h"

s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp) (void),
                                        BOOL disableFIQ)
{
    if (lockID != lockp->ownerID)
    {
        return -2;
    }

    OSIntrMode lastIntrMode = (disableFIQ) ? OS_DisableInterrupts_IrqAndFiq() : OS_DisableInterrupts();
    lockp->ownerID = 0;
    if (ctrlFuncp)
    {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;
    if (disableFIQ)
    {
        (void)OS_RestoreInterrupts_IrqAndFiq(lastIntrMode);
    }
    else
    {
        (void)OS_RestoreInterrupts(lastIntrMode);
    }
    return 0;
}
