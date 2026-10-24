#include "Main/Unknown/code_0209a02c.h"

// non-matching: 0x90 bytes, original 0x74; 10 instructions differ; first at +0x50: original `ldr r1, [pc, #0x18]
// (->0x70)`, ours `ldr r1, [pc, #0x34] (->0x8c)`
void func_0209a02c(u32 param_1, int param_2) {
    u32 uVar1;
    u32 local_10;
    local_10 = 0x1e;
    func_01ff9048((u32) (0x14), (u32) ((u32) (u32) (&local_10)), (int) (1));
    uVar1 = func_020e6cbc((u32) (param_2 + 4));
    func_01ff9048((u32) (0x19), (u32) (uVar1), (int) (0xc));
    func_01ff9048((u32) (0x1b), (u32) (param_2 + 0x1c), (int) (3));
    func_0209ba88(
        (u32) (param_1),
        (int) (*(u32 *) (((u32) (&data_0217b144)) & 0xfffffffc) >> (((u32) (&data_0217b144)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b144)) & 0xfffffffc) << (((u32) (&data_0217b144)) & 3) * -8 + 0x20),
        (int) (param_2));
    return;
}
