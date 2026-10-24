#include "Main/Unknown/code_02111584.h"

#pragma thumb on

// non-matching: 0x28 bytes, original 0x2c; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02111584(void) {
    func_021144b4();
    (**(UnkFunc **) (*((int *) ((u32) (&data_0217d344))) + 0x1c))();
    func_02111a98();
    func_0212abd0();
    func_02125da0();
    *((int *) ((u32) (&data_0217d344))) = 0;
    return;
}

#pragma thumb off
