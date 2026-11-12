#pragma once

#include "types.h"

u32 OS_GetTickLo(void);

u64 OS_GetTick(void);
// Timer 0 interrupt handler: adds 1 to gTickOverflowCount; when OSi_NeedResetTimer is nonzero (nothing sets it in
// this game) restarts timer 0 and clears the word; registers itself again for timer 0.
void OSi_CountUpTick(void);
// Returns gTickInitialized.
u32 OS_IsTickAvailable(void);
// Runs once: reserves timer 0 (OSi_SetTimerReserved), clears gTickOverflowCount, stops timer 0, zeroes its count,
// starts it with control 0xc1, installs OSi_CountUpTick for IRQ bit 3 and enables it, clears OSi_NeedResetTimer.
void OS_InitTick(void);
