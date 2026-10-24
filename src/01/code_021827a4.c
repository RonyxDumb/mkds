#include "01/code_021827a4.h"

// non-matching: 0x44 bytes, original 0x4c; 15 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_021827a4(void) {
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        func_ov001_021816a8((unsigned int) (((u32) ((u32) (&func_ov001_02182e84)))));
    }
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        func_ov001_0218169c((unsigned int) (((u32) ((u32) (&func_ov001_02182d30)))));
    }
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        func_ov001_02181690((unsigned int) (((u32) ((u32) (&func_ov001_02182bdc)))));
    }
    return;
}
