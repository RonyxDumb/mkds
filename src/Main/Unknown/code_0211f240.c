#include "Main/Unknown/code_0211f240.h"

#pragma thumb on

void func_0211f244(int param_1, int param_2, void *param_3, void *param_4, u32 param_5, u16 param_6, int param_7) {
    u32 uVar1;
    u32 *puVar2;
    uVar1 = 0xe;
    if ((param_7 != 0) && (param_7 == 1)) {
        uVar1 = 0x1e;
    }
    puVar2 = (u32 *) (*(int *) &data_0217d37c);
    func_02124748((u32) (*(u16 *) (((u32) (u32) ((u8 *) &data_0215d014)) + param_1 * 2)), (void *) (puVar2[1]), (void *) (*puVar2), (void *) (puVar2[3]), (s32) param_7, (u32) param_5, (void *) param_3, (void *) param_4);
    ((u32) func_02016468((u32) uVar1, (u32) ((u32) param_6 << 5),
                         (void *) (*(int *) ((int) data_0217d37c->mUnk_08 + 0xc) +
                                   (u32) ((u16 *) &data_0215d00c)[param_2] * 0x20),
                         (u32) 0x20));
}

void func_0211f240(void) {
}

#pragma thumb off
