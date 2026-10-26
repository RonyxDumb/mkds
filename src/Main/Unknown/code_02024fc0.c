#include "Main/Unknown/code_02024fc0.h"

void func_02024fc0(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    value3 = (u32) * (const u32 *) ((value1) + (8));
    value2 = (u32) * (const u8 *) ((value1) + (4));
    compareLeft0 = value3;
    compareRight0 = 0x440000u;
    if ((s32) compareLeft0 > (s32) compareRight0) {
        value3 = 0x440000u;
    }
    value3 = (value3 << 4);
    value12 = (u32) &func_02109078;
    value1 = (u32) * (const u32 *) ((value1) + (92));
    value3 = ((u32) ((s32) value3 >> 16));
    func_02109078((Unk0206bcb0 *) value0, (int) value1, (int) value2, (int) value3);
    return;
}
