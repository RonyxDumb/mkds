/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_TimerReserved SDK_data_0380787c
#define OSi_SetTimerReserved FUN_037fa25c
#include <nitro/os.h>
extern u16 OSi_TimerReserved;
#pragma thumb off
void OSi_SetTimerReserved (int timerNum)
{
    OSi_TimerReserved |= (1 << timerNum);
}
