#include "Main/Unknown/code_0206152c.h"
#include "Main/System/Heap.h"

u32 CreateSlotGhostRecords(u32 heap) {
    u32 value0 = heap;
    u32 value1;
    u32 value12;
    value12 = (u32) &HeapAlloc;
    value1 = 0x15e0u;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    return value0;
}
