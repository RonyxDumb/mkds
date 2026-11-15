#include "os_timer.h"
#include "exception_state.h"

u16 OSi_TimerReserved;

// Marks timer timerNum as reserved.
void OSi_SetTimerReserved(u32 timerNum) {
    OSi_TimerReserved = OSi_TimerReserved | (1 << timerNum);
}
