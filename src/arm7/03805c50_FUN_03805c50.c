/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RTC_ReadStatus2 FUN_03805b34
#define RtcGpioTransfer FUN_038057b4
#define RTC_WriteAlarm1 FUN_03805c50
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>
extern void RTC_ReadStatus2(RTCRawStatus2 *stat);
extern void RtcGpioTransfer(u16 inst, u16 param, void *buf, u32 size);
#pragma thumb off
BOOL RTC_WriteAlarm1(const RTCRawAlarm *alarm)
{
    RTCRawStatus2 stat2;
    RTC_ReadStatus2(&stat2);

    if (stat2.intr_mode == RTC_INTERRUPT_MODE_ALARM) {
        RtcGpioTransfer(RTC_INSTRUCTION_WRITE, RTC_INSTRUCTION_ALARM1, alarm, 3);
        return TRUE;
    }
    return FALSE;
}
