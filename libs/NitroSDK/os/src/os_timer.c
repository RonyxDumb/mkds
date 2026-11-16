#include "os_timer.h"
#include "Main/Unknown/unk_02170000.h"

// Marks timer timerNum as reserved.
void OSi_SetTimerReserved(u32 timerNum) {
    g_ReservedTimerMask = g_ReservedTimerMask | (1 << timerNum);
}
