#include "Main/Menu/menu_heap.h"
#include "Main/System/heap_call.h"

void *MenuGetCurrentHeap(void) {
    void *heap;
    heap = GetCurrentHeapCall();
    heap = GetHeap(heap);
    return heap;
}
