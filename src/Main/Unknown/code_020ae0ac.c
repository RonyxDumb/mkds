#include "Main/Unknown/code_020ae0ac.h"

// non-matching: 0x38 bytes, original 0x1c; 9 instructions differ; first at +0x0: original `ldr r2, [pc, #0x10]
// (->0x18)`, ours `ldr r3, [pc, #0x2c] (->0x34)`
int func_020ae0ac(int param_1) {
    return (int) *(
        s8 *) (param_1 * 0x30 +
               (*(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc) >> (((u32) (&data_021759c0)) & 3) * 8 |
                *(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc) << (((u32) (&data_021759c0)) & 3) * -8 + 0x20) +
               0x86);
}
