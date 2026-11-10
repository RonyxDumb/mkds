#include "code_020165d8.h"
#include "code_02016638.h"

s32 NNSi_GfdPushVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *p) {
    if (IsVramTransferTaskQueueFull_(p) != 0) {
        return 0;
    }
    p->mIdxRear = GetNextIndex_(p, p->mIdxRear);
    p->mNumTasks += 1;
    return 1;
}
