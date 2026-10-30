#include "03/code_021d2ecc.h"

int func_ov003_021d2eec(int param_1, int param_2) {
    return (*(int *) &data_ov003_021da2f0) + param_1 * 0x400 + param_2 * 8;
}

void *func_ov003_021d2ecc(void) {
    unsigned int v4 = ((unsigned int) func_ov003_021d285c((u32) (0x10u), (u32) (0x4u)));
    unsigned int v7;
    unsigned int v8;
    *(unsigned int *) ((v4) + (0)) = (unsigned int) (0x0u);
    v7 = ((v4) + (0x0u));
    v8 = ((v7) + (0x8u));
    *(unsigned int *) ((v4) + (4)) = (unsigned int) (v8);
    *(unsigned int *) ((v4) + (8)) = (unsigned int) (v4);
    *(unsigned int *) ((v4) + (12)) = (unsigned int) (0x0u);
    return (void *) v4;
}
