#include "03/code_021cdb90.h"
#include "code_020205b0.h"

// non-matching: 0x34 bytes, original 0x38; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021cdb90(void) {
    int iVar1;
    iVar1 = func_ov003_021d285c((u32) (((u32) 0x000006f8u)), (u32) (0x20));
    *((int *) ((u32) (&data_ov003_021da270))) = iVar1;
    func_02020720((u16 *) (iVar1 + ((int) 0x000004f8u)), (u32) (((u32) 0x0000a001u)));
    func_02151804((u32) (*((int *) ((u32) (&data_ov003_021da270)))));
    return;
}
