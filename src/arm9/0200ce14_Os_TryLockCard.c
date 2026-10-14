/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_UnlockByWord SDK_data_0200cfc0
#define OSi_FreeCardBus SDK_data_0200cde0
#define OS_UnlockCard Os_TryLockCard
#include "OS_spinLock.h"

#include "OS_system.h"
#include "mmap.h"
#include "MI_exMemory.h"
#include "code32.h"
extern s32 OS_UnlockByWord(u16 lockID, OSLockWord* lockp, void (*ctrlFuncp) (void));
extern void OSi_FreeCardBus(void);
s32 OS_UnlockCard(u16 lockID)
{
    return OS_UnlockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_FreeCardBus);
}
