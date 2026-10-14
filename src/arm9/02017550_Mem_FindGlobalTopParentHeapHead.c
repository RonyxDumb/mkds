/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PMi_DeleteList SDK_data_02017640
#define PMi_PostSleepCallbackList SDK_data_02173268
#define PM_DeletePostSleepCallback Mem_FindGlobalTopParentHeapHead
#include <nitro/spi/ARM9/pm.h>
#include <nitro/pxi.h>
#include <nitro/gx.h>
#include <nitro/spi/common/config.h>
#include <nitro/ctrdg.h>
#include <nitro/mb.h>
extern void PMi_DeleteList (PMSleepCallbackInfo ** listp, PMSleepCallbackInfo * info);
extern PMSleepCallbackInfo * PMi_PostSleepCallbackList;
#pragma thumb off
void PM_DeletePostSleepCallback (PMSleepCallbackInfo * info)
{
    PMi_DeleteList(&PMi_PostSleepCallbackList, info);
}
