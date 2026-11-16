#include "03/System/exp_heap.h"

#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "expanded_heap_head.h"
#include "cpu_copy_fill.h"

NNSiFndHeapHead *gExpHeap;

void CreateExpHeapOverBuffer(void *buffer) {
    Mem_CpuFill8(buffer, 0, EXP_HEAP_BYTES);
    gExpHeap = Mem_Exp_Create(buffer, EXP_HEAP_BYTES, 0);
    if (gExpHeap == NULL) {
        Os_Terminate();
    }
}

void ReleaseExpHeap(void) {
    Mem_Exp_Finalize(gExpHeap);
    gExpHeap = NULL;
}

void *AllocExpHeapBlock(u32 size, s32 alignment) {
    u32 interrupts = Os_DisableIrqHandler(1);
    void *block = Mem_Exp_Allocate(gExpHeap, size, alignment);

    if (block == NULL) {
        Os_Terminate();
    }
    Os_EnableIrqHandler(interrupts);
    return block;
}

void *AllocZeroedExpHeapBlock(u32 size, s32 alignment) {
    void *block = AllocExpHeapBlock(size, alignment);

    Mem_CpuFill8(block, 0, size);
    return block;
}

void FreeExpHeapBlockAndClearPointer(void *storage) {
    void **block = storage;
    u32 interrupts = Os_DisableIrqHandler(1);

    if (*block != NULL) {
        Mem_Exp_Free(gExpHeap, *block);
        Os_EnableIrqHandler(interrupts);
        *block = NULL;
    }
}

void FreeExpHeapBlock(void *block) {
    u32 interrupts = Os_DisableIrqHandler(1);

    if (block != NULL) {
        Mem_Exp_Free(gExpHeap, block);
        Os_EnableIrqHandler(interrupts);
    }
}
