#include "Main/Unknown/code_0204b6cc.h"

#pragma thumb on

void func_0204b6f8(u32 p0, void *p1, u32 p2, void (*p3)(u32, u32), u32 p4) {
    unsigned int v4 = p4;
    unsigned int v7 = ((unsigned int) func_0204b714((u32) (p0), (u32) (p1), (u32) (p2), (u32) (p3), (u32) (0x0u),
                                                    (u32) (v4), (u32) (0x0u)));
}

void func_0204b6cc(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    *(u32 *) ((*(int *) &data_021759d4) + 0x18) = param_2;
    func_0204b714((u32) (param_1), (u32) (param_3), (u32) (param_4), (u32) (param_5), (u32) (1), (u32) (param_6),
                  (u32) (param_7));
    return;
}

#pragma thumb off
