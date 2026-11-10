#pragma once

#include "types.h"

unsigned int RaceSetupCopyGetConnectionKind(void);
void RaceSetupCopyMI_CpuClearFast(void *destination, u32 size);
void RaceSetupCopyMI_CpuFillFast(void *destination, u32 value, u32 size);
void CreateRaceSetupCopy(void *heap);
