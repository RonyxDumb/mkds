#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_020364e0.h"

void *m2d_proc_getCurrentHeap(void) {
    void *value0;
    value0 = proc_getCurrent();
    value0 = proc_getHeap(value0);
    return value0;
}
