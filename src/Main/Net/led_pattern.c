#include "Main/Net/led_pattern.h"
#include "power_management_commands.h"

u32 SendLedPatternWireless(void) {
    return PMi_SendLEDPatternCommand(0xfu);
}

void SendLedPatternNone(void) {
    u32 value;
    u32 unusedValue;
    value = 0u;
    value = PMi_SendLEDPatternCommand(value);
}
