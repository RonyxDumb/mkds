/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsVramTransferTaskQueueEmpty_ StructTEQ_IsCounterEmpty
#define GetNextIndex_ StructTEQ_IncrementValidateIndex
#define NNSi_GfdPopVramTransferTaskQueue StructTEQ_TryPopTEQSub
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>
extern BOOL IsVramTransferTaskQueueEmpty_ (const NNSGfdVramTransferTaskQueue * pQueue);
extern u16 GetNextIndex_ (const NNSGfdVramTransferTaskQueue * pQueue, u16 idx);
#pragma thumb off
BOOL NNSi_GfdPopVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue)
{
    NNS_GFD_NULL_ASSERT(pQueue);

    if ( !IsVramTransferTaskQueueEmpty_(pQueue)) {
        pQueue->idxFront = GetNextIndex_(pQueue, pQueue->idxFront);
        pQueue->numTasks--;
        return TRUE;
    } else {
        return FALSE;
    }
}
