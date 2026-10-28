#include "03/code_021bf698.h"

void func_ov003_021bf6c8(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    int iVar4;
    int iVar3;
    int iVar2;
    u32 uVar1;
    iVar4 = 6;
    func_ov003_021bf698();
    iVar3 = 0;
    iVar2 = 0;
    do {
        uVar1 = func_ov003_021d1be4(0, iVar4, 1);
        *(u32 *) ((*(int *) &data_ov003_021da150) + iVar2) = uVar1;
        func_ov003_021d1790(*(u32 *) ((*(int *) &data_ov003_021da150) + iVar2), 0xffffffff, 1);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 1;
    } while (iVar3 < 4);
    func_ov003_021d17d4(*(u32 *) (*(int *) &data_ov003_021da150), 0xffffffff, param_1, param_3);
    func_ov003_021d17d4(*(u32 *) ((*(int *) &data_ov003_021da150) + 4), 0xffffffff, param_2, param_3);
    func_ov003_021d17d4(*(u32 *) ((*(int *) &data_ov003_021da150) + 8), 0xffffffff, param_1, param_4);
    func_ov003_021d17d4(*(u32 *) ((*(int *) &data_ov003_021da150) + 0xc), 0xffffffff, param_2, param_4);
    return;
}

void func_ov003_021bf698(void) {
    int iVar3;
    int iVar2;
    iVar3 = 0;
    iVar2 = 0;
    do {
        if (0 != *(int *) (*(int *) data_ov003_021da150 + iVar2)) {
            func_ov003_021d197c();
            *(u32 *) (*(int *) data_ov003_021da150 + iVar2) = 0;
        }
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    return;
}
