/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_EnqueueTail Os_Mutex_EnqueueThread
#include "nitro/types.h"
#include "OS_mutex.h"
#include "OS_system.h"
#include "code32.h"

void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex)
{
    OSMutex *prev = thread->mutexQueue.tail;

    if (!prev)
    {
        thread->mutexQueue.head = mutex;
    }
    else
    {
        prev->link.next = mutex;
    }

    mutex->link.prev = prev;
    mutex->link.next = NULL;
    thread->mutexQueue.tail = mutex;
}
