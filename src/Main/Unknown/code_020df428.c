#include "Main/Unknown/code_020df428.h"

#pragma thumb on

void func_020df428(int param_1, int param_2) {
    func_020de6a8();
    if (*(int *) (param_1 + 0xf8) != 0) {
        *(unsigned short *) (param_1 + ((int) 0x00000110u)) = (short) ((u32) 0x0000ffffu);
        return;
    }
    func_020d7d4c(param_1 + ((int) 0x00000108u), param_2, *((u32 *) ((u32) (&data_02158908))),
                  (int) *(short *) (param_2 + 0x28));
    func_020d859c((Unk020d84e4 *) (param_1 + ((int) 0x00000108u)), *(u16 *) (param_2 + 0x30), 1);
    func_020d8c74(param_1 + ((int) 0x00000108u), param_1 + 4);
    return;
}

#pragma thumb off
