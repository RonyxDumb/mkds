/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OsCountZeroBits Os_CountLeadingZeroBits
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_vramExclusive SDK_data_02170284
#define OSi_vramLockId SDK_data_02170288
#define OSi_TryLockVram func_0200ff04
#include "OS_vramExclusive.h"
#include "OS_system.h"
#include "code32.h"
extern u32 OSi_vramExclusive;
extern u16 OSi_vramLockId[9];
BOOL OSi_TryLockVram(u16 bank, u16 lockId)
{
    u32 workMap;
    s32 zeroBits;
    OSIntrMode enabled = OS_DisableInterrupts();

    workMap = (u32)(bank & OSi_vramExclusive);
    while (TRUE)
    {
        zeroBits = (s32)(31 - OsCountZeroBits(workMap));
        if (zeroBits < 0)
        {
            break;
        }
        workMap &= ~(0x00000001 << zeroBits);
        if (OSi_vramLockId[zeroBits] != lockId)
        {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        }
    }

    workMap = (u32)(bank & 0x01ff);
    while (TRUE)
    {
        zeroBits = (s32)(31 - OsCountZeroBits(workMap));
        if (zeroBits < 0)
        {
            break;
        }
        workMap &= ~(0x00000001 << zeroBits);
        OSi_vramLockId[zeroBits] = lockId;
        OSi_vramExclusive |= (0x00000001 << zeroBits);
    }

    (void)OS_RestoreInterrupts(enabled);
    return TRUE;
}
