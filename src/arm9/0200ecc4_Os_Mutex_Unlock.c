/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OSi_DequeueItem Os_Mutex_DequeueThread
#define OS_WakeupThread Os_Thread_WakeUp
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_ThreadInfo SDK_data_0216ff5c
#define OS_UnlockMutex Os_Mutex_Unlock
#include "nitro/types.h"
#include "OS_mutex.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_DequeueItem(OSThread *thread, OSMutex *mutex);
void OS_UnlockMutex(OSMutex *mutex)
{
    OSIntrMode prevIntrMode = OS_DisableInterrupts();
    OSThread *currentThread = OS_GetCurrentThread();

    if (mutex->thread == currentThread && --mutex->count == 0)
    {
        OSi_DequeueItem(currentThread, mutex);
        mutex->thread = NULL;

        OS_WakeupThread(&mutex->queue);
    }

    (void)OS_RestoreInterrupts(prevIntrMode);
}
