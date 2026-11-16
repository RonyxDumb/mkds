#include "Main/Unknown/code_020cb99c.h"
#include "Main/Unknown/code_020364e0.h"

void *menu_process_getCurrentHeapHandle(void) {
    void *value0;
    value0 = proc_getCurrent();
    value0 = proc_getHeap(value0);
    return value0;
}
