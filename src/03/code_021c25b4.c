#include "03/code_021c25b4.h"

// non-matching: 0x28 bytes, original 0x2c; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021c25b4(void) {
    int iVar1;
    u32 uVar2;
    iVar1 = func_ov003_021d285c((u32) (100), (u32) (4));
    *((int *) ((u32) (&data_ov003_021da190))) = iVar1;
    uVar2 = func_ov003_021d1d60((int) (8), (int) (iVar1), (int) (0xc));
    *(u32 *) (*((int *) ((u32) (&data_ov003_021da190))) + 0x60) = uVar2;
    return;
}
