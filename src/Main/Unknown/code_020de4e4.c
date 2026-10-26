#include "Main/Unknown/code_020de4e4.h"

// non-matching: 0xa0 bytes, original 0xa4; 21 instructions differ; first at +0x0: original `stmdb sp!, {r4, r5, lr}`,
// ours `stmdb sp!, {r4, r5, r6, lr}`
void func_020de4e4(u32 param_1, int param_2, u32 param_3, u32 param_4) {
    u32 uVar1;
    if (*(unsigned short *) (param_2 + 0x8e) == 0) {
        uVar1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
        func_020e67c4(*(u32 *) (((u32) ((u32) (&data_0217b6f0)))), uVar1, param_2 + 0x1c, 0, param_4);
        return;
    }
    func_020e6a18(*(u32 *) (((u32) ((u32) (&data_0217b6f4)))));
    uVar1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_020e66e4(*(u32 *) (((u32) ((u32) (&data_0217b6f4)))), uVar1, *(u16 *) (param_2 + 0xac), param_2 + 0x1c, 0,
                  param_4);
    func_020e6a18(*(u32 *) (((u32) ((u32) (&data_0217b6f0)))));
    return;
}
