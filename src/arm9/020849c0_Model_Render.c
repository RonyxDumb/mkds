/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_FndFreeToExpHeap SDK_data_020130d4
#define AllocatorFreeForExpHeap Model_Render
#include "nitro.h"
#include "NNS_FND_allocator.h"
#include "NNS_FND_expheap.h"
#include "code32.h"

void AllocatorFreeForExpHeap(NNSFndAllocator * pAllocator, void *memBlock)
{
    NNS_FndFreeToExpHeap(pAllocator->pHeap, memBlock);
}
