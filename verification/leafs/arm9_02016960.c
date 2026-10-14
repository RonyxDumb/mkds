/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsVramTransferTaskQueueFull_ StructTEQ_IsTEQSubListFull
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>

#pragma thumb off
BOOL IsVramTransferTaskQueueFull_ (const NNSGfdVramTransferTaskQueue * pQueue)
{
    return (pQueue->numTasks == pQueue->lengthOfArray) ? TRUE: FALSE;
}
