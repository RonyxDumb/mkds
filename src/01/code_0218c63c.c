#include "01/code_0218c63c.h"

void func_ov001_0218c728(int param_1) {
    u32 *puVar1;
    int iVar2;
    iVar2 = *(int *) (param_1 + 0xa0);
    func_ov001_0218875c((Unk02188950 *) (param_1), (s32) (*(u32 *) (iVar2 + 8)), (s32) (*(u32 *) (iVar2 + 0xc)), (s32) (*(u32 *) (iVar2 + ((int) 0x00000214u))));
    func_ov001_021888a4((Unk02188950 *) (param_1), (s32) (0), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0xc)));
    puVar1 = (u32 *) (param_1 + ((int) 0x000002a4u));
    *puVar1 = ((u32) 0x00011800u);
    *(u32 *) (param_1 + ((int) 0x00000298u)) = *puVar1;
    puVar1 = (u32 *) (param_1 + ((int) 0x000002acu));
    *puVar1 = ((u32) 0x0000c000u);
    *(u32 *) (param_1 + ((int) 0x000002a0u)) = *puVar1;
    return;
}

void func_ov001_0218c6b4(int param_1) {
    u32 uVar1;
    u32 uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    iVar4 = *(int *) (param_1 + 0xa0);
    iVar3 = *(int *) (iVar4 + 0xc);
    iVar5 = *(int *) (iVar4 + 8);
    uVar1 = _s32_div_f(iVar5, 0x14);
    uVar2 = _s32_div_f(iVar3, 0x14);
    func_ov001_021886f8((int) (param_1), (u32) (iVar5 << 1), (u32) (uVar1), (u32) (iVar3 << 1),
                        (int) (*(int *) (iVar4 + ((int) 0x00000214u)) << 1), (u32) (uVar2));
    func_ov001_0218883c((int) (param_1), (int) (0), (u32) (0), (u32) (0), (u32) (((u32) 0x00000e00u)));
    *(u32 *) (param_1 + ((int) 0x000002a4u)) = ((u32) 0x00023000u);
    *(u32 *) (param_1 + ((int) 0x000002acu)) = ((u32) 0x00018000u);
    return;
}

void func_ov001_0218c63c(int param_1) {
    u32 uVar1;
    u32 uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    iVar4 = *(int *) (param_1 + 0xa0);
    iVar3 = *(int *) (iVar4 + 0xc);
    iVar5 = *(int *) (iVar4 + 8);
    uVar1 = _s32_div_f(iVar5, 0x14);
    uVar2 = _s32_div_f(iVar3, 0x14);
    func_ov001_021886f8((int) (param_1), (u32) (iVar5 * 3), (u32) (uVar1), (u32) (iVar3 * 3),
                        (int) (*(int *) (iVar4 + ((int) 0x00000214u)) * 3), (u32) (uVar2));
    func_ov001_0218883c((int) (param_1), (int) (0), (u32) (0), (u32) (0), (u32) (((u32) 0x00000e00u)));
    *(u32 *) (param_1 + ((int) 0x000002a4u)) = ((u32) 0x00034800u);
    *(u32 *) (param_1 + ((int) 0x000002acu)) = ((u32) 0x00024000u);
    return;
}
