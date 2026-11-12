#include "03/System/alloc_exp_heap_block.h"
#include "03/System/exp_heap.h"

u32 AllocExpHeapBlockWrapper(u32 size) {
    u32 value0 = size;
    u32 alignment;
    u32 allocFunctionAddress;
    alignment = 32u;
    allocFunctionAddress = (u32) &AllocExpHeapBlock;
    value0 = (u32) AllocExpHeapBlock(value0, alignment);
    return value0;
}
