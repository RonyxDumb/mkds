#include "Main/Unknown/code_020a2f0c.h"

void func_020a2f0c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value12;
    value1 = ~(0u);
    *(u32 *) ((value0) + (164)) = (u32) value1;
    value1 = 1u;
    *(u32 *) ((value0) + (244)) = (u32) value1;
    value1 = 0u;
    value12 = (u32) &func_020d2398;
    *(u32 *) ((value0) + (248)) = (u32) value1;
    func_020d2398((void *) value0);
}
