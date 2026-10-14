/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define s_VramTransferManager SDK_data_02173220
#define ResetTaskQueue_ SDK_data_0201661c
#define NNS_GfdInitVramTransferManager InitializeGlobalTEQ
#include <nnsys/gfd/VramTransferMan/gfd_VramTransferManager.h>
extern NNSGfdVramTransferManager s_VramTransferManager;
extern void ResetTaskQueue_ (NNSGfdVramTransferTaskQueue * pQueue);
#pragma thumb off
void NNS_GfdInitVramTransferManager (NNSGfdVramTransferTask * pTaskArray, u32 lengthOfArray)
{
    NNS_GFD_NULL_ASSERT(pTaskArray);
    NNS_GFD_NON_ZERO_ASSERT(lengthOfArray);

    {
        NNSGfdVramTransferManager * pMan = &s_VramTransferManager;

        pMan->taskQueue.pTaskArray = pTaskArray;
        pMan->taskQueue.lengthOfArray = lengthOfArray;

        ResetTaskQueue_(&pMan->taskQueue);
    }
}
