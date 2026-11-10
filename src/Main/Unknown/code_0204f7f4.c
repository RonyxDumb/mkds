#include "Main/Unknown/code_0204f7f4.h"
#include "pm.h"

u32 SendLedPatternWireless(void) {
    return PMi_SendLEDPatternCommand(0xfu);
}

void SendLedPatternNone(void) {
    u32 value0;
    u32 value12;
    value0 = 0u;
    value0 = PMi_SendLEDPatternCommand(value0);
}
