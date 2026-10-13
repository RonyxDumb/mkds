/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask Os_DisableIrqHandler
#define OS_GetTick Os_GetTick
#define OSi_SetTimer Os_SetAlarmTimer
#define OSi_InsertAlarm Os_InsertAlarm
#define SDK_AUTOLOAD_DTCM_START SDK_data_027e0000
#define OSi_AlarmQueue SDK_data_02170260
#define OSi_ArrangeTimer Os_AlarmHandlerImpl
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_SetTimer(OSAlarm *alarm);
extern void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);
extern struct OSiAlarmQueue OSi_AlarmQueue;
void OSi_ArrangeTimer(void)
{
    OS_SetTimerControl(OS_TIMER_1, 0);

    (void)OS_DisableIrqMask(OS_IE_TIMER1);

    OS_SetIrqCheckFlag(OS_IE_TIMER1);

    OSTick tick = OS_GetTick();

    OSAlarm *alarm = OSi_AlarmQueue.head;

    if (!alarm)
    {
        return;
    }

    if (tick < alarm->fire)
    {
        OSi_SetTimer(alarm);
        return;
    }

    OSAlarm *next = alarm->next;
    OSi_AlarmQueue.head = next;

    if (!next)
    {
        OSi_AlarmQueue.tail = NULL;
    }
    else
    {
        next->prev = NULL;
    }

    OSAlarmHandler handler = alarm->handler;

    if (!alarm->period)
    {
        alarm->handler = NULL;
    }

    if (handler)
    {
        (handler)(alarm->arg);
    }

    if (alarm->period > 0)
    {
        alarm->handler = handler;
        OSi_InsertAlarm(alarm, 0);
    }

    if (OSi_AlarmQueue.head)
    {
        OSi_SetTimer(OSi_AlarmQueue.head);
    }
}
