#include "00/code_021a3744.h"

u32 func_ov000_021a3744(void *(*arg0)(u32, u32, s32), void (*arg1)(u32, void *)) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_ov000_021b5df0;
    *(u32 *) ((value2) + 0u) = (u32) value0;
    value0 = (u32) &data_ov000_021b5dec;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    return (u32) value0;
}
