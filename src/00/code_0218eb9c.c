#include "00/code_0218eb9c.h"

u32 func_ov000_0218eb9c(int *param_1, u32 param_2) {
    int iVar1;
    int local_8[1];
    if ((param_1 == (int *) 0x0) || (*param_1 == 0)) {
        return 0;
    }
    if (*(int *) (*param_1 + ((int) 0x00000108u)) != 0) {
        return 0;
    }
    iVar1 = func_ov000_02194934((Unk0218f960 *) param_1, param_2, (Unk02194934 **) local_8);
    if ((iVar1 != 0) && (*(int *) (local_8[0] + 8) != 0)) {
        return 1;
    }
    return 0;
}
