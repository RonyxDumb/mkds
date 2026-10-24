#include "00/code_0218ed74.h"

u32 func_ov000_0218ed74(int *param_1, int param_2) {
    int iVar1;
    int iVar2;
    int local_10;
    if ((param_1 == (int *) 0x0) || (iVar2 = *param_1, iVar2 == 0)) {
        return 2;
    }
    if (*(int *) (iVar2 + ((int) 0x00000108u)) != 0) {
        return 0;
    }
    if (*(int *) (iVar2 + ((int) 0x000001d8u)) == 4) {
        func_ov000_02196590(param_1, ((u32) ((u32) (&data_ov000_021b23e8))));
        return 2;
    }
    iVar1 = func_ov000_02194934(param_1, param_2, &local_10);
    if (iVar1 == 0) {
        return 0;
    }
    *(int *) (local_10 + 0x14) = *(int *) (local_10 + 0x14) + -1;
    if ((*(int *) (iVar2 + ((int) 0x00000100u)) == 0) && (*(int *) (local_10 + 0x14) <= 0)) {
        func_ov000_021a3668((u32) (*(u32 *) (local_10 + 0x10)));
        *(u32 *) (local_10 + 0x10) = 0;
        iVar2 = func_ov000_021947e4((int) (local_10));
        if (iVar2 != 0) {
            func_ov000_021948f8(param_1, local_10);
        }
    }
    return 0;
}
