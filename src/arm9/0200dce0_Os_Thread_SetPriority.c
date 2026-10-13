/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_InsertThreadToList Os_InsertThread
#define OSi_RescheduleThread Os_RescheduleThread
#define OSi_ThreadInfo SDK_data_0216ff5c
#define OSi_IdleThread SDK_data_0216ff6c
#define OS_SetThreadPriority Os_Thread_SetPriority
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
extern void OSi_InsertThreadToList(OSThread *thread);
extern void OSi_RescheduleThread(void);
extern OSThreadInfo OSi_ThreadInfo;
extern OSThread OSi_IdleThread;
BOOL OS_SetThreadPriority(OSThread *thread, u32 prio)
{
    OSThread *t = OSi_ThreadInfo.list;
    OSThread *pre = NULL;
    OSIntrMode enabled = OS_DisableInterrupts();

    while (t && t != thread)
    {
        pre = t;
        t = t->next;
    }

    if (!t || t == &OSi_IdleThread)
    {
        (void)OS_RestoreInterrupts(enabled);
        return FALSE;
    }

    if (t->priority != prio)
    {
        if (!pre)
        {
            OSi_ThreadInfo.list = thread->next;
        }
        else
        {
            pre->next = thread->next;
        }

        thread->priority = prio;
        OSi_InsertThreadToList(thread);

        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enabled);

    return TRUE;
}
