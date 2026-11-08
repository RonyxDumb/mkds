#include "code_0200f59c.h"
#include "registers.h"

u32 OS_GetTickLo(void) {
    u32 value0;
    value0 = reg_OS_TM0CNT_L;
    return value0;
}
