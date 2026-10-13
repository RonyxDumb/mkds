/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_DoUnlockByWord SDK_data_0200cf30
#define OS_UnlockByWord Os_Lock_Unlock
#include "OS_spinLock.h"

#include "OS_system.h"
#include "mmap.h"
#include "MI_exMemory.h"
#include "code32.h"
extern s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp) (void),
                                        BOOL disableFIQ);
s32 OS_UnlockByWord(u16 lockID, OSLockWord* lockp, void (*ctrlFuncp) (void))
{
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, FALSE);
}
