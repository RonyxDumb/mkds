/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_DequeueItem Os_Mutex_DequeueThread
#include "nitro/types.h"
#include "OS_mutex.h"
#include "OS_system.h"
#include "code32.h"

void OSi_DequeueItem(OSThread *thread, OSMutex *mutex)
{
    OSMutex *next = mutex->link.next;
    OSMutex *prev = mutex->link.prev;

    if (!next)
    {
        thread->mutexQueue.tail = prev;
    }
    else
    {
        next->link.prev = prev;
    }

    if(!prev)
    {
        thread->mutexQueue.head = next;
    }
    else
    {
        prev->link.next = next;
    }
}
