#include "00/code_021a73d8.h"

s32 func_ov000_021a73d8(Unk021b49b8 *param_1) {
    Unk021a6fa8 *iVar1;
    Unk021a7064 *uVar2;
    iVar1 = func_ov000_021a732c(param_1);
    if (iVar1 == 0) {
        return -0x31;
    }
    uVar2 = func_ov000_021a7064(func_ov000_021a7378, iVar1, 1);
    func_ov000_021a6f84(iVar1, uVar2);
    return (s32) iVar1;
}
