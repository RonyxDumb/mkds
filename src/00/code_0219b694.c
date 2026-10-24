#include "00/code_0219b694.h"

void func_ov000_0219b6c0(int param_1, u32 param_2) {
    UnkFunc *pcVar1;
    if (param_1 == 0) {
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b54c8))) + 0x30) = param_2;
        func_ov000_0219b8a8((u32) (3));
        func_ov000_0219d5bc();
    } else {
        func_ov000_0219b8a8((u32) (0));
    }
    pcVar1 = *(UnkFunc **) (*((int *) ((u32) (&data_ov000_021b54c8))) + 0x5c);
    if (pcVar1 != (UnkFunc *) 0x0) {
        (*pcVar1)(param_1, param_2, *(u32 *) (*((int *) ((u32) (&data_ov000_021b54c8))) + 0x60));
    }
    return;
}

// non-matching: 0x28 bytes, original 0x2c; 9 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours
// `push {r4, r5, r6, lr}`
void func_ov000_0219b694(u32 param_1, u32 param_2) {
    func_ov000_0219b8a8((u32) (*(u32 *) (*((int *) ((u32) (&data_ov000_021b54c8))) + 0x28)));
    (**(UnkFunc **) (*((int *) ((u32) (&data_ov000_021b54c8))) + 100))(
        param_1, param_2, *(u32 *) (*((int *) ((u32) (&data_ov000_021b54c8))) + 0x68));
    return;
}
