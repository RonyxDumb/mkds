#include "03/code_021c28f8.h"
#include "03/code_021d27d8.h"

u32 AllocExpHeapBlockWrapper(u32 size) {
    u32 value0 = size;
    u32 alignment;
    u32 allocFunctionAddress;
    alignment = 32u;
    allocFunctionAddress = (u32) &AllocExpHeapBlock;
    value0 = (u32) AllocExpHeapBlock(value0, alignment);
    return value0;
}
