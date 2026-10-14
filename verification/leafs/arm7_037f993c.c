/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_EnqueueTail FUN_037f993c
#include <nitro/types.h>
#include <nitro.h>

#pragma thumb off
void OSi_EnqueueTail (OSThread * thread, OSMutex * mutex)
{
#ifndef SDK_THREAD_INFINITY
    OSMutex * prev = thread->mutexQueueTail;

    SDK_ASSERT(thread && mutex);

    if (!prev) {
        thread->mutexQueueHead = mutex;
    } else {
        prev->next = mutex;
    }

    mutex->prev = prev;
    mutex->next = NULL;
    thread->mutexQueueTail = mutex;
#else
    OSMutex * prev = thread->mutexQueue.tail;

    SDK_ASSERT(thread && mutex);

    if (!prev) {
        thread->mutexQueue.head = mutex;
    } else {
        prev->link.next = mutex;
    }

    mutex->link.prev = prev;
    mutex->link.next = NULL;
    thread->mutexQueue.tail = mutex;
#endif
}
