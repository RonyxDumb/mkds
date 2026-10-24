#include "03/code_021cd0d0.h"

// non-matching: 3 instructions differ; first at +0x10: original nothing, ours `ldr r7, [pc, #0x30] (->0x44)`
int func_ov003_021cd0d0(int *param_1) {
    int iVar5;
    int iVar4;
    int iVar3;
    int iVar2;
    u32 uVar1;
    iVar4 = 0;
    *param_1 = *((int *) ((u32) (&data_ov003_021da26c))) + ((int) 0x00001300u);
    uVar1 = ((u32) ((u32) (&data_ov003_021d6638)));
    iVar5 = 0;
    iVar3 = *param_1;
    do {
        iVar2 = func_02134d30((u32) (iVar3 + 0x20), (u32) (uVar1), (int) (6));
        if (iVar2 != 0) {
            iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 0x2a;
        iVar5 = iVar5 + 1;
    } while (iVar5 < 0x14);
    return iVar4;
}
