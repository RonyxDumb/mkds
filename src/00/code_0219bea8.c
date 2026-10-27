#include "00/code_0219bea8.h"

// non-matching: same size; 12 lines differ; first: original `cmp r0, #0`, ours `ldr r1, [pc, #76]`
void func_ov000_0219bea8(u32 param_1, u32 param_2, void (*param_3)(s32 param_1), u32 param_4) {
    int *piVar1;
    int iVar2;
    iVar2 = func_ov000_0219c39c();
    piVar1 = (int *) &data_ov000_021b54c8;
    if (iVar2 == 0) {
        if (*(int *) ((*(int *) &data_ov000_021b54c8) + 0x24) == 0) {
            *(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x5c) = (u32) param_3;
            *(u32 *) (*piVar1 + 0x60) = param_4;
            *(u32 *) (*piVar1 + 0x94) = param_1;
            *(u32 *) (*piVar1 + 0x98) = param_2;
            iVar2 = func_ov000_021a3810();
            if (iVar2 != 4) {
                func_ov000_0219c990(2, ((u32) 0xffff1596u));
                return;
            }
            func_ov000_0219b8a8((u32) (1));
            func_ov000_0218d6e4((u32) (*(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x54)));
        }
    }
    return;
}
