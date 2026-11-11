#include "code_02016468.h"

#include "code_02016574.h"
#include "code_020165d8.h"
#include "code_02016638.h"
#include "code_020165b8.h"
#include "code_0201661c.h"

NNSGfdVramTransferTaskQueue data_02173220;

void NNS_GfdInitVramTransferManager(NNSGfdVramTransferTask *pTaskArray, u32 lengthOfArray) {
    data_02173220.mPTaskArray = pTaskArray;
    data_02173220.mLengthOfArray = lengthOfArray;
    ResetTaskQueue_(&data_02173220);
}

void NNS_GfdDoVramTransfer(void) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &data_02173220;
    task = NNSi_GfdGetFrontVramTransferTaskQueue(queue);
    while (NNSi_GfdPopVramTransferTaskQueue(queue) != 0) {
        DoTransfer_(task);
        queue->mTotalSize -= task->mSzByte;
        task = NNSi_GfdGetFrontVramTransferTaskQueue(queue);
    }
}

s32 NNS_GfdRegisterNewVramTransferTask(u32 type, u32 dstAddr, void *pSrc, u32 szByte) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &data_02173220;
    if (IsVramTransferTaskQueueFull_(queue) != 0) {
        return 0;
    }
    task = NNSi_GfdGetEndVramTransferTaskQueue(queue);
    task->mType = type;
    task->mPSrc = pSrc;
    task->mDstAddr = dstAddr;
    task->mSzByte = szByte;
    NNSi_GfdPushVramTransferTaskQueue(queue);
    queue->mTotalSize = queue->mTotalSize + task->mSzByte;
    return 1;
}
