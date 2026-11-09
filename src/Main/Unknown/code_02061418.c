#include "Main/Unknown/code_02061418.h"
#include "Main/Unknown/code_02036820.h"

Unk0206152c *CreateGhostFileRecords(void *heap) {
    void *value0 = heap;
    u32 size;
    u32 value12;
    value12 = (u32) &HeapAlloc;
    size = 0x4600u;
    value0 = HeapAlloc(value0, size);
    return value0;
}
