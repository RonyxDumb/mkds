/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_TimerReserved SDK_data_02170248
#define OSi_SetTimerReserved Os_ReserveTimer
#include "OS_timer.h"
#include "function_target.h"
#include "code32.h"
extern u16 OSi_TimerReserved;
void OSi_SetTimerReserved(s32 timerNum)
{
    OSi_TimerReserved |= (1 << timerNum);
}
