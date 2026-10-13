/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OSi_EnqueueTail Os_Mutex_EnqueueThread
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_ThreadInfo SDK_data_0216ff5c
#define OS_TryLockMutex Os_Mutex_TryLock
#include "nitro/types.h"
#include "OS_mutex.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex);
BOOL OS_TryLockMutex(OSMutex *mutex)
{
    OSIntrMode prevIntrMode = OS_DisableInterrupts();
    OSThread *currentThread = OS_GetCurrentThread();
    BOOL locked;

    if (mutex->thread == NULL)
    {
        mutex->thread = currentThread;
        mutex->count++;
        OSi_EnqueueTail(currentThread, mutex);
        locked = TRUE;
    }
    else if (mutex->thread == currentThread)
    {
        mutex->count++;
        locked = TRUE;
    }
    else
    {
        locked = FALSE;
    }

    (void)OS_RestoreInterrupts(prevIntrMode);
    return locked;
}
