#include "heap_list_common_head.h"
#include "linked_list_ops.h"
#include "linked_list_init.h"

u32 g_GlobalMemUnkInit;
NNSFndList g_GlobalHeapHeadList;

// Returns the innermost heap in list whose memory contains memBlock, looking into the child lists first.
NNSiFndHeapHead *Mem_FindTopParentHeapHead(NNSFndList *list, const void *memBlock) {
    NNSiFndHeapHead *candidate;
    NNSiFndHeapHead *child;

    candidate = IntrusiveListWrapper_NextItem(list, 0);
    while (candidate != 0) {
        if (candidate->mHeapStart <= memBlock && memBlock < candidate->mHeapEnd) {
            child = Mem_FindTopParentHeapHead(&candidate->mChildList, memBlock);
            if (child == 0) {
                child = candidate;
            }
            return child;
        }
        candidate = IntrusiveListWrapper_NextItem(list, candidate);
    }
    return 0;
}

// Returns the child list of the heap that contains heap, or the root list.
NNSFndList *Mem_FindTopParentHeapHeadList(NNSiFndHeapHead *heap) {
    NNSFndList *list;
    NNSiFndHeapHead *container;

    list = &g_GlobalHeapHeadList;
    container = Mem_FindTopParentHeapHead(list, heap);
    if (container != 0) {
        list = &container->mChildList;
    }
    return list;
}

// Fills in the heap header and links the heap into the child list of the heap that contains it.
void Mem_InitializeHeapHead(NNSiFndHeapHead *heap, u32 signature, void *heapStart, void *heapEnd, u16 optFlag) {
    heap->mSignature = signature;
    heap->mHeapStart = heapStart;
    heap->mHeapEnd = heapEnd;
    heap->mAttribute = 0;
    heap->mAttribute &= ~0xff;
    heap->mAttribute |= optFlag & 0xff;
    IntrusiveListWrapper_InitializeEmpty(&heap->mChildList, 4);
    if (g_GlobalMemUnkInit == 0) {
        IntrusiveListWrapper_InitializeEmpty(&g_GlobalHeapHeadList, 4);
        g_GlobalMemUnkInit = 1;
    }
    IntrusiveListWrapper_InsertLast(Mem_FindTopParentHeapHeadList(heap), heap);
}

// Removes the heap from the list of the heap that contains it.
void Mem_FinalizeHeapHead(NNSiFndHeapHead *heap) {
    IntrusiveListWrapper_RemoveItem(Mem_FindTopParentHeapHeadList(heap), heap);
}

// Returns the innermost heap whose memory contains memBlock.
NNSFndHeapHandle Mem_FindGlobalTopParentHeapHead(const void *memBlock) {
    return Mem_FindTopParentHeapHead(&g_GlobalHeapHeadList, memBlock);
}
