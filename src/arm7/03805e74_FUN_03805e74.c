/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RTC_ReadStatus1 FUN_03805b8c
#define RTC_WriteStatus1 FUN_03805b60
#define RtcGpioTransfer FUN_038057b4
#define RtcChangeAlarmFormat24to12 FUN_03805930
#define RtcChangeAlarmFormat12to24 FUN_03805818
#define RTC_SetHourFormat FUN_03805e74
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>
extern void RTC_ReadStatus1(RTCRawStatus1 *stat);
extern void RTC_WriteStatus1(const RTCRawStatus1 *stat);
extern void RtcGpioTransfer(u16 inst, u16 param, void *buf, u32 size);
extern void RtcChangeAlarmFormat24to12(RTCRawAlarm *alarm);
extern void RtcChangeAlarmFormat12to24(RTCRawAlarm *alarm);
#pragma thumb off
void RTC_SetHourFormat(u16 format)
{
    RTCRawStatus1 stat1;
    RTCRawAlarm alarm;

    format %= 2;
    if (format != 1) {
        return;
    }

    RTC_ReadStatus1(&stat1);

    if (stat1.format != format) {
        stat1.format = format;
        RTC_WriteStatus1(&stat1);

        RtcGpioTransfer(RTC_INSTRUCTION_READ, RTC_INSTRUCTION_ALARM1, &alarm, 3);

        if (format == 0) {
            RtcChangeAlarmFormat24to12(&alarm);
        } else {
            RtcChangeAlarmFormat12to24(&alarm);
        }

        RtcGpioTransfer(RTC_INSTRUCTION_WRITE, RTC_INSTRUCTION_ALARM1, &alarm, 3);

        RtcGpioTransfer(RTC_INSTRUCTION_READ, RTC_INSTRUCTION_ALARM2, &alarm, 3);

        if (format == 0) {
            RtcChangeAlarmFormat24to12(&alarm);
        } else {
            RtcChangeAlarmFormat12to24(&alarm);
        }

        RtcGpioTransfer(RTC_INSTRUCTION_WRITE, RTC_INSTRUCTION_ALARM2, &alarm, 3);
    }
}
