#include "00/code_021a91b4.h"
#include "00/unk_021b6000.h"
#include "03/code_021b94b8.h"
#include "code_0214d018.h"

void func_ov000_021a91cc(s32 a) {
    s32 i;
    Unk021a91cc *b;
    i = 0;
    b = (Unk021a91cc *) data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (b->field5A != 0 && a - b->field50 > 0xef) {
            b->field5A = 0;
        }
        b++;
    }
}

void func_ov000_021a91b4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value0 = (u32) &data_ov000_021b61f4;
    value1 = 0u;
    value2 = 0x170u;
    MI_CpuFill8((void *) value0, value1, value2);
}
