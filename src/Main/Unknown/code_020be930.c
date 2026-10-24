#include "Main/Unknown/code_020be930.h"

// non-matching: 0x3c bytes, original 0x20; 11 instructions differ; first at +0x0: original `ldr r2, [pc, #0x14]
// (->0x1c)`, ours `ldr r3, [pc, #0x30] (->0x38)`
void func_020be930(int param_1) {
    *(u32 *) (param_1 * 0xc +
              (*(u32 *) (((u32) (&data_0217b3d8)) & 0xfffffffc) >> (((u32) (&data_0217b3d8)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b3d8)) & 0xfffffffc) << (((u32) (&data_0217b3d8)) & 3) * -8 + 0x20) +
              0xfc) = 0;
    return;
}
