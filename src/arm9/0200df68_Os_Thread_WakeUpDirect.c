/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OSi_RescheduleThread Os_RescheduleThread
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_WakeupThreadDirect Os_Thread_WakeUpDirect
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
void OS_WakeupThreadDirect(OSThread *thread)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    thread->state = OS_THREAD_STATE_READY;
    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enabled);
}
