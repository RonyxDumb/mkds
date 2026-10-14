/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RtcChangeAlarmFormat24to12 FUN_03805930
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>

#pragma thumb off
void RtcChangeAlarmFormat24to12(RTCRawAlarm *alarm)
{
    switch (alarm->hour) {
    case 0x00:
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x10:
    case 0x11:
        alarm->afternoon = 0;
        break;
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x22:
    case 0x23:
        alarm->afternoon = 1;
        alarm->hour -= 0x12;
        break;
    case 0x20:
    case 0x21:
        alarm->afternoon = 1;
        alarm->hour -= 0x18;
        break;
    default:
        alarm->afternoon = 0;
        alarm->hour = 0x00;
    }
}
