/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_DetachVAlarm FUN_037fade0
#define OS_CancelVAlarm FUN_037fabc0
#include <nitro.h>
extern void OSi_DetachVAlarm (OSVAlarm * alarm);
#pragma thumb off
void OS_CancelVAlarm (OSVAlarm * alarm)
{
    OSIntrMode enabled = OS_DisableInterrupts();;

    SDK_ASSERT(OSi_UseVAlarm);
    SDK_ASSERT(alarm);

    alarm->canceled = TRUE;
    if (alarm->handler == NULL) {
        (void)OS_RestoreInterrupts(enabled);
        return;
    }

    OSi_DetachVAlarm(alarm);

    alarm->handler = NULL;

    (void)OS_RestoreInterrupts(enabled);
}
