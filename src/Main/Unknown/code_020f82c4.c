#include "Main/Unknown/code_020f82c4.h"

// non-matching: 0x28 bytes, original 0x24; 7 instructions differ; first at +0xc: original nothing, ours `ldrne r0, [pc,
// #0x10] (->0x24)`
void func_020f82e8(int param_1) {
    int iVar1;
    int *piVar2;
    piVar2 = ((int *) ((u32) (&data_0217bc60)));
    iVar1 = ((int) 0x00000708u);
    *((int *) ((u32) (&data_0217bc60))) = ((int) 0x00000708u);
    if (param_1 != 0) {
        *piVar2 = iVar1 + 300;
    }
    return;
}

// non-matching: 0x28 bytes, original 0x24; 7 instructions differ; first at +0xc: original nothing, ours `ldrne r0, [pc,
// #0x10] (->0x24)`
void func_020f82c4(int param_1) {
    int iVar1;
    int *piVar2;
    piVar2 = ((int *) ((u32) (&data_0217bc5c)));
    iVar1 = ((int) 0x00000708u);
    *((int *) ((u32) (&data_0217bc5c))) = ((int) 0x00000708u);
    if (param_1 != 0) {
        *piVar2 = iVar1 + 300;
    }
    return;
}
