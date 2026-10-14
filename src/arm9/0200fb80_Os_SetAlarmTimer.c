/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_GetTick Os_GetTick
#define OSi_EnterTimerCallback Os_SetTimerIrqHandler
#define OS_EnableIrqMask Os_EnableIrqHandler
#define OSi_AlarmHandler SDK_data_0200f790
#define OSi_SetTimer Os_SetAlarmTimer
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"

void OSi_SetTimer(OSAlarm *alarm)
{
    OSTick tick = OS_GetTick();

    OS_SetTimerControl(OS_TIMER_1, 0);

    s64 delta = (s64)(alarm->fire - tick);

    OSi_EnterTimerCallback(OS_TIMER_1, OSi_AlarmHandler, NULL);

    u16 timerCount;
    if (delta < 0)
    {
        timerCount = (u16)~1;
    }
    else if (delta < 0x10000)
    {
        timerCount = (u16)(~delta);
    }
    else
    {
        timerCount = 0;
    }

    OS_SetTimerCount((OSTimer)OS_TIMER_1, timerCount);
    OS_SetTimerControl(OS_TIMER_1, (u16)OSi_TICK_TIMERCONTROL);

    (void)OS_EnableIrqMask(OS_IE_TIMER1);
}
