#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"


void *GetArenaHeap(void);
void RunRootHeapCall(u32 func);
void InitStartup(void);
void GetArenaLoHiNop(void);
void InitStartupLibraries(void);
void EnableVBlankIrq(void);
void VBlankIrqHandler(void);

extern struct DisplaySettings *gDisplaySettings;
