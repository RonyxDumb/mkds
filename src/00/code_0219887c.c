#include "00/code_0219887c.h"

u16 func_ov000_021988e4(int param_1) {
    return *(u16 *) (param_1 + 8);
}

int func_ov000_021988dc(int param_1) {
    return *(int *) (param_1 + 0x54) - *(int *) (param_1 + 0x58);
}

u32 func_ov000_021988d8(u32 *param_1) {
    return *param_1;
}

void func_ov000_021988d4(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x30) = param_2;
    return;
}

void func_ov000_021988a4(int param_1, u32 param_2) {
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b3f8c, data_ov000_021b3f98, 0, 0x19c);
    }
    *(u32 *) (param_1 + 0x40) = param_2;
    return;
}

u32 func_ov000_0219887c(int param_1) {
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b3f8c, data_ov000_021b3f98, 0, 0x1a3);
    }
    return *(u32 *) (param_1 + 0x40);
}
