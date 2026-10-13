/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_SetTimerReserved Os_ReserveTimer
#define OS_DisableIrqMask Os_DisableIrqHandler
#define OSi_UseAlarm SDK_data_0217025c
#define OSi_AlarmQueue SDK_data_02170260
#define OS_InitAlarm Os_InitializeAlarm
#include "consts.h"
#include "OS_alarm.h"
#include "OS_interrupt.h"
#include "OS_irqTable.h"
#include "OS_terminate_proc.h"
#include "OS_system.h"
#include "code32.h"
extern u16 OSi_UseAlarm;
extern struct OSiAlarmQueue OSi_AlarmQueue;
void OS_InitAlarm(void)
{
    if (!OSi_UseAlarm)
    {
        OSi_UseAlarm = TRUE;

        OSi_SetTimerReserved(OS_TIMER_1);

        OSi_AlarmQueue.head = NULL;
        OSi_AlarmQueue.tail = NULL;

        (void)OS_DisableIrqMask(OS_IE_TIMER1);
    }
}
