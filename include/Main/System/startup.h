#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"


void *GetGlobalHeapHandle(void);
void SetExecuteStart(u32 func);
void InitializeEverything(void);
void MemoryRegionAddressAccess(void);
void InitializeSDKModules(void);
void EnableVblankIRQ(void);
void VblankIRQHandler(void);

extern struct DisplaySettings *g_GlobalDisplayConfig;
