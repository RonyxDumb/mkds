#include "01/code_02187cd4.h"

void func_ov001_02187cd4(int param_1, u32 param_2) {
    int *piVar1;
    *(u32 *) (param_1 + ((int) 0x000002e4u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x0000027cu)) = 3;
    piVar1 = (int *) (param_1 + ((int) 0x00000304u));
    *(int *) (*(int *) (*piVar1 + 0x10) + 0x2c) = param_1;
    func_020109c4((void *) (*(u32 *) (*piVar1 + 0x10)), (void (*)(void *))(((u32) &func_ov001_02187d14)), (u32) (0),
                  (u8) (6), (u8) (3));
    return;
}
