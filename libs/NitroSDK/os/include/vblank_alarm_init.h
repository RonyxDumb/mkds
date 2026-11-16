#pragma once

#include "types.h"

// Runs once: clears the vertical count alarm list (OSi_VAlarmQueue), OSi_VFrameCount and OSi_PreviousVCount and the
// V-count interrupt enable.
void OS_InitVAlarm(void);
