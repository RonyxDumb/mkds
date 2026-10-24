#include "Main/Unknown/code_020d4104.h"

// non-matching: 0x34 bytes, original 0x18; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0xc]
// (->0x14)`, ours `ldr r3, [pc, #0x28] (->0x30)`
int func_020d4104(int param_1) {
    return param_1 * 0xc +
           (*(u32 *) (((u32) (&data_0217b4dc)) & 0xfffffffc) >> (((u32) (&data_0217b4dc)) & 3) * 8 |
            *(u32 *) (((u32) (&data_0217b4dc)) & 0xfffffffc) << (((u32) (&data_0217b4dc)) & 3) * -8 + 0x20);
}
