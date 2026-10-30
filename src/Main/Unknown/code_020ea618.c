#include "Main/Unknown/code_020ea618.h"

void func_020ea618(void *param_1, int param_2) {
    u16 uVar1;
    u16 uVar2;
    u16 uVar3;
    uVar1 = *(u16 *) ((u8 *) param_1 + 0x6e);
    if (param_2 < (int) (u32) uVar1) {
        uVar2 = *(u16 *) ((u8 *) param_1 + 0x6c);
        uVar3 = func_020d3c44();
        *(u16 *) ((u8 *) param_1 + 0x6c) = uVar3;
        *(short *) ((u8 *) param_1 + 0x6e) = (short) param_2;
        func_0207ad88(param_1);
        *(u16 *) ((u8 *) param_1 + 0x6c) = uVar2;
        *(u16 *) ((u8 *) param_1 + 0x6e) = uVar1;
        return;
    }
    func_0207ad88();
    return;
}
