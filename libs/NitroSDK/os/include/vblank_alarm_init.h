#pragma once

#include "types.h"

// Runs once: clears the vertical count alarm list (g_VAlarmQueue), g_VAlarm_FrameCount and g_VAlarm_PrevVCount and the
// V-count interrupt enable.
void Os_InitializeVAlarm(void);
