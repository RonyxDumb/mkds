#include "Main/Unknown/code_02028f08.h"
#include "code_0201ea30.h"

u32 func_02028f08(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_0201ea30;
    value2 = value0;
    value0 = value1;
    value1 = value2;
    value0 = (u32) func_0201ea30((Unk0201ea30 *) value0, (int) value1);
    return (u32) value0;
}
