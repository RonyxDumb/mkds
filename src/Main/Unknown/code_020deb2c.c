#include "Main/Unknown/code_020deb2c.h"

void func_020deb2c(Vec3 *param_1, void *param_2, u32 param_3, int param_4, u32 param_5) {
    int iVar1;
    u32 uVar2;
    uVar2 = (u32) * (u16 *) ((u32) param_2 + 0x74);
    if (param_4 == 0) {
        if (uVar2 == (int) data_021759c0->mUnk_62) {
            iVar1 = (int) func_0208b7bc((u32) 0x2d, (const Vec3 *) param_1);
            if (iVar1 != 0) {
                func_02081f10((u32) iVar1, uVar2, (u32) 0x1e);
            }
            iVar1 = (int) func_0208b7bc((u32) 0x2e, (const Vec3 *) param_1);
            if (iVar1 != 0) {
                func_02081f10((u32) iVar1, uVar2, (u32) 0x1e);
            }
        }
        iVar1 = (int) func_0208b7bc((u32) 0x2f, (const Vec3 *) param_1);
        if (iVar1 != 0) {
            func_02081f10((u32) iVar1, uVar2, (u32) 0x1e);
        }
    }
    func_020d26ec(param_2, 0xd4);
    func_020fa78c(uVar2, param_3, param_5);
}
