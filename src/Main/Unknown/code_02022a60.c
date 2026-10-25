#include "Main/Unknown/code_02022a60.h"

u32 func_02022a60(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value4;
    u32 value5;
    value5 = value1;
    value4 = value2;
    value0 = (u32) func_02022a90((u32) value0);
    value1 = ~(0u);
    *(u32 *) ((value0) + (36)) = (u32) value1;
    *(u32 *) ((value0) + (40)) = (u32) value5;
    *(u32 *) ((value0) + (44)) = (u32) value4;
    return (u32) value0;
}
