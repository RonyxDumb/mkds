#include "03/code_021c1c5c.h"

// non-matching: 0x24 bytes, original 0x28; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c1cb0(void) {
    func_ov003_021d197c(*(u32 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x58));
    func_ov003_021d34e0((int) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x5c)),
                        (u32) (((u32) ((u32) (&func_ov003_021c118c)))));
    return;
}

u8 func_ov003_021c1ca0(void) {
    return *(u8 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x60);
}

void func_ov003_021c1c90(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x66) = param_1;
    return;
}

void func_ov003_021c1c80(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x67) = param_1;
    return;
}

void func_ov003_021c1c70(u8 param_1) {
    *(u8 *) (*((int *) ((u32) (&data_ov003_021da160))) + 0x68) = param_1;
    return;
}

u32 func_ov003_021c1c5c(void) {
    if (*((int *) ((u32) (&data_ov003_021da160))) != 0) {
        return 1;
    }
    return 0;
}
