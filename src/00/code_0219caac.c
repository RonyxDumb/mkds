#include "00/code_0219caac.h"

u32 func_ov000_0219caf4(void) {
    return *(u32 *) (*((int *) ((u32) (&data_ov000_021b5664))) + 0x20);
}

// non-matching: 0x4c bytes, original 0x48; 27 instructions differ; first at +0x0: original `push {r4, r5, r6, lr}`,
// ours `push {r4, r5, r6, r7, lr}`
void func_ov000_0219caac(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    int *piVar1;
    *((int *) ((u32) (&data_ov000_021b565c))) = param_1;
    func_0214d168((void *) ((u32 *) (u32) (param_1)), (u8) (0), (u32) (((u32) 0x00000264u)));
    piVar1 = ((int *) ((u32) (&data_ov000_021b565c)));
    *(u32 *) *((int *) ((u32) (&data_ov000_021b565c))) = param_3;
    *(u32 *) (*piVar1 + 4) = 0;
    *(u32 *) (*piVar1 + 8) = param_4;
    *(u32 *) (*piVar1 + 0xc) = param_5;
    *(u32 *) (*piVar1 + 0x18) = param_6;
    *(u32 *) (*piVar1 + 0x1c) = param_7;
    *(u32 *) (*piVar1 + 0x20) = param_2;
    return;
}
