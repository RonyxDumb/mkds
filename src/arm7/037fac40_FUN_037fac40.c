/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_SetIrqFunction FUN_037f8944
#define OS_EnableIrqMask FUN_037f888c
#define OSi_VAlarmHandler SDK_data_037fa9bc
#define OSi_SetNextVAlarm FUN_037fac40
#include <nitro.h>
extern void OSi_VAlarmHandler (void *);
#pragma thumb off
void OSi_SetNextVAlarm (OSVAlarm * alarm)
{
    OS_SetIrqFunction(OS_IE_V_COUNT, (void (*)()) OSi_VAlarmHandler);

    GX_SetVCountEqVal(alarm->fire);
    GX_VCountEqIntr(TRUE);

    (void)OS_EnableIrqMask(OS_IE_V_COUNT);
}
