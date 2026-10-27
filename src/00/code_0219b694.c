#include "00/code_0219b694.h"

void func_ov000_0219b6c0(int param_1, u32 param_2) {
    UnkFunc *pcVar1;
    if (param_1 == 0) {
        *(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x30) = param_2;
        func_ov000_0219b8a8((u32) (3));
        func_ov000_0219d5bc();
    } else {
        func_ov000_0219b8a8((u32) (0));
    }
    pcVar1 = *(UnkFunc **) ((*(int *) &data_ov000_021b54c8) + 0x5c);
    if (pcVar1 != (UnkFunc *) 0x0) {
        (*pcVar1)(param_1, param_2, *(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x60));
    }
    return;
}

void func_ov000_0219b694(u32 param_1, u32 param_2) {
    func_ov000_0219b8a8((u32) (*(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x28)));
    (**(UnkFunc **) ((*(int *) &data_ov000_021b54c8) + 100))(param_1, param_2,
                                                             *(u32 *) ((*(int *) &data_ov000_021b54c8) + 0x68));
    return;
}
