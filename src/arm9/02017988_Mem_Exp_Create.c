/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define InitExpHeap Mem_Exp_Initialize
#define NNS_FndCreateExpHeapEx Mem_Exp_Create
#include "nitro/types.h"
#include "NNS_FND_expheap.h"
#include "code32.h"
extern NNSiFndHeapHead* InitExpHeap(void* startAddress, void* endAddress, u16 optFlag);
NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag)
{
    void* endAddress = NNSi_FndRoundDownPtr(AddU32ToPtr(startAddress, size), 4);
    startAddress = NNSi_FndRoundUpPtr(startAddress, 4);
    if (NNSiGetUIntPtr(startAddress) > NNSiGetUIntPtr(endAddress) || GetOffsetFromPtr(startAddress, endAddress) < sizeof(NNSiFndHeapHead) + sizeof(NNSiFndExpHeapHead) + sizeof(NNSiFndExpHeapMBlockHead) + 4)
        return NULL;
    return InitExpHeap(startAddress, endAddress, optFlag);
}
