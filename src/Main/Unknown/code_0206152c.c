#include "Main/Unknown/code_0206152c.h"
#include "Main/System/Heap.h"

u32 ghdat_allocDownloadGhostsStruct(u32 heap) {
    u32 value0 = heap;
    u32 value1;
    u32 value12;
    value12 = (u32) &heap_alloc;
    value1 = 0x15e0u;
    value0 = (u32) heap_alloc((void *) value0, value1);
    return value0;
}
