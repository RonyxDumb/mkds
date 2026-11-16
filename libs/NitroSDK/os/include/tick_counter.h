#pragma once

#include "types.h"

u32 OS_GetTickLo(void);

u64 Os_GetTick(void);
// Timer 0 interrupt handler: adds 1 to g_Os_TickCounter; when g_Os_NeedsTimerReset is nonzero (nothing sets it in
// this game) restarts timer 0 and clears the word; registers itself again for timer 0.
void Os_CountTicks(void);
// Returns g_Os_TickInitialized.
u32 Os_IsTickInitialized(void);
// Runs once: reserves timer 0 (Os_ReserveTimer), clears g_Os_TickCounter, stops timer 0, zeroes its count,
// starts it with control 0xc1, installs Os_CountTicks for IRQ bit 3 and enables it, clears g_Os_NeedsTimerReset.
void Os_InitializeTick(void);
