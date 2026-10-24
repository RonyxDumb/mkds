#include "Main/Unknown/code_020e7388.h"

// non-matching: 0x34 bytes, original 0x18; 11 instructions differ; first at +0x0: original `ldr r1, [pc, #0xc]
// (->0x14)`, ours `ldr r1, [pc, #0x28] (->0x30)`
u16 func_020e7388(int param_1) {
    return *(u16 *) ((*(u32 *) (((u32) (&data_0217b868)) & 0xfffffffc) >> (((u32) (&data_0217b868)) & 3) * 8 |
                      *(u32 *) (((u32) (&data_0217b868)) & 0xfffffffc) << (((u32) (&data_0217b868)) & 3) * -8 + 0x20) +
                     param_1 * 2);
}
