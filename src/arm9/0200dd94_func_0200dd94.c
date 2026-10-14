/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_RescheduleThread Os_RescheduleThread
#define OSi_ThreadInfo SDK_data_0216ff5c
#define OS_YieldThread func_0200dd94
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
extern void OSi_RescheduleThread(void);
extern OSThreadInfo OSi_ThreadInfo;
void OS_YieldThread(void)
{
    OSThread *current = OS_GetCurrentThread();
    OSThread *pre = NULL;
    OSThread *lastThread = NULL;
    s32 samePriorityThread = 0;
    OSIntrMode enabled = OS_DisableInterrupts();

    OSThread *t = OSi_ThreadInfo.list;
    OSThread *tPre = NULL;

    while (t)
    {
        if (t == current)
        {
            pre = tPre;
        }

        if (current->priority == t->priority)
        {
            lastThread = t;
            samePriorityThread++;
        }

        tPre = t;
        t = t->next;
    }

    if (samePriorityThread <= 1 || lastThread == current)
    {
        (void)OS_RestoreInterrupts(enabled);
        return;
    }

    if (!pre)
    {
        OSi_ThreadInfo.list = current->next;
    }
    else
    {
        pre->next = current->next;
    }

    current->next = lastThread->next;
    lastThread->next = current;

    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enabled);
}
