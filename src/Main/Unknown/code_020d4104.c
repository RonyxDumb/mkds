#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d4104.h"

int func_020d4104(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b4dc;
    value1 = 0xcu;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (int) value0;
}
