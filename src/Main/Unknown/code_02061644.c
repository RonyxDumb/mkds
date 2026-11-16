#include "Main/Unknown/code_02061644.h"
#include "Main/System/Heap.h"

u32 ghdat_allocPersonalGhostsStruct(u32 heap) {
    u32 value0 = heap;
    u32 size;
    u32 value12;
    value12 = (u32) &heap_alloc;
    size = 0x600u;
    value0 = (u32) heap_alloc((void *) value0, size);
    return value0;
}
