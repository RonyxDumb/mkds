#include "03/code_021cfed8.h"

void func_ov003_021cff38(u32 param_1, u16 param_2) {
    func_0214544c((u32) (param_1), (u16) (3), (u16) (0x11), (u16) (param_2), (u16) (0x1e));
    return;
}

// non-matching: 0x58 bytes, original 0x60; 15 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
u16 func_ov003_021cfed8(void) {
    int *piVar1;
    u16 uVar2;
    if (*(int *) (*((int *) ((u32) (&data_ov003_021da2a8))) + 0x40) != 7) {
        func_0200fd1c();
    }
    func_ov003_021d07b0((u32) (1));
    uVar2 = func_ov003_021cfe40((u32) (*(u16 *) (*((int *) ((u32) (&data_ov003_021da2a8))) + 0x60)));
    piVar1 = ((int *) ((u32) (&data_ov003_021da2a8)));
    *(u16 *) (*((int *) ((u32) (&data_ov003_021da2a8))) + 0x5c) = uVar2;
    if ((UnkFunc *) *((u32 *) ((u32) (&data_ov003_021da2a4))) != (UnkFunc *) 0x0) {
        (*(UnkFunc *) *((u32 *) ((u32) (&data_ov003_021da2a4))))(
            ((u32) 0x08000000u), ((u32) ((u32) (&data_ov003_021d7ac8))), *(u16 *) (*piVar1 + 0x5c));
    }
    return *(u16 *) (*((int *) ((u32) (&data_ov003_021da2a8))) + 0x5c);
}
