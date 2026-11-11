#include "00/code_021a3668.h"
#include "00/code_021a369c.h"

void DWCi_GsFree(void *ptr) {
    u32 value0 = (u32) ptr;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = 5u;
    value2 = 0u;
    DWC_Free(value0, value1, value2);
}
