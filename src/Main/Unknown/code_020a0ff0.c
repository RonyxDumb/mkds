#include "Main/Unknown/code_020a0ff0.h"

// non-matching: 0x38 bytes, original 0x1c; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0x10]
// (->0x18)`, ours `ldr r3, [pc, #0x2c] (->0x34)`
int func_020a0ff0(int param_1) {
    return param_1 * 0x70 +
           (*(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) >> (((u32) (&data_0217b1fc)) & 3) * 8 |
            *(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) << (((u32) (&data_0217b1fc)) & 3) * -8 + 0x20) +
           0xc;
}
