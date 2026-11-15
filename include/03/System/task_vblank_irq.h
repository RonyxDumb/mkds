#pragma once

#include "types.h"
#include "interrupt_control.h"

void TaskVBlankIrqHandler(void);
void RestoreTaskVBlankIrq(void);
void EnableTaskVBlankIrq(void);

extern u32 gSavedIrqMask;
extern OSIrqFunction gSavedIrqFunction;
