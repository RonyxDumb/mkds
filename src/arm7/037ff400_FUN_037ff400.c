/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_CancelAlarm FUN_037fa564
#define SNDi_Work SDK_data_03807ecc
#define SND_StopAlarm FUN_037ff400
#include <nitro/snd/common/alarm.h>
#include <nitro/pxi.h>
#include <nitro/snd/common/work.h>

#pragma thumb off
    void SND_StopAlarm (int alarmNo)
    {
        SNDAlarm * alarm;

        SDK_MINMAX_ASSERT(alarmNo, SND_ALARM_MIN, SND_ALARM_MAX);

        alarm = &SNDi_Work.alarm[alarmNo];

        if (!alarm->enable)
            return;

        OS_CancelAlarm(&alarm->alarm);

        alarm->id++;
        alarm->enable = FALSE;
    }
