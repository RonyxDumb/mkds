#include "Main/System/heap.h"
#include "expanded_heap_head.h"
#include "heap_frame_allocator.h"
#include "heap_list_common_head.h"
#include "reset_interrupts_halt.h"

void *Mem_AllocateHeap(void *heap, u32 size) {
    NNSiFndHeapHead *heapHead = heap;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(heap, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = Mem_Frame_Allocate(heap, size, 4);
            break;
    }
    return block;
}

void *Mem_AllocateHeapAligned(void *heap, u32 size, s32 alignment) {
    NNSiFndHeapHead *heapHead = heap;
    void *block = NULL;
    u32 irqState;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(heap, size, alignment);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            irqState = Os_DisableIrq();
            block = Mem_Frame_Allocate(heap, size, alignment);
            Os_RestoreIrq(irqState);
            break;
    }
    return block;
}

void Mem_FreeHeap(void *heap, void *block) {
    NNSiFndHeapHead *heapHead = heap;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            Mem_Exp_Free(heap, block);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            break;
    }
}

void Mem_DestroyHeap(NNSiFndHeapHead *heap) {
    NNSiFndHeapHead *heapHead = heap;
    NNSiFndHeapHead *parentHeap;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            Mem_Exp_Finalize(heap);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            Mem_Frame_Finalize(heap);
            break;
    }
    parentHeap = Mem_FindGlobalTopParentHeapHead(heap);
    if (parentHeap == NULL) {
        return;
    }
    switch (parentHeap->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            Mem_Exp_Free(parentHeap, heap);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            break;
    }
}

void *Mem_CreateChildExpHeap(void *parent) {
    NNSiFndHeapHead *heapHead = parent;
    u32 size = 0;
    void *block;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            size = Mem_Exp_GetAllocatableSize(parent, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            size = Mem_Frame_GetAllocatableSize(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = Mem_Frame_Allocate(parent, size, 4);
            break;
    }
    return Mem_Exp_Create(block, size, 1);
}

void *Mem_CreateOrphanChildHeap(void *parent) {
    NNSiFndHeapHead *heapHead = parent;
    u32 size = 0;
    void *block;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            size = Mem_Exp_GetAllocatableSize(parent, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            size = Mem_Frame_GetAllocatableSize(parent, 4);
            break;
    }
    block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = Mem_Frame_Allocate(parent, size, 4);
            break;
    }
    return Mem_Frame_Create(block, size, 1);
}

void *Mem_CreateChildFrameHeapFromHead(void *parent, u32 size) {
    NNSiFndHeapHead *heapHead = parent;
    void *block = NULL;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(parent, size, 4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            block = Mem_Frame_Allocate(parent, size, 4);
            break;
    }
    return Mem_Frame_Create(block, size, 1);
}

void *Mem_CreateChildFrameHeapFromTail(void *parent, u32 size) {
    NNSiFndHeapHead *heapHead = parent;
    void *block = NULL;
    u32 irqState;
    switch (heapHead->mSignature) {
        case HEAP_SIGNATURE_EXP_HEAP:
            block = Mem_Exp_Allocate(parent, size, -4);
            break;
        case HEAP_SIGNATURE_FRAME_HEAP:
            irqState = Os_DisableIrq();
            block = Mem_Frame_Allocate(parent, size, -4);
            Os_RestoreIrq(irqState);
            break;
    }
    return Mem_Frame_Create(block, size, 1);
}

void FrmHeapShrinkInParent(void *heap) {
    u32 newSize = Mem_Frame_SomeFn4(heap);
    Mem_ResizeExpHeap(Mem_FindGlobalTopParentHeapHead(heap), heap, newSize);
}
