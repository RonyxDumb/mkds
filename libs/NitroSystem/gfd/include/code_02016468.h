#pragma once

#include "types.h"
#include "code_02016638.h" // NNSGfdVramTransferTask

s32 CallQueueAppend(u32, u32, void *, u32);
void NNS_GfdDoVramTransfer(void);
void NNS_GfdInitVramTransferManager(NNSGfdVramTransferTask *pTaskArray, u32 lengthOfArray);
