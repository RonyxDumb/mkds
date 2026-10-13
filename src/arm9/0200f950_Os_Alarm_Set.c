/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate Os_Terminate
#define OS_DisableInterrupts Os_DisableIrq
#define OS_GetTick Os_GetTick
#define OSi_InsertAlarm Os_InsertAlarm
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_SetAlarm Os_Alarm_Set
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);
void OS_SetAlarm(OSAlarm * alarm, OSTick tick, OSAlarmHandler handler, void *arg)
{
    if (!alarm || alarm->handler)
    {
        OS_Terminate();
    }

    OSIntrMode enabled = OS_DisableInterrupts();

    alarm->period = 0;

    alarm->handler = handler;
    alarm->arg = arg;

    OSi_InsertAlarm(alarm, OS_GetTick() + tick);

    (void)OS_RestoreInterrupts(enabled);
}
