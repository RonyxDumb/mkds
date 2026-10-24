#include "03/code_021cdcb8.h"

// non-matching: 12 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_ov003_021cdcb8(u32 param_1) {
    func_0200ee74((u32) (*((u32 *) ((u32) (&data_ov003_021da278)))), (int) (((u32) 0x00000600u)));
    func_0214bd04((u32) (*((u32 *) ((u32) (&data_ov003_021da278)))), (int) (0), (u32) (((u32) 0x00000600u)));
    func_ov003_021d1490(*((u32 *) ((u32) (&data_ov003_021da278))));
    func_ov003_021d34c8(1, param_1);
    return;
}
