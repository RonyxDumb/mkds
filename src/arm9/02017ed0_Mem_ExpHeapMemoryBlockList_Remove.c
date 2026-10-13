/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RemoveMBlock Mem_ExpHeapMemoryBlockList_Remove
#include "nitro/types.h"
#include "NNS_FND_expheap.h"
#include "code32.h"

NNSiFndExpHeapMBlockHead* RemoveMBlock(NNSiFndExpMBlockList* list, NNSiFndExpHeapMBlockHead* block)
{
    NNSiFndExpHeapMBlockHead* const prev = block->pMBHeadPrev;
    NNSiFndExpHeapMBlockHead* const next = block->pMBHeadNext;

    if (prev != NULL)
    {
        prev->pMBHeadNext = next;
    }
    else
    {
        list->head = next;
    }

    if (next != NULL)
    {
        next->pMBHeadPrev = prev;
    }
    else
    {
        list->tail = prev;
    }

    return prev;
}
