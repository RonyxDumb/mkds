#pragma once

#include "types.h"
#include "code_0200c914.h"

void TaskVBlankIrqHandler(void);
void RestoreTaskVBlankIrq(void);
void EnableTaskVBlankIrq(void);

extern u32 gSavedIrqMask;
extern OSIrqFunction gSavedIrqFunction;
