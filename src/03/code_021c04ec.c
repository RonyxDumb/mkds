#include "03/code_021c04ec.h"

// non-matching: 16 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_ov003_021c04ec(int param_1) {
    if (param_1 != *(s8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x0000011fu))) {
        func_ov003_021c0050((int) (param_1), (int) (1));
        func_ov003_021c0050((int) ((int) *(s8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x0000011fu))),
                            (int) (0));
        *(s8 *) (*((int *) ((u32) (&data_ov003_021da15c))) + ((int) 0x0000011fu)) = (s8) param_1;
    }
    return;
}
