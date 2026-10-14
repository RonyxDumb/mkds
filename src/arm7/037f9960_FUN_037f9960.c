/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_RemoveMutexLinkFromQueue FUN_037f9584
#define OS_WakeupThread FUN_037f9088
#define OSi_UnlockAllMutex FUN_037f9960
#include <nitro/types.h>
#include <nitro.h>

#pragma thumb off
void OSi_UnlockAllMutex (OSThread * thread)
{
    OSMutex * mutex;

    SDK_ASSERT(thread);

#ifndef SDK_THREAD_INFINITY
    while (thread->mutexQueueHead) {
        mutex = OSi_DequeueHead(thread);
        SDK_ASSERT(mutex->thread == thread);

        mutex->count = 0;
        mutex->thread = NULL;
        OS_WakeupThread(&(mutex->queue));
    }
#else
    while (thread->mutexQueue.head) {
        mutex = OSi_RemoveMutexLinkFromQueue(&thread->mutexQueue);

        SDK_ASSERT(mutex->thread == thread);
        mutex->count = 0;
        mutex->thread = NULL;
        OS_WakeupThread(&mutex->queue);

    }
#endif
}
