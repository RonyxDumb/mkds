/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_RemoveMutexLinkFromQueue Os_MutexQueue_Pop
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

OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue)
{
    OSMutex *mutexHead = queue->head;

    if (mutexHead)
    {
        OSMutex *next = mutexHead->link.next;

        queue->head = next;

        if (next)
        {
            next->link.prev = NULL;
        }
        else
        {
            queue->tail = NULL;
        }
    }

    return mutexHead;
}
