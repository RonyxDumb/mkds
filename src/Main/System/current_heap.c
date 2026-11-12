#include "Main/System/current_heap.h"
#include "Main/System/heap_call.h"

u32 GetCurrentHeap(void) {
    u32 value0;
    value0 = (u32) GetCurrentHeapCall();
    value0 = (u32) GetHeap((void *) value0);
    return value0;
}
