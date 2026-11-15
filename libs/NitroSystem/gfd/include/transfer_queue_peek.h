#pragma once

#include "types.h"
#include "transfer_task_types.h" // NNSGfdVramTransferTask

typedef struct NNSGfdVramTransferTaskQueue NNSGfdVramTransferTaskQueue;

NNSGfdVramTransferTask *NNSi_GfdGetEndVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue);
NNSGfdVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue);
