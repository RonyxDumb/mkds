#include "03/code_021cafa0.h"
#include "03/code_021d2a34.h"

void func_ov003_021cb06c(void) {
    func_ov003_021cafa4();
    func_ov003_021cafa0();
    func_ov003_021caeb8();
    return;
}

void func_ov003_021cafa4(void) {
    int iVar1;
    u32 uVar2;
    int iVar3;
    uVar2 = 0;
    iVar3 = ((int) ((u32) (&data_ov003_021d6508)));
    do {
        iVar1 = func_ov003_021d2a34((const Unk021d299c *) (u16 *) ((u16 *) (u32) (iVar3)));
        if (iVar1 != 0) {
            func_ov003_021bf31c((u8) (1));
            *(u8 *) &data_ov003_021da230 = (s8) uVar2;
            func_ov003_021caca8();
            return;
        }
        iVar3 = iVar3 + 8;
        uVar2 = uVar2 + 1;
    } while (uVar2 < 7);
    iVar3 = func_ov003_021d2b04((u32) (1));
    if (iVar3 != 0) {
        func_ov003_021bf31c((u8) (1));
        return;
    }
    iVar3 = func_ov003_021d2b04((u32) (2));
    if (iVar3 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    iVar3 = func_ov003_021d2ae8((u32) (0x40));
    if (iVar3 != 0) {
        func_ov003_021cab4c(1);
        return;
    }
    iVar3 = func_ov003_021d2ae8((u32) (0x80));
    if (iVar3 != 0) {
        func_ov003_021cab4c(3);
        return;
    }
    iVar3 = func_ov003_021d2ae8((u32) (0x20));
    if (iVar3 != 0) {
        func_ov003_021cab4c(0);
        return;
    }
    iVar3 = func_ov003_021d2ae8((u32) (0x10));
    if (iVar3 != 0) {
        func_ov003_021cab4c(2);
    }
    return;
}

void func_ov003_021cafa0(void) {
    return;
}
