#include "03/Net/led_pattern_send.h"
#include "03/code_021d3278.h"
#include "pm.h"

void SendLedPatternWirelessIfDifferent(void) {
    int result;
    int pattern[1];
    result = PM_GetLEDPattern((u32 *) pattern);
    if ((result == 0) && (pattern[0] != 0xf)) {
        PMi_SendLEDPatternCommand(0xf);
    }
}

void SendLedPatternOn(void) {
    u32 value0;
    u32 unused;
    value0 = 1u;
    value0 = PMi_SendLEDPatternCommand(value0);
}
