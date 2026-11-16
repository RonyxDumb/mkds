#include "03/System/exp_heap.h"

#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "expanded_heap_head.h"
#include "cpu_copy_fill.h"

NNSiFndHeapHead *gExpHeap;

void CreateExpHeapOverBuffer(void *buffer) {
    MI_CpuFill8(buffer, 0, EXP_HEAP_BYTES);
    gExpHeap = NNS_FndCreateExpHeapEx(buffer, EXP_HEAP_BYTES, 0);
    if (gExpHeap == NULL) {
        OS_Terminate();
    }
}

void ReleaseExpHeap(void) {
    NNS_FndDestroyExpHeap(gExpHeap);
    gExpHeap = NULL;
}

void *AllocExpHeapBlock(u32 size, s32 alignment) {
    u32 savedIrqMask = OS_DisableIrqMask(1);
    void *block = NNS_FndAllocFromExpHeapEx(gExpHeap, size, alignment);

    if (block == NULL) {
        OS_Terminate();
    }
    OS_EnableIrqMask(savedIrqMask);
    return block;
}

void *AllocZeroedExpHeapBlock(u32 size, s32 alignment) {
    void *block = AllocExpHeapBlock(size, alignment);

    MI_CpuFill8(block, 0, size);
    return block;
}

void FreeExpHeapBlockAndClearPointer(void *pointerAddress) {
    void **blockPointer = pointerAddress;
    u32 savedIrqMask = OS_DisableIrqMask(1);

    if (*blockPointer != NULL) {
        NNS_FndFreeToExpHeap(gExpHeap, *blockPointer);
        OS_EnableIrqMask(savedIrqMask);
        *blockPointer = NULL;
    }
}

void FreeExpHeapBlock(void *block) {
    u32 savedIrqMask = OS_DisableIrqMask(1);

    if (block != NULL) {
        NNS_FndFreeToExpHeap(gExpHeap, block);
        OS_EnableIrqMask(savedIrqMask);
    }
}
