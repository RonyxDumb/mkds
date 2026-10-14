/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_DequeueItem FUN_037f9918
#include <nitro/types.h>
#include <nitro.h>

#pragma thumb off
void OSi_DequeueItem (OSThread * thread, OSMutex * mutex)
{
#ifndef SDK_THREAD_INFINITY
    OSMutex * next = mutex->next;
    OSMutex * prev = mutex->prev;

    SDK_ASSERT(thread && mutex);

    if (!next) {
        thread->mutexQueueTail = prev;
    } else {
        next->prev = prev;
    }

    if (!prev) {
        thread->mutexQueueHead = next;
    } else {
        prev->next = next;
    }
#else
    OSMutex * next = mutex->link.next;
    OSMutex * prev = mutex->link.prev;

    SDK_ASSERT(thread && mutex);

    if (!next) {
        thread->mutexQueue.tail = prev;
    } else {
        next->link.prev = prev;
    }

    if (!prev) {
        thread->mutexQueue.head = next;
    } else {
        prev->link.next = next;
    }
#endif
}
