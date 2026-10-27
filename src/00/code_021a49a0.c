#include "00/code_021a49a0.h"

void func_ov000_021a49f4(int param_1, u32 param_2) {
    if (param_1 == 0) {
        param_1 = *(int *) &data_ov000_021b426c;
    }
    *(u32 *) (param_1 + 0xa0) = param_2;
    return;
}

void func_ov000_021a49e0(int param_1, u32 param_2) {
    if (param_1 == 0) {
        param_1 = *(int *) &data_ov000_021b426c;
    }
    *(u32 *) (param_1 + 0xa4) = param_2;
    return;
}

void func_ov000_021a49cc(int param_1, u32 param_2) {
    if (param_1 == 0) {
        param_1 = *(int *) &data_ov000_021b426c;
    }
    *(u32 *) (param_1 + 0xa8) = param_2;
    return;
}

void func_ov000_021a49a0(int param_1) {
    if (param_1 == 0) {
        param_1 = *(int *) &data_ov000_021b426c;
    }
    if (*(int *) (param_1 + 0xbc) != 0) {
        func_ov000_021a4868((int *) ((int *) (u32) (param_1)));
    }
    func_ov000_021a4940((u32 *) ((u32 *) (u32) (param_1)));
    return;
}
