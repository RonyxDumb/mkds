/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_CreateVAlarm FUN_037fadcc
#include <nitro.h>

#pragma thumb off
void OS_CreateVAlarm (OSVAlarm * alarm)
{
    SDK_ASSERT(OSi_UseVAlarm);
    SDK_ASSERT(alarm);

    alarm->handler = 0;
    alarm->tag = 0;

    alarm->finish = FALSE;
}
