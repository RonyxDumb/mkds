/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_GetTick Os_GetTick
#define OSi_SetTimer Os_SetAlarmTimer
#define OSi_AlarmQueue SDK_data_02170260
#define OSi_InsertAlarm Os_InsertAlarm
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"
extern void OSi_SetTimer(OSAlarm *alarm);
extern struct OSiAlarmQueue OSi_AlarmQueue;
void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire)
{
    if (alarm->period > 0)
    {
        OSTick tick = OS_GetTick();

        fire = alarm->start;
        if (alarm->start < tick)
        {
            fire += alarm->period * ((tick - alarm->start) / alarm->period + 1);
        }
    }

    alarm->fire = fire;

    OSAlarm *prev;
    OSAlarm *next;

    for (next = OSi_AlarmQueue.head; next; next = next->next)
    {
        if ((s64)(fire - next->fire) >= 0)
        {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;
        if (prev)
        {
            prev->next = alarm;
        }
        else
        {
            OSi_AlarmQueue.head = alarm;
            OSi_SetTimer(alarm);
        }

        return;
    }

    alarm->next = 0;
    prev = OSi_AlarmQueue.tail;
    OSi_AlarmQueue.tail = alarm;
    alarm->prev = prev;
    if (prev)
    {
        prev->next = alarm;
    }
    else
    {
        OSi_AlarmQueue.head = OSi_AlarmQueue.tail = alarm;
        OSi_SetTimer(alarm);
    }
}
