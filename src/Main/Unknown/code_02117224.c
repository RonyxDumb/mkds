#include "Main/Unknown/code_02117224.h"

#pragma thumb on

// non-matching: 0x7c bytes, original 0x84; 12 instructions differ; first at +0xa: original `ldr r1, [pc, #0x64]
// (->0x70)`, ours `ldr r7, [pc, #0x5c] (->0x68)`
void func_02117224(u32 param_1) {
    int *piVar1;
    int iVar2;
    u32 uVar3;
    u32 *puVar4;
    int iVar5;
    iVar2 = ((u32) func_02036bec((void *) (param_1), (u32) (0x18)));
    *((int *) ((u32) (&data_0217d35c))) = iVar2;
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d524))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d35c))))), (void *) (uVar3));
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d528))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_0217d35c))) + 4)), (void *) (uVar3));
    piVar1 = ((int *) ((u32) (&data_0217d35c)));
    iVar5 = 0;
    puVar4 = ((u32 *) ((u32) (&data_0216d548)));
    iVar2 = 0;
    do {
        uVar3 = ((int) func_0204799c((const char *) (*puVar4)));
        func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*piVar1 + 8 + iVar2)), (void *) (uVar3));
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d530))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d35c))) + 0x14) = uVar3;
    return;
}

#pragma thumb off
