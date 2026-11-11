#include "code_02016574.h"
#include "code_02016638.h"

s32 NNSi_GfdPopVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    if (IsVramTransferTaskQueueEmpty_(queue) != 0) {
        return 0;
    }
    queue->mIdxFront = GetNextIndex_(queue, queue->mIdxFront);
    queue->mNumTasks -= 1;
    return 1;
}
