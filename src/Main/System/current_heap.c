#include "Main/System/current_heap.h"
#include "Main/System/heap_call.h"

u32 GetCurrentHeap(void) {
    u32 heap;
    heap = (u32) GetCurrentHeapCall();
    heap = (u32) GetHeap((void *) heap);
    return heap;
}
