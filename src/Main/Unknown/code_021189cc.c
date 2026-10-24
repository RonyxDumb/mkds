#include "Main/Unknown/code_021189cc.h"

#pragma thumb on

// non-matching: 2 instructions differ; first at +0x2: original nothing, ours `ldr r6, [pc, #0x20] (->0x24)`
void func_021189cc(void) {
    int iVar4;
    int iVar3;
    u32 uVar2;
    int *piVar1;
    piVar1 = ((int *) ((u32) (&data_0217d360)));
    iVar4 = 0;
    iVar3 = 0;
    do {
        uVar2 = func_021189f4(iVar4);
        *(u32 *) (*piVar1 + iVar3 + 0x48) = uVar2;
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    return;
}

#pragma thumb off
