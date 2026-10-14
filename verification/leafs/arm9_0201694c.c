/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsVramTransferTaskQueueEmpty_ StructTEQ_IsCounterEmpty
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>

#pragma thumb off
BOOL IsVramTransferTaskQueueEmpty_ (const NNSGfdVramTransferTaskQueue * pQueue)
{
    return (pQueue->numTasks == 0) ? TRUE: FALSE;
}
