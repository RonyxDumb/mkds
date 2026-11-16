#pragma once

#include "types.h"
#include "thread_mutex_types.h"

// Threads sleeping until an interrupt flag is set.
extern OSThreadQueue g_DTCM;

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void WaitForIRQ(u32 clear, u32 irqFlags);
