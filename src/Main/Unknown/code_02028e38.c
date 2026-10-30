#include "Main/Unknown/code_02028e38.h"

#pragma thumb on

void func_02028e38(void) {
    int iVar1;
    short *psVar2;
    iVar1 = func_020280dc();
    if (iVar1 == 0) {
        psVar2 = (short *) func_02078b04((int) (*(u32 *) ((*(int *) &data_02174e18) + 0xa8)),
                                         (int) (*(u32 *) ((*(int *) &data_02174e18) + 0xa4)));
        iVar1 = (*(int *) &data_02174e18) + 100;
        func_02028ec0((int) (10), (u32) (0x10), (int) ((int) *psVar2), (Unk02174e14_00 *) (iVar1));
        func_02028ec0((int) (9), (u32) (0xf), (int) ((int) psVar2[1]), (Unk02174e14_00 *) (iVar1));
        func_02028ec0((int) (8), (u32) (0xe), (int) ((int) psVar2[2]), (Unk02174e14_00 *) (iVar1));
        func_02028ec0((int) (7), (u32) (0xd), (int) ((int) psVar2[3]), (Unk02174e14_00 *) (iVar1));
        func_02028ec0((int) (6), (u32) (0xc), (int) ((int) psVar2[4]), (Unk02174e14_00 *) (iVar1));
        func_02028ec0((int) (5), (u32) (0xb), (int) ((int) psVar2[5]), (Unk02174e14_00 *) (iVar1));
    }
    return;
}

#pragma thumb off
