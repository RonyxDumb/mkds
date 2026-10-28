#include "Main/Unknown/code_0202f14c.h"

#pragma thumb on

void func_0202f160(void) {
    int iVar1;
    iVar1 = func_0202f19c();
    if (iVar1 == 0) {
        func_021258f0();
    }
    (**(UnkFunc **) (*(int *) ((*(int *) &data_02174e4c) + ((int) 0x0000080cu)) + 0xc))();
    func_020ae5f0((void *) ((*(int *) &data_02174e4c)), (void *) ((*(int *) &data_02174e4c) + ((int) 0x00000404u)));
    return;
}

unsigned int func_0202f14c(void) {
    return (
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_02174e4c))) + 0))) +
        (0x818u));
}

#pragma thumb off
