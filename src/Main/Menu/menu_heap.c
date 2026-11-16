#include "Main/Menu/menu_heap.h"
#include "Main/System/heap_call.h"

void *GetActiveExecutionContextHeapHandle(void) {
    void *heap;
    heap = GetActiveExecutionContext();
    heap = ExecutionContext_GetHeapHandle(heap);
    return heap;
}
