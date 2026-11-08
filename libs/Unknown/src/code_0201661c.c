#include "code_0201661c.h"
#include "code_02016638.h"

void CallQueueReset(CallQueue *queue) {
    u32 zero;
    zero = 0u;
    queue->mTailIndex = zero;
    queue->mHeadIndex = queue->mTailIndex;
    queue->mCount = zero;
    queue->mQueuedSize = zero;
}
