#include "Main/Unknown/code_020a228c.h"

// non-matching: 0x3c bytes, original 0x20; 13 instructions differ; first at +0x0: original `ldr r2, [pc, #0x14]
// (->0x1c)`, ours `ldr r3, [pc, #0x30] (->0x38)`
void func_020a228c(int param_1) {
    *(u32 *) (param_1 * 0x70 +
              (*(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) >> (((u32) (&data_0217b1fc)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b1fc)) & 0xfffffffc) << (((u32) (&data_0217b1fc)) & 3) * -8 + 0x20) +
              100) = 0xffffffff;
    return;
}
