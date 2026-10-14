/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadInfo SDK_data_0216ff5c
#define OSi_RemoveThreadFromList Os_PopThread
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
extern OSThreadInfo OSi_ThreadInfo;
void OSi_RemoveThreadFromList(OSThread *thread)
{
    OSThread *t = OSi_ThreadInfo.list;
    OSThread *pre = NULL;

    while (t && t != thread)
    {
        pre = t;
        t = t-> next;
    }

    if (!pre)
    {
        OSi_ThreadInfo.list = thread->next;
    }
    else
    {
        pre->next = thread->next;
    }
}
