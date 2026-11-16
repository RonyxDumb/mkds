#include "Main/Race/race_hud_sub_screen_heap.h"
#include "Main/System/heap_call.h"

void *GetActiveExecutionContextHeapHandle_2(void) {
    void *heap;
    heap = GetActiveExecutionContext();
    heap = ExecutionContext_GetHeapHandle(heap);
    return heap;
}
