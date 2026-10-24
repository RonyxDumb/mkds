#include "00/code_0219c954.h"

// non-matching: 0x34 bytes, original 0x3c; 15 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_0219c954(void) {
    if (*(int *) (*((int *) ((u32) (&data_ov000_021b565c))) + 0x28) != 0) {
        func_ov000_02186474();
        func_ov000_02186430();
        func_ov000_021a3704((unsigned int) (0),
                            (unsigned int) (*(u32 *) (*((int *) ((u32) (&data_ov000_021b565c))) + 0x28)),
                            (unsigned int) (0));
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b565c))) + 0x28) = 0;
    }
    *((int *) ((u32) (&data_ov000_021b565c))) = 0;
    return;
}
