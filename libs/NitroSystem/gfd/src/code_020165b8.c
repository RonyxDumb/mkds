#include "code_020165b8.h"
#include "code_02016638.h"

NNSGfdVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *p) {
    return p->mPTaskArray + p->mIdxFront;
}

NNSGfdVramTransferTask *NNSi_GfdGetEndVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *arg0) {
    return arg0->mPTaskArray + arg0->mIdxRear;
}
