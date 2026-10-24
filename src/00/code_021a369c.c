#include "00/code_021a369c.h"

void func_ov000_021a372c(u32 param_1, u32 param_2) {
    (*(UnkFunc *) *((u32 *) ((u32) (&data_ov000_021b5df0))))(param_1, param_2, 0x20);
    return;
}

void func_ov000_021a3718(unsigned int p0, unsigned int p1, unsigned int p2) {
    unsigned int v2 = ((u32) (&data_ov000_021b5df0));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v4 = ((unsigned int (*)(unsigned int, unsigned int, unsigned int))(v3))(p0, p1, p2);
}

void func_ov000_021a3704(unsigned int p0, unsigned int p1, unsigned int p2) {
    unsigned int v2 = ((u32) (&data_ov000_021b5dec));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v4 = ((unsigned int (*)(unsigned int, unsigned int, unsigned int))(v3))(p0, p1, p2);
}

void func_ov000_021a36f0(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3) {
    unsigned int v4 =
        ((unsigned int) func_ov000_021a369c((u32) (p0), (int) (p1), (u32) (p2), (u32) (p3), (u32) (0x20u)));
}

int func_ov000_021a369c(u32 param_1, int param_2, u32 param_3, u32 param_4, u32 param_5) {
    int iVar1;
    iVar1 = (*(UnkWordFunc *) *((u32 *) ((u32) (&data_ov000_021b5df0))))(param_1, param_4, param_5);
    if (iVar1 == 0) {
        return 0;
    }
    if (param_2 != 0) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_2)), (void *) ((u32 *) (u32) (iVar1)), (u32) (param_4));
        (*(UnkWordFunc *) *((u32 *) ((u32) (&data_ov000_021b5dec))))(param_1, param_2, param_3);
    }
    return iVar1;
}
