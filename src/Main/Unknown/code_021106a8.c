#include "Main/Unknown/code_021106a8.h"

// non-matching: 0x8c bytes, original 0x78; 20 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
void func_021106a8(int param_1, int param_2) {
    u16 uVar1;
    u32 uVar2;
    uVar2 = 3;
    if (param_1 == 0xc) {
        if (param_2 == 0) {
            uVar1 = 0x47;
        } else {
            uVar1 = 0x48;
        }
        uVar2 = 0;
    } else {
        uVar1 = param_2 + param_1 * 2 & 0xffff;
    }
    func_0212ecc0((const void *) (((u32) ((u32) (&data_0217d068)))), (u32) (uVar2), (u32) (uVar1));
    if (*(u32 *) (((u32) ((u32) (&data_0217d068)))) >> (((u32) ((u32) (&data_0217d068))) & 3) * 8 != 0 ||
        *(u32 *) (((u32) ((u32) (&data_0217d068)))) << (((u32) ((u32) (&data_0217d068))) & 3) * -8 + 0x20 != 0) {
        func_02105b28(&data_0217d068, (u8) (100));
    }
    func_0212ecc0((const void *) (((u32) ((u32) (&data_0217d068)))), (u32) (0), (u32) (4));
    return;
}
