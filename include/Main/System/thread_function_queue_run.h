#pragma once

#include "types.h"

unsigned int WorkerHasPendingTask(void);

u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex);

void WorkerNotifyTaskPending(void);

extern s32 gCupPictureNitroOrRetroTable[1];
extern s32 gCupPictureNumberTable[81];
