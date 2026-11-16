#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020cab8c.h"

#pragma thumb on
void echoi_render(void) {
    u32 unusedValue;
    echoi_renderMenu();
}
#pragma thumb off

void *echoi_proc_getCurrentHeap(void) {
    void *value0;
    value0 = proc_getCurrent();
    value0 = proc_getHeap(value0);
    return value0;
}
