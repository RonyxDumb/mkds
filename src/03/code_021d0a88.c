#include "03/code_021d0a88.h"

void func_ov003_021d0ab8(void) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da2ac))) + ((int) 0x00000a90u)) = 0xc;
    return;
}

u32 func_ov003_021d0a88(void) {
    int iVar1;
    iVar1 = func_ov003_021d010c();
    if (iVar1 == 1) {
        func_ov003_021cfa68();
        *(u8 *) (*((int *) ((u32) (&data_ov003_021da2ac))) + ((int) 0x00000a90u)) = 1;
        return 1;
    }
    return 0;
}
