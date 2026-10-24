#include "Main/Unknown/code_0204b418.h"

#pragma thumb on

void func_0204b430(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    *(u32 *) (*((int *) ((u32) (&data_021759d4))) + 0x18) = param_2;
    ((u32) func_0204b458((unsigned int) (param_1), (unsigned int) (param_3), (unsigned int) (param_4),
                         (unsigned int) (param_5), (unsigned int) (1), (unsigned int) (param_6)));
    return;
}

void func_0204b418(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3) {
    unsigned int v5 = func_0204b458((unsigned int) (p0), (unsigned int) (p1), (unsigned int) (p2), (unsigned int) (p3),
                                    (unsigned int) (0x0u), (unsigned int) (0x0u));
}

#pragma thumb off
