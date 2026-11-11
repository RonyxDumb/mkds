#include "Main/Unknown/code_02036820.h"
#include "code_020176c0.h"
#include "frameheap.h"
#include "heapcommon.h"
#include "code_0200fc8c.h"

void *HeapAlloc(void *heap, u32 size) {
    NNSiFndHeapHead *heapHead = heap;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(heap, size, 4);
            break;
        case 0x46524d48:
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
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(heap, size, alignment);
            break;
        case 0x46524d48:
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
        case 0x45585048:
            NNS_FndFreeToExpHeap(heap, block);
            break;
        case 0x46524d48:
            break;
    }
}

void HeapDestroy(NNSiFndHeapHead *heap) {
    NNSiFndHeapHead *heapHead = heap;
    NNSiFndHeapHead *parentHeap;
    switch (heapHead->mSignature) {
        case 0x45585048:
            NNS_FndDestroyExpHeap(heap);
            break;
        case 0x46524d48:
            NNS_FndDestroyFrmHeap(heap);
            break;
    }
    parentHeap = NNS_FndFindContainHeap(heap);
    if (parentHeap == NULL) {
        return;
    }
    switch (parentHeap->mSignature) {
        case 0x45585048:
            NNS_FndFreeToExpHeap(parentHeap, heap);
            break;
        case 0x46524d48:
            break;
    }
}

void *CreateExpHeapFromMaxFree(void *parent) {
    NNSiFndHeapHead *heapHead = parent;
    u32 size = 0;
    void *block;
    switch (heapHead->mSignature) {
        case 0x45585048:
            size = NNS_FndGetAllocatableSizeForExpHeapEx(parent, 4);
            break;
        case 0x46524d48:
            size = NNS_FndGetAllocatableSizeForFrmHeapEx(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case 0x46524d48:
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
        case 0x45585048:
            size = NNS_FndGetAllocatableSizeForExpHeapEx(parent, 4);
            break;
        case 0x46524d48:
            size = NNS_FndGetAllocatableSizeForFrmHeapEx(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case 0x46524d48:
            block = NNS_FndAllocFromFrmHeapEx(parent, size, 4);
            break;
    }
    return NNS_FndCreateFrmHeapEx(block, size, 1);
}

void *CreateFrmHeapFromFront(void *parent, u32 size) {
    NNSiFndHeapHead *heapHead = parent;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(parent, size, 4);
            break;
        case 0x46524d48:
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
        case 0x45585048:
            block = NNS_FndAllocFromExpHeapEx(parent, size, -4);
            break;
        case 0x46524d48:
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
