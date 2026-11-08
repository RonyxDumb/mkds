#include "Main/Unknown/code_020ce744.h"
#include "registers.h"

void GxDispCntBits8To12Write(int bits) {
    u32 value0 = bits;
    u32 value1;
    value1 = reg_GX_DISPCNT;
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    reg_GX_DISPCNT = value0;
}

void GxsDispCntBits8To12Write(int bits) {
    u32 value0 = bits;
    u32 value1;
    value1 = reg_GXS_DB_DISPCNT;
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    reg_GXS_DB_DISPCNT = value0;
}
