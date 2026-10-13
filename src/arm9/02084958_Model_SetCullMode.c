/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_FndFreeToExpHeap SDK_data_0201311c
#define AllocatorFreeForExpHeap Model_SetCullMode
#include "nitro.h"
#include "NNS_FND_allocator.h"
#include "NNS_FND_expheap.h"
#include "code32.h"

void AllocatorFreeForExpHeap(NNSFndAllocator * pAllocator, void *memBlock)
{
    NNS_FndFreeToExpHeap(pAllocator->pHeap, memBlock);
}
