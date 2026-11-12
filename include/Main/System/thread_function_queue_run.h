#pragma once

#include "types.h"

unsigned int GetThreadFunctionQueueRunRequested(void);

u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex);

void RequestThreadFunctionQueueRun(void);
