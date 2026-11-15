#include "03/System/exp_heap.h"

#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

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
    u32 interrupts = OS_DisableIrqMask(1);
    void *block = NNS_FndAllocFromExpHeapEx(gExpHeap, size, alignment);

    if (block == NULL) {
        OS_Terminate();
    }
    OS_EnableIrqMask(interrupts);
    return block;
}

void *AllocZeroedExpHeapBlock(u32 size, s32 alignment) {
    void *block = AllocExpHeapBlock(size, alignment);

    MI_CpuFill8(block, 0, size);
    return block;
}

void FreeExpHeapBlockAndClearPointer(void *storage) {
    void **block = storage;
    u32 interrupts = OS_DisableIrqMask(1);

    if (*block != NULL) {
        NNS_FndFreeToExpHeap(gExpHeap, *block);
        OS_EnableIrqMask(interrupts);
        *block = NULL;
    }
}

void FreeExpHeapBlock(void *block) {
    u32 interrupts = OS_DisableIrqMask(1);

    if (block != NULL) {
        NNS_FndFreeToExpHeap(gExpHeap, block);
        OS_EnableIrqMask(interrupts);
    }
}
