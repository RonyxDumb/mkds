/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_JoinThread Os_Thread_Join
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
extern void OS_SleepThread(OSThreadQueue *queue);
void OS_JoinThread(OSThread *thread)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (thread->state != OS_THREAD_STATE_TERMINATED)
    {
        OS_SleepThread(&thread->joinQueue);
    }

    (void)OS_RestoreInterrupts(enabled);
}
