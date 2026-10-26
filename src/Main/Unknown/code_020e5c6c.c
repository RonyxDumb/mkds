#include "Main/Unknown/code_020e5c6c.h"

// non-matching: 0x98 bytes, original 0xa0; 24 instructions differ; first at +0x0: original `stmdb sp!, {r4, r5, lr}`,
// ours `stmdb sp!, {r4, r5, r6, lr}`
void func_020e5c6c(u32 param_1, int param_2, u32 param_3, u32 param_4) {
    u32 uVar1;
    *(short *) ((*(u32 *) (((u32) ((u32) (&data_0217b830))))) + 0x18) =
        (short) ((int) (*(u16 *) (param_2 + 0xb8) & 0x10) >> 4);
    if (*(unsigned short *) (param_2 + 0x8e) == 0) {
        uVar1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
        func_020e67c4(*(u32 *) (((u32) ((u32) (&data_0217b830)))), uVar1, param_2 + 0x1c, 0, param_4);
        return;
    }
    uVar1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_020e66e4(*(u32 *) (((u32) ((u32) (&data_0217b830)))), uVar1, *(u16 *) (param_2 + 0xac), param_2 + 0x1c, 0,
                  param_4);
    return;
}
