/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define EXIi_SelectRcnt FUN_037fb808
#define RtcGpioTransfer FUN_038057b4
#define RTC_ReadAdjust FUN_03805adc
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>
extern void RtcGpioTransfer(u16 inst, u16 param, void *buf, u32 size);
#pragma thumb off
void RTC_ReadAdjust(RTCRawAdjust *adjust)
{
    EXIi_SelectRcnt(EXI_GPIOIF_GPIO);

    RtcGpioTransfer(RTC_INSTRUCTION_READ, RTC_INSTRUCTION_ADJUST, adjust, 1);
}
