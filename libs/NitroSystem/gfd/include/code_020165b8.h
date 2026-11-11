#pragma once

#include "types.h"
#include "code_02016638.h" // NNSGfdVramTransferTask

typedef struct NNSGfdVramTransferTaskQueue NNSGfdVramTransferTaskQueue;

NNSGfdVramTransferTask *NNSi_GfdGetEndVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue);
NNSGfdVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue);
