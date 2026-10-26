#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020846a8.h"

int func_020846a8(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ae84;
    value1 = 0x58u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (int) value0;
}
