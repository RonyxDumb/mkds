/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsVramTransferTaskQueueFull_ StructTEQ_IsTEQSubListFull
#define GetNextIndex_ StructTEQ_IncrementValidateIndex
#define NNSi_GfdPushVramTransferTaskQueue StructTEQ_ReserveTEQSub
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>
extern BOOL IsVramTransferTaskQueueFull_ (const NNSGfdVramTransferTaskQueue * pQueue);
extern u16 GetNextIndex_ (const NNSGfdVramTransferTaskQueue * pQueue, u16 idx);
#pragma thumb off
BOOL NNSi_GfdPushVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue)
{
    NNS_GFD_NULL_ASSERT(pQueue);

    if ( !IsVramTransferTaskQueueFull_(pQueue)) {
        pQueue->idxRear = GetNextIndex_(pQueue, pQueue->idxRear);
        pQueue->numTasks++;
        return TRUE;
    } else {
        return FALSE;
    }
}
