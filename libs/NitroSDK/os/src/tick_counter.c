#include "tick_counter.h"
#include "interrupt_control.h"
#include "reset_interrupt_enable.h"
#include "exception_state.h"
#include "timer_reserved_flag.h"
#include "registers.h"

u16 gTickInitialized;
u32 OSi_NeedResetTimer;
volatile u64 gTickOverflowCount;

// Runs once: reserves timer 0, clears gTickOverflowCount, starts timer 0 and installs OSi_CountUpTick for its
// interrupt.
void OS_InitTick(void) {
    if (gTickInitialized != 0) {
        return;
    }
    gTickInitialized = 1;
    OSi_SetTimerReserved(0);
    gTickOverflowCount = 0;
    *(vu16 *) 0x4000102 = 0;
    reg_OS_TM0CNT_L = 0;
    *(vu16 *) 0x4000102 = 0xc1;
    OS_SetIrqFunction(8, OSi_CountUpTick);
    OS_EnableIrqMask(8);
    OSi_NeedResetTimer = 0;
}

// Returns gTickInitialized.
u32 OS_IsTickAvailable(void) {
    return gTickInitialized;
}

// Timer 0 overflow handler: adds 1 to gTickOverflowCount and restarts timer 0 when OSi_NeedResetTimer asks for it.
void OSi_CountUpTick(void) {
    gTickOverflowCount++;
    if (OSi_NeedResetTimer != 0) {
        *(vu16 *) 0x4000102 = 0;
        reg_OS_TM0CNT_L = 0;
        *(vu16 *) 0x4000102 = 0xc1;
        OSi_NeedResetTimer = 0;
    }
    OSi_EnterTimerCallback(0, OSi_CountUpTick, 0);
}

// Returns gTickOverflowCount shifted left by 16 plus the timer 0 count, adding 1 to the overflow count when an overflow
// is pending that the count does not yet include.
u64 OS_GetTick(void) {
    u32 enabled;
    volatile u16 count;
    volatile u64 overflows;

    enabled = OS_DisableInterrupts();
    count = reg_OS_TM0CNT_L;
    overflows = gTickOverflowCount & 0xffffffffffffULL;
    if ((reg_OS_IF & 8) && !(count & 0x8000)) {
        overflows++;
    }
    OS_RestoreInterrupts(enabled);
    return (overflows << 16) | count;
}

u32 OS_GetTickLo(void) {
    u32 timerCounter;
    timerCounter = reg_OS_TM0CNT_L;
    return timerCounter;
}
