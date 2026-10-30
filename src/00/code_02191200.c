#include "00/code_02191200.h"

int func_ov000_02191200(int *param_1) {
    int iVar1;
    int iVar2;
    int local_10;
    iVar2 = *param_1;
    iVar1 = func_ov000_02196714((u32) ((u32) (u32) (param_1)), (u32) (*(u32 *) (iVar2 + ((int) 0x000001d4u))),
                                (u32 *) (&local_10));
    if (iVar1 == 0) {
        if (local_10 == 4) {
            func_ov000_021965a0((Unk0218f960 *) (param_1), 0x107u, data_ov000_021b2b48);
            func_ov000_02190f4c((Unk0218f960 *) (param_1), 4, 1);
            return 4;
        }
        if (local_10 == 0) {
            return 0;
        }
        if (local_10 != 3) {
            func_0213442c(data_ov000_021b2b70, data_ov000_021b2b88, 0, 0x2ef);
        }
        *(u32 *) (iVar2 + ((int) 0x000001d8u)) = 2;
        iVar1 = 0;
    }
    return iVar1;
}
