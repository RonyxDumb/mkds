/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate FUN_037fb000
#define OS_DisableInterrupts FUN_037faf70
#define OSi_InsertAlarm FUN_037fa6e4
#define OS_RestoreInterrupts FUN_037faf84
#define OS_SetPeriodicAlarm FUN_037fa5f4
#include <nitro/os.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>
extern void OSi_InsertAlarm (OSAlarm * alarm, OSTick fire);
#pragma thumb off
void OS_SetPeriodicAlarm (OSAlarm * alarm, OSTick start, OSTick period, OSAlarmHandler handler, void * arg)
{
    u32 enabled;

    SDK_ASSERT(OSi_UseAlarm);
    SDK_ASSERTMSG(handler, "OS_SetPeriodicAlarm: handler must not be NULL\n");
    SDK_ASSERTMSG(period > 0, "OS_SetPeriodicAlarm: bad period specified.");

    if (!alarm || alarm->handler) {
#ifndef SDK_FINALROM
        OS_Panic("alarm could be already used.");
#else
        OS_Panic("");
#endif
    }

    enabled = OS_DisableInterrupts();

    alarm->period = period;
    alarm->start = start;
    alarm->handler = handler;
    alarm->arg = arg;

    OSi_InsertAlarm(alarm, 0);

    (void)OS_RestoreInterrupts(enabled);
}
