#include "Main/System/current_heap.h"
#include "Main/System/heap_call.h"

u32 GetActiveExecutionContextHeapHandle_1(void) {
    u32 heap;
    heap = (u32) GetActiveExecutionContext();
    heap = (u32) ExecutionContext_GetHeapHandle((void *) heap);
    return heap;
}
