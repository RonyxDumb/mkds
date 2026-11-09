#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02036820.h"

Unk0206152c *CreateSlotGhostRecords(void *heap) {
    void *value0 = heap;
    u32 value1;
    u32 value12;
    value12 = (u32) &HeapAlloc;
    value1 = 0x15e0u;
    value0 = HeapAlloc(value0, value1);
    return value0;
}
