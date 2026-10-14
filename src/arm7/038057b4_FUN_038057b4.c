/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RTCi_GpioStart FUN_03805fb4
#define RTCi_GpioSendCommand FUN_03806028
#define RTCi_GpioReceiveData FUN_03806128
#define RTCi_GpioSendData FUN_03806098
#define RTCi_GpioEnd FUN_03805ff4
#define RtcGpioTransfer FUN_038057b4
#include "nitro/rtc/ARM7/instruction.h"

#include "nitro/rtc/ARM7/gpio.h"
#include <nitro/exi/ARM7/genPort.h>

#pragma thumb off
void RtcGpioTransfer(u16 inst, u16 param, void *buf, u32 size)
{
    RTCi_GpioStart();
    RTCi_GpioSendCommand(inst, param);
    switch (inst) {
    case RTC_INSTRUCTION_READ:
        RTCi_GpioReceiveData(buf, size);
        break;
    case RTC_INSTRUCTION_WRITE:
        RTCi_GpioSendData(buf, size);
        break;
    }
    RTCi_GpioEnd();
}
