/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AllocFromHead Mem_Exp_AllocFromHead
#define AllocFromTail Mem_Exp_AllocFromTail
#define NNS_FndAllocFromExpHeapEx Mem_Exp_Allocate
#include "nitro/types.h"
#include "NNS_FND_expheap.h"
#include "code32.h"
extern void* AllocFromHead(NNSiFndHeapHead* pHeapHd, u32 size, int alignment);
extern void* AllocFromTail(NNSiFndHeapHead* pHeapHd, u32 size, int alignment);
void* NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle handle, u32 size, int alignment)
{
    if (size == 0)
        size = 1;
    size = NNSi_FndRoundUp(size, 4);
    if (alignment >= 0)
        return AllocFromHead(handle, size, alignment);
    else
        return AllocFromTail(handle, size, -alignment);
}
