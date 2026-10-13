/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_DoUnlockByWord SDK_data_0200cea0
#define OSi_FreeCartridgeBus SDK_data_0200ce48
#define OS_UnlockCartridge Operation_CartArm9
#include "OS_spinLock.h"

#include "OS_system.h"
#include "mmap.h"
#include "MI_exMemory.h"
#include "code32.h"
extern s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp) (void),
                                        BOOL disableFIQ);
extern void OSi_FreeCartridgeBus(void);
s32 OS_UnlockCartridge(u16 lockID)
{
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_FreeCartridgeBus, TRUE);
}
