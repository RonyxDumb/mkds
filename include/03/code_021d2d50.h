#pragma once

#include "types.h"

void InitKeyTouchInput(void);
void TaskVBlankIrqHandler(void);
void RestoreTaskVBlankIrq(void);
void EnableTaskVBlankIrq(void);
