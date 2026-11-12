#include "code_0200fc1c.h"

#include "code_0200c914.h"

u16 OSi_UseVAlarm;
u32 OSi_VFrameCount;
u32 OSi_PreviousVCount;
u32 OSi_VAlarmQueue[2];

// Runs once: empties the vertical count alarm state and clears the V-count interrupt enable.
void OS_InitVAlarm(void) {
    if (OSi_UseVAlarm != 0) {
        return;
    }
    OSi_UseVAlarm = 1;
    OSi_VAlarmQueue[0] = 0;
    OSi_VAlarmQueue[1] = 0;
    OS_DisableIrqMask(4);
    OSi_VFrameCount = 0;
    OSi_PreviousVCount = 0;
}
