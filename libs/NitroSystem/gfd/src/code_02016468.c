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
    NNSGfdVramTransferTaskQueue *p;
    NNSGfdVramTransferTask *e;

    p = &data_02173220;
    e = NNSi_GfdGetFrontVramTransferTaskQueue(p);
    while (NNSi_GfdPopVramTransferTaskQueue(p) != 0) {
        DoTransfer_(e);
        p->mTotalSize -= e->mSzByte;
        e = NNSi_GfdGetFrontVramTransferTaskQueue(p);
    }
}

s32 NNS_GfdRegisterNewVramTransferTask(u32 a, u32 b, void *c, u32 d) {
    NNSGfdVramTransferTaskQueue *p;
    NNSGfdVramTransferTask *e;

    p = &data_02173220;
    if (IsVramTransferTaskQueueFull_(p) != 0) {
        return 0;
    }
    e = NNSi_GfdGetEndVramTransferTaskQueue(p);
    e->mType = a;
    e->mPSrc = c;
    e->mDstAddr = b;
    e->mSzByte = d;
    NNSi_GfdPushVramTransferTaskQueue(p);
    p->mTotalSize = p->mTotalSize + e->mSzByte;
    return 1;
}
