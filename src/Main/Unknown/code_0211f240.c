#include "Main/Unknown/code_0211f240.h"

#pragma thumb on

// non-matching: 23 instructions differ; first at +0x0: original `push {r4, r5, r6, lr}`, ours `push {r4, r5, r6, r7,
// lr}`
void func_0211f244(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u16 param_6, int param_7) {
    u32 uVar1;
    u32 *puVar2;
    uVar1 = 0xe;
    if ((param_7 != 0) && (param_7 == 1)) {
        uVar1 = 0x1e;
    }
    puVar2 = (u32 *) *((int *) ((u32) (&data_0217d37c)));
    func_02124748(*(u16 *) (((u32) (u32) ((unsigned char *) &data_0215d014)) + param_1 * 2), puVar2[1], *puVar2,
                  puVar2[3], param_7, param_5, param_3, param_4);
    ((u32) func_02016468((u32) (uVar1), (u32) ((u32) param_6 << 5),
                         (void *) (*(int *) (*(int *) (*((int *) ((u32) (&data_0217d37c))) + 8) + 0xc) +
                                   (u32) ((unsigned short *) &data_0215d00c)[param_2] * 0x20),
                         (u32) (0x20)));
    return;
}

unsigned int func_0211f240(unsigned int p0) {
    return p0;
}

#pragma thumb off
