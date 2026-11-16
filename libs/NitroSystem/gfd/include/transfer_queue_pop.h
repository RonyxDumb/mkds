#pragma once

#include "types.h"

typedef struct NNSGfdVramTransferTaskQueue NNSGfdVramTransferTaskQueue;

s32 StructTEQ_TryPopTEQSub(NNSGfdVramTransferTaskQueue *queue);
