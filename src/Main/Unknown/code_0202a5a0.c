#include "Main/Unknown/code_0202a5a0.h"

#pragma thumb on

// non-matching: 16 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_0202a604(u32 param_1) {
    int iVar1;
    iVar1 = func_02049b6c();
    if (iVar1 == 0) {
        func_020ae6ac((void *) (*((int *) ((u32) (&data_02174e24)))), (void *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000404u)));
        if (*(int *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000808u)) == 0) {
            func_02029aa0((int) (param_1));
        } else {
            func_02032ac4((int) (param_1));
        }
        func_020ae630((void *) (*((int *) ((u32) (&data_02174e24)))), (void *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000404u)));
        func_0212a920();
    }
    return;
}

void func_0202a5d8(void) {
    if (*(int *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000808u)) == 0) {
        func_02029a98();
    } else {
        func_02032ab0();
    }
    func_0212abd0();
    return;
}

// non-matching: 0x34 bytes, original 0x38; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0202a5a0(void) {
    if (*(int *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000808u)) == 0) {
        func_02029a90();
    } else {
        func_02032aa8();
    }
    func_020ae5f0((void *) (*((int *) ((u32) (&data_02174e24)))), (void *) (*((int *) ((u32) (&data_02174e24))) + ((int) 0x00000404u)));
    return;
}

#pragma thumb off
