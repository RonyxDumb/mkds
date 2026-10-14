/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_Terminate FUN_037fb000
#define OS_SetVAlarmTag FUN_037fac14
#include <nitro.h>

#pragma thumb off
void OS_SetVAlarmTag (OSVAlarm * alarm, u32 tag)
{
#ifdef SDK_DEBUG
    SDK_ASSERT(OSi_UseVAlarm);
    SDK_ASSERT(alarm);
    SDK_ASSERTMSG(tag > 0, "OSSetVAlarmTag: Tag must be >0.");
#else
    if (tag == 0) {
        OS_Panic("");
    }
#endif

    if (alarm) {
        alarm->tag = tag;
    }
}
