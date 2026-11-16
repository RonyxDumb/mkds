#include "vblank_alarm_init.h"

#include "interrupt_control.h"

u16 g_VAlarmInitialized;
u32 g_VAlarm_FrameCount;
u32 g_VAlarm_PrevVCount;
u32 g_VAlarmQueue[2];

// Runs once: empties the vertical count alarm state and clears the V-count interrupt enable.
void Os_InitializeVAlarm(void) {
    if (g_VAlarmInitialized != 0) {
        return;
    }
    g_VAlarmInitialized = 1;
    g_VAlarmQueue[0] = 0;
    g_VAlarmQueue[1] = 0;
    Os_DisableIrqHandler(4);
    g_VAlarm_FrameCount = 0;
    g_VAlarm_PrevVCount = 0;
}
