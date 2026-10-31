#include "Main/Unknown/code_020d2450.h"

void func_020d2450(void *param_1) {
    int iVar1;
    u8 auStack_28[12];
    u8 auStack_1c[20];
    iVar1 = func_01ffdee4((int *) ((int *) ((u32) param_1 + 4)), (u32 *) 0, (u32) 0, 0xa000, (u32) 8,
                          (short) 0xfffffffe, (int *) 0, (int *) ((int *) (void *) auStack_28), (int *) 0,
                          (u32 *) 0, (u32 *) 0, (int *) 0, (u16 *) 0, (u32 *) 0);
    if (iVar1 != 0) {
        func_020d7b88((Vec3 *) ((u32) auStack_28), (u32 *) ((u32 *) (void *) auStack_1c));
        func_01ffccd0((int *) ((int *) ((u32) param_1 + 0x28)), (void *) ((u32) auStack_1c));
        return;
    }
}
