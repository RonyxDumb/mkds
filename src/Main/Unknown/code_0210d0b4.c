#include "Main/Unknown/code_0210d0b4.h"

// non-matching: 0x64 bytes, original 0x34; 20 instructions differ; first at +0x0: original `stmdb sp!, {r4, lr}`, ours
// `stmdb sp!, {r4, r5, r6, lr}`
void func_0210d0ec(void) {
    u32 uVar1;
    u32 uVar2;
    u32 uVar3;
    uVar2 = ((u32) ((u32) (&data_0217d028)));
    if (*(u32 *) (((u32) ((u32) (&data_0217d028)))) >> (((u32) ((u32) (&data_0217d028))) & 3) * 8 != 0 ||
        *(u32 *) (((u32) ((u32) (&data_0217d028)))) << (((u32) ((u32) (&data_0217d028))) & 3) * -8 + 0x20 != 0) {
        do {
            func_0210c3a8();
            uVar1 = uVar2 & 3;
            uVar3 = *(u32 *) (uVar2);
        } while (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0);
        return;
    }
    return;
}

void func_0210d0b4(u32 param_1, int param_2, u32 param_3) {
    func_0212ec04((u32) (param_2), (u32) (0xffffffff), (u32) (0xffffffff), (u32) (param_3),
                  (u32) (*(u8 *) (param_2 + 0x18)), (u32) (*(u16 *) (param_2 + 0x16)));
    return;
}
