/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_CreateAlarm FUN_037fa814
#include <nitro/os.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void OS_CreateAlarm (OSAlarm * alarm)
{
    SDK_ASSERT(OSi_UseAlarm);
    SDK_ASSERT(alarm);

    alarm->handler = 0;
    alarm->tag = 0;
}
