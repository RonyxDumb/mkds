#include "03/code_021c0fd8.h"

// non-matching: 0x7c bytes, original 0x84; 10 instructions differ; first at +0xa: original nothing, ours `ldr r6, [pc,
// #0x6c] (->0x78)`
void func_ov003_021c0fd8(u32 param_1) {
    int iVar4;
    int iVar3;
    int *piVar2;
    int *piVar1;
    func_ov003_021d34c8(0, param_1);
    piVar1 = ((int *) ((u32) (&data_ov003_021da160)));
    iVar4 = 0;
    iVar3 = 0;
    do {
        func_ov003_021d197c(*(u32 *) (*piVar1 + iVar3 + 0x48));
        func_ov003_021d2388((int) (*(u32 *) (*piVar1 + iVar3)));
        piVar2 = ((int *) ((u32) (&data_ov003_021da160)));
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d197c(*(u32 *) (*piVar2 + iVar4 + 0x40));
        piVar1 = ((int *) ((u32) (&data_ov003_021da160)));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) (*piVar1 + iVar4 + 0x38)));
        piVar2 = ((int *) ((u32) (&data_ov003_021da160)));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) (*piVar2 + iVar4 + 0x10)));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da160))));
    return;
}
