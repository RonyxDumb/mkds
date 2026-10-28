#include "00/code_02188694.h"

void func_ov000_021886fc(int param_1, u32 param_2) {
    int iVar1;
    iVar1 = func_ov000_02188584((u32) (0x10));
    func_0214d02c((u32 *) ((u32 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (iVar1 + param_1 * 0x100)), (int) (0xf0));
    return;
}

// non-matching: register allocation only, 6 instructions; first at +0x10: original `ldrb r0, [r2, #0x8]`, ours `ldrb
// r1, [r2, #0x8]`
u32 func_ov000_021886c4(u8 param_1, u32 param_2) {
    u32 *puVar1;
    u32 uVar2;
    puVar1 = (u32 *) func_ov000_02188584((u32) (1));
    if ((*(u8 *) (puVar1 + 2) & param_1) == 0) {
        *(u8 *) (puVar1 + 2) = *(u8 *) (puVar1 + 2) | (u8) param_1;
        uVar2 = (*(UnkWordFunc *) *puVar1)(param_1, param_2);
        return uVar2;
    }
    return 0;
}

void func_ov000_02188694(u8 param_1, u32 param_2, u32 param_3) {
    u32 iVar1 = func_ov000_02188584(1);
    if ((*(u8 *) (iVar1 + 8) & param_1) != 0) {
        *(u8 *) (iVar1 + 8) = *(u8 *) (8 + (u32) iVar1) & ~param_1;
        iVar1 = 4 + iVar1;
        (**(UnkFunc **) iVar1)(param_1, param_2, param_3);
    }
    return;
}
