#include "Main/Unknown/code_0205c7a0.h"

// non-matching: 0x6c bytes, original 0x60; 12 instructions differ; first at +0x0: original `stmdb sp!, {r4, lr}`, ours
// `stmdb sp!, {r4, r5, lr}`
void func_0205c7a0(u32 param_1) {
    int iVar1;
    if (param_1 == 0xffffffff) {
        return;
    }
    param_1 = param_1 & 0xff;
    if (((u32) * (u8 *) ((*(u32 *) (((u32) (&data_0217aa14)))) + 0x749) & 1 << param_1) != 0) {
        iVar1 = func_0205c340((u32) (param_1), (u32) (1), (int) (8));
        if (iVar1 != 0) {
            *(short *) ((*(u32 *) (((u32) (&data_0217aa14)))) + 0xf8) = (short) param_1;
        }
        return;
    }
    return;
}
