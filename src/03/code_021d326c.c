#include "03/code_021d326c.h"
#include "pm.h"

void SendLedPatternOn(void) {
    u32 value0;
    u32 unused;
    value0 = 1u;
    value0 = PMi_SendLEDPatternCommand(value0);
}
