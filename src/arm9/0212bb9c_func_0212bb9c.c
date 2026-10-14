/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sAlarmLock SDK_data_0217d43c
#define NNS_SndAllocAlarm func_0212bb9c
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sAlarmLock;
#pragma thumb off
int NNS_SndAllocAlarm (void)
{
    int alarmNo;
    u32 mask = 1;

    for (alarmNo = 0; alarmNo < SND_ALARM_NUM; alarmNo++, mask <<= 1) {
        if ((sAlarmLock & mask) == 0) {
            sAlarmLock |= mask;
            return alarmNo;
        }
    }

    return -1;
}
