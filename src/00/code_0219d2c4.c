#include "00/code_0219d2c4.h"

// non-matching: 0x20 bytes, original 0x24; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_0219d2c4(void) {
    int iVar1;
    iVar1 = *((int *) ((u32) (&data_ov000_021b5664)));
    (**(UnkFunc **) (iVar1 + 0x2c))(0, *(u8 *) (iVar1 + 0x1d), *(u32 *) (iVar1 + 0x30));
    *(u32 *) *((int *) ((u32) (&data_ov000_021b5664))) = 2;
    return;
}
