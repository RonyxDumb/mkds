#include "03/code_021be59c.h"

u32 func_ov003_021be604(void) {
    return data_ov003_021d8bfc;
}

u32 func_ov003_021be5cc(u32 param_1, s32 param_2) {
    u32 result;
    if (param_2 > 0) {
        func_0200ed34(data_ov003_021d8c8c);
        result = data_ov003_021d8bd4(param_2);
        func_0200ecc4(data_ov003_021d8c8c);
        return result;
    }
    return 0;
}

void func_ov003_021be59c(u32 param_1, s32 param_2, s32 param_3) {
    if (param_2 != 0 && param_3 > 0) {
        func_0200ed34(data_ov003_021d8c8c);
        data_ov003_021d8bdc(param_2);
        func_0200ecc4(data_ov003_021d8c8c);
    }
}
