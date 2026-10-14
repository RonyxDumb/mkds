/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OSi_TickCounter SDK_data_02170254
#define OS_GetTick Os_GetTick
#include "OS_tick.h"
#include "OS_interrupt.h"
#include "OS_timer.h"
#include "OS_system.h"
#include "code32.h"
extern vu64 OSi_TickCounter;
OSTick OS_GetTick(void)
{
    OSIntrMode prev = OS_DisableInterrupts();
    vu16 countL = *(REGType16 *)((u32)&reg_OS_TM0CNT_L + OS_TIMER_0 * 4);
    vu64 countH = OSi_TickCounter & 0xffffffffffffULL;

    if (reg_OS_IF & OS_IE_TIMER0 && !(countL & 0x8000))
    {
        countH++;
    }

    (void)OS_RestoreInterrupts(prev);

    return (countH << 16) | countL;
}
