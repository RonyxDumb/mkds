#include "Main/Unknown/code_020474e4.h"

#pragma thumb on

// non-matching: 6 instructions differ; first at +0xc4: original `ldr r1, [pc, #0x18] (->0x140)`, ours `ldr r2, [pc,
// #0x18] (->0xe0)`
void func_02047544(u32 param_1, u32 param_2, u32 param_3) {
    int *piVar1;
    func_02047634((u32) (param_3), (int) (2), (int) (0x3c), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (3), (int) (0x32), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (4), (int) (5), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (5), (int) (5), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (0), (int) (0x14), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (1), (int) (0x14), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (0xe), (int) (0x46), (u32) (0), (u32) (1));
    func_02047634((u32) (param_3), (int) (0xf), (int) (0x46), (u32) (0), (u32) (1));
    func_02047634((u32) (param_2), (int) (6), (int) (200), (u32) (1), (u32) (1));
    func_02047634((u32) (param_2), (int) (7), (int) (200), (u32) (0), (u32) (1));
    func_02047634((u32) (param_1), (int) (8), (int) (0x46), (u32) (1), (u32) (0));
    func_02047634((u32) (param_1), (int) (0xd), (int) (0x1e), (u32) (0), (u32) (0));
    piVar1 = (&(*(int *) &data_021759c8));
    *(u32 *) ((*(int *) &data_021759c8) + ((int) 0x00000a78u)) = param_1;
    *(u32 *) (*piVar1 + ((int) 0x00000a7cu)) = param_2;
    *(u32 *) (*piVar1 + ((int) 0x00000a80u)) = param_3;
    return;
}

void func_020474e4(void) {
    func_02047634((u32) (*(u32 *) ((*(int *) &data_0217aa10) + 0xa0)), (int) (0xb), (int) (0xaa), (u32) (0), (u32) (0));
    func_02047634((u32) (*(u32 *) ((*(int *) &data_0217aa10) + 0xa0)), (int) (0xc), (int) (0x6e), (u32) (0), (u32) (0));
    func_02047634((u32) (*(u32 *) ((*(int *) &data_0217aa10) + 0xa0)), (int) (9), (int) (0x1e), (u32) (0), (u32) (0));
    func_02047634((u32) (*(u32 *) ((*(int *) &data_0217aa10) + 0xa0)), (int) (10), (int) (0x1e), (u32) (0), (u32) (0));
    return;
}

#pragma thumb off
