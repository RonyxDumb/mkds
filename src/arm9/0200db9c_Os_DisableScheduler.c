/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_RescheduleCount SDK_data_0216ff48
#define OS_DisableScheduler Os_DisableScheduler
#include "MI_memory.h"
#include "OS_thread.h"
#include "OS_mutex.h"
#include "OS_alarm.h"
#include "OS_system.h"
#include "OS_context.h"
#include "OS_terminate_proc.h"
#include "systemWork.h"
#include "mmap.h"
#include "code32.h"
extern u32 OSi_RescheduleCount;
u32 OS_DisableScheduler(void)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    u32 count;

    if (OSi_RescheduleCount < (u32)-1)
    {
        count = OSi_RescheduleCount++;
    }
    (void)OS_RestoreInterrupts(enabled);

    return count;
}
