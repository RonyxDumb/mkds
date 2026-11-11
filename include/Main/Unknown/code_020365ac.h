#pragma once

#include "types.h"


void *GetArenaHeap(void);
void RunRootHeapCall(u32 func);
void InitStartup(void);
void GetArenaLoHiNop(void);
void InitStartupLibraries(void);
void EnableVBlankIrq(void);
void VBlankIrqHandler(void);
