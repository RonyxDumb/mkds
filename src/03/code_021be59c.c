#include "03/code_021be59c.h"

u32 func_ov003_021be604(void) {
    return *(u32 *) &data_ov003_021d8bfc;
}

// non-matching: 0x40 bytes, original 0x38; 15 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
u32 func_ov003_021be5cc(u32 param_1, int param_2) {
    u32 uVar1;
    if (0 < param_2) {
        func_0200ed34((void *) (((u32) &data_ov003_021d8c8c)));
        uVar1 = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8bd4))(param_2);
        func_0200ecc4((void *) (((u32) &data_ov003_021d8c8c)));
        return uVar1;
    }
    return 0;
}

// non-matching: 0x34 bytes, original 0x30; 13 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_ov003_021be59c(u32 param_1, int param_2, int param_3) {
    if ((param_2 != 0) && (0 < param_3)) {
        func_0200ed34((void *) (((u32) &data_ov003_021d8c8c)));
        (*(UnkFunc *) (*(u32 *) &data_ov003_021d8bdc))(param_2);
        func_0200ecc4((void *) (((u32) &data_ov003_021d8c8c)));
    }
    return;
}
