#include "code_02016574.h"
#include "code_02016638.h"

s32 NNSi_GfdPopVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *p) {
    if (IsVramTransferTaskQueueEmpty_(p) != 0) {
        return 0;
    }
    p->mIdxFront = GetNextIndex_(p, p->mIdxFront);
    p->mNumTasks -= 1;
    return 1;
}
