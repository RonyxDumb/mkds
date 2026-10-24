#include "00/code_021aa004.h"

u32 func_ov000_021aa004(int param_1, u32 param_2, u32 param_3) {
    u32 uVar1;
    u32 local_18;
    do {
        uVar1 = func_ov000_021adfc8(&local_18, param_3);
        if (local_18 == 0) {
            return 0xffffffff;
        }
        if (local_18 > param_2) {
            local_18 = param_2;
        }
        func_0214d1fc((const void *) ((u16 *) (u32) (uVar1)), (void *) ((u32 *) (u32) (param_1)), (u32) (local_18));
        func_ov000_021adf30(local_18, param_3);
        param_1 = param_1 + local_18;
        param_2 = param_2 - local_18;
    } while (0 < (int) param_2);
    return 0;
}
