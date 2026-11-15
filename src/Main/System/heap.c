#include "Main/System/heap.h"
#include "expanded_heap_head.h"
#include "frameheap.h"
#include "heapcommon.h"
#include "reset_interrupt_enable.h"

void *HeapAlloc(void *heap, u32 size) {
    NNSiFndHeapHead *heapHead = heap;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(heap, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = NNS_FndAllocFromFrmHeapEx(heap, size, 4);
            break;
    }
    return block;
}

void *HeapAllocAligned(void *heap, u32 size, s32 alignment) {
    NNSiFndHeapHead *heapHead = heap;
    void *block = NULL;
    u32 irqState;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(heap, size, alignment);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            irqState = OS_DisableInterrupts();
            block = NNS_FndAllocFromFrmHeapEx(heap, size, alignment);
            OS_RestoreInterrupts(irqState);
            break;
    }
    return block;
}

void HeapFree(void *heap, void *block) {
    NNSiFndHeapHead *heapHead = heap;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            NNS_FndFreeToExpHeap(heap, block);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            break;
    }
}

void HeapDestroy(NNSiFndHeapHead *heap) {
    NNSiFndHeapHead *heapHead = heap;
    NNSiFndHeapHead *parentHeap;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            NNS_FndDestroyExpHeap(heap);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            NNS_FndDestroyFrmHeap(heap);
            break;
    }
    parentHeap = NNS_FndFindContainHeap(heap);
    if (parentHeap == NULL) {
        return;
    }
    switch (parentHeap->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            NNS_FndFreeToExpHeap(parentHeap, heap);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            break;
    }
}

void *CreateExpHeapFromMaxFree(void *parent) {
    NNSiFndHeapHead *heapHead = parent;
    u32 size = 0;
    void *block;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            size = NNS_FndGetAllocatableSizeForExpHeapEx(parent, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            size = NNS_FndGetAllocatableSizeForFrmHeapEx(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = NNS_FndAllocFromFrmHeapEx(parent, size, 4);
            break;
    }
    return NNS_FndCreateExpHeapEx(block, size, 1);
}

void *CreateFrmHeapFromMaxFree(void *parent) {
    NNSiFndHeapHead *heapHead = parent;
    u32 size = 0;
    void *block;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            size = NNS_FndGetAllocatableSizeForExpHeapEx(parent, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            size = NNS_FndGetAllocatableSizeForFrmHeapEx(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = NNS_FndAllocFromFrmHeapEx(parent, size, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(block, size, 1);
}

void *CreateFrmHeapFromFront(void *parent, u32 size) {
    NNSiFndHeapHead *heapHead = parent;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = NNS_FndAllocFromFrmHeapEx(parent, size, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(block, size, 1);
}

void *CreateFrmHeapFromBack(void *parent, u32 size) {
    NNSiFndHeapHead *heapHead = parent;
    void *block = NULL;
    u32 irqState;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = NNS_FndAllocFromExpHeapEx(parent, size, -4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            irqState = OS_DisableInterrupts();
            block = NNS_FndAllocFromFrmHeapEx(parent, size, -4);
            OS_RestoreInterrupts(irqState);
            break;
    }
    return NNS_FndCreateFrmHeapEx(block, size, 1);
}

void FrmHeapShrinkInParent(void *heap) {
    u32 newSize = NNS_FndAdjustFrmHeap(heap);
    NNS_FndResizeForMBlockExpHeap(NNS_FndFindContainHeap(heap), heap, newSize);
}
