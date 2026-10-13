/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_RemoveLinkFromQueue Os_ThreadQueue_Pop
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

OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue)
{
    OSThread *thread = queue->head;

    if (thread)
    {
        OSThread *next = thread->link.next;

        queue->head = next;

        if (next)
        {
            next->link.prev = NULL;
        }
        else
        {
            queue->tail = NULL;
            thread->queue = NULL;
        }
    }

    return thread;
}
