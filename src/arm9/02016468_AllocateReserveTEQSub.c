/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsVramTransferTaskQueueFull_ StructTEQ_IsTEQSubListFull
#define NNSi_GfdGetEndVramTransferTaskQueue StructTEQ_GetNextFreeTEQSub
#define NNSi_GfdPushVramTransferTaskQueue StructTEQ_ReserveTEQSub
#define s_VramTransferManager SDK_data_02173220
#define NNS_GfdRegisterNewVramTransferTask AllocateReserveTEQSub
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>
extern BOOL IsVramTransferTaskQueueFull_ (const NNSGfdVramTransferTaskQueue * pQueue);
extern NNSGfdVramTransferTask * NNSi_GfdGetEndVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue);
extern BOOL NNSi_GfdPushVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue);
extern NNSGfdVramTransferManager s_VramTransferManager;
#pragma thumb off
BOOL NNS_GfdRegisterNewVramTransferTask (NNS_GFD_DST_TYPE type, u32 dstAddr, void * pSrc, u32 szByte)
{
    NNSGfdVramTransferManager * pMan = &s_VramTransferManager;

    if ( !IsVramTransferTaskQueueFull_(&pMan->taskQueue)) {
        NNSGfdVramTransferTask * pTask =
            NNSi_GfdGetEndVramTransferTaskQueue(&pMan->taskQueue);

        pTask->type = type;
        pTask->pSrc = pSrc;
        pTask->dstAddr = dstAddr;
        pTask->szByte = szByte;

        (void)NNSi_GfdPushVramTransferTaskQueue(&pMan->taskQueue);

        pMan->taskQueue.totalSize += pTask->szByte;

        return TRUE;
    }

    return FALSE;
}
