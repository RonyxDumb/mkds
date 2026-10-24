#include "00/code_02196ae0.h"

// non-matching: 0xa8 bytes, original 0xb0; 23 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours
// `push {r4, r5, r6, lr}`
void func_ov000_02196ae0(int param_1, int param_2) {
    int iVar1;
    *(u8 *) (param_1 + param_2) = 0;
    iVar1 = func_0213a038((u32) (param_1), (u32) (((u32) ((u32) (&data_ov000_021b3d88)))), (int) (8));
    if (iVar1 == 0) {
        func_ov000_02196d0c(param_1, param_2);
        return;
    }
    iVar1 = func_0213a038((u32) (param_1), (u32) (((u32) ((u32) (&data_ov000_021b3d94)))), (int) (9));
    if (iVar1 == 0) {
        func_ov000_02196ca4(param_1, param_2);
        return;
    }
    iVar1 = func_0213a038((u32) (param_1), (u32) (((u32) ((u32) (&data_ov000_021b3d94)))), (int) (9));
    if (iVar1 == 0) {
        func_ov000_02196ca4(param_1, param_2);
        return;
    }
    iVar1 = func_0213a038((u32) (param_1), (u32) (((u32) ((u32) (&data_ov000_021b3da0)))), (int) (8));
    if (iVar1 == 0) {
        func_ov000_02196c00(param_1, param_2);
        return;
    }
    iVar1 = func_0213a038((u32) (param_1), (u32) (((u32) ((u32) (&data_ov000_021b3dac)))), (int) (8));
    if (iVar1 == 0) {
        func_ov000_02196b90(param_1, param_2);
    }
    return;
}
