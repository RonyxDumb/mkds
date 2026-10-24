#include "01/code_02188e24.h"

void func_ov001_02188e74(int param_1, u32 param_2, u32 param_3) {
    *(u32 *) (param_1 + ((int) 0x000001d8u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x000001dcu)) = param_3;
    return;
}

void func_ov001_02188e48(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    *(u32 *) (param_1 + ((int) 0x000001e0u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x000001e4u)) = param_3;
    *(u32 *) (param_1 + ((int) 0x000001e8u)) = param_4;
    *(u32 *) (param_1 + ((int) 0x000001ecu)) = param_5;
    return;
}

void func_ov001_02188e24(int param_1, u32 param_2, int param_3) {
    *(u32 *) (param_1 + ((int) 0x000001f0u)) = param_2;
    *(u32 *) (param_1 + 0xb0) = 0;
    if (param_3 == 0) {
        param_3 = ((int) ((u32) (&func_ov001_02188e88)));
    }
    *(int *) (param_1 + ((int) 0x000001f4u)) = param_3;
    return;
}
