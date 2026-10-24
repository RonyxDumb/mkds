#include "03/code_021d35c0.h"

// non-matching: 3 instructions differ; first at +0x2: original nothing, ours `ldr r6, [pc, #0x2c] (->0x30)`
void func_ov003_021d35c0(void) {
    int iVar3;
    int iVar2;
    int *piVar1;
    piVar1 = ((int *) ((u32) (&data_ov003_021da32c)));
    iVar3 = 0;
    iVar2 = 0;
    do {
        func_ov003_021d2eb8(*(u32 *) (*piVar1 + iVar2 + 8));
        func_ov003_021d1d4c(*(u32 *) (*piVar1 + iVar2));
        iVar2 = iVar2 + 0x3c;
        iVar3 = iVar3 + 1;
    } while (2 > iVar3);
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da32c))));
    return;
}
