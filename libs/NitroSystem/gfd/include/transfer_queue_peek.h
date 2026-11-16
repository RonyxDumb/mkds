#pragma once

#include "types.h"
#include "transfer_task_types.h" // NNSGfdVramTransferTask

typedef struct NNSGfdVramTransferTaskQueue NNSGfdVramTransferTaskQueue;

NNSGfdVramTransferTask *StructTEQ_GetNextFreeTEQSub(NNSGfdVramTransferTaskQueue *queue);
NNSGfdVramTransferTask *StructTEQ_GetTopUsedTEQSub(NNSGfdVramTransferTaskQueue *queue);
