#include "03/code_021ccc08.h"

// non-matching: 5 instructions differ; first at +0x0: original `ldr r1, [pc, #0x14] (->0x18)`, ours `ldr r2, [pc,
// #0x14] (->0x18)`
void func_ov003_021ccc08(int param_1) {
    u8 uVar1;
    *(s8 *) (*((int *) ((u32) (&data_ov003_021da268))) + 0x1c) = (s8) param_1;
    if (param_1 == 2) {
        uVar1 = 4;
    } else {
        uVar1 = 6;
    }
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da268))) + 0x1d) = uVar1;
    return;
}
