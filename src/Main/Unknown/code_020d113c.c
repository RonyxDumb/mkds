#include "Main/Unknown/code_020d113c.h"
#include "Main/Unknown/code_020364e0.h"

u32 cpic_process_getCurrentHeapHandle(void) {
    u32 value0;
    value0 = (u32) proc_getCurrent();
    value0 = (u32) proc_getHeap((void *) value0);
    return value0;
}
