#include "00/code_021a37dc.h"

// non-matching: 13 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_ov000_021a37dc(void) {
    int iVar1;
    if (*((int *) ((u32) (&data_ov000_021b5df4))) != 0) {
        iVar1 = func_ov000_02188720();
        while (iVar1 == 0) {
            func_0200dc3c((u32) (10));
            iVar1 = func_ov000_02188720();
        }
        *((int *) ((u32) (&data_ov000_021b5df4))) = 0;
    }
    return;
}
