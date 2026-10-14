/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_GfdGetFrontVramTransferTaskQueue StructTEQ_GetTopUsedTEQSub
#define NNSi_GfdPopVramTransferTaskQueue StructTEQ_TryPopTEQSub
#define DoTransfer_ StructTEQSub_HandleTEQSub
#define s_VramTransferManager SDK_data_02173220
#define NNS_GfdDoVramTransfer HandleAllGlobalTEQSubs
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>
extern NNSGfdVramTransferTask * NNSi_GfdGetFrontVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue);
extern BOOL NNSi_GfdPopVramTransferTaskQueue (NNSGfdVramTransferTaskQueue * pQueue);
extern void DoTransfer_ (const NNSGfdVramTransferTask * pTask);
extern NNSGfdVramTransferManager s_VramTransferManager;
#pragma thumb off
void NNS_GfdDoVramTransfer (void)
{
    NNSGfdVramTransferManager * pMan = &s_VramTransferManager;
    NNSGfdVramTransferTask * pTask = NNSi_GfdGetFrontVramTransferTaskQueue(&pMan->taskQueue);

    while ( NNSi_GfdPopVramTransferTaskQueue(&pMan->taskQueue))
    {
        DoTransfer_(pTask);

        pMan->taskQueue.totalSize -= pTask->szByte;
        pTask = NNSi_GfdGetFrontVramTransferTaskQueue(&pMan->taskQueue);
    }
}
