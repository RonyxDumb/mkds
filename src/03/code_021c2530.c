#include "03/code_021c2530.h"

void func_ov003_021c2544(int param_1) {
    func_ov003_021d1490(*(u32 *) (param_1 + 8));
    func_ov003_021d1d0c((u16 *) ((u16 *) (u32) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da190))) + 0x60))),
                        (u32) (param_1));
    return;
}

int func_ov003_021c2530(int *param_1, u32 param_2) {
    return param_1[1] + *(int *) (*param_1 + (param_2 & ((u32) 0x0000ffffu)) * 4);
}
