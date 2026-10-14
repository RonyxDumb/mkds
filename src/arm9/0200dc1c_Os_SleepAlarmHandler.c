/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_WakeupThreadDirect SDK_data_0200df68
#define OSi_SleepAlarmCallback Os_SleepAlarmHandler
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
extern void OS_WakeupThreadDirect(OSThread *thread);
void OSi_SleepAlarmCallback(void *arg)
{
    OSThread **pp_thread = (OSThread **)arg;
    OSThread *p_thread = *pp_thread;
    *pp_thread = NULL;

    p_thread->alarmForSleep = NULL;

    OS_WakeupThreadDirect(p_thread);
}
