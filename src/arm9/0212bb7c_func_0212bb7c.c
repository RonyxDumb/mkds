/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sAlarmLock SDK_data_0217d43c
#define NNS_SndFreeAlarm func_0212bb7c
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sAlarmLock;
#pragma thumb off
void NNS_SndFreeAlarm (int alarmNo)
{
    NNS_MINMAX_ASSERT(alarmNo, SND_ALARM_MIN, SND_ALARM_MAX);
    NNS_ASSERT(sAlarmLock & (1 << alarmNo));

    sAlarmLock &= ~(1 << alarmNo);
}
