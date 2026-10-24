#include "Main/Unknown/code_020b4dc4.h"

unsigned int func_020b4df8(void) {
    return ((unsigned int) *(
        const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                   const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_021759c0))) +
                                                          0))) +
                               8));
}

u32 func_020b4dc4(int param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_020b4df8());
    if ((iVar1 == 1) && (param_1 != 0)) {
        return 1;
    }
    uVar2 = func_0207a68c((int) (param_1));
    return uVar2;
}
