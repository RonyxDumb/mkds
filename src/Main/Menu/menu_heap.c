#include "Main/Menu/menu_heap.h"
#include "Main/System/heap_call.h"

void *MenuGetCurrentHeap(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}
