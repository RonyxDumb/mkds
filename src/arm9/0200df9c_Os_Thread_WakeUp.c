/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OSi_RemoveLinkFromQueue Os_ThreadQueue_Pop
#define OSi_RescheduleThread Os_RescheduleThread
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_WakeupThread Os_Thread_WakeUp
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
extern OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
extern void OSi_RescheduleThread(void);
void OS_WakeupThread(OSThreadQueue *queue)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (queue->head)
    {
        while (queue->head)
        {
            OSThread *thread = OSi_RemoveLinkFromQueue(queue);

            thread->state = OS_THREAD_STATE_READY;
            thread->queue = NULL;
            thread->link.prev = thread->link.next = NULL;
        }

        OS_InitThreadQueue(queue);
        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enabled);
}
