#include "00/code_021a31a4.h"

// non-matching: 0x2c bytes, original 0x30; 11 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_021a31a4(int param_1) {
    *((int *) ((u32) (&data_ov000_021b5dd0))) = param_1;
    func_0214d168((void *) ((u32 *) (u32) (param_1)), (u8) (0), (u32) (((u32) 0x00000614u)));
    *(short *) (*((int *) ((u32) (&data_ov000_021b5dd0))) + ((int) 0x00000610u)) = (short) ((u32) 0x000005b9u);
    return;
}
