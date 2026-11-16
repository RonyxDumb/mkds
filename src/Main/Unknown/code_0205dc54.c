#include "Main/Unknown/code_0205dc54.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_0217a000.h"

u32 rres_init(void *heap) {
    u32 value0 = (u32) heap;
    u32 value1;
    value1 = 0x168u;
    value0 = (u32) heap_alloc((void *) value0, value1);
    value1 = (u32) &rres_sRaceResults;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
