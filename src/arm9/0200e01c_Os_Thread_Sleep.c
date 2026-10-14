/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OSi_InsertLinkToQueue Os_ThreadQueue_Queue
#define OSi_RescheduleThread Os_RescheduleThread
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_CurrentThreadPtr SDK_data_0216ff54
#define OS_SleepThread Os_Thread_Sleep
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
extern void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
extern void OSi_RescheduleThread(void);
extern OSThread **OSi_CurrentThreadPtr;
void OS_SleepThread(OSThreadQueue *queue)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    OSThread *currentThread = OSi_GetCurrentThread();

    if (queue)
    {
        currentThread->queue = queue;
        OSi_InsertLinkToQueue(queue, currentThread);
    }

    currentThread->state = OS_THREAD_STATE_WAITING;
    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enabled);
}
