#include "Main/Race/race_hud_sub_screen_heap.h"
#include "Main/System/heap_call.h"

void *RaceHudSubScreenGetCurrentHeap(void) {
    void *heap;
    heap = GetCurrentHeapCall();
    heap = GetHeap(heap);
    return heap;
}
