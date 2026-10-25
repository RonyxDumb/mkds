#include "Main/Unknown/code_020f40dc.h"

void func_020f40dc(Unk020f40dc *arg0, s32 arg1, s32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value4;
    u32 value5;
    value5 = value0;
    value4 = value1;
    *(u32 *) ((value5) + (0)) = (u32) value4;
    *(u32 *) ((value5) + (8)) = (u32) value2;
    value0 = 0u;
    *(u32 *) ((value5) + (32)) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value5) + (4));
    value0 = (u32) * (const u32 *) ((value0) + (508));
    func_0206c14c((Unk0206bcb0 *) value0);
    value1 = (u32) &data_0217bc48;
    value0 = 0x1cu;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = 0u;
    value0 = (value4) * (value0) + (value2);
    value0 = (u32) * (const u32 *) ((value0) + (16));
    *(u32 *) ((value5) + (12)) = (u32) value0;
    *(u16 *) ((value5) + (16)) = (u16) value1;
    *(u16 *) ((value5) + (18)) = (u16) value1;
    return;
}
