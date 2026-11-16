#include "Main/Unknown/code_0204f7f4.h"
#include "pm.h"

u32 LEDBlink_Wireless(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &PMi_SendLEDPatternCommand;
    value0 = 0xfu;
    value0 = PMi_SendLEDPatternCommand(value0);
    return value0;
}

void LEDBlink_NoPattern(void) {
    u32 value0;
    u32 value12;
    value0 = 0u;
    value0 = PMi_SendLEDPatternCommand(value0);
}
