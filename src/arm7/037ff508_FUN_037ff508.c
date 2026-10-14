/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_CancelAlarm FUN_037fa564
#define SNDi_Work SDK_data_03807ecc
#define SND_SetupAlarm FUN_037ff508
#include <nitro/snd/common/alarm.h>
#include <nitro/pxi.h>
#include <nitro/snd/common/work.h>

#pragma thumb off
    void SND_SetupAlarm (int alarmNo, OSTick tick, OSTick period, int id)
    {
        SNDAlarm * alarm;

        SDK_MINMAX_ASSERT(alarmNo, SND_ALARM_MIN, SND_ALARM_MAX);
        SDK_MINMAX_ASSERT(id, 0x00, 0xff);

        alarm = &SNDi_Work.alarm[alarmNo];

        if (alarm->enable) {
            OS_CancelAlarm(&alarm->alarm);
            alarm->enable = FALSE;
        }

        alarm->setting.tick = tick;
        alarm->setting.period = period;
        alarm->id = (u8)id;
    }
