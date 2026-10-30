#include "Main/Unknown/code_020df428.h"

#pragma thumb on

void func_020df428(int param_1, int param_2) {
    func_020de6a8((Unk020de6a8 *) param_1, (Unk020de6a8_1 *) param_2);
    if (*(int *) (param_1 + 0xf8) != 0) {
        *(unsigned short *) (param_1 + 0x110) = (short) ((u32) 0x0000ffffu);
        return;
    }
    func_020d7d4c((Unk020d84e4 *) (param_1 + 0x108), (Unk020fa294 *) param_2, *(u32 *) &data_02158908,
                  (int) *(short *) (param_2 + 0x28));
    func_020d859c((Unk020d84e4 *) (param_1 + 0x108), *(u16 *) (param_2 + 0x30), 1);
    func_020d8c74((Unk020e0144 *) (param_1 + 0x108), (Vec3 *) (param_1 + 4));
}

#pragma thumb off
