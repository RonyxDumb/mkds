#include "00/code_0218dd8c.h"

int func_ov000_0218dd8c(int *param_1, int param_2, u32 param_3) {
    int iVar1;
    int iVar2;
    int iVar3;
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xd3);
    }
    iVar3 = 0;
    if (0 < param_1[1]) {
        iVar2 = 0;
        do {
            iVar1 = func_ov000_0218d8dc((int *) (u32) (*(u32 *) (*param_1 + iVar2)), param_2, param_3);
            if (iVar1 != 0) {
                return iVar1;
            }
            iVar2 = iVar2 + 4;
            iVar3 = iVar3 + 1;
        } while (iVar3 < param_1[1]);
    }
    return 0;
}
