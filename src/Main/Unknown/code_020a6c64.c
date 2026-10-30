#include "Main/Unknown/code_020a6c64.h"

void func_020a6c64(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    func_020d2398((void *) value0);
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    value1 = 0x44u;
    value0 = (u32) func_02036bec((void *) value0, (u32) value1);
    *(u32 *) ((value4) + (148)) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value4) + (148));
    value2 = (value4) + (4u);
    value1 = 0xbu;
    func_02109110((Unk0210bfbc *) value0, (u32) value1, (Vec3 *) value2);
    value0 = (u32) * (const u32 *) ((value4) + (148));
    func_0210bae8((unsigned int) value0);
    value0 = (u32) &data_0217ca6c;
    value0 = (u32) * (const u32 *) ((value0) + (428));
    *(u32 *) ((value4) + (112)) = (u32) value0;
}
