#include "tick_counter.h"
#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "system_state_globals.h"
#include "timer_reserved_flag.h"
#include "registers.h"

u16 g_Os_TickInitialized;
u32 g_Os_NeedsTimerReset;
volatile u64 g_Os_TickCounter;

// Runs once: reserves timer 0, clears g_Os_TickCounter, starts timer 0 and installs Os_CountTicks for its
// interrupt.
void Os_InitializeTick(void) {
    if (g_Os_TickInitialized != 0) {
        return;
    }
    g_Os_TickInitialized = 1;
    Os_ReserveTimer(0);
    g_Os_TickCounter = 0;
    *(vu16 *) 0x4000102 = 0;
    reg_OS_TM0CNT_L = 0;
    *(vu16 *) 0x4000102 = 0xc1;
    Os_SetIrqHandler(8, Os_CountTicks);
    Os_EnableIrqHandler(8);
    g_Os_NeedsTimerReset = 0;
}

// Returns g_Os_TickInitialized.
u32 Os_IsTickInitialized(void) {
    return g_Os_TickInitialized;
}

// Timer 0 overflow handler: adds 1 to g_Os_TickCounter and restarts timer 0 when g_Os_NeedsTimerReset asks for it.
void Os_CountTicks(void) {
    g_Os_TickCounter++;
    if (g_Os_NeedsTimerReset != 0) {
        *(vu16 *) 0x4000102 = 0;
        reg_OS_TM0CNT_L = 0;
        *(vu16 *) 0x4000102 = 0xc1;
        g_Os_NeedsTimerReset = 0;
    }
    Os_SetTimerIrqHandler(0, Os_CountTicks, 0);
}

// Returns g_Os_TickCounter shifted left by 16 plus the timer 0 count, adding 1 to the overflow count when an overflow
// is pending that the count does not yet include.
u64 Os_GetTick(void) {
    u32 enabled;
    volatile u16 count;
    volatile u64 overflows;

    enabled = Os_DisableIrq();
    count = reg_OS_TM0CNT_L;
    overflows = g_Os_TickCounter & 0xffffffffffffULL;
    if ((reg_OS_IF & 8) && !(count & 0x8000)) {
        overflows++;
    }
    Os_RestoreIrq(enabled);
    return (overflows << 16) | count;
}

u32 OS_GetTickLo(void) {
    u32 timerCounter;
    timerCounter = reg_OS_TM0CNT_L;
    return timerCounter;
}
