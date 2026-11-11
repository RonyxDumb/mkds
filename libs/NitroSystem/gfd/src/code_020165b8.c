#include "code_020165b8.h"
#include "code_02016638.h"

NNSGfdVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxFront;
}

NNSGfdVramTransferTask *NNSi_GfdGetEndVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxRear;
}
