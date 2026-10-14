/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_Terminate FUN_037fb000
#define OSi_GetVFrame FUN_037fa920
#define OSi_InsertVAlarm FUN_037fae5c
#define OS_RestoreInterrupts FUN_037faf84
#define OS_SetVAlarm FUN_037fad34
#include <nitro.h>
extern s32 OSi_GetVFrame (s32 vcount);
extern void OSi_InsertVAlarm (OSVAlarm * alarm);
#pragma thumb off
void OS_SetVAlarm (OSVAlarm * alarm, s16 count, s16 delay, OSVAlarmHandler handler, void * arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    s32 currentVCount;
    s32 currentVFrame;

    SDK_ASSERT(OSi_UseVAlarm);
    SDK_ASSERTMSG(handler, "OS_SetVAlarm: handler must not be NULL.");
    if (!alarm || alarm->handler) {
#ifndef SDK_FINALROM
        OS_Panic("v-alarm could be already used.");
#else
        OS_Panic("");
#endif
    }

    currentVCount = GX_GetVCount();
    currentVFrame = OSi_GetVFrame(currentVCount);

    alarm->period = FALSE;

    alarm->fire = count;
    alarm->frame = (u32)((count > currentVCount) ? currentVFrame : (currentVFrame + 1));

    alarm->delay = delay;

    alarm->handler = handler;
    alarm->arg = arg;

    alarm->canceled = FALSE;

    OSi_InsertVAlarm(alarm);

    (void)OS_RestoreInterrupts(enabled);
}
