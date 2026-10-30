#include "00/code_02196714.h"

u32 func_ov000_02196714(Unk0218f960 *param_1, u32 param_2, u32 *param_3) {
    int iVar1;
    int local_18;
    int local_14[2];
    local_18 = 0;
    local_14[0] = 0;
    iVar1 = func_ov000_0218e68c((u32) (param_2), (u32 *) (0), (u32 *) (&local_18), (u32 *) (local_14));
    if (iVar1 == -1) {
        func_ov000_0219690c(param_1, data_ov000_021b3a58);
        func_ov000_021965a0((Unk0218f960 *) (u32) (param_1), 5, data_ov000_021b3a6c);
        func_ov000_02190f4c((Unk0218f960 *) (u32) (param_1), 3, 1);
        return 3;
    }
    if (0 < iVar1) {
        if (local_14[0] != 0) {
            func_ov000_0219690c(param_1, data_ov000_021b3aa4);
            *param_3 = 4;
            return 0;
        }
        if (local_18 != 0) {
            func_ov000_0219690c(param_1, data_ov000_021b3abc);
            *param_3 = 3;
            return 0;
        }
    }
    *param_3 = 0;
    return 0;
}
