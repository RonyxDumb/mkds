#include "Main/Unknown/code_020cffa0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_0217b000.h"

u32 SomeAlloc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) proc_getCurrent();
    value0 = (u32) proc_getHeap((void *) value0);
    value1 = 0x38u;
    value0 = (u32) heap_alloc((void *) value0, value1);
    value1 = (u32) &data_0217b490;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
