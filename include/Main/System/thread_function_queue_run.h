#pragma once

#include "types.h"

unsigned int GetThreadFunctionQueueRunRequested(void);

u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex);

void RequestThreadFunctionQueueRun(void);

extern s32 gCupPictureNitroOrRetroTable[1];
extern s32 gCupPictureNumberTable[81];
