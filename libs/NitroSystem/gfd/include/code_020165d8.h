#pragma once

#include "types.h"

typedef struct NNSGfdVramTransferTaskQueue NNSGfdVramTransferTaskQueue;

s32 NNSi_GfdPushVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue);
