/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define EXIi_SelectRcnt FUN_037fb808
#define RtcGpioTransfer FUN_038057b4
#define RTC_WriteStatus1 FUN_03805b60
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>
extern void RtcGpioTransfer(u16 inst, u16 param, void *buf, u32 size);
#pragma thumb off
void RTC_WriteStatus1(const RTCRawStatus1 *stat)
{
    EXIi_SelectRcnt(EXI_GPIOIF_GPIO);

    RtcGpioTransfer(RTC_INSTRUCTION_WRITE, RTC_INSTRUCTION_STAT1, stat, 1);
}
