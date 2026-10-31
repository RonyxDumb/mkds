#include "Main/Unknown/code_020ae21c.h"

u32 func_020ae21c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ae23c;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ae23c((u32) value0);
    return (u32) value0;
}
