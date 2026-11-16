#include "Main/System/heap_array_alloc.h"
#include "Main/System/heap.h"
#include "Main/System/current_heap.h"

#pragma optimize_for_size on

#pragma thumb on

void *AllocArrayFromCurrentHeap(s32 count, s32 elementSize) {
    void *memory;

    memory = NULL;
    if (count > 0) {
        memory = HeapAlloc((void *) GetCurrentHeap(), elementSize * count);
    }
    return memory;
}

#pragma thumb off
