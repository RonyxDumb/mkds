#include "Main/Net/led_pattern.h"
#include "pm.h"

u32 SendLedPatternWireless(void) {
    return PMi_SendLEDPatternCommand(0xfu);
}

void SendLedPatternNone(void) {
    u32 sendResult;
    u32 unusedValue;
    sendResult = 0u;
    sendResult = PMi_SendLEDPatternCommand(sendResult);
}
