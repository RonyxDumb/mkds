/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_SetTimer Os_SetAlarmTimer
#define OSi_AlarmQueue SDK_data_02170260
#define OS_CancelAlarm Os_Alarm_Cancel
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_SetTimer(OSAlarm *alarm);
extern struct OSiAlarmQueue OSi_AlarmQueue;
void OS_CancelAlarm(OSAlarm *alarm)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (!alarm->handler)
    {
        (void)OS_RestoreInterrupts(enabled);
        return;
    }

    OSAlarm *next = alarm->next;

    if (!next)
    {
        OSi_AlarmQueue.tail = alarm->prev;
    }
    else
    {
        next->prev = alarm->prev;
    }

    if (alarm->prev)
    {
        alarm->prev->next = next;
    }
    else
    {
        OSi_AlarmQueue.head = next;
        if (next)
        {
            OSi_SetTimer(next);
        }
    }

    alarm->handler = NULL;
    alarm->period = 0;

    (void)OS_RestoreInterrupts(enabled);
}
