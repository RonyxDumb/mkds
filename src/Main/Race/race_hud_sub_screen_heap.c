#include "Main/Race/race_hud_sub_screen_heap.h"
#include "Main/System/heap_call.h"

void *RaceHudSubScreenGetCurrentHeap(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}
