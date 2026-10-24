#include "Main/Unknown/code_0208f0a0.h"

// non-matching: 0x84 bytes, original 0x58; 24 instructions differ; first at +0x0: original `stmdb sp!, {r4, r5, lr}`,
// ours `stmdb sp!, {r4, r5, r6, r7, lr}`
void func_0208f0a0(void) {
    u32 uVar1;
    u32 uVar2;
    int iVar3;
    u32 uVar4;
    iVar3 = func_0201733c(
        (u32) (*(u32 *) (((u32) (&data_0217b08c)) & 0xfffffffc) >> (((u32) (&data_0217b08c)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b08c)) & 0xfffffffc) << (((u32) (&data_0217b08c)) & 3) * -8 + 0x20),
        (int) (0));
    uVar2 = ((u32) (&data_0217b08c));
    if (iVar3 == 0) {
        return;
    }
    do {
        func_0208e99c((int) (iVar3));
        uVar1 = uVar2 & 3;
        uVar4 = *(u32 *) (uVar2 & 0xfffffffc);
        iVar3 = func_0201733c((u32) (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20), (int) (iVar3));
    } while (iVar3 != 0);
    return;
}
