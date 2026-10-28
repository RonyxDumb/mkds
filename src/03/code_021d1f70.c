#include "03/code_021d1f70.h"

u8 func_ov003_021d1f70(int param_1) {
    int iVar1;
    if (param_1 == 1) {
        iVar1 = *(int *) &data_ov003_021da2c0;
    } else {
        iVar1 = (*(int *) &data_ov003_021da2c0) + 0xc;
    }
    return *(u8 *) (iVar1 + 9);
}
