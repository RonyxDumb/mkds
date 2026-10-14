/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_SetTimerReserved Os_ReserveTimer
#define OS_SetIrqFunction Os_SetIrqHandler
#define OS_EnableIrqMask Os_EnableIrqHandler
#define OSi_UseTick SDK_data_0217024c
#define OSi_TickCounter SDK_data_02170254
#define OSi_CountUpTick SDK_data_0200f65c
#define OSi_NeedResetTimer SDK_data_02170250
#define OS_InitTick Os_InitializeTick
#include "OS_tick.h"
#include "OS_interrupt.h"
#include "OS_timer.h"
#include "OS_system.h"
#include "code32.h"
extern u16 OSi_UseTick;
extern vu64 OSi_TickCounter;
extern void OSi_CountUpTick(void);
extern BOOL OSi_NeedResetTimer;
void OS_InitTick(void)
{
    if (OSi_UseTick)
    {
        return;
    }
    OSi_UseTick = 1;
    OSi_SetTimerReserved(0);
    OSi_TickCounter = 0;
    reg_OS_TM0CNT_H = 0;
    reg_OS_TM0CNT_L = 0;
    reg_OS_TM0CNT_H = 0xc1;
    OS_SetIrqFunction(8, OSi_CountUpTick);
    (void)OS_EnableIrqMask(8);
    OSi_NeedResetTimer = FALSE;
}
