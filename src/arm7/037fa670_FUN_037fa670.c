/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate FUN_037fb000
#define OS_DisableInterrupts FUN_037faf70
#define OS_GetTick FUN_037fa278
#define OSi_InsertAlarm FUN_037fa6e4
#define OS_RestoreInterrupts FUN_037faf84
#define OS_SetAlarm FUN_037fa670
#include <nitro/os.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>
extern void OSi_InsertAlarm (OSAlarm * alarm, OSTick fire);
#pragma thumb off
void OS_SetAlarm (OSAlarm * alarm, OSTick tick, OSAlarmHandler handler, void * arg)
{
    OSIntrMode enabled;

    SDK_ASSERT(OSi_UseAlarm);
    SDK_ASSERTMSG(handler, "OS_SetAlarm: handler must not be NULL.");

    if (!alarm || alarm->handler) {
#ifndef SDK_FINALROM
        OS_Panic("alarm could be already used.");
#else
        OS_Panic("");
#endif
    }

    enabled = OS_DisableInterrupts();

    alarm->period = 0;
    alarm->handler = handler;
    alarm->arg = arg;

    OSi_InsertAlarm(alarm, OS_GetTick() + tick);

    (void)OS_RestoreInterrupts(enabled);
}
