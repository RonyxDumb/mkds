#include "code_020165d8.h"
#include "code_02016638.h"

s32 NNSi_GfdPushVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    if (IsVramTransferTaskQueueFull_(queue) != 0) {
        return 0;
    }
    queue->mIdxRear = GetNextIndex_(queue, queue->mIdxRear);
    queue->mNumTasks += 1;
    return 1;
}
