#pragma once

#include "types.h"
#include "code_0200e77c.h"

// Threads sleeping until an interrupt flag is set.
extern OSThreadQueue OSi_IrqThreadQueue;

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void OS_WaitIrq(u32 clear, u32 irqFlags);
