#include "Main/Unknown/code_0204b418.h"

#pragma thumb on

void func_0204b430(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    *(u32 *) ((*(int *) &data_021759d4) + 0x18) = param_2;
    ((u32) func_0204b458((u32) (param_1), (u32 *) (param_3), (u32) (param_4), (void (*)(u32 *, u32)) (param_5),
                         (s32) (1), (s32) (param_6)));
    return;
}

void func_0204b418(u32 p0, void *p1, u32 p2, u32 p3) {
    unsigned int v5 = func_0204b458((u32) (p0), (u32 *) (p1), (u32) (p2), (void (*)(u32 *, u32)) (p3), (s32) (0x0u),
                                    (s32) (0x0u));
}

#pragma thumb off
