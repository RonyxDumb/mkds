/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_CancelAlarm FUN_037fa564
#define OS_CreateAlarm FUN_037fa814
#define OS_SetAlarm FUN_037fa670
#define OS_GetTick FUN_037fa278
#define OS_SetPeriodicAlarm FUN_037fa5f4
#define SNDi_Work SDK_data_03807ecc
#define AlarmHandler SDK_data_037ff3d0
#define SND_StartAlarm FUN_037ff440
#include <nitro/snd/common/alarm.h>
#include <nitro/pxi.h>
#include <nitro/snd/common/work.h>
extern void AlarmHandler (void * arg);
#pragma thumb off
    void SND_StartAlarm (int alarmNo)
    {
        OSTick tick;
        OSTick period;
        SNDAlarm * alarm;
        void * arg;

        SDK_MINMAX_ASSERT(alarmNo, SND_ALARM_MIN, SND_ALARM_MAX);

        alarm = &SNDi_Work.alarm[alarmNo];

        if (alarm->enable) {
            OS_CancelAlarm(&alarm->alarm);
            alarm->enable = FALSE;
        }

        tick = alarm->setting.tick;
        period = alarm->setting.period;
        arg = (void *)((alarm->id << 8) | alarmNo);

        OS_CreateAlarm(&alarm->alarm);

        if (period == 0) {
            OS_SetAlarm(&alarm->alarm, tick, AlarmHandler, arg);
        } else {
            OS_SetPeriodicAlarm(&alarm->alarm, OS_GetTick() + tick, period, AlarmHandler, arg);
        }

        alarm->enable = TRUE;
    }
