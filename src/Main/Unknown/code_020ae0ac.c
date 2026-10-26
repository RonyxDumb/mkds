#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae0ac.h"

int func_020ae0ac(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const s8 *) ((value1) + (134));
    return (int) value0;
}
