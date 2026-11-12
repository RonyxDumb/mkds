#pragma once

#include "types.h"

void TaskVBlankIrqHandler(void);
void RestoreTaskVBlankIrq(void);
void EnableTaskVBlankIrq(void);

extern u32 gSavedIrqMask;
extern UnkFunc *gSavedIrqFunction;
