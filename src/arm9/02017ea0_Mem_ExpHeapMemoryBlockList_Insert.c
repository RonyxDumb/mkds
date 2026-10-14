/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define InsertMBlock Mem_ExpHeapMemoryBlockList_Insert
#include "nitro/types.h"
#include "NNS_FND_expheap.h"
#include "code32.h"

NNSiFndExpHeapMBlockHead* InsertMBlock(NNSiFndExpMBlockList* list, NNSiFndExpHeapMBlockHead* target, NNSiFndExpHeapMBlockHead* prev)
{
    NNSiFndExpHeapMBlockHead* next;
    target->pMBHeadPrev = prev;
    if (prev != NULL)
    {
        next = prev->pMBHeadNext;
        prev->pMBHeadNext = target;
    }
    else
    {
        next = list->head;
        list->head = target;
    }
    target->pMBHeadNext = next;
    if (next != NULL)
    {
        next->pMBHeadPrev = target;
    }
    else
    {
        list->tail = target;
    }

    return target;
}
