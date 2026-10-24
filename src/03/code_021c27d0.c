#include "03/code_021c27d0.h"

void func_ov003_021c2824(void) {
    func_ov003_021d3544((unsigned int) (0), (unsigned int) (((u32) ((u32) (&func_ov003_021c27f8)))), (unsigned int) (0),
                        (unsigned int) (0x78));
    return;
}

void func_ov003_021c27f8(u32 param_1) {
    int iVar1;
    iVar1 = func_ov003_021d1290();
    if (iVar1 != 0) {
        *(u8 *) (*((int *) ((u32) (&data_ov003_021da194))) + ((int) 0x0001e2a1u)) = 1;
        func_ov003_021d34c8(0, param_1);
    }
    return;
}

u32 func_ov003_021c27e4(void) {
    if (*((int *) ((u32) (&data_ov003_021da194))) == 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c27d0(u32 param_1) {
    *(u32 *) (*((int *) ((u32) (&data_ov003_021da194))) + ((int) 0x0001e298u)) = param_1;
    return;
}
