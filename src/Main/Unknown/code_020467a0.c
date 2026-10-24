#include "Main/Unknown/code_020467a0.h"

// non-matching: 0x4c bytes, original 0x30; 11 instructions differ; first at +0xc: original `ldr r0, [pc, #0x18]
// (->0x2c)`, ours `ldr r1, [pc, #0x34] (->0x48)`
void func_020467a0(void) {
    func_0205db50();
    *(u16 *) ((*(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc) >> (((u32) (&data_021759c0)) & 3) * 8 |
               *(u32 *) (((u32) (&data_021759c0)) & 0xfffffffc) << (((u32) (&data_021759c0)) & 3) * -8 + 0x20) +
              0x248) = 1;
    return;
}
