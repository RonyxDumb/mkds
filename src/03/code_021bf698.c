#include "03/code_021bf698.h"

// non-matching: 0x90 bytes, original 0x98; 21 instructions differ; first at +0x2: original `sub sp, #0x14`, ours `sub
// sp, #0x1c`
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
        *(u32 *) (*((int *) ((u32) (&data_ov003_021da150))) + iVar2) = uVar1;
        func_ov003_021d1790(*(u32 *) (*((int *) ((u32) (&data_ov003_021da150))) + iVar2), 0xffffffff, 1);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 1;
    } while (iVar3 < 4);
    func_ov003_021d17d4(*(u32 *) *((int *) ((u32) (&data_ov003_021da150))), 0xffffffff, param_1, param_3);
    func_ov003_021d17d4(*(u32 *) (*((int *) ((u32) (&data_ov003_021da150))) + 4), 0xffffffff, param_2, param_3);
    func_ov003_021d17d4(*(u32 *) (*((int *) ((u32) (&data_ov003_021da150))) + 8), 0xffffffff, param_1, param_4);
    func_ov003_021d17d4(*(u32 *) (*((int *) ((u32) (&data_ov003_021da150))) + 0xc), 0xffffffff, param_2, param_4);
    return;
}

// non-matching: 2 instructions differ; first at +0x4: original nothing, ours `ldr r7, [pc, #0x24] (->0x2c)`
void func_ov003_021bf698(void) {
    int iVar3;
    int iVar2;
    int *piVar1;
    piVar1 = ((int *) ((u32) (&data_ov003_021da150)));
    iVar3 = 0;
    iVar2 = 0;
    do {
        if (0 != *(int *) (*piVar1 + iVar2)) {
            func_ov003_021d197c();
            *(u32 *) (*piVar1 + iVar2) = 0;
        }
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    return;
}
