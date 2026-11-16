#include "Main/System/heap_array_alloc.h"
#include "Main/System/heap.h"
#include "Main/System/current_heap.h"

#pragma optimize_for_size on

#pragma thumb on

void *AllocateActiveHeapSizeCount_from_thumb(s32 count, s32 elementSize) {
    void *memory;

    memory = NULL;
    if (count > 0) {
        memory = Mem_AllocateHeap((void *) GetActiveExecutionContextHeapHandle_1(), elementSize * count);
    }
    return memory;
}

#pragma thumb off
