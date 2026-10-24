#include "00/code_02187230.h"

// non-matching: 0x48 bytes, original 0x44; 15 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
u32 func_ov000_02187230(int param_1) {
    func_0200ed34((int) (param_1 + ((int) 0x00000a28u)));
    if (*(int *) (param_1 + ((int) 0x00000a40u)) == 1) {
        func_0200ecc4((int) (param_1 + ((int) 0x00000a28u)));
        return 0;
    }
    func_0200ecc4((int) (param_1 + ((int) 0x00000a28u)));
    func_0200dc3c((u32) (10));
    return 1;
}
