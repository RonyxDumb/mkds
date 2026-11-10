#pragma once

#include "types.h"

// Declared here until the code that defines it is decompiled.

void *GetArenaHeap(void);
void RunRootHeapCall(u32 func);
void InitStartup(void);
void GetArenaLoHiNop(void);
void InitStartupLibraries(void);
void EnableVBlankIrq(void);
void VBlankIrqHandler(void);
