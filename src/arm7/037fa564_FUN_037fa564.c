/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_SetTimer FUN_037fa884
#define OSi_AlarmQueue SDK_data_03807894
#define OS_CancelAlarm FUN_037fa564
#include <nitro/os.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>
extern void OSi_SetTimer (OSAlarm * alarm);
extern struct OSiAlarmQueue OSi_AlarmQueue;
#pragma thumb off
void OS_CancelAlarm (OSAlarm * alarm)
{
    OSAlarm * next;
    u32 enabled;

    SDK_ASSERT(OSi_UseAlarm);
    SDK_ASSERT(alarm);

    enabled = OS_DisableInterrupts();

    if (alarm->handler == NULL) {
        (void)OS_RestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;

    if (next == NULL) {
        OSi_AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }

    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        OSi_AlarmQueue.head = next;
        if (next) {
            OSi_SetTimer(next);
        }
    }

    alarm->handler = NULL;
    alarm->period = 0;

    (void)OS_RestoreInterrupts(enabled);
}
