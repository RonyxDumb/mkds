/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_FndInitList IntrusiveListWrapper_InitializeEmpty
#define FindListContainHeap Mem_FindTopParentHeapHeadList
#define NNS_FndAppendListObject IntrusiveListWrapper_InsertLast
#define sRootListInitialized SDK_data_02173264
#define sRootList SDK_data_02173268
#define NNSi_FndInitHeapHead Mem_InitializeHeapHead
#include "nitro.h"
#include "NNS_FND_heapcommon.h"
#include "NNS_FND_list.h"
#include "code32.h"
extern NNSFndList* FindListContainHeap(const void * memBlock);
extern BOOL sRootListInitialized;
extern NNSFndList sRootList;
void NNSi_FndInitHeapHead(NNSiFndHeapHead *pHead, u32 signature, void* heapStart, void* heapEnd, u16 optionFlag)
{
    pHead->signature = signature;
    pHead->heapStart = heapStart;
    pHead->heapEnd = heapEnd;
    pHead->attribute = 0;
    SetOptForHeap(pHead, optionFlag);
    NNS_FndInitList(&pHead->childList, 4);
    if (!sRootListInitialized)
    {
        NNS_FndInitList(&sRootList, 4);
        sRootListInitialized = TRUE;
    }
    NNS_FndAppendListObject(FindListContainHeap(pHead), pHead);
}
