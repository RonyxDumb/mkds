#include "03/code_021d010c.h"

void func_ov003_021d0134(int param_1) {
    if (*(u16 *) (param_1 + 2) != 0) {
        func_ov003_021d07b0((u32) 10);
        return;
    }
    func_ov003_021d07b0((u32) 0);
}

void func_ov003_021d0128(u32 param_1) {
    data_ov003_021da2a8->mUnk_08 = param_1;
}

u16 func_ov003_021d0118(void) {
    return data_ov003_021da2a8->mUnk_52;
}

u32 func_ov003_021d010c(void) {
    return (u32) data_ov003_021da2a8->mUnk_40;
}
