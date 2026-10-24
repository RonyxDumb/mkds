#include "Main/Unknown/code_020deb2c.h"

void func_020deb2c(u32 param_1, int param_2, u32 param_3, int param_4, u32 param_5) {
    int iVar1;
    u32 uVar2;
    uVar2 = (u32) * (u16 *) (param_2 + 0x74);
    if (param_4 == 0) {
        if (uVar2 == (int) *(s8 *) ((*(u32 *) (((u32) ((u32) (&data_021759c0))))) + 0x62)) {
            iVar1 = func_0208b7bc(0x2d, param_1);
            if (iVar1 != 0) {
                func_02081f10((unsigned int) (iVar1), (unsigned int) (uVar2), (unsigned int) (0x1e));
            }
            iVar1 = func_0208b7bc(0x2e, param_1);
            if (iVar1 != 0) {
                func_02081f10((unsigned int) (iVar1), (unsigned int) (uVar2), (unsigned int) (0x1e));
            }
        }
        iVar1 = func_0208b7bc(0x2f, param_1);
        if (iVar1 != 0) {
            func_02081f10((unsigned int) (iVar1), (unsigned int) (uVar2), (unsigned int) (0x1e));
        }
    }
    func_020d26ec(param_2, 0xd4);
    func_020fa78c(uVar2, param_3, param_5);
    return;
}
