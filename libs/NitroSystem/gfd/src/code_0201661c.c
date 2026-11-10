#include "code_0201661c.h"
#include "code_02016638.h"

void ResetTaskQueue_(NNSGfdVramTransferTaskQueue *queue) {
    u32 zero;
    zero = 0u;
    queue->mIdxRear = zero;
    queue->mIdxFront = queue->mIdxRear;
    queue->mNumTasks = zero;
    queue->mTotalSize = zero;
}
