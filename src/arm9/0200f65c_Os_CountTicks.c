/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_EnterTimerCallback Os_SetTimerIrqHandler
#define OSi_TickCounter SDK_data_02170254
#define OSi_NeedResetTimer SDK_data_02170250
#define OSi_CountUpTick Os_CountTicks
#include "OS_tick.h"
#include "OS_interrupt.h"
#include "OS_timer.h"
#include "OS_system.h"
#include "code32.h"
extern vu64 OSi_TickCounter;
extern BOOL OSi_NeedResetTimer;
void OSi_CountUpTick(void)
{
    OSi_TickCounter++;

    if (OSi_NeedResetTimer)
    {
        OS_SetTimerControl(OS_TIMER_0, 0);
        OS_SetTimerCount(OS_TIMER_0, 0);
        OS_SetTimerControl(OS_TIMER_0, OSi_TICK_TIMERCONTROL);

        OSi_NeedResetTimer = FALSE;
    }

    OSi_EnterTimerCallback(OS_TIMER_0, (void (*)(void *))OSi_CountUpTick, 0);
}
