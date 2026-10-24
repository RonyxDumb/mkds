#include "01/code_02192f8c.h"

// non-matching: 0x28 bytes, original 0x2c; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_02192f8c(void) {
    if (*(UnkFunc **) (*((int *) ((u32) (&data_ov001_021a9bd0))) + 0x1c) != (UnkFunc *) 0x0) {
        (**(UnkFunc **) (*((int *) ((u32) (&data_ov001_021a9bd0))) + 0x1c))();
    }
    func_ov001_021932c8();
    func_0212abd0();
    func_02125da0();
    *((int *) ((u32) (&data_ov001_021a9bd0))) = 0;
    return;
}
