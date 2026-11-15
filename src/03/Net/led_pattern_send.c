#include "03/Net/led_pattern_send.h"
#include "03/Net/led_pattern_send_if_different.h"
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
    u32 result;
    u32 unused;
    result = 1u;
    result = PMi_SendLEDPatternCommand(result);
}
