#include "code_02146c98.h"

// non-matching: the original stores with two stmia instructions and returns the advanced pointer
u32 *func_02146c98(s32 *param_1) {
    param_1[0] = 0x1000;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0x1000;
    return (u32 *) (param_1 + 4);
}
