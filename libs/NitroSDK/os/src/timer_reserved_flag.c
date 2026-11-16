#include "timer_reserved_flag.h"
#include "system_state_globals.h"

u16 g_ReservedTimerMask;

// Marks timer timerNum as reserved.
void Os_ReserveTimer(u32 timerNum) {
    g_ReservedTimerMask = g_ReservedTimerMask | (1 << timerNum);
}
